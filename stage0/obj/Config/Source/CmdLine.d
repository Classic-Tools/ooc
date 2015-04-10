#include "Config/Source/CmdLine.oh"
#include "CharClass.oh"
#include "Strings.oh"
#include "LongStrings.oh"
#include "TextRider.oh"
#include "RT0.oh"
#include "Language/String0.oh"
#define Config_Source_CmdLine__maxLenArgument 2048
#define Config_Source_CmdLine__connectFailed 1
#define Config_Source_CmdLine__junkAfterEnd 2
#define Config_Source_CmdLine__readError 3
#define Config_Source_CmdLine__unknownOption 4
#define Config_Source_CmdLine__singleCharWithArgs 5
#define Config_Source_CmdLine__expectArguments 6
static Config_Source_CmdLine__ErrorContext Config_Source_CmdLine__cmdLineContext;
static Msg__Msg Config_Source_CmdLine__Error(OOC_INT32 code);
static Msg__Msg Config_Source_CmdLine__ErrorReason(OOC_INT32 code, Msg__Msg reason);
static Msg__Msg Config_Source_CmdLine__ErrorString(OOC_INT32 code, const Config_Value__String string__ref, OOC_LEN string_0d);
static Msg__Msg Config_Source_CmdLine__ErrorStringNum(OOC_INT32 code, const Config_Value__String string__ref, OOC_LEN string_0d, OOC_INT32 number);
static void Config_Source_CmdLine__Init(Config_Source_CmdLine__CmdLine cmdLine);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_Config_Source_CmdLine__OptionTemplate = { (RT0__Struct[]){&_td_Config_Source_CmdLine__OptionTemplateDesc}, NULL, &_mid, "OptionTemplate", 4, -1, RT0__strPointer };
RT0__StructDesc _td_Config_Source_CmdLine__1152 = { (RT0__Struct[]){&_td_Config_Value__StringPtr}, NULL, &_mid, NULL, 4, 1, RT0__strOpenArray };
RT0__StructDesc _td_Config_Source_CmdLine__NameArray = { (RT0__Struct[]){&_td_Config_Source_CmdLine__1152}, NULL, &_mid, "NameArray", 4, -1, RT0__strPointer };
RT0__StructDesc _td_Config_Source_CmdLine__OptionTemplateDesc = { (RT0__Struct[]){&_td_Config_Source_CmdLine__OptionTemplateDesc}, (void*[]){}, &_mid, "OptionTemplateDesc", 16, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Source_CmdLine__Command = { (RT0__Struct[]){&_td_Config_Source_CmdLine__CommandDesc}, NULL, &_mid, "Command", 4, -1, RT0__strPointer };
RT0__StructDesc _td_Config_Source_CmdLine__1382 = { (RT0__Struct[]){&_td_Config_Value__StringPtr}, NULL, &_mid, NULL, 4, 1, RT0__strOpenArray };
RT0__StructDesc _td_Config_Source_CmdLine__ArgList = { (RT0__Struct[]){&_td_Config_Source_CmdLine__1382}, NULL, &_mid, "ArgList", 4, -1, RT0__strPointer };
RT0__StructDesc _td_Config_Source_CmdLine__CommandDesc = { (RT0__Struct[]){&_td_Config_Source_CmdLine__CommandDesc}, (void*[]){(void*)Config_Source_CmdLine__CommandDesc_DoNotWrite}, &_mid, "CommandDesc", 16, 0, RT0__strRecord };
RT0__StructDesc _td_Config_Source_CmdLine__CmdLine = { (RT0__Struct[]){&_td_Config_Source_CmdLine__CmdLineDesc}, NULL, &_mid, "CmdLine", 4, -1, RT0__strPointer };
RT0__StructDesc _td_Config_Source_CmdLine__CmdLineDesc = { (RT0__Struct[]){&_td_Config_Source__SourceDesc,&_td_Config_Source_CmdLine__CmdLineDesc}, (void*[]){(void*)Config_Source_CmdLine__CmdLineDesc_Write,(void*)Config_Source_CmdLine__CmdLineDesc_AddOptionTemplate,(void*)Config_Source_CmdLine__CmdLineDesc_EnableDashDash,(void*)Config_Source_CmdLine__CmdLineDesc_EnableExpandToSingleChar,(void*)Config_Source_CmdLine__CmdLineDesc_OptionsStartWithDash,(void*)Config_Source_CmdLine__CmdLineDesc_Parse}, &_mid, "CmdLineDesc", 16, 1, RT0__strRecord };
RT0__StructDesc _td_Config_Source_CmdLine__ErrorContext = { (RT0__Struct[]){&_td_Config_Source_CmdLine__ErrorContextDesc}, NULL, &_mid, "ErrorContext", 4, -1, RT0__strPointer };
RT0__StructDesc _td_Config_Source_CmdLine__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_Config_Source_CmdLine__ErrorContextDesc}, (void*[]){(void*)Config_Source_CmdLine__ErrorContextDesc_GetTemplate}, &_mid, "ErrorContextDesc", 4, 1, RT0__strRecord };
RT0__StructDesc _td_Config_Source_CmdLine__4172 = { (RT0__Struct[]){&RT0__longchar}, NULL, &_mid, NULL, 256, 128, RT0__strArray };
RT0__StructDesc _td_Config_Source_CmdLine__6587 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_Config_Source_CmdLine__13337 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 2048, 2048, RT0__strArray };
RT0__StructDesc _td_Config_Source_CmdLine__13496 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 3, 3, RT0__strArray };
RT0__StructDesc _td_Config_Source_CmdLine__13545 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_Config_Source_CmdLine__19662 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1024, 1024, RT0__strArray };
RT0__StructDesc _td_Config_Source_CmdLine__19742 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"Config:Source:CmdLine", (RT0__Struct[]) { &_td_Config_Source_CmdLine__OptionTemplate, &_td_Config_Source_CmdLine__NameArray, &_td_Config_Source_CmdLine__OptionTemplateDesc, &_td_Config_Source_CmdLine__Command, &_td_Config_Source_CmdLine__ArgList, &_td_Config_Source_CmdLine__CommandDesc, &_td_Config_Source_CmdLine__CmdLine, &_td_Config_Source_CmdLine__CmdLineDesc, &_td_Config_Source_CmdLine__ErrorContext, &_td_Config_Source_CmdLine__ErrorContextDesc, NULL } };

extern void OOC_Config_Source_CmdLine_init0() {
  RT0__RegisterModule(&_mid);
  OOC_Config_Source_CmdLine_init();
}

/* --- */
