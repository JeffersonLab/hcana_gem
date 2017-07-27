/**
\class GEMEvtHandler
\brief Custom event handler for GEM data
*/

#include "THaEvtTypeHandler.h"
#include "GEMEvtHandler.h"
#include "GEMMapping.h"
#include "GEMConfigure.h"
#include "THaCodaData.h"
#include "THaEvData.h"

using namespace std;

GEMEvtHandler::GEMEvtHandler(const char *name, const char* description)
 : THaEvtTypeHandler(name, description)
{
  fConfigFileName = "config/gem.cfg";
}
GEMEvtHandler::~GEMEvtHandler()
{

}
Int_t GEMEvtHandler::Analyze(THaEvData *evdata)
{
  cout << "Handling GEM event" << endl;

  return kOK;
}
THaAnalysisObject::EStatus GEMEvtHandler::Init(const TDatime& date)
{
  // Will want to open the GEM configuration files here
  GEMConfigure* configure = new GEMConfigure(fConfigFileName.c_str());
  configure->LoadConfigure();

  string mapping_file(configure->GetMapping());
  cout<<"Loading Mapping File from:  "<<mapping_file.c_str()<<endl;
  GEMMapping* mapping = GEMMapping::GetInstance();
  mapping->LoadMapping(mapping_file.c_str());

  return kOK;
}
