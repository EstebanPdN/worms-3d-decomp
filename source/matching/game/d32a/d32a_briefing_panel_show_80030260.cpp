// GWMP8P rev0 0x80030260. Builds the mission briefing panel: finds the
// owner's screen through its type descriptor, resets its item list, creates
// a panel through the service lookup, reads position and size values, sets
// the panel's name, font, text and colour keys, appends it to the list,
// titles the screen and posts FE.BriefingPanel. Names are inferred from the
// original strings and instructions.
struct Object;
struct ObjectVtable { void *unknown00[3]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVtable *vtable; };
struct Descriptor_80178474 {
    void *value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct String;
extern "C" void w3d_string_base_finish(String *);
extern "C" void w3d_string_release(String *);
extern "C" void w3d_string_release_header(void *);
struct String {
    const char *text;
    String(const char *);
    String(const String &o);
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
    String &operator=(const String &o) {
        ++*(unsigned short *)(o.text - 6);
        unsigned short *h = (unsigned short *)(text - 6);
        if (--*h == 0) w3d_string_release_header(h);
        text = o.text;
        return *this;
    }
};
struct Vec { float x, y, z; };
struct Field { char pad[24]; int count; };
struct Panel : Object {
    char pad[16]; Vec colour; Vec pos; char pad2[20]; float width; char pad3[20]; String name; char pad4[32];
    int on; int flag; String colour_key; String text_key; String font;
    void SetPos(const Vec &v) { pos = v; }
    void SetColour(const Vec &v) { colour = v; }
};
struct Screen : Object { char pad[16]; Field *field; char pad2[4]; String title; };
template <class T> struct Handle {
    T *value;
    Handle() : value(0) {}
    Handle(T *next) : value(next) { if (value) value->vtable->retain(value); }
    Handle(const Handle &);
    ~Handle() { if (value) value->vtable->release(value); }
    void assign(T *next) {
        if (next) {
            next->vtable->retain(next);
            if (value) value->vtable->release(value);
            value = next;
        }
    }
};
struct Self { char pad[40]; void *f40, *f44, *f48, *f52, *f56; void *owner; char pad2[4]; int shown; };
struct Id { int words[2]; };
extern void *g_arena_804b1754;
extern Id g_id_804acd54;
extern char g_key_80419d78[], s_803730b0[], s_80372fc0[];
extern "C" void *w3d_empty_80341584(void *);
extern "C" Screen *w3d_auto_80179598(void *, Descriptor_80178474 *);
extern "C" void list_begin_801ef380(Screen *, int, int, int, int);
extern "C" void list_append_801ef174(Screen *, int, int, Panel *);
extern "C" Panel *w3d_s10_service_forward_8020b680(const void *);
extern "C" float w3d_auto_80178df0(void *);
extern "C" void *tsonnet_b33_arena_801613f0(void *, int);
extern "C" int w3d_cached_message_id(Id *, int);
extern "C" void *w3d_message_string_init(void *, unsigned short, const char *);
extern "C" int w3d_message_post_current(void *);
extern "C" void w3d_d32a_briefing_panel_show_80030260(Self *self)
{
    Descriptor_80178474 d;
    Handle<Screen> h;
    {
        Handle<Screen> t(w3d_auto_80179598(w3d_empty_80341584(self->owner), &d));
        h.assign(t.value);
    }
    list_begin_801ef380(h.value, 20, 6, 0, h.value->field->count);
    Handle<Panel> panel(w3d_s10_service_forward_8020b680(g_key_80419d78));
    float px = w3d_auto_80178df0(self->f48);
    float py = w3d_auto_80178df0(self->f52);
    Vec a;
    a.x = px;
    a.y = py;
    a.z = 0.0f;
    float cx = w3d_auto_80178df0(self->f40);
    float cy = w3d_auto_80178df0(self->f44);
    Vec b;
    b.x = cx;
    b.y = cy;
    b.z = 0.0f;
    panel.value->flag = 1;
    { Panel *o = panel.value; o->name = String("Briefing"); }
    panel.value->on = 0;
    panel.value->SetPos(a);
    { Panel *o = panel.value; o->font = String("FE.Font"); }
    panel.value->SetColour(b);
    { Panel *o = panel.value; o->colour_key = String("FE.BriefingPanel.TextColour"); }
    { Panel *o = panel.value; o->text_key = String(s_803730b0); }
    { Panel *o = panel.value; o->width = w3d_auto_80178df0(self->f56); }
    list_append_801ef174(h.value, 20, 6, panel.value);
    { Screen *o = h.value; o->title = String("Briefing Panel"); }
    void *m = tsonnet_b33_arena_801613f0(g_arena_804b1754, 12);
    unsigned short mid = w3d_cached_message_id(&g_id_804acd54, 1);
    w3d_message_post_current(w3d_message_string_init(m, mid, s_80372fc0));
    self->shown = 1;
}
