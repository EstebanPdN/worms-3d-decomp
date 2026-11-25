// d24d: 0x8013f348 (404 bytes). Show the surrender flag on a worm: when the worm
// graphic has no attachment (+164) yet, load the "SurrenderFlag" model into a
// handle (0x8015adf4), keep its mesh retained as the attachment, attach it to the
// given mesh (virtual +92, attachment id 0x804ab328) and pick the resource value
// +596 for "Prod" kinds, +600 otherwise. Then play the idle clip named by
// 0x804ab100 (control +492) and "DrawSurrender" (control +472) on that mesh.
// Same shapes as the admitted worm model d17d_worm_model_801385a4. The load name
// is a temporary bound to a const reference, which keeps its address in a saved
// register. The float literals form this function's pool at 0x8039fdb4.
extern "C" int strcmp(const char *, const char *);
extern "C" void d24d_string_init_8020c5c0(void *);
extern "C" unsigned short *d24d_string_header_80341884(void *);
// Shared text pointer as stored in resource records.
struct d24d_SharedText { char *text; };
// Shared engine string; constructor and release are out of line.
struct d24d_String {
 d24d_String(const d24d_String &);
    char *text;
    d24d_String(const char *);
    d24d_String(const d24d_SharedText &o) {
        d24d_string_init_8020c5c0(this);
        text = o.text;
        ++*d24d_string_header_80341884(this);
    }
    ~d24d_String();
};
extern "C" void d24d_string_finish_8020c5c4(d24d_String *);
extern "C" void d24d_string_release_80341588(d24d_String *);
inline d24d_String::~d24d_String() {
    d24d_string_finish_8020c5c4(this);
    d24d_string_release_80341588(this);
}
inline bool d24d_same(const char *a, const char *b) { return strcmp(a, b) == 0; }
inline bool d24d_differs(const char *a, const char *b) { return strcmp(a, b) != 0; }

struct d24d_Object;
struct d24d_Object { void **vtable; };
struct d24d_Vec3 {
    float x, y, z;
    d24d_Vec3(float ax, float ay, float az) { x = ax; y = ay; z = az; }
};
// Retaining reference (one pointer, not copyable).
struct d24d_Ref {
    d24d_Object *value;
    d24d_Ref(d24d_Object *object) { value = object; if (object) ((void (*)(d24d_Object *))object->vtable[3])(object); }
    ~d24d_Ref() { if (value) ((void (*)(d24d_Object *))value->vtable[4])(value); }
private:
    d24d_Ref(const d24d_Ref &);
};
// Retaining member pointer.
struct d24d_Ptr {
    d24d_Object *value;
    void operator=(d24d_Object *object) {
        if (object) ((void (*)(d24d_Object *))object->vtable[3])(object);
        if (value) ((void (*)(d24d_Object *))value->vtable[4])(value);
        value = object;
    }
};
struct d24d_Graphic {
    unsigned char unknown000[28];
    d24d_Object *mesh;                  // +28
    unsigned char unknown020[80];
    d24d_Object *worm;                  // +112
    unsigned char unknown074[48];
    d24d_Ptr attachment;                // +164
    unsigned char unknown0a8[304];
    int drawControl;                    // +472
    unsigned char unknown1dc[12];
    int control;                        // +488
    int flagControl;                    // +492
    unsigned char unknown1ec[100];
    int primaryValue;                   // +596
    int resourceValue;                  // +600
    unsigned char unknown25c[80];
    unsigned int mode;                  // +684
};
struct d24d_WormData { unsigned char unknown00[132]; int type; };
struct d24d_Resource {
    unsigned char unknown00[72];
    d24d_SharedText model;              // +72
    const char *animation;              // +76
    const char *idle;                   // +80
};
struct d24d_Name { char *text; };
extern "C" d24d_WormData *d24d_worm_data_800fc6dc(d24d_Object *);
extern "C" void d24d_resource_lookup_800fc330(const char **, d24d_Resource **);
extern "C" void s9_release_actor_inner_8013e458(void *);
extern "C" int d24d_handle_load_8015adf4(const d24d_String *, d24d_Object **, unsigned char);
extern "C" d24d_Object *d24d_mesh_of_80343584(d24d_Object *);
extern "C" int d24d_mesh_set_resource_value_80182410(d24d_Object *, int);
extern "C" void d24d_mode_enter_8013ef98(d24d_Graphic *);
extern "C" void d24d_mode_enter_8013efe8(d24d_Graphic *);
extern "C" int d24d_play_named_801359ec(d24d_Graphic *, d24d_Object *, const char *, int *, float, float, float);
extern "C" int d24d_check_control_8018179c(d24d_Object *, int, int);
inline d24d_Resource *d24d_resource_for(const char **key) {
    d24d_Resource *resource;
    d24d_resource_lookup_800fc330(key, &resource);
    return resource;
}
extern int d24d_attach_id_804ab328, d24d_attach_id_804ab32c;
extern const char *d24d_resource_table_803eb63c[];


extern int d24d_attach_id_804ab328;
extern const char *d24d_idle_804ab100;
extern const char d24d_flag_8039fd94[], d24d_draw_8039fda4[], d24d_prod_8039f5a0[];
extern "C" void d24d_worm_surrender_8013f348(d24d_Graphic *self, d24d_Object *mesh) {
    if (self->attachment.value == 0) {
        {
            const d24d_String &name = d24d_String(d24d_flag_8039fd94);
            d24d_Ref handle(0);
            d24d_handle_load_8015adf4(&name, &handle.value, 255);
            self->attachment = d24d_mesh_of_80343584(handle.value);
        }
        ((void (*)(d24d_Object *, d24d_Object *, int))mesh->vtable[23])(mesh, self->attachment.value, d24d_attach_id_804ab328);
        d24d_Object *info = ((d24d_Object *(*)(d24d_Object *))self->attachment.value->vtable[16])(self->attachment.value);
        d24d_Name *kind = ((d24d_Name *(*)(d24d_Object *))info->vtable[17])(info);
        if (d24d_same(kind->text, d24d_prod_8039f5a0))
            d24d_mesh_set_resource_value_80182410(self->attachment.value, self->primaryValue);
        else
            d24d_mesh_set_resource_value_80182410(self->attachment.value, self->resourceValue);
    }
    d24d_play_named_801359ec(self, mesh, d24d_idle_804ab100, &self->flagControl, 1.0f, 0.0f, 0.0f);
    d24d_play_named_801359ec(self, mesh, d24d_draw_8039fda4, &self->drawControl, 1.0f, -1.0f, 0.0f);
}
