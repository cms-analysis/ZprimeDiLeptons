import FWCore.ParameterSet.Config as cms
from RecoMuon.TrackingTools.MuonServiceProxy_cff import *
from PhysicsTools.PatAlgos.triggerLayer1.triggerProducer_cfi import *
#from TrackingTools.TransientTrack.TransientTrackBuilder_cfi import *

process = cms.Process("tree")
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.load("Configuration.StandardSequences.MagneticField_38T_cff")
process.load('Configuration/Geometry/GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
process.load("Configuration.StandardSequences.Reconstruction_cff")

process.load("RecoVertex.BeamSpotProducer.BeamSpot_cfi")
process.load("RecoTracker.Configuration.RecoTracker_cff")
#process.load("RecoTracker.TransientTrackingRecHit.TransientTrackingRecHitBuilderWithoutRefit_cfi")
#process.load("TrackingTools.TrackRefitter.TracksToTrajectories_cff")
process.load('Configuration/StandardSequences/EndOfProcess_cff')


process.options = cms.untracked.PSet(
    Rethrow = cms.untracked.vstring('ProductNotFound'),
    wantSummary = cms.untracked.bool(True) 
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

# reduce verbosity
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(10000)  

process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring(
#'file:pickevents_256729_612_898506503.root'
#'file:pickevents_256941_217_310981654.root'
#'file:pickevents_256676_238_340224775.root'
#'file:fevt_260424_115_211873064.root'
#'file:pickevents_259683_73_120918950.root'
#'file:pickevents_257613_979_1512626426.root'
#'file:pickevents_257968_268_387574044.root'
'file:pickevents_256734_75_93945569.root'
#'file:pickevents_260627_1632_2969419431.root'
#'file:pickevents_260627_1179_2177306937.root'
#'file:pickevents_260627_1775_3199077339.root'
#'file:pickevents_256677_337_345331220.root'
#'file:pickevents_257613_461_725033741.root'
 )
)

##-------- Electron events of interest --------
process.HLTEle =cms.EDFilter("HLTHighLevel",
     TriggerResultsTag = cms.InputTag("TriggerResults","","HLT"),
     # HLTPaths = cms.vstring("HLT_Mu45_eta2p1_v1","HLT_Mu50_v1"),
     HLTPaths = cms.vstring("HLT_Mu50_v*"),
     eventSetupPathsKey = cms.string(''),
     andOr = cms.bool(True), #----- True = OR, False = AND between the HLTPaths
     throw = cms.bool(False) # throw exception on unknown path names
 )

from RecoJets.JetProducers.kt4PFJets_cfi import *
process.kt6PFJetsForIsolation = kt4PFJets.clone( rParam = 0.6, doRhoFastjet = True )
process.kt6PFJetsForIsolation.Rho_EtaMax = cms.double(2.5)

process.load("RecoMET/METProducers.METSignificance_cfi")
process.load("RecoMET/METProducers.METSignificanceParams_cfi")
process.METSignificance.srcLeptons = cms.VInputTag(
       'gedGsfElectrons',
       'muons',
       'gedPhotons'
       )
process.METSignificance.srcPfJets            = cms.InputTag('ak4PFJets')
process.METSignificance.srcMet               = cms.InputTag('pfMet')
process.METSignificance.srcPFCandidates      = cms.InputTag('particleFlow')

# Global tag
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'MCRUN2_74_V9', '')
# process.GlobalTag = GlobalTag(process.GlobalTag, '74X_dataRun2_Prompt_v0', '')

process.maketreeMuon = cms.EDAnalyzer("MaketreeMuons",
    outputFile               = cms.string('CMSSW745_Data2015_ZprimeMuMu_13TeV_tree.root'),
    genEventInfo             = cms.InputTag('generator'),
    rhoIsoInputTag           = cms.InputTag("kt6PFJetsForIsolation", "rho"),
    #rhoIsoInputTag          = cms.InputTag("kt6PFJetsCentral:rho"),
    PileupSrc                = cms.InputTag("addPileupInfo"),
    thePFMETCollectionToken  = cms.InputTag("pfMet"),
    METSignificance          = cms.InputTag("METSignificance","METSignificance"),                                  
    globalMuons              = cms.InputTag('muons'),
    globalMuonTracks         = cms.InputTag('globalMuons'),
    vertexCollection         = cms.InputTag('offlinePrimaryVertices'),
    genparticleCollection    = cms.InputTag("genParticles"),                                   
    TrackCollectionTag       = cms.InputTag("generalTracks"),
    Jets                     = cms.InputTag("ak4PFJets"),                                   
    # Trigger matching                                           
    triggerEvent          = cms.InputTag("hltTriggerSummaryAOD","","HLT"),
    # triggerFilter         = cms.vstring('hltL3fL1sMu16orMu25L1f0L2f10QL3Filtered45e2p1Q','hltL3fL1sMu16orMu25L1f0L2f10QL3Filtered50Q'),
    # triggerFilter         = cms.vstring('hltL3fL1sMu16orMu25L1f0L2f10QL3Filtered45e2p1Q'),                                  
    triggerFilter         = cms.vstring('hltL3fL1sMu16orMu25L1f0L2f10QL3Filtered50Q'),   
    #triggerFilter2        = cms.string('hltL3fL1sMu16L1f0L2f16QL3Filtered40Q'),
    maxAbsZ  = cms.double(24),	
    maxd0    = cms.double(2),
    minndof  = cms.int32(4),
    NbGoodPv = cms.int32(1)
)



#process.p = cms.Path(process.HLTEle*process.maketreeMuon)

process.p = cms.Path( process.METSignificance*process.maketreeMuon)

 
