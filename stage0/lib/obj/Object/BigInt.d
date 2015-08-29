#include <Object/BigInt.oh>
#include <CharClass.oh>
#include <Strings.oh>
typedef OOC_INT32 Object_BigInt__TwoDigits;
#define Object_BigInt__shift 15
#define Object_BigInt__base 32768
#define Object_BigInt__mask 32767
Object_BigInt__BigInt Object_BigInt__zero;
Object_BigInt__BigInt Object_BigInt__one;
static OOC_INT8 Object_BigInt__powerOf2[37];
static Object_BigInt__BigInt Object_BigInt__NewInstance(OOC_INT32 size);
static void Object_BigInt__Normalize(Object_BigInt__BigInt big);
static Object_BigInt__BigInt Object_BigInt__AddAbs(Object_BigInt__BigInt a, Object_BigInt__BigInt b);
static Object_BigInt__BigInt Object_BigInt__SubAbs(Object_BigInt__BigInt a, Object_BigInt__BigInt b);
static Object_BigInt__BigInt Object_BigInt__MulAbs(Object_BigInt__BigInt a, Object_BigInt__BigInt b);
static OOC_INT16 Object_BigInt__InplaceDivRem1(OOC_INT16 pout[], OOC_LEN pout_0d, OOC_INT16 pin[], OOC_LEN pin_0d, OOC_INT32 size, OOC_INT16 n);
static Object_BigInt__BigInt Object_BigInt__DivRem1(Object_BigInt__BigInt a, OOC_INT16 n, OOC_INT16 *rem);
static Object_BigInt__BigInt Object_BigInt__MulAdd1(Object_BigInt__BigInt a, OOC_INT16 n, OOC_INT16 add);
static Object_BigInt__BigInt Object_BigInt__DivRemAbs(Object_BigInt__BigInt v1, Object_BigInt__BigInt _w1, Object_BigInt__BigInt *rem);
static void Object_BigInt__DivRem(Object_BigInt__BigInt a, Object_BigInt__BigInt b, Object_BigInt__BigInt *div, Object_BigInt__BigInt *rem);
static void Object_BigInt__Init(void);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Object_BigInt__BigInt = { (RT0__Struct[]){&_td_Object_BigInt__BigIntDesc}, NULL, NULL, &_mid, "BigInt", 4, -1, RT0__strPointer };
RT0__StructDesc _td_Object_BigInt__1485 = { (RT0__Struct[]){&RT0__integer}, NULL, NULL, &_mid, NULL, 2, 1, RT0__strOpenArray };
RT0__StructDesc _td_Object_BigInt__DigitArray = { (RT0__Struct[]){&_td_Object_BigInt__1485}, NULL, NULL, &_mid, "DigitArray", 4, -1, RT0__strPointer };
RT0__StructDesc _td_Object_BigInt__BigIntDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td_Object_Boxed__ObjectDesc,&_td_Object_BigInt__BigIntDesc}, (void*[]){(void*)Object_BigInt__BigIntDesc_Equals,(void*)Object_BigInt__BigIntDesc_HashCode,(void*)Object_BigInt__BigIntDesc_ToString,(void*)Object_BigInt__BigIntDesc_Load,(void*)Object_BigInt__BigIntDesc_Store,(void*)Object_BigInt__BigIntDesc_Cmp,(void*)Object_BigInt__BigIntDesc_Abs,(void*)Object_BigInt__BigIntDesc_Add,(void*)Object_BigInt__BigIntDesc_Copy,(void*)Object_BigInt__BigIntDesc_Div,(void*)Object_BigInt__BigIntDesc_DivMod,(void*)Object_BigInt__BigIntDesc_Format,(void*)Object_BigInt__BigIntDesc_Invert,(void*)Object_BigInt__BigIntDesc_IsZero,(void*)Object_BigInt__BigIntDesc_LShift,(void*)Object_BigInt__BigIntDesc_Mod,(void*)Object_BigInt__BigIntDesc_Mul,(void*)Object_BigInt__BigIntDesc_Neg,(void*)Object_BigInt__BigIntDesc_NonZero,(void*)Object_BigInt__BigIntDesc_RShift,(void*)Object_BigInt__BigIntDesc_Sign,(void*)Object_BigInt__BigIntDesc_Sub,(void*)Object_BigInt__BigIntDesc_ToLongInt}, NULL, &_mid, "BigIntDesc", 8, 3, RT0__strRecord };
RT0__StructDesc _td_Object_BigInt__2156 = { (RT0__Struct[]){&RT0__shortint}, NULL, NULL, &_mid, NULL, 37, 37, RT0__strArray };
RT0__StructDesc _td_Object_BigInt__11319 = { (RT0__Struct[]){&RT0__integer}, NULL, NULL, &_mid, NULL, 2, 1, RT0__strOpenArray };
RT0__StructDesc _td_Object_BigInt__11370 = { (RT0__Struct[]){&RT0__integer}, NULL, NULL, &_mid, NULL, 2, 1, RT0__strOpenArray };
RT0__StructDesc _td_Object_BigInt__16888 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_Object_BigInt__16877 = { (RT0__Struct[]){&_td_Object_BigInt__16888}, NULL, NULL, &_mid, NULL, 4, -1, RT0__strPointer };
RT0__StructDesc _td_Object_BigInt__19766 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_Object_BigInt__20929 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Object:BigInt", (RT0__Struct[]) { &_td_Object_BigInt__BigInt, &_td_Object_BigInt__DigitArray, &_td_Object_BigInt__BigIntDesc, NULL } };

extern void OOC_Object_BigInt_init0() {
  RT0__RegisterModule(&_mid);
  OOC_Object_BigInt_init();
}

/* --- */
