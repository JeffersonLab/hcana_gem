// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME srcdIDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "THcGEMDataProcessor.h"
#include "THcGEMPhysics.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_THcGEMDataProcessor(void *p = 0);
   static void *newArray_THcGEMDataProcessor(Long_t size, void *p);
   static void delete_THcGEMDataProcessor(void *p);
   static void deleteArray_THcGEMDataProcessor(void *p);
   static void destruct_THcGEMDataProcessor(void *p);
   static void streamer_THcGEMDataProcessor(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::THcGEMDataProcessor*)
   {
      ::THcGEMDataProcessor *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::THcGEMDataProcessor >(0);
      static ::ROOT::TGenericClassInfo 
         instance("THcGEMDataProcessor", ::THcGEMDataProcessor::Class_Version(), "THcGEMDataProcessor.h", 18,
                  typeid(::THcGEMDataProcessor), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::THcGEMDataProcessor::Dictionary, isa_proxy, 16,
                  sizeof(::THcGEMDataProcessor) );
      instance.SetNew(&new_THcGEMDataProcessor);
      instance.SetNewArray(&newArray_THcGEMDataProcessor);
      instance.SetDelete(&delete_THcGEMDataProcessor);
      instance.SetDeleteArray(&deleteArray_THcGEMDataProcessor);
      instance.SetDestructor(&destruct_THcGEMDataProcessor);
      instance.SetStreamerFunc(&streamer_THcGEMDataProcessor);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::THcGEMDataProcessor*)
   {
      return GenerateInitInstanceLocal((::THcGEMDataProcessor*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::THcGEMDataProcessor*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_THcGEMPhysics(void *p = 0);
   static void *newArray_THcGEMPhysics(Long_t size, void *p);
   static void delete_THcGEMPhysics(void *p);
   static void deleteArray_THcGEMPhysics(void *p);
   static void destruct_THcGEMPhysics(void *p);
   static void streamer_THcGEMPhysics(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::THcGEMPhysics*)
   {
      ::THcGEMPhysics *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::THcGEMPhysics >(0);
      static ::ROOT::TGenericClassInfo 
         instance("THcGEMPhysics", ::THcGEMPhysics::Class_Version(), "THcGEMPhysics.h", 31,
                  typeid(::THcGEMPhysics), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::THcGEMPhysics::Dictionary, isa_proxy, 16,
                  sizeof(::THcGEMPhysics) );
      instance.SetNew(&new_THcGEMPhysics);
      instance.SetNewArray(&newArray_THcGEMPhysics);
      instance.SetDelete(&delete_THcGEMPhysics);
      instance.SetDeleteArray(&deleteArray_THcGEMPhysics);
      instance.SetDestructor(&destruct_THcGEMPhysics);
      instance.SetStreamerFunc(&streamer_THcGEMPhysics);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::THcGEMPhysics*)
   {
      return GenerateInitInstanceLocal((::THcGEMPhysics*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::THcGEMPhysics*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr THcGEMDataProcessor::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *THcGEMDataProcessor::Class_Name()
{
   return "THcGEMDataProcessor";
}

//______________________________________________________________________________
const char *THcGEMDataProcessor::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::THcGEMDataProcessor*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int THcGEMDataProcessor::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::THcGEMDataProcessor*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *THcGEMDataProcessor::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::THcGEMDataProcessor*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *THcGEMDataProcessor::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::THcGEMDataProcessor*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr THcGEMPhysics::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *THcGEMPhysics::Class_Name()
{
   return "THcGEMPhysics";
}

//______________________________________________________________________________
const char *THcGEMPhysics::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::THcGEMPhysics*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int THcGEMPhysics::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::THcGEMPhysics*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *THcGEMPhysics::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::THcGEMPhysics*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *THcGEMPhysics::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::THcGEMPhysics*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void THcGEMDataProcessor::Streamer(TBuffer &R__b)
{
   // Stream an object of class THcGEMDataProcessor.

   TObject::Streamer(R__b);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_THcGEMDataProcessor(void *p) {
      return  p ? new(p) ::THcGEMDataProcessor : new ::THcGEMDataProcessor;
   }
   static void *newArray_THcGEMDataProcessor(Long_t nElements, void *p) {
      return p ? new(p) ::THcGEMDataProcessor[nElements] : new ::THcGEMDataProcessor[nElements];
   }
   // Wrapper around operator delete
   static void delete_THcGEMDataProcessor(void *p) {
      delete ((::THcGEMDataProcessor*)p);
   }
   static void deleteArray_THcGEMDataProcessor(void *p) {
      delete [] ((::THcGEMDataProcessor*)p);
   }
   static void destruct_THcGEMDataProcessor(void *p) {
      typedef ::THcGEMDataProcessor current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_THcGEMDataProcessor(TBuffer &buf, void *obj) {
      ((::THcGEMDataProcessor*)obj)->::THcGEMDataProcessor::Streamer(buf);
   }
} // end of namespace ROOT for class ::THcGEMDataProcessor

//______________________________________________________________________________
void THcGEMPhysics::Streamer(TBuffer &R__b)
{
   // Stream an object of class THcGEMPhysics.

   TObject::Streamer(R__b);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_THcGEMPhysics(void *p) {
      return  p ? new(p) ::THcGEMPhysics : new ::THcGEMPhysics;
   }
   static void *newArray_THcGEMPhysics(Long_t nElements, void *p) {
      return p ? new(p) ::THcGEMPhysics[nElements] : new ::THcGEMPhysics[nElements];
   }
   // Wrapper around operator delete
   static void delete_THcGEMPhysics(void *p) {
      delete ((::THcGEMPhysics*)p);
   }
   static void deleteArray_THcGEMPhysics(void *p) {
      delete [] ((::THcGEMPhysics*)p);
   }
   static void destruct_THcGEMPhysics(void *p) {
      typedef ::THcGEMPhysics current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_THcGEMPhysics(TBuffer &buf, void *obj) {
      ((::THcGEMPhysics*)obj)->::THcGEMPhysics::Streamer(buf);
   }
} // end of namespace ROOT for class ::THcGEMPhysics

namespace {
  void TriggerDictionaryInitialization_Dict_Impl() {
    static const char* headers[] = {
"THcGEMDataProcessor.h",
"THcGEMPhysics.h",
0
    };
    static const char* includePaths[] = {
"./src",
"/home/siplu/TOOLS/ROOT/root-6.10/include",
"/mnt/28888C40888C0F0E/GIT/JLAB/HcAna/hcana_gem/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "Dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$THcGEMDataProcessor.h")))  THcGEMDataProcessor;
class __attribute__((annotate("$clingAutoload$THcGEMPhysics.h")))  THcGEMPhysics;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "Dict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "THcGEMDataProcessor.h"
#include "THcGEMPhysics.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"THcGEMDataProcessor", payloadCode, "@",
"THcGEMPhysics", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("Dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_Dict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_Dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_Dict() {
  TriggerDictionaryInitialization_Dict_Impl();
}
