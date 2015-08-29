#include <OOC/SSA/ConstProp.d>
#include <__oo2c.h>
#include <setjmp.h>

static OOC_SSA__Const OOC_SSA_ConstProp__ComputeConst(OOC_SSA__ProcBlock pb, OOC_SSA__Instr instr) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SSA__Const arg1;
  OOC_SSA__Const arg2;
  Object_Boxed__Object v;
  Object_BigInt__BigInt _i1;
  Object_BigInt__BigInt _i2;

  i0 = (OOC_INT32)instr;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 1492))+36);
  i1 = i1==42;
  if (i1) goto l57;
  i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 1799)))), OOC_SSA__InstrDesc_SizeOpndList)),OOC_SSA__InstrDesc_SizeOpndList)((OOC_SSA__Instr)i0);
  i1 = i1>=2;
  if (i1) goto l5;
  i1=0u;
  goto l7;
l5:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 1837))+36);
  i1 = i1!=80;
  
l7:
  if (i1) goto l9;
  i1=0u;
  goto l11;
l9:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 1884))+36);
  i1 = i1!=39;
  
l11:
  if (i1) goto l13;
  i1=0u;
  goto l15;
l13:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 1925))+36);
  i1 = i1!=40;
  
l15:
  if (i1) goto l17;
  i1=0u;
  goto l19;
l17:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 1968))+36);
  i1 = i1!=52;
  
l19:
  if (i1) goto l21;
  i1=0u;
  goto l23;
l21:
  i1 = *(OOC_INT8*)((_check_pointer(i0, 2006))+36);
  i1 = i1!=53;
  
l23:
  if (!i1) goto l65;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2120))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 2130));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2135))+16);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2146)))), &_td_OOC_SSA__ConstDesc, 2146);
  arg1 = (OOC_SSA__Const)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 2173))+24);
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 2183))+8);
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i2, 2193));
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 2198))+16);
  i2 = _type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2209)))), &_td_OOC_SSA__ConstDesc, 2209);
  arg2 = (OOC_SSA__Const)i2;
  v = (Object_Boxed__Object)0;
  i3 = *(OOC_INT8*)((_check_pointer(i1, 2255))+5);
  switch (i3) {
  case 1 ... 9:
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2331))+44);
    i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 2338)))), &_td_Object_BigInt__BigIntDesc);
    if (i3) goto l29;
    i3=0u;
    goto l31;
l29:
    i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2363))+44);
    i3 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 2370)))), &_td_Object_BigInt__BigIntDesc);
    
l31:
    if (i3) goto l33;
    i1=0;
    goto l48;
l33:
    i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 2489))+44);
    i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2504)))), &_td_Object_BigInt__BigIntDesc, 2504);
    _i1 = (Object_BigInt__BigInt)i1;
    i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 2533))+44);
    i2 = _type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 2548)))), &_td_Object_BigInt__BigIntDesc, 2548);
    _i2 = (Object_BigInt__BigInt)i2;
    i3 = *(OOC_INT8*)((_check_pointer(i0, 2588))+36);
    switch (i3) {
    case 19:
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2636)))), Object_BigInt__BigIntDesc_Add)),Object_BigInt__BigIntDesc_Add)((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i2);
      v = (Object_Boxed__Object)i1;
      
      goto l48;
    case 20:
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2682)))), Object_BigInt__BigIntDesc_Sub)),Object_BigInt__BigIntDesc_Sub)((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i2);
      v = (Object_Boxed__Object)i1;
      
      goto l48;
    case 22:
      i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2728)))), Object_BigInt__BigIntDesc_Mul)),Object_BigInt__BigIntDesc_Mul)((Object_BigInt__BigInt)i1, (Object_BigInt__BigInt)i2);
      v = (Object_Boxed__Object)i1;
      
      goto l48;
    case 25:
      i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2799)))), Object_BigInt__BigIntDesc_Cmp)),Object_BigInt__BigIntDesc_Cmp)((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1==0));
      v = (Object_Boxed__Object)i1;
      
      goto l48;
    case 26:
      i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2863)))), Object_BigInt__BigIntDesc_Cmp)),Object_BigInt__BigIntDesc_Cmp)((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1!=0));
      v = (Object_Boxed__Object)i1;
      
      goto l48;
    case 28:
      i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2927)))), Object_BigInt__BigIntDesc_Cmp)),Object_BigInt__BigIntDesc_Cmp)((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1<=0));
      v = (Object_Boxed__Object)i1;
      
      goto l48;
    case 27:
      i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2991)))), Object_BigInt__BigIntDesc_Cmp)),Object_BigInt__BigIntDesc_Cmp)((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1<0));
      v = (Object_Boxed__Object)i1;
      
      goto l48;
    case 30:
      i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3055)))), Object_BigInt__BigIntDesc_Cmp)),Object_BigInt__BigIntDesc_Cmp)((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1>=0));
      v = (Object_Boxed__Object)i1;
      
      goto l48;
    case 29:
      i1 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3119)))), Object_BigInt__BigIntDesc_Cmp)),Object_BigInt__BigIntDesc_Cmp)((Object_BigInt__BigInt)i1, (Object__Object)i2);
      i1 = (OOC_INT32)Object_Boxed__NewBoolean((i1>0));
      v = (Object_Boxed__Object)i1;
      
      goto l48;
    default:
      i1=0;
      goto l48;
    }
    /* goto: unreachable */
  default:
    i1=0;
    goto l48;
  }
