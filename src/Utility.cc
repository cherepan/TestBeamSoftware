#include "Utility.h"
#include <climits>
#include <cmath>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>
#include "TLorentzVector.h"
#include "TFile.h"
using std::cout;
using std::cerr;
using std::endl;
using std::ios;
using std::setw;

using std::string;

namespace Utility {
  void tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters) {
  
    // Skip delimiters at beginning.
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
  
    // Find first "non-delimiter".
    std::string::size_type pos = str.find_first_of(delimiters, lastPos);
  
    while (std::string::npos != pos || string::npos != lastPos)  {
      // Found a token, add it to the vector.
      tokens.push_back(str.substr(lastPos, pos - lastPos));
    
      // Skip delimiters.  Note the "not_of"
      lastPos = str.find_first_not_of(delimiters, pos);
    
      // Find next "non-delimiter"
      pos = str.find_first_of(delimiters, lastPos);
    }
  }

  void fillHistofromVec( const std::vector<int>& vec, const char* h) {
    for( unsigned int i = 0; i<vec.size(); i++ ) {
      Utility::fillHist1D(h,vec[i]);
    }
  }

  void fill2DHistofromVec( const std::vector<int>& vecC0, const std::vector<int>& vecC1,const char* h) {
    for( unsigned int i = 0; i<vecC0.size(); i++ ) {
      Utility::fillHist2D(h,vecC0[i],0);
    }
    for( unsigned int i = 0; i<vecC1.size(); i++ ) {
      Utility::fillHist2D(h,1015-vecC1[i],1);
    }
  }


  void getInfofromClusterVec(const std::vector<Cluster>& cvec,const std::string det, TFile* fout, const TString col) {
    fout->cd(TString(det));
    Utility::fillHist1D( "ncluster" + col, cvec.size() );
    for( unsigned int i =0; i<cvec.size(); i++ ) {
      Utility::fillHist1D("clusterWidth" + col,cvec[i].width);
      Utility::fillHist1D("clusterPos" + col,cvec[i].position);
      Utility::fillHistProfile("clusterWidthVsPosProf" + col,cvec[i].position,cvec[i].width);
      Utility::fillHist2D("clusterWidthVsPos2D" + col,cvec[i].position,cvec[i].width);
    }
  }

  // ------------------------------------------------------------------------
  // Convenience routine for filling 1D histograms. We rely on root to keep 
  // track of all the histograms that are booked all over so that we do not 
  // have to use any global variables to save the histogram pointers. Instead, 
  // we use the name of the histograms and gROOT to retrieve them from the 
  // Root object pool whenever necessary. This is the closest one can go to 
  // hbook and ID based histogramming
  // -------------------------------------------------------------------------
  
  TH1* getHist1D(const char* hname) {
    TObject *obj = gDirectory->GetList()->FindObject(hname); 
    if (!obj) {
      std::cerr << "**** getHist1D: Histogram for <" << hname << "> not found!" << std::endl;
      return 0;
    }
    TH1 *h = 0;
    if (obj->InheritsFrom("TH1D"))
      h = dynamic_cast<TH1D*>(obj);
    else if (obj->InheritsFrom("TH1C"))
      h = dynamic_cast<TH1C*>(obj);
    //else if (obj->InheritsFrom("TH1K"))
    //  h = dynamic_cast<TH1K*>(obj);
    else if (obj->InheritsFrom("TH1S"))
      h = dynamic_cast<TH1S*>(obj);
    else if (obj->InheritsFrom("TH1I"))
      h = dynamic_cast<TH1I*>(obj);
    else
      h = dynamic_cast<TH1F*>(obj);
    
    if (!h) {
      std::cerr << "**** getHist1D: <" << hname << "> may not be a 1D Histogram" << std::endl;
      return 0;
    }
    return h;
  }
  
  TH1* getHist1D(const string& hname) {
    return getHist1D(hname.c_str());
  }
  // ---------------------------------------------
  // Convenience routine for filling 2D histograms
  // ---------------------------------------------
  TH2* getHist2D(const char* hname) {
    TObject *obj = gDirectory->GetList()->FindObject(hname); 
    if (!obj) {
      cerr << "**** getHist2D: Histogram for <" << hname << "> not found!" << endl;
      return nullptr;
    }
    
    TH2 *h = nullptr;
    if (obj->InheritsFrom("TH2D"))
      h = dynamic_cast<TH2D*>(obj);
    else if (obj->InheritsFrom("TH2C"))
      h = dynamic_cast<TH2C*>(obj);
    else if (obj->InheritsFrom("TH2S"))
      h = dynamic_cast<TH2S*>(obj);
    else if (obj->InheritsFrom("TH2I"))
      h = dynamic_cast<TH2I*>(obj);
    else
      h = dynamic_cast<TH2F*>(obj);
    
    if (!h) {
      cerr << "**** getHist2D: <<" << hname << ">> may not be a 2D Histogram" << endl;
      return nullptr;
    }
    return h;
  }
  TH2* getHist2D(const string& hname) {
    return getHist2D(hname.c_str());
  }

  TProfile* getHistProfile(const char* hname) {
    TObject *obj = gDirectory->GetList()->FindObject(hname);
    if (!obj) {
      cerr << "**** getHistProfile: Histogram for <" << hname << "> not found!" << endl;
      return nullptr;
    }
    TProfile *h = nullptr;
    if (obj->InheritsFrom("TProfile"))
      h = dynamic_cast<TProfile*>(obj);

    if (!h) {
      cerr << "**** getHistProfile: <<" << hname << ">> may not be a 2Profile Histogram" << endl;
      return nullptr;
    }
    return h;
  }
  TProfile* getHistProfile(const string& hname) {
    return getHistProfile(hname.c_str());
  }

}
