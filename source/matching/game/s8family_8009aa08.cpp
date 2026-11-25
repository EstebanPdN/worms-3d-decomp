struct s8_Message { unsigned short id; };
struct s8_Cache { int first,second; };
extern s8_Cache lbl_804adfc4;
extern "C" int fn_8015fb34(void *,const s8_Message *);
extern "C" int fn_8009af20(void *);
extern "C" int fn_8009af9c(void *);
extern "C" int fn_8015f65c(int,s8_Cache *);
extern "C" int fn_8015fd1c(void *);
extern "C" int s8_message_route_8009aa08(void *self,const s8_Message *message) {
    int id=message->id;
    switch(id) {
    case 64:
        if(fn_8015fb34(self,message)>=0) {
            fn_8009af20(self);
            return 0;
        }
        return (int)0x80004005;
    case 66:
        fn_8009af9c(self);
        break;
    default:
        if(fn_8015f65c(id,&lbl_804adfc4)) fn_8015fd1c(self);
        break;
    }
    return fn_8015fb34(self,message);
}
