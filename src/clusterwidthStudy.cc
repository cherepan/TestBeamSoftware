#include <iostream>
#include <cstdlib>
#include <string>
#include "TROOT.h"
#include "TStopwatch.h"
#include "ClusterWidthAnalysis.h"
//#include "ReconstructionFromRaw.h"
#include "argvparser.h"
using std::cout;
using std::cerr;
using std::endl;

using namespace CommandLineProcessing;

int main( int argc,char* argv[] ){
   
  ArgvParser cmd;
  cmd.setIntroductoryDescription( "Offline Analysis Application for beam test data" );
  cmd.setHelpOption( "h", "help", "Print this help page" );
  cmd.addErrorCode( 0, "Success" );
  cmd.addErrorCode( 1, "Error" );
  cmd.defineOption( "iFile", "Input RawTuple name", ArgvParser::OptionRequiresValue);
  cmd.defineOption( "tFile", "Telescope tuple file name", ArgvParser::OptionRequiresValue);
  cmd.defineOption( "oFile", "Output file name", ArgvParser::OptionRequiresValue);  
  cmd.defineOption( "raw", "Tuple type is Raw. Default is EDM", ArgvParser::NoOptionAttribute);  
  cmd.defineOption( "sw", "Stub Window. Default = 7", ArgvParser::NoOptionAttribute);
  cmd.defineOption( "clsw", "Cluster Size cut. Default = 3", ArgvParser::NoOptionAttribute);
  cmd.defineOption( "telMatch", "Do Telescope matching. Default = false", ArgvParser::NoOptionAttribute); 
  cmd.defineOption( "png", "Produce png files for web. Default = false", ArgvParser::NoOptionAttribute); 
  int result = cmd.parse( argc, argv );
  if (result != ArgvParser::NoParserError)
  {
    cout << cmd.parseErrorDescription(result);
    exit(1);
  }

  std::string inFilename = ( cmd.foundOption( "iFile" ) ) ? cmd.optionValue( "iFile" ) : "";
  
  if ( inFilename.empty() ) {
    std::cerr << "Error, no input file provided. Quitting" << std::endl;
    exit( 1 );
  }

  std::string telFilename = ( cmd.foundOption( "tFile" ) ) ? cmd.optionValue( "tFile" ) : "";
  if ( telFilename.empty() ) {
    std::cerr << "Error, no telescope filename provided. Quitting" << std::endl;
    exit( 1 );
  }

  std::string outFilename = ( cmd.foundOption( "oFile" ) ) ? cmd.optionValue( "oFile" ) : "";
  if ( outFilename.empty() ) {
    std::cerr << "Error, no output filename provided. Quitting" << std::endl;
    exit( 1 );
  }


  bool isRaw = ( cmd.foundOption( "raw" ) ) ? true:false;
  float stubWindow = ( cmd.foundOption( "sw" ) ) ? std::stod(cmd.optionValue( "sw")) : 7;
  int clustSize = ( cmd.foundOption( "clsw" ) ) ? std::stoi(cmd.optionValue( "clsw")) : 3;
  bool doTelmatch = ( cmd.foundOption( "telMatch" ) ) ? true : false;
  bool publishPng = ( cmd.foundOption( "png" ) ) ? true : false;
  
  std::cout << "isRaw=" << isRaw << std::endl;  
  //Let's roll
  TStopwatch timer;
  timer.Start();
  //ClusterWidthAnalysis(const string inFilename,const string telFileName,const string outFilename,int stubWindow,
  //                     int clustSize, bool doTelmatch)
  ClusterWidthAnalysis tr(inFilename,telFilename,outFilename,stubWindow,clustSize,doTelmatch);
  std::cout << "Event Loop start" << std::endl;
  tr.eventLoop();
  tr.endJob();
  timer.Stop();
  cout << "Realtime/CpuTime = " << timer.RealTime() << "/" << timer.CpuTime() << endl;
  return 0;
}