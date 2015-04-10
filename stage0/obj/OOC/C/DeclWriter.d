#include "OOC/C/DeclWriter.oh"
#include "Err.oh"
#include "Files.oh"
#include "IntStr.oh"
#include "Strings.oh"
#include "IO/Memory.oh"
#include "Language/Boolean.oh"
#include "Language/String8.oh"
#include "Language/String16.oh"
#include "Language/Integer.oh"
#include "Language/Set.oh"
#include "Language/Real.oh"
#include "OOC/SymbolTable/Predef.oh"
#include "RT0.oh"
#include "Language/String0.oh"
#define OOC_C_DeclWriter__lastBasicType 15
#define OOC_C_DeclWriter__priName 0
#define OOC_C_DeclWriter__priStruct 1
#define OOC_C_DeclWriter__priPointer 1
#define OOC_C_DeclWriter__priArray 2
#define OOC_C_DeclWriter__priFunction 2
#define OOC_C_DeclWriter__priDeclaration 3
static void OOC_C_DeclWriter__InitWriter(OOC_C_DeclWriter__Writer w, Channel__Channel ch, URI__HierarchicalURI baseURI);
static void OOC_C_DeclWriter__InitType(OOC_C_DeclWriter__Type t);
static void OOC_C_DeclWriter__WriteLeft(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Type t, OOC_INT8 callerPri);
static void OOC_C_DeclWriter__WriteRight(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Type t, OOC_INT8 callerPri);
static void OOC_C_DeclWriter__InitBasicType(OOC_C_DeclWriter__BasicType bt, OOC_INT8 id, const OOC_CHAR8 repr__ref[], OOC_LEN repr_0d);
static OOC_C_DeclWriter__BasicType OOC_C_DeclWriter__NewBasicType(OOC_INT8 id, const OOC_CHAR8 repr__ref[], OOC_LEN repr_0d);
static void OOC_C_DeclWriter__InitPointer(OOC_C_DeclWriter__Pointer p, OOC_INT8 typeQualifier, OOC_C_DeclWriter__Type base);
static void OOC_C_DeclWriter__InitArray(OOC_C_DeclWriter__Array a, OOC_C_DeclWriter__Type base, OOC_INT32 size);
static void OOC_C_DeclWriter__InitFunction(OOC_C_DeclWriter__Function fct, OOC_C_DeclWriter__Type resultType, OOC_CHAR8 restParameters);
static void OOC_C_DeclWriter__InitStruct(OOC_C_DeclWriter__Struct _struct, OOC_CHAR8 isUnion, ADT_String__String name);
static void OOC_C_DeclWriter__InitTypeRef(OOC_C_DeclWriter__TypeRef typeRef, OOC_INT8 _class, ADT_String__String name);
static void OOC_C_DeclWriter__InitDeclaration(OOC_C_DeclWriter__Declaration d, ADT_String__String name, OOC_INT8 typeQualifier, OOC_INT8 storageClass, OOC_C_DeclWriter__Type type);
static void OOC_C_DeclWriter__InitIncludeModule(OOC_C_DeclWriter__IncludeModule d, OOC_Repository__Module module);
static void OOC_C_DeclWriter__InitDefine(OOC_C_DeclWriter__Define d, ADT_String__String name, Language__Value _const);
static void OOC_C_DeclWriter__Test();

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_C_DeclWriter__Type = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeDesc}, NULL, &_mid, "Type", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__TypeDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeDesc}, (void*[]){(void*)OOC_C_DeclWriter__TypeDesc_Priority,(void*)OOC_C_DeclWriter__TypeDesc_WriteLeft,(void*)OOC_C_DeclWriter__TypeDesc_WriteRight}, &_mid, "TypeDesc", 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__BasicType = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__BasicTypeDesc}, NULL, &_mid, "BasicType", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__BasicTypeDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeDesc,&_td_OOC_C_DeclWriter__BasicTypeDesc}, (void*[]){(void*)OOC_C_DeclWriter__BasicTypeDesc_Priority,(void*)OOC_C_DeclWriter__BasicTypeDesc_WriteLeft,(void*)OOC_C_DeclWriter__BasicTypeDesc_WriteRight}, &_mid, "BasicTypeDesc", 33, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__4837 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 32, 32, RT0__strArray };
RT0__StructDesc _td_OOC_C_DeclWriter__Pointer = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__PointerDesc}, NULL, &_mid, "Pointer", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__PointerDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeDesc,&_td_OOC_C_DeclWriter__PointerDesc}, (void*[]){(void*)OOC_C_DeclWriter__PointerDesc_Priority,(void*)OOC_C_DeclWriter__PointerDesc_WriteLeft,(void*)OOC_C_DeclWriter__PointerDesc_WriteRight}, &_mid, "PointerDesc", 8, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__Array = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__ArrayDesc}, NULL, &_mid, "Array", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__ArrayDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeDesc,&_td_OOC_C_DeclWriter__ArrayDesc}, (void*[]){(void*)OOC_C_DeclWriter__ArrayDesc_Priority,(void*)OOC_C_DeclWriter__ArrayDesc_WriteLeft,(void*)OOC_C_DeclWriter__ArrayDesc_WriteRight}, &_mid, "ArrayDesc", 8, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__Function = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__FunctionDesc}, NULL, &_mid, "Function", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__FunctionDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeDesc,&_td_OOC_C_DeclWriter__FunctionDesc}, (void*[]){(void*)OOC_C_DeclWriter__FunctionDesc_Priority,(void*)OOC_C_DeclWriter__FunctionDesc_WriteLeft,(void*)OOC_C_DeclWriter__FunctionDesc_WriteRight,(void*)OOC_C_DeclWriter__FunctionDesc_AddParameter}, &_mid, "FunctionDesc", 12, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__Struct = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__StructDesc}, NULL, &_mid, "Struct", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__StructDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeDesc,&_td_OOC_C_DeclWriter__StructDesc}, (void*[]){(void*)OOC_C_DeclWriter__StructDesc_Priority,(void*)OOC_C_DeclWriter__StructDesc_WriteLeft,(void*)OOC_C_DeclWriter__StructDesc_WriteRight,(void*)OOC_C_DeclWriter__StructDesc_AddMember,(void*)OOC_C_DeclWriter__StructDesc_AddPadding}, &_mid, "StructDesc", 12, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__TypeRef = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeRefDesc}, NULL, &_mid, "TypeRef", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__TypeRefDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeDesc,&_td_OOC_C_DeclWriter__TypeRefDesc}, (void*[]){(void*)OOC_C_DeclWriter__TypeRefDesc_Priority,(void*)OOC_C_DeclWriter__TypeRefDesc_WriteLeft,(void*)OOC_C_DeclWriter__TypeRefDesc_WriteRight}, &_mid, "TypeRefDesc", 8, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__Declaration = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__DeclarationDesc}, NULL, &_mid, "Declaration", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__DeclarationDesc = { (RT0__Struct[]){&_td_ADT_Object__ObjectDesc,&_td_OOC_C_DeclWriter__DeclarationDesc}, (void*[]){(void*)ADT_Object__ObjectDesc_Destroy,(void*)ADT_Object__ObjectDesc_Equals,(void*)ADT_Object__ObjectDesc_HashCode,(void*)ADT_Object__ObjectDesc_Load,(void*)ADT_Object__ObjectDesc_Store,(void*)ADT_Object__ObjectDesc_ToString,(void*)OOC_C_DeclWriter__DeclarationDesc_Write}, &_mid, "DeclarationDesc", 12, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__IncludeModule = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__IncludeModuleDesc}, NULL, &_mid, "IncludeModule", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__IncludeModuleDesc = { (RT0__Struct[]){&_td_ADT_Object__ObjectDesc,&_td_OOC_C_DeclWriter__DeclarationDesc,&_td_OOC_C_DeclWriter__IncludeModuleDesc}, (void*[]){(void*)ADT_Object__ObjectDesc_Destroy,(void*)ADT_Object__ObjectDesc_Equals,(void*)ADT_Object__ObjectDesc_HashCode,(void*)ADT_Object__ObjectDesc_Load,(void*)ADT_Object__ObjectDesc_Store,(void*)ADT_Object__ObjectDesc_ToString,(void*)OOC_C_DeclWriter__IncludeModuleDesc_Write}, &_mid, "IncludeModuleDesc", 16, 2, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__Define = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__DefineDesc}, NULL, &_mid, "Define", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__DefineDesc = { (RT0__Struct[]){&_td_ADT_Object__ObjectDesc,&_td_OOC_C_DeclWriter__DeclarationDesc,&_td_OOC_C_DeclWriter__DefineDesc}, (void*[]){(void*)ADT_Object__ObjectDesc_Destroy,(void*)ADT_Object__ObjectDesc_Equals,(void*)ADT_Object__ObjectDesc_HashCode,(void*)ADT_Object__ObjectDesc_Load,(void*)ADT_Object__ObjectDesc_Store,(void*)ADT_Object__ObjectDesc_ToString,(void*)OOC_C_DeclWriter__DefineDesc_Write}, &_mid, "DefineDesc", 16, 2, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__Writer = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__WriterDesc}, NULL, &_mid, "Writer", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__WriterDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__WriterDesc}, (void*[]){(void*)OOC_C_DeclWriter__WriterDesc_AddDeclaration,(void*)OOC_C_DeclWriter__WriterDesc_Close,(void*)OOC_C_DeclWriter__WriterDesc_CopyTo,(void*)OOC_C_DeclWriter__WriterDesc_Indent,(void*)OOC_C_DeclWriter__WriterDesc_NewArray,(void*)OOC_C_DeclWriter__WriterDesc_NewDeclaration,(void*)OOC_C_DeclWriter__WriterDesc_NewDefine,(void*)OOC_C_DeclWriter__WriterDesc_NewFunction,(void*)OOC_C_DeclWriter__WriterDesc_NewIncludeModule,(void*)OOC_C_DeclWriter__WriterDesc_NewPointer,(void*)OOC_C_DeclWriter__WriterDesc_NewStruct,(void*)OOC_C_DeclWriter__WriterDesc_NewTypeRef,(void*)OOC_C_DeclWriter__WriterDesc_Newline,(void*)OOC_C_DeclWriter__WriterDesc_WriteChar,(void*)OOC_C_DeclWriter__WriterDesc_WriteConst,(void*)OOC_C_DeclWriter__WriterDesc_WriteDeclaration,(void*)OOC_C_DeclWriter__WriterDesc_WriteDeclarationList,(void*)OOC_C_DeclWriter__WriterDesc_WriteInclude,(void*)OOC_C_DeclWriter__WriterDesc_WriteLInt,(void*)OOC_C_DeclWriter__WriterDesc_WriteLn,(void*)OOC_C_DeclWriter__WriterDesc_WriteModuleInclude,(void*)OOC_C_DeclWriter__WriterDesc_WriteString,(void*)OOC_C_DeclWriter__WriterDesc_WriteType,(void*)OOC_C_DeclWriter__WriterDesc_WriteTypeCast}, &_mid, "WriterDesc", 88, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__8718 = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__BasicType}, NULL, &_mid, NULL, 64, 16, RT0__strArray };
RT0__StructDesc _td_OOC_C_DeclWriter__9051 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_C_DeclWriter__9432 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_C_DeclWriter__11472 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_C_DeclWriter__12249 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_C_DeclWriter__19779 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_C_DeclWriter__19936 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_C_DeclWriter__23748 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 32, 32, RT0__strArray };
RT0__StructDesc _td_OOC_C_DeclWriter__29616 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_C_DeclWriter__29654 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 4096, 4096, RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:C:DeclWriter", (RT0__Struct[]) { &_td_OOC_C_DeclWriter__Type, &_td_OOC_C_DeclWriter__TypeDesc, &_td_OOC_C_DeclWriter__BasicType, &_td_OOC_C_DeclWriter__BasicTypeDesc, &_td_OOC_C_DeclWriter__Pointer, &_td_OOC_C_DeclWriter__PointerDesc, &_td_OOC_C_DeclWriter__Array, &_td_OOC_C_DeclWriter__ArrayDesc, &_td_OOC_C_DeclWriter__Function, &_td_OOC_C_DeclWriter__FunctionDesc, &_td_OOC_C_DeclWriter__Struct, &_td_OOC_C_DeclWriter__StructDesc, &_td_OOC_C_DeclWriter__TypeRef, &_td_OOC_C_DeclWriter__TypeRefDesc, &_td_OOC_C_DeclWriter__Declaration, &_td_OOC_C_DeclWriter__DeclarationDesc, &_td_OOC_C_DeclWriter__IncludeModule, &_td_OOC_C_DeclWriter__IncludeModuleDesc, &_td_OOC_C_DeclWriter__Define, &_td_OOC_C_DeclWriter__DefineDesc, &_td_OOC_C_DeclWriter__Writer, &_td_OOC_C_DeclWriter__WriterDesc, NULL } };

extern void OOC_OOC_C_DeclWriter_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_C_DeclWriter_init();
}

/* --- */
