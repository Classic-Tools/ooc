#include <StringSearch/NoMatch.oh>
StringSearch_NoMatch__Factory StringSearch_NoMatch__factory;
StringSearch_NoMatch__Matcher StringSearch_NoMatch__matcher;
static void StringSearch_NoMatch__InitMatcher(StringSearch_NoMatch__Matcher matcher, Object__String8 pattern, OOC_UINT32 flags, OOC_INT32 groups);
static StringSearch_NoMatch__Matcher StringSearch_NoMatch__NewMatcher(Object__String8 pattern, OOC_UINT32 flags, OOC_INT32 groups);
static void StringSearch_NoMatch__InitFactory(StringSearch_NoMatch__Factory f);
static StringSearch_NoMatch__Factory StringSearch_NoMatch__NewFactory(void);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_StringSearch_NoMatch__Factory = { (RT0__Struct[]){&_td_StringSearch_NoMatch__FactoryDesc}, NULL, &_mid, "Factory", 4, -1, RT0__strPointer };
RT0__StructDesc _td_StringSearch_NoMatch__FactoryDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_StringSearch__FactoryDesc,&_td_StringSearch_NoMatch__FactoryDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString,(void*)StringSearch_NoMatch__FactoryDesc_Compile,(void*)StringSearch__FactoryDesc_Destroy}, &_mid, "FactoryDesc", 0, 2, RT0__strRecord };
RT0__StructDesc _td_StringSearch_NoMatch__Matcher = { (RT0__Struct[]){&_td_StringSearch_NoMatch__MatcherDesc}, NULL, &_mid, "Matcher", 4, -1, RT0__strPointer };
RT0__StructDesc _td_StringSearch_NoMatch__MatcherDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_StringSearch__MatcherDesc,&_td_StringSearch_NoMatch__MatcherDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString,(void*)StringSearch__MatcherDesc_Destroy,(void*)StringSearch_NoMatch__MatcherDesc_Match,(void*)StringSearch_NoMatch__MatcherDesc_MatchChars,(void*)StringSearch_NoMatch__MatcherDesc_Search,(void*)StringSearch_NoMatch__MatcherDesc_SearchChars}, &_mid, "MatcherDesc", 12, 2, RT0__strRecord };
RT0__StructDesc _td_StringSearch_NoMatch__1809 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_StringSearch_NoMatch__2125 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"StringSearch:NoMatch", (RT0__Struct[]) { &_td_StringSearch_NoMatch__Factory, &_td_StringSearch_NoMatch__FactoryDesc, &_td_StringSearch_NoMatch__Matcher, &_td_StringSearch_NoMatch__MatcherDesc, NULL } };

extern void OOC_StringSearch_NoMatch_init0() {
  RT0__RegisterModule(&_mid);
  OOC_StringSearch_NoMatch_init();
}

/* --- */
