#include <PosixFileDescr.oh>

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_PosixFileDescr__Channel = { (RT0__Struct[]){&_td_PosixFileDescr__ChannelDesc}, NULL, &_mid, "Channel", 4, -1, RT0__strPointer };
RT0__StructDesc _td_PosixFileDescr__Reader = { (RT0__Struct[]){&_td_PosixFileDescr__ReaderDesc}, NULL, &_mid, "Reader", 4, -1, RT0__strPointer };
RT0__StructDesc _td_PosixFileDescr__Writer = { (RT0__Struct[]){&_td_PosixFileDescr__WriterDesc}, NULL, &_mid, "Writer", 4, -1, RT0__strPointer };
RT0__StructDesc _td_PosixFileDescr__ChannelDesc = { (RT0__Struct[]){&_td_Channel__ChannelDesc,&_td_PosixFileDescr__ChannelDesc}, (void*[]){(void*)Channel__ChannelDesc_ClearError,(void*)PosixFileDescr__ChannelDesc_Close,(void*)PosixFileDescr__ChannelDesc_Flush,(void*)PosixFileDescr__ChannelDesc_GetModTime,(void*)PosixFileDescr__ChannelDesc_Length,(void*)PosixFileDescr__ChannelDesc_NewReader,(void*)PosixFileDescr__ChannelDesc_NewWriter}, &_mid, "ChannelDesc", 44, 1, RT0__strRecord };
RT0__StructDesc _td_PosixFileDescr__3767 = { (RT0__Struct[]){NULL}, NULL, &_mid, NULL, 4, -1, RT0__strPointer };
RT0__StructDesc _td_PosixFileDescr__ReaderDesc = { (RT0__Struct[]){&_td_Channel__ReaderDesc,&_td_PosixFileDescr__ReaderDesc}, (void*[]){(void*)PosixFileDescr__ReaderDesc_Available,(void*)Channel__ReaderDesc_ClearError,(void*)PosixFileDescr__ReaderDesc_Pos,(void*)PosixFileDescr__ReaderDesc_ReadByte,(void*)PosixFileDescr__ReaderDesc_ReadBytes,(void*)PosixFileDescr__ReaderDesc_SetPos}, &_mid, "ReaderDesc", 20, 1, RT0__strRecord };
RT0__StructDesc _td_PosixFileDescr__WriterDesc = { (RT0__Struct[]){&_td_Channel__WriterDesc,&_td_PosixFileDescr__WriterDesc}, (void*[]){(void*)Channel__WriterDesc_ClearError,(void*)PosixFileDescr__WriterDesc_Pos,(void*)PosixFileDescr__WriterDesc_SetPos,(void*)PosixFileDescr__WriterDesc_WriteByte,(void*)PosixFileDescr__WriterDesc_WriteBytes}, &_mid, "WriterDesc", 20, 1, RT0__strRecord };
RT0__StructDesc _td_PosixFileDescr__ErrorContext = { (RT0__Struct[]){&_td_PosixFileDescr__ErrorContextDesc}, NULL, &_mid, "ErrorContext", 4, -1, RT0__strPointer };
RT0__StructDesc _td_PosixFileDescr__ErrorContextDesc = { (RT0__Struct[]){&_td_Msg__ContextDesc,&_td_Channel__ErrorContextDesc,&_td_PosixFileDescr__ErrorContextDesc}, (void*[]){(void*)PosixFileDescr__ErrorContextDesc_GetTemplate}, &_mid, "ErrorContextDesc", 4, 2, RT0__strRecord };
RT0__StructDesc _td_PosixFileDescr__5406 = { (RT0__Struct[]){&RT0__byte}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_PosixFileDescr__5760 = { (RT0__Struct[]){&RT0__byte}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"PosixFileDescr", (RT0__Struct[]) { &_td_PosixFileDescr__Channel, &_td_PosixFileDescr__Reader, &_td_PosixFileDescr__Writer, &_td_PosixFileDescr__ChannelDesc, &_td_PosixFileDescr__ReaderDesc, &_td_PosixFileDescr__WriterDesc, &_td_PosixFileDescr__ErrorContext, &_td_PosixFileDescr__ErrorContextDesc, NULL } };

extern void OOC_PosixFileDescr_init0() {
  RT0__RegisterModule(&_mid);
  OOC_PosixFileDescr_init();
}

/* --- */
