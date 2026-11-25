// Names, roles, types, qualifiers and layouts are inferred from original instructions.
extern "C" void fn_8020c5c4(void*);extern "C" void fn_80341588(void*);extern "C" void fn_802134fc(void*);extern "C" void fn_80210990(void*,int);extern void*vt_80418df0[];extern void*vt_80418eb8[];
struct F10c_80200e5c_Iface{void**table;};struct F10c_80200e5c_Held{F10c_80200e5c_Iface*p;~F10c_80200e5c_Held(){if(p)((void(*)(F10c_80200e5c_Iface*))p->table[4])(p);}};
struct F10c_80200e5c_Text{char*text;~F10c_80200e5c_Text(){fn_8020c5c4(this);fn_80341588(this);}};
struct F10c_80200e5c_Base{void**table;char unknown[16];~F10c_80200e5c_Base(){table=(void**)vt_80418eb8;fn_80210990((char*)this+4,0);}};
template<int N>struct F10c_80200e5c_Entry{char unknown[N];};
template<class T>struct F10c_80200e5c_Vector{T*begin,*end,*capacity;int unknown;~F10c_80200e5c_Vector(){T*last=end;for(T*p=begin;p!=last;++p)p->~T();if(begin)fn_802134fc(begin);}};
struct F10c_80200e5c_Strings{F10c_80200e5c_Text*begin,*end,*capacity;int unknown;~F10c_80200e5c_Strings(){F10c_80200e5c_Text*last=end;for(F10c_80200e5c_Text*p=begin;p!=last;++p)p->~F10c_80200e5c_Text();if(begin)fn_802134fc(begin);}};
struct F10c_80200e5c_Owner:F10c_80200e5c_Base{F10c_80200e5c_Held held20;char unknown24[16];F10c_80200e5c_Held held40;F10c_80200e5c_Vector<F10c_80200e5c_Entry<12> > a;char unknown60[64];F10c_80200e5c_Vector<F10c_80200e5c_Entry<64> > b;F10c_80200e5c_Strings strings;~F10c_80200e5c_Owner();static void operator delete(void*);};
F10c_80200e5c_Owner::~F10c_80200e5c_Owner(){table=(void**)vt_80418df0;}

