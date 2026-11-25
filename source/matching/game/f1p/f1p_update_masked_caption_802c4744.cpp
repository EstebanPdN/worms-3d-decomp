// Inferred partial owner and native shared-text cleanup scopes.
extern "C" void fn_803426b8(void*),fn_8020c5c4(void*),fn_80341588(void*);
// Inferred partial owner and native shared-text cleanup scopes.
extern "C" void * fn_8020bdf4(void*,const char*,int);
struct F1pMaskedText_803426b8{
 F1pMaskedText_803426b8(const F1pMaskedText_803426b8 &);char*p;F1pMaskedText_803426b8();~F1pMaskedText_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
struct F1pMaskedView{char*p;};struct F1pMaskedIface{void**table;};struct F1pMaskedOwner{char unknown0[84];int active;char unknown88[156];F1pMaskedIface*caption;char unknown248[4];F1pMaskedView name,text;char unknown260[116];int mask;};extern "C" F1pMaskedIface*fn_80343580(F1pMaskedIface*);extern "C" int fn_8020c5cc(F1pMaskedView*);extern "C" int fn_8018c5b0(F1pMaskedIface*,const char*);extern char text_803d8764[];
inline void updateMasked(F1pMaskedOwner*s,F1pMaskedView*text,F1pMaskedIface*p){if(!*(unsigned short*)(text->p-4)){((void(*)(F1pMaskedIface*,int))s->caption->table[22])(s->caption,0);return;}if(s->mask){F1pMaskedText_803426b8 masked;fn_8020bdf4(&masked,text_803d8764,fn_8020c5cc(text));fn_8018c5b0(p,masked.p);}else fn_8018c5b0(p,text->p);((void(*)(F1pMaskedIface*,int))s->caption->table[22])(s->caption,1);}
extern "C" void w3d_update_masked_caption_802c4744(F1pMaskedOwner*s){if(s->active&&*(unsigned short*)(s->name.p-4)&&s->caption){F1pMaskedIface*p=fn_80343580(s->caption);updateMasked(s,&s->text,p);}}
