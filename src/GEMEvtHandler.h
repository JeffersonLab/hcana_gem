#ifndef GEMEvtHandler_
#define GEMEvtHandler_

/////////////////////////////////////////////////////////////////////
//
//   GEMEvtHandler
//
/////////////////////////////////////////////////////////////////////

#include "THaEvtTypeHandler.h"

class GEMEvtHandler : public THaEvtTypeHandler {

public:

   GEMEvtHandler(const char*, const char*);
   virtual ~GEMEvtHandler();

   Int_t Analyze(THaEvData *evdata);
   virtual void AddEventType(Int_t evtype);
   virtual EStatus Init( const TDatime& run_time);
   void SetConfigFile( const char* name) { fConfigFileName = name; }

protected:

   std::string fConfigFileName;

   ClassDef(GEMEvtHandler,0)




};
#endif
