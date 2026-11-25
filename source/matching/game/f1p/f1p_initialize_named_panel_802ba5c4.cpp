// Partial external panel/data views; callback identity is observed by address.
struct F1pNamedIface{void**table;};struct F1pNamedHeld{
 F1pNamedHeld(const F1pNamedHeld &);F1pNamedIface*p;F1pNamedHeld():p(0){}~F1pNamedHeld(){if(p)((void(*)(F1pNamedIface*))p->table[4])(p);}};
struct F1pNamedText{char*p;};struct F1pNamedKey{const char*p;F1pNamedKey(const char*t):p(t){}};
struct F1pNamedData{char unknown0[140];F1pNamedText resource;};struct F1pNamedOwner{char unknown0[40];F1pNamedData*data;char unknown44[172];unsigned handle;};struct F1pNamedContext{char unknown0[52];void*service;};
extern "C" F1pNamedContext*fn_80165254();extern "C" void fn_802b0b84(void*,void*,void*),fn_802ba710(void*),fn_802ba818(void*);
extern "C" int fn_802baca0(void *, void *);extern "C" int fn_800fc1b0(F1pNamedKey*,F1pNamedHeld*);extern "C" void fn_800fd62c(F1pNamedText*,void(*)(),void*,unsigned*);
extern "C" void w3d_initialize_named_panel_802ba5c4(F1pNamedOwner*s){fn_802b0b84((char*)s+28,s,fn_80165254()->service);F1pNamedHeld h;F1pNamedText*text=&s->data->resource;if(*(unsigned short*)(text->p-4)){F1pNamedKey key(text->p);if(fn_800fc1b0(&key,&h)>=0)fn_800fd62c(text,(void (*)())fn_802baca0,s,&s->handle);}fn_802ba710(s);fn_802ba818(s);}
