// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIhomedIedmondiumdIrootmIonmIvscodedIread_ntuple_with_chain_c_ACLiC_dict
#define R__NO_DEPRECATION

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

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "/home/edmondium/root-on-vscode/./read_ntuple_with_chain.c"

// Header files passed via #pragma extra_include

namespace {
  void TriggerDictionaryInitialization_read_ntuple_with_chain_c_ACLiC_dict_Impl() {
    static const char* headers[] = {
"./read_ntuple_with_chain.c",
nullptr
    };
    static const char* includePaths[] = {
"/home/edmondium/root_install/include",
"/home/edmondium/root_install/etc/",
"/home/edmondium/root_install/etc//cling",
"/home/edmondium/root_install/etc//cling/plugins/include",
"/home/edmondium/root_install/include/",
"/home/edmondium/root_install/include",
"/home/edmondium/root-on-vscode/",
"/home/edmondium/root_install/include/",
"/home/edmondium/root-on-vscode/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "read_ntuple_with_chain_c_ACLiC_dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "read_ntuple_with_chain_c_ACLiC_dict dictionary payload"

#ifndef __ACLIC__
  #define __ACLIC__ 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "./read_ntuple_with_chain.c"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"read_ntuple_with_chain", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("read_ntuple_with_chain_c_ACLiC_dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_read_ntuple_with_chain_c_ACLiC_dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_read_ntuple_with_chain_c_ACLiC_dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_read_ntuple_with_chain_c_ACLiC_dict() {
  TriggerDictionaryInitialization_read_ntuple_with_chain_c_ACLiC_dict_Impl();
}