l48:
  i2 = i1!=0;
  if (!i2) goto l65;
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3748)))), &_td_Object_Boxed__BooleanDesc);
  if (i2) goto l53;
  i2 = (OOC_INT32)pb;
  i0 = *(OOC_INT8*)((_check_pointer(i0, 3882))+5);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 3863)))), OOC_SSA__ProcBlockDesc_GetConst)),OOC_SSA__ProcBlockDesc_GetConst)((OOC_SSA__ProcBlock)i2, (Object_Boxed__Object)i1, i0, (OOC_SymbolTable__Type)0);
  return (OOC_SSA__Const)i0;
  goto l65;
l53:
  i0 = (OOC_INT32)pb;
  i1 = *(OOC_UINT8*)(_check_pointer((_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 3813)))), &_td_Object_Boxed__BooleanDesc, 3813)), 3821));
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 3790)))), OOC_SSA__ProcBlockDesc_GetConstBool)),OOC_SSA__ProcBlockDesc_GetConstBool)((OOC_SSA__ProcBlock)i0, i1);
  return (OOC_SSA__Const)i0;
  goto l65;
l57:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 1544))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 1554));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1559))+16);
  i1 = _type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 1570)))), &_td_OOC_SSA__ConstDesc, 1570);
  arg1 = (OOC_SSA__Const)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1592))+44);
  i2 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 1599)))), &_td_Object_BigInt__BigIntDesc);
  if (i2) goto l60;
  i2=0u;
  goto l62;
l60:
  i2 = *(OOC_INT8*)((_check_pointer(i0, 1634))+5);
  i2 = i2<10;
  
l62:
  if (!i2) goto l65;
  i2 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 1742))+44);
  i0 = *(OOC_INT8*)((_check_pointer(i0, 1755))+5);
  i0 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 1727)))), OOC_SSA__ProcBlockDesc_GetConst)),OOC_SSA__ProcBlockDesc_GetConst)((OOC_SSA__ProcBlock)i2, (Object_Boxed__Object)i1, i0, (OOC_SymbolTable__Type)0);
  return (OOC_SSA__Const)i0;
l65:
  return (OOC_SSA__Const)0;
  ;
}

