struct s8_Message { unsigned short id; };
extern "C" int fn_8016293c(void *,const s8_Message *);
extern "C" int fn_80098d94(void *);
extern "C" int s8_message_initialize_80098c88(void *self,const s8_Message *message) {
    if(message->id==64) {
        if(fn_8016293c(self,message)>=0) {
            fn_80098d94(self);
            return 0;
        }
        return (int)0x80004005;
    }
    return fn_8016293c(self,message);
}
