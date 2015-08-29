#include <OOC/SSA/IGraph.d>
#include <__oo2c.h>
#include <setjmp.h>

void OOC_SSA_IGraph__GraphDesc_Clear(OOC_SSA_IGraph__Graph g) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_INT32 i;
  OOC_INT32 j;

  i0 = (OOC_INT32)g;
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2494));
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 2497)), 0);
  i2 = 0<i1;
  if (!i2) goto l16;
  i2=0;
l3_loop:
  i3 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2534));
  j = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i3, 2537)), 1);
  i4 = 0<i3;
  if (!i4) goto l11;
  i4=0;
l6_loop:
  i5 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 2557));
  i5 = _check_pointer(i5, 2560);
  i6 = OOC_ARRAY_LENGTH(i5, 1);
  i7 = OOC_ARRAY_LENGTH(i5, 0);
  *(OOC_UINT32*)((i5+((_check_index(i2, i7, OOC_UINT32, 2560))*(4*i6)))+(_check_index(i4, i6, OOC_UINT32, 2562))*4) = 0u;
  i4 = i4+1;
  j = i4;
  i5 = i4<i3;
  if (i5) goto l6_loop;
l11:
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l16:
  return;
  ;
}

static void OOC_SSA_IGraph__InitGraph(OOC_SSA_IGraph__Graph g, OOC_INT32 size) {
  register OOC_INT32 i0,i1;

  i0 = size;
  i1 = (OOC_INT32)g;
  *(OOC_INT32*)(_check_pointer(i1, 2678)) = ((OOC_INT32)RT0__NewObject(_td_OOC_SSA_IGraph__BitMatrix.baseTypes[0], i0, (((i0+32)-1)>>5)));
  *(OOC_INT32*)((_check_pointer(i1, 2731))+4) = i0;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i1, 2752)))), OOC_SSA_IGraph__GraphDesc_Clear)),OOC_SSA_IGraph__GraphDesc_Clear)((OOC_SSA_IGraph__Graph)i1);
  return;
  ;
}

OOC_SSA_IGraph__Graph OOC_SSA_IGraph__NewGraph(OOC_INT32 size) {
  register OOC_INT32 i0,i1;

  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_IGraph__Graph.baseTypes[0]);
  i1 = size;
  OOC_SSA_IGraph__InitGraph((OOC_SSA_IGraph__Graph)i0, i1);
  return (OOC_SSA_IGraph__Graph)i0;
  ;
}

OOC_SSA_IGraph__Vector OOC_SSA_IGraph__GraphDesc_NewVector(OOC_SSA_IGraph__Graph g) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SSA_IGraph__Vector v;
  OOC_INT32 i;

  i0 = (OOC_INT32)g;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3147));
  i0 = OOC_ARRAY_LENGTH((_check_pointer(i0, 3150)), 1);
  i0 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_IGraph__Vector.baseTypes[0], i0);
  v = (OOC_SSA_IGraph__Vector)i0;
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 3182)), 0);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = _check_pointer(i0, 3197);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_UINT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 3197))*4) = 0u;
  i2 = i2+1;
  i = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l8:
  return (OOC_SSA_IGraph__Vector)i0;
  ;
}

OOC_SSA_IGraph__Vector OOC_SSA_IGraph__GraphDesc_CopyVector(OOC_SSA_IGraph__Graph g, OOC_SSA_IGraph__Vector v) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7;
  OOC_SSA_IGraph__Vector w;
  OOC_INT32 i;

  i0 = (OOC_INT32)v;
  i1 = (OOC_INT32)g;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3443));
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i0, 3432)), 0);
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i2, 3446)), 1);
  _assert((i3==i2), 127, 3418);
  i1 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i1, 3472));
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3475)), 1);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_IGraph__Vector.baseTypes[0], i1);
  w = (OOC_SSA_IGraph__Vector)i1;
  i = 0;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i1, 3507)), 0);
  i3 = 0<i2;
  if (!i3) goto l8;
  i3=0;