void OOC_SSA_ConstProp__Transform(OOC_SSA__ProcBlock pb) {
  register OOC_INT32 i0,i1,i2,i3;
  OOC_SSA__Instr instr;
  OOC_SSA_ConstProp__Worklist worklist;
  auto void OOC_SSA_ConstProp__Transform_AddToWorklist(OOC_SSA__Instr instr);
  auto void OOC_SSA_ConstProp__Transform_SetInfo(OOC_SSA__Instr instr, OOC_SSA__Result info);
  auto void OOC_SSA_ConstProp__Transform_AddUsesToWorklist(OOC_SSA__Result res);
  auto void OOC_SSA_ConstProp__Transform_UpdateInfo(OOC_SSA__Instr instr, OOC_SSA__Result info);
  auto void OOC_SSA_ConstProp__Transform_ClassifyInstr(OOC_SSA__Instr instr);
    
    void OOC_SSA_ConstProp__Transform_AddToWorklist(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA_ConstProp__Worklist wl;

      i0 = (OOC_INT32)instr;
      i1 = *(OOC_INT32*)((_check_pointer(i0, 4223))+20);
      i1 = i1==0;
      if (!i1) goto l4;
      *(OOC_INT32*)((_check_pointer(i0, 4255))+20) = 1;
      i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_ConstProp__Worklist.baseTypes[0]);
      wl = (OOC_SSA_ConstProp__Worklist)i1;
      i2 = (OOC_INT32)worklist;
      *(OOC_INT32*)(_check_pointer(i1, 4307)) = i2;
      *(OOC_INT32*)((_check_pointer(i1, 4337))+4) = i0;
      worklist = (OOC_SSA_ConstProp__Worklist)i1;
l4:
      return;
      ;
    }

    
    void OOC_SSA_ConstProp__Transform_SetInfo(OOC_SSA__Instr instr, OOC_SSA__Result info) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Result res;

      i0 = (OOC_INT32)instr;
      res = (OOC_SSA__Result)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l8;
      i1 = (OOC_INT32)info;
      
l3_loop:
      *(OOC_INT32*)((_check_pointer(i0, 4571))+16) = i1;
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4605));
      res = (OOC_SSA__Result)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l3_loop;
l8:
      return;
      ;
    }

    
    void OOC_SSA_ConstProp__Transform_AddUsesToWorklist(OOC_SSA__Result res) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Opnd use;
      OOC_SSA__Instr useInstr;

      i0 = (OOC_INT32)res;
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4779))+12);
      use = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l11;
l3_loop:
      i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4840))+12);
      useInstr = (OOC_SSA__Instr)i1;
      i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 4869))+16);
      i2 = i2==(OOC_INT32)0;
      if (!i2) goto l6;
      OOC_SSA_ConstProp__Transform_AddToWorklist((OOC_SSA__Instr)i1);
l6:
      i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 4964))+16);
      use = (OOC_SSA__Opnd)i0;
      i1 = i0!=(OOC_INT32)0;
      if (i1) goto l3_loop;
l11:
      return;
      ;
    }

    
    void OOC_SSA_ConstProp__Transform_UpdateInfo(OOC_SSA__Instr instr, OOC_SSA__Result info) {
      register OOC_INT32 i0,i1,i2;
      OOC_SSA__Result res;

      i0 = (OOC_INT32)instr;
      res = (OOC_SSA__Result)i0;
      i1 = i0!=(OOC_INT32)0;
      if (!i1) goto l8;
      i1 = (OOC_INT32)info;
      
l3_loop:
      *(OOC_INT32*)((_check_pointer(i0, 5176))+16) = i1;
      OOC_SSA_ConstProp__Transform_AddUsesToWorklist((OOC_SSA__Result)i0);
      i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5243));
      res = (OOC_SSA__Result)i0;
      i2 = i0!=(OOC_INT32)0;
      if (i2) goto l3_loop;
