#include <OOC/Doc/Input/Texinfo.oh>
#include <Ascii.oh>
#include <CharClass.oh>
#include <Out.oh>
#include <Msg.oh>
#include <Channel.oh>
#include <TextRider.oh>
#include <StdChannels.oh>
#include <Strings.oh>
#include <OOC/Scanner/InputBuffer.oh>
#include <OOC/Scanner.oh>
#include <OOC/Doc/Decoration.oh>
#include <OOC/Doc/TextBuffer.oh>
typedef OOC_INT8 OOC_Doc_Input_Texinfo__Id;
#define OOC_Doc_Input_Texinfo__class1Low 0
#define OOC_Doc_Input_Texinfo__cmdAtGlyph 0
#define OOC_Doc_Input_Texinfo__cmdLeftBrace 1
#define OOC_Doc_Input_Texinfo__cmdRightBrace 2
#define OOC_Doc_Input_Texinfo__class1High 2
#define OOC_Doc_Input_Texinfo__class2Low 3
#define OOC_Doc_Input_Texinfo__cmdBullet 3
#define OOC_Doc_Input_Texinfo__cmdDots 4
#define OOC_Doc_Input_Texinfo__cmdMinus 5
#define OOC_Doc_Input_Texinfo__cmdResult 6
#define OOC_Doc_Input_Texinfo__class2High 6
#define OOC_Doc_Input_Texinfo__class3Low 7
#define OOC_Doc_Input_Texinfo__cmdAsIs 7
#define OOC_Doc_Input_Texinfo__cmdCite 8
#define OOC_Doc_Input_Texinfo__cmdCode 9
#define OOC_Doc_Input_Texinfo__cmdDfn 10
#define OOC_Doc_Input_Texinfo__cmdEmph 11
#define OOC_Doc_Input_Texinfo__cmdFile 12
#define OOC_Doc_Input_Texinfo__cmdKbd 13
#define OOC_Doc_Input_Texinfo__cmdSamp 14
#define OOC_Doc_Input_Texinfo__cmdStrong 15
#define OOC_Doc_Input_Texinfo__cmdUrl 16
#define OOC_Doc_Input_Texinfo__cmdVar 17
#define OOC_Doc_Input_Texinfo__cmdOberonModule 18
#define OOC_Doc_Input_Texinfo__cmdOberonConst 19
#define OOC_Doc_Input_Texinfo__cmdOberonField 20
#define OOC_Doc_Input_Texinfo__cmdOberonParam 21
#define OOC_Doc_Input_Texinfo__cmdOberonProc 22
#define OOC_Doc_Input_Texinfo__cmdOberonType 23
#define OOC_Doc_Input_Texinfo__cmdOberonVar 24
#define OOC_Doc_Input_Texinfo__cmdEmail 25
#define OOC_Doc_Input_Texinfo__cmdUref 26
#define OOC_Doc_Input_Texinfo__class3High 26
#define OOC_Doc_Input_Texinfo__class3Args 25
#define OOC_Doc_Input_Texinfo__class4Low 27
#define OOC_Doc_Input_Texinfo__cmdExample 27
#define OOC_Doc_Input_Texinfo__cmdItemize 28
#define OOC_Doc_Input_Texinfo__cmdNoIndent 29
#define OOC_Doc_Input_Texinfo__cmdPreCond 30
#define OOC_Doc_Input_Texinfo__cmdPostCond 31
#define OOC_Doc_Input_Texinfo__cmdTable 32
#define OOC_Doc_Input_Texinfo__cmdEnd 33
#define OOC_Doc_Input_Texinfo__cmdItem 34
#define OOC_Doc_Input_Texinfo__cmdItemX 35
#define OOC_Doc_Input_Texinfo__class4High 35
#define OOC_Doc_Input_Texinfo__cmdUnknown 36
#define OOC_Doc_Input_Texinfo__cmdEmDash 37
#define OOC_Doc_Input_Texinfo__cmdLeftQuot 38
#define OOC_Doc_Input_Texinfo__cmdRightQuot 39
#define OOC_Doc_Input_Texinfo__cmdText 40
#define OOC_Doc_Input_Texinfo__cmdOpeningBrace 41
#define OOC_Doc_Input_Texinfo__cmdClosingBrace 42
#define OOC_Doc_Input_Texinfo__cmdArgSeparator 43
#define OOC_Doc_Input_Texinfo__cmdEndOfText 44
typedef struct OOC_Doc_Input_Texinfo__CommandDesc *OOC_Doc_Input_Texinfo__Command;
typedef struct OOC_Doc_Input_Texinfo__CommandDesc {
  OOC_INT8 id;
  OOC_INT8 _class;
  OOC_CHAR8 name[16];
  OOC_INT8 argLow;
  OOC_INT8 argHigh;
} OOC_Doc_Input_Texinfo__CommandDesc;
typedef struct OOC_Doc_Input_Texinfo__TokenDesc *OOC_Doc_Input_Texinfo__Token;
typedef struct OOC_Doc_Input_Texinfo__TokenDesc {
  OOC_Doc_Input_Texinfo__Token next;
  OOC_CHAR8 bol;
  OOC_INT8 id;
  OOC_CHAR8 __pad6;
  OOC_CHAR8 __pad7;
  OOC_INT32 pos;
  OOC_INT32 line;
  OOC_INT32 column;
  OOC_Scanner_InputBuffer__CharArray str;
} OOC_Doc_Input_Texinfo__TokenDesc;
static OOC_INT8 OOC_Doc_Input_Texinfo__class1[256];
static OOC_Doc_Input_Texinfo__Command OOC_Doc_Input_Texinfo__cmdList[36];
static OOC_Scanner_InputBuffer__CharArray OOC_Doc_Input_Texinfo__emptyString;
#define OOC_Doc_Input_Texinfo__unknownCommand 1
#define OOC_Doc_Input_Texinfo__expectedLeftBrace 2
#define OOC_Doc_Input_Texinfo__expectedRightBrace 3
#define OOC_Doc_Input_Texinfo__junkAfterText 4
#define OOC_Doc_Input_Texinfo__junkAtEndOfLine 5
#define OOC_Doc_Input_Texinfo__invalidItemMark 6
#define OOC_Doc_Input_Texinfo__notAtBeginningOfLine 7
#define OOC_Doc_Input_Texinfo__expectedEnd 8
#define OOC_Doc_Input_Texinfo__lonelyLeftBrace 9
#define OOC_Doc_Input_Texinfo__lonelyRightBrace 10
#define OOC_Doc_Input_Texinfo__wrongNumberOfArgs 11
#define OOC_Doc_Input_Texinfo__expectedMarkupCommand 12
static OOC_Doc_Input_Texinfo__ErrorContext OOC_Doc_Input_Texinfo__texinfoContext;
static OOC_Doc_Input_Texinfo__Token OOC_Doc_Input_Texinfo__Tokenize(OOC_Scanner_Builder_BasicList__Symbol sym, OOC_Scanner_InputBuffer__CharArray str, OOC_Error__List errList);
static void OOC_Doc_Input_Texinfo__WriteTokens(Channel__Channel ch, OOC_Doc_Input_Texinfo__Token t);
static void OOC_Doc_Input_Texinfo__Init();

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__Command = { (RT0__Struct[]){&_td_OOC_Doc_Input_Texinfo__CommandDesc}, NULL, &_mid, "Command", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__CommandDesc = { (RT0__Struct[]){&_td_OOC_Doc_Input_Texinfo__CommandDesc}, (void*[]){}, &_mid, "CommandDesc", 20, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__3206 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 16, 16, RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__Token = { (RT0__Struct[]){&_td_OOC_Doc_Input_Texinfo__TokenDesc}, NULL, &_mid, "Token", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__TokenDesc = { (RT0__Struct[]){&_td_OOC_Doc_Input_Texinfo__TokenDesc}, (void*[]){}, &_mid, "TokenDesc", 24, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__3568 = { (RT0__Struct[]){&RT0__shortint}, NULL, &_mid, NULL, 256, 256, RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__3602 = { (RT0__Struct[]){&_td_OOC_Doc_Input_Texinfo__Command}, NULL, &_mid, NULL, 144, 36, RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__ErrorContext = { (RT0__Struct[]){&_td_OOC_Doc_Input_Texinfo__ErrorContextDesc}, NULL, &_mid, "ErrorContext", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_OOC_Error__ContextDesc,&_td_OOC_Doc_Input_Texinfo__ErrorContextDesc}, (void*[]){(void*)OOC_Doc_Input_Texinfo__ErrorContextDesc_GetTemplate,(void*)OOC_Error__ContextDesc_BaseTemplate}, &_mid, "ErrorContextDesc", 4, 2, RT0__strRecord };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__4233 = { (RT0__Struct[]){&RT0__longchar}, NULL, &_mid, NULL, 256, 128, RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__5550 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 16, 16, RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__7079 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__11811 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__15475 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__17623 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 2, 2, RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__17766 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__23845 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__25331 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 2, 2, RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__28163 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 2, 2, RT0__strArray };
RT0__StructDesc _td_OOC_Doc_Input_Texinfo__31703 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:Doc:Input:Texinfo", (RT0__Struct[]) { &_td_OOC_Doc_Input_Texinfo__Command, &_td_OOC_Doc_Input_Texinfo__CommandDesc, &_td_OOC_Doc_Input_Texinfo__Token, &_td_OOC_Doc_Input_Texinfo__TokenDesc, &_td_OOC_Doc_Input_Texinfo__ErrorContext, &_td_OOC_Doc_Input_Texinfo__ErrorContextDesc, NULL } };

extern void OOC_OOC_Doc_Input_Texinfo_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_Doc_Input_Texinfo_init();
}

/* --- */
