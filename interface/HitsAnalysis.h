#ifndef HitsAnalysis_h
#define HitsAnalysis_h

#include "BeamAnaBase.h"

#include "TString.h"
//#include "Utility.h"
#include "Histogrammer.h"

class TH1;
class HitsAnalysis : public BeamAnaBase {
 public:
  HitsAnalysis();
  ~HitsAnalysis();
  void beginJob();
  void eventLoop();
  void bookHistograms();
  void printEfficiency();
  void clearEvent();
  void endJob();

 private:
  //std::string outFile_;
  Histogrammer* hist_;
  unsigned long int nEntries_;
  unsigned long int maxEvent_;
};
#endif
