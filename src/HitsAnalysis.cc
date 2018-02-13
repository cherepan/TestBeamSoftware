/*!
  \file                HitsAnalysis.cc
  \author              Vladimir Cherepanov
  \date                18/01/18

*/
#include "TROOT.h"
#include "TInterpreter.h"
#include "TH1.h"
#include "TH2.h"
#include "TF1.h"
#include "TKey.h"
#include "TClass.h"
#include "TDirectory.h"
#include "TCanvas.h"
#include <map>
#include <utility>
#include <vector>
#include <sstream>

#include "HitsAnalysis.h"
using std::vector;
using std::map;
HitsAnalysis::HitsAnalysis() :
  BeamAnaBase::BeamAnaBase()
{
}
void HitsAnalysis::bookHistograms() {
  BeamAnaBase::bookHistograms();
 
  for(auto& m : *modVec()){
    //std::cout << "Detidbottom=" << m.hdirbottom_ << std::endl;
    TString s = TString(m.hdirbottom_);
    hist_->bookTrackMatchHistograms(s);
    s = TString(m.hdirtop_);
    hist_->bookTrackMatchHistograms(s);
  }
  std::cout<<"is called "<<std::endl;
  hist_->bookHitsRelatedHistograms();
}

void HitsAnalysis::beginJob() {
  BeamAnaBase::beginJob();
  nEntries_ = analysisTree()->GetEntries();
  hist_ = outFile();
  setAddresses();
  bookHistograms();
  //analysisTree()->GetEntry(0);
  //getCbcConfig(condEv()->cwd, condEv()->window);
}