l3_loop:
  i4 = _check_pointer(i1, 3522);
  i5 = OOC_ARRAY_LENGTH(i4, 0);
  i6 = _check_pointer(i0, 3530);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_UINT32*)(i6+(_check_index(i3, i7, OOC_UINT32, 3530))*4);
  *(OOC_UINT32*)(i4+(_check_index(i3, i5, OOC_UINT32, 3522))*4) = i6;
  i3 = i3+1;
  i = i3;
  i4 = i3<i2;
  if (i4) goto l3_loop;
l8:
  return (OOC_SSA_IGraph__Vector)i1;
  ;
}

void OOC_SSA_IGraph__GraphDesc_Interfere(OOC_SSA_IGraph__Graph g, OOC_INT32 res, OOC_SSA_IGraph__Vector live) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12;
  OOC_SSA_IGraph__BitMatrix m;
  OOC_INT32 i;

  i0 = (OOC_INT32)g;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 3890));
  m = (OOC_SSA_IGraph__BitMatrix)i0;
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 3919)), 1);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2 = res;
  i3 = (OOC_INT32)live;
  i4=0;
l3_loop:
  i5 = _check_pointer(i0, 3937);
  i6 = OOC_ARRAY_LENGTH(i5, 0);
  i7 = OOC_ARRAY_LENGTH(i5, 1);
  i8 = _check_pointer(i0, 3950);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i10 = OOC_ARRAY_LENGTH(i8, 1);
  i11 = _check_pointer(i3, 3963);
  i12 = OOC_ARRAY_LENGTH(i11, 0);
  i11 = *(OOC_UINT32*)(i11+(_check_index(i4, i12, OOC_UINT32, 3963))*4);
  i8 = *(OOC_UINT32*)((i8+((_check_index(i2, i9, OOC_UINT32, 3950))*(4*i10)))+(_check_index(i4, i10, OOC_UINT32, 3954))*4);
  *(OOC_UINT32*)((i5+((_check_index(i2, i6, OOC_UINT32, 3937))*(4*i7)))+(_check_index(i4, i7, OOC_UINT32, 3941))*4) = (i8|i11);
  i4 = i4+1;
  i = i4;
  i5 = i4<i1;
  if (i5) goto l3_loop;
l8:
  return;
  ;
}

void OOC_SSA_IGraph__GraphDesc_MergeRowColumn(OOC_SSA_IGraph__Graph g, OOC_INT32 source, OOC_INT32 target) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15;
  OOC_SSA_IGraph__BitMatrix m;
  OOC_INT32 i;

  i0 = (OOC_INT32)g;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 4115));
  m = (OOC_SSA_IGraph__BitMatrix)i0;
  i1 = _check_pointer(i0, 4131);
  i2 = OOC_ARRAY_LENGTH(i1, 0);
  i3 = source;
  i4 = i3>>5;
  i5 = OOC_ARRAY_LENGTH(i1, 1);
  i6 = _check_pointer(i0, 4131);
  i7 = OOC_ARRAY_LENGTH(i6, 1);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i9 = _mod(i3,32);
  i6 = *(OOC_UINT32*)((i6+((_check_index(i3, i8, OOC_UINT32, 4131))*(4*i7)))+(_check_index(i4, i7, OOC_UINT32, 4138))*4);
  *(OOC_UINT32*)((i1+((_check_index(i3, i2, OOC_UINT32, 4131))*(4*i5)))+(_check_index(i4, i5, OOC_UINT32, 4138))*4) = (_clear_bit(i6,i9));
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 4211)), 1);
  i2 = 0<i1;
  if (!i2) goto l8;
  i2 = target;
  i5=0;
l3_loop:
  i6 = _check_pointer(i0, 4229);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = OOC_ARRAY_LENGTH(i6, 1);
  i10 = _check_pointer(i0, 4245);
  i11 = OOC_ARRAY_LENGTH(i10, 0);
  i12 = OOC_ARRAY_LENGTH(i10, 1);
  i13 = _check_pointer(i0, 4258);
  i14 = OOC_ARRAY_LENGTH(i13, 1);
  i15 = OOC_ARRAY_LENGTH(i13, 0);
  i10 = *(OOC_UINT32*)((i10+((_check_index(i2, i11, OOC_UINT32, 4245))*(4*i12)))+(_check_index(i5, i12, OOC_UINT32, 4252))*4);
  i11 = *(OOC_UINT32*)((i13+((_check_index(i3, i15, OOC_UINT32, 4258))*(4*i14)))+(_check_index(i5, i14, OOC_UINT32, 4265))*4);
  *(OOC_UINT32*)((i6+((_check_index(i2, i7, OOC_UINT32, 4229))*(4*i8)))+(_check_index(i5, i8, OOC_UINT32, 4236))*4) = (i10|i11);
  i6 = _check_pointer(i0, 4278);
  i7 = OOC_ARRAY_LENGTH(i6, 1);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  *(OOC_UINT32*)((i6+((_check_index(i3, i8, OOC_UINT32, 4278))*(4*i7)))+(_check_index(i5, i7, OOC_UINT32, 4285))*4) = 0u;
  i5 = i5+1;
  i = i5;
  i6 = i5<i1;
  if (i6) goto l3_loop;
