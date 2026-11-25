#include "w3d_ptr.h"
#line 1 "f7a_menu_message_8028e224.cpp"
// Inferred message header and by-value string ABI.
struct F7aMessage{unsigned short id;};
struct F7aText_8020bb54{Ptr32<char> text;template <class W3dU> F7aText_8020bb54(Ptr32<W3dU> w3d_p) : F7aText_8020bb54((const char *)w3d_p.get()) {}
 F7aText_8020bb54(const char*);~F7aText_8020bb54();};
struct F7aCache{int words[2];};
extern F7aCache cache_804b0cc4,cache_804b0cd4,cache_804b0ccc,cache_804b0ca4,cache_804b0cac,cache_804b0cb4,cache_804b0cbc,cache_804b0ce4;
extern int depth_804abb5c;
extern "C" int fn_8016293c(Ptr32<void>,Ptr32<F7aMessage>),fn_8015f65c(unsigned short,Ptr32<F7aCache>);
extern "C" Ptr32<const char> fn_8010a8fc(Ptr32<F7aMessage>);
extern "C" void fn_8028e4f4(Ptr32<void>),fn_8028e624(Ptr32<void>),fn_8028eb54(Ptr32<void>),fn_8028e9c0(Ptr32<void>),fn_8028e8ec(Ptr32<void>),fn_8028e444(Ptr32<void>);
extern "C" void fn_8028ebe0(Ptr32<void>,F7aText_8020bb54,int),fn_8028e630(Ptr32<void>,F7aText_8020bb54,int,int),fn_8028e7e0(Ptr32<void>,F7aText_8020bb54);
extern "C" int w3d_f7a_menu_message_8028e224(Ptr32<void> self,Ptr32<F7aMessage> msg){
 switch(msg->id){case 64:{if(fn_8016293c(self,msg)>=0){fn_8028e4f4(self);return 0;}return (int)0x80004005;}
 case 66:{fn_8028e624(self);goto done;}default:break;}
 if(fn_8015f65c(msg->id,&cache_804b0cc4)){fn_8028ebe0(self,F7aText_8020bb54(fn_8010a8fc(msg)),0);fn_8028e9c0(self);}
 else if(fn_8015f65c(msg->id,&cache_804b0cd4))fn_8028eb54(self);
 else if(fn_8015f65c(msg->id,&cache_804b0ccc)){fn_8028ebe0(self,F7aText_8020bb54(fn_8010a8fc(msg)),1);fn_8028e9c0(self);}
 else if(fn_8015f65c(msg->id,&cache_804b0ca4))fn_8028e630(self,F7aText_8020bb54(fn_8010a8fc(msg)),0,0);
 else if(fn_8015f65c(msg->id,&cache_804b0cac))fn_8028e630(self,F7aText_8020bb54(fn_8010a8fc(msg)),1,0);
 else if(fn_8015f65c(msg->id,&cache_804b0cb4))fn_8028e7e0(self,F7aText_8020bb54(fn_8010a8fc(msg)));
 else if(fn_8015f65c(msg->id,&cache_804b0cbc)){if(depth_804abb5c)fn_8028e8ec(self);}
 else if(fn_8015f65c(msg->id,&cache_804b0ce4))fn_8028e444(self);
 done:return fn_8016293c(self,msg);
}


