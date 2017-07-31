/**
\class THcGEM
\brief Custom event handler for GEM data
*/

#include "THaEvtTypeHandler.h"
#include "THcGEM.h"
#include "GEMMapping.h"
#include "GEMConfigure.h"
#include "THaCodaData.h"
#include "THaEvData.h"

using namespace std;

THcGEM::THcGEM(const char *name, const char* description)
 : THaEvtTypeHandler(name, description)
{
  fConfigFileName = "config/gem.cfg";
}
THcGEM::~THcGEM()
{
  DefineVariables( kDelete );
}
Int_t THcGEM::Analyze(THaEvData *evdata)
{
  if( !IsMyEvent(evdata->GetEvType()) ) return -1;

  Int_t ndata = evdata->GetEvLength();
  UInt_t* rdata = (UInt_t*) evdata->GetRawDataBuffer();
  
  //  cout << "THcGEM::Analyze " << ndata << " " << rdata[0] << " " << 
  //   evtype << endl;
  // Decode says it want's length, but what it really wants is index
  // of last word of event
  fHandler->Decode(&rdata[2],ndata-3);
  fUpdateEvent->Update();

  fEvCount++;

  return kOK;
}
THaAnalysisObject::EStatus THcGEM::Init(const TDatime& date)
{
  fStatus = kOK;

  // Will want to open the GEM configuration files here
  GEMConfigure* configure = new GEMConfigure(fConfigFileName.c_str());
  configure->LoadConfigure();

  string mapping_file(configure->GetMapping());
  cout<<"Loading GEM Mapping File from:  "<<mapping_file.c_str()<<endl;
  GEMMapping* mapping = GEMMapping::GetInstance();
  mapping->LoadMapping(mapping_file.c_str());

  fGEMAnalyzer = new GEMAnalyzer(configure);
  fParser = fGEMAnalyzer->GetParser();
  fHandler = fGEMAnalyzer->GetHandler();
  fUpdateEvent = fParser->GetEventUpdater();

  // Fake variables for testing
  fEvCount = 0;

  cout << "Calling THaAnalysisObject::Init" << endl;
  EStatus status;
  if (status = THaAnalysisObject::Init( date ) ) 
    return fStatus=status;
  cout << "Called THaAnalysisObject::Init" << endl;

  return kOK;
}
Int_t THcGEM::End( THaRunBase* r)
{
  fGEMAnalyzer->ProcessResults();
  return 0;
}
Int_t THcGEM::DefineVariables( EMode mode )
{
  cout << " In THcGEM::DefineVariables" << endl;
  // Define/delete global variables.

  if( mode == kDefine && fIsSetup ) return kOK;
  fIsSetup = ( mode == kDefine );
  
  RVarDef vars[] = {
    { "gemevcount", "Evcount as test", "fEvCount" },
    {0}
  };

  cout << " Doing DefineVarsFromList" << endl;
  return DefineVarsFromList( vars, mode);
}

    