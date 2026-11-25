// Observed pool-entry update at 0x80264348. Names and layouts inferred.
// The empty local object preserves the original stack reservation; no assembly.
// Constants remain original external data, not owned by this source unit.
struct Vec2 { float x,y; };
extern "C" void *fn_8015ae3c(void *);
extern "C" void *fn_80343808(void *);
extern "C" int fn_80171ee0(void *,int);
extern "C" void *fn_80171fa0(void *);
extern "C" void fn_8020c5c4(void *);
extern "C" void fn_80341588(void *);
extern float value_803cb280[];
extern float value_803cb284[];
extern "C" void w3d_pool_write_scaled_entry_80264348(void *name,int index,float value) {
    struct Pad { int x,y; Pad() {} ~Pad() {} }; Pad padding;
    void *pool=fn_80343808(fn_8015ae3c(name));
    fn_80171ee0(pool,79);
    void *entries=fn_80171fa0(pool);
    Vec2 pair; pair.y=value*value_803cb280[0]; pair.x=value_803cb284[0];
    *(float *)((char *)entries+index*8)=pair.x;
    *(float *)((char *)entries+index*8+4)=pair.y;
    fn_8020c5c4(name);
    fn_80341588(name);
}
