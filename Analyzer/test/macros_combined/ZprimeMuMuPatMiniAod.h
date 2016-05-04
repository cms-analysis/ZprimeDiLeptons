//==============================================================
//          Analysis code for Z' boson to Mu Mu analysis       =  
//          In this code we select the high pt di-muons events = 
//                  To run over MINIAOD MC                     = 
//                  Author:  Sherif Elgammal                   = 
//                                                             = 
//                      04/05/2016                             = 
//==============================================================
#ifndef ZprimeMuMuPatMiniAod_h
#define ZprimeMuMuPatMiniAod_h
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TFile.h"
#include <math.h>
#include "TF2.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TLorentzVector.h"
#include <time.h>
#include <iostream>
#include <vector>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <fstream>
#include <sstream>
#include "TVector3.h"
// Header file for the classes stored in the TTree if any.
#include <vector>
using namespace std;

// Fixed size dimensions of array or collections stored in the TTree if any.

class ZprimeMuMuPatMiniAod {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           event_runNo;
   Int_t           event_evtNo;
   Int_t           event_lumi;
   Int_t           event_bunch;
   vector<int>     *iGen;
   vector<int>     *idGen;
   vector<int>     *statusGen;
   vector<float>   *ptGen;
   vector<float>   *etaGen;
   vector<float>   *phiGen;
   vector<int>     *chargeGen;
   vector<float>   *EnergyGen;
   vector<float>   *pxGen;
   vector<float>   *pyGen;
   vector<float>   *pzGen;
   vector<int>     *Ele_nbElectrons;
   vector<bool>    *Ele_isEcalDrivenSeed;
   vector<bool>    *Ele_isPassConversionVeto;
   vector<int>     *Ele_charge;
   vector<int>     *Ele_nbOfMissingHits;
   vector<int>     *Ele_nbVtx;
   vector<float>   *Ele_Et;
   vector<float>   *Ele_EtFromCaloEn;
   vector<float>   *Ele_pt;
   vector<float>   *Ele_thetaSC;
   vector<float>   *Ele_etaSC;
   vector<float>   *Ele_phiSC;
   vector<float>   *Ele_energySC;
   vector<float>   *Ele_preshowerEnergySC;
   vector<float>   *Ele_thetaTrack;
   vector<float>   *Ele_etaTrack;
   vector<float>   *Ele_phiTrack;
   vector<float>   *Ele_hadronicOverEm;
   vector<float>   *Ele_deltaEtaInSeedCluster;
   vector<float>   *Ele_deltaPhiInSeedCluster;
   vector<float>   *Ele_deltaEtaInSC;
   vector<float>   *Ele_deltaPhiInSC;
   vector<float>   *Ele_sigmaIetaIeta;
   vector<float>   *Ele_e2x5Max;
   vector<float>   *Ele_e1x5;
   vector<float>   *Ele_frac15;
   vector<float>   *Ele_frac51;
   vector<float>   *Ele_e5x5;
   vector<float>   *Ele3x3;
   vector<float>   *Ele_e2x5MaxOver5x5;
   vector<float>   *Ele_e1x5Over5x5;
   vector<float>   *Ele_sigmaIetaIetaFull5x5;
   vector<float>   *Ele_e2x5MaxFull5x5;
   vector<float>   *Ele_e1x5Full5x5;
   vector<float>   *Ele_e5x5Full5x5;
   vector<float>   *Ele_e2x5MaxOver5x5Full5x5;
   vector<float>   *Ele_e1x5Over5x5Full5x5;
   vector<float>   *Ele_e2x5Right;
   vector<float>   *Ele_e2x5Left;
   vector<float>   *Ele_e2x5Top;
   vector<float>   *Ele_e2x5Bottom;
   vector<float>   *Ele_eMax;
   vector<float>   *Ele_eRight;
   vector<float>   *Ele_eLeft;
   vector<float>   *Ele_eTop;
   vector<float>   *Ele_eBottom;
   vector<float>   *Ele_dxy;
   vector<float>   *Ele_dz;
   vector<float>   *Ele_rhoIso;
   vector<float>   *Ele_fbrem;
   vector<float>   *Ele_EoverP;
   vector<float>   *Ele_Xposition;
   vector<float>   *Ele_Yposition;
   vector<float>   *Ele_EcalPlusHcald1iso;
   vector<float>   *Ele_dr03TkSumPt;
   vector<float>   *Ele_dr03EcalRecHitSumEt;
   vector<float>   *Ele_dr03HcalDepth1TowerSumEt;
   vector<float>   *Ele_dr03HcalDepth1TowerSumEtBc;
   vector<float>   *Ele_hcalDepth1OverEcal;
   vector<float>   *Ele_hcalDepth2OverEcal;
   vector<float>   *Ele_dr03HcalDepth2TowerSumEt;
   vector<float>   *Ele_hcalDepth2TowerSumEtNoVeto;
   vector<float>   *Ele_hcalDepth1TowerSumEtNoVeto;
   vector<float>   *Ele_pfSumPhotonEt;
   vector<float>   *Ele_pfSumChargedHadronPt;
   vector<float>   *Ele_pfSumNeutralHadronEt;
   vector<float>   *Ele_pfSumPUPt;
   vector<float>   *Ele_pfDeltaBeta;
   vector<int>     *Ele_rawId;
   vector<float>   *Ele_x;
   vector<float>   *Ele_y;
   vector<float>   *Ele_z;
   vector<float>   *Ele_zTrackPositionAtVtx;
   vector<int>     *Ele_ieta;
   vector<float>   *Ele_phiWidth;
   vector<float>   *Ele_etaWidth;
   vector<int>     *ecaleb_rawId;
   vector<int>     *ecaleb_iRechit;
   vector<int>     *ecaleb_RecoFlag;
   vector<bool>    *ecaleb_isSaturated;
   vector<float>   *ecaleb_EnRecHit;
   vector<bool>    *ecaleb_iskleadingedgerecovered;
   vector<bool>    *ecaleb_iskNeighboursRecovered;
   vector<bool>    *ecaleb_kWeird;
   vector<float>   *ecaleb_ietaRecHit;
   vector<float>   *ecaleb_iphiRecHit;
   vector<float>   *ecaleb_eta;
   vector<float>   *ecaleb_phi;
   vector<float>   *ecaleb_time;
   vector<int>     *ecalee_rawId;
   vector<int>     *ecalee_iRechit;
   vector<int>     *ecalee_RecoFlag;
   vector<bool>    *ecalee_isSaturated;
   vector<float>   *ecalee_EnRecHit;
   vector<bool>    *ecalee_iskleadingedgerecovered;
   vector<bool>    *ecalee_iskNeighboursRecovered;
   vector<bool>    *ecalee_kWeird;
   vector<float>   *ecalee_ietaRecHit;
   vector<float>   *ecalee_iphiRecHit;
   vector<float>   *ecalee_eta;
   vector<float>   *ecalee_phi;
   vector<float>   *ecalee_time;
   vector<int>     *Mu_nbMuon;
   vector<bool>    *Mu_isGlobalMuon;
   vector<bool>    *Mu_isPF;
   vector<bool>    *Mu_isTrackerMuon;
   vector<float>   *Mu_et;
   vector<float>   *Mu_en;
   vector<float>   *Mu_pt;
   vector<float>   *Mu_eta;
   vector<float>   *Mu_phi;
   vector<float>   *Mu_charge;
   vector<float>   *Mu_ptTunePMuonBestTrack;
   vector<float>   *Mu_pxTunePMuonBestTrack;
   vector<float>   *Mu_pyTunePMuonBestTrack;
   vector<float>   *Mu_pzTunePMuonBestTrack;
   vector<float>   *Mu_pTunePMuonBestTrack;
   vector<float>   *Mu_etaTunePMuonBestTrack;
   vector<float>   *Mu_phiTunePMuonBestTrack;
   vector<float>   *Mu_thetaTunePMuonBestTrack;
   vector<float>   *Mu_chargeTunePMuonBestTrack;
   vector<float>   *Mu_dPToverPTTunePMuonBestTrack;
   vector<float>   *Mu_absdxyTunePMuonBestTrack;
   vector<float>   *Mu_absdzTunePMuonBestTrack;
   vector<float>   *Mu_ptInnerTrack;
   vector<float>   *Mu_normalizedChi2;
   vector<float>   *Mu_vtxMass;
   vector<float>   *Mu_vtxNormChi2;
   vector<float>   *Mu_vtxMassLept;
   vector<int>     *Mu_numberOfMatchedStations;
   vector<int>     *Mu_numberOfValidPixelHits;
   vector<int>     *Mu_numberOfValidMuonHits;
   vector<int>     *Mu_numberOftrackerLayersWithMeasurement;
   vector<float>   *Mu_emIso;
   vector<float>   *Mu_hadIso;
   vector<float>   *Mu_trackiso;
   vector<float>   *Mu_pfSumChargedHadronPt;
   vector<float>   *Mu_pfSumNeutralHadronEt;
   vector<float>   *Mu_PFSumPhotonEt;
   vector<float>   *Mu_pfSumPUPt;
   vector<int>     *Mu_nbofpv;
   vector<float>   *Mu_pfDeltaBeta;
   vector<float>   *Mu_patDeltaBeta;
   vector<int>     *HLT_nb;
   vector<string>  *HLT_name;
   vector<bool>    *HLT_isaccept;
   vector<int>     *HLTObj_nbObj;
   vector<float>   *HLTObj_pt;
   vector<float>   *HLTObj_eta;
   vector<float>   *HLTObj_phi;
   vector<string>  *HLTObj_collection;
   vector<int>     *nbPv;
   vector<int>     *Nbdof;
   vector<float>   *PositionRho;
   vector<float>   *PositionX;
   vector<float>   *PositionY;
   vector<float>   *PositionZ;
   vector<int>     *jet_nb;
   vector<int>     *jetcharge;
   vector<float>   *jetet;
   vector<float>   *jetpt;
   vector<float>   *jeteta;
   vector<float>   *jetphi;
   Double_t        GenMet_pt;
   Double_t        PFMet_pt_cor;
   Double_t        PFMet_phi_cor;
   Double_t        PFMet_en_cor;
   Double_t        PFMet_px_cor;
   Double_t        PFMet_py_cor;
   Double_t        PFMet_pz_cor;
   Double_t        PFMet_sumEt_cor;
   Double_t        PFMet_pt_uncor;
   Double_t        PFMet_phi_uncor;
   Double_t        PFMet_sumEt_uncor;
   Double_t        CaloMet_pt;
   Double_t        CaloMet_phi;
   Double_t        CaloMet_sumEt;
   Double_t        METSign;
   Double_t        PFMet_shiftedPt_JetEnUp;
   Double_t        PFMet_shiftedPt_JetEnDown;
   Int_t           num_PU_vertices;
   Int_t           PU_BunchCrossing;
   Float_t         Rho;
   vector<float>   *MC_weighting;

