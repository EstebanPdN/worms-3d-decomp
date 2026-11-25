// Archive load of the SpriteSetGroup held reference. Slot offsets and +52
// owner layout are observed; the class name is structural.
struct Cc18bObject;
struct Cc18bObjectVtable {
    void *unknown[3];
    int (*retain)(Cc18bObject *);
    int (*release)(Cc18bObject *);
};
struct Cc18bObject { Cc18bObjectVtable *vt; };
struct Cc18bArchive;
struct Cc18bArchiveVtable {
    void *unknown[8];
    void (*reference)(Cc18bArchive *, void *, const char *);
};
struct Cc18bArchive { Cc18bArchiveVtable *vt; };
struct Cc18bSpriteOwner { unsigned char unknown[52]; Cc18bObject *group; };
struct Cc18bLocalRef {
    Cc18bObject *p;
    int unknown;
    Cc18bLocalRef() : p(0) {}
    ~Cc18bLocalRef() { if (p) p->vt->release(p); }
};
static inline void cc18b_set_ref(Cc18bObject **slot, Cc18bObject *value)
{
    if (value) value->vt->retain(value);
    if (*slot) (*slot)->vt->release(*slot);
    *slot = value;
}
extern "C" int cc18b_descriptor_load_80190538(Cc18bSpriteOwner *, Cc18bArchive *);
extern "C" const char cc18b_group_name_803a7b9c[];
extern "C" int w3d_cc18b_sprite_load_80188878(Cc18bSpriteOwner *self, Cc18bArchive *archive)
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
