#include <OS/Path.oh>
#define OS_Path__sep "/"

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OS_Path__3447 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OS:Path", (RT0__Struct[]) { NULL } };

extern void OOC_OS_Path_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OS_Path_init();
}

static void* _c0;
static void* _c1;
/* --- */
