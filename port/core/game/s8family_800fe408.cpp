#include "w3d_ptr.h"
#line 1 "s8family_800fe408.cpp"
struct s8_Message { unsigned short id; };
struct s8_Cache { int first,second; };
extern s8_Cache lbl_804af14c;
extern "C" int fn_8002aa48(Ptr32<void>,Ptr32<const s8_Message>);
extern "C" int fn_800fe4b4(Ptr32<void>);
extern "C" void fn_800fe4fc(Ptr32<void>);
extern "C" int fn_8015f65c(int,Ptr32<s8_Cache>);
extern "C" int fn_800fe5b0(Ptr32<void>);
extern "C" int s8_message_route_800fe408(Ptr32<void> self,Ptr32<const s8_Message> message) {
    int id=message->id;
    switch(id) {
    case 64:
        if(fn_8002aa48(self,message)>=0) {
            fn_800fe4b4(self);
            return 0;
        }
        return (int)0x80004005;
    case 66:
        fn_800fe4fc(self);
        break;
    default:
        if(fn_8015f65c(id,&lbl_804af14c)) fn_800fe5b0(self);
        break;
    }
    return fn_8002aa48(self,message);
}