l8:
  i = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 4335)), 0);
  i2 = 0<i1;
  if (!i2) goto l19;
  i2 = target;
  i3 = _mod(i2,32);
  i2 = i2>>5;
  i5=0;
l11_loop:
  i6 = _check_pointer(i0, 4383);
  i7 = OOC_ARRAY_LENGTH(i6, 1);
  i8 = OOC_ARRAY_LENGTH(i6, 0);
  i6 = *(OOC_UINT32*)((i6+((_check_index(i5, i8, OOC_UINT32, 4383))*(4*i7)))+(_check_index(i4, i7, OOC_UINT32, 4385))*4);
  i6 = _in(i9,i6);
  if (!i6) goto l14;
  i6 = _check_pointer(i0, 4429);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = OOC_ARRAY_LENGTH(i6, 1);
  i10 = _check_pointer(i0, 4429);
  i11 = OOC_ARRAY_LENGTH(i10, 1);
  i12 = OOC_ARRAY_LENGTH(i10, 0);
  i10 = *(OOC_UINT32*)((i10+((_check_index(i5, i12, OOC_UINT32, 4429))*(4*i11)))+(_check_index(i2, i11, OOC_UINT32, 4431))*4);
  *(OOC_UINT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 4429))*(4*i8)))+(_check_index(i2, i8, OOC_UINT32, 4431))*4) = (_set_bit(i10,i3));
l14:
  i6 = _check_pointer(i0, 4504);
  i7 = OOC_ARRAY_LENGTH(i6, 0);
  i8 = OOC_ARRAY_LENGTH(i6, 1);
  i10 = _check_pointer(i0, 4504);
  i11 = OOC_ARRAY_LENGTH(i10, 1);
  i12 = OOC_ARRAY_LENGTH(i10, 0);
  i10 = *(OOC_UINT32*)((i10+((_check_index(i5, i12, OOC_UINT32, 4504))*(4*i11)))+(_check_index(i4, i11, OOC_UINT32, 4506))*4);
  *(OOC_UINT32*)((i6+((_check_index(i5, i7, OOC_UINT32, 4504))*(4*i8)))+(_check_index(i4, i8, OOC_UINT32, 4506))*4) = (_clear_bit(i10,i9));
  i5 = i5+1;
  i = i5;
  i6 = i5<i1;
  if (i6) goto l11_loop;
l19:
  return;
  ;
}

void OOC_SSA_IGraph__GraphDesc_AddToLive(OOC_SSA_IGraph__Graph g, OOC_INT32 res, OOC_SSA_IGraph__Vector live) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = (OOC_INT32)g;
  i1 = res;
  i2 = (OOC_INT32)live;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i0, 4809)))), OOC_SSA_IGraph__GraphDesc_Interfere)),OOC_SSA_IGraph__GraphDesc_Interfere)((OOC_SSA_IGraph__Graph)i0, i1, (OOC_SSA_IGraph__Vector)i2);
  i0 = _check_pointer(i2, 4848);
  i3 = i1>>5;
  i4 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = _check_pointer(i2, 4848);
  i5 = OOC_ARRAY_LENGTH(i2, 0);
  i2 = *(OOC_UINT32*)(i2+(_check_index(i3, i5, OOC_UINT32, 4848))*4);
  *(OOC_UINT32*)(i0+(_check_index(i3, i4, OOC_UINT32, 4848))*4) = (_set_bit(i2,(_mod(i1,32))));
  return;
  ;
}

