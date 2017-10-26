#!/usr/bin/env python

"""
This is a small script that does the equivalent of multicrab.
"""

import os
from optparse import OptionParser

from CRABAPI.RawCommand import crabCommand
from CRABClient.ClientExceptions import ClientException
from CRABClient.UserUtilities import getUsernameFromSiteDB
from httplib import HTTPException

def getOptions():
    """
    Parse and return the arguments provided by the user.
    """
    usage = ("Usage: %prog --crabCmd CMD [--workArea WAR --crabCmdOpts OPTS --lumiJSON JSON --driverCFG]"
             "\nThe multicrab command executes 'crab CMD OPTS' for each project directory contained in WAR"
             "\nUse multicrab -h for help")

    parser = OptionParser(usage=usage)

    parser.add_option('-c', '--crabCmd',
                      dest = 'crabCmd',
                      default = '',
                      help = "crab command",
                      metavar = 'CMD')

    parser.add_option('-w', '--workArea',
                      dest = 'workArea',
                      default = '',
                      help = "work area directory (only if CMD != 'submit')",
                      metavar = 'WAR')

    parser.add_option('-j', '--lumiJSON',
                      dest = 'lumiJSON',
                      default = '',
                      help = "lumi JSON location (only if CMD != 'submit')",
                      metavar = 'LUMI')

    parser.add_option('-o', '--crabCmdOpts',
                      dest = 'crabCmdOpts',
                      default = '',
                      help = "options for crab command CMD",
                      metavar = 'OPTS')

    parser.add_option('--driverCFG',
                      dest = 'driverCFG',
                      default = '',
                      help = "multicrab driver file",
                      metavar = 'DRIVER')

    (options, arguments) = parser.parse_args()

    if arguments:
        parser.error("Found positional argument(s): %s." % (arguments))
    if not options.crabCmd:
        parser.error("(-c CMD, --crabCmd=CMD) option not provided.")
    if options.crabCmd != 'submit':
        if not options.workArea:
            parser.error("(-w WAR, --workArea=WAR) option not provided.")
        if not os.path.isdir(options.workArea):
            parser.error("'%s' is not a valid directory." % (options.workArea))

    return options


def main():
    from ci_driver import ci_job_options as driver
    options = getOptions()

    # The submit command needs special treatment.
    if options.crabCmd == 'submit':

        #--------------------------------------------------------
        # This is the base config:
        #--------------------------------------------------------
        from CRABClient.UserUtilities import config
        config = config()

        config.General.requestName     = None
        config.General.workArea        = options.workArea
        config.General.transferOutputs = True
        config.General.transferLogs    = False

        config.JobType.pluginName = 'Analysis'

        config.Data.inputDBS         = driver["dbs"]
        config.Data.inputDataset     = None
        config.Data.splitting        = None
        config.Data.outputDatasetTag = None

        config.Data.outLFNDirBase = driver["lfnBaseDir"]

        config.Site.storageSite = driver["storageSite"]
        #--------------------------------------------------------

        certFile = options.lumiJSON
        # Will submit one task for each of these input datasets.
        # pass in datasets as a dict {datasetname,mc/data}
        inputDatasetMap = driver["datasets"]

        for key in inputDatasetMap.keys():
            inputDatasets = None
            print(key)
            if key.upper() == 'DATA':
                inputDatasets = inputDatasetMap[key]
                config.JobType.psetName = driver["cfgFile"]

                config.Data.splitting = 'LumiBased'
                config.Data.unitsPerJob = 250

            elif key.upper() == 'MC':
                inputDatasets = inputDatasetMap[key]
                config.JobType.psetName = driver["cfgFile"]

                # config.Data.useParent = True
                config.Data.splitting = 'FileBased'
                config.Data.unitsPerJob = 5
            else:
                print("Unknown key: {}".format(key))
                continue

            for inDS in inputDatasets:
                print "Key: %s - Creating config for for input dataset %s" % (key,inDS[0])
                # inDS is of the form /A/B/C. Since B is unique for each inDS, use this in the CRAB request name.
                if key == 'DATA':
                    config.General.requestName = "{}_{}_{}".format(getUsernameFromSiteDB(),options.workArea,inDS[0].split('/')[1])
                else:
                    config.General.requestName = "{}_{}_{}".format(getUsernameFromSiteDB(),options.workArea,inDS[0].split('/')[1])
                    pass
                print config.General.workArea
                print config.General.requestName
                config.Data.inputDataset = inDS[0]
                config.Data.outputDatasetTag = '{}_{}'.format(config.General.workArea, config.General.requestName)
                if key == 'DATA':
                    config.Data.lumiMask = inDS[1]
                    pass

                sampleType = inDS[0].split('/')[1]
                if sampleType == "CIToMuMuGenSim":
                    sampleType = inDS[0].split('/')[2].split('-')[1]
                    config.General.requestName = "{}_{}_{}".format(getUsernameFromSiteDB(),options.workArea,inDS[0].split('/')[2].split('-')[1])
                    pass
                elif sampleType == "CIToDielectron_L100k":
                    sampleType = inDS[0].split('/')[2].split('-')[1]
                    config.General.requestName = "{}_{}_{}".format(getUsernameFromSiteDB(),options.workArea,inDS[0].split('/')[2].split('-')[1])
                    pass
                config.JobType.pyCfgParams = ['sampleType=%s'%(sampleType), 'runCrab=True']

                # Submit.
                try:
                    print "Submitting for input dataset %s" % (inDS[0])
                    # continue  ## uncomment for debugging
                    crabCommand(options.crabCmd, config = config, *options.crabCmdOpts.split())
                except HTTPException as hte:
                    print "Submission for input dataset %s failed: %s" % (inDS[0], hte.headers)
                except ClientException as cle:
                    print "Submission for input dataset %s failed: %s" % (inDS[0], cle)

    # All other commands can be simply executed.
    elif options.workArea:

        for dir in os.listdir(options.workArea):
            projDir = os.path.join(options.workArea, dir)
            if not  os.path.isdir(projDir):
                continue
            # Execute the crab command.
            msg = "Executing (the equivalent of): crab %s --dir %s %s" % (options.crabCmd, projDir, options.crabCmdOpts)
            print "-"*len(msg)
            print msg
            print "-"*len(msg)
            try:
                crabCommand(options.crabCmd, dir = projDir, *options.crabCmdOpts.split())
            except HTTPException as hte:
                print "Failed executing command %s for task %s: %s" % (options.crabCmd, projDir, hte.headers)
            except ClientException as cle:
                print "Failed executing command %s for task %s: %s" % (options.crabCmd, projDir, cle)


if __name__ == '__main__':
    main()
