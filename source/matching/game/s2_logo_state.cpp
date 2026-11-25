/* Spectator message and intro-logo state setup. */
extern "C" {
struct S2LogoVirtual { void **vtable; };
struct S2Logo { void *vtable; unsigned char pad04[24]; S2LogoVirtual *resource; unsigned int stamp; };
struct S2Spectator { unsigned char pad00[72]; void *vtable72; };
struct S2LogoService { void *vtable; unsigned char pad04[24]; unsigned int words[13]; unsigned int last; };
struct S2LogoString { char *text; unsigned int storage; };
struct S2LogoVector { float x, y, z; void set(float a, float b, float c) { x = a; y = b; z = c; } };
struct S2LogoContext { unsigned char pad00[48]; unsigned int stamp; };
int w3d_fn_800a8348(S2Spectator *, const char *, int);
int w3d_ctor_8015fef0(S2Logo *);
void w3d_base_destroy_8015ff2c(S2Logo *, int);
int w3d_auto_8015fb34(S2Logo *, unsigned short *);
void w3d_fn_801084b4(S2Logo *);
void w3d_string_from_text(S2LogoString *, const char *);
void w3d_string_base_finish(S2LogoString *);
void w3d_string_release(S2LogoString *);
void w3d_handle_set_name(S2LogoString *, S2LogoVirtual **, unsigned int);
S2LogoContext *w3d_engine_get_context();
int w3d_ctor_801628b0(S2LogoService *);
extern unsigned char w3d_obj_80410700[], w3d_obj_80410738[], w3d_obj_80410778[];
extern const char w3d_str_80399b90[], w3d_str_80399bbc[];
extern const float w3d_f32_80399bcc[], w3d_f32_80399bd0[], w3d_f32_80399bd4[];

S2Spectator *w3d_spectator_message_801081dc(S2Spectator *self)
{
    struct { unsigned int first, second; } scratch;
    w3d_fn_800a8348(self, w3d_str_80399b90, 19);
    self->vtable72 = w3d_obj_80410700;
    return self;
}


S2Logo *w3d_logo_construct_80108368(S2Logo *self)
{
    struct { unsigned int first, second; } scratch;
    w3d_ctor_8015fef0(self);
    self->resource = 0;
    self->vtable = w3d_obj_80410738;
    return self;
}


void w3d_logo_destroy_801083ac(S2Logo *self, int flags)
{
    self->vtable = w3d_obj_80410738;
    if (self->resource) ((void (*)(S2LogoVirtual *))self->resource->vtable[4])(self->resource);
    w3d_base_destroy_8015ff2c(self, flags);
}


int w3d_logo_dispatch_8010840c(S2Logo *self, unsigned short *message)
{
    switch (*message) {
    case 64:
        if (w3d_auto_8015fb34(self, message) >= 0) {
            w3d_fn_801084b4(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        if (self->resource) ((void (*)(S2LogoVirtual *))self->resource->vtable[4])(self->resource);
        self->resource = 0;
        return 0;
    default:
        return w3d_auto_8015fb34(self, message);
    }
}


#if 0 /* 2 attempts; vector local addressing and load scheduling differ */
void w3d_fn_801084b4(S2Logo *self)
{
    struct { S2LogoString name; S2LogoVector value; } local;
    w3d_string_from_text(&local.name, w3d_str_80399bbc);
    S2LogoString *name = &local.name;
    w3d_handle_set_name(name, &self->resource, 255);
    w3d_string_base_finish(name);
    w3d_string_release(name);
    local.value.set(w3d_f32_80399bcc[0], w3d_f32_80399bd0[0], w3d_f32_80399bd4[0]);
    ((void (*)(S2LogoVirtual *, S2LogoVector *, int))self->resource->vtable[21])(self->resource, &local.value, 0);
    self->stamp = w3d_engine_get_context()->stamp;
}
#endif


S2LogoService *w3d_service_construct_8010912c(S2LogoService *self)
{
    struct { unsigned int first, second; } scratch;
    w3d_ctor_801628b0(self);
    self->vtable = w3d_obj_80410778;
    self->words[0] = 0;
    self->words[1] = 0;
    self->words[2] = 0;
    self->words[3] = 0;
    self->words[4] = 0;
    self->words[5] = 0;
    self->words[6] = 0;
    self->words[7] = 0;
    self->words[8] = 0;
    self->words[9] = 0;
    self->words[10] = 0;
    self->words[11] = 0;
    self->words[12] = 0;
    self->last = 0;
    return self;
}

}
