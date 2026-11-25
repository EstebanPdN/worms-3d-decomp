#include "w3d_ptr.h"
#line 1 "cx15b_gx_watermark_watch_8016814c.cpp"
// Inferred engine names. Layout offsets and PPC32 four-byte pointers follow original effective addresses.
typedef unsigned int u32;typedef unsigned short u16;typedef unsigned char u8;
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))

extern "C" {void status_803069fc(Ptr32<u8>,Ptr32<u8>,Ptr32<u8>,Ptr32<u8>,Ptr32<u8>);int progress_80306cc8();void report_802fb7ac(Ptr32<const char>,...);void abort_801683c4();void panic_802fb82c(Ptr32<const char>,int,Ptr32<const char>,...);extern u32 ticks_804b00e4,hangs_804ab504,limit_804b00e8;extern int last_804ab508;extern char warning_803a4e20[],file_803a4e58[],message_803a4e6c[];}
extern "C" void w3d_cx15b_gx_watermark_watch_8016814c(){++ticks_804b00e4;u8 high,dummy;status_803069fc(&high,&dummy,&dummy,&dummy,&dummy);int progress=progress_80306cc8();if(high && progress==last_804ab508){++hangs_804ab504;if(hangs_804ab504>=limit_804b00e8){report_802fb7ac(warning_803a4e20);abort_801683c4();panic_802fb82c(file_803a4e58,1169,message_803a4e6c);}}else{hangs_804ab504=0;last_804ab508=progress;}}



