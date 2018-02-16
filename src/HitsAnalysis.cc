/*!
  \file                HitsAnalysis.cc
  \brief               Example user code for Analysis
  \author              Suvankar Roy Chowdhury, Rajarshi Bhattacharya
  \date                05/07/16
  Support :            mail to : suvankar.roy.chowdhury@cern.ch, rajarshi.bhattacharya@cern.ch
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
    hist_->bookHitsRelatedHistograms();
  }
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

  long int den = 0;
  long int nClsb = 0, nClst = 0, numstub = 0;

  int nhits10(0), nhit20(0);
  int nhits11(0), nhit21(0);
  int ncl10(0), ncl20(0);
  int ncl11(0), ncl21(0);

  for (Long64_t jentry=0; jentry < maxEvent_; jentry++) {
    clearEvent();
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

 
	//----------------- check allignment--------------------

	int nStrips = (*modVec())[0].nstrips_;
	double DUT_z = (*modVec())[0].z;

	setDetChannelVectors();
	const auto& d0c0 = (*modVec())[0].bottomHits;
	const auto& d1c0 = (*modVec())[0].topHits;
	const auto& d0Cls = (*modVec())[0].bottomOfflineCls;
	const auto& d1Cls = (*modVec())[0].topOfflineCls;
	
	std::vector<tbeam::OfflineTrack>  selectedTk = event()->tracks;
	if (selectedTk.size()!=1) continue;
	if (selectedTk[0].chi2()>5.) continue;
	
	auto& tk0 = event()->tracks[0];
	std::pair<double, double> xTkAtDUT_micron = Utility::extrapolateTrackAtDUTwithAngles(tk0, telPlaneprev_.z, offsetbottom(), zDUTbottom(), 
											     sensordeltaZ(), dutangle(), shiftPlanes(), 
											     bottomsensorPhi(), topsensorPhi());


	double D0xDUT;
	double D1xDUT;
	
	if (d0Cls.size()==1){
	  for(auto& cl : d0Cls ) {
	    D0xDUT = (cl.center()-nStrips/2)*dutpitch();


	    //std::cout<<" cl.center  "<< cl.center() << " track   "<<  (-xTkAtDUT_micron.first /1000/dutpitch() + nStrips/2) << std::endl; // --convert position to the strip number
	    D0xDUT = -D0xDUT;
	    if (cl.size()==1) {hist_->fillHist1D("HitsRelated","d0_1tk1Cls_1Hit_diffX_afterAlignment", D0xDUT-xTkAtDUT_micron.first/1000.); }
	    if (cl.size()==2) hist_->fillHist1D("HitsRelated","d0_1tk2Cls_1Hit_diffX_afterAlignment", D0xDUT-xTkAtDUT_micron.first/1000.);
	    hist_->fillHist1D("HitsRelated","d0_1tk1Cls_allHit_diffX_afterAlignment", D0xDUT-xTkAtDUT_micron.first/1000.);
	  }
	}
	
	
	
	if (d1Cls.size()==1){
	  for(auto& cl : d1Cls ) {
	    D1xDUT = (cl.center()-nStrips/2)*dutpitch();
	    D1xDUT = -D1xDUT;
	    if (cl.size()==1) hist_->fillHist1D("HitsRelated","d1_1tk1Cls_1Hit_diffX_afterAlignment", D1xDUT-xTkAtDUT_micron.second/1000.);
	    if (cl.size()==2) hist_->fillHist1D("HitsRelated","d1_1tk2Cls_1Hit_diffX_afterAlignment", D1xDUT-xTkAtDUT_micron.second/1000.);
	    hist_->fillHist1D("HitsRelated","d1_1tk1Cls_allHit_diffX_afterAlignment", D1xDUT-xTkAtDUT_micron.second/1000.);
	  }
	}
  

	//---------------------  matching efficiency --------------------------

	// --------------------  clusters            ------------------------
	double deltaXmatching_mm = 1;
	if (d0Cls.size()==1){
	  for(auto& cl : d0Cls ) {
	    D0xDUT = -(cl.center()-nStrips/2)*dutpitch();
	    int d0ClCenter = cl.center();
	    if (cl.size()==1){
	      hist_->fillHist1D("HitsRelated","d0_1tk1Cl_beforeMatch", d0ClCenter);
	      if(fabs(D0xDUT - xTkAtDUT_micron.second/1000.) < deltaXmatching_mm) hist_->fillHist1D("HitsRelated","d0_1tk1Cl_afterMatch", d0ClCenter);
	    }
	    if (cl.size()==2){
	      hist_->fillHist1D("HitsRelated","d0_1tk2Cl_beforeMatch", d0ClCenter);
	      if(fabs(D0xDUT - xTkAtDUT_micron.second/1000.) < deltaXmatching_mm) hist_->fillHist1D("HitsRelated","d0_1tk2Cl_afterMatch", d0ClCenter);
	    }
	    hist_->fillHist1D("HitsRelated","d0_1tkAllCl_beforeMatch", d0ClCenter);
	    if(fabs(D0xDUT - xTkAtDUT_micron.second/1000.) < deltaXmatching_mm) hist_->fillHist1D("HitsRelated","d0_1tkAllCl_afterMatch", d0ClCenter);
	    hist_->fillHist1D("HitsRelated","ClusterSize", cl.size());
	    if(fabs(D0xDUT - xTkAtDUT_micron.second/1000.) < deltaXmatching_mm){ hist_->fillHist1D("HitsRelated","MatchedClusterSize",cl.size() );
		hist_->fillHist1D("HitsRelated","d0_Cluster_size_matched", cl.size()); 
	      }
	    hist_->fillHist1D("HitsRelated","d0_Cluster_size", cl.size()); 
	  }
	}


	if (d1Cls.size()==1){
	  for(auto& cl : d1Cls ) {
	    D1xDUT = -(cl.center()-nStrips/2)*dutpitch();
	    int d1ClCenter = cl.center();
	    if (cl.size()==1){
	      hist_->fillHist1D("HitsRelated","d1_1tk1Cl_beforeMatch", d1ClCenter);
	      if(fabs(D1xDUT - xTkAtDUT_micron.second/1000.) < deltaXmatching_mm) hist_->fillHist1D("HitsRelated","d1_1tk1Cl_afterMatch", d1ClCenter);
	    }
	    if (cl.size()==2){
	      hist_->fillHist1D("HitsRelated","d1_1tk2Cl_beforeMatch", d1ClCenter);
	      if(fabs(D1xDUT - xTkAtDUT_micron.second/1000.) < deltaXmatching_mm) hist_->fillHist1D("HitsRelated","d1_1tk2Cl_afterMatch", d1ClCenter);
	    }
	    hist_->fillHist1D("HitsRelated","d1_1tkAllCl_beforeMatch", d1ClCenter);
	    if(fabs(D1xDUT - xTkAtDUT_micron.second/1000.) < deltaXmatching_mm){ hist_->fillHist1D("HitsRelated","d1_1tkAllCl_afterMatch", d1ClCenter); 
	      hist_->fillHist1D("HitsRelated","d1_Cluster_size_matched", cl.size()); 
	    }
	    hist_->fillHist1D("HitsRelated","d1_Cluster_size", cl.size()); 
	  }
	}
 

	// --------------------  hits               ------------------------
	int ntotalhits(0);
	int nmatchedhits(0);
	for(int i =0; i < d0c0.size(); i++) {
	  ntotalhits++;
	  double D0xDUT;
	  D0xDUT = -(d0c0[i].strip()-nStrips/2)*dutpitch();
	   if(fabs(D0xDUT - xTkAtDUT_micron.second/1000.) < deltaXmatching_mm)nmatchedhits++;
	}
	hist_->fillHist1D("HitsRelated" ,"NHits", ntotalhits);
	hist_->fillHist1D("HitsRelated" ,"NMatchedHits", nmatchedhits);






	if(d0c0.size() >0){
	  
	  nhits10++;
	  double D0xDUT;



	  if(d0c0.size()==1){
	   
	    int strip = d0c0[0].strip();
	    D0xDUT = -(strip-nStrips/2)*dutpitch();
	    hist_->fillHist1D("HitsRelated","d0_1tk1Hit_beforeMatch", strip);
	    if(fabs(D0xDUT - xTkAtDUT_micron.second/1000.) < deltaXmatching_mm) hist_->fillHist1D("HitsRelated","d0_1tk1Hit_afterMatch",strip );
	  }
	  if(d0c0.size()==2){
	   
	    int strip = (d0c0[0].strip() + d0c0[1].strip() )*0.5;
	    D0xDUT = -(strip-nStrips/2)*dutpitch();
	    hist_->fillHist1D("HitsRelated","d0_1tk2Hit_beforeMatch", strip);
	    if(fabs(D0xDUT - xTkAtDUT_micron.second/1000.) < deltaXmatching_mm) hist_->fillHist1D("HitsRelated","d0_1tk2Hit_afterMatch",strip );
	  }
	  if(d0c0.size()==3){
	    int strip = (d0c0[0].strip() + d0c0[2].strip() )*0.5;
	    D0xDUT = -(strip-nStrips/2)*dutpitch();
	    hist_->fillHist1D("HitsRelated","d0_1tk3Hit_beforeMatch", strip);
	    if(fabs(D0xDUT - xTkAtDUT_micron.second/1000.) < deltaXmatching_mm){ hist_->fillHist1D("HitsRelated","d0_1tk3Hit_afterMatch",strip ); }
	  }
	  if(d0c0.size()==1 || d0c0.size()==2  || d0c0.size()==3  ){//|| d0c0.size()==4 || d0c0.size()==5  || d0c0.size()==6  || d0c0.size()==7 || d0c0.size()==8  || d0c0.size()==9   ){
	    hist_->fillHist1D("HitsRelated","Hits_det0", 1);
	    if(fabs(D0xDUT - xTkAtDUT_micron.second/1000.) < deltaXmatching_mm){  hist_->fillHist1D("HitsRelated","Hits_det0_matched", 1);}
	  }

	}



	if(d1c0.size() >0){
	  
	  nhits11++;
	  double D1xDUT;
	  if(d1c0.size()==1){
	    int strip = d0c0[0].strip();
	    D1xDUT = -(strip-nStrips/2)*dutpitch();
	    hist_->fillHist1D("HitsRelated","d1_1tk1Hit_beforeMatch", strip);
	    if(fabs(D1xDUT - xTkAtDUT_micron.second/1000.) < deltaXmatching_mm) hist_->fillHist1D("HitsRelated","d1_1tk1Hit_afterMatch",strip );
	  }
	  if(d1c0.size()==2){
	    int strip = (d1c0[0].strip() + d1c0[1].strip() )*0.5;
	    D1xDUT = -(strip-nStrips/2)*dutpitch();
	    hist_->fillHist1D("HitsRelated","d1_1tk2Hit_beforeMatch", strip);
	    if(fabs(D1xDUT - xTkAtDUT_micron.second/1000.) < deltaXmatching_mm) hist_->fillHist1D("HitsRelated","d1_1tk2Hit_afterMatch",strip );
	  }
	  if(d1c0.size()==3){

	    int strip = (d1c0[0].strip() + d1c0[2].strip() )*0.5;
	    D1xDUT = -(strip-nStrips/2)*dutpitch();
	    hist_->fillHist1D("HitsRelated","d1_1tk3Hit_beforeMatch", strip);
	    if(fabs(D1xDUT - xTkAtDUT_micron.second/1000.) < deltaXmatching_mm){ hist_->fillHist1D("HitsRelated","d1_1tk3Hit_afterMatch",strip );}
	  }

	  if(d1c0.size()==1 || d1c0.size()==2  || d1c0.size()==3 ){//|| d1c0.size()==4 || d1c0.size()==5  || d1c0.size()==6  || d1c0.size()==7 || d1c0.size()==8  || d1c0.size()==9   ){
	    hist_->fillHist1D("HitsRelated","Hits_det1", 1);
	    if(fabs(D0xDUT - xTkAtDUT_micron.second/1000.) < deltaXmatching_mm){  hist_->fillHist1D("HitsRelated","Hits_det1_matched", 1);}
	      }
	}






	hist_->fillHist1D("HitsRelated","numberTracks", event()->tracks.size());
	hist_->fillHist2D("HitsRelated", "NTracksVsBottomHits", event()->tracks.size(), d0c0.size());
	hist_->fillHist2D("HitsRelated", "NTracksVsUpperHits", event()->tracks.size(), d1c0.size());
	
	
    if(event()->tracks.size()==1)
      {
	setDetChannelVectors();
	const auto& d0c0 = (*modVec())[0].bottomHits;
	const auto& d1c0 = (*modVec())[0].topHits;
	const auto& d0Cls = (*modVec())[0].bottomOfflineCls;
	const auto& d1Cls = (*modVec())[0].topOfflineCls;
	
	std::vector<tbeam::OfflineTrack>  selectedTk = event()->tracks;
	if (selectedTk.size()!=1) continue;
	if (selectedTk[0].chi2()>5.) continue;


	auto& tk = event()->tracks[0];


	//	std::pair<double, double> xTkAtDUT11 = Utility::extrapolateTrackAtDUTwithAngles(selectedTk[0], refPlaneZ, resultBothPlanesConstraintShiftPhi[0], resultBothPlanesConstraintShiftPhi[1], resultBothPlanesConstraintShiftPhi[2], resultBothPlanesConstraintShiftPhi[3], resultBothPlanesConstraintShiftPhi[4], resultBothPlanesConstraintShiftPhi[5], resultBothPlanesConstraintShiftPhi[6]);
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

	    if (d0Cls.size()==1){
	      for(auto& cl : d0Cls ) {
		float	D0xDUT = (cl.center()-nStrips/2)*dutpitch();
		D0xDUT = -D0xDUT;
		if (cl.size()==1) hist_->fillHist1D("HitsRelated","AllignmentTest", D0xDUT-xTkAtDUT_micron.first/1000.);
	      }
	    }
       
	    //hist_->fillHist1D(dnamebottom, "d0_1tk1Hit_diffX_start", xDUT-xTkAtDUT/1000.);


	    if(d0c0.size() ==1){
	      float xDUT = (d0c0[0].strip() - nStrips/2) * dutpitch();
	      //  std::cout<<"xDut "<< xDUT <<" trackatDut  "<<TrackPosAtDUT.first/1000. <<std::endl;
	    }

	    hist_->fillHist1D("HitsRelated","UpDownHitsDeltaPos", x0-x1);
	   
	    hist_->fillHist1D("HitsRelated","chi2", selectedTk[0].chi2());
	    hist_->fillHist2D("HitsRelated", "UpDownStrips", x0, x1);
	  
	    // std::cout<<"   size 0 "<< d0c0.size() << " strip  "  << d0c0[0].strip()<<std::endl;
	    // std::cout<<"   size 1 "<< d1c0.size() << " strip  "  << d1c0[0].strip()<<std::endl;


	    //   std::cout<<"sizes:    "<< d0c0.size() << "    " <<d1c0.size() <<" strip  "  << d0c0[0].strip()<<"   " <<d1c0[0].strip()<<std::endl;
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
    float resultBothPlanesConstraintShift[] = {-18.8072, -114101., 2400.02, -0.980538, 18.5594};
    //Select events with one track
    if ( event()->tracks.size() !=1 ) continue;
    auto& tk = event()->tracks[0];
    //Select tracks with chi2 > 5
    if (tk.chi2()>5.) continue;
    den++;
    auto& m = modVec()->at(0);

    std::string dnamebottom = m.hdirbottom_ + "/TrackMatch";
    std::string dnametop    = m.hdirtop_ + "/TrackMatch";
    //extrapolate the track. x direction is accross the strips
    //xTkAtDUT is a pair of the extrapolated position of the tk in the two planes of the module
    //xTkAtDUT.first will give the position of the track on  bottom sensor
    //xTkAtDUT.second will give the position of the track on top sensor
    // std::pair<double, double> xTkAtDUT = Utility::extrapolateTrackAtDUTwithAngles(tk, m.z, offsetbottom(), zDUTbottom(), sensordeltaZ(), dutangle(), shiftPlanes());
    std::pair<double, double> xTkAtDUT = xTkAtDUT_micron;//Utility::extrapolateTrackAtDUTwithAngles(tk, telPlaneprev_.z, offsetbottom(), zDUTbottom(),sensordeltaZ(), dutangle(), shiftPlanes(), bottomsensorPhi(), topsensorPhi());
    //std::cout<<"first second   "<< xTkAtDUT.first<<"  "<< xTkAtDUT.second <<std::endl;
    //extrapolate along y direction
    float yTkAtDUT_bottom = ( tk.yPosPrevHit() + (zDUTbottom() - m.z)*tk.dydz() )/1000.;
    float yTkAtDUT_top = ( tk.yPosPrevHit() + (zDUTbottom() + sensordeltaZ() - m.z)*tk.dydz() )/1000.;

  
    if(d0c0.size()==1){
      int strip = d0c0[0].strip();
      D0xDUT = -(strip-nStrips/2)*dutpitch();
      //std::cout<<" yTkAtDUT_bottom  " << yTkAtDUT_bottom <<" D0xDUT  " <<D0xDUT << "  " << xTkAtDUT.first/1000<< std::endl;
      hist_->fillHist2D("HitsRelated", "HitsScanLower", strip, yTkAtDUT_bottom);
    }
   if(d1c0.size()==1){
      int strip = d1c0[0].strip();
      D1xDUT = -(strip-nStrips/2)*dutpitch();
      //std::cout<<" yTkAtDUT_bottom  " << yTkAtDUT_bottom <<" D0xDUT  " <<D0xDUT << "  " << xTkAtDUT.first/1000<< std::endl;
      hist_->fillHist2D("HitsRelated", "HitsScanUpper", strip, yTkAtDUT_top);
    }




   
    // float yTkAtDUT_bottom = tk.yPos() + (zDUTbottom() - m.z)*tk.dydz();
    // float yTkAtDUT_top    = tk.yPos() + (zDUTbottom() + sensordeltaZ() - m.z)*tk.dydz();
    hist_->fillHist1D(dnamebottom, "tkposx", xTkAtDUT.first);
    hist_->fillHist1D(dnametop,    "tkposx", xTkAtDUT.second); 
    //convert tk xpos to strip number
    int xTkAtDUT_strip_bottom = xTkAtDUT.first/m.pitch_  + m.nstrips_/2.;
    int xTkAtDUT_strip_top    = xTkAtDUT.second/m.pitch_ + m.nstrips_/2.;

    //  std::cout<<" xTkAtDUT_strip_bottom  "<< xTkAtDUT_strip_bottom <<"   "<< xTkAtDUT_strip_top <<std::endl;


    hist_->fillHist1D(dnamebottom, "trackpos_strip", xTkAtDUT_strip_bottom);
    hist_->fillHist1D(dnametop,    "trackpos_strip", xTkAtDUT_strip_top); 

    bool mCls_bottom = false;
    bool mCls_top = false;
    bool mOfflinestub = false;   
    //Fill cluster residuals
    for(auto& c: m.bottomOfflineCls) {
      float cx = -1.*(c.center() - m.nstrips_/2.)*m.pitch_;
      hist_->fillHist1D(dnamebottom, "clusresidualX", cx - xTkAtDUT.first);//xTkAtDUT.first since bottom sensor
      if(std::abs(cx - xTkAtDUT.first) < 100.)    {
        mCls_bottom = true;
        hist_->fillHist2D(dnamebottom, "moduleSize_Cluster", c.center(), yTkAtDUT_bottom/1000.);
        hist_->fillHist1D(dnamebottom, "matchedclusterpos_strip", c.center()); 
      }
    }

    for(auto& c: m.topOfflineCls) {
      float cx = -1.*(c.center() - m.nstrips_/2.)*m.pitch_;
      hist_->fillHist1D(dnamebottom, "clusresidualX", cx - xTkAtDUT.second);//xTkAtDUT.second since top sensor
      if(std::abs(cx - xTkAtDUT.first) < 100.)  {
        mCls_top = true;
        hist_->fillHist2D(dnametop, "moduleSize_Cluster", c.center(), yTkAtDUT_top/1000.);
        hist_->fillHist1D(dnametop, "matchedclusterpos_strip", c.center());
      }
    }
    //stub residual
    for(auto& s: m.offlineStubs) {
      float sx = -1.*(s.positionX() - m.nstrips_/2.)*m.pitch_;
      hist_->fillHist1D(dnamebottom, "stubresidualX", sx - xTkAtDUT.first);//xTkAtDUT.first since bottom sensor
      if(std::abs(sx - xTkAtDUT.first) < 100.)    mOfflinestub = true;
    }
    
    //Increment counters if matching is found
    if(mCls_bottom)   nClsb++;
    if(mCls_top)      nClst++;
    if(mOfflinestub)  numstub++;
  }//event Loop end
  std::cout << "Den=" << den << "\t#ClustersBottom=" << nClsb << "\t#ClustersTop=" << nClst << "\tStub=" << numstub << std::endl;

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
