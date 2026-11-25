// GWMP8P rev0 0x802c196c. Fits a box to named scene items: looks up the name
// (string parameter by value, destroyed in this function), walks the list
// and for each item not derived from the type at 0x80365c68 grows the bounds
// by its centre and half extent, then stores the middle and half size.
// Partial views; field roles are inferred.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *);
struct Str {
    char *p;
    Str(const Str &);
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned len() const { return *(unsigned short *)(p - 4); }
};
struct Vec {
    float x, y, z;
    Vec(const Vec &o) {
        float a = o.x, b = o.y, c = o.z;
        x = a;
        y = b;
        z = c;
    }
};
struct Type { char u0[20]; Type *parent; };
extern Type type_80365c68[];
inline bool derived(Type *t, Type *base) {
    while (t != base) {
        Type *parent = t->parent;
        if (t == parent)
            return false;
        t = parent;
    }
    return true;
}
struct Part;
struct PartVt { char u0[20]; Type *(*type)(Part *); };
struct Part { PartVt *vt; char u4[16]; Vec extent; Vec centre; };
struct List { char u0[24]; unsigned count; char u28[4]; Part *items[1]; };
struct Data { char u0[20]; List *list; };
struct Res;
struct ResVt { char u0[16]; void (*destroy)(Res *); };
struct Res { ResVt *vt; };
struct Handle {
    Res *r;
    Handle() { r = 0; }
    Handle(const Handle &);
    ~Handle() { if (r) r->vt->destroy(r); }
};
struct Key { const char *text; };
struct Box { char u0[52]; float x, y, w, h; };
extern "C" int fn_800fc1b0(Key *, Handle *);
extern "C" void *fn_80341584(Res *);
extern "C" Data *fn_801797b4(void *);
extern "C" void d27l_fit_box_to_items_802c196c(Box *self, Str name) {
    if (name.len()) {
        Handle h;
        Key k;
        k.text = name.p;
        if (fn_800fc1b0(&k, &h) < 0)
            return;
        List *list = fn_801797b4(fn_80341584(h.r))->list;
        int first = 1;
        float minX = 0.0f, maxX = minX, maxY = minX, minY = minX;
        unsigned count = list->count;
        Part **items = list->items;
        for (unsigned i = 0; i < count; i++) {
            Vec e = items[i]->extent;
            Vec c = items[i]->centre;
            if (!derived(items[i]->vt->type(items[i]), type_80365c68)) {
                float loX = c.x - e.x;
                float hiX = c.x + e.x;
                float hiY = c.y + e.y;
                float loY = c.y - e.y;
                if (loX > hiX) {
                    float t = loX;
                    loX = hiX;
                    hiX = t;
                }
                if (loY > hiY) {
                    float t = hiY;
                    hiY = loY;
                    loY = t;
                }
                if (first == 1) {
                    first = 0;
                    maxX = hiX;
                    minX = loX;
                    maxY = hiY;
                    minY = loY;
                }
                if (maxX < hiX)
                    maxX = hiX;
                if (minX > loX)
                    minX = loX;
                if (maxY < hiY)
                    maxY = hiY;
                if (minY > loY)
                    minY = loY;
            }
        }
        float halfX = (maxX - minX) * 0.5f;
        float halfY = (maxY - minY) * 0.5f;
                self->h = halfY;
        self->w = halfX;
        self->x = minX + halfX;
        self->y = minY + halfY;
    }
}