void OOC_SSA_IGraph__GraphDesc_RemoveFromLive(OOC_SSA_IGraph__Graph g, OOC_INT32 res, OOC_SSA_IGraph__Vector live) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;

  i0 = (OOC_INT32)live;
  i1 = _check_pointer(i0, 5056);
  i2 = res;
  i3 = i2>>5;
  i4 = OOC_ARRAY_LENGTH(i1, 0);
  i0 = _check_pointer(i0, 5056);
  i5 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT32*)(i0+(_check_index(i3, i5, OOC_UINT32, 5056))*4);
  *(OOC_UINT32*)(i1+(_check_index(i3, i4, OOC_UINT32, 5056))*4) = (_clear_bit(i0,(_mod(i2,32))));
  return;
  ;
}

OOC_CHAR8 OOC_SSA_IGraph__GraphDesc_In(OOC_SSA_IGraph__Graph g, OOC_INT32 res, OOC_SSA_IGraph__Vector live) {
  register OOC_INT32 i0,i1,i2;

  i0 = (OOC_INT32)live;
  i0 = _check_pointer(i0, 5317);
  i1 = res;
  i2 = OOC_ARRAY_LENGTH(i0, 0);
  i0 = *(OOC_UINT32*)(i0+(_check_index((i1>>5), i2, OOC_UINT32, 5317))*4);
  return (_in((_mod(i1,32)),i0));
  ;
}

OOC_CHAR8 OOC_SSA_IGraph__GraphDesc_Conflicts(OOC_SSA_IGraph__Graph g, OOC_INT32 i, OOC_INT32 j) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SSA_IGraph__BitMatrix m;

  i0 = (OOC_INT32)g;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 5517));
  m = (OOC_SSA_IGraph__BitMatrix)i0;
  i0 = _check_pointer(i0, 5555);
  i1 = OOC_ARRAY_LENGTH(i0, 0);
  i2 = OOC_ARRAY_LENGTH(i0, 1);
  i3 = i;
  i4 = j;
  i0 = *(OOC_UINT32*)((i0+((_check_index(i3, i1, OOC_UINT32, 5555))*(4*i2)))+(_check_index((i4>>5), i2, OOC_UINT32, 5557))*4);
  return (_in((_mod(i4,32)),i0));
  ;
}

void OOC_SSA_IGraph__GraphDesc_MergeVector(OOC_SSA_IGraph__Graph g, OOC_SSA_IGraph__Vector source, OOC_SSA_IGraph__Vector dest) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5;
  OOC_INT32 i;

  i0 = (OOC_INT32)source;
  i1 = (OOC_INT32)dest;
  i2 = OOC_ARRAY_LENGTH((_check_pointer(i0, 5806)), 0);
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i1, 5820)), 0);
  _assert((i2==i3), 127, 5787);
  i2 = (OOC_INT32)g;
  i = 0;
  i3 = *(OOC_INT32*)((_check_pointer(i2, 5844))+4);
  i4 = 0<i3;
  if (!i4) goto l11;
  i4=0;
l3_loop:
  i5 = OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5866)))), OOC_SSA_IGraph__GraphDesc_In)),OOC_SSA_IGraph__GraphDesc_In)((OOC_SSA_IGraph__Graph)i2, i4, (OOC_SSA_IGraph__Vector)i0);
  if (!i5) goto l6;
  OOC_TBCALL(((OOC_INT32)OOC_TBPROC_ADR(((OOC_INT32)OOC_TYPE_TAG((_check_pointer(i2, 5897)))), OOC_SSA_IGraph__GraphDesc_AddToLive)),OOC_SSA_IGraph__GraphDesc_AddToLive)((OOC_SSA_IGraph__Graph)i2, i4, (OOC_SSA_IGraph__Vector)i1);
l6:
  i4 = i4+1;
  i = i4;
  i5 = i4<i3;
  if (i5) goto l3_loop;
l11:
  return;
  ;
}

void OOC_SSA_IGraph__GraphDesc_SymmetricMatrix(OOC_SSA_IGraph__Graph g) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14;
  OOC_SSA_IGraph__BitMatrix m;
  OOC_INT32 y;
  OOC_INT32 x;

  i0 = (OOC_INT32)g;
  i0 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 6365));
  m = (OOC_SSA_IGraph__BitMatrix)i0;
  y = 0;
  i1 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6394)), 0);
  i2 = 0<i1;
  if (!i2) goto l23;
  i2=0;
