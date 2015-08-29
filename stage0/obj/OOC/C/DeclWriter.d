#include <OOC/C/DeclWriter.oh>
#include <IntStr.oh>
#include <Strings.oh>
#include <Object/BigInt.oh>
#include <OOC/SymbolTable/Predef.oh>
#include <OOC/SymbolTable/TypeRules.oh>
#define OOC_C_DeclWriter__lastBasicType 16
#define OOC_C_DeclWriter__priName 0
#define OOC_C_DeclWriter__priStruct 1
#define OOC_C_DeclWriter__priPointer 1
#define OOC_C_DeclWriter__priArray 2
#define OOC_C_DeclWriter__priFunction 2
#define OOC_C_DeclWriter__priDeclaration 3
static void OOC_C_DeclWriter__InitWriter(OOC_C_DeclWriter__Writer w, IO__ByteChannel ch, URI__HierarchicalURI baseURI);
static void OOC_C_DeclWriter__InitType(OOC_C_DeclWriter__Type t);
static void OOC_C_DeclWriter__WriteLeft(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Type t, OOC_INT8 callerPri);
static void OOC_C_DeclWriter__WriteRight(OOC_C_DeclWriter__Writer w, OOC_C_DeclWriter__Type t, OOC_INT8 callerPri);
static void OOC_C_DeclWriter__InitBasicType(OOC_C_DeclWriter__BasicType bt, OOC_INT8 id, const OOC_CHAR8 repr__ref[], OOC_LEN repr_0d);
static OOC_C_DeclWriter__BasicType OOC_C_DeclWriter__NewBasicType(OOC_INT8 id, const OOC_CHAR8 repr__ref[], OOC_LEN repr_0d);
static void OOC_C_DeclWriter__InitPointer(OOC_C_DeclWriter__Pointer p, OOC_INT8 typeQualifier, OOC_C_DeclWriter__Type base);
static void OOC_C_DeclWriter__InitArray(OOC_C_DeclWriter__Array a, OOC_C_DeclWriter__Type base, OOC_INT32 size);
static void OOC_C_DeclWriter__InitFunction(OOC_C_DeclWriter__Function fct, OOC_C_DeclWriter__Type resultType, OOC_CHAR8 restParameters);
static void OOC_C_DeclWriter__InitStruct(OOC_C_DeclWriter__Struct _struct, OOC_CHAR8 isUnion, Object__String name);
static void OOC_C_DeclWriter__InitTypeRef(OOC_C_DeclWriter__TypeRef typeRef, OOC_INT8 _class, Object__String name);
static void OOC_C_DeclWriter__InitDeclaration(OOC_C_DeclWriter__Declaration d, Object__String name, OOC_INT8 typeQualifier, OOC_INT8 storageClass, OOC_C_DeclWriter__Type type);
static void OOC_C_DeclWriter__InitIncludeModule(OOC_C_DeclWriter__IncludeModule d, OOC_Repository__Module module);
static void OOC_C_DeclWriter__InitDefine(OOC_C_DeclWriter__Define d, Object__String name, Object_Boxed__Object _const);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_C_DeclWriter__Type = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeDesc}, NULL, &_mid, "Type", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__TypeDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeDesc}, (void*[]){(void*)OOC_C_DeclWriter__TypeDesc_Priority,(void*)OOC_C_DeclWriter__TypeDesc_WriteLeft,(void*)OOC_C_DeclWriter__TypeDesc_WriteRight}, &_mid, "TypeDesc", 0, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__BasicType = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__BasicTypeDesc}, NULL, &_mid, "BasicType", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__BasicTypeDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeDesc,&_td_OOC_C_DeclWriter__BasicTypeDesc}, (void*[]){(void*)OOC_C_DeclWriter__BasicTypeDesc_Priority,(void*)OOC_C_DeclWriter__BasicTypeDesc_WriteLeft,(void*)OOC_C_DeclWriter__BasicTypeDesc_WriteRight}, &_mid, "BasicTypeDesc", 33, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__4922 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 32, 32, RT0__strArray };
RT0__StructDesc _td_OOC_C_DeclWriter__Pointer = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__PointerDesc}, NULL, &_mid, "Pointer", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__PointerDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeDesc,&_td_OOC_C_DeclWriter__PointerDesc}, (void*[]){(void*)OOC_C_DeclWriter__PointerDesc_Priority,(void*)OOC_C_DeclWriter__PointerDesc_WriteLeft,(void*)OOC_C_DeclWriter__PointerDesc_WriteRight}, &_mid, "PointerDesc", 8, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__Array = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__ArrayDesc}, NULL, &_mid, "Array", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__ArrayDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeDesc,&_td_OOC_C_DeclWriter__ArrayDesc}, (void*[]){(void*)OOC_C_DeclWriter__ArrayDesc_Priority,(void*)OOC_C_DeclWriter__ArrayDesc_WriteLeft,(void*)OOC_C_DeclWriter__ArrayDesc_WriteRight}, &_mid, "ArrayDesc", 8, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__Function = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__FunctionDesc}, NULL, &_mid, "Function", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__FunctionDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeDesc,&_td_OOC_C_DeclWriter__FunctionDesc}, (void*[]){(void*)OOC_C_DeclWriter__FunctionDesc_Priority,(void*)OOC_C_DeclWriter__FunctionDesc_WriteLeft,(void*)OOC_C_DeclWriter__FunctionDesc_WriteRight,(void*)OOC_C_DeclWriter__FunctionDesc_AddParameter,(void*)OOC_C_DeclWriter__FunctionDesc_MakeParametersVolatile,(void*)OOC_C_DeclWriter__FunctionDesc_SetNoReturn}, &_mid, "FunctionDesc", 12, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__Struct = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__StructDesc}, NULL, &_mid, "Struct", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__StructDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeDesc,&_td_OOC_C_DeclWriter__StructDesc}, (void*[]){(void*)OOC_C_DeclWriter__StructDesc_Priority,(void*)OOC_C_DeclWriter__StructDesc_WriteLeft,(void*)OOC_C_DeclWriter__StructDesc_WriteRight,(void*)OOC_C_DeclWriter__StructDesc_AddMember,(void*)OOC_C_DeclWriter__StructDesc_AddPadding}, &_mid, "StructDesc", 12, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__TypeRef = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeRefDesc}, NULL, &_mid, "TypeRef", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__TypeRefDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__TypeDesc,&_td_OOC_C_DeclWriter__TypeRefDesc}, (void*[]){(void*)OOC_C_DeclWriter__TypeRefDesc_Priority,(void*)OOC_C_DeclWriter__TypeRefDesc_WriteLeft,(void*)OOC_C_DeclWriter__TypeRefDesc_WriteRight}, &_mid, "TypeRefDesc", 8, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__Declaration = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__DeclarationDesc}, NULL, &_mid, "Declaration", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__DeclarationDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_C_DeclWriter__DeclarationDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString,(void*)OOC_C_DeclWriter__DeclarationDesc_SetTypeQualifier,(void*)OOC_C_DeclWriter__DeclarationDesc_Write}, &_mid, "DeclarationDesc", 12, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__IncludeModule = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__IncludeModuleDesc}, NULL, &_mid, "IncludeModule", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__IncludeModuleDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_C_DeclWriter__DeclarationDesc,&_td_OOC_C_DeclWriter__IncludeModuleDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString,(void*)OOC_C_DeclWriter__DeclarationDesc_SetTypeQualifier,(void*)OOC_C_DeclWriter__IncludeModuleDesc_Write}, &_mid, "IncludeModuleDesc", 16, 2, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__Define = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__DefineDesc}, NULL, &_mid, "Define", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__DefineDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_C_DeclWriter__DeclarationDesc,&_td_OOC_C_DeclWriter__DefineDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString,(void*)OOC_C_DeclWriter__DeclarationDesc_SetTypeQualifier,(void*)OOC_C_DeclWriter__DefineDesc_Write}, &_mid, "DefineDesc", 16, 2, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__Writer = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__WriterDesc}, NULL, &_mid, "Writer", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_C_DeclWriter__WriterDesc = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__WriterDesc}, (void*[]){(void*)OOC_C_DeclWriter__WriterDesc_AddDeclaration,(void*)OOC_C_DeclWriter__WriterDesc_Close,(void*)OOC_C_DeclWriter__WriterDesc_CopyTo,(void*)OOC_C_DeclWriter__WriterDesc_Indent,(void*)OOC_C_DeclWriter__WriterDesc_NewArray,(void*)OOC_C_DeclWriter__WriterDesc_NewDeclaration,(void*)OOC_C_DeclWriter__WriterDesc_NewDefine,(void*)OOC_C_DeclWriter__WriterDesc_NewFunction,(void*)OOC_C_DeclWriter__WriterDesc_NewIncludeModule,(void*)OOC_C_DeclWriter__WriterDesc_NewPointer,(void*)OOC_C_DeclWriter__WriterDesc_NewStruct,(void*)OOC_C_DeclWriter__WriterDesc_NewTypeRef,(void*)OOC_C_DeclWriter__WriterDesc_Newline,(void*)OOC_C_DeclWriter__WriterDesc_WriteBasicConst,(void*)OOC_C_DeclWriter__WriterDesc_WriteChar,(void*)OOC_C_DeclWriter__WriterDesc_WriteConst,(void*)OOC_C_DeclWriter__WriterDesc_WriteDeclaration,(void*)OOC_C_DeclWriter__WriterDesc_WriteDeclarationList,(void*)OOC_C_DeclWriter__WriterDesc_WriteInclude,(void*)OOC_C_DeclWriter__WriterDesc_WriteLInt,(void*)OOC_C_DeclWriter__WriterDesc_WriteLn,(void*)OOC_C_DeclWriter__WriterDesc_WriteModuleInclude,(void*)OOC_C_DeclWriter__WriterDesc_WriteObject,(void*)OOC_C_DeclWriter__WriterDesc_WriteString,(void*)OOC_C_DeclWriter__WriterDesc_WriteStringConst,(void*)OOC_C_DeclWriter__WriterDesc_WriteType,(void*)OOC_C_DeclWriter__WriterDesc_WriteTypeCast}, &_mid, "WriterDesc", 92, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_C_DeclWriter__8802 = { (RT0__Struct[]){&_td_OOC_C_DeclWriter__BasicType}, NULL, &_mid, NULL, 68, 17, RT0__strArray };
RT0__StructDesc _td_OOC_C_DeclWriter__9135 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_C_DeclWriter__9508 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_C_DeclWriter__11591 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_C_DeclWriter__12492 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_C_DeclWriter__25814 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_C_DeclWriter__25971 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_C_DeclWriter__30395 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 32, 32, RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:C:DeclWriter", (RT0__Struct[]) { &_td_OOC_C_DeclWriter__Type, &_td_OOC_C_DeclWriter__TypeDesc, &_td_OOC_C_DeclWriter__BasicType, &_td_OOC_C_DeclWriter__BasicTypeDesc, &_td_OOC_C_DeclWriter__Pointer, &_td_OOC_C_DeclWriter__PointerDesc, &_td_OOC_C_DeclWriter__Array, &_td_OOC_C_DeclWriter__ArrayDesc, &_td_OOC_C_DeclWriter__Function, &_td_OOC_C_DeclWriter__FunctionDesc, &_td_OOC_C_DeclWriter__Struct, &_td_OOC_C_DeclWriter__StructDesc, &_td_OOC_C_DeclWriter__TypeRef, &_td_OOC_C_DeclWriter__TypeRefDesc, &_td_OOC_C_DeclWriter__Declaration, &_td_OOC_C_DeclWriter__DeclarationDesc, &_td_OOC_C_DeclWriter__IncludeModule, &_td_OOC_C_DeclWriter__IncludeModuleDesc, &_td_OOC_C_DeclWriter__Define, &_td_OOC_C_DeclWriter__DefineDesc, &_td_OOC_C_DeclWriter__Writer, &_td_OOC_C_DeclWriter__WriterDesc, NULL } };

extern void OOC_OOC_C_DeclWriter_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_C_DeclWriter_init();
}

/* --- */
