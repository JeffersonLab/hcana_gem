#ifndef GEMEvtHandler_
#define GEMEvtHandler_

/////////////////////////////////////////////////////////////////////
//
//   GEMEvtHandler
//
/////////////////////////////////////////////////////////////////////

#include "THaEvtTypeHandler.h"
#include "GEMAnalyzer.h"
#include "GEMEvioParser.h"
#include "GEMDataHandler.h"
#include "EventUpdater.h"

class GEMEvtHandler : public THaEvtTypeHandler {

public:

   GEMEvtHandler(const char*, const char*);
   virtual ~GEMEvtHandler();

   Int_t Analyze(THaEvData *evdata);
   virtual EStatus Init( const TDatime& run_time);
   virtual Int_t End( THaRunBase* r=0 );
   void SetConfigFile( const char* name) { fConfigFileName = name; }

protected:

   std::string fConfigFileName;

   GEMAnalyzer* fGEMAnalyzer;
   GEMEvioParser* fParser;
   GEMDataHandler* fHandler;
   EventUpdater* fUpdateEvent;

   ClassDef(GEMEvtHandler,0)




};
#endif
