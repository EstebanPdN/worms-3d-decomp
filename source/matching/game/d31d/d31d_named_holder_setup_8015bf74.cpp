// GWMP8P rev0 0x8015bf74. Setup of a named resource holder. Names are inferred;
// virtual slots are reference-ABI observations.
#pragma interface
extern "C" { struct String; void string_finish_8020c5c4(String *); void string_release_80341588(String *); }
struct String { void *rep; String(const char *); String(const String &); ~String() { string_finish_8020c5c4(this); string_release_80341588(this); } };
String make_80210958();
struct Service {
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual int set(const String &);
};
struct Entry {
    virtual void s2();
    virtual void retain();
    virtual void release();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void put(int);
    virtual void s14();
    virtual int get(int);
};
struct Base {
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual int apply(const String &);
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual int finish();
};
struct Ref { Entry *p; void set(Entry *e) { if (e) e->retain(); if (p) p->release(); p = e; } };
extern "C" Service *service_8020b648();
extern "C" Entry *forward_8020b680(void *);
extern "C" Entry *singleton_8020b884();
extern "C" void set_singleton_8020b960(Entry *);
extern "C" String *string_assign_8020bd38(String *, const char *);
extern unsigned char desc_80419378[];
struct Self : Base { void *u4; void *u8; String name; Ref a; Ref b; };
extern "C" void w3d_d31d_named_holder_setup_8015bf74(Self *self, const char *text) {
    service_8020b648()->set(String(text));
    string_assign_8020bd38(&self->name, text);
    self->a.set(forward_8020b680(desc_80419378));
    self->b.set(singleton_8020b884());
    String m = make_80210958();
    set_singleton_8020b960(self->a.p);
    self->apply(String(""));
    Entry *e = self->a.p;
    e->put(e->get(0));
    self->finish();
}
