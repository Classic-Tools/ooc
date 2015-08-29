#include "XML/UnicodeCodec/UTF16.oh"
XML_UnicodeCodec_UTF16__Factory XML_UnicodeCodec_UTF16__factory;
XML_UnicodeCodec_UTF16__FactoryLE XML_UnicodeCodec_UTF16__factoryLE;
XML_UnicodeCodec_UTF16__FactoryBE XML_UnicodeCodec_UTF16__factoryBE;
static void XML_UnicodeCodec_UTF16__InitBE(XML_UnicodeCodec_UTF16__Codec codec, OOC_INT8 bom);
static XML_UnicodeCodec_UTF16__Codec XML_UnicodeCodec_UTF16__NewBE(OOC_INT8 bom);
static void XML_UnicodeCodec_UTF16__InitLE(XML_UnicodeCodec_UTF16__Codec codec, OOC_INT8 bom);
static XML_UnicodeCodec_UTF16__Codec XML_UnicodeCodec_UTF16__NewLE(OOC_INT8 bom);
static void XML_UnicodeCodec_UTF16__InitFactory(XML_UnicodeCodec_UTF16__Factory f);
static void XML_UnicodeCodec_UTF16__InitFactoryLE(XML_UnicodeCodec_UTF16__FactoryLE f);
static void XML_UnicodeCodec_UTF16__InitFactoryBE(XML_UnicodeCodec_UTF16__FactoryBE f);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__Codec = { (RT0__Struct[]){&_td_XML_UnicodeCodec_UTF16__CodecDesc}, NULL, &_mid, "Codec", 4, -1, RT0__strPointer };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__CodecDesc = { (RT0__Struct[]){&_td_XML_UnicodeCodec__CodecDesc,&_td_XML_UnicodeCodec_UTF16__CodecDesc}, (void*[]){(void*)XML_UnicodeCodec_UTF16__CodecDesc_Decode,(void*)XML_UnicodeCodec_UTF16__CodecDesc_Encode,(void*)XML_UnicodeCodec__CodecDesc_EncodeBOM}, &_mid, "CodecDesc", 12, 1, RT0__strRecord };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__Factory = { (RT0__Struct[]){&_td_XML_UnicodeCodec_UTF16__FactoryDesc}, NULL, &_mid, "Factory", 4, -1, RT0__strPointer };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__FactoryDesc = { (RT0__Struct[]){&_td_XML_UnicodeCodec__FactoryDesc,&_td_XML_UnicodeCodec_UTF16__FactoryDesc}, (void*[]){(void*)XML_UnicodeCodec_UTF16__FactoryDesc_GetEncodingName,(void*)XML_UnicodeCodec_UTF16__FactoryDesc_NewCodec,(void*)XML_UnicodeCodec_UTF16__FactoryDesc_NewCodecBOM}, &_mid, "FactoryDesc", 1, 1, RT0__strRecord };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__FactoryLE = { (RT0__Struct[]){&_td_XML_UnicodeCodec_UTF16__FactoryLEDesc}, NULL, &_mid, "FactoryLE", 4, -1, RT0__strPointer };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__FactoryLEDesc = { (RT0__Struct[]){&_td_XML_UnicodeCodec__FactoryDesc,&_td_XML_UnicodeCodec_UTF16__FactoryLEDesc}, (void*[]){(void*)XML_UnicodeCodec_UTF16__FactoryLEDesc_GetEncodingName,(void*)XML_UnicodeCodec_UTF16__FactoryLEDesc_NewCodec,(void*)XML_UnicodeCodec_UTF16__FactoryLEDesc_NewCodecBOM}, &_mid, "FactoryLEDesc", 1, 1, RT0__strRecord };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__FactoryBE = { (RT0__Struct[]){&_td_XML_UnicodeCodec_UTF16__FactoryBEDesc}, NULL, &_mid, "FactoryBE", 4, -1, RT0__strPointer };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__FactoryBEDesc = { (RT0__Struct[]){&_td_XML_UnicodeCodec__FactoryDesc,&_td_XML_UnicodeCodec_UTF16__FactoryBEDesc}, (void*[]){(void*)XML_UnicodeCodec_UTF16__FactoryBEDesc_GetEncodingName,(void*)XML_UnicodeCodec_UTF16__FactoryBEDesc_NewCodec,(void*)XML_UnicodeCodec_UTF16__FactoryBEDesc_NewCodecBOM}, &_mid, "FactoryBEDesc", 1, 1, RT0__strRecord };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__1469 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__1595 = { (RT0__Struct[]){&RT0__longchar}, NULL, &_mid, NULL, 2, 1, RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__4633 = { (RT0__Struct[]){&RT0__longchar}, NULL, &_mid, NULL, 2, 1, RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__4767 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__7952 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__8672 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__9012 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__9675 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__10017 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_XML_UnicodeCodec_UTF16__10680 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"XML:UnicodeCodec:UTF16", (RT0__Struct[]) { &_td_XML_UnicodeCodec_UTF16__Codec, &_td_XML_UnicodeCodec_UTF16__CodecDesc, &_td_XML_UnicodeCodec_UTF16__Factory, &_td_XML_UnicodeCodec_UTF16__FactoryDesc, &_td_XML_UnicodeCodec_UTF16__FactoryLE, &_td_XML_UnicodeCodec_UTF16__FactoryLEDesc, &_td_XML_UnicodeCodec_UTF16__FactoryBE, &_td_XML_UnicodeCodec_UTF16__FactoryBEDesc, NULL } };

extern void OOC_XML_UnicodeCodec_UTF16_init0() {
  RT0__RegisterModule(&_mid);
  OOC_XML_UnicodeCodec_UTF16_init();
}

/* --- */
