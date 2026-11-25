// Names, roles, types, qualifiers and layouts are inferred from original instructions.
extern "C" void fn_802134fc(void*);extern "C" void fn_80210990(void*,int);
extern "C" void fn_8035b2d4(void*,void*);extern "C" void fn_8035a3f8(void*,void*);extern "C" void fn_8035b8fc(void*,void*);extern "C" void fn_8035b8a4(void*,void*);extern "C" void fn_8035b84c(void*,void*);
extern void*vt_80418f88[];extern void*vt_80419038[];
struct F10c_80203b08_Iface{void**table;};struct F10c_80203b08_Held{F10c_80203b08_Iface*p;~F10c_80203b08_Held(){if(p)((void(*)(F10c_80203b08_Iface*))p->table[4])(p);}};
struct F10c_80203b08_Base{void**table;char unknown[16];~F10c_80203b08_Base(){table=(void**)vt_80419038;fn_80210990((char*)this+4,0);}};
template<int Size>struct F10c_80203b08_Entry{char unknown[Size];};
template<class T>struct F10c_80203b08_Vector{T*begin,*end,*capacity;int unknown;~F10c_80203b08_Vector(){T*last=end;for(T*p=begin;p!=last;++p){}if(begin)fn_802134fc(begin);}};
struct F10c_80203b08_Node{int unknown;F10c_80203b08_Node*parent,*left,*right;};
template<void(*Erase)(void*,void*)>struct F10c_80203b08_Tree{int unknown;F10c_80203b08_Node*header;int count;int unknown12;~F10c_80203b08_Tree(){if(count){Erase(this,header->parent);header->left=header;header->parent=0;header->right=header;count=0;}if(header)fn_802134fc(header);}};
struct F10c_80203b08_Owner:F10c_80203b08_Base{F10c_80203b08_Held held;int unknown24;F10c_80203b08_Vector<F10c_80203b08_Entry<64> > records;F10c_80203b08_Tree<fn_8035b84c> a;F10c_80203b08_Tree<fn_8035b8a4> b;F10c_80203b08_Tree<fn_8035b8fc> c;F10c_80203b08_Vector<F10c_80203b08_Entry<4> > words;F10c_80203b08_Tree<fn_8035a3f8> d;int unknown124;F10c_80203b08_Tree<fn_8035b2d4> e;char unknown144[8];~F10c_80203b08_Owner();static void operator delete(void*);};
F10c_80203b08_Owner::~F10c_80203b08_Owner(){table=(void**)vt_80418f88;}

