#include <OOC/IR/ConstFold.d>
#include <__oo2c.h>
#include <setjmp.h>

static void OOC_IR_ConstFold__InitConstFold(OOC_IR_ConstFold__ConstFold c) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)c;
  OOC_IR__InitConstFold((OOC_IR__ConstFold)i0, (OOC_IR__Builder)(OOC_INT32)0);
  return;
  ;
}

OOC_IR_ConstFold__ConstFold OOC_IR_ConstFold__NewConstFold(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_IR_ConstFold__ConstFold.baseTypes[0]);
  OOC_IR_ConstFold__InitConstFold((OOC_IR_ConstFold__ConstFold)i0);
  return (OOC_IR_ConstFold__ConstFold)i0;
  ;
}

static OOC_SymbolTable__Type OOC_IR_ConstFold__SmallestType(Object_Boxed__Object value) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)value;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1691)))), &_td_Object_BigInt__BigIntDesc);
  if (i1) goto l11;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1763)))), &_td_Object_Boxed__LongRealDesc);
  if (i1) goto l9;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1887)))), &_td_Object_Boxed__SetDesc);
  if (i1) goto l7;
  _failed_with(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1879)))), 1879);
  goto l12;
l7:
  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(10);
  return (OOC_SymbolTable__Type)i0;
  goto l12;
l9:
  i0 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(8);
  return (OOC_SymbolTable__Type)i0;
  goto l12;
l11:
  i0 = (OOC_INT32)OOC_SymbolTable_Predef__SmallestIntType((Object_BigInt__BigInt)i0);
  return (OOC_SymbolTable__Type)i0;
l12:
  _failed_function(1559); return 0;
  ;
}

OOC_IR__Const OOC_IR_ConstFold__ConstFoldDesc_ValueConst(OOC_IR_ConstFold__ConstFold c, Object_Boxed__Object value, OOC_IR__Operator op) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)value;
  i1 = (OOC_INT32)OOC_IR_ConstFold__SmallestType((Object_Boxed__Object)i0);
  type = (OOC_SymbolTable__Type)i1;
  i2 = i1==(OOC_INT32)0;
  if (i2) goto l3;
  i2 = (OOC_INT32)c;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2267));
  i4 = (OOC_INT32)op;
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 2287));
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2267));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 2275)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i2, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i1, (Object_Boxed__Object)i0);
  return (OOC_IR__Const)i0;
  goto l4;
l3:
  i0 = (OOC_INT32)c;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2193));
  i2 = (OOC_INT32)op;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2226));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2193));
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2201)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 10, (OOC_Scanner_SymList__Symbol)i2);
  return (OOC_IR__Const)(OOC_INT32)0;
l4:
  _failed_function(2046); return 0;
  ;
}

OOC_IR__Const OOC_IR_ConstFold__ConstFoldDesc_BooleanConst(OOC_IR_ConstFold__ConstFold c, OOC_CHAR8 value, OOC_IR__Operator op) {
  register OOC_INT32 i0,i1,i2,i3,i4;

  i0 = (OOC_INT32)c;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2431));
  i2 = (OOC_INT32)op;
  i3 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(0);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2451));
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2431));
  i4 = value;
  i4 = (OOC_INT32)Object_Boxed__NewBoolean(i4);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2439)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i0, (OOC_Scanner_SymList__Symbol)i2, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i4);
  return (OOC_IR__Const)i0;
  ;
}

OOC_CHAR8 OOC_IR_ConstFold__ConstFoldDesc_ValidEval(OOC_IR_ConstFold__ConstFold c, OOC_IR__Expression expr, Object_Boxed__Object *result) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)c;
  *(OOC_INT32*)((_check_pointer(i0, 2640))+4) = (OOC_INT32)0;
  i1 = (OOC_INT32)expr;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2662)))), OOC_IR__NodeDesc_Accept)),OOC_IR__NodeDesc_Accept)((OOC_IR__Node)i1, (OOC_IR__Visitor)i0);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2681))+4);
  i1 = i1!=(OOC_INT32)0;
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2711));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2719))+20);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2700))+4);
  i1 = i2!=i1;
  
l5:
  if (!i1) goto l7;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2751))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 2762)))), &_td_OOC_IR__ConstDesc, 2762)), 2768))+8);
  *result = (Object_Boxed__Object)i0;
  return 1u;
l7:
  return 0u;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitConst(OOC_IR_ConstFold__ConstFold c, OOC_IR__Const _const) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)c;
  i1 = (OOC_INT32)_const;
  *(OOC_INT32*)((_check_pointer(i0, 2901))+4) = i1;
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitVar(OOC_IR_ConstFold__ConstFold c, OOC_IR__Var car) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitPredefProc(OOC_IR_ConstFold__ConstFold c, OOC_IR__PredefProc pproc) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitProcedureRef(OOC_IR_ConstFold__ConstFold c, OOC_IR__ProcedureRef procRef) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitTypeRef(OOC_IR_ConstFold__ConstFold c, OOC_IR__TypeRef typeRef) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitModuleRef(OOC_IR_ConstFold__ConstFold c, OOC_IR__ModuleRef modRef) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitAdr(OOC_IR_ConstFold__ConstFold c, OOC_IR__Adr adr) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitLen(OOC_IR_ConstFold__ConstFold c, OOC_IR__Len len) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 length;
  OOC_SymbolTable__Type type;

  i0 = (OOC_INT32)len;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 3613))+8);
  switch (i1) {
  case 16:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3664))+12);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3674)))), &_td_OOC_IR__ConstDesc, 3674)), 3680))+8);
    i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3687)))), &_td_Object_Boxed__StringDesc);
    if (i1) goto l5;
    length = 1;
    
    goto l10;