l3_loop:
  x = 0;
  i3 = OOC_ARRAY_LENGTH((_check_pointer(i0, 6428)), 0);
  i4 = _mod(i2,32);
  i5 = i2>>5;
  i6 = 0<i3;
  if (!i6) goto l18;
  i6=0;
l6_loop:
  i7 = _check_pointer(i0, 6469);
  i8 = OOC_ARRAY_LENGTH(i7, 1);
  i9 = OOC_ARRAY_LENGTH(i7, 0);
  i10 = i6>>5;
  i7 = *(OOC_UINT32*)((i7+((_check_index(i2, i9, OOC_UINT32, 6469))*(4*i8)))+(_check_index(i10, i8, OOC_UINT32, 6471))*4);
  i8 = _mod(i6,32);
  i7 = _in(i8,i7);
  if (i7) goto l12;
  i7 = _check_pointer(i0, 6591);
  i9 = OOC_ARRAY_LENGTH(i7, 1);
  i11 = OOC_ARRAY_LENGTH(i7, 0);
  i7 = *(OOC_UINT32*)((i7+((_check_index(i6, i11, OOC_UINT32, 6591))*(4*i9)))+(_check_index(i5, i9, OOC_UINT32, 6593))*4);
  i7 = _in(i4,i7);
  if (!i7) goto l13;
  i7 = _check_pointer(i0, 6683);
  i9 = OOC_ARRAY_LENGTH(i7, 0);
  i11 = OOC_ARRAY_LENGTH(i7, 1);
  i12 = _check_pointer(i0, 6683);
  i13 = OOC_ARRAY_LENGTH(i12, 1);
  i14 = OOC_ARRAY_LENGTH(i12, 0);
  i12 = *(OOC_UINT32*)((i12+((_check_index(i2, i14, OOC_UINT32, 6683))*(4*i13)))+(_check_index(i10, i13, OOC_UINT32, 6685))*4);
  *(OOC_UINT32*)((i7+((_check_index(i2, i9, OOC_UINT32, 6683))*(4*i11)))+(_check_index(i10, i11, OOC_UINT32, 6685))*4) = (_set_bit(i12,i8));
  goto l13;
l12:
  i7 = _check_pointer(i0, 6514);
  i8 = OOC_ARRAY_LENGTH(i7, 0);
  i9 = OOC_ARRAY_LENGTH(i7, 1);
  i10 = _check_pointer(i0, 6514);
  i11 = OOC_ARRAY_LENGTH(i10, 1);
  i12 = OOC_ARRAY_LENGTH(i10, 0);
  i10 = *(OOC_UINT32*)((i10+((_check_index(i6, i12, OOC_UINT32, 6514))*(4*i11)))+(_check_index(i5, i11, OOC_UINT32, 6516))*4);
  *(OOC_UINT32*)((i7+((_check_index(i6, i8, OOC_UINT32, 6514))*(4*i9)))+(_check_index(i5, i9, OOC_UINT32, 6516))*4) = (_set_bit(i10,i4));
l13:
  i6 = i6+1;
  x = i6;
  i7 = i6<i3;
  if (i7) goto l6_loop;
l18:
  i3 = _check_pointer(i0, 6787);
  i6 = OOC_ARRAY_LENGTH(i3, 0);
  i7 = OOC_ARRAY_LENGTH(i3, 1);
  i8 = _check_pointer(i0, 6787);
  i9 = OOC_ARRAY_LENGTH(i8, 1);
  i10 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = *(OOC_UINT32*)((i8+((_check_index(i2, i10, OOC_UINT32, 6787))*(4*i9)))+(_check_index(i5, i9, OOC_UINT32, 6789))*4);
  *(OOC_UINT32*)((i3+((_check_index(i2, i6, OOC_UINT32, 6787))*(4*i7)))+(_check_index(i5, i7, OOC_UINT32, 6789))*4) = (_clear_bit(i8,i4));
  i2 = i2+1;
  y = i2;
  i3 = i2<i1;
  if (i3) goto l3_loop;
l23:
  return;
  ;
}