l8:
      return;
      ;
    }

    
    void OOC_SSA_ConstProp__Transform_ClassifyInstr(OOC_SSA__Instr instr) {
      register OOC_INT32 i0,i1,i2,i3,i4;
      OOC_SSA__Opnd opnd;
      OOC_SSA__Result state;
      OOC_SSA__Result _const;
      auto OOC_SSA__Opnd OOC_SSA_ConstProp__Transform_ClassifyInstr_MatchingPath(OOC_SSA__Const expr, OOC_CHAR8 isSwitch, OOC_SSA__Opnd branch);
      auto void OOC_SSA_ConstProp__Transform_ClassifyInstr_ReplaceSelect(OOC_SSA__Instr select, OOC_SSA__Opnd branch);
        
        OOC_SSA__Opnd OOC_SSA_ConstProp__Transform_ClassifyInstr_MatchingPath(OOC_SSA__Const expr, OOC_CHAR8 isSwitch, OOC_SSA__Opnd branch) {
          register OOC_INT32 i0,i1,i2,i3,i4;
          auto OOC_CHAR8 OOC_SSA_ConstProp__Transform_ClassifyInstr_MatchingPath_InLabelList(Object_Boxed__Object expr, OOC_SSA__Opnd opnd);
            
            OOC_CHAR8 OOC_SSA_ConstProp__Transform_ClassifyInstr_MatchingPath_InLabelList(Object_Boxed__Object expr, OOC_SSA__Opnd opnd) {
              register OOC_INT32 i0,i1,i2,i3;
              Object_Boxed__Object lower;
              Object_Boxed__Object upper;

              i0 = (OOC_INT32)opnd;
              i1 = i0!=(OOC_INT32)0;
              if (!i1) goto l15;
              i1 = (OOC_INT32)expr;
              
l3_loop:
              i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5869));
              i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5879)))), &_td_OOC_SSA__ConstDesc, 5879)), 5885))+44);
              lower = (Object_Boxed__Object)i2;
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 5919))+8);
              i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i3, 5929));
              i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 5939)))), &_td_OOC_SSA__ConstDesc, 5939)), 5945))+44);
              upper = (Object_Boxed__Object)i3;
              i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5975)))), Object_Boxed__ObjectDesc_Cmp)),Object_Boxed__ObjectDesc_Cmp)((Object_Boxed__Object)i2, (Object__Object)i1);
              i2 = i2<=0;
              if (i2) goto l6;
              i2=0u;
              goto l8;
l6:
              i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6001)))), Object_Boxed__ObjectDesc_Cmp)),Object_Boxed__ObjectDesc_Cmp)((Object_Boxed__Object)i1, (Object__Object)i3);
              i2 = i2<=0;
              
l8:
              if (!i2) goto l10;
              return 1u;
l10:
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6094))+8);
              i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6104))+8);
              opnd = (OOC_SSA__Opnd)i0;
              i2 = i0!=(OOC_INT32)0;
              if (i2) goto l3_loop;
l15:
              return 0u;
              ;
            }


          i0 = isSwitch;
          if (i0) goto l22;
          i0 = (OOC_INT32)branch;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l5;
          i1=0u;
          goto l7;
l5:
          i1 = *(OOC_INT8*)((_check_pointer(i0, 6666))+4);
          i1 = i1==1;
          
l7:
          if (!i1) goto l21;
          i1 = (OOC_INT32)expr;
          
l9_loop:
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6708))+44);
          i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6731));
          i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6708))+44);
          i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i3, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i3, 6741)))), &_td_OOC_SSA__ConstDesc, 6741)), 6747))+44);
          i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 6715)))), Object__ObjectDesc_Equals)),Object__ObjectDesc_Equals)((Object__Object)i4, (Object__Object)i3);
          if (!i2) goto l12;
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6788))+8);
          return (OOC_SSA__Opnd)i2;
l12:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6845))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6855))+8);
          branch = (OOC_SSA__Opnd)i0;
          i2 = i0!=(OOC_INT32)0;
          if (i2) goto l15;
          i2=0u;
          goto l17;
l15:
          i2 = *(OOC_INT8*)((_check_pointer(i0, 6666))+4);
          i2 = i2==1;
          
l17:
          if (i2) goto l9_loop;
l21:
          _assert(0u, 127, 6892);
          goto l51;
l22:
          i0 = (OOC_INT32)branch;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l25;
          i1=0u;
          goto l27;
l25:
          i1 = *(OOC_INT8*)((_check_pointer(i0, 6280))+4);
          i1 = i1==16;
          
l27:
          if (i1) goto l29;
          i1=0u;
          goto l31;
l29:
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6328));
          i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6333)))), &_td_OOC_SSA__ConstDesc));
          
l31:
          if (!i1) goto l50;
l34_loop:
          i1 = (OOC_INT32)expr;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6397));
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 6382))+44);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer((_type_guard(i0, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 6407)))), &_td_OOC_SSA__InstrDesc, 6407)), 6413))+24);
          i0 = OOC_SSA_ConstProp__Transform_ClassifyInstr_MatchingPath_InLabelList((Object_Boxed__Object)i1, (OOC_SSA__Opnd)i0);
          if (!i0) goto l37;
          i0 = (OOC_INT32)branch;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6457))+8);
          return (OOC_SSA__Opnd)i0;