   // List of branches
   TBranch        *b_event_runNo;   //!
   TBranch        *b_event_evtNo;   //!
   TBranch        *b_event_lumi;   //!
   TBranch        *b_event_bunch;   //!
   TBranch        *b_iGen;   //!
   TBranch        *b_idGen;   //!
   TBranch        *b_statusGen;   //!
   TBranch        *b_ptGen;   //!
   TBranch        *b_etaGen;   //!
   TBranch        *b_phiGen;   //!
   TBranch        *b_chargeGen;   //!
   TBranch        *b_EnergyGen;   //!
   TBranch        *b_pxGen;   //!
   TBranch        *b_pyGen;   //!
   TBranch        *b_pzGen;   //!
   TBranch        *b_Ele_nbElectrons;   //!
   TBranch        *b_Ele_isEcalDrivenSeed;   //!
   TBranch        *b_Ele_isPassConversionVeto;   //!
   TBranch        *b_Ele_charge;   //!
   TBranch        *b_Ele_nbOfMissingHits;   //!
   TBranch        *b_Ele_nbVtx;   //!
   TBranch        *b_Ele_Et;   //!
   TBranch        *b_Ele_EtFromCaloEn;   //!
   TBranch        *b_Ele_pt;   //!
   TBranch        *b_Ele_thetaSC;   //!
   TBranch        *b_Ele_etaSC;   //!
   TBranch        *b_Ele_phiSC;   //!
   TBranch        *b_Ele_energySC;   //!
   TBranch        *b_Ele_preshowerEnergySC;   //!
   TBranch        *b_Ele_thetaTrack;   //!
   TBranch        *b_Ele_etaTrack;   //!
   TBranch        *b_Ele_phiTrack;   //!
   TBranch        *b_Ele_hadronicOverEm;   //!
   TBranch        *b_Ele_deltaEtaInSeedCluster;   //!
   TBranch        *b_Ele_deltaPhiInSeedCluster;   //!
   TBranch        *b_Ele_deltaEtaInSC;   //!
   TBranch        *b_Ele_deltaPhiInSC;   //!
   TBranch        *b_Ele_sigmaIetaIeta;   //!
   TBranch        *b_Ele_e2x5Max;   //!
   TBranch        *b_Ele_e1x5;   //!
   TBranch        *b_Ele_frac15;   //!
   TBranch        *b_Ele_frac51;   //!
   TBranch        *b_Ele_e5x5;   //!
   TBranch        *b_Ele3x3;   //!
   TBranch        *b_Ele_e2x5MaxOver5x5;   //!
   TBranch        *b_Ele_e1x5Over5x5;   //!
   TBranch        *b_Ele_sigmaIetaIetaFull5x5;   //!
   TBranch        *b_Ele_e2x5MaxFull5x5;   //!
   TBranch        *b_Ele_e1x5Full5x5;   //!
   TBranch        *b_Ele_e5x5Full5x5;   //!
   TBranch        *b_Ele_e2x5MaxOver5x5Full5x5;   //!
   TBranch        *b_Ele_e1x5Over5x5Full5x5;   //!
   TBranch        *b_Ele_e2x5Right;   //!
   TBranch        *b_Ele_e2x5Left;   //!
   TBranch        *b_Ele_e2x5Top;   //!
   TBranch        *b_Ele_e2x5Bottom;   //!
   TBranch        *b_Ele_eMax;   //!
   TBranch        *b_Ele_eRight;   //!
   TBranch        *b_Ele_eLeft;   //!
   TBranch        *b_Ele_eTop;   //!
   TBranch        *b_Ele_eBottom;   //!
   TBranch        *b_Ele_dxy;   //!
   TBranch        *b_Ele_dz;   //!
   TBranch        *b_Ele_rhoIso;   //!
   TBranch        *b_Ele_fbrem;   //!
   TBranch        *b_Ele_EoverP;   //!
   TBranch        *b_Ele_Xposition;   //!
   TBranch        *b_Ele_Yposition;   //!
   TBranch        *b_Ele_EcalPlusHcald1iso;   //!
   TBranch        *b_Ele_dr03TkSumPt;   //!
   TBranch        *b_Ele_dr03EcalRecHitSumEt;   //!
   TBranch        *b_Ele_dr03HcalDepth1TowerSumEt;   //!
   TBranch        *b_Ele_dr03HcalDepth1TowerSumEtBc;   //!
   TBranch        *b_Ele_hcalDepth1OverEcal;   //!
   TBranch        *b_Ele_hcalDepth2OverEcal;   //!
   TBranch        *b_Ele_dr03HcalDepth2TowerSumEt;   //!
   TBranch        *b_Ele_hcalDepth2TowerSumEtNoVeto;   //!
   TBranch        *b_Ele_hcalDepth1TowerSumEtNoVeto;   //!
   TBranch        *b_Ele_pfSumPhotonEt;   //!
   TBranch        *b_Ele_pfSumChargedHadronPt;   //!
   TBranch        *b_Ele_pfSumNeutralHadronEt;   //!
   TBranch        *b_Ele_pfSumPUPt;   //!
   TBranch        *b_Ele_pfDeltaBeta;   //!
   TBranch        *b_Ele_rawId;   //!
   TBranch        *b_Ele_x;   //!
   TBranch        *b_Ele_y;   //!
   TBranch        *b_Ele_z;   //!
   TBranch        *b_Ele_zTrackPositionAtVtx;   //!
   TBranch        *b_Ele_ieta;   //!
   TBranch        *b_Ele_phiWidth;   //!
   TBranch        *b_Ele_etaWidth;   //!
   TBranch        *b_ecaleb_rawId;   //!
   TBranch        *b_ecaleb_iRechit;   //!
   TBranch        *b_ecaleb_RecoFlag;   //!
   TBranch        *b_ecaleb_isSaturated;   //!
   TBranch        *b_ecaleb_EnRecHit;   //!
   TBranch        *b_ecaleb_iskleadingedgerecovered;   //!
   TBranch        *b_ecaleb_iskNeighboursRecovered;   //!
   TBranch        *b_ecaleb_kWeird;   //!
   TBranch        *b_ecaleb_ietaRecHit;   //!
   TBranch        *b_ecaleb_iphiRecHit;   //!
   TBranch        *b_ecaleb_eta;   //!
   TBranch        *b_ecaleb_phi;   //!
   TBranch        *b_ecaleb_time;   //!
   TBranch        *b_ecalee_rawId;   //!
   TBranch        *b_ecalee_iRechit;   //!
   TBranch        *b_ecalee_RecoFlag;   //!
   TBranch        *b_ecalee_isSaturated;   //!
   TBranch        *b_ecalee_EnRecHit;   //!
   TBranch        *b_ecalee_iskleadingedgerecovered;   //!
   TBranch        *b_ecalee_iskNeighboursRecovered;   //!
   TBranch        *b_ecalee_kWeird;   //!
   TBranch        *b_ecalee_ietaRecHit;   //!
   TBranch        *b_ecalee_iphiRecHit;   //!
   TBranch        *b_ecalee_eta;   //!
   TBranch        *b_ecalee_phi;   //!
   TBranch        *b_ecalee_time;   //!
   TBranch        *b_Mu_nbMuon;   //!
   TBranch        *b_Mu_isGlobalMuon;   //!
   TBranch        *b_Mu_isPF;   //!
   TBranch        *b_Mu_isTrackerMuon;   //!
   TBranch        *b_Mu_et;   //!
   TBranch        *b_Mu_en;   //!
   TBranch        *b_Mu_pt;   //!
   TBranch        *b_Mu_eta;   //!
   TBranch        *b_Mu_phi;   //!
   TBranch        *b_Mu_charge;   //!
   TBranch        *b_Mu_ptTunePMuonBestTrack;   //!
   TBranch        *b_Mu_pxTunePMuonBestTrack;   //!
   TBranch        *b_Mu_pyTunePMuonBestTrack;   //!
   TBranch        *b_Mu_pzTunePMuonBestTrack;   //!
   TBranch        *b_Mu_pTunePMuonBestTrack;   //!
   TBranch        *b_Mu_etaTunePMuonBestTrack;   //!
   TBranch        *b_Mu_phiTunePMuonBestTrack;   //!
   TBranch        *b_Mu_thetaTunePMuonBestTrack;   //!
   TBranch        *b_Mu_chargeTunePMuonBestTrack;   //!
   TBranch        *b_Mu_dPToverPTTunePMuonBestTrack;   //!
   TBranch        *b_Mu_absdxyTunePMuonBestTrack;   //!
   TBranch        *b_Mu_absdzTunePMuonBestTrack;   //!
   TBranch        *b_Mu_ptInnerTrack;   //!
   TBranch        *b_Mu_normalizedChi2;   //!
   TBranch        *b_Mu_vtxMass;   //!
   TBranch        *b_Mu_vtxNormChi2;   //!
   TBranch        *b_Mu_vtxMassLept;   //!
   TBranch        *b_Mu_numberOfMatchedStations;   //!
   TBranch        *b_Mu_numberOfValidPixelHits;   //!
   TBranch        *b_Mu_numberOfValidMuonHits;   //!
   TBranch        *b_Mu_numberOftrackerLayersWithMeasurement;   //!
   TBranch        *b_Mu_emIso;   //!
   TBranch        *b_Mu_hadIso;   //!
   TBranch        *b_Mu_trackiso;   //!
   TBranch        *b_Mu_pfSumChargedHadronPt;   //!
   TBranch        *b_Mu_pfSumNeutralHadronEt;   //!
   TBranch        *b_Mu_PFSumPhotonEt;   //!
   TBranch        *b_Mu_pfSumPUPt;   //!
   TBranch        *b_Mu_nbofpv;   //!
   TBranch        *b_Mu_pfDeltaBeta;   //!
   TBranch        *b_Mu_patDeltaBeta;   //!
   TBranch        *b_HLT_nb;   //!
   TBranch        *b_HLT_name;   //!
   TBranch        *b_HLT_isaccept;   //!
   TBranch        *b_HLTObj_nbObj;   //!
   TBranch        *b_HLTObj_pt;   //!
   TBranch        *b_HLTObj_eta;   //!
   TBranch        *b_HLTObj_phi;   //!
   TBranch        *b_HLTObj_collection;   //!
   TBranch        *b_nbPv;   //!
   TBranch        *b_Nbdof;   //!
   TBranch        *b_PositionRho;   //!
   TBranch        *b_PositionX;   //!
   TBranch        *b_PositionY;   //!
   TBranch        *b_PositionZ;   //!
   TBranch        *b_jet_nb;   //!
   TBranch        *b_jetcharge;   //!
   TBranch        *b_jetet;   //!
   TBranch        *b_jetpt;   //!
   TBranch        *b_jeteta;   //!
   TBranch        *b_jetphi;   //!
   TBranch        *b_GenMet_pt;   //!
   TBranch        *b_PFMet_pt_cor;   //!
   TBranch        *b_PFMet_phi_cor;   //!
   TBranch        *b_PFMet_en_cor;   //!
   TBranch        *b_PFMet_px_cor;   //!
   TBranch        *b_PFMet_py_cor;   //!
   TBranch        *b_PFMet_pz_cor;   //!
   TBranch        *b_PFMet_sumEt_cor;   //!
   TBranch        *b_PFMet_pt_uncor;   //!
   TBranch        *b_PFMet_phi_uncor;   //!
   TBranch        *b_PFMet_sumEt_uncor;   //!
   TBranch        *b_CaloMet_pt;   //!
   TBranch        *b_CaloMet_phi;   //!
   TBranch        *b_CaloMet_sumEt;   //!
   TBranch        *b_METSign;   //!
   TBranch        *b_PFMet_shiftedPt_JetEnUp;   //!
   TBranch        *b_PFMet_shiftedPt_JetEnDown;   //!
   TBranch        *b_num_PU_vertices;   //!
   TBranch        *b_PU_BunchCrossing;   //!
   TBranch        *b_Rho;   //!
   TBranch        *b_MC_weighting;   //!

