struct K7aString;
extern "C" void * w3d_string_from_text(K7aString *string, const char *text);
extern "C" void w3d_string_base_finish(K7aString *string);
extern "C" void w3d_string_release(K7aString *string);
struct K7aString {
    char *text;
    int unused;
    K7aString() {}
    ~K7aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct K7aVec { float x, y, z; };
static inline void k7a_vec_set(K7aVec *v, float a, float b, float c) { v->x = a; v->y = b; v->z = c; }
struct K7aLogoTable { void *slots[21]; void (*set_position)(void *self, K7aVec *position, int flags); };
struct K7aLogoResource { K7aLogoTable *vtable; };
struct K7aEngineContext { char pad0[48]; unsigned int tick; };
struct K7aLogo { char pad0[28]; K7aLogoResource *resource; unsigned int tick; };
extern "C" char w3d_str_80399bbc[];
extern "C" const float w3d_f32_80399bcc[];
extern "C" const float w3d_f32_80399bd0[];
extern "C" const float w3d_f32_80399bd4[];
extern "C" void * w3d_handle_set_name(K7aString *name, void *handle, unsigned int flags);
extern "C" K7aEngineContext *w3d_engine_get_context();

extern "C" void w3d_k7a_logo_init_801084b4(K7aLogo *self)
{
    {
        K7aString name;
        w3d_string_from_text(&name, w3d_str_80399bbc);
        w3d_handle_set_name(&name, &self->resource, 255);
    }
    K7aVec position;
    K7aVec *p = &position;
    k7a_vec_set(p, w3d_f32_80399bcc[0], w3d_f32_80399bd0[0], w3d_f32_80399bd4[0]);
    self->resource->vtable->set_position(self->resource, p, 0);
    self->tick = w3d_engine_get_context()->tick;
}
