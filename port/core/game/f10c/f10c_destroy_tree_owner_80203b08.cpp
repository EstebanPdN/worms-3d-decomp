#include "w3d_ptr.h"
#line 1 "f10c_destroy_tree_owner_80203b08.cpp"
// Names, roles, types, qualifiers and layouts are inferred from original instructions.
extern "C" void fn_802134fc(Ptr32<void>);extern "C" void fn_80210990(Ptr32<void>,int);
extern "C" void fn_8035b2d4(Ptr32<void>,Ptr32<void>);extern "C" void fn_8035a3f8(Ptr32<void>,Ptr32<void>);extern "C" void fn_8035b8fc(Ptr32<void>,Ptr32<void>);extern "C" void fn_8035b8a4(Ptr32<void>,Ptr32<void>);extern "C" void fn_8035b84c(Ptr32<void>,Ptr32<void>);
extern Ptr32<void> vt_80418f88[];extern Ptr32<void> vt_80419038[];
struct F10c_80203b08_Iface{Ptr32<Ptr32<void>> table;};struct F10c_80203b08_Held{Ptr32<F10c_80203b08_Iface> p;~F10c_80203b08_Held(){if(p)((Ptr32<void (Ptr32<F10c_80203b08_Iface>)>)p->table[4])(p);}};
struct F10c_80203b08_Base{Ptr32<Ptr32<void>> table;char unknown[16];~F10c_80203b08_Base(){table=(Ptr32<Ptr32<void>>)vt_80419038;fn_80210990((Ptr32<char>)this+4,0);}};
template<int Size>struct F10c_80203b08_Entry{char unknown[Size];};
template<class T>struct F10c_80203b08_Vector{Ptr32<T> begin; Ptr32<T> end; Ptr32<T> capacity;int unknown;~F10c_80203b08_Vector(){Ptr32<T> last=end;for(Ptr32<T> p=begin;p!=last;++p){}if(begin)fn_802134fc(begin);}};
struct F10c_80203b08_Node{int unknown;Ptr32<F10c_80203b08_Node> parent; Ptr32<F10c_80203b08_Node> left; Ptr32<F10c_80203b08_Node> right;};
template<void (*Erase)(Ptr32<void>, Ptr32<void>)>struct F10c_80203b08_Tree{int unknown;Ptr32<F10c_80203b08_Node> header;int count;int unknown12;~F10c_80203b08_Tree(){if(count){Erase(this,header->parent);header->left=header;header->parent=0;header->right=header;count=0;}if(header)fn_802134fc(header);}};
struct F10c_80203b08_Owner:F10c_80203b08_Base{F10c_80203b08_Held held __attribute__((aligned(__alignof__(F10c_80203b08_Base))));int unknown24;F10c_80203b08_Vector<F10c_80203b08_Entry<64> > records;F10c_80203b08_Tree<fn_8035b84c> a;F10c_80203b08_Tree<fn_8035b8a4> b;F10c_80203b08_Tree<fn_8035b8fc> c;F10c_80203b08_Vector<F10c_80203b08_Entry<4> > words;F10c_80203b08_Tree<fn_8035a3f8> d;int unknown124;F10c_80203b08_Tree<fn_8035b2d4> e;char unknown144[8];~F10c_80203b08_Owner();static void operator delete(void*);};
F10c_80203b08_Owner::~F10c_80203b08_Owner(){table=(Ptr32<Ptr32<void>>)vt_80418f88;}



