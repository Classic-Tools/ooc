#include <OOC/SSA/Opcode.oh>
#include <Log.oh>
#include <Strings.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA_Opcode__34364 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_Opcode__34450 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 16, 16, 0, RT0__strArray };
RT0__StructDesc _td_OOC_SSA_Opcode__35036 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_Opcode__35139 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 32, 32, 0, RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:Opcode", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_SSA_Opcode_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SSA_Opcode_init();
}

/* --- */
