#include "w3d_ptr.h"
#line 1 "f1p_categories_message_8027b8a0.cpp"
// Inferred message cache, property key and partial menu state.
struct F1pCatMsg{unsigned short id;};
struct F1pCatCache{int words[2];};
struct F1pCatKey{Ptr32<const char> text;template <class W3dU> F1pCatKey(Ptr32<W3dU> w3d_p) : F1pCatKey((const char *)w3d_p.get()) {}
 F1pCatKey(const char*p):text(p){}};
struct F1pCatMenu{char unknown[108];int reel1,reel2,reel3;};
extern "C" int fn_8016293c(Ptr32<F1pCatMenu>,Ptr32<F1pCatMsg>);
extern "C" int fn_8015f65c(unsigned short,Ptr32<F1pCatCache>);
extern "C" Ptr32<const char> fn_8010a8fc(Ptr32<F1pCatMsg>);
extern "C" int fn_802ef234(Ptr32<const char>,Ptr32<const char>);
extern "C" int fn_800fc230(Ptr32<F1pCatKey>,Ptr32<int>),fn_800fc43c(Ptr32<F1pCatKey>,int);
extern F1pCatCache cache_804b0b3c,cache_804b0b44,cache_804b0b4c,cache_804b0b54,cache_804b0b6c,cache_804b0b5c,cache_804b0b7c,cache_804b0b64,cache_804b0b74,cache_804b0b84;
extern char str_803ce964[],str_803ce970[],str_803ce97c[],str_803ce988[],str_803ce990[],str_803ce998[],str_803ce9a0[],str_803ce9b8[],str_803ce9c0[],str_803ce9c8[],str_803ce9cc[],str_803ce9d4[],str_803ce9dc[],str_803ce9f0[],str_803cea04[],str_803cea18[];
extern "C" void fn_8027bd04(Ptr32<F1pCatMenu>);
extern "C" void fn_8027be70(Ptr32<F1pCatMenu>);
extern "C" void fn_802814c4(Ptr32<F1pCatMenu>);
extern "C" void fn_80281d0c(Ptr32<F1pCatMenu>);
extern "C" void fn_8027eb24(Ptr32<F1pCatMenu>);
extern "C" void fn_8027e038(Ptr32<F1pCatMenu>);
extern "C" void fn_8027f9c0(Ptr32<F1pCatMenu>);
extern "C" void fn_8027fb34(Ptr32<F1pCatMenu>);
extern "C" void fn_8027fca8(Ptr32<F1pCatMenu>);
extern "C" void fn_8027ffdc(Ptr32<F1pCatMenu>);
extern "C" void fn_8027e1ec(Ptr32<F1pCatMenu>);
extern "C" void fn_8027c480(Ptr32<F1pCatMenu>,Ptr32<const char>);
extern "C" void fn_8027cc20(Ptr32<F1pCatMenu>,Ptr32<const char>);
extern "C" void fn_8027e390(Ptr32<F1pCatMenu>,Ptr32<const char>);
extern "C" void fn_80281ff0(Ptr32<F1pCatMenu>,Ptr32<const char>);
extern "C" void fn_8027ddc4(Ptr32<F1pCatMenu>,int),fn_80280124(Ptr32<F1pCatMenu>,int);
extern "C" int w3d_categories_message_8027b8a0(Ptr32<F1pCatMenu> self,Ptr32<F1pCatMsg> msg){
 switch(msg->id){case 64:if(fn_8016293c(self,msg)>=0){fn_8027bd04(self);return 0;}return (int)0x80004005;case 66:fn_8027be70(self);break;default:
 if(fn_8015f65c(msg->id,&cache_804b0b3c))fn_8027c480(self,fn_8010a8fc(msg));
 else if(fn_8015f65c(msg->id,&cache_804b0b44))fn_8027cc20(self,fn_8010a8fc(msg));
 else if(fn_8015f65c(msg->id,&cache_804b0b4c))fn_8027e390(self,fn_8010a8fc(msg));
 else if(fn_8015f65c(msg->id,&cache_804b0b54)){
 if(fn_802ef234(fn_8010a8fc(msg),str_803ce964)==0)fn_8027ddc4(self,0);
 else if(fn_802ef234(fn_8010a8fc(msg),str_803ce970)==0)fn_8027ddc4(self,4);
 else if(fn_802ef234(fn_8010a8fc(msg),str_803ce97c)==0)fn_8027ddc4(self,3);
 else if(fn_802ef234(fn_8010a8fc(msg),str_803ce988)==0)fn_802814c4(self);
 else if(fn_802ef234(fn_8010a8fc(msg),str_803ce990)==0)fn_80281d0c(self);
 else if(fn_802ef234(fn_8010a8fc(msg),str_803ce998)==0){F1pCatKey missionKey(str_803ce9a0);int mission;fn_800fc230(&missionKey,&mission);fn_80280124(self,mission);}
 }else if(fn_8015f65c(msg->id,&cache_804b0b6c))fn_8027eb24(self);
 else if(fn_8015f65c(msg->id,&cache_804b0b5c))fn_8027e038(self);
 else if(fn_8015f65c(msg->id,&cache_804b0b7c)){
 if(fn_802ef234(fn_8010a8fc(msg),str_803ce9b8)==0)fn_8027f9c0(self);
 else if(fn_802ef234(fn_8010a8fc(msg),str_803ce9c0)==0)fn_8027fb34(self);
 else if(fn_802ef234(fn_8010a8fc(msg),str_803ce9c8)==0)fn_8027fca8(self);
 else if(fn_802ef234(fn_8010a8fc(msg),str_803ce9cc)==0)fn_8027ffdc(self);
 }else if(fn_8015f65c(msg->id,&cache_804b0b64))fn_8027e1ec(self);
 else if(fn_8015f65c(msg->id,&cache_804b0b74))fn_80281ff0(self,fn_8010a8fc(msg));
 else if(fn_8015f65c(msg->id,&cache_804b0b84)){
 if(fn_802ef234(fn_8010a8fc(msg),str_803ce9d4)==0){
 F1pCatKey one(str_803ce9dc);fn_800fc230(&one,&self->reel1);
 F1pCatKey two(str_803ce9f0);fn_800fc230(&two,&self->reel2);
 F1pCatKey three(str_803cea04);fn_800fc230(&three,&self->reel3);
 }else if(fn_802ef234(fn_8010a8fc(msg),str_803cea18)==0){
 F1pCatKey one(str_803ce9dc);fn_800fc43c(&one,self->reel1);
 F1pCatKey two(str_803ce9f0);fn_800fc43c(&two,self->reel2);
 F1pCatKey three(str_803cea04);fn_800fc43c(&three,self->reel3);
 }}
 }
 return fn_8016293c(self,msg);
}


