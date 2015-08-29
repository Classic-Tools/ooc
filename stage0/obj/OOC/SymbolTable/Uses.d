#include <OOC/SymbolTable/Uses.oh>
#include <Err.oh>
#include <Strings.oh>
#define OOC_SymbolTable_Uses__useOfObject 1
#define OOC_SymbolTable_Uses__definition 2
#define OOC_SymbolTable_Uses__deprecated 3
static OOC_SymbolTable_Uses__ErrorContext OOC_SymbolTable_Uses__usesContext;
static void OOC_SymbolTable_Uses__InitUses(OOC_SymbolTable_Uses__Uses u, OOC_SymbolTable_Uses__Selector selector);
static void OOC_SymbolTable_Uses__AddMsg(OOC_SymbolTable_Uses__Uses u, OOC_SymbolTable__Name ident, OOC_INT32 code);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SymbolTable_Uses__Uses = { (RT0__Struct[]){&_td_OOC_SymbolTable_Uses__UsesDesc}, NULL, &_mid, "Uses", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SymbolTable_Uses__1015 = { (RT0__Struct[]){&_td_OOC_SymbolTable__Name}, NULL, &_mid, NULL, 4, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SymbolTable_Uses__Selector = { (RT0__Struct[]){&_td_OOC_SymbolTable_Uses__1015}, NULL, &_mid, "Selector", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SymbolTable_Uses__1069 = { (RT0__Struct[]){&_td_OOC_SymbolTable_Uses__1069}, (void*[]){}, &_mid, NULL, 8, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SymbolTable_Uses__1060 = { (RT0__Struct[]){&_td_OOC_SymbolTable_Uses__1069}, NULL, &_mid, NULL, 8, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SymbolTable_Uses__StoredUses = { (RT0__Struct[]){&_td_OOC_SymbolTable_Uses__1060}, NULL, &_mid, "StoredUses", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SymbolTable_Uses__UsesDesc = { (RT0__Struct[]){&_td_OOC_SymbolTable_Uses__UsesDesc}, (void*[]){(void*)OOC_SymbolTable_Uses__UsesDesc_Matches,(void*)OOC_SymbolTable_Uses__UsesDesc_RegisterSymTab,(void*)OOC_SymbolTable_Uses__UsesDesc_StartModule,(void*)OOC_SymbolTable_Uses__UsesDesc_TrackingDeclarations}, &_mid, "UsesDesc", 24, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SymbolTable_Uses__ErrorContext = { (RT0__Struct[]){&_td_OOC_SymbolTable_Uses__ErrorContextDesc}, NULL, &_mid, "ErrorContext", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SymbolTable_Uses__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_OOC_Error__ContextDesc,&_td_OOC_SymbolTable_Uses__ErrorContextDesc}, (void*[]){(void*)OOC_SymbolTable_Uses__ErrorContextDesc_GetTemplate,(void*)OOC_Error__ContextDesc_BaseTemplate}, &_mid, "ErrorContextDesc", 4, 2, RT0__strRecord };
RT0__StructDesc _td_OOC_SymbolTable_Uses__1748 = { (RT0__Struct[]){&RT0__longchar}, NULL, &_mid, NULL, 256, 128, RT0__strArray };
RT0__StructDesc _td_OOC_SymbolTable_Uses__2300 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SymbolTable_Uses__2633 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SymbolTable_Uses__2930 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SymbolTable_Uses__3044 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1024, 1024, RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SymbolTable:Uses", (RT0__Struct[]) { &_td_OOC_SymbolTable_Uses__Uses, &_td_OOC_SymbolTable_Uses__Selector, &_td_OOC_SymbolTable_Uses__StoredUses, &_td_OOC_SymbolTable_Uses__UsesDesc, &_td_OOC_SymbolTable_Uses__ErrorContext, &_td_OOC_SymbolTable_Uses__ErrorContextDesc, NULL } };

extern void OOC_OOC_SymbolTable_Uses_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SymbolTable_Uses_init();
}

/* --- */