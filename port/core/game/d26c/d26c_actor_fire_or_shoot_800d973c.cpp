#include "w3d_ptr.h"
#line 1 "d26c_actor_fire_or_shoot_800d973c.cpp"
// d26c: 0x800d973c. Schedule the actor's delayed shots with their sound, or fire at once, then post the done message
// to itself. Names are inferred; String is one word.
struct Vec3 {
    float x, y, z;
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct StringHeader { unsigned short refs; };
struct String {
    Ptr32<char> text;
    String(const String &);
    ~String();
};
extern "C" void string_init_8020c5c0(Ptr32<String>);
extern "C" Ptr32<StringHeader> string_header_80341884(Ptr32<String>);
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::String(const String &o) {
    string_init_8020c5c0(this);
    text = o.text;
    string_header_80341884(this)->refs++;
}
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
inline bool operator!=(const String &a, const char *b) { return strcmp(a.text, b) != 0; }
struct Desc { char u0[392]; int count; char u396[44]; String sound; };
struct Actor { char u0[192]; Ptr32<void> h192; };
struct Mixer { struct V { Ptr32<void> u[24]; Ptr32<void (Ptr32<Mixer>, Ptr32<const char>, Ptr32<void>)> play; }; Ptr32<struct V> vtable; };
struct Audio { char u0[108]; Ptr32<Mixer> mixer; };
extern Ptr32<Audio> audio_804b1788;
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> desc_801797b4(Ptr32<void>);
extern "C" int cached_id_8015f5a0(Ptr32<int>, int);
extern int fire_id_804aeb40, done_id_804aeb68;
extern Vec3 zero_8045e788[];
extern char empty_text_8038956c[];
extern "C" void schedule_800d8ed8(Ptr32<Actor>, unsigned short, int, Ptr32<void>, Ptr32<Vec3>, Ptr32<void>);
extern "C" void shoot_800ec6a8(Ptr32<Actor>, Ptr32<void>, Ptr32<void>, Ptr32<void>);
extern "C" Ptr32<void> arena_alloc_801613f0(Ptr32<void>, unsigned);
extern Ptr32<void> arena_804b1754;
struct Message { unsigned short id; Ptr32<const void> data; };
extern char data_8040db38[];
extern "C" void post_8015fc58(Ptr32<Actor>, Ptr32<Message>);
extern "C" void d26c_actor_fire_or_shoot_800d973c(Ptr32<Actor> self, Ptr32<void> a, Ptr32<void> b, Ptr32<void> c) {
    Ptr32<Desc> d = desc_801797b4(empty_80341584(self->h192));
    int n = d->count;
    if (n > 0) {
        Vec3 v(zero_8045e788[0]);
        schedule_800d8ed8(self, cached_id_8015f5a0(&fire_id_804aeb40, 1), n, a, &v, c);
        String s(d->sound);
        if (s != empty_text_8038956c) {
            Ptr32<Mixer> m = audio_804b1788->mixer;
            m->vtable->play(m, s.text, a);
        }
    } else {
        shoot_800ec6a8(self, a, b, c);
    }
    Ptr32<Message> m = (Ptr32<Message>)arena_alloc_801613f0(arena_804b1754, 8);
    m->id = cached_id_8015f5a0(&done_id_804aeb68, 1);
    m->data = data_8040db38;
    post_8015fc58(self, m);
}


