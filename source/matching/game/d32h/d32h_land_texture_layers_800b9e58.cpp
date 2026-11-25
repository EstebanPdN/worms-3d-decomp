// GWMP8P rev0 0x800b9e58. Loads the land texture layers: for each of 128
// layers loads up to five named textures into retained handles, resets each
// resource through virtual slot 88 and looks it up, treating the name NULL
// as no texture for the fourth and as the first texture for the fifth, then
// hands the five textures to the sink at 0x804b183c through the table at
// +2792. Class layouts are partial views; names are inferred.
struct Object;
struct ObjectVtable { void *unknown00[3]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVtable *vtable; };
inline void *Slot(Object *o, int off) { return *(void **)((char *)o->vtable + off); }
struct Ref {
    Object *p;
    Ref() { p = 0; }
    Ref(const Ref &);
    ~Ref() { if (p) p->vtable->release(p); }
    void operator=(Object *q) {
        if (q) q->vtable->retain(q);
        if (p) p->vtable->release(p);
        p = q;
    }
    void operator=(const Ref &o) {
        if (o.p) o.p->vtable->retain(o.p);
        if (p) p->vtable->release(p);
        p = o.p;
    }
};
struct Handle {
    Object *value;
    Handle() {}
    ~Handle() { if (value) value->vtable->release(value); }
private:
    Handle(const Handle &);
};
struct Name { char *text; const char *Text() const { return text; } unsigned short Length() const { return *(unsigned short *)(text - 4); } };
extern "C" int load_8015adf4(const Name *, Object **, unsigned char);
extern "C" Object *cast_8034357c(Object *);
extern "C" Object *lookup_80174074(Object *);
extern "C" int strcasecmp_802ef074(const char *, const char *);
extern "C" Object *service_8020b648();
extern char key_804143e0[];
extern const char none_803828d8[];
typedef int (*SetFn)(Object *, int);
typedef void (*ObjFn)(Object *, void *);
struct Sink { char unknown0[2792]; void **vt; };
typedef void (*AddFn)(Sink *, Object *, Object *, Object *, Object *, Object *);
extern Sink *sink_804b183c;
struct Layer { Name name[6]; };
struct Layers { Object *h[6]; };
struct Land { char unknown0[64]; Layer layers[128]; Layers res[128]; };
inline void Load(Name &n, Object *&slot) {
    Handle h;
    h.value = 0;
    load_8015adf4(&n, &h.value, 255);
    Object *o = cast_8034357c(h.value);
    if (o) o->vtable->retain(o);
    if (slot) slot->vtable->release(slot);
    slot = o;
}
extern "C" int d32h_land_texture_layers_800b9e58(Land *self) {
    Ref a, b, c, d, e, z;
    void *key = key_804143e0;
    Object *svc = service_8020b648();
    ((ObjFn)Slot(svc, 92))(svc, key);
    for (unsigned i = 0; i < 128; i++) {
        if (self->layers[i].name[0].Length()) {
            Load(self->layers[i].name[0], self->res[i].h[0]);
            ((SetFn)Slot(self->res[i].h[0], 88))(self->res[i].h[0], 0);
            a = lookup_80174074(self->res[i].h[0]);
        }
        if (self->layers[i].name[1].Length()) {
            Load(self->layers[i].name[1], self->res[i].h[1]);
            ((SetFn)Slot(self->res[i].h[1], 88))(self->res[i].h[1], 0);
            b = lookup_80174074(self->res[i].h[1]);
        }
        if (self->layers[i].name[2].Length()) {
            Load(self->layers[i].name[2], self->res[i].h[2]);
            ((SetFn)Slot(self->res[i].h[2], 88))(self->res[i].h[2], 0);
            c = lookup_80174074(self->res[i].h[2]);
        }
        int cmp = strcasecmp_802ef074(self->layers[i].name[3].Text(), none_803828d8);
        if (cmp) {
            if (self->layers[i].name[3].Length()) {
                Load(self->layers[i].name[3], self->res[i].h[3]);
                ((SetFn)Slot(self->res[i].h[3], 88))(self->res[i].h[3], 0);
                d = lookup_80174074(self->res[i].h[3]);
            }
        } else d = (Object *)0;
        if (strcasecmp_802ef074(self->layers[i].name[5].Text(), none_803828d8) == 0) e = a;
        else if (self->layers[i].name[5].Length()) {
            Load(self->layers[i].name[5], self->res[i].h[4]);
            ((SetFn)Slot(self->res[i].h[4], 88))(self->res[i].h[4], 0);
            e = lookup_80174074(self->res[i].h[4]);
        }
        ((AddFn)sink_804b183c->vt[3])(sink_804b183c, a.p, b.p, c.p, d.p, e.p);
    }
    return 0;
}