l37:
          i0 = (OOC_INT32)branch;
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6514))+8);
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6524))+8);
          branch = (OOC_SSA__Opnd)i0;
          i1 = i0!=(OOC_INT32)0;
          if (i1) goto l40;
          i1=0u;
          goto l42;
l40:
          i1 = *(OOC_INT8*)((_check_pointer(i0, 6280))+4);
          i1 = i1==16;
          
l42:
          if (i1) goto l44;
          i1=0u;
          goto l46;
l44:
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6328));
          i1 = !(OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 6333)))), &_td_OOC_SSA__ConstDesc));
          
l46:
          if (i1) goto l34_loop;
l50:
          i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 6574))+8);
          return (OOC_SSA__Opnd)i0;
l51:
          _failed_function(5489); return 0;
          ;
        }

        
        void OOC_SSA_ConstProp__Transform_ClassifyInstr_ReplaceSelect(OOC_SSA__Instr select, OOC_SSA__Opnd branch) {
          register OOC_INT32 i0,i1,i2;
          OOC_SSA__Result res;
          OOC_SSA__Opnd opnd;

          i0 = (OOC_INT32)select;
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7105));
          res = (OOC_SSA__Result)i0;
          i1 = (OOC_INT32)branch;
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7137));
          i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 7142))+8);
          i2 = *(OOC_INT8*)((_check_pointer(i2, 7149))+36);
          i2 = i2==6;
          if (i2) goto l3;
          OOC_SSA_ConstProp__Transform_AddUsesToWorklist((OOC_SSA__Result)i0);
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7681));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7660)))), OOC_SSA__ResultDesc_ReplaceUses)),OOC_SSA__ResultDesc_ReplaceUses)((OOC_SSA__Result)i0, (OOC_SSA__Result)i1);
          goto l12;
l3:
          i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7320));
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7325))+8);
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7332))+24);
          opnd = (OOC_SSA__Opnd)i1;
          i2 = i0!=0;
          if (!i2) goto l12;
l6_loop:
          OOC_SSA_ConstProp__Transform_AddUsesToWorklist((OOC_SSA__Result)i0);
          i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7446));
          OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 7427)))), OOC_SSA__ResultDesc_ReplaceUses)),OOC_SSA__ResultDesc_ReplaceUses)((OOC_SSA__Result)i0, (OOC_SSA__Result)i2);
          i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7476));
          res = (OOC_SSA__Result)i0;
          i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 7514))+8);
          opnd = (OOC_SSA__Opnd)i1;
          i2 = i0!=0;
          if (i2) goto l6_loop;
l12:
          return;
          ;
        }


      i0 = (OOC_INT32)instr;
      i1 = *(OOC_INT8*)((_check_pointer(i0, 7758))+36);
      switch (i1) {
      case 6:
      case 5:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 7949))+24);
        opnd = (OOC_SSA__Opnd)i1;
        i2 = i1!=(OOC_INT32)0;
        if (i2) goto l5;
        i2=0u;
        goto l7;
l5:
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7995));
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8000))+16);
        i2 = i2!=(OOC_INT32)0;
        
l7:
        if (!i2) goto l19;
l10_loop:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8048))+8);
        opnd = (OOC_SSA__Opnd)i1;
        i2 = i1!=(OOC_INT32)0;
        if (i2) goto l13;
        i2=0u;
        goto l15;
l13:
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 7995));
        i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i2, 8000))+16);
        i2 = i2!=(OOC_INT32)0;
        
l15:
        if (i2) goto l10_loop;
l19:
        i1 = i1==(OOC_INT32)0;
        if (!i1) goto l57;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8172))+12);
        _assert((i1==(OOC_INT32)0), 127, 8159);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 8213));
        i1 = *(OOC_INT8*)((_check_pointer(i1, 8225))+4);
        _assert((i1==2), 127, 8200);
        i1 = *(OOC_INT8*)((_check_pointer(i0, 8269))+36);
        i1 = i1==5;
        if (i1) goto l24;
        i1=0u;
        goto l26;
l24:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8316))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 8326));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8331))+16);
        i2 = (OOC_INT32)OOC_SSA_ConstProp__notConstant;
        i1 = i1!=i2;
        