l5:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3730))+12);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3740)))), &_td_OOC_IR__ConstDesc, 3740)), 3746))+8);
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3759)))), &_td_Object_Boxed__StringDesc, 3759)), 3766));
    i1 = *(OOC_INT32*)(_check_pointer(i1, 3773));
    length = (i1+1);
    
    goto l10;
  case 17:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 3940))+20);
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 3955))+4);
    i2 = *(OOC_INT32*)((_check_pointer(i0, 3996))+16);
    i1 = (OOC_INT32)OOC_SymbolTable__ArrayDesc_GetNthElementType((OOC_SymbolTable__Array)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3966)))), &_td_OOC_SymbolTable__ArrayDesc, 3966)), i2);
    type = (OOC_SymbolTable__Type)i1;
    i1 = *(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 4028)))), &_td_OOC_SymbolTable__ArrayDesc, 4028)), 4034))+52);
    length = i1;
    goto l10;
  case 18:
  case 19:
    i1 = (OOC_INT32)c;
    *(OOC_INT32*)((_check_pointer(i1, 4106))+4) = 0;
    return;
    goto l10;
  default:
    _failed_case(i1, 3605);
    goto l10;
  }
l10:
  i1 = (OOC_INT32)c;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4156));
  i3 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(6);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4177));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 4156));
  i5 = length;
  i5 = (OOC_INT32)Object_BigInt__NewInt(i5);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 4164)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i5);
  *(OOC_INT32*)((_check_pointer(i1, 4144))+4) = i0;
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitConstructor(OOC_IR_ConstFold__ConstFold c, OOC_IR__Constructor cons) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCurrentException(OOC_IR_ConstFold__ConstFold c, OOC_IR__CurrentException ce) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitDeref(OOC_IR_ConstFold__ConstFold c, OOC_IR__Deref deref) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitIndex(OOC_IR_ConstFold__ConstFold c, OOC_IR__Index index) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitSetMember(OOC_IR_ConstFold__ConstFold c, OOC_IR__SetMember op) {
  register OOC_INT32 i0,i1,i2,i3;
  Object_Boxed__Object e;
  Object_Boxed__Object s;
  OOC_INT32 element;
  OOC_UINT32 set;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4967))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&e);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4996))+12);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&s);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 5160))+4) = 0;
  goto l8;
l7:
  i1 = (OOC_INT32)e;
  i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5036)))), &_td_Object_BigInt__BigIntDesc, 5036)));
  element = i1;
  i3 = (OOC_INT32)s;
  i3 = *(OOC_UINT32*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5078)))), &_td_Object_Boxed__SetDesc, 5078)), 5082));
  set = i3;
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_BooleanConst((OOC_IR_ConstFold__ConstFold)i2, (_in(i1,i3)), (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 5097))+4) = i0;
l8:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitSetRange(OOC_IR_ConstFold__ConstFold c, OOC_IR__SetRange op) {
  register OOC_INT32 i0,i1,i2,i3;
  Object_Boxed__Object l;
  Object_Boxed__Object r;
  OOC_INT32 left;
  OOC_INT32 right;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5355))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&l);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5381))+12);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&r);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 5564))+4) = (OOC_INT32)0;
  goto l8;
l7:
  i1 = (OOC_INT32)l;
  i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5417)))), &_td_Object_BigInt__BigIntDesc, 5417)));
  left = i1;
  i3 = (OOC_INT32)r;
  i3 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5462)))), &_td_Object_BigInt__BigIntDesc, 5462)));
  right = i3;
  i1 = (OOC_INT32)Object_Boxed__NewSet((_bit_range(i1,i3)));
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 5490))+4) = i0;
l8:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitSetOp(OOC_IR_ConstFold__ConstFold c, OOC_IR__SetOp op) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Object_Boxed__Object l;
  Object_Boxed__Object r;
  OOC_UINT32 left;
  OOC_UINT32 right;
  OOC_UINT32 result;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5768))+12);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&l);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5794))+16);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&r);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 6283))+4) = 0;
  goto l15;
l7:
  i1 = (OOC_INT32)l;
  i1 = *(OOC_UINT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 5832)))), &_td_Object_Boxed__SetDesc, 5832)), 5836));
  left = i1;
  i3 = (OOC_INT32)r;
  i3 = *(OOC_UINT32*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5868)))), &_td_Object_Boxed__SetDesc, 5868)), 5872));
  right = i3;
  i4 = *(OOC_INT8*)((_check_pointer(i0, 5898))+8);
  switch (i4) {
  case 6:
    result = (i1|i3);
    goto l14;
  case 7:
    result = (_logical_subtr(i1,i3));
    goto l14;
  case 8:
    result = (i1&i3);
    goto l14;
  case 9:
    result = (i1^i3);
    goto l14;
  default:
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6126));
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6158));
    i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 6126));
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6134)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i4, 6, (OOC_Scanner_SymList__Symbol)i3);
    *(OOC_INT32*)((_check_pointer(i2, 6175))+4) = 0;
    return;
    goto l14;
  }
