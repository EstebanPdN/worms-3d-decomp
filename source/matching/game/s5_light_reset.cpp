/* Releases held per-light resources and empties light index ranges. */
extern "C" {
struct S5ResetIface;
struct S5ResetVtable { void (*reserved[4])(); void (*release)(S5ResetIface *); };
struct S5ResetIface { S5ResetVtable *vtable; };
struct S5ResetEntry { unsigned char position[12]; S5ResetIface *light,*attachment; unsigned char unknown14[7]; unsigned char flag; unsigned char active; unsigned char rest[31]; };
struct S5ResetRange { S5ResetEntry *begin,*end; unsigned char rest[8]; };
struct S5ResetIndices { unsigned short *begin,*end,*capacity; };
struct S5ResetManager;
struct S5ResetManagerVtable { void (*reserved[49])(); void (*set)(S5ResetManager *,const char *,unsigned char); };
struct S5ResetManager { S5ResetManagerVtable *vtable; };
struct S5ResetContext { unsigned char reserved[116]; S5ResetManager *manager; };
extern S5ResetRange w3d_light_range_8043c384[];
extern S5ResetIndices w3d_light_unused_8043c394[];
extern void *w3d_light_source_804aada8;
extern S5ResetContext *w3d_light_context_804b17ec;
extern const char w3d_str_80382f88[];
void w3d_mesh_instance_reset_resource_value(S5ResetIface *);
int w3d_text_format_803442b4(char *,const char *,...);
void *memcpy(void *,const void *,unsigned,...);
static inline S5ResetEntry &s5_reset_entry(unsigned index) { return *(w3d_light_range_8043c384->begin+index); }
static inline S5ResetEntry *s5_reset_destroy(S5ResetEntry *begin,S5ResetEntry *end)
{
    for (S5ResetEntry *entry=begin;entry!=end;++entry) {
        if (entry->attachment) entry->attachment->vtable->release(entry->attachment);
        if (entry->light) entry->light->vtable->release(entry->light);
    }
    return begin;
}
static inline void s5_reset_clear(S5ResetRange *range) { range->end=s5_reset_destroy(range->begin,range->end); }
/* 0x800c04a4: 13 register-allocation/order differences remain after six attempts. */
#if 0
void w3d_light_reset_all_800c04a4(void)
{
    char name[32];
    w3d_light_source_804aada8=0;
    unsigned index=0;
    if ((unsigned)(w3d_light_range_8043c384->end-w3d_light_range_8043c384->begin)) do {
        if (s5_reset_entry(index).attachment)
            w3d_mesh_instance_reset_resource_value(s5_reset_entry(index).attachment);
        if (s5_reset_entry(index).light) {
            S5ResetManager *manager=w3d_light_context_804b17ec->manager;
            S5ResetManagerVtable *vtable=manager->vtable;
            w3d_text_format_803442b4(name,w3d_str_80382f88,index);
            vtable->set(manager,name,s5_reset_entry(index).flag);
        }
        S5ResetEntry *entry=&s5_reset_entry(index);
        S5ResetIface *replacement=0;
        if (entry->attachment) entry->attachment->vtable->release(entry->attachment);
        entry->attachment=replacement;
        entry=&s5_reset_entry(index);
        if (entry->light) entry->light->vtable->release(entry->light);
        entry->light=replacement;
        s5_reset_entry(index).active=0;
        ++index;
    } while (index < (unsigned)(w3d_light_range_8043c384->end-w3d_light_range_8043c384->begin));
    s5_reset_clear(w3d_light_range_8043c384);
    int bytes=(char*)w3d_light_unused_8043c394->end-(char*)w3d_light_unused_8043c394->begin;
    ((void (*)(void *,void *,int,...))memcpy)(w3d_light_unused_8043c394->begin,w3d_light_unused_8043c394->end,0);
    w3d_light_unused_8043c394->end=(unsigned short*)((char*)w3d_light_unused_8043c394->end-bytes);
}
#endif
}