   ZprimeMuMuPatMiniAod(TTree *tree=0);
   virtual ~ZprimeMuMuPatMiniAod();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   void PrintEventInformation(int runNumber, int lumiNumber, int eventNumber,
			      float vtxChi2, float vtxMass, float CosmicRejection);
   bool SelectFirstMuon(float &pTmuon1,float &Enmuon1,float &Etamuon1,
                        float &Phimuon1,int &ChargeMu1,unsigned &FlagMu1,
                        float &pxmuon1,float &pymuon1,float &pzmuon1,
                        float &pmuon1,float &dxymuon1,float &pTmuon1tuneP,
			float &pTmuonBestTrack1);
   bool SelectSecondMuon(int ChargeMu1,unsigned FlagMu1,float pTmuon1,float Etamuon1,float Phimuon1,
			 float &pTmuon2,float &Enmuon2,
                         float &Etamuon2,float &Phimuon2,int &ChargeMu2,float &pxmuon2,
                         float &pymuon2,float &pzmuon2,float &pmuon2,float &dxymuon2,
			 float &pTmuon2tuneP,float &pTmuonBestTrack2);
   float Mass(float Pt1,float Eta1,float Phi1,float En1,
              float Pt2,float Eta2,float Phi2,float En2);
   void PlotRecoInfo(float CosmicMuonRejec,float vertexMassMu,float MassGenerated,
		     float PtTunePMuBestTrack,float PtTunePMu,float PtMuBestTrack,
		     float PtGenerated,float etaMu1,
		     float PtTunePMuBestTrack2,float PtTunePMu2,float PtMuBestTrack2,
		     float PtGenerated2,float etaMu2);
   void PickThehighestMass(float &vtxHighestMass,float &vtxHighestChi2,int EvtNb);
   double ThreeDangle(float pxMu1,float pyMu1,float pzMu1,float pMu1,
                      float pxMu2,float pyMu2,float pzMu2,float pMu2);
   
   bool SelectFirstGenMu(float &ETMu1,float &PhiSCMu1,
                         float &EtaSCMu1,float &EnMu1,
                         int &IDele1,int &Statele1,
                         unsigned &GenFlag1);
   
   bool SelectSecondGenMu(unsigned GenFlag1,float ETMu1,float &ETMu2,float &PhiSCMu2,
                          float &EtaSCMu2,float &EnMu2,int &IDele2,int &Statele2);
   /*
   bool GenRecoMatchMu1(float RecoEta1,float RecoPhi1,
                        float &ETMu1,float &PhiSCMu1,
                        float &EtaSCMu1,float &EnMu1,
                        unsigned &GenFlag1);
   */
   bool GenRecoMatchMu(float RecoEta1,float RecoPhi1);
   /*
   bool GenRecoMatchMu2(unsigned GenFlag1,float RecoEta2,float RecoPhi2,
                        float &ETMu2,float &PhiSCMu2,
                        float &EtaSCMu2,float &EnMu2);
   */
   void PlotGenInfo(float ZprimeGenMass,float EtaGenMu1,float EtaGenMu2,float PtGenMu1,
		    float PtGenMu2,float EnGenMu1,float EnGenMu2);
   
