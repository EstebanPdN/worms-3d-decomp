struct s8_StopOwner { char pad0[4]; char descriptor[72]; void *handle; };
extern "C" int fn_800b01b0(void *,void *);
extern "C" int fn_800b0100(void *,int);
extern "C" void s8_guarded_stop_800e73f0(s8_StopOwner *self) {
    if(self->handle && fn_800b01b0(self->handle,self->descriptor)) {
        if(self->handle) fn_800b0100(self->handle,3);
        self->handle=0;
    }
}