l14:
  i1 = result;
  i1 = (OOC_INT32)Object_Boxed__NewSet(i1);
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 6216))+4) = i0;
l15:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitChangeElement(OOC_IR_ConstFold__ConstFold c, OOC_IR__ChangeElement op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitSelectField(OOC_IR_ConstFold__ConstFold c, OOC_IR__SelectField sf) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitSelectProc(OOC_IR_ConstFold__ConstFold c, OOC_IR__SelectProc sp) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitNegate(OOC_IR_ConstFold__ConstFold c, OOC_IR__Negate op) {
  register OOC_INT32 i0,i1,i2,i3;
  Object_Boxed__Object value;
  OOC_INT16 id;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6754))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&value);
  if (i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i2, 7315))+4) = 0;
  goto l10;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6788))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6796))+4);
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6806)))), &_td_OOC_SymbolTable__PredefTypeDesc, 6806)), 6817))+40);
  id = i1;
  switch (i1) {
  case 4 ... 7:
    i1 = (OOC_INT32)value;
    i1 = (OOC_INT32)Object_BigInt__BigIntDesc_Neg((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6921)))), &_td_Object_BigInt__BigIntDesc, 6921)));
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
    *(OOC_INT32*)((_check_pointer(i2, 6884))+4) = i0;
    goto l10;
  case 10:
    i1 = (OOC_INT32)value;
    i1 = *(OOC_UINT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7016)))), &_td_Object_Boxed__SetDesc, 7016)), 7020));
    i1 = (OOC_INT32)Object_Boxed__NewSet((~i1));
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
    *(OOC_INT32*)((_check_pointer(i2, 6966))+4) = i0;
    goto l10;
  case 8:
  case 9:
    i1 = (OOC_INT32)value;
    i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7139)))), &_td_Object_Boxed__LongRealDesc, 7139)), 7148)))), Object_Boxed__LongRealDesc_Neg)),Object_Boxed__LongRealDesc_Neg)((Object_Boxed__LongReal)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7139)))), &_td_Object_Boxed__LongRealDesc, 7139)));
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
    *(OOC_INT32*)((_check_pointer(i2, 7103))+4) = i0;
    goto l10;
  default:
    i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7224));
    i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7264));
    i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 7224));
    OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7232)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i3, 7, (OOC_Scanner_SymList__Symbol)i0);
    *(OOC_INT32*)((_check_pointer(i2, 7278))+4) = 0;
    goto l10;
  }
l10:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitNewBlock(OOC_IR_ConstFold__ConstFold c, OOC_IR__NewBlock _new) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitNewObject(OOC_IR_ConstFold__ConstFold c, OOC_IR__NewObject _new) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitNot(OOC_IR_ConstFold__ConstFold c, OOC_IR__Not op) {
  register OOC_INT32 i0,i1,i2;
  Object_Boxed__Object value;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7642))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&value);
  if (i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i2, 7741))+4) = 0;
  goto l4;
l3:
  i1 = (OOC_INT32)value;
  i1 = *(OOC_UINT8*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 7708)))), &_td_Object_Boxed__BooleanDesc, 7708)), 7716));
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_BooleanConst((OOC_IR_ConstFold__ConstFold)i2, (!i1), (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 7669))+4) = i0;
l4:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitAbs(OOC_IR_ConstFold__ConstFold c, OOC_IR__Abs op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitAsh(OOC_IR_ConstFold__ConstFold c, OOC_IR__Ash op) {
  register OOC_INT32 i0,i1,i2,i3;
  Object_Boxed__Object v;
  Object_Boxed__Object e;
  OOC_INT32 shift;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8000))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&v);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8027))+12);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&e);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 8299))+4) = (OOC_INT32)0;
  goto l12;
l7:
  i1 = (OOC_INT32)e;
  i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8065)))), &_td_Object_BigInt__BigIntDesc, 8065)));
  shift = i1;
  i3 = i1<0;
  if (i3) goto l10;
  i3 = (OOC_INT32)v;
  i1 = (OOC_INT32)Object_BigInt__BigIntDesc_LShift((Object_BigInt__BigInt)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8242)))), &_td_Object_BigInt__BigIntDesc, 8242)), i1);
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 8207))+4) = i0;
  goto l12;
l10:
  i3 = (OOC_INT32)v;
  i1 = (OOC_INT32)Object_BigInt__BigIntDesc_RShift((Object_BigInt__BigInt)(_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8156)))), &_td_Object_BigInt__BigIntDesc, 8156)), (-i1));
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i2, (Object_Boxed__Object)i1, (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 8121))+4) = i0;
l12:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCap(OOC_IR_ConstFold__ConstFold c, OOC_IR__Cap op) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  Object_Boxed__Object value;
  OOC_CHAR8 str[2];

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8468))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&value);
  if (i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i2, 8739))+4) = 0;
  goto l4;
l3:
  i1 = (OOC_INT32)value;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8532)))), &_td_Object_Boxed__StringDesc, 8532)), 8539));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8532)))), &_td_Object_Boxed__StringDesc, 8532)), 8539));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 8545)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, 0);
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(0, 2, OOC_UINT8, 8497))) = (_cap(i1));
  *(OOC_UINT8*)((OOC_INT32)str+(_check_index(1, 2, OOC_UINT8, 8567))) = 0u;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 8595));
  i3 = (OOC_INT32)OOC_SymbolTable_Predef__GetType(1);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8615));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 8595));
  i5 = (OOC_INT32)Object__NewLatin1((void*)(OOC_INT32)str, 2);
  i5 = (OOC_INT32)Object_Boxed__NewString((Object__String)i5);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8603)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i5);
  *(OOC_INT32*)((_check_pointer(i2, 8583))+4) = i0;
