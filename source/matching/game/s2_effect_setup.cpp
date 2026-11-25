/* Effect-state configuration and callback registration. */
extern "C" {
struct S2EffectState { unsigned char pad00[7]; unsigned char dirty; void touch() { dirty |= 2; } };
struct S2EffectObject { void **vtable; S2EffectState state; unsigned char pad0c[12]; int value24, value28;
    void set24(int value) { value24 = value; state.touch(); }
    void set28(int value) { value28 = value; state.touch(); }
};
struct S2EffectRef {
    S2EffectObject *value;
    unsigned int reserved;
    S2EffectRef(S2EffectObject *object) {
        value = object;
        if (object) ((void (*)(S2EffectObject *))object->vtable[3])(object);
    }
    ~S2EffectRef() {
        if (value) ((void (*)(S2EffectObject *))value->vtable[4])(value);
    }
};
struct S2EffectOwner { unsigned char pad00[52]; S2EffectObject *resource; unsigned char pad38[16]; float u, v; };
typedef int (*S2EffectCallback)(S2EffectOwner *, S2EffectOwner *);
S2EffectObject *w3d_fn_8020b680(void *);
void w3d_fn_801ef174(S2EffectObject *, int, int, S2EffectObject *);
int w3d_fn_801d4544(S2EffectObject *, S2EffectObject *);
int w3d_fn_80105ac8(S2EffectOwner *, S2EffectOwner *);
int w3d_fn_80106118(S2EffectOwner *, S2EffectOwner *);
int w3d_fn_80106218(S2EffectOwner *, S2EffectOwner *);
extern S2EffectObject *w3d_obj_804af1e8;
extern unsigned char w3d_obj_80415cb0[], w3d_obj_80415c00[], w3d_obj_80417000[], w3d_obj_80362844[];
extern const float w3d_f32_80399918[];

int w3d_fn_80106118(S2EffectOwner *unused, S2EffectOwner *owner)
{
    S2EffectObject *resource = owner->resource;
    S2EffectRef temporary(w3d_fn_8020b680(w3d_obj_80415cb0));
    temporary.value->set28(0);
    temporary.value->set24(5);
    w3d_fn_801ef174(resource, 28, 3, temporary.value);
    S2EffectObject *previous = owner->resource;
    owner->resource = resource;
    if (resource) ((void (*)(S2EffectObject *))resource->vtable[3])(resource);
    if (previous) ((void (*)(S2EffectObject *))previous->vtable[4])(previous);
    return 0;
}


int w3d_fn_80106218(S2EffectOwner *unused, S2EffectOwner *owner)
{
    S2EffectObject *resource = owner->resource;
    S2EffectRef temporary(w3d_fn_8020b680(w3d_obj_80415c00));
    temporary.value->set24(1);
    w3d_fn_801d4544(resource, temporary.value);
    w3d_fn_801d4544(resource, w3d_obj_804af1e8);
    S2EffectObject *previous = owner->resource;
    owner->resource = resource;
    if (resource) ((void (*)(S2EffectObject *))resource->vtable[3])(resource);
    if (previous) ((void (*)(S2EffectObject *))previous->vtable[4])(previous);
    return 0;
}


void w3d_effect_register_80106530(S2EffectOwner *self, S2EffectObject *target)
{
    self->v = self->u = w3d_f32_80399918[0];
    S2EffectRef factory(w3d_fn_8020b680(w3d_obj_80417000));
    S2EffectRef callback(((S2EffectObject *(*)(S2EffectObject *))factory.value->vtable[11])(factory.value));
    ((void (*)(S2EffectObject *, void *, S2EffectCallback, int))callback.value->vtable[6])(callback.value, w3d_obj_80362844, w3d_fn_80105ac8, 0);
    ((void (*)(S2EffectObject *, S2EffectObject *))factory.value->vtable[6])(factory.value, target);
}


void w3d_effect_register_8010663c(S2EffectOwner *self, S2EffectObject *target)
{
    S2EffectRef factory(w3d_fn_8020b680(w3d_obj_80417000));
    S2EffectRef callback(((S2EffectObject *(*)(S2EffectObject *))factory.value->vtable[11])(factory.value));
    ((void (*)(S2EffectObject *, void *, S2EffectCallback, int))callback.value->vtable[6])(callback.value, w3d_obj_80362844, w3d_fn_80106218, 0);
    ((void (*)(S2EffectObject *, S2EffectObject *))factory.value->vtable[6])(factory.value, target);
}


void w3d_effect_register_80106734(S2EffectOwner *self, S2EffectObject *target)
{
    S2EffectRef factory(w3d_fn_8020b680(w3d_obj_80417000));
    S2EffectRef callback(((S2EffectObject *(*)(S2EffectObject *))factory.value->vtable[11])(factory.value));
    ((void (*)(S2EffectObject *, void *, S2EffectCallback, int))callback.value->vtable[6])(callback.value, w3d_obj_80362844, w3d_fn_80106118, 0);
    ((void (*)(S2EffectObject *, S2EffectObject *))factory.value->vtable[6])(factory.value, target);
}

}
