import os

class ciDriver:
    
    def __init__(self,*args,**kwargs):
        from ci_2mu_samples import cito2musamples
        from ci_2e_samples import cito2esamples

        print("args:",args)
        print("kwargs",kwargs)
        self.lam  = args[0]
        self.intf = args[1]
        self.heli = args[2]
        if self.lam in ["Lam10","Lam100k"]:
            self.dbs  = "phys03"
        else:
            self.dbs  = "global"
            pass

        self.cito2musamples = cito2musamples[self.lam][self.intf][self.heli]
        self.cito2esamples  = cito2esamples[self.lam][self.intf][self.heli]
        pass

    def getJobOptions(self):

        ci_job_options = {
            "storageSite":"T3_US_FNALLPC",
            "lfnBaseDir": "/store/user/%s/CINtuples"%(os.getenv("USER")),
            "cfgFile":    "runMakeZprimeMiniAodTreeMC_cfg.py",
            "dbs":        self.dbs,
            "datasets": {
                "MC": list(mu for mu in self.cito2musamples) + list(e for e in self.cito2esamples),
                # "MC":   list(mu for mu in self.cito2musamples),
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
