struct s14_MeshContext {
    char pad0[28]; void *mesh; int field32; char pad36[4]; int property40;
    char pad44[36]; unsigned timestamp; int started, state88, disabled;
};
struct s14_GameState { char pad0[56]; int paused; };
struct s14_Manager { char pad0[188]; unsigned flags; };
struct s14_IndexedObject { char pad0[80]; char position[48]; int state128; };
extern "C" int fn_800a08b0(s14_MeshContext *,void *);
extern "C" int fn_800a0e2c(s14_MeshContext *,void *);
extern "C" int fn_800a12c0(s14_MeshContext *);
extern "C" int fn_800a12fc(s14_MeshContext *);
extern "C" int fn_800a14c4(s14_MeshContext *,int);
extern "C" int fn_800a14f4(s14_MeshContext *);
extern "C" int fn_800a1524(s14_MeshContext *);
extern "C" s14_IndexedObject *fn_800fc6dc(int);
extern "C" s14_GameState *fn_80165254();
extern "C" int fn_80178c48(void *);
extern "C" int fn_80181640(float,float,float,int,int,void *,int);
extern "C" int fn_80181ccc(void *,int);
extern "C" int fn_80343584(void *);
extern float lbl_80380864[],lbl_80380868[];
extern int lbl_804aac18, lbl_804aae44;
extern s14_Manager *lbl_804b1788;
extern "C" int s14_mesh_tick_typed_800a0340(s14_MeshContext *self,unsigned now) {
    if(self->state88==1) self->timestamp=now;
    if(now>self->timestamp+3500 && !self->started && !self->disabled && !fn_800a14f4(self) && !fn_800a1524(self) && !fn_80165254()->paused && !(lbl_804b1788->flags&4)) fn_800a12fc(self);
    int index=fn_80178c48((void *)self->property40);
    if(index!=-1) {
        s14_IndexedObject *object=fn_800fc6dc(index);
        if(object->state128!=10) fn_800a12c0(self);
        void *position=object->position;
        fn_800a08b0(self,position);
        fn_800a0e2c(self,position);
    } else fn_800a12c0(self);
    if(self->started && !self->disabled) {
        int mesh=fn_80343584(self->mesh);
        if(fn_80181ccc((void *)mesh,self->field32)) fn_80181640(lbl_80380864[0],lbl_80380868[0],lbl_80380868[0],mesh,lbl_804aac18,&self->field32,0);
    }
    if(fn_80165254()->paused || (lbl_804b1788->flags&4) || lbl_804aae44) fn_800a14c4(self,0);
    return 0;
}
