static void* _c0;
static void* _c1;
#include <XML/Error.oh>
#include <Ascii.oh>
#include <Strings.oh>
#include <TextRider.oh>
#include <LongStrings.oh>
#include <Object.oh>
#include <IO.oh>
#include <OS/ProcessParameters.oh>
#include <URI/Scheme/File.oh>
OOC_INT32 XML_Error__errMsgLineBase;
OOC_INT32 XML_Error__errMsgColumnBase;
OOC_INT32 XML_Error__errMsgCharPosBase;

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_XML_Error__Mapping = { (RT0__Struct[]){&_td_XML_Error__MappingDesc}, NULL, NULL, &_mid, "Mapping", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Error__MappingDesc = { (RT0__Struct[]){&_td_XML_Error__MappingDesc}, (void*[]){}, NULL, &_mid, "MappingDesc", 12, 0, 0, RT0__strRecord };
RT0__StructDesc _td_XML_Error__Context = { (RT0__Struct[]){&_td_XML_Error__ContextDesc}, NULL, NULL, &_mid, "Context", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Error__ContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_XML_Error__ContextDesc}, (void*[]){(void*)XML_Error__ContextDesc_GetTemplate,(void*)XML_Error__ContextDesc_WriteTemplate,(void*)XML_Error__ContextDesc_SetString}, NULL, &_mid, "ContextDesc", 8, 1, 0, RT0__strRecord };
RT0__StructDesc _td_XML_Error__List = { (RT0__Struct[]){&_td_XML_Error__ListDesc}, NULL, NULL, &_mid, "List", 4, -1, 0, RT0__strPointer };
RT0__StructDesc _td_XML_Error__ListDesc = { (RT0__Struct[]){&_td_Msg__MsgListDesc,&_td_XML_Error__ListDesc}, (void*[]){(void*)Msg__MsgListDesc_Append,(void*)Msg__MsgListDesc_AppendList,(void*)XML_Error__ListDesc_Write}, NULL, &_mid, "ListDesc", 16, 1, 0, RT0__strRecord };
RT0__StructDesc _td_XML_Error__3911 = { (RT0__Struct[]){&RT0__longchar}, NULL, NULL, &_mid, NULL, 2048, 1024, 0, RT0__strArray };
RT0__StructDesc _td_XML_Error__5115 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 8192, 8192, 0, RT0__strArray };
RT0__StructDesc _td_XML_Error__5212 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1024, 1024, 0, RT0__strArray };
RT0__StructDesc _td_XML_Error__5299 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_XML_Error__5329 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, 0, RT0__strOpenArray };
RT0__StructDesc _td_XML_Error__6273 = { (RT0__Struct[]){&RT0__char}, NULL, NULL, &_mid, NULL, 1, 1, 0, RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"XML:Error", (RT0__Struct[]) { &_td_XML_Error__Mapping, &_td_XML_Error__MappingDesc, &_td_XML_Error__Context, &_td_XML_Error__ContextDesc, &_td_XML_Error__List, &_td_XML_Error__ListDesc, NULL } };

extern void OOC_XML_Error_init0() {
  RT0__RegisterModule(&_mid);
  OOC_XML_Error_init();
}

/* --- */
