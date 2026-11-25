#include "w3d_ptr.h"
#line 1 "d24d_worm_lights_80139a04.cpp"
// d24d: 0x80139a04 (312 bytes). Look up a worm's two light resources by name:
// format "WormLight.%d" and "WeaponLight.%d" with the worm id (+112) and resolve
// each through the resource table of 0x804b17ec (+116, virtual slot 50, kind 4).
// Both are kept retained in the graphic (+596, +600; the previous values are
// released), then the mesh (+28) gets the first through 0x80182410. The text
// buffer has an out-of-line variadic formatting constructor (0x803442b4); each
// lookup binds a temporary of it to a const reference. 0x80182408 ends in li r3,0
// and is declared with its status return.
struct d24d_Object { Ptr32<Ptr32<void>> vtable; };
struct d24d_Ptr {
    Ptr32<d24d_Object> value;
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((d24d_Object *)w3d_p.get()); }
 void operator=(d24d_Object *object) {
        if (object) ((Ptr32<void (Ptr32<d24d_Object>)>)object->vtable[3])(object);
        if (value) ((Ptr32<void (Ptr32<d24d_Object>)>)value->vtable[4])(value);
        value = object;
    }
};
struct d24d_Text_803442b4 {
    char text[32];
    template <class W3dU> d24d_Text_803442b4(Ptr32<W3dU> w3d_p) : d24d_Text_803442b4((const char *)w3d_p.get()) {}
 d24d_Text_803442b4(const char *, ...);
};
struct d24d_Resources {
    unsigned char unknown00[116];
    Ptr32<d24d_Object> table;                  // +116
};
struct d24d_WormGraphic {
    unsigned char unknown00[28];
    Ptr32<d24d_Object> mesh;                   // +28
    unsigned char unknown20[80];
    int id;                              // +112
    unsigned char unknown74[480];
    d24d_Ptr wormLight;                  // +596
    d24d_Ptr weaponLight;                // +600
};
extern Ptr32<d24d_Resources> d24d_resources_804b17ec;
extern const char d24d_worm_light_8039f6a0[];    // "WormLight.%d"
extern const char d24d_weapon_light_8039f6b0[];  // "WeaponLight.%d"
extern "C" int d24d_mesh_status_80182408(Ptr32<d24d_Object>);
extern "C" int d24d_mesh_set_resource_value_80182410(Ptr32<d24d_Object>, Ptr32<d24d_Object>);

extern "C" void d24d_worm_lights_80139a04(Ptr32<d24d_WormGraphic> self) {
    Ptr32<d24d_Object> worm; Ptr32<d24d_Object> weapon;
    {
        Ptr32<d24d_Object> table = d24d_resources_804b17ec->table;
        Ptr32<Ptr32<void>> vtable = table->vtable;
        const d24d_Text_803442b4 &name = d24d_Text_803442b4(d24d_worm_light_8039f6a0, self->id);
        worm = ((Ptr32<Ptr32<d24d_Object> (Ptr32<d24d_Object>, const d24d_Text_803442b4 &, int)>)vtable[50])(table, name, 4);
    }
    {
        Ptr32<d24d_Object> table = d24d_resources_804b17ec->table;
        Ptr32<Ptr32<void>> vtable = table->vtable;
        const d24d_Text_803442b4 &name = d24d_Text_803442b4(d24d_weapon_light_8039f6b0, self->id);
        weapon = ((Ptr32<Ptr32<d24d_Object> (Ptr32<d24d_Object>, const d24d_Text_803442b4 &, int)>)vtable[50])(table, name, 4);
    }
    self->wormLight = worm;
    self->weaponLight = weapon;
    d24d_mesh_status_80182408(self->mesh);
    d24d_mesh_set_resource_value_80182410(self->mesh, self->wormLight.value);
}


