#include <OOC/Doc/ResolveRef.oh>
#include <Msg.oh>
#include <Strings.oh>
#include <Object.oh>
#include <ADT/Dictionary.oh>
#include <OOC/Doc.oh>
#include <OOC/SymbolTable/Exports.oh>
#define OOC_Doc_ResolveRef__refEmpty 0
#define OOC_Doc_ResolveRef__refHasMarkup 1
#define OOC_Doc_ResolveRef__invalidCharacter 2
#define OOC_Doc_ResolveRef__moduleNameExpected 3
#define OOC_Doc_ResolveRef__identExpected 4
#define OOC_Doc_ResolveRef__endOfString 5
#define OOC_Doc_ResolveRef__unresolvedIdent 6
#define OOC_Doc_ResolveRef__notModule 7
#define OOC_Doc_ResolveRef__notConstDecl 8
#define OOC_Doc_ResolveRef__notFieldDecl 9
#define OOC_Doc_ResolveRef__notParameterDecl 10
#define OOC_Doc_ResolveRef__notProcDecl 11
#define OOC_Doc_ResolveRef__notTypeDecl 12
#define OOC_Doc_ResolveRef__notVarDecl 13
#define OOC_Doc_ResolveRef__refToPrivateDecl 14
static OOC_Doc_ResolveRef__ErrorContext OOC_Doc_ResolveRef__resolveContext;
static OOC_CHAR8 OOC_Doc_ResolveRef__ParseRef(OOC_Doc__OberonRef ref, OOC_Error__List errList, OOC_CHAR8 *external, OOC_Doc__InlineList *tokenList);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Doc_ResolveRef__ErrorContext = { (RT0__Struct[]){&_td_OOC_Doc_ResolveRef__ErrorContextDesc}, NULL, NULL, &_mid, "ErrorContext", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_Doc_ResolveRef__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_OOC_Error__ContextDesc,&_td_OOC_Doc_ResolveRef__ErrorContextDesc}, (void*[]){(void*)OOC_Doc_ResolveRef__ErrorContextDesc_GetTemplate,(void*)OOC_Error__ContextDesc_BaseTemplate}, NULL, &_mid, "ErrorContextDesc", 4, 2, RT0__strRecord };
RT0__StructDesc _td_OOC_Doc_ResolveRef__1656 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 256, 128, RT0__strArray };
RT0__StructDesc _td_OOC_Doc_ResolveRef__4596 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 2, 2, RT0__strArray };
RT0__StructDesc _td_OOC_Doc_ResolveRef__4812 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1024, 1024, RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Doc:ResolveRef", (RT0__Struct[]) { &_td_OOC_Doc_ResolveRef__ErrorContext, &_td_OOC_Doc_ResolveRef__ErrorContextDesc, NULL } };

extern void OOC_OOC_Doc_ResolveRef_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Doc_ResolveRef_init();
}

/* --- */