l26:
        if (i1) goto l28;
        i1 = (OOC_INT32)OOC_SSA_ConstProp__notConstant;
        OOC_SSA_ConstProp__Transform_UpdateInfo((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1);
        goto l57;
l28:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8566))+24);
        i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 8576));
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 8581))+16);
        i2 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 8645)))), OOC_SSA__InstrDesc_IsSwitchStatm)),OOC_SSA__InstrDesc_IsSwitchStatm)((OOC_SSA__Instr)i0);
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8709))+24);
        i3 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i3, 8719))+8);
        i1 = (OOC_INT32)OOC_SSA_ConstProp__Transform_ClassifyInstr_MatchingPath((OOC_SSA__Const)(_type_guard(i1, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 8592)))), &_td_OOC_SSA__ConstDesc, 8592)), i2, (OOC_SSA__Opnd)i3);
        OOC_SSA_ConstProp__Transform_ClassifyInstr_ReplaceSelect((OOC_SSA__Instr)i0, (OOC_SSA__Opnd)i1);
        goto l57;
      default:
        state = (OOC_SSA__Result)i0;
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 8964))+24);
        i2 = (OOC_INT32)OOC_SSA_ConstProp__notConstant;
        opnd = (OOC_SSA__Opnd)i1;
        i3=i0;
l32_loop:
        i4 = i1==(OOC_INT32)0;
        if (i4) goto l44;
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 9059));
        i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 9064))+16);
        i4 = i4==(OOC_INT32)0;
        if (i4) goto l41;
        i4 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 9148));
        i4 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i4, 9153))+16);
        i4 = i4==i2;
        if (i4) goto l40;
        goto l43;
l40:
        state = (OOC_SSA__Result)i2;
        i1=i2;
        goto l45;
l41:
        state = (OOC_SSA__Result)(OOC_INT32)0;
        i3=(OOC_INT32)0;
l43:
        i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 9269))+8);
        opnd = (OOC_SSA__Opnd)i1;
        
        goto l32_loop;
l44:
        i1=i3;
l45:
        i3 = i1==i0;
        if (i3) goto l51;
        i1 = i1==i2;
        if (!i1) goto l57;
        OOC_SSA_ConstProp__Transform_UpdateInfo((OOC_SSA__Instr)i0, (OOC_SSA__Result)i2);
        goto l57;
l51:
        i1 = (OOC_INT32)pb;
        i1 = (OOC_INT32)OOC_SSA_ConstProp__ComputeConst((OOC_SSA__ProcBlock)i1, (OOC_SSA__Instr)i0);
        _const = (OOC_SSA__Result)i1;
        i2 = i1==(OOC_INT32)0;
        if (i2) goto l54;
        i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 9605));
        _assert((i2==(OOC_INT32)0), 127, 9592);
        OOC_SSA_ConstProp__Transform_UpdateInfo((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1);
        goto l57;
l54:
        i1 = (OOC_INT32)OOC_SSA_ConstProp__notConstant;
        OOC_SSA_ConstProp__Transform_UpdateInfo((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1);
        goto l57;
      }
l57:
      return;
      ;
    }


  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10167))+8);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l24;
l3_loop:
  *(OOC_INT32*)((_check_pointer(i0, 10218))+20) = 0;
  i1 = OOC_TYPE_TEST(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10250)))), &_td_OOC_SSA__ConstDesc);
  if (i1) goto l6;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 10273))+36);
  i1 = i1==81;
  
  goto l8;
l6:
  i1=1u;
l8:
  if (i1) goto l18;
  i1 = *(OOC_INT8*)((_check_pointer(i0, 10394))+36);
  i1 = i1!=5;
  if (i1) goto l12;
  i1=0u;
  goto l14;
l12:
  i1 = (OOC_INT32)OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 10428)))), OOC_SSA__InstrDesc_GetArgStore)),OOC_SSA__InstrDesc_GetArgStore)((OOC_SSA__Instr)i0);
  i1 = i1!=(OOC_INT32)0;
  
l14:
  if (i1) goto l16;
  OOC_SSA_ConstProp__Transform_SetInfo((OOC_SSA__Instr)i0, (OOC_SSA__Result)(OOC_INT32)0);
  goto l19;
