struct s8_Message { unsigned short id; };
struct s8_Cache { int first,second; };
extern s8_Cache lbl_804af14c;
extern "C" int fn_8002aa48(void *,const s8_Message *);
extern "C" int fn_800fe4b4(void *);
extern "C" void fn_800fe4fc(void *);
extern "C" int fn_8015f65c(int,s8_Cache *);
extern "C" int fn_800fe5b0(void *);
extern "C" int s8_message_route_800fe408(void *self,const s8_Message *message) {
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