l4:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitEntier(OOC_IR_ConstFold__ConstFold c, OOC_IR__Entier op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitOdd(OOC_IR_ConstFold__ConstFold c, OOC_IR__Odd op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitShift(OOC_IR_ConstFold__ConstFold c, OOC_IR__Shift op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitBinaryArith(OOC_IR_ConstFold__ConstFold c, OOC_IR__BinaryArith op) {
  register OOC_INT32 i0,i1,i2;
  Object_Boxed__Object l;
  Object_Boxed__Object r;
  Object_Boxed__Object result;
  auto Object_Boxed__Object OOC_IR_ConstFold__ConstFoldDesc_VisitBinaryArith_IntegerOp(void);
  auto Object_Boxed__Object OOC_IR_ConstFold__ConstFoldDesc_VisitBinaryArith_RealOp(void);
    
    Object_Boxed__Object OOC_IR_ConstFold__ConstFoldDesc_VisitBinaryArith_IntegerOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      Object_BigInt__BigInt left;
      Object_BigInt__BigInt right;

      i0 = (OOC_INT32)l;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 9251)))), &_td_Object_BigInt__BigIntDesc, 9251);
      left = (Object_BigInt__BigInt)i0;
      i1 = (OOC_INT32)r;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9282)))), &_td_Object_BigInt__BigIntDesc, 9282);
      right = (Object_BigInt__BigInt)i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 9307))+8);
      switch (i3) {
      case 0:
        i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Add((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
        return (Object_Boxed__Object)i0;
        goto l16;
      case 1:
        i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Sub((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
        return (Object_Boxed__Object)i0;
        goto l16;
      case 4:
        i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Mul((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
        return (Object_Boxed__Object)i0;
        goto l16;
      case 2:
        i3 = Object_BigInt__BigIntDesc_Sign((Object_BigInt__BigInt)i1);
        i3 = i3==0;
        if (i3) goto l8;
        i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Div((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
        return (Object_Boxed__Object)i0;
        goto l16;
l8:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9560));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 9595));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9560));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9568)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 8, (OOC_Scanner_SymList__Symbol)i2);
        goto l16;
      case 5:
        i3 = Object_BigInt__BigIntDesc_Sign((Object_BigInt__BigInt)i1);
        i3 = i3==0;
        if (i3) goto l13;
        i0 = (OOC_INT32)Object_BigInt__BigIntDesc_Mod((Object_BigInt__BigInt)i0, (Object_BigInt__BigInt)i1);
        return (Object_Boxed__Object)i0;
        goto l16;
l13:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9715));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 9750));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9715));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9723)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 8, (OOC_Scanner_SymList__Symbol)i2);
        goto l16;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9827));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 9859));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9827));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 9835)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        goto l16;
      }
l16:
      return (Object_Boxed__Object)0;
      ;
    }

    
    Object_Boxed__Object OOC_IR_ConstFold__ConstFoldDesc_VisitBinaryArith_RealOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      register OOC_REAL64 d0;
      Object_Boxed__LongReal left;
      Object_Boxed__LongReal right;

      i0 = (OOC_INT32)l;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10015)))), &_td_Object_Boxed__LongRealDesc, 10015);
      left = (Object_Boxed__LongReal)i0;
      i1 = (OOC_INT32)r;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10047)))), &_td_Object_Boxed__LongRealDesc, 10047);
      right = (Object_Boxed__LongReal)i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 10074))+8);
      switch (i3) {
      case 0:
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10117)))), Object_Boxed__LongRealDesc_Add)),Object_Boxed__LongRealDesc_Add)((Object_Boxed__LongReal)i0, (Object_Boxed__LongReal)i1);
        return (Object_Boxed__Object)i0;
        goto l11;
      case 1:
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10161)))), Object_Boxed__LongRealDesc_Sub)),Object_Boxed__LongRealDesc_Sub)((Object_Boxed__LongReal)i0, (Object_Boxed__LongReal)i1);
        return (Object_Boxed__Object)i0;
        goto l11;
      case 4:
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10205)))), Object_Boxed__LongRealDesc_Mul)),Object_Boxed__LongRealDesc_Mul)((Object_Boxed__LongReal)i0, (Object_Boxed__LongReal)i1);
        return (Object_Boxed__Object)i0;
        goto l11;
      case 3:
        d0 = *(OOC_REAL64*)(_check_pointer(i1, 10254));
        i3 = d0==0.0000000000000000;
        if (i3) goto l8;
        i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10352)))), Object_Boxed__LongRealDesc_Div)),Object_Boxed__LongRealDesc_Div)((Object_Boxed__LongReal)i0, (Object_Boxed__LongReal)i1);
        return (Object_Boxed__Object)i0;
        goto l11;
l8:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10280));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10315));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10280));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10288)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 8, (OOC_Scanner_SymList__Symbol)i2);
        goto l11;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10392));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 10424));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10392));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 10400)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        goto l11;
      }
l11:
      return (Object_Boxed__Object)0;
      ;
    }


  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10560))+12);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&l);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10586))+16);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&r);
  
l5:
  if (!i1) goto l15;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10654))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10659))+4);
  i0 = *(OOC_INT16*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10669)))), &_td_OOC_SymbolTable__PredefTypeDesc, 10669)), 10680))+40);
  switch (i0) {
  case 4:
  case 5:
  case 6:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitBinaryArith_IntegerOp();
    result = (Object_Boxed__Object)i0;
    goto l11;
  case 8:
  case 9:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitBinaryArith_RealOp();
    result = (Object_Boxed__Object)i0;
    goto l11;
  default:
    _failed_case(i0, 10647);
    goto l11;
  }
