/* Observed reel movement, activation, and pointer hit testing. */
extern "C" {
#define FIELD(p,t,o) (*(t *)((char *)(p)+(o)))
struct Reel { int mode; char pad[68]; };
struct Pot { char pad[268]; Reel reels[11]; char gap[256]; unsigned current[3]; unsigned target[3]; };
int w3d_fn_802aa8a4(void *, int);
void w3d_fn_802b0990(void *);
void w3d_fn_802b1258(void *);
int w3d_auto_802ab5c0(void *,float,float);
extern const float w3d_f32_803d69b4[];
extern const float w3d_f32_803d69b8[];
extern const float w3d_f32_803d69bc[];
extern const float w3d_f32_803d69c0[];
#if 0 /* Direction arithmetic and return register allocation differ. */
int w3d_s4_wormpot_rotation_direction(void *self, unsigned reel, unsigned span)
{
    unsigned target=((Pot *)self)->target[reel];
    unsigned current=((Pot *)self)->current[reel];
    int result;
    if(current<target) goto lower;
    result=2;
    if(current-target < span-current+target) goto done;
    return 1;
lower:
    result=1;
    if(target-current < span-target+current) goto done;
    return 2;
done:
    return result;
}
#endif

void w3d_s4_wormpot_start(void *self)
{
    if((FIELD(self,unsigned,1340)&3)==0) {
        int mode=((Pot *)self)->reels[FIELD(self,unsigned,1072)].mode;
        if(mode==0) {
            if(FIELD(self,int,140)) w3d_fn_802aa8a4(self,10);
            else w3d_fn_802aa8a4(self,1);
        } else w3d_fn_802aa8a4(self,mode);
    }
}
void w3d_s4_wormpot_stop(void *self)
{
    if((FIELD(self,unsigned,1340)&3)==0) {
        FIELD(self,int,1380)=((Pot *)self)->reels[FIELD(self,unsigned,1072)].mode;
        w3d_fn_802aa8a4(self,0);
    }
}
#if 0 /* Activation arguments occupy reversed saved registers after three checks. */
void w3d_s4_wormpot_set_active(void *self,int active)
{
    if(active!=FIELD(self,int,176)) {
        w3d_fn_802b0990((char *)self+28);
        if(active) {
            void *config=FIELD(self,void *,40);
            void *name=FIELD(config,void *,156);
            if(FIELD(name,unsigned short,-4) && ((FIELD(config,unsigned char,11)^4)&4) && FIELD(self,int,140)) w3d_fn_802b1258(name);
            w3d_s4_wormpot_start(self);
        } else w3d_s4_wormpot_stop(self);
    }
}
#endif
#if 0 /* The original reloads the first argument before the mode query. */
int w3d_s4_wormpot_pointer(void *self,float x,float y)
{
    int mode;
    if(y<*w3d_f32_803d69b4 || y>*w3d_f32_803d69b8 || x<*w3d_f32_803d69bc || x>*w3d_f32_803d69c0 || (mode=w3d_auto_802ab5c0(self,x,y))==0) return 0;
    if(FIELD(self,int,176)) w3d_fn_802aa8a4(self,mode);
    return 1;
}
#endif
}
