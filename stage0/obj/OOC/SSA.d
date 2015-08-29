#include <OOC/SSA.oh>
#include <Log.oh>
#include <OOC/SymbolTable/Predef.oh>
Object_BigInt__BigInt OOC_SSA__nil;
static void OOC_SSA__SetUse(OOC_SSA__Result arg, OOC_SSA__Opnd opnd);
static void OOC_SSA__DeleteUse(OOC_SSA__Opnd opnd);
static void OOC_SSA__InitOpnd(OOC_SSA__Opnd opnd, OOC_SSA__Result arg, OOC_INT8 _class);
static OOC_SSA__Opnd OOC_SSA__NewOpnd(OOC_SSA__Result arg, OOC_INT8 _class);
static void OOC_SSA__InitTypedOpnd(OOC_SSA__TypedOpnd opnd, OOC_SSA__Result arg, OOC_INT8 _class, OOC_SymbolTable__Type type, OOC_CHAR8 passByReference);
static OOC_SSA__Opnd OOC_SSA__NewTypedOpnd(OOC_SSA__Result arg, OOC_INT8 _class, OOC_SymbolTable__Type type, OOC_CHAR8 passByReference);
static void OOC_SSA__InitResult(OOC_SSA__Result res, OOC_SSA__Instr instr, OOC_INT8 _class, OOC_INT8 subclass);
static void OOC_SSA__InitInstr(OOC_SSA__Instr instr, OOC_INT8 opcode, OOC_INT8 subclass);
static void OOC_SSA__AddOpnd(OOC_SSA__Instr instr, OOC_SSA__Opnd opnd);
static void OOC_SSA__InitConst(OOC_SSA__Const _const, OOC_INT8 subclass, Object_Boxed__Object value, OOC_SymbolTable__Type type);
static void OOC_SSA__InitDeclRef(OOC_SSA__DeclRef declRef, OOC_SymbolTable__Declaration decl);
static void OOC_SSA__InitTypeRef(OOC_SSA__TypeRef typeRef, OOC_SymbolTable__Type type);
static void OOC_SSA__InitAddress(OOC_SSA__Address address, OOC_INT8 opcode, OOC_SymbolTable__Declaration decl);
static OOC_SSA__Address OOC_SSA__NewAddress(OOC_INT8 opcode, OOC_SymbolTable__Declaration decl);
static void OOC_SSA__InitProcBlock(OOC_SSA__ProcBlock pb, OOC_SymbolTable__ProcDecl procDecl, OOC_CHAR8 checkFunctionResult);
static void OOC_SSA__AppendInstr(OOC_SSA__ProcBlock pb, OOC_SSA__Instr instr);
static OOC_INT32 OOC_SSA__ConstBucket(OOC_SymbolTable__Type type);
static void OOC_SSA__Add(OOC_SSA__Instr *list, OOC_SSA__Instr instr);
static void OOC_SSA__Remove(OOC_SSA__Instr *list, OOC_SSA__Instr instr);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_SSA__Node = { (RT0__Struct[]){&_td_OOC_SSA__NodeDesc}, NULL, &_mid, "Node", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA__Opnd = { (RT0__Struct[]){&_td_OOC_SSA__OpndDesc}, NULL, &_mid, "Opnd", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA__Result = { (RT0__Struct[]){&_td_OOC_SSA__ResultDesc}, NULL, &_mid, "Result", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA__Instr = { (RT0__Struct[]){&_td_OOC_SSA__InstrDesc}, NULL, &_mid, "Instr", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA__Const = { (RT0__Struct[]){&_td_OOC_SSA__ConstDesc}, NULL, &_mid, "Const", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA__DeclRef = { (RT0__Struct[]){&_td_OOC_SSA__DeclRefDesc}, NULL, &_mid, "DeclRef", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA__TypeRef = { (RT0__Struct[]){&_td_OOC_SSA__TypeRefDesc}, NULL, &_mid, "TypeRef", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA__Address = { (RT0__Struct[]){&_td_OOC_SSA__AddressDesc}, NULL, &_mid, "Address", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA__NodeDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString}, &_mid, "NodeDesc", 0, 1, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA__OpndDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA__OpndDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString,(void*)OOC_SSA__OpndDesc_DeleteOpnd,(void*)OOC_SSA__OpndDesc_GetIntConst,(void*)OOC_SSA__OpndDesc_IsScheduleOpnd,(void*)OOC_SSA__OpndDesc_IsValueOpnd,(void*)OOC_SSA__OpndDesc_IsValueOpndHere,(void*)OOC_SSA__OpndDesc_OpndIndex,(void*)OOC_SSA__OpndDesc_ReplaceArg}, &_mid, "OpndDesc", 20, 2, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA__TypedOpnd = { (RT0__Struct[]){&_td_OOC_SSA__TypedOpndDesc}, NULL, &_mid, "TypedOpnd", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA__TypedOpndDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA__OpndDesc,&_td_OOC_SSA__TypedOpndDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString,(void*)OOC_SSA__OpndDesc_DeleteOpnd,(void*)OOC_SSA__OpndDesc_GetIntConst,(void*)OOC_SSA__OpndDesc_IsScheduleOpnd,(void*)OOC_SSA__OpndDesc_IsValueOpnd,(void*)OOC_SSA__OpndDesc_IsValueOpndHere,(void*)OOC_SSA__OpndDesc_OpndIndex,(void*)OOC_SSA__OpndDesc_ReplaceArg}, &_mid, "TypedOpndDesc", 28, 3, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA__ResultDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA__ResultDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString,(void*)OOC_SSA__ResultDesc_DeleteResult,(void*)OOC_SSA__ResultDesc_IsBooleanConst,(void*)OOC_SSA__ResultDesc_LogId,(void*)OOC_SSA__ResultDesc_ReplaceUses,(void*)OOC_SSA__ResultDesc_ResultIndex}, &_mid, "ResultDesc", 24, 2, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA__InstrDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA__ResultDesc,&_td_OOC_SSA__InstrDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString,(void*)OOC_SSA__ResultDesc_DeleteResult,(void*)OOC_SSA__ResultDesc_IsBooleanConst,(void*)OOC_SSA__ResultDesc_LogId,(void*)OOC_SSA__ResultDesc_ReplaceUses,(void*)OOC_SSA__ResultDesc_ResultIndex,(void*)OOC_SSA__InstrDesc_AddOpnd,(void*)OOC_SSA__InstrDesc_AddResult,(void*)OOC_SSA__InstrDesc_AddResultSubclass,(void*)OOC_SSA__InstrDesc_AddTypedOpnd,(void*)OOC_SSA__InstrDesc_AddUniqueOpnd,(void*)OOC_SSA__InstrDesc_CountOpndClass,(void*)OOC_SSA__InstrDesc_GetArgClass,(void*)OOC_SSA__InstrDesc_GetArgStore,(void*)OOC_SSA__InstrDesc_GetBackwardFeed,(void*)OOC_SSA__InstrDesc_GetCollectTarget,(void*)OOC_SSA__InstrDesc_GetLoopEnd,(void*)OOC_SSA__InstrDesc_GetLoopStart,(void*)OOC_SSA__InstrDesc_GetOpcodeName,(void*)OOC_SSA__InstrDesc_GetOpndClass,(void*)OOC_SSA__InstrDesc_GetResultClass,(void*)OOC_SSA__InstrDesc_GetResultStore,(void*)OOC_SSA__InstrDesc_GetResultType,(void*)OOC_SSA__InstrDesc_IsConst,(void*)OOC_SSA__InstrDesc_IsSwitchStatm,(void*)OOC_SSA__InstrDesc_IsSync,(void*)OOC_SSA__InstrDesc_LastOpnd,(void*)OOC_SSA__InstrDesc_LogOpcode,(void*)OOC_SSA__InstrDesc_NthArg,(void*)OOC_SSA__InstrDesc_NthOpnd,(void*)OOC_SSA__InstrDesc_NthResult,(void*)OOC_SSA__InstrDesc_SetPos,(void*)OOC_SSA__InstrDesc_SetSubclass,(void*)OOC_SSA__InstrDesc_SizeOpndList,(void*)OOC_SSA__InstrDesc_SizeResultList,(void*)OOC_SSA__InstrDesc_UniqueResult}, &_mid, "InstrDesc", 44, 3, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA__ConstDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA__ResultDesc,&_td_OOC_SSA__InstrDesc,&_td_OOC_SSA__ConstDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString,(void*)OOC_SSA__ResultDesc_DeleteResult,(void*)OOC_SSA__ResultDesc_IsBooleanConst,(void*)OOC_SSA__ResultDesc_LogId,(void*)OOC_SSA__ResultDesc_ReplaceUses,(void*)OOC_SSA__ResultDesc_ResultIndex,(void*)OOC_SSA__InstrDesc_AddOpnd,(void*)OOC_SSA__InstrDesc_AddResult,(void*)OOC_SSA__InstrDesc_AddResultSubclass,(void*)OOC_SSA__InstrDesc_AddTypedOpnd,(void*)OOC_SSA__InstrDesc_AddUniqueOpnd,(void*)OOC_SSA__InstrDesc_CountOpndClass,(void*)OOC_SSA__InstrDesc_GetArgClass,(void*)OOC_SSA__InstrDesc_GetArgStore,(void*)OOC_SSA__InstrDesc_GetBackwardFeed,(void*)OOC_SSA__InstrDesc_GetCollectTarget,(void*)OOC_SSA__InstrDesc_GetLoopEnd,(void*)OOC_SSA__InstrDesc_GetLoopStart,(void*)OOC_SSA__InstrDesc_GetOpcodeName,(void*)OOC_SSA__InstrDesc_GetOpndClass,(void*)OOC_SSA__InstrDesc_GetResultClass,(void*)OOC_SSA__InstrDesc_GetResultStore,(void*)OOC_SSA__InstrDesc_GetResultType,(void*)OOC_SSA__InstrDesc_IsConst,(void*)OOC_SSA__InstrDesc_IsSwitchStatm,(void*)OOC_SSA__InstrDesc_IsSync,(void*)OOC_SSA__InstrDesc_LastOpnd,(void*)OOC_SSA__InstrDesc_LogOpcode,(void*)OOC_SSA__InstrDesc_NthArg,(void*)OOC_SSA__InstrDesc_NthOpnd,(void*)OOC_SSA__InstrDesc_NthResult,(void*)OOC_SSA__InstrDesc_SetPos,(void*)OOC_SSA__InstrDesc_SetSubclass,(void*)OOC_SSA__InstrDesc_SizeOpndList,(void*)OOC_SSA__InstrDesc_SizeResultList,(void*)OOC_SSA__InstrDesc_UniqueResult}, &_mid, "ConstDesc", 52, 4, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA__DeclRefDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA__ResultDesc,&_td_OOC_SSA__InstrDesc,&_td_OOC_SSA__DeclRefDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString,(void*)OOC_SSA__ResultDesc_DeleteResult,(void*)OOC_SSA__ResultDesc_IsBooleanConst,(void*)OOC_SSA__ResultDesc_LogId,(void*)OOC_SSA__ResultDesc_ReplaceUses,(void*)OOC_SSA__ResultDesc_ResultIndex,(void*)OOC_SSA__InstrDesc_AddOpnd,(void*)OOC_SSA__InstrDesc_AddResult,(void*)OOC_SSA__InstrDesc_AddResultSubclass,(void*)OOC_SSA__InstrDesc_AddTypedOpnd,(void*)OOC_SSA__InstrDesc_AddUniqueOpnd,(void*)OOC_SSA__InstrDesc_CountOpndClass,(void*)OOC_SSA__InstrDesc_GetArgClass,(void*)OOC_SSA__InstrDesc_GetArgStore,(void*)OOC_SSA__InstrDesc_GetBackwardFeed,(void*)OOC_SSA__InstrDesc_GetCollectTarget,(void*)OOC_SSA__InstrDesc_GetLoopEnd,(void*)OOC_SSA__InstrDesc_GetLoopStart,(void*)OOC_SSA__InstrDesc_GetOpcodeName,(void*)OOC_SSA__InstrDesc_GetOpndClass,(void*)OOC_SSA__InstrDesc_GetResultClass,(void*)OOC_SSA__InstrDesc_GetResultStore,(void*)OOC_SSA__InstrDesc_GetResultType,(void*)OOC_SSA__InstrDesc_IsConst,(void*)OOC_SSA__InstrDesc_IsSwitchStatm,(void*)OOC_SSA__InstrDesc_IsSync,(void*)OOC_SSA__InstrDesc_LastOpnd,(void*)OOC_SSA__InstrDesc_LogOpcode,(void*)OOC_SSA__InstrDesc_NthArg,(void*)OOC_SSA__InstrDesc_NthOpnd,(void*)OOC_SSA__InstrDesc_NthResult,(void*)OOC_SSA__InstrDesc_SetPos,(void*)OOC_SSA__InstrDesc_SetSubclass,(void*)OOC_SSA__InstrDesc_SizeOpndList,(void*)OOC_SSA__InstrDesc_SizeResultList,(void*)OOC_SSA__InstrDesc_UniqueResult}, &_mid, "DeclRefDesc", 48, 4, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA__TypeRefDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA__ResultDesc,&_td_OOC_SSA__InstrDesc,&_td_OOC_SSA__TypeRefDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString,(void*)OOC_SSA__ResultDesc_DeleteResult,(void*)OOC_SSA__ResultDesc_IsBooleanConst,(void*)OOC_SSA__ResultDesc_LogId,(void*)OOC_SSA__ResultDesc_ReplaceUses,(void*)OOC_SSA__ResultDesc_ResultIndex,(void*)OOC_SSA__InstrDesc_AddOpnd,(void*)OOC_SSA__InstrDesc_AddResult,(void*)OOC_SSA__InstrDesc_AddResultSubclass,(void*)OOC_SSA__InstrDesc_AddTypedOpnd,(void*)OOC_SSA__InstrDesc_AddUniqueOpnd,(void*)OOC_SSA__InstrDesc_CountOpndClass,(void*)OOC_SSA__InstrDesc_GetArgClass,(void*)OOC_SSA__InstrDesc_GetArgStore,(void*)OOC_SSA__InstrDesc_GetBackwardFeed,(void*)OOC_SSA__InstrDesc_GetCollectTarget,(void*)OOC_SSA__InstrDesc_GetLoopEnd,(void*)OOC_SSA__InstrDesc_GetLoopStart,(void*)OOC_SSA__InstrDesc_GetOpcodeName,(void*)OOC_SSA__InstrDesc_GetOpndClass,(void*)OOC_SSA__InstrDesc_GetResultClass,(void*)OOC_SSA__InstrDesc_GetResultStore,(void*)OOC_SSA__InstrDesc_GetResultType,(void*)OOC_SSA__InstrDesc_IsConst,(void*)OOC_SSA__InstrDesc_IsSwitchStatm,(void*)OOC_SSA__InstrDesc_IsSync,(void*)OOC_SSA__InstrDesc_LastOpnd,(void*)OOC_SSA__InstrDesc_LogOpcode,(void*)OOC_SSA__InstrDesc_NthArg,(void*)OOC_SSA__InstrDesc_NthOpnd,(void*)OOC_SSA__InstrDesc_NthResult,(void*)OOC_SSA__InstrDesc_SetPos,(void*)OOC_SSA__InstrDesc_SetSubclass,(void*)OOC_SSA__InstrDesc_SizeOpndList,(void*)OOC_SSA__InstrDesc_SizeResultList,(void*)OOC_SSA__InstrDesc_UniqueResult}, &_mid, "TypeRefDesc", 48, 4, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA__AddressDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA__ResultDesc,&_td_OOC_SSA__InstrDesc,&_td_OOC_SSA__AddressDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString,(void*)OOC_SSA__ResultDesc_DeleteResult,(void*)OOC_SSA__ResultDesc_IsBooleanConst,(void*)OOC_SSA__ResultDesc_LogId,(void*)OOC_SSA__ResultDesc_ReplaceUses,(void*)OOC_SSA__ResultDesc_ResultIndex,(void*)OOC_SSA__InstrDesc_AddOpnd,(void*)OOC_SSA__InstrDesc_AddResult,(void*)OOC_SSA__InstrDesc_AddResultSubclass,(void*)OOC_SSA__InstrDesc_AddTypedOpnd,(void*)OOC_SSA__InstrDesc_AddUniqueOpnd,(void*)OOC_SSA__InstrDesc_CountOpndClass,(void*)OOC_SSA__InstrDesc_GetArgClass,(void*)OOC_SSA__InstrDesc_GetArgStore,(void*)OOC_SSA__InstrDesc_GetBackwardFeed,(void*)OOC_SSA__InstrDesc_GetCollectTarget,(void*)OOC_SSA__InstrDesc_GetLoopEnd,(void*)OOC_SSA__InstrDesc_GetLoopStart,(void*)OOC_SSA__InstrDesc_GetOpcodeName,(void*)OOC_SSA__InstrDesc_GetOpndClass,(void*)OOC_SSA__InstrDesc_GetResultClass,(void*)OOC_SSA__InstrDesc_GetResultStore,(void*)OOC_SSA__InstrDesc_GetResultType,(void*)OOC_SSA__InstrDesc_IsConst,(void*)OOC_SSA__InstrDesc_IsSwitchStatm,(void*)OOC_SSA__InstrDesc_IsSync,(void*)OOC_SSA__InstrDesc_LastOpnd,(void*)OOC_SSA__InstrDesc_LogOpcode,(void*)OOC_SSA__InstrDesc_NthArg,(void*)OOC_SSA__InstrDesc_NthOpnd,(void*)OOC_SSA__InstrDesc_NthResult,(void*)OOC_SSA__InstrDesc_SetPos,(void*)OOC_SSA__InstrDesc_SetSubclass,(void*)OOC_SSA__InstrDesc_SizeOpndList,(void*)OOC_SSA__InstrDesc_SizeResultList,(void*)OOC_SSA__InstrDesc_UniqueResult}, &_mid, "AddressDesc", 48, 4, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA__ProcBlock = { (RT0__Struct[]){&_td_OOC_SSA__ProcBlockDesc}, NULL, &_mid, "ProcBlock", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_SSA__ProcBlockDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_OOC_SSA__NodeDesc,&_td_OOC_SSA__ProcBlockDesc}, (void*[]){(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)Object__ObjectDesc_ToString,(void*)OOC_SSA__ProcBlockDesc_AddCopyParameter,(void*)OOC_SSA__ProcBlockDesc_AddGetLengthInstr,(void*)OOC_SSA__ProcBlockDesc_AddInstr,(void*)OOC_SSA__ProcBlockDesc_AddSetInstr,(void*)OOC_SSA__ProcBlockDesc_DeleteInstr,(void*)OOC_SSA__ProcBlockDesc_Destroy,(void*)OOC_SSA__ProcBlockDesc_GetAddress,(void*)OOC_SSA__ProcBlockDesc_GetConst,(void*)OOC_SSA__ProcBlockDesc_GetConstBool,(void*)OOC_SSA__ProcBlockDesc_GetConstInt,(void*)OOC_SSA__ProcBlockDesc_GetConstNil,(void*)OOC_SSA__ProcBlockDesc_GetDeclRef,(void*)OOC_SSA__ProcBlockDesc_GetEnter,(void*)OOC_SSA__ProcBlockDesc_GetTypeRef,(void*)OOC_SSA__ProcBlockDesc_Reverse,(void*)OOC_SSA__ProcBlockDesc_SetAddress,(void*)OOC_SSA__ProcBlockDesc_SetLoopContext,(void*)OOC_SSA__ProcBlockDesc_SetMarkers,(void*)OOC_SSA__ProcBlockDesc_TopSort}, &_mid, "ProcBlockDesc", 104, 2, RT0__strRecord };
RT0__StructDesc _td_OOC_SSA__7040 = { (RT0__Struct[]){&_td_ADT_Dictionary__Dictionary}, NULL, &_mid, NULL, 72, 18, RT0__strArray };
RT0__StructDesc _td_OOC_SSA__15902 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA__24519 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA__27628 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_SSA__27660 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 64, 64, RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:SSA", (RT0__Struct[]) { &_td_OOC_SSA__Node, &_td_OOC_SSA__Opnd, &_td_OOC_SSA__Result, &_td_OOC_SSA__Instr, &_td_OOC_SSA__Const, &_td_OOC_SSA__DeclRef, &_td_OOC_SSA__TypeRef, &_td_OOC_SSA__Address, &_td_OOC_SSA__NodeDesc, &_td_OOC_SSA__OpndDesc, &_td_OOC_SSA__TypedOpnd, &_td_OOC_SSA__TypedOpndDesc, &_td_OOC_SSA__ResultDesc, &_td_OOC_SSA__InstrDesc, &_td_OOC_SSA__ConstDesc, &_td_OOC_SSA__DeclRefDesc, &_td_OOC_SSA__TypeRefDesc, &_td_OOC_SSA__AddressDesc, &_td_OOC_SSA__ProcBlock, &_td_OOC_SSA__ProcBlockDesc, NULL } };

extern void OOC_OOC_SSA_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_SSA_init();
}

/* --- */
