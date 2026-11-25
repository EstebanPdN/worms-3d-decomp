#include "w3d_ptr.h"
#line 1 "cc18b_sprite_load_80188878.cpp"
// Archive load of the SpriteSetGroup held reference. Slot offsets and +52
// owner layout are observed; the class name is structural.
struct Cc18bObject;
struct Cc18bObjectVtable {
    Ptr32<void> unknown[3];
    Ptr32<int (Ptr32<Cc18bObject>)> retain;
    Ptr32<int (Ptr32<Cc18bObject>)> release;
};
struct Cc18bObject { Ptr32<Cc18bObjectVtable> vt; };
struct Cc18bArchive;
struct Cc18bArchiveVtable {
    Ptr32<void> unknown[8];
    Ptr32<void (Ptr32<Cc18bArchive>, Ptr32<void>, Ptr32<const char>)> reference;
};
struct Cc18bArchive { Ptr32<Cc18bArchiveVtable> vt; };
struct Cc18bSpriteOwner { unsigned char unknown[52]; Ptr32<Cc18bObject> group; };
struct Cc18bLocalRef {
    Ptr32<Cc18bObject> p;
    int unknown;
    Cc18bLocalRef() : p(0) {}
    ~Cc18bLocalRef() { if (p) p->vt->release(p); }
};
static inline void cc18b_set_ref(Ptr32<Ptr32<Cc18bObject>> slot, Ptr32<Cc18bObject> value)
{
    if (value) value->vt->retain(value);
    if (*slot) (*slot)->vt->release(*slot);
    *slot = value;
}
extern "C" int cc18b_descriptor_load_80190538(Ptr32<Cc18bSpriteOwner>, Ptr32<Cc18bArchive>);
extern "C" const char cc18b_group_name_803a7b9c[];
extern "C" int w3d_cc18b_sprite_load_80188878(Ptr32<Cc18bSpriteOwner> self, Ptr32<Cc18bArchive> archive)
{
    int result = cc18b_descriptor_load_80190538(self, archive);
    if (result >= 0) {
        {
            Cc18bLocalRef group;
            archive->vt->reference(archive, &group.p, cc18b_group_name_803a7b9c);
            cc18b_set_ref(&self->group, group.p);
        }
        result = (int)0x80004001;
    }
    return result;
}


