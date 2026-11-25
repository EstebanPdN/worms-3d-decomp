#include "w3d_ptr.h"
#line 1 "d32a_briefing_panel_show_80030260.cpp"
// GWMP8P rev0 0x80030260. Builds the mission briefing panel: finds the
// owner's screen through its type descriptor, resets its item list, creates
// a panel through the service lookup, reads position and size values, sets
// the panel's name, font, text and colour keys, appends it to the list,
// titles the screen and posts FE.BriefingPanel. Names are inferred from the
// original strings and instructions.
struct Object;
struct ObjectVtable { Ptr32<void> unknown00[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Descriptor_80178474 {
    Ptr32<void> value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct String;
extern "C" void w3d_string_base_finish(Ptr32<String>);
extern "C" void w3d_string_release(Ptr32<String>);
extern "C" void w3d_string_release_header(Ptr32<void>);
struct String {
    Ptr32<const char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &o);
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
    String &operator=(const String &o) {
        ++*(Ptr32<unsigned short>)(o.text - 6);
        Ptr32<unsigned short> h = (Ptr32<unsigned short>)(text - 6);
        if (--*h == 0) w3d_string_release_header(h);
        text = o.text;
        return *this;
    }
};
struct Vec { float x, y, z; };
struct Field { char pad[24]; int count; };
struct Panel : Object {
    char pad[16] __attribute__((aligned(__alignof__(Object)))); Vec colour; Vec pos; char pad2[20]; float width; char pad3[20]; String name; char pad4[32];
    int on; int flag; String colour_key; String text_key; String font;
    void SetPos(const Vec &v) { pos = v; }
    void SetColour(const Vec &v) { colour = v; }
};
struct Screen : Object { char pad[16] __attribute__((aligned(__alignof__(Object)))); Ptr32<Field> field; char pad2[4]; String title; };
template <class T> struct Handle {
    Ptr32<T> value;
    Handle() : value(0) {}
    template <class W3dU> Handle<T>(Ptr32<W3dU> w3d_p) : Handle<T>((T *)w3d_p.get()) {}
 Handle(T *next) : value(next) { if (value) value->vtable->retain(value); }
    Handle(const Handle &);
    ~Handle() { if (value) value->vtable->release(value); }
    void assign(Ptr32<T> next) {
        if (next) {
            next->vtable->retain(next);
            if (value) value->vtable->release(value);
            value = next;
        }
    }
};
struct Self { char pad[40]; Ptr32<void> f40; Ptr32<void> f44; Ptr32<void> f48; Ptr32<void> f52; Ptr32<void> f56; Ptr32<void> owner; char pad2[4]; int shown; };
struct Id { int words[2]; };
extern Ptr32<void> g_arena_804b1754;
extern Id g_id_804acd54;
extern char g_key_80419d78[], s_803730b0[], s_80372fc0[];
extern "C" Ptr32<void> w3d_empty_80341584(Ptr32<void>);
extern "C" Ptr32<Screen> w3d_auto_80179598(Ptr32<void>, Ptr32<Descriptor_80178474>);
extern "C" void list_begin_801ef380(Ptr32<Screen>, int, int, int, int);
extern "C" void list_append_801ef174(Ptr32<Screen>, int, int, Ptr32<Panel>);
extern "C" Ptr32<Panel> w3d_s10_service_forward_8020b680(Ptr32<const void>);
extern "C" float w3d_auto_80178df0(Ptr32<void>);
extern "C" Ptr32<void> tsonnet_b33_arena_801613f0(Ptr32<void>, int);
extern "C" int w3d_cached_message_id(Ptr32<Id>, int);
extern "C" Ptr32<void> w3d_message_string_init(Ptr32<void>, unsigned short, Ptr32<const char>);
extern "C" int w3d_message_post_current(Ptr32<void>);
extern "C" void w3d_d32a_briefing_panel_show_80030260(Ptr32<Self> self)
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
    { Ptr32<Panel> o = panel.value; o->name = String("Briefing"); }
    panel.value->on = 0;
    panel.value->SetPos(a);
    { Ptr32<Panel> o = panel.value; o->font = String("FE.Font"); }
    panel.value->SetColour(b);
    { Ptr32<Panel> o = panel.value; o->colour_key = String("FE.BriefingPanel.TextColour"); }
    { Ptr32<Panel> o = panel.value; o->text_key = String(s_803730b0); }
    { Ptr32<Panel> o = panel.value; o->width = w3d_auto_80178df0(self->f56); }
    list_append_801ef174(h.value, 20, 6, panel.value);
    { Ptr32<Screen> o = h.value; o->title = String("Briefing Panel"); }
    Ptr32<void> m = tsonnet_b33_arena_801613f0(g_arena_804b1754, 12);
    unsigned short mid = w3d_cached_message_id(&g_id_804acd54, 1);
    w3d_message_post_current(w3d_message_string_init(m, mid, s_80372fc0));
    self->shown = 1;
}


