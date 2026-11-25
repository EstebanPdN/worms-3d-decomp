#include "w3d_ptr.h"
#line 1 "d26k_status_refresh_8021e054.cpp"
// Status refresh (Worms 3D GameCube PAL, 0x8021e054).
// 
// Reads ActiveWormIndex, stores it at +272 and retains the indexed team at +264.
// Stores a stamp (0x80162ba8) at +268 and the title string at +260. With a live
// camera 0x804aa8c8, copies its 64-byte view matrix to +28 and shares the active
// worm's name into +256. Finally resolves the three sounds of 0x804abac0 into
// +232, +224 and +228.

struct String_803426b8;
extern "C" void string_init_8020c5c0(Ptr32<String_803426b8>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<String_803426b8>);
extern "C" void string_finish_8020c5c4(Ptr32<String_803426b8>);
extern "C" void string_release_80341588(Ptr32<String_803426b8>);
extern "C" void release_header_8020bb2c(Ptr32<unsigned short>);
extern "C" Ptr32<String_803426b8> string_from_text_8020bb54(Ptr32<String_803426b8>, Ptr32<const char>);
struct String_803426b8 {
    Ptr32<char> text;
    String_803426b8();
    String_803426b8(const String_803426b8 &other) {
        string_init_8020c5c0(this);
        text = other.text;
        ++*string_header_80341884(this);
    }
    ~String_803426b8() {
        string_finish_8020c5c4(this);
        string_release_80341588(this);
    }
    String_803426b8 &operator=(const String_803426b8 &other) {
        ++reinterpret_cast<unsigned short *>(w3d::R(other.text))[-3];
        Ptr32<unsigned short> header = reinterpret_cast<unsigned short *>(w3d::R(text)) - 3;
        if (--*header == 0) {
            release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};
struct Interface;
struct InterfaceTable {
    Ptr32<void> reserved[3];
    Ptr32<int (Ptr32<Interface>)> retain;
    Ptr32<int (Ptr32<Interface>)> release;
};
struct Interface { Ptr32<InterfaceTable> table; };
struct Ref {
    Ptr32<Interface> p;
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Interface *)w3d_p.get()) {}
 Ref(Interface *o) : p(o) { if (p) p->table->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->table->release(p); }
};

struct Matrix { float m[16]; };
struct PropertyKey { Ptr32<const char> name; };
struct Worm { char pad[60]; String_803426b8 name; };
struct Camera { char pad0[312]; int index; Ptr32<Ptr32<Worm>> worms; char pad1[328 - 320]; char view[4]; };
struct Sounds { char pad[76]; Ptr32<void> first; Ptr32<void> second; Ptr32<void> third; };
struct Status {
    char pad0[28]; Matrix view; char pad1[224 - 92]; Ptr32<void> second; Ptr32<void> third; Ptr32<void> first; char pad2[256 - 236];
    String_803426b8 wormName; String_803426b8 title; Ptr32<Interface> team; int stamp; int index;
    void setTeam(Ptr32<Interface> n) { Ptr32<Interface> old = team; team = n; if (n) n->table->retain(n); if (old) old->table->release(old); }
};
extern const char text_803b4708[];
extern Ptr32<Camera> global_804aa8c8;
extern Ptr32<Sounds> global_804abac0;
extern "C" int read_800fc1f0(Ptr32<PropertyKey>, Ptr32<int>);
extern "C" Ptr32<Interface> query_800fc6dc(int);
extern "C" int stamp_80162ba8();
extern "C" void title_80165018(Ptr32<String_803426b8>);
extern "C" void view_8015aa04(Ptr32<void>, Ptr32<Matrix>);
extern "C" Ptr32<void> load_80178c48(Ptr32<void>);
inline void put(Ptr32<Status> s, Ptr32<Camera> c) { Matrix m; view_8015aa04(c->view, &m); s->view = m; }
extern "C" void w3d_d26k_status_refresh_8021e054(Ptr32<Status> self) {
    int index = -1;
    {
        PropertyKey key;
        key.name = text_803b4708;
        read_800fc1f0(&key, &index);
    }
    self->index = index;
    self->setTeam(query_800fc6dc(index));
    self->stamp = stamp_80162ba8();
    String_803426b8 title;
    title_80165018(&title);
    self->title = title;
    Ptr32<Camera> camera = global_804aa8c8;
    if (camera) {
        put(self, camera);
        Ptr32<Worm> worm = *reinterpret_cast<Worm **>(w3d::R(reinterpret_cast<char *>(w3d::R(camera->worms)) + (camera->index << 2)));
        self->wormName = worm->name;
    }
    Ptr32<Sounds> sounds = global_804abac0;
    self->first = load_80178c48(sounds->first);
    self->second = load_80178c48(sounds->second);
    self->third = load_80178c48(sounds->third);
}


