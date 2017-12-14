import os

class ciDriver:

    def __init__(self,*args,**kwargs):
        from ci_2mu_samples import cito2musamples
        from ci_2e_samples import cito2esamples
        from dy_2mu_samples import dyto2musamples
        from dy_2e_samples import dyto2esamples

        print("args:",args)
        print("kwargs",kwargs)

        self.isDY = False
        self.dy   = args[0]
        self.lam  = None
        self.intf = None
        self.heli = None

        if self.dy in ["DYTo2L"]:
            self.isDY = True
        else:
            self.isDY = False
            self.lam  = args[0]
            self.intf = args[1]
            self.heli = args[2]
            pass

        if self.lam in ["Lam10","Lam100k"]:
            self.dbs  = "phys03"
        else:
            self.dbs  = "global"
            pass

        if self.isDY:
            self.dyto2musamples = dyto2musamples["DY"]
            self.dyto2esamples  = dyto2esamples["DY"]
        else:
            self.cito2musamples = cito2musamples[self.lam][self.intf][self.heli]
            self.cito2esamples  = cito2esamples[self.lam][self.intf][self.heli]
            pass
        pass

    def getJobOptions(self):
        if self.isDY:
            mcfiles = list(mu for mu in self.dyto2musamples) + list(e for e in self.dyto2esamples)
        else:
            mcfiles = list(mu for mu in self.cito2musamples) + list(e for e in self.cito2esamples)
            pass

        ci_job_options = {
            "storageSite":"T3_US_FNALLPC",
            "lfnBaseDir": "/store/user/%s/CINtuples"%(os.getenv("USER")),
            "cfgFile":    "runMakeZprimeMiniAodTreeMC_cfg.py",
            "dbs":        self.dbs,
            "datasets": {
                "MC": mcfiles,
                "data": [
                    # ["/SingleMuon/Run2016B-23Sep2016-v3/MINIAOD",json],
                    # ["/SingleMuon/Run2016C-23Sep2016-v1/MINIAOD",json],
                    # ["/SingleMuon/Run2016D-23Sep2016-v1/MINIAOD",json],
                    # ["/SingleMuon/Run2016E-23Sep2016-v1/MINIAOD",json],
                    # ["/SingleMuon/Run2016F-23Sep2016-v1/MINIAOD",json],
                    # ["/SingleMuon/Run2016G-23Sep2016-v1/MINIAOD",json],
                    # ["/SingleMuon/Run2016H-PromptReco-v1/MINIAOD",json],
                    # ["/SingleMuon/Run2016H-PromptReco-v2/MINIAOD",json],
                    # ["/SingleMuon/Run2016H-PromptReco-v3/MINIAOD",json],
                    # ["/SingleElectron/Run2016B-23Sep2016-v3/MINIAOD",json],
                    # ["/SingleElectron/Run2016C-23Sep2016-v1/MINIAOD",json],
                    # ["/SingleElectron/Run2016D-23Sep2016-v1/MINIAOD",json],
                    # ["/SingleElectron/Run2016E-23Sep2016-v1/MINIAOD",json],
                    # ["/SingleElectron/Run2016F-23Sep2016-v1/MINIAOD",json],
                    # ["/SingleElectron/Run2016G-23Sep2016-v1/MINIAOD",json],
                    # ["/SingleElectron/Run2016H-PromptReco-v1/MINIAOD",json],
                    # ["/SingleElectron/Run2016H-PromptReco-v2/MINIAOD",json],
                    # ["/SingleElectron/Run2016H-PromptReco-v3/MINIAOD",json],
                    ],
                },
            }
        return ci_job_options
    pass
