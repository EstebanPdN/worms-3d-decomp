typedef unsigned int u32;
struct Vec { float x,y,z; Vec(const Vec &v) { float a=v.x, b=v.y, c=v.z; x=a; z=c; y=b; } };
struct State { char pad[20]; int elapsed; Vec pos; };
struct Context { char pad[52]; int delta; };
struct Message { char pad[8]; int type; char pad2[4]; Vec pos; };
extern "C" Context *fn_80165254();
extern "C" void *fn_801613f0(void *, int);
extern "C" Message *fn_80131a84(void *);
extern "C" void fn_8016239c(Message *);
extern "C" void *lbl_804b1754;
extern "C" int terra_only_a8_message_8002165c(State *s) {
    s->elapsed += fn_80165254()->delta;
    Message *m = fn_80131a84(fn_801613f0(lbl_804b1754, 236));
    m->type = 4;
    Vec temp = s->pos;
    u32 *src = (u32 *)&temp;
    u32 *dst = (u32 *)&m->pos;
    u32 v0=src[0];
    u32 v1=src[1];
    u32 v2=src[2];
    dst[0]=v0;
    dst[2]=v2;
    dst[1]=v1;
    fn_8016239c(m);
    return 0;
}
