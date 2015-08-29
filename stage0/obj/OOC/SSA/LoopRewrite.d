#include <OOC/SSA/LoopRewrite.oh>
#include <Object.oh>
#include <Object/BigInt.oh>
#include <ADT/Dictionary.oh>
#include <ADT/ArrayList.oh>
#include <OOC/SSA/Opcode.oh>
#include <OOC/SSA/Opnd.oh>
#include <OOC/SSA/Result.oh>
#define OOC_SSA_LoopRewrite__dangerous OOC_FALSE
#define OOC_SSA_LoopRewrite__dangerousAdr OOC_TRUE
#define OOC_SSA_LoopRewrite__notVisited 0
#define OOC_SSA_LoopRewrite__visited 1
#define OOC_SSA_LoopRewrite__loopInvariant 1
#define OOC_SSA_LoopRewrite__forwardInductive 2
#define OOC_SSA_LoopRewrite__bottom 3
#define OOC_SSA_LoopRewrite__initMarker (-1)
typedef struct OOC_SSA_LoopRewrite__WorklistDesc *OOC_SSA_LoopRewrite__Worklist;
typedef struct OOC_SSA_LoopRewrite__WorklistDesc {
  OOC_SSA_LoopRewrite__Worklist next;
  OOC_SSA__Instr instr;
} OOC_SSA_LoopRewrite__WorklistDesc;
typedef struct OOC_SSA_LoopRewrite__SumDesc *OOC_SSA_LoopRewrite__Sum;
typedef OOC_SSA_LoopRewrite__Sum *OOC_SSA_LoopRewrite__Factors;
typedef struct OOC_SSA_LoopRewrite__ProductDesc *OOC_SSA_LoopRewrite__Product;
typedef struct OOC_SSA_LoopRewrite__ProductDesc {
  OOC_INT32 magnitude;
  OOC_SSA_LoopRewrite__Factors factors;
} OOC_SSA_LoopRewrite__ProductDesc;
typedef struct OOC_SSA_LoopRewrite__PListDesc *OOC_SSA_LoopRewrite__PList;
typedef struct OOC_SSA_LoopRewrite__PListDesc {
  OOC_SSA_LoopRewrite__Product *prod;
  OOC_INT32 size;
} OOC_SSA_LoopRewrite__PListDesc;
typedef struct OOC_SSA_LoopRewrite__CycleElementDesc *OOC_SSA_LoopRewrite__CycleElement;
typedef struct OOC_SSA_LoopRewrite__SumDesc {
  OOC_INT8 subclass;
  OOC_CHAR8 __pad1;
  OOC_CHAR8 __pad2;
  OOC_CHAR8 __pad3;
  OOC_SSA__Result atom;
  OOC_INT32 id;
  OOC_CHAR8 replacementCandidate;
  OOC_CHAR8 __pad13;
  OOC_CHAR8 __pad14;
  OOC_CHAR8 __pad15;
  OOC_SSA_LoopRewrite__CycleElement ce;
  OOC_SSA_LoopRewrite__PList ceFactor;
  OOC_SSA_LoopRewrite__PList loopInvariant;
  OOC_SSA_LoopRewrite__PList constant;
  OOC_SSA_LoopRewrite__PList others;
  OOC_SSA__Result replacement;
  OOC_INT8 useClass;
  OOC_CHAR8 __pad41;
  OOC_CHAR8 __pad42;
  OOC_CHAR8 __pad43;
  OOC_SSA__Result reconstruct;
} OOC_SSA_LoopRewrite__SumDesc;
#define OOC_SSA_LoopRewrite__useOutsideLoop 0
#define OOC_SSA_LoopRewrite__useIndirectOutsideLoop 1
#define OOC_SSA_LoopRewrite__useReplacementCandidate 2
#define OOC_SSA_LoopRewrite__useReplacementCode 3
#define OOC_SSA_LoopRewrite__useInCycleElement 3
#define OOC_SSA_LoopRewrite__useBackedgeValue 4
#define OOC_SSA_LoopRewrite__maxUseId 4
typedef struct OOC_SSA_LoopRewrite__InductionCycleDesc *OOC_SSA_LoopRewrite__InductionCycle;
typedef struct OOC_SSA_LoopRewrite__CycleElementDesc {
  OOC_INT8 subclass;
  OOC_CHAR8 __pad1;
  OOC_CHAR8 __pad2;
  OOC_CHAR8 __pad3;
  OOC_SSA__Result atom;
  OOC_INT32 id;
  OOC_CHAR8 replacementCandidate;
  OOC_CHAR8 __pad13;
  OOC_CHAR8 __pad14;
  OOC_CHAR8 __pad15;
  OOC_SSA_LoopRewrite__CycleElement ce;
  OOC_SSA_LoopRewrite__PList ceFactor;
  OOC_SSA_LoopRewrite__PList loopInvariant;
  OOC_SSA_LoopRewrite__PList constant;
  OOC_SSA_LoopRewrite__PList others;
  OOC_SSA__Result replacement;
  OOC_INT8 useClass;
  OOC_CHAR8 __pad41;
  OOC_CHAR8 __pad42;
  OOC_CHAR8 __pad43;
  OOC_SSA__Result reconstruct;
  OOC_SSA_LoopRewrite__CycleElement next;
  OOC_SSA__Result res;
  OOC_INT32 pos;
  OOC_SSA_LoopRewrite__InductionCycle ic;
  OOC_INT32 useCount[5];
} OOC_SSA_LoopRewrite__CycleElementDesc;
typedef struct OOC_SSA_LoopRewrite__RewrittenCycleDesc *OOC_SSA_LoopRewrite__RewrittenCycle;
typedef struct OOC_SSA_LoopRewrite__RewrittenCycleDesc {
  OOC_SSA_LoopRewrite__RewrittenCycle next;
  OOC_SSA_LoopRewrite__Sum origin;
  OOC_SSA__Result a;
  OOC_SSA__Result b;
  OOC_SSA__Result *replacements;
} OOC_SSA_LoopRewrite__RewrittenCycleDesc;
typedef struct OOC_SSA_LoopRewrite__InductionCycleDesc {
  OOC_INT8 subclass;
  OOC_CHAR8 __pad1;
  OOC_CHAR8 __pad2;
  OOC_CHAR8 __pad3;
  OOC_SSA__Result atom;
  OOC_INT32 id;
  OOC_CHAR8 replacementCandidate;
  OOC_CHAR8 __pad13;
  OOC_CHAR8 __pad14;
  OOC_CHAR8 __pad15;
  OOC_SSA_LoopRewrite__CycleElement ce;
  OOC_SSA_LoopRewrite__PList ceFactor;
  OOC_SSA_LoopRewrite__PList loopInvariant;
  OOC_SSA_LoopRewrite__PList constant;
  OOC_SSA_LoopRewrite__PList others;
  OOC_SSA__Result replacement;
  OOC_INT8 useClass;
  OOC_CHAR8 __pad41;
  OOC_CHAR8 __pad42;
  OOC_CHAR8 __pad43;
  OOC_SSA__Result reconstruct;
  OOC_SSA_LoopRewrite__CycleElement next;
  OOC_SSA__Result res;
  OOC_INT32 pos;
  OOC_SSA_LoopRewrite__InductionCycle ic;
  OOC_INT32 useCount[5];
  OOC_INT32 cycleLength;
  OOC_SSA_LoopRewrite__RewrittenCycle rewrittenCycles;
} OOC_SSA_LoopRewrite__InductionCycleDesc;
#define OOC_SSA_LoopRewrite__zero  0
#define OOC_SSA_LoopRewrite__signUnknown (-2)
#define OOC_SSA_LoopRewrite__signNotPositive (-1)
#define OOC_SSA_LoopRewrite__signZero 0
#define OOC_SSA_LoopRewrite__signNotNegative 1
static OOC_SSA_LoopRewrite__PList OOC_SSA_LoopRewrite__one;
static OOC_INT32 OOC_SSA_LoopRewrite__idCount;
static void OOC_SSA_LoopRewrite__InitSum(OOC_SSA_LoopRewrite__Sum sum, OOC_INT8 subclass, OOC_SSA__Result atom);
static void OOC_SSA_LoopRewrite__InitCycleElement(OOC_SSA_LoopRewrite__CycleElement ce, OOC_SSA_LoopRewrite__InductionCycle ic, OOC_SSA__Result res);
static void OOC_SSA_LoopRewrite__InitInductionCycle(OOC_SSA_LoopRewrite__InductionCycle ic, OOC_SSA__Result res);
static void OOC_SSA_LoopRewrite__Classify(OOC_SSA__ProcBlock pb, OOC_SSA__Instr loopStart);
static void OOC_SSA_LoopRewrite__FindInductiveCycles(OOC_SSA__Instr loopStart);
static OOC_INT32 OOC_SSA_LoopRewrite__Cmp(OOC_SSA_LoopRewrite__Product a, OOC_SSA_LoopRewrite__Product b);
static OOC_SSA_LoopRewrite__Sum OOC_SSA_LoopRewrite__NewSum(OOC_INT8 subclass, OOC_SSA__Result atom);
static OOC_SSA__Result OOC_SSA_LoopRewrite__InitialValue(OOC_SSA__ProcBlock pb, OOC_SSA_LoopRewrite__RewrittenCycle rc, OOC_SSA__Result initOld, OOC_INT32 marker);
static void OOC_SSA_LoopRewrite__Rewrite(OOC_SSA__ProcBlock pb, OOC_SSA_LoopRewrite__Sum sum);
static OOC_INT8 OOC_SSA_LoopRewrite__ClassifyUse(OOC_SSA__Opnd use, OOC_SSA_LoopRewrite__InductionCycle ic);
static void OOC_SSA_LoopRewrite__RewriteUses(OOC_SSA__ProcBlock pb, OOC_SSA_LoopRewrite__RewrittenCycle rc, OOC_SSA_LoopRewrite__CycleElement ce);
static void OOC_SSA_LoopRewrite__ClassifyCEUses(OOC_SSA__ProcBlock pb, OOC_SSA__Instr loopStart);
static void OOC_SSA_LoopRewrite__InstallEquivCE(OOC_SSA__ProcBlock pb, OOC_SSA__Instr loopStart);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA_LoopRewrite__Worklist = { (RT0__Struct[]){&_td_OOC_SSA_LoopRewrite__WorklistDesc}, NULL, &_mid, "Worklist", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__WorklistDesc = { (RT0__Struct[]){&_td_OOC_SSA_LoopRewrite__WorklistDesc}, (void*[]){}, &_mid, "WorklistDesc", 8, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__Sum = { (RT0__Struct[]){&_td_OOC_SSA_LoopRewrite__SumDesc}, NULL, &_mid, "Sum", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__2107 = { (RT0__Struct[]){&_td_OOC_SSA_LoopRewrite__Sum}, NULL, &_mid, NULL, 4, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__Factors = { (RT0__Struct[]){&_td_OOC_SSA_LoopRewrite__2107}, NULL, &_mid, "Factors", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__Product = { (RT0__Struct[]){&_td_OOC_SSA_LoopRewrite__ProductDesc}, NULL, &_mid, "Product", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__ProductDesc = { (RT0__Struct[]){&_td_OOC_SSA_LoopRewrite__ProductDesc}, (void*[]){}, &_mid, "ProductDesc", 8, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__PList = { (RT0__Struct[]){&_td_OOC_SSA_LoopRewrite__PListDesc}, NULL, &_mid, "PList", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__PListDesc = { (RT0__Struct[]){&_td_OOC_SSA_LoopRewrite__PListDesc}, (void*[]){}, &_mid, "PListDesc", 8, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__2914 = { (RT0__Struct[]){&_td_OOC_SSA_LoopRewrite__Product}, NULL, &_mid, NULL, 4, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__2903 = { (RT0__Struct[]){&_td_OOC_SSA_LoopRewrite__2914}, NULL, &_mid, NULL, 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__CycleElement = { (RT0__Struct[]){&_td_OOC_SSA_LoopRewrite__CycleElementDesc}, NULL, &_mid, "CycleElement", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__SumDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA_LoopRewrite__SumDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString}, &_mid, "SumDesc", 48, 2, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__InductionCycle = { (RT0__Struct[]){&_td_OOC_SSA_LoopRewrite__InductionCycleDesc}, NULL, &_mid, "InductionCycle", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__CycleElementDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA_LoopRewrite__SumDesc,&_td_OOC_SSA_LoopRewrite__CycleElementDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString}, &_mid, "CycleElementDesc", 84, 3, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__5545 = { (RT0__Struct[]){&RT0__longint}, NULL, &_mid, NULL, 20, 5, RT0__strArray };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__RewrittenCycle = { (RT0__Struct[]){&_td_OOC_SSA_LoopRewrite__RewrittenCycleDesc}, NULL, &_mid, "RewrittenCycle", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__RewrittenCycleDesc = { (RT0__Struct[]){&_td_OOC_SSA_LoopRewrite__RewrittenCycleDesc}, (void*[]){}, &_mid, "RewrittenCycleDesc", 20, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__5879 = { (RT0__Struct[]){&_td_OOC_SSA__Result}, NULL, &_mid, NULL, 4, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__5868 = { (RT0__Struct[]){&_td_OOC_SSA_LoopRewrite__5879}, NULL, &_mid, NULL, 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA_LoopRewrite__InductionCycleDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA_LoopRewrite__SumDesc,&_td_OOC_SSA_LoopRewrite__CycleElementDesc,&_td_OOC_SSA_LoopRewrite__InductionCycleDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString}, &_mid, "InductionCycleDesc", 92, 4, RT0__strRecord };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA:LoopRewrite", (RT0__Struct[]) { &_td_OOC_SSA_LoopRewrite__Worklist, &_td_OOC_SSA_LoopRewrite__WorklistDesc, &_td_OOC_SSA_LoopRewrite__Sum, &_td_OOC_SSA_LoopRewrite__Factors, &_td_OOC_SSA_LoopRewrite__Product, &_td_OOC_SSA_LoopRewrite__ProductDesc, &_td_OOC_SSA_LoopRewrite__PList, &_td_OOC_SSA_LoopRewrite__PListDesc, &_td_OOC_SSA_LoopRewrite__CycleElement, &_td_OOC_SSA_LoopRewrite__SumDesc, &_td_OOC_SSA_LoopRewrite__InductionCycle, &_td_OOC_SSA_LoopRewrite__CycleElementDesc, &_td_OOC_SSA_LoopRewrite__RewrittenCycle, &_td_OOC_SSA_LoopRewrite__RewrittenCycleDesc, &_td_OOC_SSA_LoopRewrite__InductionCycleDesc, NULL } };

extern void OOC_OOC_SSA_LoopRewrite_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SSA_LoopRewrite_init();
}

/* --- */
