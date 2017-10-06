from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

## change as needed
config.Data.inputDataset = '/CITo2Mu_M300_CUETP8M1_Lam22TeVConLL_13TeV_Pythia8_Corrected-v4/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM'
sample = config.Data.inputDataset.split('/')

## change as needed
config.General.requestName = 'Dimuon_Ntuple_M300_CI_L22000_LL_Con_13TeV_test'
config.General.workArea    = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs    = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'runMakeZprimeMiniAodTreeMC_cfg.py'
#config.JobType.numCores = 4

config.JobType.pyCfgParams = ['sampleType=%s'%(sample[1]), 'runCrab=True']
#config.Data.outputPrimaryDataset = 'CIToEEntuple'
config.Data.inputDBS    = 'global'
config.Data.splitting   = 'FileBased'
config.Data.unitsPerJob = 1
## config.Data.totalUnits  = 1 ## only do one job for testing purposes
#NJOBS = 100
#config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
## change as needed
config.Data.outLFNDirBase    = '/store/user/sturdy' #%s/' % (getUsernameFromSiteDB())
config.Data.publication      = True
config.Data.outputDatasetTag = 'ntuples'

## change as needed
config.Site.storageSite = 'T3_US_FNALLPC' 
