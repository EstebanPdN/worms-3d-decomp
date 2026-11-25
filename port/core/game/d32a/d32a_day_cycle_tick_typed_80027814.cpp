#include "w3d_ptr.h"
#line 1 "d32a_day_cycle_tick_typed_80027814.cpp"
// GWMP8P rev0 0x80027814. Each tick moves the sun along a time-driven path
// and clears the ambient colour, then walks the world list until it finds a
// level object with a non-empty name. It relabels the object DAY, EVENING or
// NIGHT in turn, posts its name, restarts two services, and sends the
// Land.Materials and Land.File settings to the owner. Names are inferred
// from the original instructions and strings.
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" float w3d_cx9c_cosf_802e86d4(float);
extern "C" float w3d_cx9c_sinf_802e88ac(float);
struct String;
extern "C" void w3d_string_base_finish(Ptr32<String>);
extern "C" void w3d_string_release(Ptr32<String>);
extern "C" void w3d_string_release_header(Ptr32<void>);
extern "C" void w3d_string_format(Ptr32<String>, Ptr32<const char>, ...);
struct String {
    Ptr32<const char> text;
    String();
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
struct Vec { float x, y, z; Vec(float a, float b, float c) { x = a; y = b; z = c; } };
struct Light;
struct LightTable { char pad[44]; Ptr32<int (Ptr32<Light>, Ptr32<const Vec>)> dir; Ptr32<int (Ptr32<Light>, Ptr32<const Vec>)> col; };
struct Light { Ptr32<LightTable> t; };
struct Item;
struct ItemTable { char pad[16]; Ptr32<void (Ptr32<Item>)> release; char pad2[4]; Ptr32<int (Ptr32<Item>)> kind; char pad3[4]; Ptr32<Ptr32<const char> (Ptr32<Item>)> name; };
struct Item { Ptr32<ItemTable> t; };
struct ItemRef {
    Ptr32<Item> p;
    ItemRef() { p = 0; }
    ~ItemRef() { if (p) p->t->release(p); }
};
struct List;
struct ListTable { char pad[116]; Ptr32<int (Ptr32<List>, Ptr32<int>, Ptr32<ItemRef>)> find; };
struct List { Ptr32<ListTable> t; };
struct Engine { char pad[48]; Ptr32<Light> light; char pad2[48]; Ptr32<List> list; };
struct Type { char pad[20]; Ptr32<Type> parent; };
struct Actor;
struct ActorTable { char pad[20]; Ptr32<Ptr32<Type> (Ptr32<Actor>)> type; };
struct Actor { Ptr32<ActorTable> t; char pad[48]; String label; struct Name { Ptr32<const char> text; bool operator!=(const char *o) const { return strcmp(text, o) != 0; } } name; };
struct Self { char pad[20]; int id; };
struct Id { int words[2]; };
extern Ptr32<Engine> g_engine_804b1788;
extern Ptr32<void> g_arena_804b1754;
extern Ptr32<void> g_hub_804b178c;
extern float g_time_804aa810;
extern int g_prev_804aa814;
extern int g_cur_804aa818;
extern unsigned int g_phase_804aa81c;
extern Id g_id_804acbc4, g_id_804acbcc, g_id_804acbd4;
extern Type g_type_803667a8[];
extern char g_key_8040f818[], g_key_8040f7c8[];
extern "C" Ptr32<void> w3d_empty_80341584(Ptr32<Item>);
extern "C" Ptr32<Actor> w3d_auto_801797b4(Ptr32<void>);
extern "C" Ptr32<void> tsonnet_b33_arena_801613f0(Ptr32<void>, int);
extern "C" int w3d_cached_message_id(Ptr32<Id>, int);
extern "C" Ptr32<void> w3d_message_string_init(Ptr32<void>, unsigned short, Ptr32<const char>);
extern "C" int w3d_message_post_current(Ptr32<void>);
extern "C" Ptr32<void> w3d_s10_service_forward_8020b680(Ptr32<const void>);
extern "C" int fn_80164514(Ptr32<void>, Ptr32<void>, int);
extern "C" void d30j_remove_node_children_80164cec(Ptr32<void>, int);
extern "C" int w3d_auto_800fc2b0(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<const char>>);
extern "C" void w3d_auto_8015fc58(Ptr32<Self>, Ptr32<void>);
inline unsigned short MsgId(Id &i) { return w3d_cached_message_id(&i, 1); }
inline int IsA(Ptr32<Type> t)
{
    Ptr32<Type> want = g_type_803667a8;
    while (t != want) {
        Ptr32<Type> p = t->parent;
        if (t == p) return 0;
        t = p;
    }
    return 1;
}
extern "C" int w3d_d32a_day_cycle_tick_typed_80027814(Ptr32<Self> self)
{
    g_time_804aa810 += 0.02f;
    Vec dir(w3d_cx9c_cosf_802e86d4(g_time_804aa810 * 0.21f) * 400.0f,
            w3d_cx9c_sinf_802e88ac(g_time_804aa810 * 0.11f) * 290.0f + 300.0f,
            w3d_cx9c_sinf_802e88ac(g_time_804aa810 * 0.21f) * 400.0f);
    Vec col(0.0f, 0.0f, 0.0f);
    g_engine_804b1788->light->t->dir(g_engine_804b1788->light, &dir);
    g_engine_804b1788->light->t->col(g_engine_804b1788->light, &col);
    Ptr32<List> list = g_engine_804b1788->list;
    ItemRef item;
    String map;
    int more = 1;
    for (;;) {
        g_cur_804aa818 = g_prev_804aa814;
        list->t->find(list, &g_cur_804aa818, &item);
        if (item.p->t->kind(item.p) == 5) {
            Ptr32<Actor> a = w3d_auto_801797b4(w3d_empty_80341584(item.p));
            if (IsA(a->t->type(a)) == 1 && a->name != "") {
                switch (g_phase_804aa81c) {
                case 0:
                    a->label = String("DAY");
                    g_phase_804aa81c = 1;
                    break;
                case 1:
                    a->label = String("EVENING");
                    g_phase_804aa81c = 2;
                    break;
                case 2:
                    a->label = String("NIGHT");
                    g_phase_804aa81c = 0;
                    g_prev_804aa814 = g_cur_804aa818;
                    break;
                }
                more = 0;
                Ptr32<void> m = tsonnet_b33_arena_801613f0(g_arena_804b1754, 12);
                unsigned short mid = MsgId(g_id_804acbc4);
                w3d_message_post_current(w3d_message_string_init(m, mid, item.p->t->name(item.p)));
                Ptr32<void> s = w3d_s10_service_forward_8020b680(g_key_8040f818);
                fn_80164514(g_hub_804b178c, s, self->id);
                s = w3d_s10_service_forward_8020b680(g_key_8040f7c8);
                fn_80164514(g_hub_804b178c, s, self->id);
                Ptr32<const char> n1 = "Land.Materials";
                Ptr32<const char> v1 = 0;
                w3d_auto_800fc2b0(&n1, &v1);
                Ptr32<void> m1 = tsonnet_b33_arena_801613f0(g_arena_804b1754, 12);
                unsigned short id1 = MsgId(g_id_804acbcc);
                w3d_auto_8015fc58(self, w3d_message_string_init(m1, id1, v1));
                Ptr32<const char> n2 = "Land.File";
                Ptr32<const char> v2 = 0;
                w3d_auto_800fc2b0(&n2, &v2);
                if (v2 && *v2) {
                    w3d_string_format(&map, "Maps/%s", w3d::VA(v2));
                    Ptr32<void> m2 = tsonnet_b33_arena_801613f0(g_arena_804b1754, 12);
                    unsigned short id2 = MsgId(g_id_804acbd4);
                    w3d_auto_8015fc58(self, w3d_message_string_init(m2, id2, map.text));
                }
                d30j_remove_node_children_80164cec(g_hub_804b178c, self->id);
            }
        }
        if (!more) break;
        g_prev_804aa814 = g_cur_804aa818;
    }
    return 0;
}


