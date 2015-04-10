#include "OOC/SSA/ConstProp.oh"
#include "Language.oh"
#include "Language/Integer.oh"
#include "Language/Boolean.oh"
#include "OOC/SSA/Opcode.oh"
#include "OOC/SSA/Opnd.oh"
#include "OOC/SSA/Result.oh"
#include "OOC/SSA/DeadCodeElimination.oh"
#include "RT0.oh"
#include "Language/String0.oh"
typedef struct OOC_SSA_ConstProp__WorklistDesc *OOC_SSA_ConstProp__Worklist;
typedef struct OOC_SSA_ConstProp__WorklistDesc {
  OOC_SSA_ConstProp__Worklist next;
  OOC_SSA__Instr instr;
} OOC_SSA_ConstProp__WorklistDesc;
#define OOC_SSA_ConstProp__unclassified  0
static OOC_SSA__Result OOC_SSA_ConstProp__notConstant;
static OOC_SSA__Const OOC_SSA_ConstProp__ComputeConst(OOC_SSA__ProcBlock pb, OOC_SSA__Instr instr);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA_ConstProp__Worklist = { (RT0__Struct[]){&_td_OOC_SSA_ConstProp__WorklistDesc}, NULL, &_mid, "Worklist", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_ConstProp__WorklistDesc = { (RT0__Struct[]){&_td_OOC_SSA_ConstProp__WorklistDesc}, (void*[]){}, &_mid, "WorklistDesc", 8, 0, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:ConstProp", (RT0__Struct[]) { &_td_OOC_SSA_ConstProp__Worklist, &_td_OOC_SSA_ConstProp__WorklistDesc, NULL } };

extern void OOC_OOC_SSA_ConstProp_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SSA_ConstProp_init();
}

/* --- */
