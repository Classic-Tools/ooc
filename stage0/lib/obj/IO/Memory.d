#include <IO/Memory.oh>
#define IO_Memory__offset 16
static void IO_Memory__Init(IO_Memory__Channel ch);

/* run-time meta data */
static RT0__ModuleDesc _mid;
RT0__StructDesc _td_IO_Memory__927 = { (RT0__Struct[]){&RT0__char}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_IO_Memory__Data = { (RT0__Struct[]){&_td_IO_Memory__927}, NULL, &_mid, "Data", 4, -1, RT0__strPointer };
RT0__StructDesc _td_IO_Memory__Channel = { (RT0__Struct[]){&_td_IO_Memory__ChannelDesc}, NULL, &_mid, "Channel", 4, -1, RT0__strPointer };
RT0__StructDesc _td_IO_Memory__ChannelDesc = { (RT0__Struct[]){&_td_IO__ChannelDesc,&_td_IO__ByteChannelDesc,&_td_IO_Memory__ChannelDesc}, (void*[]){(void*)IO__ChannelDesc_Close,(void*)IO__ChannelDesc_CloseAndRegister,(void*)IO_Memory__ChannelDesc_FileDescriptor,(void*)IO__ChannelDesc_KeyForSelector,(void*)IO__ChannelDesc_RegisterWithSelector,(void*)IO_Memory__ChannelDesc_SetBlocking,(void*)IO_Memory__ChannelDesc_SetPos,(void*)IO__ByteChannelDesc_Flush,(void*)IO_Memory__ChannelDesc_Read,(void*)IO__ByteChannelDesc_TransferTo,(void*)IO_Memory__ChannelDesc_Write,(void*)IO_Memory__ChannelDesc_Fingerprint,(void*)IO_Memory__ChannelDesc_Truncate}, &_mid, "ChannelDesc", 20, 2, RT0__strRecord };
RT0__StructDesc _td_IO_Memory__1774 = { (RT0__Struct[]){&RT0__byte}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_IO_Memory__2517 = { (RT0__Struct[]){&RT0__byte}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
RT0__StructDesc _td_IO_Memory__3375 = { (RT0__Struct[]){&RT0__byte}, NULL, &_mid, NULL, 1, 1, RT0__strOpenArray };
static RT0__ModuleDesc _mid = { (OOC_CHAR8*)"IO:Memory", (RT0__Struct[]) { &_td_IO_Memory__Data, &_td_IO_Memory__Channel, &_td_IO_Memory__ChannelDesc, NULL } };

extern void OOC_IO_Memory_init0() {
  RT0__RegisterModule(&_mid);
  OOC_IO_Memory_init();
}

/* --- */
