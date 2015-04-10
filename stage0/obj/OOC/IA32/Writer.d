#include "OOC/IA32/Writer.oh"
#include "Ascii.oh"
#include "Files.oh"
#include "IntStr.oh"
#include "Strings.oh"
#include "ADT/Object.oh"
#include "Language/String8.oh"
#include "RT0.oh"
#include "Language/String0.oh"
static void OOC_IA32_Writer__InitWriter(OOC_IA32_Writer__Writer w, Channel__Channel ch);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_OOC_IA32_Writer__Writer = { (RT0__Struct[]){&_td_OOC_IA32_Writer__WriterDesc}, NULL, &_mid, "Writer", 4, -1, RT0__strPointer };
RT0__StructDesc _td_OOC_IA32_Writer__WriterDesc = { (RT0__Struct[]){&_td_OOC_IA32_Writer__WriterDesc}, (void*[]){(void*)OOC_IA32_Writer__WriterDesc_Close,(void*)OOC_IA32_Writer__WriterDesc_Directive,(void*)OOC_IA32_Writer__WriterDesc_GetStringLabel,(void*)OOC_IA32_Writer__WriterDesc_Instr,(void*)OOC_IA32_Writer__WriterDesc_Label,(void*)OOC_IA32_Writer__WriterDesc_Newline,(void*)OOC_IA32_Writer__WriterDesc_PopBytes,(void*)OOC_IA32_Writer__WriterDesc_PushInt,(void*)OOC_IA32_Writer__WriterDesc_PushLabel,(void*)OOC_IA32_Writer__WriterDesc_Section,(void*)OOC_IA32_Writer__WriterDesc_StringLiteral,(void*)OOC_IA32_Writer__WriterDesc_Write,(void*)OOC_IA32_Writer__WriterDesc_WriteStringData}, &_mid, "WriterDesc", 16, 0, RT0__strRecord };
RT0__StructDesc _td_OOC_IA32_Writer__2010 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_IA32_Writer__2123 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_IA32_Writer__2306 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_IA32_Writer__2455 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_IA32_Writer__2641 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_IA32_Writer__2831 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_OOC_IA32_Writer__3208 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 32, 32, RT0__strArray };
RT0__StructDesc _td_OOC_IA32_Writer__3826 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"OOC:IA32:Writer", (RT0__Struct[]) { &_td_OOC_IA32_Writer__Writer, &_td_OOC_IA32_Writer__WriterDesc, NULL } };

extern void OOC_OOC_IA32_Writer_init0() {
  RT0__RegisterModule(&_mid);
  OOC_OOC_IA32_Writer_init();
}

/* --- */
