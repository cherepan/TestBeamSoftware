// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME Dict

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
#include "interface/Hit.h"
#include "interface/Cluster.h"
#include "interface/Cbc.h"
#include "interface/Stub.h"
#include "interface/Track.h"
#include "interface/Event.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_tbeamcLcLhit(void *p = 0);
   static void *newArray_tbeamcLcLhit(Long_t size, void *p);
   static void delete_tbeamcLcLhit(void *p);
   static void deleteArray_tbeamcLcLhit(void *p);
   static void destruct_tbeamcLcLhit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::tbeam::hit*)
   {
      ::tbeam::hit *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::tbeam::hit >(0);
      static ::ROOT::TGenericClassInfo 
         instance("tbeam::hit", ::tbeam::hit::Class_Version(), "interface/Hit.h", 7,
                  typeid(::tbeam::hit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::tbeam::hit::Dictionary, isa_proxy, 4,
                  sizeof(::tbeam::hit) );
      instance.SetNew(&new_tbeamcLcLhit);
      instance.SetNewArray(&newArray_tbeamcLcLhit);
      instance.SetDelete(&delete_tbeamcLcLhit);
      instance.SetDeleteArray(&deleteArray_tbeamcLcLhit);
      instance.SetDestructor(&destruct_tbeamcLcLhit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::tbeam::hit*)
   {
      return GenerateInitInstanceLocal((::tbeam::hit*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::tbeam::hit*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_tbeamcLcLcluster(void *p = 0);
   static void *newArray_tbeamcLcLcluster(Long_t size, void *p);
   static void delete_tbeamcLcLcluster(void *p);
   static void deleteArray_tbeamcLcLcluster(void *p);
   static void destruct_tbeamcLcLcluster(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::tbeam::cluster*)
   {
      ::tbeam::cluster *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::tbeam::cluster >(0);
      static ::ROOT::TGenericClassInfo 
         instance("tbeam::cluster", ::tbeam::cluster::Class_Version(), "interface/Cluster.h", 7,
                  typeid(::tbeam::cluster), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::tbeam::cluster::Dictionary, isa_proxy, 4,
                  sizeof(::tbeam::cluster) );
      instance.SetNew(&new_tbeamcLcLcluster);
      instance.SetNewArray(&newArray_tbeamcLcLcluster);
      instance.SetDelete(&delete_tbeamcLcLcluster);
      instance.SetDeleteArray(&deleteArray_tbeamcLcLcluster);
      instance.SetDestructor(&destruct_tbeamcLcLcluster);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::tbeam::cluster*)
   {
      return GenerateInitInstanceLocal((::tbeam::cluster*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::tbeam::cluster*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_tbeamcLcLcbc(void *p = 0);
   static void *newArray_tbeamcLcLcbc(Long_t size, void *p);
   static void delete_tbeamcLcLcbc(void *p);
   static void deleteArray_tbeamcLcLcbc(void *p);
   static void destruct_tbeamcLcLcbc(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::tbeam::cbc*)
   {
      ::tbeam::cbc *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::tbeam::cbc >(0);
      static ::ROOT::TGenericClassInfo 
         instance("tbeam::cbc", ::tbeam::cbc::Class_Version(), "interface/Cbc.h", 7,
                  typeid(::tbeam::cbc), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::tbeam::cbc::Dictionary, isa_proxy, 4,
                  sizeof(::tbeam::cbc) );
      instance.SetNew(&new_tbeamcLcLcbc);
      instance.SetNewArray(&newArray_tbeamcLcLcbc);
      instance.SetDelete(&delete_tbeamcLcLcbc);
      instance.SetDeleteArray(&deleteArray_tbeamcLcLcbc);
      instance.SetDestructor(&destruct_tbeamcLcLcbc);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::tbeam::cbc*)
   {
      return GenerateInitInstanceLocal((::tbeam::cbc*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::tbeam::cbc*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_tbeamcLcLstub(void *p = 0);
   static void *newArray_tbeamcLcLstub(Long_t size, void *p);
   static void delete_tbeamcLcLstub(void *p);
   static void deleteArray_tbeamcLcLstub(void *p);
   static void destruct_tbeamcLcLstub(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::tbeam::stub*)
   {
      ::tbeam::stub *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::tbeam::stub >(0);
      static ::ROOT::TGenericClassInfo 
         instance("tbeam::stub", ::tbeam::stub::Class_Version(), "interface/Stub.h", 7,
                  typeid(::tbeam::stub), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::tbeam::stub::Dictionary, isa_proxy, 4,
                  sizeof(::tbeam::stub) );
      instance.SetNew(&new_tbeamcLcLstub);
      instance.SetNewArray(&newArray_tbeamcLcLstub);
      instance.SetDelete(&delete_tbeamcLcLstub);
      instance.SetDeleteArray(&deleteArray_tbeamcLcLstub);
      instance.SetDestructor(&destruct_tbeamcLcLstub);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::tbeam::stub*)
   {
      return GenerateInitInstanceLocal((::tbeam::stub*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::tbeam::stub*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_tbeamcLcLOfflineTrack(void *p = 0);
   static void *newArray_tbeamcLcLOfflineTrack(Long_t size, void *p);
   static void delete_tbeamcLcLOfflineTrack(void *p);
   static void deleteArray_tbeamcLcLOfflineTrack(void *p);
   static void destruct_tbeamcLcLOfflineTrack(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::tbeam::OfflineTrack*)
   {
      ::tbeam::OfflineTrack *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::tbeam::OfflineTrack >(0);
      static ::ROOT::TGenericClassInfo 
         instance("tbeam::OfflineTrack", ::tbeam::OfflineTrack::Class_Version(), "interface/Track.h", 7,
                  typeid(::tbeam::OfflineTrack), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::tbeam::OfflineTrack::Dictionary, isa_proxy, 4,
                  sizeof(::tbeam::OfflineTrack) );
      instance.SetNew(&new_tbeamcLcLOfflineTrack);
      instance.SetNewArray(&newArray_tbeamcLcLOfflineTrack);
      instance.SetDelete(&delete_tbeamcLcLOfflineTrack);
      instance.SetDeleteArray(&deleteArray_tbeamcLcLOfflineTrack);
      instance.SetDestructor(&destruct_tbeamcLcLOfflineTrack);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::tbeam::OfflineTrack*)
   {
      return GenerateInitInstanceLocal((::tbeam::OfflineTrack*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::tbeam::OfflineTrack*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_tbeamcLcLOfflineEvent(void *p = 0);
   static void *newArray_tbeamcLcLOfflineEvent(Long_t size, void *p);
   static void delete_tbeamcLcLOfflineEvent(void *p);
   static void deleteArray_tbeamcLcLOfflineEvent(void *p);
   static void destruct_tbeamcLcLOfflineEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::tbeam::OfflineEvent*)
   {
      ::tbeam::OfflineEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::tbeam::OfflineEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("tbeam::OfflineEvent", ::tbeam::OfflineEvent::Class_Version(), "interface/Event.h", 16,
                  typeid(::tbeam::OfflineEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::tbeam::OfflineEvent::Dictionary, isa_proxy, 4,
                  sizeof(::tbeam::OfflineEvent) );
      instance.SetNew(&new_tbeamcLcLOfflineEvent);
      instance.SetNewArray(&newArray_tbeamcLcLOfflineEvent);
      instance.SetDelete(&delete_tbeamcLcLOfflineEvent);
      instance.SetDeleteArray(&deleteArray_tbeamcLcLOfflineEvent);
      instance.SetDestructor(&destruct_tbeamcLcLOfflineEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::tbeam::OfflineEvent*)
   {
      return GenerateInitInstanceLocal((::tbeam::OfflineEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::tbeam::OfflineEvent*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace tbeam {
//______________________________________________________________________________
atomic_TClass_ptr hit::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *hit::Class_Name()
{
   return "tbeam::hit";
}

//______________________________________________________________________________
const char *hit::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::tbeam::hit*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int hit::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::tbeam::hit*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *hit::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::tbeam::hit*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *hit::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::tbeam::hit*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace tbeam
namespace tbeam {
//______________________________________________________________________________
atomic_TClass_ptr cluster::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *cluster::Class_Name()
{
   return "tbeam::cluster";
}

//______________________________________________________________________________
const char *cluster::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::tbeam::cluster*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int cluster::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::tbeam::cluster*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *cluster::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::tbeam::cluster*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *cluster::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::tbeam::cluster*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace tbeam
namespace tbeam {
//______________________________________________________________________________
atomic_TClass_ptr cbc::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *cbc::Class_Name()
{
   return "tbeam::cbc";
}

//______________________________________________________________________________
const char *cbc::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::tbeam::cbc*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int cbc::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::tbeam::cbc*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *cbc::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::tbeam::cbc*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *cbc::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::tbeam::cbc*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace tbeam
namespace tbeam {
//______________________________________________________________________________
atomic_TClass_ptr stub::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *stub::Class_Name()
{
   return "tbeam::stub";
}

//______________________________________________________________________________
const char *stub::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::tbeam::stub*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int stub::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::tbeam::stub*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *stub::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::tbeam::stub*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *stub::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::tbeam::stub*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace tbeam
namespace tbeam {
//______________________________________________________________________________
atomic_TClass_ptr OfflineTrack::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *OfflineTrack::Class_Name()
{
   return "tbeam::OfflineTrack";
}

//______________________________________________________________________________
const char *OfflineTrack::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::tbeam::OfflineTrack*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int OfflineTrack::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::tbeam::OfflineTrack*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *OfflineTrack::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::tbeam::OfflineTrack*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *OfflineTrack::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::tbeam::OfflineTrack*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace tbeam
namespace tbeam {
//______________________________________________________________________________
atomic_TClass_ptr OfflineEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *OfflineEvent::Class_Name()
{
   return "tbeam::OfflineEvent";
}

//______________________________________________________________________________
const char *OfflineEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::tbeam::OfflineEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int OfflineEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::tbeam::OfflineEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *OfflineEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::tbeam::OfflineEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *OfflineEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::tbeam::OfflineEvent*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace tbeam
namespace tbeam {
//______________________________________________________________________________
void hit::Streamer(TBuffer &R__b)
{
   // Stream an object of class tbeam::hit.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(tbeam::hit::Class(),this);
   } else {
      R__b.WriteClassBuffer(tbeam::hit::Class(),this);
   }
}

} // namespace tbeam
namespace ROOT {
   // Wrappers around operator new
   static void *new_tbeamcLcLhit(void *p) {
      return  p ? new(p) ::tbeam::hit : new ::tbeam::hit;
   }
   static void *newArray_tbeamcLcLhit(Long_t nElements, void *p) {
      return p ? new(p) ::tbeam::hit[nElements] : new ::tbeam::hit[nElements];
   }
   // Wrapper around operator delete
   static void delete_tbeamcLcLhit(void *p) {
      delete ((::tbeam::hit*)p);
   }
   static void deleteArray_tbeamcLcLhit(void *p) {
      delete [] ((::tbeam::hit*)p);
   }
   static void destruct_tbeamcLcLhit(void *p) {
      typedef ::tbeam::hit current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::tbeam::hit

namespace tbeam {
//______________________________________________________________________________
void cluster::Streamer(TBuffer &R__b)
{
   // Stream an object of class tbeam::cluster.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(tbeam::cluster::Class(),this);
   } else {
      R__b.WriteClassBuffer(tbeam::cluster::Class(),this);
   }
}

} // namespace tbeam
namespace ROOT {
   // Wrappers around operator new
   static void *new_tbeamcLcLcluster(void *p) {
      return  p ? new(p) ::tbeam::cluster : new ::tbeam::cluster;
   }
   static void *newArray_tbeamcLcLcluster(Long_t nElements, void *p) {
      return p ? new(p) ::tbeam::cluster[nElements] : new ::tbeam::cluster[nElements];
   }
   // Wrapper around operator delete
   static void delete_tbeamcLcLcluster(void *p) {
      delete ((::tbeam::cluster*)p);
   }
   static void deleteArray_tbeamcLcLcluster(void *p) {
      delete [] ((::tbeam::cluster*)p);
   }
   static void destruct_tbeamcLcLcluster(void *p) {
      typedef ::tbeam::cluster current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::tbeam::cluster

namespace tbeam {
//______________________________________________________________________________
void cbc::Streamer(TBuffer &R__b)
{
   // Stream an object of class tbeam::cbc.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(tbeam::cbc::Class(),this);
   } else {
      R__b.WriteClassBuffer(tbeam::cbc::Class(),this);
   }
}

} // namespace tbeam
namespace ROOT {
   // Wrappers around operator new
   static void *new_tbeamcLcLcbc(void *p) {
      return  p ? new(p) ::tbeam::cbc : new ::tbeam::cbc;
   }
   static void *newArray_tbeamcLcLcbc(Long_t nElements, void *p) {
      return p ? new(p) ::tbeam::cbc[nElements] : new ::tbeam::cbc[nElements];
   }
   // Wrapper around operator delete
   static void delete_tbeamcLcLcbc(void *p) {
      delete ((::tbeam::cbc*)p);
   }
   static void deleteArray_tbeamcLcLcbc(void *p) {
      delete [] ((::tbeam::cbc*)p);
   }
   static void destruct_tbeamcLcLcbc(void *p) {
      typedef ::tbeam::cbc current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::tbeam::cbc

namespace tbeam {
//______________________________________________________________________________
void stub::Streamer(TBuffer &R__b)
{
   // Stream an object of class tbeam::stub.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(tbeam::stub::Class(),this);
   } else {
      R__b.WriteClassBuffer(tbeam::stub::Class(),this);
   }
}

} // namespace tbeam
namespace ROOT {
   // Wrappers around operator new
   static void *new_tbeamcLcLstub(void *p) {
      return  p ? new(p) ::tbeam::stub : new ::tbeam::stub;
   }
   static void *newArray_tbeamcLcLstub(Long_t nElements, void *p) {
      return p ? new(p) ::tbeam::stub[nElements] : new ::tbeam::stub[nElements];
   }
   // Wrapper around operator delete
   static void delete_tbeamcLcLstub(void *p) {
      delete ((::tbeam::stub*)p);
   }
   static void deleteArray_tbeamcLcLstub(void *p) {
      delete [] ((::tbeam::stub*)p);
   }
   static void destruct_tbeamcLcLstub(void *p) {
      typedef ::tbeam::stub current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::tbeam::stub

namespace tbeam {
//______________________________________________________________________________
void OfflineTrack::Streamer(TBuffer &R__b)
{
   // Stream an object of class tbeam::OfflineTrack.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(tbeam::OfflineTrack::Class(),this);
   } else {
      R__b.WriteClassBuffer(tbeam::OfflineTrack::Class(),this);
   }
}

} // namespace tbeam
namespace ROOT {
   // Wrappers around operator new
   static void *new_tbeamcLcLOfflineTrack(void *p) {
      return  p ? new(p) ::tbeam::OfflineTrack : new ::tbeam::OfflineTrack;
   }
   static void *newArray_tbeamcLcLOfflineTrack(Long_t nElements, void *p) {
      return p ? new(p) ::tbeam::OfflineTrack[nElements] : new ::tbeam::OfflineTrack[nElements];
   }
   // Wrapper around operator delete
   static void delete_tbeamcLcLOfflineTrack(void *p) {
      delete ((::tbeam::OfflineTrack*)p);
   }
   static void deleteArray_tbeamcLcLOfflineTrack(void *p) {
      delete [] ((::tbeam::OfflineTrack*)p);
   }
   static void destruct_tbeamcLcLOfflineTrack(void *p) {
      typedef ::tbeam::OfflineTrack current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::tbeam::OfflineTrack

namespace tbeam {
//______________________________________________________________________________
void OfflineEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class tbeam::OfflineEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(tbeam::OfflineEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(tbeam::OfflineEvent::Class(),this);
   }
}

} // namespace tbeam
namespace ROOT {
   // Wrappers around operator new
   static void *new_tbeamcLcLOfflineEvent(void *p) {
      return  p ? new(p) ::tbeam::OfflineEvent : new ::tbeam::OfflineEvent;
   }
   static void *newArray_tbeamcLcLOfflineEvent(Long_t nElements, void *p) {
      return p ? new(p) ::tbeam::OfflineEvent[nElements] : new ::tbeam::OfflineEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_tbeamcLcLOfflineEvent(void *p) {
      delete ((::tbeam::OfflineEvent*)p);
   }
   static void deleteArray_tbeamcLcLOfflineEvent(void *p) {
      delete [] ((::tbeam::OfflineEvent*)p);
   }
   static void destruct_tbeamcLcLOfflineEvent(void *p) {
      typedef ::tbeam::OfflineEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::tbeam::OfflineEvent

namespace ROOT {
   static TClass *vectorlEtbeamcLcLstubgR_Dictionary();
   static void vectorlEtbeamcLcLstubgR_TClassManip(TClass*);
   static void *new_vectorlEtbeamcLcLstubgR(void *p = 0);
   static void *newArray_vectorlEtbeamcLcLstubgR(Long_t size, void *p);
   static void delete_vectorlEtbeamcLcLstubgR(void *p);
   static void deleteArray_vectorlEtbeamcLcLstubgR(void *p);
   static void destruct_vectorlEtbeamcLcLstubgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<tbeam::stub>*)
   {
      vector<tbeam::stub> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<tbeam::stub>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<tbeam::stub>", -2, "vector", 214,
                  typeid(vector<tbeam::stub>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEtbeamcLcLstubgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<tbeam::stub>) );
      instance.SetNew(&new_vectorlEtbeamcLcLstubgR);
      instance.SetNewArray(&newArray_vectorlEtbeamcLcLstubgR);
      instance.SetDelete(&delete_vectorlEtbeamcLcLstubgR);
      instance.SetDeleteArray(&deleteArray_vectorlEtbeamcLcLstubgR);
      instance.SetDestructor(&destruct_vectorlEtbeamcLcLstubgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<tbeam::stub> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<tbeam::stub>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEtbeamcLcLstubgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<tbeam::stub>*)0x0)->GetClass();
      vectorlEtbeamcLcLstubgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEtbeamcLcLstubgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEtbeamcLcLstubgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<tbeam::stub> : new vector<tbeam::stub>;
   }
   static void *newArray_vectorlEtbeamcLcLstubgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<tbeam::stub>[nElements] : new vector<tbeam::stub>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEtbeamcLcLstubgR(void *p) {
      delete ((vector<tbeam::stub>*)p);
   }
   static void deleteArray_vectorlEtbeamcLcLstubgR(void *p) {
      delete [] ((vector<tbeam::stub>*)p);
   }
   static void destruct_vectorlEtbeamcLcLstubgR(void *p) {
      typedef vector<tbeam::stub> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<tbeam::stub>

namespace ROOT {
   static TClass *vectorlEtbeamcLcLhitgR_Dictionary();
   static void vectorlEtbeamcLcLhitgR_TClassManip(TClass*);
   static void *new_vectorlEtbeamcLcLhitgR(void *p = 0);
   static void *newArray_vectorlEtbeamcLcLhitgR(Long_t size, void *p);
   static void delete_vectorlEtbeamcLcLhitgR(void *p);
   static void deleteArray_vectorlEtbeamcLcLhitgR(void *p);
   static void destruct_vectorlEtbeamcLcLhitgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<tbeam::hit>*)
   {
      vector<tbeam::hit> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<tbeam::hit>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<tbeam::hit>", -2, "vector", 214,
                  typeid(vector<tbeam::hit>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEtbeamcLcLhitgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<tbeam::hit>) );
      instance.SetNew(&new_vectorlEtbeamcLcLhitgR);
      instance.SetNewArray(&newArray_vectorlEtbeamcLcLhitgR);
      instance.SetDelete(&delete_vectorlEtbeamcLcLhitgR);
      instance.SetDeleteArray(&deleteArray_vectorlEtbeamcLcLhitgR);
      instance.SetDestructor(&destruct_vectorlEtbeamcLcLhitgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<tbeam::hit> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<tbeam::hit>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEtbeamcLcLhitgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<tbeam::hit>*)0x0)->GetClass();
      vectorlEtbeamcLcLhitgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEtbeamcLcLhitgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEtbeamcLcLhitgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<tbeam::hit> : new vector<tbeam::hit>;
   }
   static void *newArray_vectorlEtbeamcLcLhitgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<tbeam::hit>[nElements] : new vector<tbeam::hit>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEtbeamcLcLhitgR(void *p) {
      delete ((vector<tbeam::hit>*)p);
   }
   static void deleteArray_vectorlEtbeamcLcLhitgR(void *p) {
      delete [] ((vector<tbeam::hit>*)p);
   }
   static void destruct_vectorlEtbeamcLcLhitgR(void *p) {
      typedef vector<tbeam::hit> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<tbeam::hit>

namespace ROOT {
   static TClass *vectorlEtbeamcLcLclustergR_Dictionary();
   static void vectorlEtbeamcLcLclustergR_TClassManip(TClass*);
   static void *new_vectorlEtbeamcLcLclustergR(void *p = 0);
   static void *newArray_vectorlEtbeamcLcLclustergR(Long_t size, void *p);
   static void delete_vectorlEtbeamcLcLclustergR(void *p);
   static void deleteArray_vectorlEtbeamcLcLclustergR(void *p);
   static void destruct_vectorlEtbeamcLcLclustergR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<tbeam::cluster>*)
   {
      vector<tbeam::cluster> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<tbeam::cluster>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<tbeam::cluster>", -2, "vector", 214,
                  typeid(vector<tbeam::cluster>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEtbeamcLcLclustergR_Dictionary, isa_proxy, 0,
                  sizeof(vector<tbeam::cluster>) );
      instance.SetNew(&new_vectorlEtbeamcLcLclustergR);
      instance.SetNewArray(&newArray_vectorlEtbeamcLcLclustergR);
      instance.SetDelete(&delete_vectorlEtbeamcLcLclustergR);
      instance.SetDeleteArray(&deleteArray_vectorlEtbeamcLcLclustergR);
      instance.SetDestructor(&destruct_vectorlEtbeamcLcLclustergR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<tbeam::cluster> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<tbeam::cluster>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEtbeamcLcLclustergR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<tbeam::cluster>*)0x0)->GetClass();
      vectorlEtbeamcLcLclustergR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEtbeamcLcLclustergR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEtbeamcLcLclustergR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<tbeam::cluster> : new vector<tbeam::cluster>;
   }
   static void *newArray_vectorlEtbeamcLcLclustergR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<tbeam::cluster>[nElements] : new vector<tbeam::cluster>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEtbeamcLcLclustergR(void *p) {
      delete ((vector<tbeam::cluster>*)p);
   }
   static void deleteArray_vectorlEtbeamcLcLclustergR(void *p) {
      delete [] ((vector<tbeam::cluster>*)p);
   }
   static void destruct_vectorlEtbeamcLcLclustergR(void *p) {
      typedef vector<tbeam::cluster> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<tbeam::cluster>

namespace ROOT {
   static TClass *vectorlEtbeamcLcLcbcgR_Dictionary();
   static void vectorlEtbeamcLcLcbcgR_TClassManip(TClass*);
   static void *new_vectorlEtbeamcLcLcbcgR(void *p = 0);
   static void *newArray_vectorlEtbeamcLcLcbcgR(Long_t size, void *p);
   static void delete_vectorlEtbeamcLcLcbcgR(void *p);
   static void deleteArray_vectorlEtbeamcLcLcbcgR(void *p);
   static void destruct_vectorlEtbeamcLcLcbcgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<tbeam::cbc>*)
   {
      vector<tbeam::cbc> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<tbeam::cbc>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<tbeam::cbc>", -2, "vector", 214,
                  typeid(vector<tbeam::cbc>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEtbeamcLcLcbcgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<tbeam::cbc>) );
      instance.SetNew(&new_vectorlEtbeamcLcLcbcgR);
      instance.SetNewArray(&newArray_vectorlEtbeamcLcLcbcgR);
      instance.SetDelete(&delete_vectorlEtbeamcLcLcbcgR);
      instance.SetDeleteArray(&deleteArray_vectorlEtbeamcLcLcbcgR);
      instance.SetDestructor(&destruct_vectorlEtbeamcLcLcbcgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<tbeam::cbc> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<tbeam::cbc>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEtbeamcLcLcbcgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<tbeam::cbc>*)0x0)->GetClass();
      vectorlEtbeamcLcLcbcgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEtbeamcLcLcbcgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEtbeamcLcLcbcgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<tbeam::cbc> : new vector<tbeam::cbc>;
   }
   static void *newArray_vectorlEtbeamcLcLcbcgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<tbeam::cbc>[nElements] : new vector<tbeam::cbc>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEtbeamcLcLcbcgR(void *p) {
      delete ((vector<tbeam::cbc>*)p);
   }
   static void deleteArray_vectorlEtbeamcLcLcbcgR(void *p) {
      delete [] ((vector<tbeam::cbc>*)p);
   }
   static void destruct_vectorlEtbeamcLcLcbcgR(void *p) {
      typedef vector<tbeam::cbc> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<tbeam::cbc>

namespace ROOT {
   static TClass *vectorlEtbeamcLcLOfflineTrackgR_Dictionary();
   static void vectorlEtbeamcLcLOfflineTrackgR_TClassManip(TClass*);
   static void *new_vectorlEtbeamcLcLOfflineTrackgR(void *p = 0);
   static void *newArray_vectorlEtbeamcLcLOfflineTrackgR(Long_t size, void *p);
   static void delete_vectorlEtbeamcLcLOfflineTrackgR(void *p);
   static void deleteArray_vectorlEtbeamcLcLOfflineTrackgR(void *p);
   static void destruct_vectorlEtbeamcLcLOfflineTrackgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<tbeam::OfflineTrack>*)
   {
      vector<tbeam::OfflineTrack> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<tbeam::OfflineTrack>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<tbeam::OfflineTrack>", -2, "vector", 214,
                  typeid(vector<tbeam::OfflineTrack>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEtbeamcLcLOfflineTrackgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<tbeam::OfflineTrack>) );
      instance.SetNew(&new_vectorlEtbeamcLcLOfflineTrackgR);
      instance.SetNewArray(&newArray_vectorlEtbeamcLcLOfflineTrackgR);
      instance.SetDelete(&delete_vectorlEtbeamcLcLOfflineTrackgR);
      instance.SetDeleteArray(&deleteArray_vectorlEtbeamcLcLOfflineTrackgR);
      instance.SetDestructor(&destruct_vectorlEtbeamcLcLOfflineTrackgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<tbeam::OfflineTrack> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<tbeam::OfflineTrack>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEtbeamcLcLOfflineTrackgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<tbeam::OfflineTrack>*)0x0)->GetClass();
      vectorlEtbeamcLcLOfflineTrackgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEtbeamcLcLOfflineTrackgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEtbeamcLcLOfflineTrackgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<tbeam::OfflineTrack> : new vector<tbeam::OfflineTrack>;
   }
   static void *newArray_vectorlEtbeamcLcLOfflineTrackgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<tbeam::OfflineTrack>[nElements] : new vector<tbeam::OfflineTrack>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEtbeamcLcLOfflineTrackgR(void *p) {
      delete ((vector<tbeam::OfflineTrack>*)p);
   }
   static void deleteArray_vectorlEtbeamcLcLOfflineTrackgR(void *p) {
      delete [] ((vector<tbeam::OfflineTrack>*)p);
   }
   static void destruct_vectorlEtbeamcLcLOfflineTrackgR(void *p) {
      typedef vector<tbeam::OfflineTrack> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<tbeam::OfflineTrack>

namespace ROOT {
   static TClass *maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR_Dictionary();
   static void maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR_TClassManip(TClass*);
   static void *new_maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR(void *p = 0);
   static void *newArray_maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR(Long_t size, void *p);
   static void delete_maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR(void *p);
   static void deleteArray_maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR(void *p);
   static void destruct_maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<unsigned int,vector<tbeam::cbc> >*)
   {
      map<unsigned int,vector<tbeam::cbc> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<unsigned int,vector<tbeam::cbc> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<unsigned int,vector<tbeam::cbc> >", -2, "map", 96,
                  typeid(map<unsigned int,vector<tbeam::cbc> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(map<unsigned int,vector<tbeam::cbc> >) );
      instance.SetNew(&new_maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR);
      instance.SetNewArray(&newArray_maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR);
      instance.SetDelete(&delete_maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR);
      instance.SetDestructor(&destruct_maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<unsigned int,vector<tbeam::cbc> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<unsigned int,vector<tbeam::cbc> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<unsigned int,vector<tbeam::cbc> >*)0x0)->GetClass();
      maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,vector<tbeam::cbc> > : new map<unsigned int,vector<tbeam::cbc> >;
   }
   static void *newArray_maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,vector<tbeam::cbc> >[nElements] : new map<unsigned int,vector<tbeam::cbc> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR(void *p) {
      delete ((map<unsigned int,vector<tbeam::cbc> >*)p);
   }
   static void deleteArray_maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR(void *p) {
      delete [] ((map<unsigned int,vector<tbeam::cbc> >*)p);
   }
   static void destruct_maplEunsignedsPintcOvectorlEtbeamcLcLcbcgRsPgR(void *p) {
      typedef map<unsigned int,vector<tbeam::cbc> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<unsigned int,vector<tbeam::cbc> >

namespace ROOT {
   static TClass *maplEunsignedsPintcOunsignedsPintgR_Dictionary();
   static void maplEunsignedsPintcOunsignedsPintgR_TClassManip(TClass*);
   static void *new_maplEunsignedsPintcOunsignedsPintgR(void *p = 0);
   static void *newArray_maplEunsignedsPintcOunsignedsPintgR(Long_t size, void *p);
   static void delete_maplEunsignedsPintcOunsignedsPintgR(void *p);
   static void deleteArray_maplEunsignedsPintcOunsignedsPintgR(void *p);
   static void destruct_maplEunsignedsPintcOunsignedsPintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<unsigned int,unsigned int>*)
   {
      map<unsigned int,unsigned int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<unsigned int,unsigned int>));
      static ::ROOT::TGenericClassInfo 
         instance("map<unsigned int,unsigned int>", -2, "map", 96,
                  typeid(map<unsigned int,unsigned int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEunsignedsPintcOunsignedsPintgR_Dictionary, isa_proxy, 0,
                  sizeof(map<unsigned int,unsigned int>) );
      instance.SetNew(&new_maplEunsignedsPintcOunsignedsPintgR);
      instance.SetNewArray(&newArray_maplEunsignedsPintcOunsignedsPintgR);
      instance.SetDelete(&delete_maplEunsignedsPintcOunsignedsPintgR);
      instance.SetDeleteArray(&deleteArray_maplEunsignedsPintcOunsignedsPintgR);
      instance.SetDestructor(&destruct_maplEunsignedsPintcOunsignedsPintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<unsigned int,unsigned int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<unsigned int,unsigned int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEunsignedsPintcOunsignedsPintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<unsigned int,unsigned int>*)0x0)->GetClass();
      maplEunsignedsPintcOunsignedsPintgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEunsignedsPintcOunsignedsPintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEunsignedsPintcOunsignedsPintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,unsigned int> : new map<unsigned int,unsigned int>;
   }
   static void *newArray_maplEunsignedsPintcOunsignedsPintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,unsigned int>[nElements] : new map<unsigned int,unsigned int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEunsignedsPintcOunsignedsPintgR(void *p) {
      delete ((map<unsigned int,unsigned int>*)p);
   }
   static void deleteArray_maplEunsignedsPintcOunsignedsPintgR(void *p) {
      delete [] ((map<unsigned int,unsigned int>*)p);
   }
   static void destruct_maplEunsignedsPintcOunsignedsPintgR(void *p) {
      typedef map<unsigned int,unsigned int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<unsigned int,unsigned int>

namespace ROOT {
   static TClass *maplEstringcOvectorlEtbeamcLcLstubgRsPgR_Dictionary();
   static void maplEstringcOvectorlEtbeamcLcLstubgRsPgR_TClassManip(TClass*);
   static void *new_maplEstringcOvectorlEtbeamcLcLstubgRsPgR(void *p = 0);
   static void *newArray_maplEstringcOvectorlEtbeamcLcLstubgRsPgR(Long_t size, void *p);
   static void delete_maplEstringcOvectorlEtbeamcLcLstubgRsPgR(void *p);
   static void deleteArray_maplEstringcOvectorlEtbeamcLcLstubgRsPgR(void *p);
   static void destruct_maplEstringcOvectorlEtbeamcLcLstubgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,vector<tbeam::stub> >*)
   {
      map<string,vector<tbeam::stub> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,vector<tbeam::stub> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,vector<tbeam::stub> >", -2, "map", 96,
                  typeid(map<string,vector<tbeam::stub> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOvectorlEtbeamcLcLstubgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,vector<tbeam::stub> >) );
      instance.SetNew(&new_maplEstringcOvectorlEtbeamcLcLstubgRsPgR);
      instance.SetNewArray(&newArray_maplEstringcOvectorlEtbeamcLcLstubgRsPgR);
      instance.SetDelete(&delete_maplEstringcOvectorlEtbeamcLcLstubgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOvectorlEtbeamcLcLstubgRsPgR);
      instance.SetDestructor(&destruct_maplEstringcOvectorlEtbeamcLcLstubgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,vector<tbeam::stub> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,vector<tbeam::stub> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOvectorlEtbeamcLcLstubgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,vector<tbeam::stub> >*)0x0)->GetClass();
      maplEstringcOvectorlEtbeamcLcLstubgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOvectorlEtbeamcLcLstubgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOvectorlEtbeamcLcLstubgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,vector<tbeam::stub> > : new map<string,vector<tbeam::stub> >;
   }
   static void *newArray_maplEstringcOvectorlEtbeamcLcLstubgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,vector<tbeam::stub> >[nElements] : new map<string,vector<tbeam::stub> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOvectorlEtbeamcLcLstubgRsPgR(void *p) {
      delete ((map<string,vector<tbeam::stub> >*)p);
   }
   static void deleteArray_maplEstringcOvectorlEtbeamcLcLstubgRsPgR(void *p) {
      delete [] ((map<string,vector<tbeam::stub> >*)p);
   }
   static void destruct_maplEstringcOvectorlEtbeamcLcLstubgRsPgR(void *p) {
      typedef map<string,vector<tbeam::stub> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,vector<tbeam::stub> >

namespace ROOT {
   static TClass *maplEstringcOvectorlEtbeamcLcLhitgRsPgR_Dictionary();
   static void maplEstringcOvectorlEtbeamcLcLhitgRsPgR_TClassManip(TClass*);
   static void *new_maplEstringcOvectorlEtbeamcLcLhitgRsPgR(void *p = 0);
   static void *newArray_maplEstringcOvectorlEtbeamcLcLhitgRsPgR(Long_t size, void *p);
   static void delete_maplEstringcOvectorlEtbeamcLcLhitgRsPgR(void *p);
   static void deleteArray_maplEstringcOvectorlEtbeamcLcLhitgRsPgR(void *p);
   static void destruct_maplEstringcOvectorlEtbeamcLcLhitgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,vector<tbeam::hit> >*)
   {
      map<string,vector<tbeam::hit> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,vector<tbeam::hit> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,vector<tbeam::hit> >", -2, "map", 96,
                  typeid(map<string,vector<tbeam::hit> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOvectorlEtbeamcLcLhitgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,vector<tbeam::hit> >) );
      instance.SetNew(&new_maplEstringcOvectorlEtbeamcLcLhitgRsPgR);
      instance.SetNewArray(&newArray_maplEstringcOvectorlEtbeamcLcLhitgRsPgR);
      instance.SetDelete(&delete_maplEstringcOvectorlEtbeamcLcLhitgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOvectorlEtbeamcLcLhitgRsPgR);
      instance.SetDestructor(&destruct_maplEstringcOvectorlEtbeamcLcLhitgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,vector<tbeam::hit> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,vector<tbeam::hit> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOvectorlEtbeamcLcLhitgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,vector<tbeam::hit> >*)0x0)->GetClass();
      maplEstringcOvectorlEtbeamcLcLhitgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOvectorlEtbeamcLcLhitgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOvectorlEtbeamcLcLhitgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,vector<tbeam::hit> > : new map<string,vector<tbeam::hit> >;
   }
   static void *newArray_maplEstringcOvectorlEtbeamcLcLhitgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,vector<tbeam::hit> >[nElements] : new map<string,vector<tbeam::hit> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOvectorlEtbeamcLcLhitgRsPgR(void *p) {
      delete ((map<string,vector<tbeam::hit> >*)p);
   }
   static void deleteArray_maplEstringcOvectorlEtbeamcLcLhitgRsPgR(void *p) {
      delete [] ((map<string,vector<tbeam::hit> >*)p);
   }
   static void destruct_maplEstringcOvectorlEtbeamcLcLhitgRsPgR(void *p) {
      typedef map<string,vector<tbeam::hit> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,vector<tbeam::hit> >

namespace ROOT {
   static TClass *maplEstringcOvectorlEtbeamcLcLclustergRsPgR_Dictionary();
   static void maplEstringcOvectorlEtbeamcLcLclustergRsPgR_TClassManip(TClass*);
   static void *new_maplEstringcOvectorlEtbeamcLcLclustergRsPgR(void *p = 0);
   static void *newArray_maplEstringcOvectorlEtbeamcLcLclustergRsPgR(Long_t size, void *p);
   static void delete_maplEstringcOvectorlEtbeamcLcLclustergRsPgR(void *p);
   static void deleteArray_maplEstringcOvectorlEtbeamcLcLclustergRsPgR(void *p);
   static void destruct_maplEstringcOvectorlEtbeamcLcLclustergRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,vector<tbeam::cluster> >*)
   {
      map<string,vector<tbeam::cluster> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,vector<tbeam::cluster> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,vector<tbeam::cluster> >", -2, "map", 96,
                  typeid(map<string,vector<tbeam::cluster> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOvectorlEtbeamcLcLclustergRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,vector<tbeam::cluster> >) );
      instance.SetNew(&new_maplEstringcOvectorlEtbeamcLcLclustergRsPgR);
      instance.SetNewArray(&newArray_maplEstringcOvectorlEtbeamcLcLclustergRsPgR);
      instance.SetDelete(&delete_maplEstringcOvectorlEtbeamcLcLclustergRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOvectorlEtbeamcLcLclustergRsPgR);
      instance.SetDestructor(&destruct_maplEstringcOvectorlEtbeamcLcLclustergRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,vector<tbeam::cluster> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,vector<tbeam::cluster> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOvectorlEtbeamcLcLclustergRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,vector<tbeam::cluster> >*)0x0)->GetClass();
      maplEstringcOvectorlEtbeamcLcLclustergRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOvectorlEtbeamcLcLclustergRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOvectorlEtbeamcLcLclustergRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,vector<tbeam::cluster> > : new map<string,vector<tbeam::cluster> >;
   }
   static void *newArray_maplEstringcOvectorlEtbeamcLcLclustergRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<string,vector<tbeam::cluster> >[nElements] : new map<string,vector<tbeam::cluster> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOvectorlEtbeamcLcLclustergRsPgR(void *p) {
      delete ((map<string,vector<tbeam::cluster> >*)p);
   }
   static void deleteArray_maplEstringcOvectorlEtbeamcLcLclustergRsPgR(void *p) {
      delete [] ((map<string,vector<tbeam::cluster> >*)p);
   }
   static void destruct_maplEstringcOvectorlEtbeamcLcLclustergRsPgR(void *p) {
      typedef map<string,vector<tbeam::cluster> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,vector<tbeam::cluster> >

namespace {
  void TriggerDictionaryInitialization_Dict_Impl() {
    static const char* headers[] = {
"interface/Hit.h",
"interface/Cluster.h",
"interface/Cbc.h",
"interface/Stub.h",
"interface/Track.h",
"interface/Event.h",
0
    };
    static const char* includePaths[] = {
"/cvmfs/cms.cern.ch/slc6_amd64_gcc530/lcg/root/6.08.07/include",
"/grid_mnt/home-pbs/vcherepa/cms_work/BeamTest/CMSSW_9_2_3/src/TestBeamSoftware/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "Dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace tbeam{class __attribute__((annotate("$clingAutoload$interface/Hit.h")))  hit;}
namespace tbeam{class __attribute__((annotate("$clingAutoload$interface/Cluster.h")))  cluster;}
namespace tbeam{class __attribute__((annotate("$clingAutoload$interface/Cbc.h")))  cbc;}
namespace tbeam{class __attribute__((annotate("$clingAutoload$interface/Stub.h")))  stub;}
namespace tbeam{class __attribute__((annotate("$clingAutoload$interface/Track.h")))  OfflineTrack;}
namespace tbeam{class __attribute__((annotate("$clingAutoload$interface/Event.h")))  OfflineEvent;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "Dict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "interface/Hit.h"
#include "interface/Cluster.h"
#include "interface/Cbc.h"
#include "interface/Stub.h"
#include "interface/Track.h"
#include "interface/Event.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"tbeam::OfflineEvent", payloadCode, "@",
"tbeam::OfflineTrack", payloadCode, "@",
"tbeam::cbc", payloadCode, "@",
"tbeam::cluster", payloadCode, "@",
"tbeam::hit", payloadCode, "@",
"tbeam::stub", payloadCode, "@",
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
