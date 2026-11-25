// Inferred32-byte owner and vector views, uninstantiated here.
// Factory8020a9a8 allocates32B; constructor8020aad0 initializes through31.
extern "C" void fn_802134fc(void*);extern "C" void fn_80210990(void*,int);extern void*vt_80419430[],*vt_804181c0[];
struct F16bI180{void**table;};struct F16bV180{F16bI180**begin,**end,**capacity;~F16bV180(){if(begin)fn_802134fc(begin);}int size()const{return end-begin;}F16bI180*operator[](int i){return *(F16bI180**)((char*)begin+(i<<2));}};
struct F16bB180{void**table;unsigned node[4];~F16bB180(){table=vt_804181c0;fn_80210990(node,0);}};
struct F16bO180:F16bB180{F16bV180 held;~F16bO180();static void operator delete(void*);};
F16bO180::~F16bO180(){table=vt_80419430;for(int i=0,n=held.size();i<n;++i){F16bI180*p=held[i];((void(*)(F16bI180*))p->table[4])(p);}}
