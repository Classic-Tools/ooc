#include "OOC/IA32/RuntimeData.oh"
#include "RT0.oh"
#include "Language/String0.oh"

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:IA32:RuntimeData", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_IA32_RuntimeData_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_IA32_RuntimeData_init();
}

/* --- */