void HitsAnalysis::eventLoop()
{
  Long64_t nbytes = 0, nb = 0;
  maxEvent_ = getMaxEvt();
  if(nEntries_ < maxEvent_ || maxEvent_ == 0) maxEvent_ = nEntries_;
  cout << "#Events=" << nEntries_ <<" -->  MAX EVENTS TO BE PROCESSED : "<< maxEvent_ <<endl;
  hist_->fillHist1D("EventInfo","nevents", nEntries_);

  for (Long64_t jentry=0; jentry < maxEvent_; jentry++) {
    clearEvent();

    //    if(event()->tracks.size()==1){
  
    Long64_t ientry = analysisTree()->GetEntry(jentry);
    if (ientry < 0) break;
    if (jentry%1000 == 0) {
      cout << " Events processed. " << std::setw(8) << jentry
	   << endl;
    }
    if(jentry==0) {
      hist_->fillHist1D("EventInfo","hvSettings", event()->HVsettings);
      hist_->fillHist1D("EventInfo","dutAngle", event()->DUTangle);
      //hist_->fillHist1D("EventInfo","vcth", event()->vcth);
      //hist_->fillHist1D("EventInfo","offset", cbcOffset1());
      //hist_->fillHist1D("EventInfo","offset", cbcOffset2());
      //hist_->fillHist1D("EventInfo","window", event()->cwd);
      //hist_->fillHist1D("EventInfo","tilt", static_cast<unsigned long int>(condEv()->tilt));



      cout << "Alignment Parameters" << aLparameteres();
      for(auto& cm: event()->conddatamap){
        uint8_t uid = (cm.first >> 24) & MASK_BITS_8;
        uint8_t i2cReg  = (cm.first >> 16)  & MASK_BITS_8;
        uint8_t i2cPage = (cm.first >> 12)  & MASK_BITS_4;
        uint8_t roId    = (cm.first >> 8)   & MASK_BITS_4;
        uint8_t feId    = (cm.first)        & MASK_BITS_8;
        std::cout << "uid=" << (int)uid
                  << ":i2cReg="<< (int)i2cReg
                  << ":i2cPage="<< (int)i2cPage
                  << ":roId="<< (int)roId
                  << ":feId="<< (int)feId
                  << ":value=" << (int)cm.second
                  << std::endl;
        //if(uid == 1)
        //  std::cout << "Value for uid=1>>>" << (int)cm.second << std::endl;
      }

    }
    hist_->fillHist1D("HitsRelated","numberTracks", event()->tracks.size());
    const auto& d0c0 = (*modVec())[0].bottomHits;
    const auto& d1c0 = (*modVec())[0].topHits;
    hist_->fillHist2D("HitsRelated", "NTracksVsBottomHits", event()->tracks.size(), d0c0.size());
    hist_->fillHist2D("HitsRelated", "NTracksVsUpperHits", event()->tracks.size(), d1c0.size());
    if(event()->tracks.size()==1)
      {
	std::vector<tbeam::OfflineTrack> selectedTk = event()->tracks;

	if (selectedTk[0].chi2()<5.){

	  
	  hist_->fillHist2D("HitsRelated", "NHitsCorrelation", d0c0.size(), d1c0.size());

	  if(d0c0.size() >0 && d1c0.size() > 0)
	  {
	    //	    float xTkAtDUT = Utility::extrapolateTrackAtDUTwithAngles(selectedTk[0], refPlaneZ, 0, -556212., 0.);
	    double x0(0),x1(0);
	    if(d0c0.size()==1) x0=d0c0[0].strip();
	    if(d1c0.size()==1) x1=d1c0[0].strip();
	    if(d0c0.size()==2) x0=(d0c0[0].strip() + d0c0[1].strip())*0.5;
	    if(d1c0.size()==2) x1=(d1c0[0].strip() + d1c0[1].strip())*0.5;
	    if(d0c0.size()==3) x0=(d0c0[0].strip() + d0c0[2].strip())*0.5;
	    if(d1c0.size()==3) x1=(d1c0[0].strip() + d1c0[2].strip())*0.5;

	    if(d0c0.size()==4) x0=(d0c0[0].strip() + d0c0[3].strip())*0.5;
	    if(d1c0.size()==4) x1=(d1c0[0].strip() + d1c0[3].strip())*0.5;

	    if(d0c0.size()==5) x0=(d0c0[0].strip() + d0c0[4].strip())*0.5;
	    if(d1c0.size()==5) x1=(d1c0[0].strip() + d1c0[4].strip())*0.5;

	    if(d0c0.size()==6) x0=(d0c0[0].strip() + d0c0[5].strip())*0.5;
	    if(d1c0.size()==6) x1=(d1c0[0].strip() + d1c0[5].strip())*0.5;

	    if(d0c0.size()==7) x0=(d0c0[0].strip() + d0c0[6].strip())*0.5;
	    if(d1c0.size()==7) x1=(d1c0[0].strip() + d1c0[6].strip())*0.5;

	    if(d0c0.size()==8) x0=(d0c0[0].strip() + d0c0[7].strip())*0.5;
	    if(d1c0.size()==8) x1=(d1c0[0].strip() + d1c0[7].strip())*0.5;

	    if(d0c0.size()==9) x0=(d0c0[0].strip() + d0c0[8].strip())*0.5;
	    if(d1c0.size()==9) x1=(d1c0[0].strip() + d1c0[8].strip())*0.5;


	    hist_->fillHist1D("HitsRelated","UpDownHitsDeltaPos", x0-x1);
	   
	    hist_->fillHist1D("HitsRelated","chi2", selectedTk[0].chi2());
	    hist_->fillHist2D("HitsRelated", "UpDownStrips", x0, x1);
	  
	    // std::cout<<"   size 0 "<< d0c0.size() << " strip  "  << d0c0[0].strip()<<std::endl;
	    // std::cout<<"   size 1 "<< d1c0.size() << " strip  "  << d1c0[0].strip()<<std::endl;


	    std::cout<<"sizes:    "<< d0c0.size() << "    " <<d1c0.size() <<" strip  "  << d0c0[0].strip()<<"   " <<d1c0[0].strip()<<std::endl;
	  }
	}
      }


	hist_->fillHist1D("EventInfo","condData", static_cast<unsigned int>(event()->condData));
	hist_->fillHist1D("EventInfo","tdcPhase", static_cast<unsigned int>(event()->tdcPhase));
	//set the hits/cluster/stubs from the sensors in user accessable module
	setDetChannelVectors();
	//fill common histograms for dut hits, clusters
	fillCommonHistograms();
	//Fill track match histograms
	for(auto& m : *modVec()){
	  std::string dnamebottom = m.hdirbottom_ + "/TrackMatch";
	  //loop over tracks
	  for(auto& tk: event()->tracks) {
	    //previous hit
	    float xtk_prev = tk.xPosPrevHit() + std::abs(m.z - telPlaneprev_.z)*tk.dxdz();
	    float ytk_prev = tk.yPosPrevHit() + std::abs(m.z - telPlaneprev_.z)*tk.dydz();
	    hist_->fillHist1D(dnamebottom, "tkposx_prev", xtk_prev/1000.);
	    hist_->fillHist1D(dnamebottom, "tkposy_prev", ytk_prev/1000.);
	    //next hit
	    float xtk_next = tk.xPosNextHit() + std::abs(m.z - telPlaneprev_.z)*tk.dxdz();
	    float ytk_next = tk.yPosNextHit() + std::abs(m.z - telPlaneprev_.z)*tk.dydz();
	    hist_->fillHist1D(dnamebottom, "tkposx_next", xtk_next/1000.);
	    hist_->fillHist1D(dnamebottom, "tkposy_next", ytk_next/1000.);
	    //Fill hit residuals
	    for(auto& h: m.bottomHits) {
	      float hx = (h.strip() - m.nstrips_/2.)*m.pitch_;
	      hist_->fillHist1D(dnamebottom, "hitresidualX_prev", hx - xtk_prev/1000.);
	      hist_->fillHist1D(dnamebottom, "hitresidualX_next", hx - xtk_next/1000.);
	    }
	    //Fill cluster residuals
	    for(auto& c: m.bottomOfflineCls) {
	      float cx = (c.center() - m.nstrips_/2.)*m.pitch_;
	      hist_->fillHist1D(dnamebottom, "clusresidualX_prev", cx - xtk_prev/1000.);
	      hist_->fillHist1D(dnamebottom, "clusresidualX_next", cx - xtk_next/1000.);
	    }
	  }
	}
      
    //}
  }

}

void HitsAnalysis::clearEvent() {
  BeamAnaBase::clearEvent();
}

void HitsAnalysis::endJob() {
  BeamAnaBase::endJob();
  hist_->closeFile();
}

HitsAnalysis::~HitsAnalysis(){
  delete hist_;
}