l11:
  i0 = (OOC_INT32)result;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l15;
  i1 = (OOC_INT32)c;
  i2 = (OOC_INT32)op;
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_ValueConst((OOC_IR_ConstFold__ConstFold)i1, (Object_Boxed__Object)i0, (OOC_IR__Operator)i2);
  *(OOC_INT32*)((_check_pointer(i1, 10945))+4) = i0;
  return;
l15:
  i0 = (OOC_INT32)c;
  *(OOC_INT32*)((_check_pointer(i0, 11014))+4) = (OOC_INT32)0;
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitBooleanOp(OOC_IR_ConstFold__ConstFold c, OOC_IR__BooleanOp op) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  Object_Boxed__Object l;
  Object_Boxed__Object r;
  OOC_CHAR8 left;
  OOC_CHAR8 right;
  OOC_CHAR8 result;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11210))+12);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&l);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11236))+16);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&r);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 11510))+4) = 0;
  goto l21;
l7:
  i1 = (OOC_INT32)l;
  i1 = *(OOC_UINT8*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11274)))), &_td_Object_Boxed__BooleanDesc, 11274)), 11282));
  left = i1;
  i3 = (OOC_INT32)r;
  i3 = *(OOC_UINT8*)(_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 11313)))), &_td_Object_Boxed__BooleanDesc, 11313)), 11321));
  right = i3;
  i4 = *(OOC_INT8*)((_check_pointer(i0, 11342))+8);
  switch (i4) {
  case 20:
    if (i1) goto l12;
    i1=0u;
    goto l13;
l12:
    i1=i3;
l13:
    result = i1;
    goto l20;
  case 21:
    if (i1) goto l17;
    i1=i3;
    goto l18;
l17:
    i1=1u;
l18:
    result = i1;
    goto l20;
  default:
    _failed_case(i4, 11335);
    goto l20;
  }
l20:
  i1 = result;
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_BooleanConst((OOC_IR_ConstFold__ConstFold)i2, i1, (OOC_IR__Operator)i0);
  *(OOC_INT32*)((_check_pointer(i2, 11455))+4) = i0;
l21:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitConcat(OOC_IR_ConstFold__ConstFold c, OOC_IR__Concat op) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6;
  Object__String s;
  OOC_INT32 i;

  i0 = (OOC_INT32)Object__emptyString;
  s = (Object__String)i0;
  i1 = (OOC_INT32)op;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11711))+8);
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 11719)), 0);
  i3 = (OOC_INT32)c;
  i4 = 0<i2;
  if (!i4) goto l13;
  i4=i0;i0=0;
l4_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11739))+8);
  i5 = _check_pointer(i5, 11747);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i0, i6, OOC_UINT32, 11747))*4);
  i5 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11751)))), &_td_OOC_IR__ConstDesc);
  if (i5) goto l7;
  *(OOC_INT32*)((_check_pointer(i3, 11855))+4) = 0;
  return;
  
  goto l8;
l7:
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11786))+8);
  i5 = _check_pointer(i5, 11794);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i5 = (OOC_INT32)*(OOC_INT32*)(i5+(_check_index(i0, i6, OOC_UINT32, 11794))*4);
  i5 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11801)))), &_td_OOC_IR__ConstDesc, 11801)), 11807))+8);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i5, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i5, 11820)))), &_td_Object_Boxed__StringDesc, 11820)), 11827));
  i4 = (OOC_INT32)Object__Concat2((void*)i4,(void*)i5);
  s = (Object__String)i4;
  
l8:
  i0 = i0+1;
  i = i0;
  i5 = i0<i2;
  if (i5) goto l4_loop;
l12:
  i0=i4;
l13:
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 11924));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 11944));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11952))+4);
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 11924));
  i0 = (OOC_INT32)Object_Boxed__NewString((Object__String)i0);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11932)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i1, (Object_Boxed__Object)i0);
  *(OOC_INT32*)((_check_pointer(i3, 11912))+4) = i0;
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCompare(OOC_IR_ConstFold__ConstFold c, OOC_IR__Compare op) {
  register OOC_INT32 i0,i1,i2;
  Object_Boxed__Object l;
  Object_Boxed__Object r;
  Object_Boxed__Boolean result;
  auto Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_StringOp(void);
  auto Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_IntegerOp(void);
  auto Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_RealOp(void);
  auto Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_CharOp(void);
  auto Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_BooleanOp(void);
    
    Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_StringOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      Object_Boxed__String left;
      Object_Boxed__String right;
      OOC_CHAR8 result;

      i0 = (OOC_INT32)l;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12270)))), &_td_Object_Boxed__StringDesc, 12270);
      left = (Object_Boxed__String)i0;
      i1 = (OOC_INT32)r;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12300)))), &_td_Object_Boxed__StringDesc, 12300);
      right = (Object_Boxed__String)i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 12320))+8);
      switch (i3) {
      case 10:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12369)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0==0);
        goto l9;
      case 11:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12423)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0!=0);
        goto l9;
      case 12:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12477)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0<0);
        goto l9;
      case 13:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12531)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0<=0);
        goto l9;
      case 14:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12586)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0>0);
        goto l9;
      case 15:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12640)))), Object_Boxed__StringDesc_Cmp)),Object_Boxed__StringDesc_Cmp)((Object_Boxed__String)i0, (Object__Object)i1);
        result = (i0>=0);
        goto l9;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12674));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 12706));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 12674));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12682)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        return (Object_Boxed__Boolean)0;
        goto l9;
      }
