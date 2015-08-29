#include <OOC/SSA/IRtoSSA.oh>
#include <Log.oh>
#include <Object.oh>
#include <Object/Boxed.oh>
#include <Object/BigInt.oh>
#include <OOC/SymbolTable.oh>
#include <OOC/SymbolTable/Predef.oh>
#include <OOC/SymbolTable/Builder.oh>
#include <OOC/SymbolTable/TypeRules.oh>
#include <OOC/SSA/Opcode.oh>
#include <OOC/SSA/Opnd.oh>
#include <OOC/SSA/Result.oh>
#include <OOC/SSA/Allocator.oh>
static void OOC_SSA_IRtoSSA__AddStoreBackwardFeed(OOC_SSA__ProcBlock pb, OOC_SSA__Instr loopEnd, OOC_SSA__Result storeArg);

/* run-time meta data */
static RT0__ModuleDesc _mid;
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:IRtoSSA", (RT0__Struct[]) { NULL } };

extern void OOC_OOC_SSA_IRtoSSA_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SSA_IRtoSSA_init();
}

/* --- */