   bool RecoHLTMuonMatching(float RecoEta,float RecoPhi);
   //bool RecoHLTMuonMatching(float hltEta,float hltPhi,float RecoEta,float RecoPhi);
   bool isPassHLT();

   void MuonPassingID();
   void PlotPterror();
   void PlotNbTrackLayers();
   void PlotNBValidPixelHits();
   void PlotNbValidMuonHits();
   void PlotNbMatchedStations();
   void PlotTrackiso();
   void PlotAbsDxy();
   void PlotPtTuneP();
   void plotAllHighPtMuonsID();
   void MuonPassingNewID();
   void MuonPassingTightID();
   void CosThetaCollinSoper(float Et1,float Eta1,float Phi1,float En1,
			    float Et2,float Eta2,float Phi2,float En2,
			    float ChargeEle1,float RecoMass);
   float delR(float eta1,float phi1,float eta2,float phi2);
   //================================================================================
   float HLT_pt,HLT_eta,HLT_phi;
   int weight;
   float ptEffCut;
   float PtDYTRecMu1,PtDYTRecMu2,PtRecTunePMu1,PtRecTunePMu2,PtRecMuBestTrack1,PtRecMuBestTrack2;
   float RecoHLTMatchingDeltaRcut,deltaRcut,minMassCut,maxMassCut;
   float vtxChi2Mu,vtxMassMu;
   float mPtGen1,mPhiGen1,mEtaGen1,mEnGen1;
   unsigned mGenFlag1;
   float mPtGen2,mPhiGen2,mEtaGen2,mEnGen2;
   int ChargeRecMu1,ChargeRecMu2;
   unsigned flagmu1;
   unsigned flag1;
   float PtRecTunePMuBestTrack1,EnRecMu1,EtaRecMu1,PhiRecMu1;
   float PtRecTunePMuBestTrack2,EnRecMu2,EtaRecMu2,PhiRecMu2;
   float pxRecMu1,pyRecMu1,pzRecMu1,pRecMu1,dxyRecMu1;
   float pxRecMu2,pyRecMu2,pzRecMu2,pRecMu2,dxyRecMu2;
   float genET1,genPhi1,genEta1,genEn1;
   int genID1,genStat1;
   float genET2,genPhi2,genEta2,genEn2;
   int genID2,genStat2;
   float MassGen,RecoMass;
   int NbGen,NbReco;
   int nbTP,nbTT,nbTF;
   float TagProbeEtaCut;
   float Eff;
   float MassCutMin,MassCutMax;
   float MassResolution;
   float EtaCut;
   TH1F* h1_ZprimeRecomassBeforeTrigger_;
   TH1F* h1_ZprimeRecomass_;
   TH1F* h1_ZprimeRecomasslogscale_;                                                              
   TH1F* h1_ZprimeRecomass60to120_;
   TH1F* h1_ZprimeRecomassAbove400GeV_;
   TH1F* h1_ZprimeRecomassAbove1000GeV_;
   TH1F* h1_3Dangle_;
   TH1F* h1_DxyDiff_;
   TH1F* h1_ZprimeGenmass_;
   TH1F* h1_ZprimeGenEta1_;
   TH1F* h1_ZprimeGenEta2_;
   TH1F* h1_ZprimeGenPt1_;
   TH1F* h1_ZprimeGenPt2_;
   TH1F* h1_ZprimeGenEn1_;
   TH1F* h1_ZprimeGenEn2_;
   TH1F* h1_MassRecoGenDif_;
   TH1F* h1_dPToverPT_;
   TH1F* h1_normalizedChi2_;
   TH1F* h1_numberOftrackerLayersWithMeasurement_;
   TH1F* h1_numberOfValidPixelHits_;
   TH1F* h1_numberOfValidMuonHits_;
   TH1F* h1_numberOfMatchedStations_;
   TH1F* h1_trackiso_;
   TH1F* h1_absdxy_;
   TH1F* h1_PtEffpterror_;
   TH1F* h1_PtEffptnumberOftrackerLayers_;
   TH1F* h1_PtEffptnumberOfPixelHits_;
   TH1F* h1_PtEffptnumberOfMuonHits_;
   TH1F* h1_PtEffptnumberOfMatchedStations_;
   TH1F* h1_PtEffptTrackIso_;
   TH1F* h1_PtEffptabsdsy_;
   TH1F* h1_PtEffpfSumChargedHadron_;
   TH1F* h1_PtEffpfSumNeutralHadron_;
   TH1F* h1_PtEffpfPhotonIso_;
   TH1F* h1_FracpfSumChargedHadron_;
   TH1F* h1_FracpfSumNeutralHadron_;
   TH1F* h1_FracpfPhotonIso_;
   TH1F* h1_EtaEffpterror_;
   TH1F* h1_EtaEffptnumberOftrackerLayers_;
   TH1F* h1_EtaEffptnumberOfPixelHits_;
   TH1F* h1_EtaEffptnumberOfMuonHits_;
   TH1F* h1_EtaEffptnumberOfMatchedStations_;
   TH1F* h1_EtaEffptTrackIso_;
   TH1F* h1_EtaEffptabsdsy_;
   TH1F* h1_nbPVID_;
   TH1F* h1_PtID_;
   TH1F* h1_EtaID_;
   TH1F* h1_nbPVNewID_;
   TH1F* h1_PtNewID_;
   TH1F* h1_EtaNewID_;
   TH1F* h1_nbPVTightID_;
   TH1F* h1_PtTightID_;
   TH1F* h1_EtaTightID_;
   ofstream output_txt; 
   TH1F* h1_PtResolutionMBT_;
   TH1F* h1_PtResolutionTunePMBT_;
   TH1F* h1_PtResolutiontuneP_;
   TH1F* h1_MassResultionEBEB1_;
   TH1F* h1_MassResultionEBEB2_;
   TH1F* h1_MassResultionEBEB3_;
   TH1F* h1_MassResultionEBEB4_;
   TH1F* h1_MassResultionEBEB5_;
   TH1F* h1_MassResultionEBEB6_;
   TH1F* h1_MassResultionEBEB7_;
   TH1F* h1_MassResultionEBEB8_;
   TH1F* h1_MassResultionEBEB9_;
   TH1F* h1_MassResultionEBEB10_; 
   TH1F* h1_MassGenInAccep_;
   TH1F* h1_MassRecoInAccep_;
   TH1F* h1_CosAngleCollinSoperCorrect60Mass120_;
   TH1F* h1_CosAngleCollinSoperCorrect120Mass300_;
   TH1F* h1_CosAngleCollinSoperCorrect300Mass700_;
   TH1F* h1_CosAngleCollinSoperCorrect700Mass3000_;
   TH1F* h1_CosAngleCollinSoperCorrect4900Mass5100_;
   TH1F* h1_absCosAngleCollinSoperCorrect4500Mass5500_;
   TH1F* h1_ptHistoBefor_;
   TH1F* h1_ptHistoPassingVtxChi2Mu_;
   TH1F* h1_ptHistoPassingCosmicRejec_;
   TH1F* h1_ptHistoPassingHLT_;
   TH1F* h1_etaHistoBefor_;
   TH1F* h1_etaHistoPassingVtxChi2Mu_;
   TH1F* h1_etaHistoPassingCosmicRejec_;
   TH1F* h1_etaHistoPassingHLT_;
   TH1F* h1_3DangleHisto1_;
   TH1F* h1_3DangleHisto2_;
   TH1F* h1_Fail3DangleHistoMass_;
   TH1F* h1_Fail3DangleHistoPhi_;
   TH1F* h_ptHistoFRDum_;
   TH1F* h_ptHistoFRNum_;
   TH1F* h1_ZprimeRecomass50_;
   TH1F* h1_ZprimeRecomassBB_;
   TH1F* h1_ZprimeRecomassEE_;
   TH1F* h1_ZprimeRecomassBE_;
   TH1F* h1_ZprimeRecomass20_;      
   TH2F* h2_ZprimeRecomassNewbin_;
   TH1F *h1_ZprimeRecomassBinWidth_;
   int NbFireHLT;
   TH1F *h_NbFireHLT;
   TH1F* h1_ptAfterTrigger_;
   TH1F* h1_ptBeforeTrigger_;
   TH1F* h1_PtTuneP_;
};