OOC_SSA_IGraph__ColorArray OOC_SSA_IGraph__GraphDesc_ColorGraphTrivial(OOC_SSA_IGraph__Graph g) {
  register OOC_INT32 i0,i1,i2,i3,i4;
  OOC_SSA_IGraph__ColorArray ca;
  OOC_INT32 i;

  i0 = (OOC_INT32)g;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7124))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_IGraph__ColorArray.baseTypes[0], i1);
  ca = (OOC_SSA_IGraph__ColorArray)i1;
  i = 0;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 7152))+4);
  i2 = 0<i0;
  if (!i2) goto l8;
  i2=0;
l3_loop:
  i3 = _check_pointer(i1, 7172);
  i4 = OOC_ARRAY_LENGTH(i3, 0);
  *(OOC_INT32*)(i3+(_check_index(i2, i4, OOC_UINT32, 7172))*4) = i2;
  i2 = i2+1;
  i = i2;
  i3 = i2<i0;
  if (i3) goto l3_loop;
l8:
  return (OOC_SSA_IGraph__ColorArray)i1;
  ;
}

OOC_SSA_IGraph__ColorArray OOC_SSA_IGraph__GraphDesc_ColorGraphSimple(OOC_SSA_IGraph__Graph g) {
  register OOC_INT32 i0,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10;
  OOC_SSA_IGraph__ColorArray ca;
  OOC_SSA_IGraph__BitMatrix m;
  OOC_INT32 i;
  OOC_INT32 color;
  OOC_INT32 clashes;
  OOC_INT32 j;

  i0 = (OOC_INT32)g;
  i1 = *(OOC_INT32*)((_check_pointer(i0, 7620))+4);
  i1 = (OOC_INT32)RT0__NewObject(_td_OOC_SSA_IGraph__ColorArray.baseTypes[0], i1);
  ca = (OOC_SSA_IGraph__ColorArray)i1;
  i2 = (OOC_INT32)*(OOC_INT32*)(_check_pointer(i0, 7639));
  m = (OOC_SSA_IGraph__BitMatrix)i2;
  i = 0;
  i0 = *(OOC_INT32*)((_check_pointer(i0, 7663))+4);
  i3 = 0<i0;
  if (!i3) goto l30;
  i3=0;
l3_loop:
  i4 = 0<i3;
  color = 0;
  i5=0;
l4_loop:
  clashes = 0;
  j = 0;
  if (i4) goto l7;
  i6=0;
  goto l21;
l7:
  i6=i5;i5=0;i7=0;
l8_loop:
  i8 = _check_pointer(i2, 7794);
  i9 = OOC_ARRAY_LENGTH(i8, 1);
  i10 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = *(OOC_UINT32*)((i8+((_check_index(i3, i10, OOC_UINT32, 7794))*(4*i9)))+(_check_index((i5>>5), i9, OOC_UINT32, 7796))*4);
  i8 = _in((_mod(i5,32)),i8);
  if (i8) goto l11;
  i8=0u;
  goto l13;
l11:
  i8 = _check_pointer(i1, 7835);
  i9 = OOC_ARRAY_LENGTH(i8, 0);
  i8 = *(OOC_INT32*)(i8+(_check_index(i5, i9, OOC_UINT32, 7835))*4);
  i8 = i8==i6;
  
l13:
  if (!i8) goto l16;
  i6 = i6+1;
  color = i6;
  i7 = i7+1;
  clashes = i7;
  
l16:
  i5 = i5+1;
  j = i5;
  i8 = i5<i3;
  if (i8) goto l8_loop;
l20:
  i5=i6;i6=i7;
l21:
  i6 = i6==0;
  if (!i6) goto l4_loop;
l25:
  i4 = _check_pointer(i1, 7967);
  i6 = OOC_ARRAY_LENGTH(i4, 0);
  *(OOC_INT32*)(i4+(_check_index(i3, i6, OOC_UINT32, 7967))*4) = i5;
  i3 = i3+1;
  i = i3;
  i4 = i3<i0;
  if (i4) goto l3_loop;
l30:
  return (OOC_SSA_IGraph__ColorArray)i1;
  ;
}

void OOC_OOC_SSA_IGraph_init(void) {

  return;
  ;
}

/* --- */