l9:
      i0 = result;
      i0 = (OOC_INT32)Object_Boxed__NewBoolean(i0);
      return (Object_Boxed__Boolean)i0;
      ;
    }

    
    Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_IntegerOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      Object_BigInt__BigInt left;
      Object_BigInt__BigInt right;
      OOC_CHAR8 result;

      i0 = (OOC_INT32)l;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 12916)))), &_td_Object_BigInt__BigIntDesc, 12916);
      left = (Object_BigInt__BigInt)i0;
      i1 = (OOC_INT32)r;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 12948)))), &_td_Object_BigInt__BigIntDesc, 12948);
      right = (Object_BigInt__BigInt)i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 12973))+8);
      switch (i3) {
      case 10:
        i0 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i0, (Object__Object)i1);
        result = (i0==0);
        goto l9;
      case 11:
        i0 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i0, (Object__Object)i1);
        result = (i0!=0);
        goto l9;
      case 12:
        i0 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i0, (Object__Object)i1);
        result = (i0<0);
        goto l9;
      case 13:
        i0 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i0, (Object__Object)i1);
        result = (i0<=0);
        goto l9;
      case 14:
        i0 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i0, (Object__Object)i1);
        result = (i0>0);
        goto l9;
      case 15:
        i0 = Object_BigInt__BigIntDesc_Cmp((Object_BigInt__BigInt)i0, (Object__Object)i1);
        result = (i0>=0);
        goto l9;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13327));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 13359));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13327));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13335)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        return (Object_Boxed__Boolean)0;
        goto l9;
      }
l9:
      i0 = result;
      i0 = (OOC_INT32)Object_Boxed__NewBoolean(i0);
      return (Object_Boxed__Boolean)i0;
      ;
    }

    
    Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_RealOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      Object_Boxed__LongReal left;
      Object_Boxed__LongReal right;
      OOC_CHAR8 result;

      i0 = (OOC_INT32)l;
      i0 = _type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13567)))), &_td_Object_Boxed__LongRealDesc, 13567);
      left = (Object_Boxed__LongReal)i0;
      i1 = (OOC_INT32)r;
      i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13600)))), &_td_Object_Boxed__LongRealDesc, 13600);
      right = (Object_Boxed__LongReal)i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 13627))+8);
      switch (i3) {
      case 10:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13676)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0==0);
        goto l9;
      case 11:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13730)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0!=0);
        goto l9;
      case 12:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13784)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0<0);
        goto l9;
      case 13:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13838)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0<=0);
        goto l9;
      case 14:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13893)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0>0);
        goto l9;
      case 15:
        i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 13947)))), Object_Boxed__LongRealDesc_Cmp)),Object_Boxed__LongRealDesc_Cmp)((Object_Boxed__LongReal)i0, (Object__Object)i1);
        result = (i0>=0);
        goto l9;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13981));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14013));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 13981));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 13989)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        return (Object_Boxed__Boolean)0;
        goto l9;
      }
l9:
      i0 = result;
      i0 = (OOC_INT32)Object_Boxed__NewBoolean(i0);
      return (Object_Boxed__Boolean)i0;
      ;
    }

    
    Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_CharOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_CHAR32 left;
      OOC_CHAR32 right;
      OOC_CHAR8 result;

      i0 = (OOC_INT32)l;
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14212)))), &_td_Object_Boxed__StringDesc, 14212)), 14219));
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14212)))), &_td_Object_Boxed__StringDesc, 14212)), 14219));
      i0 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14225)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i0, 0);
      left = i0;
      i1 = (OOC_INT32)r;
      i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14258)))), &_td_Object_Boxed__StringDesc, 14258)), 14265));
      i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14258)))), &_td_Object_Boxed__StringDesc, 14258)), 14265));
      i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 14271)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, 0);
      right = i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 14299))+8);
      switch (i3) {
      case 10:
        result = (i0==i1);
        goto l9;
      case 11:
        result = (i0!=i1);
        goto l9;
      case 12:
        result = ((OOC_UINT32)i0<(OOC_UINT32)i1);
        goto l9;
      case 13:
        result = ((OOC_UINT32)i0<=(OOC_UINT32)i1);
        goto l9;
      case 14:
        result = ((OOC_UINT32)i0>(OOC_UINT32)i1);
        goto l9;
      case 15:
        result = ((OOC_UINT32)i0>=(OOC_UINT32)i1);
        goto l9;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14611));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 14643));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 14611));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14619)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        return (Object_Boxed__Boolean)0;
        goto l9;
      }
l9:
      i0 = result;
      i0 = (OOC_INT32)Object_Boxed__NewBoolean(i0);
      return (Object_Boxed__Boolean)i0;
      ;
    }

    
    Object_Boxed__Boolean OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_BooleanOp(void) {
      register OOC_INT32 i0,i1,i2,i3;
      OOC_CHAR8 left;
      OOC_CHAR8 right;
      OOC_CHAR8 result;

      i0 = (OOC_INT32)l;
      i0 = *(OOC_UINT8*)(_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 14844)))), &_td_Object_Boxed__BooleanDesc, 14844)), 14852));
      left = i0;
      i1 = (OOC_INT32)r;
      i1 = *(OOC_UINT8*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 14881)))), &_td_Object_Boxed__BooleanDesc, 14881)), 14889));
      right = i1;
      i2 = (OOC_INT32)op;
      i3 = *(OOC_INT8*)((_check_pointer(i2, 14909))+8);
      switch (i3) {
      case 10:
        result = (i0==i1);
        goto l5;
      case 11:
        result = (i0!=i1);
        goto l5;
      default:
        i0 = (OOC_INT32)c;
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15031));
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 15063));
        i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 15031));
        OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 15039)))), OOC_IR__BuilderDesc_ErrSym)),OOC_IR__BuilderDesc_ErrSym)((OOC_IR__Builder)i0, 6, (OOC_Scanner_SymList__Symbol)i2);
        return (Object_Boxed__Boolean)0;
        goto l5;
      }
