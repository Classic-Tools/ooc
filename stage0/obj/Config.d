static void* _c0;
static void* _c1;
static void* _c2;
static void* _c3;
static void* _c4;
static void* _c5;
static void* _c6;
static void* _c7;
#include <Config.oh>
#include <IntStr.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Config__Config = { (RT0__Struct[]){&_td_Config__ConfigDesc}, NULL, NULL, &_mid, "Config", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config__ConfigDesc = { (RT0__Struct[]){&_td_Config__ConfigDesc}, (void*[]){}, NULL, &_mid, "ConfigDesc", 0, 0, 0, RT0__strRecord };
RT0__StructDesc _td_Config__Variable = { (RT0__Struct[]){&_td_Config__VariableDesc}, NULL, NULL, &_mid, "Variable", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config__VariableDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_Config__VariableDesc}, (void*[]){(void*)Config__VariableDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Config__VariableDesc_StringToValue,(void*)Config__VariableDesc_Clone}, NULL, &_mid, "VariableDesc", 0, 1, 0, RT0__strRecord };
RT0__StructDesc _td_Config__BooleanVar = { (RT0__Struct[]){&_td_Config__BooleanVarDesc}, NULL, NULL, &_mid, "BooleanVar", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config__BooleanVarDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_Config__VariableDesc,&_td_Config__BooleanVarDesc}, (void*[]){(void*)Config__BooleanVarDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Config__BooleanVarDesc_StringToValue,(void*)Config__BooleanVarDesc_Clone}, NULL, &_mid, "BooleanVarDesc", 1, 2, 0, RT0__strRecord };
RT0__StructDesc _td_Config__IntegerVar = { (RT0__Struct[]){&_td_Config__IntegerVarDesc}, NULL, NULL, &_mid, "IntegerVar", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config__IntegerVarDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_Config__VariableDesc,&_td_Config__IntegerVarDesc}, (void*[]){(void*)Config__IntegerVarDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Config__IntegerVarDesc_StringToValue,(void*)Config__IntegerVarDesc_Clone}, NULL, &_mid, "IntegerVarDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_Config__StringVar = { (RT0__Struct[]){&_td_Config__StringVarDesc}, NULL, NULL, &_mid, "StringVar", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_Config__StringVarDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_Config__VariableDesc,&_td_Config__StringVarDesc}, (void*[]){(void*)Config__StringVarDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Config__StringVarDesc_StringToValue,(void*)Config__StringVarDesc_Clone}, NULL, &_mid, "StringVarDesc", 4, 2, 0, RT0__strRecord };
RT0__StructDesc _td_Config__3580 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 16, 16, 0, RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Config", (RT0__Struct[]) { &_td_Config__Config, &_td_Config__ConfigDesc, &_td_Config__Variable, &_td_Config__VariableDesc, &_td_Config__BooleanVar, &_td_Config__BooleanVarDesc, &_td_Config__IntegerVar, &_td_Config__IntegerVarDesc, &_td_Config__StringVar, &_td_Config__StringVarDesc, NULL } };

extern void OOC_Config_init0() {
  RT0__RegisterModule(&_mid);
  OOC_Config_init();
}

/* --- */
