#include <iostream>
#include <cstdlib>
#include <string>
#include "TROOT.h"
#include "TStopwatch.h"
#include "HitsAnalysis.h"
using std::cout;
using std::cerr;
using std::endl;

int main( int argc,char* argv[] ){
  if(argc<2)  {
    std::cout << "Jobcard missing.\n./baselinHits <jobcardname>" << std::endl;
    return 1;
  }
  std::string jobfile = argv[1];
  //Let's roll
  TStopwatch timer;
  timer.Start();
  HitsAnalysis r;
  r.readJob(jobfile);
  r.beginJob();
  std::cout << "Event Loop start" << std::endl;
  r.eventLoop();
  r.endJob();
  timer.Stop();
  cout << "Realtime/CpuTime = " << timer.RealTime() << "/" << timer.CpuTime() << endl;
  return 0;
}
