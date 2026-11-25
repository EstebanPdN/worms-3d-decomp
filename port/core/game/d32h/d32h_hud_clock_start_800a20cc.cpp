#include "w3d_ptr.h"
#line 1 "d32h_hud_clock_start_800a20cc.cpp"
// GWMP8P rev0 0x800a20cc. HUD clock start: reads the HUD.Clock.* settings
// into retained objects on self, copies the clock position vectors, loads
// the clock background and digit resources, fills two meshes with texture
// coordinates and the tint colour, lays the clock out (0x800a30bc), reads
// the round, turn, hot-seat time and display-mode properties and subscribes
// to one cached message. Class layouts are partial views; names are
// inferred.
struct Object;
struct ObjectVtable { Ptr32<void> unknown00[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Handle {
    Ptr32<Object> value;
    Handle() {}
    ~Handle() { if (value) value->vtable->release(value); }
private:
    Handle(const Handle &);
};
struct PropertyKey { Ptr32<const char> name; };
struct String { String(const String &); Ptr32<char> text; template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *t); ~String(); };
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
extern "C" int property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" int vector_800fc2f0(Ptr32<PropertyKey>, Ptr32<void>);
extern "C" int colour_800fc370(Ptr32<PropertyKey>, Ptr32<unsigned int>);
extern "C" Ptr32<Object> castA_80342a74(Ptr32<Object>);
extern "C" Ptr32<Object> castF_80342fa4(Ptr32<Object>);
extern "C" Ptr32<Object> castD_80343df4(Ptr32<Object>);
extern "C" Ptr32<Object> castT_803426b4(Ptr32<Object>);
extern "C" Ptr32<Object> castN_80342a78(Ptr32<Object>);
extern "C" Ptr32<Object> castM_8034380c(Ptr32<Object>);
extern "C" int load_8015adf4(Ptr32<const String>, Ptr32<Ptr32<Object>>, unsigned char);
struct Vec { float x, y, z; Vec() {} Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
struct Vec3 { float x, y, z; };
extern "C" Ptr32<const Vec3> value_80178ec4(Ptr32<Object>);
inline const Vec &AsVec(Ptr32<const Vec3> v) { return *(Ptr32<const Vec>)v; }
extern "C" int lock_80189450(Ptr32<Object>, int);
extern "C" int resize_8018920c(Ptr32<Object>, int);
struct Uv { float u, v; void Set(float a, float b) { u = a; v = b; } };
extern "C" Ptr32<Uv> uvs_8018963c(Ptr32<Object>);
extern "C" Ptr32<unsigned int> colours_80189760(Ptr32<Object>);
extern "C" Ptr32<unsigned char> data_80189828(Ptr32<Object>);
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
extern MessageCache message_804ae184;
extern "C" int cached_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int subscribe_80162024(Ptr32<void>, const unsigned short &, Ptr32<void>);
struct Clock;
extern "C" void layout_800a30bc(Ptr32<Clock>);
struct RGBA { signed char r, g, b, a; };
struct Pack { char unknown[8]; };
struct Clock { char unknown0[28]; Vec3 v28; Vec3 v40; Ptr32<Object> o52; Ptr32<Object> o56; Ptr32<Object> o60; Ptr32<Object> o64; Ptr32<Object> o68; Ptr32<Object> o72; Ptr32<Object> o76; char unknown80[8]; Ptr32<Object> f88[20]; char unknown168x[0]; };
template <Ptr32<Object> (*Cast)(Ptr32<Object>)>
inline void Store(Handle &h, Ptr32<Object> &slot) {
    Ptr32<Object> object = Cast(h.value);
    if (object) object->vtable->retain(object);
    if (slot) slot->vtable->release(slot);
    slot = object;
}
inline void Open(Handle &h, Ptr32<PropertyKey> key) { Ptr32<Ptr32<Object>> out = &h.value; *out = 0; property_800fc1b0(key, out); }
typedef Ptr32<int (Ptr32<Object>, Ptr32<void>, int)> Bind;
inline Ptr32<void> Slot(Ptr32<Object> o, int off) { return *(Ptr32<Ptr32<void>>)((Ptr32<char>)o->vtable + off); }
#define F(n) (*(Ptr32<Object> *)w3d::AG((char *)self + (n)))
extern "C" void d32h_hud_clock_start_800a20cc(Ptr32<Clock> self) {
    RGBA white;
    Ptr32<RGBA> w = &white;
    w->r = -1; w->g = -1; w->b = -1; w->a = -1;
    PropertyKey key0;
    {
        Handle h;
        key0.name = "HUD.Clock.Spacing";
        Open(h, &key0);
        Store<castA_80342a74>(h, F(88));
    }
    PropertyKey key1;
    {
        Handle h;
        key1.name = "HUD.Clock.SpacingOnly";
        Open(h, &key1);
        Store<castA_80342a74>(h, F(92));
    }
    PropertyKey key2;
    {
        Handle h;
        key2.name = "HUD.Clock.GameScaleV";
        Open(h, &key2);
        Store<castF_80342fa4>(h, F(96));
    }
    PropertyKey key3;
    {
        Handle h;
        key3.name = "HUD.Clock.GameScaleOnlyV";
        Open(h, &key3);
        Store<castF_80342fa4>(h, F(104));
    }
    PropertyKey key4;
    {
        Handle h;
        key4.name = "HUD.Clock.TurnScaleV";
        Open(h, &key4);
        Store<castF_80342fa4>(h, F(100));
    }
    PropertyKey key5;
    {
        Handle h;
        key5.name = "HUD.Clock.GameXOffset";
        Open(h, &key5);
        Store<castA_80342a74>(h, F(108));
    }
    PropertyKey key6;
    {
        Handle h;
        key6.name = "HUD.Clock.GameYOffset";
        Open(h, &key6);
        Store<castA_80342a74>(h, F(112));
    }
    PropertyKey key7;
    {
        Handle h;
        key7.name = "HUD.Clock.TurnXOffset";
        Open(h, &key7);
        Store<castA_80342a74>(h, F(116));
    }
    PropertyKey key8;
    {
        Handle h;
        key8.name = "HUD.Clock.GameTimeScaleSpeed";
        Open(h, &key8);
        Store<castA_80342a74>(h, F(120));
    }
    PropertyKey key9;
    {
        Handle h;
        key9.name = "HUD.Clock.ColourHotSeat";
        Open(h, &key9);
        Store<castD_80343df4>(h, F(124));
    }
    PropertyKey key10;
    {
        Handle h;
        key10.name = "HUD.Clock.ColourTurn";
        Open(h, &key10);
        Store<castD_80343df4>(h, F(128));
    }
    PropertyKey key11;
    {
        Handle h;
        key11.name = "HUD.Clock.ColourTurnEnd";
        Open(h, &key11);
        Store<castD_80343df4>(h, F(132));
    }
    PropertyKey key12;
    {
        Handle h;
        key12.name = "HUD.Clock.TurnPosition";
        Open(h, &key12);
        Store<castF_80342fa4>(h, F(140));
    }
    PropertyKey key13;
    {
        Handle h;
        key13.name = "HUD.Clock.Position";
        Open(h, &key13);
        Store<castF_80342fa4>(h, F(136));
    }
    PropertyKey key14;
    {
        Handle h;
        key14.name = "HUD.Clock.GameOnlyPos";
        Open(h, &key14);
        Store<castF_80342fa4>(h, F(144));
    }
    PropertyKey key15;
    {
        Handle h;
        key15.name = "HUD.Clock.DisplayRoundTime";
        Open(h, &key15);
        Store<castN_80342a78>(h, F(156));
    }
    PropertyKey key16;
    {
        Handle h;
        key16.name = "HUD.Clock.TurnOnlyPosition";
        Open(h, &key16);
        Store<castF_80342fa4>(h, F(160));
    }
    Ptr32<const Vec3> v0 = value_80178ec4(F(136));
    self->v28 = *v0;
    Vec a(*(Ptr32<const Vec>)&self->v28);
    Vec b(AsVec(value_80178ec4(F(100))));
    Vec c(AsVec(value_80178ec4(F(96))));
    *(Ptr32<Vec3>)((Ptr32<char>)self + 168) = *value_80178ec4(F(96));
    {
        String s("HUD.Clock.Back");
        load_8015adf4(&s, &F(60), 255);
    }
    char x64[16], x80[16];
    PropertyKey k168; k168.name = "HUD.Clock.BackPos";
    vector_800fc2f0(&k168, x64);
    ((Bind)Slot(F(60), 76))(F(60), x64, 0);
    PropertyKey k172; k172.name = "HUD.Clock.BackScale";
    vector_800fc2f0(&k172, x80);
    ((Bind)Slot(F(60), 84))(F(60), x80, 0);
    {
        String s("HUD.TimerFont");
        load_8015adf4(&s, &F(56), 255);
    }
    {
        String s("HUD.TimerFont");
        load_8015adf4(&s, &F(52), 255);
    }
    Ptr32<Object> ma = castM_8034380c(F(56));
    Ptr32<Object> mb = castM_8034380c(F(52));
    lock_80189450(ma, 16);
    lock_80189450(mb, 16);
    resize_8018920c(ma, 5);
    resize_8018920c(mb, 2);
    unsigned i;
    for (i = 0; i <= 1; i++) {
        Uv &e = uvs_8018963c(mb)[i];
        e.Set(b.x, b.y);
    }
    PropertyKey k176; k176.name = "HUD.Clock.ColourGame";
    unsigned tint;
    colour_800fc370(&k176, &tint);
    for (i = 0; i <= 4; i++) {
        Uv &e = uvs_8018963c(ma)[i];
        e.Set(c.x, c.y);
        colours_80189760(ma)[i] = tint;
    }
    self->v40 = *value_80178ec4(F(136));
    layout_800a30bc(self);
    data_80189828(ma)[2] = 11;
    PropertyKey key100;
    {
        Handle h;
        key100.name = "RoundTimeRemaining";
        Open(h, &key100);
        Store<castT_803426b4>(h, F(68));
    }
    PropertyKey key101;
    {
        Handle h;
        key101.name = "TurnTimeRemaining";
        Open(h, &key101);
        Store<castT_803426b4>(h, F(64));
    }
    PropertyKey key102;
    {
        Handle h;
        key102.name = "HotSeatTimeRemaining";
        Open(h, &key102);
        Store<castT_803426b4>(h, F(72));
    }
    PropertyKey key103;
    {
        Handle h;
        key103.name = "ClockDisplayMode";
        Open(h, &key103);
        Store<castN_80342a78>(h, F(76));
    }
    subscribe_80162024(self, cached_8015f5a0(&message_804ae184, 1), (Ptr32<char>)self + 164);
}


