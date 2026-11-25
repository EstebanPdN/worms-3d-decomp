#include "w3d_ptr.h"
#line 1 "f1p_setup_cursor_802c4840.cpp"
// The ignored return type of virtual slot22 is an inferred ABI view.
// Partial resource, string and interface ownership views inferred from instructions.
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
struct F1pResourceText{
 F1pResourceText(const F1pResourceText &);Ptr32<char> text;template <class W3dU> F1pResourceText(Ptr32<W3dU> w3d_p) : F1pResourceText((const char *)w3d_p.get()) {}
 F1pResourceText(const char*);~F1pResourceText(){fn_8020c5c4(this);fn_80341588(this);}};
struct F1pResourceIface{Ptr32<Ptr32<void>> table;};
struct F1pResourceHeld{Ptr32<F1pResourceIface> p;F1pResourceHeld():p(0){}~F1pResourceHeld(){if(p)((Ptr32<void (Ptr32<F1pResourceIface>)>)p->table[4])(p);}void assign(Ptr32<F1pResourceIface> other){if(other)((Ptr32<void (Ptr32<F1pResourceIface>)>)other->table[3])(other);if(p)((Ptr32<void (Ptr32<F1pResourceIface>)>)p->table[4])(p);p=other;}};
struct F1pResourceVec{float x,y,z;F1pResourceVec(){}F1pResourceVec(float a,float b,float c):x(a),y(b),z(c){}void set(float a,float b,float c){x=a;y=b;z=c;}};
struct F1pResourceKey{Ptr32<const char> text;template <class W3dU> F1pResourceKey(Ptr32<W3dU> w3d_p) : F1pResourceKey((const char *)w3d_p.get()) {}
 F1pResourceKey(const char*p):text(p){}};
extern "C" int fn_8015adf4(Ptr32<F1pResourceText>,Ptr32<F1pResourceHeld>,unsigned char),fn_800fc1b0(Ptr32<F1pResourceKey>,Ptr32<F1pResourceHeld>);
extern "C" Ptr32<F1pResourceIface> fn_80343df4(Ptr32<F1pResourceIface>); Ptr32<F1pResourceIface> fn_8034357c(Ptr32<F1pResourceIface>);
inline void setVector(Ptr32<F1pResourceIface> p,int slot,const F1pResourceVec&v,int mode){((Ptr32<void (Ptr32<F1pResourceIface>, const F1pResourceVec &, int)>)p->table[slot])(p,v,mode);}

struct F1pCursorOwner{char unknown[36];Ptr32<F1pResourceIface> main;char unknown40[16];F1pResourceHeld cursor;};
extern char cursor_803d87c4[];extern const float sx_803d87d8[],sy_803d87dc[],sz_803d87e0[];extern int depth_804abb60;
extern "C" void fn_802c4998(Ptr32<F1pCursorOwner>);
extern "C" void w3d_setup_cursor_802c4840(Ptr32<F1pCursorOwner> self){if(!self->cursor.p){F1pResourceVec scale(sx_803d87d8[0],sy_803d87dc[0],sz_803d87e0[0]);F1pResourceHeld found;int depth=depth_804abb60;{F1pResourceText tag(cursor_803d87c4);fn_8015adf4(&tag,&found,(unsigned char)(depth+31));}self->cursor.assign(fn_8034357c(found.p));Ptr32<F1pResourceIface> p=self->cursor.p;((Ptr32<int (Ptr32<F1pResourceIface>, int)>)p->table[22])(p,1);setVector(self->cursor.p,21,scale,0);p=self->main;((Ptr32<void (Ptr32<F1pResourceIface>, Ptr32<F1pResourceIface>, Ptr32<const char>)>)p->table[23])(p,self->cursor.p,0);fn_802c4998(self);}}


