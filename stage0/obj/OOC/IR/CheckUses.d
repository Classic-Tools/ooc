#include <OOC/IR/CheckUses.oh>
#include <Object/Boxed.oh>
#include <Config/Value.oh>
#include <Config/Value/Boolean.oh>
#include <Msg.oh>
#include <OOC/Config/StdPragmas.oh>
#include <OOC/SymbolTable/TypeRules.oh>
#include <OOC/SymbolTable/Predef.oh>
#include <OOC/Scanner/BasicList.oh>
#define OOC_IR_CheckUses__undefined 0
#define OOC_IR_CheckUses__maybeUndefined 1
#define OOC_IR_CheckUses__defined 2
#define OOC_IR_CheckUses__doesNotRead 0
#define OOC_IR_CheckUses__doesRead 1
#define OOC_IR_CheckUses__doesNotWrite 0
#define OOC_IR_CheckUses__mayWrite 1
#define OOC_IR_CheckUses__doesWrite 2
#define OOC_IR_CheckUses__scaleR 4
#define OOC_IR_CheckUses__read 0
#define OOC_IR_CheckUses__write 1
#define OOC_IR_CheckUses__writeMaybe 2
#define OOC_IR_CheckUses__passCollectWrites 0
#define OOC_IR_CheckUses__passAnalyzeCalls 1
#define OOC_IR_CheckUses__passEmitWarnings 2
typedef OOC_Scanner_BasicList__Symbol OOC_IR_CheckUses__Symbol;
#define OOC_IR_CheckUses__undefinedVar 1
#define OOC_IR_CheckUses__maybeUndefinedVar 2
#define OOC_IR_CheckUses__unreachableCode 3
#define OOC_IR_CheckUses__endOfFunction 4
#define OOC_IR_CheckUses__deadTypeTest 5
#define OOC_IR_CheckUses__calleeUndefinedvar 6
static OOC_SymbolTable__Type OOC_IR_CheckUses__any;
static OOC_IR_CheckUses__ErrorContext OOC_IR_CheckUses__checkUsesContext;
static ADT_Dictionary__Dictionary OOC_IR_CheckUses__KnownProcs(OOC_IR__Module module);
static OOC_IR_CheckUses__Def OOC_IR_CheckUses__NewDef(void);
static OOC_IR_CheckUses__Def OOC_IR_CheckUses__NewUnreachableDef(void);
static Msg__Msg OOC_IR_CheckUses__WarnSymE(OOC_Error__List errList, OOC_Config_Pragmas__History pragmaHistory, OOC_Scanner_BasicList__Symbol sym, OOC_INT32 code);
static void OOC_IR_CheckUses__WarnSym(OOC_Error__List errList, OOC_Config_Pragmas__History pragmaHistory, OOC_Scanner_BasicList__Symbol sym, OOC_INT32 code);
static void OOC_IR_CheckUses__WarnSymV(OOC_IR_CheckUses__Visitor v, OOC_Scanner_BasicList__Symbol sym, OOC_INT32 code, OOC_SymbolTable__VarDecl varDecl);
static OOC_CHAR8 OOC_IR_CheckUses__NonlocalVar(OOC_SymbolTable__ProcDecl localProc, OOC_SymbolTable__VarDecl varDecl);
static void OOC_IR_CheckUses__EmitVarWarning(OOC_IR_CheckUses__Visitor v, OOC_SymbolTable__VarDecl varDecl, OOC_Scanner_BasicList__Symbol sym, OOC_CHAR8 contextCall);
static void OOC_IR_CheckUses__VisitVarDecl(OOC_IR_CheckUses__Visitor v, OOC_SymbolTable__VarDecl varDecl, OOC_Scanner_BasicList__Symbol sym, OOC_CHAR8 contextCall);
static void OOC_IR_CheckUses__TransitiveWriteClosure(ADT_Dictionary__Dictionary knownProcs, OOC_IR_CheckUses__ProcData pd);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_IR_CheckUses__Def = { (RT0__Struct[]){&_td_OOC_IR_CheckUses__DefDesc}, NULL, &_mid, "Def", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_IR_CheckUses__DefDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_IR_CheckUses__DefDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString,(void*)OOC_IR_CheckUses__DefDesc_Copy,(void*)OOC_IR_CheckUses__DefDesc_GetClass,(void*)OOC_IR_CheckUses__DefDesc_Merge,(void*)OOC_IR_CheckUses__DefDesc_SetClass,(void*)OOC_IR_CheckUses__DefDesc_Unreachable}, &_mid, "DefDesc", 8, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_IR_CheckUses__ProcData = { (RT0__Struct[]){&_td_OOC_IR_CheckUses__ProcDataDesc}, NULL, &_mid, "ProcData", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_IR_CheckUses__ProcDataDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_IR_CheckUses__ProcDataDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString,(void*)OOC_IR_CheckUses__ProcDataDesc_SetReadFlag,(void*)OOC_IR_CheckUses__ProcDataDesc_SetWriteFlag}, &_mid, "ProcDataDesc", 12, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_IR_CheckUses__Visitor = { (RT0__Struct[]){&_td_OOC_IR_CheckUses__VisitorDesc}, NULL, &_mid, "Visitor", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_IR_CheckUses__VisitorDesc = { (RT0__Struct[]){&_td_OOC_IR__VisitorDesc,&_td_OOC_IR_VisitAll__VisitorDesc,&_td_OOC_IR_CheckUses__VisitorDesc}, (void*[]){(void*)OOC_IR_VisitAll__VisitorDesc_VisitAbs,(void*)OOC_IR_CheckUses__VisitorDesc_VisitAdr,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAsh,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAssert,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAssignOp,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAssignment,(void*)OOC_IR_VisitAll__VisitorDesc_VisitBinaryArith,(void*)OOC_IR_VisitAll__VisitorDesc_VisitBooleanOp,(void*)OOC_IR_CheckUses__VisitorDesc_VisitCall,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCap,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCase,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCaseStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCatchClause,(void*)OOC_IR_VisitAll__VisitorDesc_VisitChangeElement,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCompare,(void*)OOC_IR_VisitAll__VisitorDesc_VisitConcat,(void*)OOC_IR_VisitAll__VisitorDesc_VisitConst,(void*)OOC_IR_VisitAll__VisitorDesc_VisitConstructor,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCopy,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCopyParameter,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCopyString,(void*)OOC_IR_CheckUses__VisitorDesc_VisitDeref,(void*)OOC_IR_VisitAll__VisitorDesc_VisitEntier,(void*)OOC_IR_VisitAll__VisitorDesc_VisitExit,(void*)OOC_IR_VisitAll__VisitorDesc_VisitForStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitIfStatm,(void*)OOC_IR_CheckUses__VisitorDesc_VisitIndex,(void*)OOC_IR_VisitAll__VisitorDesc_VisitLen,(void*)OOC_IR_VisitAll__VisitorDesc_VisitLoopStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitModule,(void*)OOC_IR_VisitAll__VisitorDesc_VisitModuleRef,(void*)OOC_IR_VisitAll__VisitorDesc_VisitMoveBlock,(void*)OOC_IR_VisitAll__VisitorDesc_VisitNegate,(void*)OOC_IR_VisitAll__VisitorDesc_VisitNewBlock,(void*)OOC_IR_VisitAll__VisitorDesc_VisitNewObject,(void*)OOC_IR_VisitAll__VisitorDesc_VisitNot,(void*)OOC_IR_VisitAll__VisitorDesc_VisitOdd,(void*)OOC_IR_VisitAll__VisitorDesc_VisitPredefProc,(void*)OOC_IR_VisitAll__VisitorDesc_VisitProcedure,(void*)OOC_IR_VisitAll__VisitorDesc_VisitProcedureRef,(void*)OOC_IR_VisitAll__VisitorDesc_VisitRaise,(void*)OOC_IR_VisitAll__VisitorDesc_VisitRepeatStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitReturn,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSelectField,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSelectProc,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSetMember,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSetOp,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSetRange,(void*)OOC_IR_VisitAll__VisitorDesc_VisitShift,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTryStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeCast,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeConv,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeGuard,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeRef,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeTag,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeTest,(void*)OOC_IR_CheckUses__VisitorDesc_VisitVar,(void*)OOC_IR_VisitAll__VisitorDesc_VisitWhileStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitWithStatm}, &_mid, "VisitorDesc", 36, 2, RT0__strRecord };
RT0__StructDesc _td_OOC_IR_CheckUses__VisitorCalls = { (RT0__Struct[]){&_td_OOC_IR_CheckUses__VisitorCallsDesc}, NULL, &_mid, "VisitorCalls", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_IR_CheckUses__VisitorCallsDesc = { (RT0__Struct[]){&_td_OOC_IR__VisitorDesc,&_td_OOC_IR_VisitAll__VisitorDesc,&_td_OOC_IR_CheckUses__VisitorCallsDesc}, (void*[]){(void*)OOC_IR_VisitAll__VisitorDesc_VisitAbs,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAdr,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAsh,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAssert,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAssignOp,(void*)OOC_IR_VisitAll__VisitorDesc_VisitAssignment,(void*)OOC_IR_VisitAll__VisitorDesc_VisitBinaryArith,(void*)OOC_IR_VisitAll__VisitorDesc_VisitBooleanOp,(void*)OOC_IR_CheckUses__VisitorCallsDesc_VisitCall,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCap,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCase,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCaseStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCatchClause,(void*)OOC_IR_VisitAll__VisitorDesc_VisitChangeElement,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCompare,(void*)OOC_IR_VisitAll__VisitorDesc_VisitConcat,(void*)OOC_IR_VisitAll__VisitorDesc_VisitConst,(void*)OOC_IR_VisitAll__VisitorDesc_VisitConstructor,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCopy,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCopyParameter,(void*)OOC_IR_VisitAll__VisitorDesc_VisitCopyString,(void*)OOC_IR_VisitAll__VisitorDesc_VisitDeref,(void*)OOC_IR_VisitAll__VisitorDesc_VisitEntier,(void*)OOC_IR_VisitAll__VisitorDesc_VisitExit,(void*)OOC_IR_VisitAll__VisitorDesc_VisitForStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitIfStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitIndex,(void*)OOC_IR_VisitAll__VisitorDesc_VisitLen,(void*)OOC_IR_VisitAll__VisitorDesc_VisitLoopStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitModule,(void*)OOC_IR_VisitAll__VisitorDesc_VisitModuleRef,(void*)OOC_IR_VisitAll__VisitorDesc_VisitMoveBlock,(void*)OOC_IR_VisitAll__VisitorDesc_VisitNegate,(void*)OOC_IR_VisitAll__VisitorDesc_VisitNewBlock,(void*)OOC_IR_VisitAll__VisitorDesc_VisitNewObject,(void*)OOC_IR_VisitAll__VisitorDesc_VisitNot,(void*)OOC_IR_VisitAll__VisitorDesc_VisitOdd,(void*)OOC_IR_VisitAll__VisitorDesc_VisitPredefProc,(void*)OOC_IR_VisitAll__VisitorDesc_VisitProcedure,(void*)OOC_IR_VisitAll__VisitorDesc_VisitProcedureRef,(void*)OOC_IR_VisitAll__VisitorDesc_VisitRaise,(void*)OOC_IR_VisitAll__VisitorDesc_VisitRepeatStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitReturn,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSelectField,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSelectProc,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSetMember,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSetOp,(void*)OOC_IR_VisitAll__VisitorDesc_VisitSetRange,(void*)OOC_IR_VisitAll__VisitorDesc_VisitShift,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTryStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeCast,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeConv,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeGuard,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeRef,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeTag,(void*)OOC_IR_VisitAll__VisitorDesc_VisitTypeTest,(void*)OOC_IR_VisitAll__VisitorDesc_VisitVar,(void*)OOC_IR_VisitAll__VisitorDesc_VisitWhileStatm,(void*)OOC_IR_VisitAll__VisitorDesc_VisitWithStatm}, &_mid, "VisitorCallsDesc", 8, 2, RT0__strRecord };
RT0__StructDesc _td_OOC_IR_CheckUses__ErrorContext = { (RT0__Struct[]){&_td_OOC_IR_CheckUses__ErrorContextDesc}, NULL, &_mid, "ErrorContext", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_IR_CheckUses__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_OOC_Error__ContextDesc,&_td_OOC_IR_CheckUses__ErrorContextDesc}, (void*[]){(void*)OOC_IR_CheckUses__ErrorContextDesc_GetTemplate,(void*)OOC_Error__ContextDesc_BaseTemplate}, &_mid, "ErrorContextDesc", 4, 2, RT0__strRecord };
RT0__StructDesc _td_OOC_IR_CheckUses__4996 = { (RT0__Struct[]){&RT0__longchar}, NULL, &_mid, NULL, 256, 128, RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:IR:CheckUses", (RT0__Struct[]) { &_td_OOC_IR_CheckUses__Def, &_td_OOC_IR_CheckUses__DefDesc, &_td_OOC_IR_CheckUses__ProcData, &_td_OOC_IR_CheckUses__ProcDataDesc, &_td_OOC_IR_CheckUses__Visitor, &_td_OOC_IR_CheckUses__VisitorDesc, &_td_OOC_IR_CheckUses__VisitorCalls, &_td_OOC_IR_CheckUses__VisitorCallsDesc, &_td_OOC_IR_CheckUses__ErrorContext, &_td_OOC_IR_CheckUses__ErrorContextDesc, NULL } };

extern void OOC_OOC_IR_CheckUses_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_IR_CheckUses_init();
}

/* --- */
