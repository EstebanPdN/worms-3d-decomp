// The ignored return type of virtual slot22 is an inferred ABI view.
// Partial resource, string and interface ownership views inferred from instructions.
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
struct F1pResourceText{
 F1pResourceText(const F1pResourceText &);char*text;F1pResourceText(const char*);~F1pResourceText(){fn_8020c5c4(this);fn_80341588(this);}};
struct F1pResourceIface{void**table;};
struct F1pResourceHeld{F1pResourceIface*p;F1pResourceHeld():p(0){}~F1pResourceHeld(){if(p)((void(*)(F1pResourceIface*))p->table[4])(p);}void assign(F1pResourceIface*other){if(other)((void(*)(F1pResourceIface*))other->table[3])(other);if(p)((void(*)(F1pResourceIface*))p->table[4])(p);p=other;}};
struct F1pResourceVec{float x,y,z;F1pResourceVec(){}F1pResourceVec(float a,float b,float c):x(a),y(b),z(c){}void set(float a,float b,float c){x=a;y=b;z=c;}};
struct F1pResourceKey{const char*text;F1pResourceKey(const char*p):text(p){}};
extern "C" int fn_8015adf4(F1pResourceText*,F1pResourceHeld*,unsigned char),fn_800fc1b0(F1pResourceKey*,F1pResourceHeld*);
extern "C" F1pResourceIface*fn_80343df4(F1pResourceIface*),*fn_8034357c(F1pResourceIface*);
inline void setVector(F1pResourceIface*p,int slot,const F1pResourceVec&v,int mode){((void(*)(F1pResourceIface*,const F1pResourceVec&,int))p->table[slot])(p,v,mode);}

struct F1pCursorOwner{char unknown[36];F1pResourceIface*main;char unknown40[16];F1pResourceHeld cursor;};
extern char cursor_803d87c4[];extern const float sx_803d87d8[],sy_803d87dc[],sz_803d87e0[];extern int depth_804abb60;
extern "C" void fn_802c4998(F1pCursorOwner*);
extern "C" void w3d_setup_cursor_802c4840(F1pCursorOwner*self){if(!self->cursor.p){F1pResourceVec scale(sx_803d87d8[0],sy_803d87dc[0],sz_803d87e0[0]);F1pResourceHeld found;int depth=depth_804abb60;{F1pResourceText tag(cursor_803d87c4);fn_8015adf4(&tag,&found,(unsigned char)(depth+31));}self->cursor.assign(fn_8034357c(found.p));F1pResourceIface*p=self->cursor.p;((int(*)(F1pResourceIface*,int))p->table[22])(p,1);setVector(self->cursor.p,21,scale,0);p=self->main;((void(*)(F1pResourceIface*,F1pResourceIface*,const char*))p->table[23])(p,self->cursor.p,0);fn_802c4998(self);}}