l5:
      i0 = result;
      i0 = (OOC_INT32)Object_Boxed__NewBoolean(i0);
      return (Object_Boxed__Boolean)i0;
      ;
    }


  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15175))+12);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&l);
  if (i1) goto l3;
  i1=0u;
  goto l5;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15201))+16);
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&r);
  
l5:
  if (i1) goto l7;
  *(OOC_INT32*)((_check_pointer(i2, 15859))+4) = (OOC_INT32)0;
  goto l20;
l7:
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15230))+12);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 15235))+4);
  i0 = *(OOC_INT16*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 15245)))), &_td_OOC_SymbolTable__PredefTypeDesc, 15245)), 15256))+40);
  switch (i0) {
  case 4:
  case 5:
  case 6:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_IntegerOp();
    result = (Object_Boxed__Boolean)i0;
    goto l15;
  case 8:
  case 9:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_RealOp();
    result = (Object_Boxed__Boolean)i0;
    goto l15;
  case 1:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_CharOp();
    result = (Object_Boxed__Boolean)i0;
    goto l15;
  case 13:
  case 14:
  case 15:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_StringOp();
    result = (Object_Boxed__Boolean)i0;
    goto l15;
  case 0:
    i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_VisitCompare_BooleanOp();
    result = (Object_Boxed__Boolean)i0;
    goto l15;
  default:
    _failed_case(i0, 15223);
    goto l15;
  }
l15:
  i0 = (OOC_INT32)result;
  i1 = i0==(OOC_INT32)0;
  if (i1) goto l18;
  i1 = (OOC_INT32)c;
  i0 = *(OOC_UINT8*)(_check_pointer(i0, 15819));
  i2 = (OOC_INT32)op;
  i0 = (OOC_INT32)OOC_IR_ConstFold__ConstFoldDesc_BooleanConst((OOC_IR_ConstFold__ConstFold)i1, i0, (OOC_IR__Operator)i2);
  *(OOC_INT32*)((_check_pointer(i1, 15787))+4) = i0;
  goto l20;
l18:
  i0 = (OOC_INT32)c;
  *(OOC_INT32*)((_check_pointer(i0, 15752))+4) = (OOC_INT32)0;
l20:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitTypeCast(OOC_IR_ConstFold__ConstFold c, OOC_IR__TypeCast op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitTypeConv(OOC_IR_ConstFold__ConstFold c, OOC_IR__TypeConv op) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  Object_Boxed__Object value;
  Object_Boxed__String str;

  i0 = (OOC_INT32)op;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16533))+8);
  i2 = (OOC_INT32)c;
  i1 = OOC_IR_ConstFold__ConstFoldDesc_ValidEval((OOC_IR_ConstFold__ConstFold)i2, (OOC_IR__Expression)i1, (void*)(OOC_INT32)&value);
  if (i1) goto l3;
  *(OOC_INT32*)((_check_pointer(i2, 18472))+4) = 0;
  goto l53;
l3:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16581))+4);
  i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
  if (i1) goto l6;
  i1=0u;
  goto l8;
l6:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16617))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16623))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  
l8:
  if (i1) goto l51;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16885))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  if (i1) goto l12;
  i1=0u;
  goto l14;
l12:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16927))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 16933))+4);
  i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
  
l14:
  if (i1) goto l43;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17590))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17595))+4);
  i1 = OOC_SymbolTable_TypeRules__IsIntegerType((OOC_SymbolTable__Type)i1);
  if (i1) goto l18;
  i1=0u;
  goto l20;
l18:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17620))+4);
  i1 = OOC_SymbolTable_TypeRules__IsRealType((OOC_SymbolTable__Type)i1);
  
l20:
  if (i1) goto l41;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17848))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  if (i1) goto l24;
  i1=0u;
  goto l26;
l24:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17873))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 17878))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  
l26:
  if (i1) goto l53;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17995))+4);
  i1 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i1);
  if (i1) goto l30;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18403));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18431))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 18423));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18403));
  i5 = (OOC_INT32)value;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18411)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i5);
  *(OOC_INT32*)((_check_pointer(i2, 18391))+4) = i0;
  goto l53;
l30:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18141))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18147))+4);
  i1 = OOC_SymbolTable_TypeRules__IsStringConst((OOC_SymbolTable__Type)i1);
  if (i1) goto l37;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18177))+8);
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18184)))), &_td_OOC_IR__ConstDesc);
  if (i1) goto l35;
  i1=0u;
  goto l38;
l35:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18216))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 18222))+4);
  i1 = OOC_SymbolTable_TypeRules__IsCharType((OOC_SymbolTable__Type)i1);
  
  goto l38;
l37:
  i1=1u;
l38:
  _assert(i1, 127, 18113);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18249))+8);
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18259)))), &_td_OOC_IR__ConstDesc, 18259)), 18265))+8);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 18279)))), &_td_Object_Boxed__StringDesc, 18279);
  str = (Object_Boxed__String)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18310));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18333))+8);
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 18348))+4);
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i4, 18339));
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 18310));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 18319)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i4, (OOC_SymbolTable__Type)i0, (Object_Boxed__Object)i1);
  *(OOC_INT32*)((_check_pointer(i2, 18297))+4) = i0;
  goto l53;
