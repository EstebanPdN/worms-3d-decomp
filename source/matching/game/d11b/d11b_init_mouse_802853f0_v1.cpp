// Partial registry/name-cache views. The two observed vectors are separate
// original objects; neither registry nor globals are owned by this unit.
struct d11b_Mouse;
struct d11b_MouseRegistry;
struct d11b_CachedName { unsigned int state; const char *text; };
struct d11b_MouseVector { float x,y,z; d11b_MouseVector(float a,float b,float c):x(a),y(b),z(c) {} };
inline void *operator new(unsigned int,void *place) { return place; }
extern "C" d11b_Mouse *d11b_create_mouse_80284ca0();
extern "C" d11b_MouseRegistry *d11b_init_registry_80160038(d11b_MouseRegistry *,const char *const *,const void *,d11b_Mouse *(*)(),unsigned int,unsigned int);
extern "C" d11b_CachedName *d11b_init_cached_name_8015f518(d11b_CachedName *,const char *);
extern unsigned char d11b_registry_80368788[],d11b_base_type_803617d0[];
extern const char *const d11b_mouse_name_803eb320[];
extern const char d11b_mouse_moved_803cf388[],d11b_mouse_captured_803cf39c[];
extern d11b_CachedName d11b_moved_name_804b0b8c,d11b_captured_name_804b0b94;
extern d11b_MouseVector d11b_mouse_min_804668d0,d11b_mouse_max_804668dc;
extern "C" void d11b_init_mouse_802853f0(int initialize,int priority) {
    if (priority==0xffff && initialize) {
        d11b_init_registry_80160038(reinterpret_cast<d11b_MouseRegistry *>(d11b_registry_80368788),d11b_mouse_name_803eb320,d11b_base_type_803617d0,d11b_create_mouse_80284ca0,9,0);
        d11b_init_cached_name_8015f518(&d11b_moved_name_804b0b8c,d11b_mouse_moved_803cf388);
        d11b_init_cached_name_8015f518(&d11b_captured_name_804b0b94,d11b_mouse_captured_803cf39c);
        new (&d11b_mouse_min_804668d0) d11b_MouseVector(-320.0f,-240.0f,0.0f);
        new (&d11b_mouse_max_804668dc) d11b_MouseVector(320.0f,240.0f,0.0f);
    }
}
