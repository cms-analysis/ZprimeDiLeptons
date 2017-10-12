import os

from ci_2mu_samples import cito2musamples
from ci_2e_samples import cito2esamples

lam  = "Lam22"
intf = "Con"
heli = "LL"

ci_job_options = {
    "storageSite":"T3_US_FNALLPC",
    "lfnBaseDir": "/store/user/%s/CINtuples"%(os.getenv("USER")),
    "cfgFile":    "runMakeZprimeMiniAodTreeMC_cfg.py",
    "dbs":        "global",
    "datasets": {
        "MC":   list(mu for mu in cito2musamples[lam][intf][heli]) + list(e for e in cito2esamples[lam][intf][heli]),
            
           ##DONE## ["/CITo2E_M1300_CUETP8M1_Lam16TeVConLL_13TeV_Pythia8_Corrected-v4/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM", None],
           ##DONE## ["/CITo2E_M2000_CUETP8M1_Lam16TeVConLL_13TeV_Pythia8_Corrected-v4/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM", None],
           ##DONE## ["/CITo2E_M300_CUETP8M1_Lam16TeVConLL_13TeV_Pythia8_Corrected-v4/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM", None],
           ##DONE## ["/CITo2E_M800_CUETP8M1_Lam16TeVConLL_13TeV_Pythia8_Corrected-v4/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM", None],
           ##DONE## ["/CITo2Mu_M1300_CUETP8M1_Lam16TeVConLL_13TeV_Pythia8_Corrected-v4/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM", None],
           ##DONE## ["/CITo2Mu_M2000_CUETP8M1_Lam16TeVConLL_13TeV_Pythia8_Corrected-v4/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM", None],
           ##DONE## ["/CITo2Mu_M300_CUETP8M1_Lam16TeVConLL_13TeV_Pythia8_Corrected-v4/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM", None],
           ##DONE## ["/CITo2Mu_M800_CUETP8M1_Lam16TeVConLL_13TeV_Pythia8_Corrected-v4/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM", None],
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