l41:
  i1 = (OOC_INT32)value;
  i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17726)))), &_td_Object_BigInt__BigIntDesc, 17726)));
  i1 = (OOC_INT32)Object_Boxed__NewLongReal(((OOC_REAL64)i1));
  value = (Object_Boxed__Object)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 17769));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17797))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17789));
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 17769));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 17777)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i4, (Object_Boxed__Object)i1);
  *(OOC_INT32*)((_check_pointer(i2, 17757))+4) = i0;
  goto l53;
l43:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17059))+4);
  i1 = *(OOC_INT16*)((_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17070)))), &_td_OOC_SymbolTable__PredefTypeDesc, 17070)), 17081))+40);
  switch (i1) {
  case 1:
    i1 = (OOC_INT32)value;
    i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17186)))), &_td_Object_BigInt__BigIntDesc, 17186)));
    i1 = (OOC_INT32)Object__NewLatin1Char(i1);
    i1 = (OOC_INT32)Object_Boxed__NewString((Object__String)i1);
    value = (Object_Boxed__Object)i1;
    goto l49;
  case 2:
    i1 = (OOC_INT32)value;
    i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17315)))), &_td_Object_BigInt__BigIntDesc, 17315)));
    i1 = (OOC_INT32)Object__NewUTF16Char(i1);
    i1 = (OOC_INT32)Object_Boxed__NewString((Object__String)i1);
    value = (Object_Boxed__Object)i1;
    goto l49;
  case 3:
    i1 = (OOC_INT32)value;
    i1 = Object_BigInt__BigIntDesc_ToLongInt((Object_BigInt__BigInt)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17443)))), &_td_Object_BigInt__BigIntDesc, 17443)));
    i1 = (OOC_INT32)Object__NewUCS4Char(i1);
    i1 = (OOC_INT32)Object_Boxed__NewString((Object__String)i1);
    value = (Object_Boxed__Object)i1;
    goto l49;
  default:
    _failed_case(i1, 17052);
    goto l49;
  }
l49:
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 17502));
  i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 17534))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 17525));
  i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 17502));
  i5 = (OOC_INT32)value;
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 17511)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i4, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i3, (Object_Boxed__Object)i5);
  *(OOC_INT32*)((_check_pointer(i2, 17490))+4) = i0;
  goto l53;
l51:
  i1 = (OOC_INT32)value;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16751)))), &_td_Object_Boxed__StringDesc, 16751)), 16758));
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 16751)))), &_td_Object_Boxed__StringDesc, 16751)), 16758));
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 16764)))), Object__StringDesc_CharAt)),Object__StringDesc_CharAt)((Object__String)i1, 0);
  i1 = (OOC_INT32)Object_BigInt__NewInt(i1);
  value = (Object_Boxed__Object)i1;
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 16799));
  i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 16831))+4);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 16822));
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 16799));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 16808)))), OOC_IR__BuilderDesc_NewConst)),OOC_IR__BuilderDesc_NewConst)((OOC_IR__Builder)i5, (OOC_Scanner_SymList__Symbol)i0, (OOC_SymbolTable__Type)i4, (Object_Boxed__Object)i1);
  *(OOC_INT32*)((_check_pointer(i2, 16787))+4) = i0;
l53:
  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitTypeGuard(OOC_IR_ConstFold__ConstFold c, OOC_IR__TypeGuard op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitTypeTag(OOC_IR_ConstFold__ConstFold c, OOC_IR__TypeTag op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitTypeTest(OOC_IR_ConstFold__ConstFold c, OOC_IR__TypeTest op) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCall(OOC_IR_ConstFold__ConstFold c, OOC_IR__Call call) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitAssert(OOC_IR_ConstFold__ConstFold c, OOC_IR__Assert assert) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitReturn(OOC_IR_ConstFold__ConstFold c, OOC_IR__Return _return) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitAssignment(OOC_IR_ConstFold__ConstFold c, OOC_IR__Assignment assignment) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitAssignOp(OOC_IR_ConstFold__ConstFold c, OOC_IR__AssignOp assignOp) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitExit(OOC_IR_ConstFold__ConstFold c, OOC_IR__Exit exit) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitForStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__ForStatm forStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitIfStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__IfStatm ifStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCase(OOC_IR_ConstFold__ConstFold c, OOC_IR__Case _case) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCaseStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__CaseStatm caseStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitLoopStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__LoopStatm loopStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitMoveBlock(OOC_IR_ConstFold__ConstFold c, OOC_IR__MoveBlock move) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitRaise(OOC_IR_ConstFold__ConstFold c, OOC_IR__Raise raise) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitRepeatStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__RepeatStatm repeatStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCatchClause(OOC_IR_ConstFold__ConstFold c, OOC_IR__CatchClause _catch) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitTryStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__TryStatm tryStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitWhileStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__WhileStatm whileStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitWithStatm(OOC_IR_ConstFold__ConstFold c, OOC_IR__WithStatm withStatm) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCopy(OOC_IR_ConstFold__ConstFold c, OOC_IR__Copy cp) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCopyParameter(OOC_IR_ConstFold__ConstFold c, OOC_IR__CopyParameter cp) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitCopyString(OOC_IR_ConstFold__ConstFold c, OOC_IR__CopyString cp) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitProcedure(OOC_IR_ConstFold__ConstFold c, OOC_IR__Procedure procedure) {

  return;
  ;
}

void OOC_IR_ConstFold__ConstFoldDesc_VisitModule(OOC_IR_ConstFold__ConstFold c, OOC_IR__Module module) {

  return;
  ;
}

void OOC_OOC_IR_ConstFold_init(void) {

  return;
  ;
}

/* --- */
