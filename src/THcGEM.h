#ifndef THcGEM_
#define THcGEM_

/////////////////////////////////////////////////////////////////////
//
//   THcGEM
//
/////////////////////////////////////////////////////////////////////

#include "THaEvtTypeHandler.h"
#include "GEMAnalyzer.h"
#include "GEMEvioParser.h"
#include "GEMDataHandler.h"
#include "EventUpdater.h"
//#include "VarDef.h"

class THcGEM : public THaEvtTypeHandler {

public:

   THcGEM(const char*, const char*);
   virtual ~THcGEM();

   Int_t Analyze(THaEvData *evdata);
   virtual EStatus Init( const TDatime& run_time);
   virtual Int_t End( THaRunBase* r=0 );
   virtual Int_t DefineVariables( EMode mode = kDefine );

   void SetConfigFile( const char* name) { fConfigFileName = name; }


protected:

   std::string fConfigFileName;

   GEMAnalyzer* fGEMAnalyzer;
   GEMEvioParser* fParser;
   GEMDataHandler* fHandler;
   EventUpdater* fUpdateEvent;

   Int_t fEvCount;

   ClassDef(THcGEM,0)




};
#endif
