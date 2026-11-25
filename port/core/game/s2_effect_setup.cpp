#include "w3d_ptr.h"
#line 1 "s2_effect_setup.cpp"
/* Effect-state configuration and callback registration. */
extern "C" {
struct S2EffectState { unsigned char pad00[4]; unsigned char dirty; char w3d_tag_rest[3]; void touch() { dirty |= 2; } };
struct S2EffectObject { Ptr32<Ptr32<void>> vtable; S2EffectState state; unsigned char pad0c[12]; int value24, value28;
    void set24(int value) { value24 = value; state.touch(); }
    void set28(int value) { value28 = value; state.touch(); }
};
struct S2EffectRef {
    Ptr32<S2EffectObject> value;
    unsigned int reserved;
    S2EffectRef(Ptr32<S2EffectObject> w3d_p) : S2EffectRef((S2EffectObject *)w3d_p.get()) {}
 S2EffectRef(S2EffectObject *object) {
        value = object;
        if (object) ((Ptr32<void (Ptr32<S2EffectObject>)>)object->vtable[3])(object);
    }
    ~S2EffectRef() {
        if (value) ((Ptr32<void (Ptr32<S2EffectObject>)>)value->vtable[4])(value);
    }
};
struct S2EffectOwner { unsigned char pad00[52]; Ptr32<S2EffectObject> resource; unsigned char pad38[16]; float u, v; };
typedef Ptr32<int (Ptr32<S2EffectOwner>, Ptr32<S2EffectOwner>)> S2EffectCallback;
Ptr32<S2EffectObject> w3d_fn_8020b680(Ptr32<void>);
void w3d_fn_801ef174(Ptr32<S2EffectObject>, int, int, Ptr32<S2EffectObject>);
int w3d_fn_801d4544(Ptr32<S2EffectObject>, Ptr32<S2EffectObject>);
int w3d_fn_80105ac8(Ptr32<S2EffectOwner>, Ptr32<S2EffectOwner>);
int w3d_fn_80106118(Ptr32<S2EffectOwner>, Ptr32<S2EffectOwner>);
int w3d_fn_80106218(Ptr32<S2EffectOwner>, Ptr32<S2EffectOwner>);
extern Ptr32<S2EffectObject> w3d_obj_804af1e8;
extern unsigned char w3d_obj_80415cb0[], w3d_obj_80415c00[], w3d_obj_80417000[], w3d_obj_80362844[];
extern const float w3d_f32_80399918[];

int w3d_fn_80106118(Ptr32<S2EffectOwner> unused, Ptr32<S2EffectOwner> owner)
{
    Ptr32<S2EffectObject> resource = owner->resource;
    S2EffectRef temporary(w3d_fn_8020b680(w3d_obj_80415cb0));
    temporary.value->set28(0);
    temporary.value->set24(5);
    w3d_fn_801ef174(resource, 28, 3, temporary.value);
    Ptr32<S2EffectObject> previous = owner->resource;
    owner->resource = resource;
    if (resource) ((Ptr32<void (Ptr32<S2EffectObject>)>)resource->vtable[3])(resource);
    if (previous) ((Ptr32<void (Ptr32<S2EffectObject>)>)previous->vtable[4])(previous);
    return 0;
}


int w3d_fn_80106218(Ptr32<S2EffectOwner> unused, Ptr32<S2EffectOwner> owner)
{
    Ptr32<S2EffectObject> resource = owner->resource;
    S2EffectRef temporary(w3d_fn_8020b680(w3d_obj_80415c00));
    temporary.value->set24(1);
    w3d_fn_801d4544(resource, temporary.value);
    w3d_fn_801d4544(resource, w3d_obj_804af1e8);
    Ptr32<S2EffectObject> previous = owner->resource;
    owner->resource = resource;
    if (resource) ((Ptr32<void (Ptr32<S2EffectObject>)>)resource->vtable[3])(resource);
    if (previous) ((Ptr32<void (Ptr32<S2EffectObject>)>)previous->vtable[4])(previous);
    return 0;
}


void w3d_effect_register_80106530(Ptr32<S2EffectOwner> self, Ptr32<S2EffectObject> target)
{
    self->v = self->u = w3d_f32_80399918[0];
    S2EffectRef factory(w3d_fn_8020b680(w3d_obj_80417000));
    S2EffectRef callback(((Ptr32<Ptr32<S2EffectObject> (Ptr32<S2EffectObject>)>)factory.value->vtable[11])(factory.value));
    ((Ptr32<void (Ptr32<S2EffectObject>, Ptr32<void>, S2EffectCallback, int)>)callback.value->vtable[6])(callback.value, w3d_obj_80362844, w3d_fn_80105ac8, 0);
    ((Ptr32<void (Ptr32<S2EffectObject>, Ptr32<S2EffectObject>)>)factory.value->vtable[6])(factory.value, target);
}


void w3d_effect_register_8010663c(Ptr32<S2EffectOwner> self, Ptr32<S2EffectObject> target)
{
    S2EffectRef factory(w3d_fn_8020b680(w3d_obj_80417000));
    S2EffectRef callback(((Ptr32<Ptr32<S2EffectObject> (Ptr32<S2EffectObject>)>)factory.value->vtable[11])(factory.value));
    ((Ptr32<void (Ptr32<S2EffectObject>, Ptr32<void>, S2EffectCallback, int)>)callback.value->vtable[6])(callback.value, w3d_obj_80362844, w3d_fn_80106218, 0);
    ((Ptr32<void (Ptr32<S2EffectObject>, Ptr32<S2EffectObject>)>)factory.value->vtable[6])(factory.value, target);
}


void w3d_effect_register_80106734(Ptr32<S2EffectOwner> self, Ptr32<S2EffectObject> target)
{
    S2EffectRef factory(w3d_fn_8020b680(w3d_obj_80417000));
    S2EffectRef callback(((Ptr32<Ptr32<S2EffectObject> (Ptr32<S2EffectObject>)>)factory.value->vtable[11])(factory.value));
    ((Ptr32<void (Ptr32<S2EffectObject>, Ptr32<void>, S2EffectCallback, int)>)callback.value->vtable[6])(callback.value, w3d_obj_80362844, w3d_fn_80106118, 0);
    ((Ptr32<void (Ptr32<S2EffectObject>, Ptr32<S2EffectObject>)>)factory.value->vtable[6])(factory.value, target);
}

}