l16:
  i1 = (OOC_INT32)OOC_SSA_ConstProp__notConstant;
  OOC_SSA_ConstProp__Transform_SetInfo((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1);
  goto l19;
l18:
  *(OOC_INT32*)((_check_pointer(i0, 10317))+16) = i0;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10355));
  _assert((i0==(OOC_INT32)0), 127, 10342);
l19:
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10847))+28);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l3_loop;
l24:
  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10883));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10897))+24);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 10907));
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 10912))+8);
  i1 = *(OOC_INT8*)((_check_pointer(i1, 10919))+36);
  _assert((i1==4), 127, 10873);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10960));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10974))+24);
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 10984));
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 10989))+8);
  i1 = (OOC_INT32)OOC_SSA_ConstProp__notConstant;
  OOC_SSA_ConstProp__Transform_SetInfo((OOC_SSA__Instr)i0, (OOC_SSA__Result)i1);
  worklist = (OOC_SSA_ConstProp__Worklist)(OOC_INT32)0;
  i0 = (OOC_INT32)pb;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11096))+8);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (!i1) goto l39;
l27_loop:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11151))+16);
  i1 = i1==(OOC_INT32)0;
  if (i1) goto l30;
  i1=0u;
  goto l32;
l30:
  i1 = *(OOC_INT32*)((_check_pointer(i0, 11182))+20);
  i1 = i1==0;
  
l32:
  if (!i1) goto l34;
  OOC_SSA_ConstProp__Transform_ClassifyInstr((OOC_SSA__Instr)i0);
l34:
  i0 = (OOC_INT32)instr;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11409))+28);
  instr = (OOC_SSA__Instr)i0;
  i1 = i0!=(OOC_INT32)0;
  if (i1) goto l27_loop;
l39:
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (!i0) goto l47;
l42_loop:
  i0 = (OOC_INT32)worklist;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11526))+4);
  instr = (OOC_SSA__Instr)i1;
  *(OOC_INT32*)((_check_pointer(i1, 11546))+20) = 0;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 11587));
  worklist = (OOC_SSA_ConstProp__Worklist)i0;
  i0 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11614))+16);
  _assert((i0==(OOC_INT32)0), 127, 11601);
  OOC_SSA_ConstProp__Transform_ClassifyInstr((OOC_SSA__Instr)i1);
  i0 = (OOC_INT32)worklist;
  i0 = i0!=(OOC_INT32)0;
  if (i0) goto l42_loop;
l47:
  i0 = (OOC_INT32)pb;
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i0, 11762))+8);
  instr = (OOC_SSA__Instr)i1;
  i2 = i1!=(OOC_INT32)0;
  if (!i2) goto l66;
l50_loop:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11817))+16);
  i2 = i2!=(OOC_INT32)0;
  if (i2) goto l53;
  i2=0u;
  goto l55;
l53:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11857))+16);
  i3 = (OOC_INT32)OOC_SSA_ConstProp__notConstant;
  i2 = i2!=i3;
  
l55:
  if (i2) goto l57;
  i2=0u;
  goto l59;
l57:
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11896))+16);
  i2 = i2!=i1;
  
l59:
  if (!i2) goto l61;
  i2 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 11950))+16);
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 11930)))), OOC_SSA__ResultDesc_ReplaceUses)),OOC_SSA__ResultDesc_ReplaceUses)((OOC_SSA__Result)i1, (OOC_SSA__Result)(_type_guard(i2, ((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 11961)))), &_td_OOC_SSA__ResultDesc, 11961)));
l61:
  i1 = (OOC_INT32)*(OOC_INT32*)((_check_pointer(i1, 12002))+28);
  instr = (OOC_SSA__Instr)i1;
  i2 = i1!=(OOC_INT32)0;
  if (i2) goto l50_loop;
l66:
  OOC_SSA_DeadCodeElimination__Transform((OOC_SSA__ProcBlock)i0);
  return;
  ;
}

void OOC_OOC_SSA_ConstProp_init(void) {
  register OOC_INT32 i0;

  i0 = (OOC_INT32)OOC_SSA__NewResult((OOC_SSA__Instr)(OOC_INT32)0, (-1), (-1));
  OOC_SSA_ConstProp__notConstant = (OOC_SSA__Result)i0;
  return;
  ;
}

/* --- */