#endif

#ifdef ZprimeMuMuPatMiniAod_cxx
ZprimeMuMuPatMiniAod::ZprimeMuMuPatMiniAod(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("CMSSW763_MC_DYtoMuMu_13TeV_pattuple200.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("CMSSW763_MC_DYtoMuMu_13TeV_pattuple200.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

ZprimeMuMuPatMiniAod::~ZprimeMuMuPatMiniAod()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t ZprimeMuMuPatMiniAod::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t ZprimeMuMuPatMiniAod::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void ZprimeMuMuPatMiniAod::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   iGen = 0;
   idGen = 0;
   statusGen = 0;
   ptGen = 0;
   etaGen = 0;
   phiGen = 0;
   chargeGen = 0;
   EnergyGen = 0;
   pxGen = 0;
   pyGen = 0;
   pzGen = 0;
   Ele_nbElectrons = 0;
   Ele_isEcalDrivenSeed = 0;
   Ele_isPassConversionVeto = 0;
   Ele_charge = 0;
   Ele_nbOfMissingHits = 0;
   Ele_nbVtx = 0;
   Ele_Et = 0;
   Ele_EtFromCaloEn = 0;
   Ele_pt = 0;
   Ele_thetaSC = 0;
   Ele_etaSC = 0;
   Ele_phiSC = 0;
   Ele_energySC = 0;
   Ele_preshowerEnergySC = 0;
   Ele_thetaTrack = 0;
   Ele_etaTrack = 0;
   Ele_phiTrack = 0;
   Ele_hadronicOverEm = 0;
   Ele_deltaEtaInSeedCluster = 0;
   Ele_deltaPhiInSeedCluster = 0;
   Ele_deltaEtaInSC = 0;
   Ele_deltaPhiInSC = 0;
   Ele_sigmaIetaIeta = 0;
   Ele_e2x5Max = 0;
   Ele_e1x5 = 0;
   Ele_frac15 = 0;
   Ele_frac51 = 0;
   Ele_e5x5 = 0;
   Ele3x3 = 0;
   Ele_e2x5MaxOver5x5 = 0;
   Ele_e1x5Over5x5 = 0;
   Ele_sigmaIetaIetaFull5x5 = 0;
   Ele_e2x5MaxFull5x5 = 0;
   Ele_e1x5Full5x5 = 0;
   Ele_e5x5Full5x5 = 0;
   Ele_e2x5MaxOver5x5Full5x5 = 0;
   Ele_e1x5Over5x5Full5x5 = 0;
   Ele_e2x5Right = 0;
   Ele_e2x5Left = 0;
   Ele_e2x5Top = 0;
   Ele_e2x5Bottom = 0;
   Ele_eMax = 0;
   Ele_eRight = 0;
   Ele_eLeft = 0;
   Ele_eTop = 0;
   Ele_eBottom = 0;
   Ele_dxy = 0;
   Ele_dz = 0;
   Ele_rhoIso = 0;
   Ele_fbrem = 0;
   Ele_EoverP = 0;
   Ele_Xposition = 0;
   Ele_Yposition = 0;
   Ele_EcalPlusHcald1iso = 0;
   Ele_dr03TkSumPt = 0;
   Ele_dr03EcalRecHitSumEt = 0;
   Ele_dr03HcalDepth1TowerSumEt = 0;
   Ele_dr03HcalDepth1TowerSumEtBc = 0;
   Ele_hcalDepth1OverEcal = 0;
   Ele_hcalDepth2OverEcal = 0;
   Ele_dr03HcalDepth2TowerSumEt = 0;
   Ele_hcalDepth2TowerSumEtNoVeto = 0;
   Ele_hcalDepth1TowerSumEtNoVeto = 0;
   Ele_pfSumPhotonEt = 0;
   Ele_pfSumChargedHadronPt = 0;
   Ele_pfSumNeutralHadronEt = 0;
   Ele_pfSumPUPt = 0;
   Ele_pfDeltaBeta = 0;
   Ele_rawId = 0;
   Ele_x = 0;
   Ele_y = 0;
   Ele_z = 0;
   Ele_zTrackPositionAtVtx = 0;
   Ele_ieta = 0;
   Ele_phiWidth = 0;
   Ele_etaWidth = 0;
   ecaleb_rawId = 0;
   ecaleb_iRechit = 0;
   ecaleb_RecoFlag = 0;
   ecaleb_isSaturated = 0;
   ecaleb_EnRecHit = 0;
   ecaleb_iskleadingedgerecovered = 0;
   ecaleb_iskNeighboursRecovered = 0;
   ecaleb_kWeird = 0;
   ecaleb_ietaRecHit = 0;
   ecaleb_iphiRecHit = 0;
   ecaleb_eta = 0;
   ecaleb_phi = 0;
   ecaleb_time = 0;
   ecalee_rawId = 0;
   ecalee_iRechit = 0;
   ecalee_RecoFlag = 0;
   ecalee_isSaturated = 0;
   ecalee_EnRecHit = 0;
   ecalee_iskleadingedgerecovered = 0;
   ecalee_iskNeighboursRecovered = 0;
   ecalee_kWeird = 0;
   ecalee_ietaRecHit = 0;
   ecalee_iphiRecHit = 0;
   ecalee_eta = 0;
   ecalee_phi = 0;
   ecalee_time = 0;
   Mu_nbMuon = 0;
   Mu_isGlobalMuon = 0;
   Mu_isPF = 0;
   Mu_isTrackerMuon = 0;
   Mu_et = 0;
   Mu_en = 0;
   Mu_pt = 0;
   Mu_eta = 0;
   Mu_phi = 0;
   Mu_charge = 0;
   Mu_ptTunePMuonBestTrack = 0;
   Mu_pxTunePMuonBestTrack = 0;
   Mu_pyTunePMuonBestTrack = 0;
   Mu_pzTunePMuonBestTrack = 0;
   Mu_pTunePMuonBestTrack = 0;
   Mu_etaTunePMuonBestTrack = 0;
   Mu_phiTunePMuonBestTrack = 0;
   Mu_thetaTunePMuonBestTrack = 0;
   Mu_chargeTunePMuonBestTrack = 0;
   Mu_dPToverPTTunePMuonBestTrack = 0;
   Mu_absdxyTunePMuonBestTrack = 0;
   Mu_absdzTunePMuonBestTrack = 0;
   Mu_ptInnerTrack = 0;
   Mu_normalizedChi2 = 0;
   Mu_vtxMass = 0;
   Mu_vtxNormChi2 = 0;
   Mu_vtxMassLept = 0;
   Mu_numberOfMatchedStations = 0;
   Mu_numberOfValidPixelHits = 0;
   Mu_numberOfValidMuonHits = 0;
   Mu_numberOftrackerLayersWithMeasurement = 0;
   Mu_emIso = 0;
   Mu_hadIso = 0;
   Mu_trackiso = 0;
   Mu_pfSumChargedHadronPt = 0;
   Mu_pfSumNeutralHadronEt = 0;
   Mu_PFSumPhotonEt = 0;
   Mu_pfSumPUPt = 0;
   Mu_nbofpv = 0;
   Mu_pfDeltaBeta = 0;
   Mu_patDeltaBeta = 0;
   HLT_nb = 0;
   HLT_name = 0;
   HLT_isaccept = 0;
   HLTObj_nbObj = 0;
   HLTObj_pt = 0;
   HLTObj_eta = 0;
   HLTObj_phi = 0;
   HLTObj_collection = 0;
   nbPv = 0;
   Nbdof = 0;
   PositionRho = 0;
   PositionX = 0;
   PositionY = 0;
   PositionZ = 0;
   jet_nb = 0;
   jetcharge = 0;
   jetet = 0;
   jetpt = 0;
   jeteta = 0;
   jetphi = 0;
   MC_weighting = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("event_runNo", &event_runNo, &b_event_runNo);
   fChain->SetBranchAddress("event_evtNo", &event_evtNo, &b_event_evtNo);
   fChain->SetBranchAddress("event_lumi", &event_lumi, &b_event_lumi);
   fChain->SetBranchAddress("event_bunch", &event_bunch, &b_event_bunch);
   fChain->SetBranchAddress("iGen", &iGen, &b_iGen);
   fChain->SetBranchAddress("idGen", &idGen, &b_idGen);
   fChain->SetBranchAddress("statusGen", &statusGen, &b_statusGen);
   fChain->SetBranchAddress("ptGen", &ptGen, &b_ptGen);
   fChain->SetBranchAddress("etaGen", &etaGen, &b_etaGen);
   fChain->SetBranchAddress("phiGen", &phiGen, &b_phiGen);
   fChain->SetBranchAddress("chargeGen", &chargeGen, &b_chargeGen);
   fChain->SetBranchAddress("EnergyGen", &EnergyGen, &b_EnergyGen);
   fChain->SetBranchAddress("pxGen", &pxGen, &b_pxGen);
   fChain->SetBranchAddress("pyGen", &pyGen, &b_pyGen);
   fChain->SetBranchAddress("pzGen", &pzGen, &b_pzGen);
   fChain->SetBranchAddress("Ele_nbElectrons", &Ele_nbElectrons, &b_Ele_nbElectrons);
   fChain->SetBranchAddress("Ele_isEcalDrivenSeed", &Ele_isEcalDrivenSeed, &b_Ele_isEcalDrivenSeed);
   fChain->SetBranchAddress("Ele_isPassConversionVeto", &Ele_isPassConversionVeto, &b_Ele_isPassConversionVeto);
   fChain->SetBranchAddress("Ele_charge", &Ele_charge, &b_Ele_charge);
   fChain->SetBranchAddress("Ele_nbOfMissingHits", &Ele_nbOfMissingHits, &b_Ele_nbOfMissingHits);
   fChain->SetBranchAddress("Ele_nbVtx", &Ele_nbVtx, &b_Ele_nbVtx);
   fChain->SetBranchAddress("Ele_Et", &Ele_Et, &b_Ele_Et);
   fChain->SetBranchAddress("Ele_EtFromCaloEn", &Ele_EtFromCaloEn, &b_Ele_EtFromCaloEn);
   fChain->SetBranchAddress("Ele_pt", &Ele_pt, &b_Ele_pt);
   fChain->SetBranchAddress("Ele_thetaSC", &Ele_thetaSC, &b_Ele_thetaSC);
   fChain->SetBranchAddress("Ele_etaSC", &Ele_etaSC, &b_Ele_etaSC);
   fChain->SetBranchAddress("Ele_phiSC", &Ele_phiSC, &b_Ele_phiSC);
   fChain->SetBranchAddress("Ele_energySC", &Ele_energySC, &b_Ele_energySC);
   fChain->SetBranchAddress("Ele_preshowerEnergySC", &Ele_preshowerEnergySC, &b_Ele_preshowerEnergySC);
   fChain->SetBranchAddress("Ele_thetaTrack", &Ele_thetaTrack, &b_Ele_thetaTrack);
   fChain->SetBranchAddress("Ele_etaTrack", &Ele_etaTrack, &b_Ele_etaTrack);
   fChain->SetBranchAddress("Ele_phiTrack", &Ele_phiTrack, &b_Ele_phiTrack);
   fChain->SetBranchAddress("Ele_hadronicOverEm", &Ele_hadronicOverEm, &b_Ele_hadronicOverEm);
   fChain->SetBranchAddress("Ele_deltaEtaInSeedCluster", &Ele_deltaEtaInSeedCluster, &b_Ele_deltaEtaInSeedCluster);
   fChain->SetBranchAddress("Ele_deltaPhiInSeedCluster", &Ele_deltaPhiInSeedCluster, &b_Ele_deltaPhiInSeedCluster);
   fChain->SetBranchAddress("Ele_deltaEtaInSC", &Ele_deltaEtaInSC, &b_Ele_deltaEtaInSC);
   fChain->SetBranchAddress("Ele_deltaPhiInSC", &Ele_deltaPhiInSC, &b_Ele_deltaPhiInSC);
   fChain->SetBranchAddress("Ele_sigmaIetaIeta", &Ele_sigmaIetaIeta, &b_Ele_sigmaIetaIeta);
   fChain->SetBranchAddress("Ele_e2x5Max", &Ele_e2x5Max, &b_Ele_e2x5Max);
   fChain->SetBranchAddress("Ele_e1x5", &Ele_e1x5, &b_Ele_e1x5);
   fChain->SetBranchAddress("Ele_frac15", &Ele_frac15, &b_Ele_frac15);
   fChain->SetBranchAddress("Ele_frac51", &Ele_frac51, &b_Ele_frac51);
   fChain->SetBranchAddress("Ele_e5x5", &Ele_e5x5, &b_Ele_e5x5);
   fChain->SetBranchAddress("Ele3x3", &Ele3x3, &b_Ele3x3);
   fChain->SetBranchAddress("Ele_e2x5MaxOver5x5", &Ele_e2x5MaxOver5x5, &b_Ele_e2x5MaxOver5x5);
   fChain->SetBranchAddress("Ele_e1x5Over5x5", &Ele_e1x5Over5x5, &b_Ele_e1x5Over5x5);
   fChain->SetBranchAddress("Ele_sigmaIetaIetaFull5x5", &Ele_sigmaIetaIetaFull5x5, &b_Ele_sigmaIetaIetaFull5x5);
   fChain->SetBranchAddress("Ele_e2x5MaxFull5x5", &Ele_e2x5MaxFull5x5, &b_Ele_e2x5MaxFull5x5);
   fChain->SetBranchAddress("Ele_e1x5Full5x5", &Ele_e1x5Full5x5, &b_Ele_e1x5Full5x5);
   fChain->SetBranchAddress("Ele_e5x5Full5x5", &Ele_e5x5Full5x5, &b_Ele_e5x5Full5x5);
   fChain->SetBranchAddress("Ele_e2x5MaxOver5x5Full5x5", &Ele_e2x5MaxOver5x5Full5x5, &b_Ele_e2x5MaxOver5x5Full5x5);
   fChain->SetBranchAddress("Ele_e1x5Over5x5Full5x5", &Ele_e1x5Over5x5Full5x5, &b_Ele_e1x5Over5x5Full5x5);
   fChain->SetBranchAddress("Ele_e2x5Right", &Ele_e2x5Right, &b_Ele_e2x5Right);
   fChain->SetBranchAddress("Ele_e2x5Left", &Ele_e2x5Left, &b_Ele_e2x5Left);
   fChain->SetBranchAddress("Ele_e2x5Top", &Ele_e2x5Top, &b_Ele_e2x5Top);
   fChain->SetBranchAddress("Ele_e2x5Bottom", &Ele_e2x5Bottom, &b_Ele_e2x5Bottom);
   fChain->SetBranchAddress("Ele_eMax", &Ele_eMax, &b_Ele_eMax);
   fChain->SetBranchAddress("Ele_eRight", &Ele_eRight, &b_Ele_eRight);
   fChain->SetBranchAddress("Ele_eLeft", &Ele_eLeft, &b_Ele_eLeft);
   fChain->SetBranchAddress("Ele_eTop", &Ele_eTop, &b_Ele_eTop);
   fChain->SetBranchAddress("Ele_eBottom", &Ele_eBottom, &b_Ele_eBottom);
   fChain->SetBranchAddress("Ele_dxy", &Ele_dxy, &b_Ele_dxy);
   fChain->SetBranchAddress("Ele_dz", &Ele_dz, &b_Ele_dz);
   fChain->SetBranchAddress("Ele_rhoIso", &Ele_rhoIso, &b_Ele_rhoIso);
   fChain->SetBranchAddress("Ele_fbrem", &Ele_fbrem, &b_Ele_fbrem);
   fChain->SetBranchAddress("Ele_EoverP", &Ele_EoverP, &b_Ele_EoverP);
   fChain->SetBranchAddress("Ele_Xposition", &Ele_Xposition, &b_Ele_Xposition);
   fChain->SetBranchAddress("Ele_Yposition", &Ele_Yposition, &b_Ele_Yposition);
   fChain->SetBranchAddress("Ele_EcalPlusHcald1iso", &Ele_EcalPlusHcald1iso, &b_Ele_EcalPlusHcald1iso);
   fChain->SetBranchAddress("Ele_dr03TkSumPt", &Ele_dr03TkSumPt, &b_Ele_dr03TkSumPt);
   fChain->SetBranchAddress("Ele_dr03EcalRecHitSumEt", &Ele_dr03EcalRecHitSumEt, &b_Ele_dr03EcalRecHitSumEt);
   fChain->SetBranchAddress("Ele_dr03HcalDepth1TowerSumEt", &Ele_dr03HcalDepth1TowerSumEt, &b_Ele_dr03HcalDepth1TowerSumEt);
   fChain->SetBranchAddress("Ele_dr03HcalDepth1TowerSumEtBc", &Ele_dr03HcalDepth1TowerSumEtBc, &b_Ele_dr03HcalDepth1TowerSumEtBc);
   fChain->SetBranchAddress("Ele_hcalDepth1OverEcal", &Ele_hcalDepth1OverEcal, &b_Ele_hcalDepth1OverEcal);
   fChain->SetBranchAddress("Ele_hcalDepth2OverEcal", &Ele_hcalDepth2OverEcal, &b_Ele_hcalDepth2OverEcal);
   fChain->SetBranchAddress("Ele_dr03HcalDepth2TowerSumEt", &Ele_dr03HcalDepth2TowerSumEt, &b_Ele_dr03HcalDepth2TowerSumEt);
   fChain->SetBranchAddress("Ele_hcalDepth2TowerSumEtNoVeto", &Ele_hcalDepth2TowerSumEtNoVeto, &b_Ele_hcalDepth2TowerSumEtNoVeto);
   fChain->SetBranchAddress("Ele_hcalDepth1TowerSumEtNoVeto", &Ele_hcalDepth1TowerSumEtNoVeto, &b_Ele_hcalDepth1TowerSumEtNoVeto);
   fChain->SetBranchAddress("Ele_pfSumPhotonEt", &Ele_pfSumPhotonEt, &b_Ele_pfSumPhotonEt);
   fChain->SetBranchAddress("Ele_pfSumChargedHadronPt", &Ele_pfSumChargedHadronPt, &b_Ele_pfSumChargedHadronPt);
   fChain->SetBranchAddress("Ele_pfSumNeutralHadronEt", &Ele_pfSumNeutralHadronEt, &b_Ele_pfSumNeutralHadronEt);
   fChain->SetBranchAddress("Ele_pfSumPUPt", &Ele_pfSumPUPt, &b_Ele_pfSumPUPt);
   fChain->SetBranchAddress("Ele_pfDeltaBeta", &Ele_pfDeltaBeta, &b_Ele_pfDeltaBeta);
   fChain->SetBranchAddress("Ele_rawId", &Ele_rawId, &b_Ele_rawId);
   fChain->SetBranchAddress("Ele_x", &Ele_x, &b_Ele_x);
   fChain->SetBranchAddress("Ele_y", &Ele_y, &b_Ele_y);
   fChain->SetBranchAddress("Ele_z", &Ele_z, &b_Ele_z);
   fChain->SetBranchAddress("Ele_zTrackPositionAtVtx", &Ele_zTrackPositionAtVtx, &b_Ele_zTrackPositionAtVtx);
   fChain->SetBranchAddress("Ele_ieta", &Ele_ieta, &b_Ele_ieta);
   fChain->SetBranchAddress("Ele_phiWidth", &Ele_phiWidth, &b_Ele_phiWidth);
   fChain->SetBranchAddress("Ele_etaWidth", &Ele_etaWidth, &b_Ele_etaWidth);
   fChain->SetBranchAddress("ecaleb_rawId", &ecaleb_rawId, &b_ecaleb_rawId);
   fChain->SetBranchAddress("ecaleb_iRechit", &ecaleb_iRechit, &b_ecaleb_iRechit);
   fChain->SetBranchAddress("ecaleb_RecoFlag", &ecaleb_RecoFlag, &b_ecaleb_RecoFlag);
   fChain->SetBranchAddress("ecaleb_isSaturated", &ecaleb_isSaturated, &b_ecaleb_isSaturated);
   fChain->SetBranchAddress("ecaleb_EnRecHit", &ecaleb_EnRecHit, &b_ecaleb_EnRecHit);
   fChain->SetBranchAddress("ecaleb_iskleadingedgerecovered", &ecaleb_iskleadingedgerecovered, &b_ecaleb_iskleadingedgerecovered);
   fChain->SetBranchAddress("ecaleb_iskNeighboursRecovered", &ecaleb_iskNeighboursRecovered, &b_ecaleb_iskNeighboursRecovered);
   fChain->SetBranchAddress("ecaleb_kWeird", &ecaleb_kWeird, &b_ecaleb_kWeird);
   fChain->SetBranchAddress("ecaleb_ietaRecHit", &ecaleb_ietaRecHit, &b_ecaleb_ietaRecHit);
   fChain->SetBranchAddress("ecaleb_iphiRecHit", &ecaleb_iphiRecHit, &b_ecaleb_iphiRecHit);
   fChain->SetBranchAddress("ecaleb_eta", &ecaleb_eta, &b_ecaleb_eta);
   fChain->SetBranchAddress("ecaleb_phi", &ecaleb_phi, &b_ecaleb_phi);
   fChain->SetBranchAddress("ecaleb_time", &ecaleb_time, &b_ecaleb_time);
   fChain->SetBranchAddress("ecalee_rawId", &ecalee_rawId, &b_ecalee_rawId);
   fChain->SetBranchAddress("ecalee_iRechit", &ecalee_iRechit, &b_ecalee_iRechit);
   fChain->SetBranchAddress("ecalee_RecoFlag", &ecalee_RecoFlag, &b_ecalee_RecoFlag);
   fChain->SetBranchAddress("ecalee_isSaturated", &ecalee_isSaturated, &b_ecalee_isSaturated);
   fChain->SetBranchAddress("ecalee_EnRecHit", &ecalee_EnRecHit, &b_ecalee_EnRecHit);
   fChain->SetBranchAddress("ecalee_iskleadingedgerecovered", &ecalee_iskleadingedgerecovered, &b_ecalee_iskleadingedgerecovered);
   fChain->SetBranchAddress("ecalee_iskNeighboursRecovered", &ecalee_iskNeighboursRecovered, &b_ecalee_iskNeighboursRecovered);
   fChain->SetBranchAddress("ecalee_kWeird", &ecalee_kWeird, &b_ecalee_kWeird);
   fChain->SetBranchAddress("ecalee_ietaRecHit", &ecalee_ietaRecHit, &b_ecalee_ietaRecHit);
   fChain->SetBranchAddress("ecalee_iphiRecHit", &ecalee_iphiRecHit, &b_ecalee_iphiRecHit);
   fChain->SetBranchAddress("ecalee_eta", &ecalee_eta, &b_ecalee_eta);
   fChain->SetBranchAddress("ecalee_phi", &ecalee_phi, &b_ecalee_phi);
   fChain->SetBranchAddress("ecalee_time", &ecalee_time, &b_ecalee_time);
   fChain->SetBranchAddress("Mu_nbMuon", &Mu_nbMuon, &b_Mu_nbMuon);
   fChain->SetBranchAddress("Mu_isGlobalMuon", &Mu_isGlobalMuon, &b_Mu_isGlobalMuon);
   fChain->SetBranchAddress("Mu_isPF", &Mu_isPF, &b_Mu_isPF);
   fChain->SetBranchAddress("Mu_isTrackerMuon", &Mu_isTrackerMuon, &b_Mu_isTrackerMuon);
   fChain->SetBranchAddress("Mu_et", &Mu_et, &b_Mu_et);
   fChain->SetBranchAddress("Mu_en", &Mu_en, &b_Mu_en);
   fChain->SetBranchAddress("Mu_pt", &Mu_pt, &b_Mu_pt);
   fChain->SetBranchAddress("Mu_eta", &Mu_eta, &b_Mu_eta);
   fChain->SetBranchAddress("Mu_phi", &Mu_phi, &b_Mu_phi);
   fChain->SetBranchAddress("Mu_charge", &Mu_charge, &b_Mu_charge);
   fChain->SetBranchAddress("Mu_ptTunePMuonBestTrack", &Mu_ptTunePMuonBestTrack, &b_Mu_ptTunePMuonBestTrack);
   fChain->SetBranchAddress("Mu_pxTunePMuonBestTrack", &Mu_pxTunePMuonBestTrack, &b_Mu_pxTunePMuonBestTrack);
   fChain->SetBranchAddress("Mu_pyTunePMuonBestTrack", &Mu_pyTunePMuonBestTrack, &b_Mu_pyTunePMuonBestTrack);
   fChain->SetBranchAddress("Mu_pzTunePMuonBestTrack", &Mu_pzTunePMuonBestTrack, &b_Mu_pzTunePMuonBestTrack);
   fChain->SetBranchAddress("Mu_pTunePMuonBestTrack", &Mu_pTunePMuonBestTrack, &b_Mu_pTunePMuonBestTrack);
   fChain->SetBranchAddress("Mu_etaTunePMuonBestTrack", &Mu_etaTunePMuonBestTrack, &b_Mu_etaTunePMuonBestTrack);
   fChain->SetBranchAddress("Mu_phiTunePMuonBestTrack", &Mu_phiTunePMuonBestTrack, &b_Mu_phiTunePMuonBestTrack);
   fChain->SetBranchAddress("Mu_thetaTunePMuonBestTrack", &Mu_thetaTunePMuonBestTrack, &b_Mu_thetaTunePMuonBestTrack);
   fChain->SetBranchAddress("Mu_chargeTunePMuonBestTrack", &Mu_chargeTunePMuonBestTrack, &b_Mu_chargeTunePMuonBestTrack);
   fChain->SetBranchAddress("Mu_dPToverPTTunePMuonBestTrack", &Mu_dPToverPTTunePMuonBestTrack, &b_Mu_dPToverPTTunePMuonBestTrack);
   fChain->SetBranchAddress("Mu_absdxyTunePMuonBestTrack", &Mu_absdxyTunePMuonBestTrack, &b_Mu_absdxyTunePMuonBestTrack);
   fChain->SetBranchAddress("Mu_absdzTunePMuonBestTrack", &Mu_absdzTunePMuonBestTrack, &b_Mu_absdzTunePMuonBestTrack);
   fChain->SetBranchAddress("Mu_ptInnerTrack", &Mu_ptInnerTrack, &b_Mu_ptInnerTrack);
   fChain->SetBranchAddress("Mu_normalizedChi2", &Mu_normalizedChi2, &b_Mu_normalizedChi2);
   fChain->SetBranchAddress("Mu_vtxMass", &Mu_vtxMass, &b_Mu_vtxMass);
   fChain->SetBranchAddress("Mu_vtxNormChi2", &Mu_vtxNormChi2, &b_Mu_vtxNormChi2);
   fChain->SetBranchAddress("Mu_vtxMassLept", &Mu_vtxMassLept, &b_Mu_vtxMassLept);
   fChain->SetBranchAddress("Mu_numberOfMatchedStations", &Mu_numberOfMatchedStations, &b_Mu_numberOfMatchedStations);
   fChain->SetBranchAddress("Mu_numberOfValidPixelHits", &Mu_numberOfValidPixelHits, &b_Mu_numberOfValidPixelHits);
   fChain->SetBranchAddress("Mu_numberOfValidMuonHits", &Mu_numberOfValidMuonHits, &b_Mu_numberOfValidMuonHits);
   fChain->SetBranchAddress("Mu_numberOftrackerLayersWithMeasurement", &Mu_numberOftrackerLayersWithMeasurement, &b_Mu_numberOftrackerLayersWithMeasurement);
   fChain->SetBranchAddress("Mu_emIso", &Mu_emIso, &b_Mu_emIso);
   fChain->SetBranchAddress("Mu_hadIso", &Mu_hadIso, &b_Mu_hadIso);
   fChain->SetBranchAddress("Mu_trackiso", &Mu_trackiso, &b_Mu_trackiso);
   fChain->SetBranchAddress("Mu_pfSumChargedHadronPt", &Mu_pfSumChargedHadronPt, &b_Mu_pfSumChargedHadronPt);
   fChain->SetBranchAddress("Mu_pfSumNeutralHadronEt", &Mu_pfSumNeutralHadronEt, &b_Mu_pfSumNeutralHadronEt);
   fChain->SetBranchAddress("Mu_PFSumPhotonEt", &Mu_PFSumPhotonEt, &b_Mu_PFSumPhotonEt);
   fChain->SetBranchAddress("Mu_pfSumPUPt", &Mu_pfSumPUPt, &b_Mu_pfSumPUPt);
   fChain->SetBranchAddress("Mu_nbofpv", &Mu_nbofpv, &b_Mu_nbofpv);
   fChain->SetBranchAddress("Mu_pfDeltaBeta", &Mu_pfDeltaBeta, &b_Mu_pfDeltaBeta);
   fChain->SetBranchAddress("Mu_patDeltaBeta", &Mu_patDeltaBeta, &b_Mu_patDeltaBeta);
   fChain->SetBranchAddress("HLT_nb", &HLT_nb, &b_HLT_nb);
   fChain->SetBranchAddress("HLT_name", &HLT_name, &b_HLT_name);
   fChain->SetBranchAddress("HLT_isaccept", &HLT_isaccept, &b_HLT_isaccept);
   fChain->SetBranchAddress("HLTObj_nbObj", &HLTObj_nbObj, &b_HLTObj_nbObj);
   fChain->SetBranchAddress("HLTObj_pt", &HLTObj_pt, &b_HLTObj_pt);
   fChain->SetBranchAddress("HLTObj_eta", &HLTObj_eta, &b_HLTObj_eta);
   fChain->SetBranchAddress("HLTObj_phi", &HLTObj_phi, &b_HLTObj_phi);
   fChain->SetBranchAddress("HLTObj_collection", &HLTObj_collection, &b_HLTObj_collection);
   fChain->SetBranchAddress("nbPv", &nbPv, &b_nbPv);
   fChain->SetBranchAddress("Nbdof", &Nbdof, &b_Nbdof);
   fChain->SetBranchAddress("PositionRho", &PositionRho, &b_PositionRho);
   fChain->SetBranchAddress("PositionX", &PositionX, &b_PositionX);
   fChain->SetBranchAddress("PositionY", &PositionY, &b_PositionY);
   fChain->SetBranchAddress("PositionZ", &PositionZ, &b_PositionZ);
   fChain->SetBranchAddress("jet_nb", &jet_nb, &b_jet_nb);
   fChain->SetBranchAddress("jetcharge", &jetcharge, &b_jetcharge);
   fChain->SetBranchAddress("jetet", &jetet, &b_jetet);
   fChain->SetBranchAddress("jetpt", &jetpt, &b_jetpt);
   fChain->SetBranchAddress("jeteta", &jeteta, &b_jeteta);
   fChain->SetBranchAddress("jetphi", &jetphi, &b_jetphi);
   fChain->SetBranchAddress("GenMet_pt", &GenMet_pt, &b_GenMet_pt);
   fChain->SetBranchAddress("PFMet_pt_cor", &PFMet_pt_cor, &b_PFMet_pt_cor);
   fChain->SetBranchAddress("PFMet_phi_cor", &PFMet_phi_cor, &b_PFMet_phi_cor);
   fChain->SetBranchAddress("PFMet_en_cor", &PFMet_en_cor, &b_PFMet_en_cor);
   fChain->SetBranchAddress("PFMet_px_cor", &PFMet_px_cor, &b_PFMet_px_cor);
   fChain->SetBranchAddress("PFMet_py_cor", &PFMet_py_cor, &b_PFMet_py_cor);
   fChain->SetBranchAddress("PFMet_pz_cor", &PFMet_pz_cor, &b_PFMet_pz_cor);
   fChain->SetBranchAddress("PFMet_sumEt_cor", &PFMet_sumEt_cor, &b_PFMet_sumEt_cor);
   fChain->SetBranchAddress("PFMet_pt_uncor", &PFMet_pt_uncor, &b_PFMet_pt_uncor);
   fChain->SetBranchAddress("PFMet_phi_uncor", &PFMet_phi_uncor, &b_PFMet_phi_uncor);
   fChain->SetBranchAddress("PFMet_sumEt_uncor", &PFMet_sumEt_uncor, &b_PFMet_sumEt_uncor);
   fChain->SetBranchAddress("CaloMet_pt", &CaloMet_pt, &b_CaloMet_pt);
   fChain->SetBranchAddress("CaloMet_phi", &CaloMet_phi, &b_CaloMet_phi);
   fChain->SetBranchAddress("CaloMet_sumEt", &CaloMet_sumEt, &b_CaloMet_sumEt);
   fChain->SetBranchAddress("METSign", &METSign, &b_METSign);
   fChain->SetBranchAddress("PFMet_shiftedPt_JetEnUp", &PFMet_shiftedPt_JetEnUp, &b_PFMet_shiftedPt_JetEnUp);
   fChain->SetBranchAddress("PFMet_shiftedPt_JetEnDown", &PFMet_shiftedPt_JetEnDown, &b_PFMet_shiftedPt_JetEnDown);
   fChain->SetBranchAddress("num_PU_vertices", &num_PU_vertices, &b_num_PU_vertices);
   fChain->SetBranchAddress("PU_BunchCrossing", &PU_BunchCrossing, &b_PU_BunchCrossing);
   fChain->SetBranchAddress("Rho", &Rho, &b_Rho);
   fChain->SetBranchAddress("MC_weighting", &MC_weighting, &b_MC_weighting);
   Notify();
}

Bool_t ZprimeMuMuPatMiniAod::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void ZprimeMuMuPatMiniAod::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t ZprimeMuMuPatMiniAod::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef ZprimeMuMuPatMiniAod_cxx
