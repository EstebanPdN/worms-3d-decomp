// (Worms 3D GameCube PAL, 0x801b25e8).
//
// Writes a readable dump of an object to the dumper's stream: a local
// formatting writer on the output at +40 prints the class name and address,
// then, walking the class chain from root to leaf, prints each property:
// array properties as name, count and elements (recursing for object
// elements, or through 0x801ef970 for plain ones), others as name = value
// (recursing for object values), with indent and closing lines. Takes the
// interface pointer (object at -4). Names are inferred.

struct Out { virtual void v0(); virtual void AddRef(); virtual void Release(); };
struct String { char *p; };
struct Writer;
extern Writer &endl(Writer &);
struct Writer {
    Out *out;
    unsigned base : 7;
    unsigned upper : 1;
    unsigned fill : 8;
    unsigned width : 5;
    unsigned rest : 11;
    Writer(Out *o) {
        out = o;
        if (out) out->AddRef();
        base = 10;
        upper = 0;
        fill = 0;
        width = 6;
    }
    ~Writer() { if (out) out->Release(); }
    Writer &operator<<(const String &s);
    Writer &operator<<(const char *s);
    Writer &operator<<(unsigned n);
    Writer &operator<<(Writer &(*m)(Writer &)) { return m(*this); }
};
extern "C" int w3d_format_into_80355a44(char *, const char *, ...);
struct Class;
struct Type;
extern "C" const char *w3d_auto_801ffea8(Class *);
extern "C" int w3d_auto_801fffc8(Type *);
struct Prop { const char *name; short offset; unsigned char b6, flags; Type *type; };
struct Item {
    Prop *prop;
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void print(Writer &, void *);
    virtual void v4(); virtual void v5();
    virtual void **get(void *, unsigned *);
};
struct ObjectItem {
    Prop *prop;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void **get(void *);
};
struct Object { virtual void v0(); virtual void v1(); virtual void v2(); virtual Class *GetClass(); };
struct ClassBase {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual unsigned Count();
};
struct Class : ClassBase {
    char pad[16];
    Class *parent;
    char pad24[24];
    struct Items { Item **v; Item *operator[](unsigned i) { return *(Item **)((char *)v + (i << 2)); } } items;
};
struct Dumper {
    char pad0[40];
    Out *out;
    char pad44[4];
    int limit;
    char pad52[8];
    String line;
};
extern "C" void w3d_k4b_writer_append_indent_801b2550(Dumper *);
extern "C" void w3d_s20_shrink_range_801b25ac(Dumper *);
extern "C" void w3d_d29e_print_array_801ef970(Item *, Writer *, void *, int, char *);

extern const char s_at[], s_fmt[], s_open[], s_count[], s_mid[], s_close[], s_eq[], s_end[];

extern "C" int w3d_d31e_dump_object_801b25e8(char *iface, Object *obj)
{
    if (obj) {
        Dumper *self = iface ? (Dumper *)(iface - 4) : 0;
        Writer w(self->out);
        Class *chain[32];
        char buf[16];
        Class *cls = obj->GetClass();
        int n = 0;
        Writer &a = w << self->line << w3d_auto_801ffea8(cls) << s_at;
        w3d_format_into_80355a44(buf, s_fmt, obj);
        a << buf << s_open << endl;
        w3d_k4b_writer_append_indent_801b2550(self);
        {
            Class *prev;
            do {
                chain[n] = cls;
                prev = cls;
                cls = cls->parent;
                n++;
            } while (cls != prev);
        }
        while (n != 0) {
            cls = chain[--n];
            unsigned count = cls->Count();
            for (unsigned i = 0; i < count; i++) {
                Item *item = cls->items[i];
                if (item->prop->flags & 1) {
                    unsigned total;
                    void **values = item->get(obj, &total);
                    w << self->line << item->prop->name << s_count << total << s_mid << endl;
                    if (w3d_auto_801fffc8(item->prop->type) == 24) {
                        w3d_k4b_writer_append_indent_801b2550(self);
                        for (unsigned j = 0; j < total; j++) w3d_d31e_dump_object_801b25e8(iface, (Object *)values[j]);
                        w3d_s20_shrink_range_801b25ac(self);
                    } else {
                        w3d_k4b_writer_append_indent_801b2550(self);
                        w << self->line;
                        w3d_d29e_print_array_801ef970(item, &w, obj, self->limit, self->line.p);
                        w3d_s20_shrink_range_801b25ac(self);
                        w << endl;
                    }
                    w << self->line << s_close << endl;
                } else {
                    w << self->line << item->prop->name << s_eq;
                    item->print(w, obj);
                    w << endl;
                    if (w3d_auto_801fffc8(item->prop->type) == 24) {
                        w3d_k4b_writer_append_indent_801b2550(self);
                        void **sub = ((ObjectItem *)item)->get(obj);
                        if (sub) w3d_d31e_dump_object_801b25e8(iface, (Object *)*sub);
                        w3d_s20_shrink_range_801b25ac(self);
                    }
                }
            }
        }
        w3d_s20_shrink_range_801b25ac(self);
        w << self->line << s_end << endl;
    }
    return 0;
}
