#include <ADT/Dictionary/AddressKey/IntValue.oh>
#include <HashCode.oh>
typedef OOC_UINT32 ADT_Dictionary_AddressKey_IntValue__HSet;
typedef struct ADT_Dictionary_AddressKey_IntValue__DummyDesc *ADT_Dictionary_AddressKey_IntValue__Dummy;
typedef struct ADT_Dictionary_AddressKey_IntValue__DummyDesc {
  char __dummy;
} ADT_Dictionary_AddressKey_IntValue__DummyDesc;
static ADT_Dictionary_AddressKey_IntValue__Dummy ADT_Dictionary_AddressKey_IntValue__dummy;
#define ADT_Dictionary_AddressKey_IntValue__minSize 4
#define ADT_Dictionary_AddressKey_IntValue__maxPoly 28
static OOC_INT32 ADT_Dictionary_AddressKey_IntValue__polys[29];
static OOC_CHAR8 ADT_Dictionary_AddressKey_IntValue__IsSet(Object__Object key);
static OOC_INT32 ADT_Dictionary_AddressKey_IntValue__Lookup(ADT_Dictionary_AddressKey_IntValue__Dictionary dict, Object__Object key, OOC_INT32 hash);
static void ADT_Dictionary_AddressKey_IntValue__Insert(ADT_Dictionary_AddressKey_IntValue__Dictionary dict, Object__Object key, OOC_INT32 hash, OOC_INT32 value);
static void ADT_Dictionary_AddressKey_IntValue__Resize(ADT_Dictionary_AddressKey_IntValue__Dictionary dict, OOC_INT32 minUsed);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_ADT_Dictionary_AddressKey_IntValue__Entry = { (RT0__Struct[]){&_td_ADT_Dictionary_AddressKey_IntValue__Entry}, (void*[]){}, NULL, &_mid, "Entry", 12, 0, 0, RT0__strRecord };
RT0__StructDesc _td_ADT_Dictionary_AddressKey_IntValue__2538 = { (RT0__Struct[]){&_td_ADT_Dictionary_AddressKey_IntValue__Entry}, NULL, NULL, &_mid, NULL, 12, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_ADT_Dictionary_AddressKey_IntValue__Table = { (RT0__Struct[]){&_td_ADT_Dictionary_AddressKey_IntValue__2538}, NULL, NULL, &_mid, "Table", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Dictionary_AddressKey_IntValue__Dictionary = { (RT0__Struct[]){&_td_ADT_Dictionary_AddressKey_IntValue__DictionaryDesc}, NULL, NULL, &_mid, "Dictionary", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Dictionary_AddressKey_IntValue__DictionaryDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_ADT_Storable__ObjectDesc,&_td_ADT_Dictionary_AddressKey_IntValue__DictionaryDesc}, (void*[]){(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode,(void*)ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Store,(void*)ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Load,(void*)ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Destroy,(void*)ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_HasKey,(void*)ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Size,(void*)ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Get,(void*)ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Set,(void*)ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Copy,(void*)ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Delete,(void*)ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Clear,(void*)ADT_Dictionary_AddressKey_IntValue__DictionaryDesc_Keys}, NULL, &_mid, "DictionaryDesc", 20, 2, 0, RT0__strRecord };
RT0__StructDesc _td_ADT_Dictionary_AddressKey_IntValue__Dummy = { (RT0__Struct[]){&_td_ADT_Dictionary_AddressKey_IntValue__DummyDesc}, NULL, NULL, &_mid, "Dummy", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_ADT_Dictionary_AddressKey_IntValue__DummyDesc = { (RT0__Struct[]){&_td_Object__ObjectDesc,&_td_ADT_Dictionary_AddressKey_IntValue__DummyDesc}, (void*[]){(void*)Object__ObjectDesc_ToString,(void*)Object__ObjectDesc_Equals,(void*)Object__ObjectDesc_HashCode}, NULL, &_mid, "DummyDesc", 0, 1, 0, RT0__strRecord };
RT0__StructDesc _td_ADT_Dictionary_AddressKey_IntValue__3838 = { (RT0__Struct[]){&RT0__longint}, NULL, NULL, &_mid, NULL, 116, 29, 0, RT0__strArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"ADT:Dictionary:AddressKey:IntValue", (RT0__Struct[]) { &_td_ADT_Dictionary_AddressKey_IntValue__Entry, &_td_ADT_Dictionary_AddressKey_IntValue__Table, &_td_ADT_Dictionary_AddressKey_IntValue__Dictionary, &_td_ADT_Dictionary_AddressKey_IntValue__DictionaryDesc, &_td_ADT_Dictionary_AddressKey_IntValue__Dummy, &_td_ADT_Dictionary_AddressKey_IntValue__DummyDesc, NULL } };

extern void OOC_ADT_Dictionary_AddressKey_IntValue_init0() {
  RT0__RegisterModule(&_mid);
  OOC_ADT_Dictionary_AddressKey_IntValue_init();
}

/* --- */
