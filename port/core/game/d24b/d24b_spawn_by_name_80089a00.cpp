#include "w3d_ptr.h"
#line 1 "d24b_spawn_by_name_80089a00.cpp"
/* Spawn by worm name (0x80089a00): copies the team list 0x8043bb64 and for every worm
 * calls the landmine spawn 0x8008bc78 or the second spawn 0x8008df50 at the worm's
 * position (+4) depending on its name (+60). Field and type names are inferred; the
 * list and strings are external views of original data; the unit owns no data. */
extern "C" Ptr32<char> w3d_allocate_80212fd4(unsigned);
extern "C" void w3d_release_802134fc(Ptr32<void>);
extern "C" Ptr32<void> w3d_copy_802eee50(...);
extern "C" int w3d_strcmp_802ef234(Ptr32<const char>, Ptr32<const char>);
struct String {
    Ptr32<char> text;
    String();
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *text);
    String(const String &);
    ~String();
};
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
inline String::~String() {
    w3d_string_finish_8020c5c4(this);
    w3d_string_release_80341588(this);
}
struct Vec3 {
    float x, y, z;
    Vec3(const Vec3 &o) { float ax = o.x, ay = o.y, az = o.z; x = ax; y = ay; z = az; }
};
struct Worm { char unknown00[4]; Vec3 position; char unknown16[24]; Vec3 velocity; char unknown52[8]; Ptr32<const char> name; };
template <class T>
struct List {
    Ptr32<T> begin; Ptr32<T> end; Ptr32<T> capacity;
    List() {}
    ~List() { if (begin) w3d_release_802134fc(begin); }
    unsigned size() const { return end - begin; }
    T &operator[](unsigned i) { return begin[i]; }
};
struct Team { char unknown00[20]; List <Ptr32<Worm> > worms; };
extern List <Ptr32<Team> > w3d_teams_8043bb64;
struct Spawner;
extern "C" void w3d_spawn_mine_8008bc78(Ptr32<Spawner>, Ptr32<Vec3>);
extern "C" void w3d_spawn_other_8008df50(Ptr32<Spawner>, Ptr32<Vec3>);
extern "C" char w3d_string_8037d888[]; /* "mine" */
extern "C" char w3d_string_8037d890[]; /* "oildrum" */

inline bool Same(const String &a, Ptr32<const char> b) { return w3d_strcmp_802ef234(a.text, b) == 0; }

extern "C" void w3d_d24b_spawn_by_name_80089a00(Ptr32<Spawner> self)
{
    List <Ptr32<Team> > teams;
    {
        unsigned n = (Ptr32<char>)w3d_teams_8043bb64.end - (Ptr32<char>)w3d_teams_8043bb64.begin;
        Ptr32<Ptr32<Team>> p = (Ptr32<Ptr32<Team>>)w3d_allocate_80212fd4(n);
        Ptr32<Ptr32<Team>> e = (Ptr32<Ptr32<Team>>)((Ptr32<char>)p + n);
        teams.begin = p;
        teams.end = e;
        teams.capacity = e;
        w3d_copy_802eee50(w3d::VA(p), w3d::VA(w3d_teams_8043bb64.begin), n);
    }
    for (unsigned i = 0; i < teams.size(); i++) {
        List <Ptr32<Worm> > &worms = teams[i]->worms;
        for (unsigned j = 0; j < worms.size(); j++) {
            Vec3 position(worms[j]->position);
            {
                Vec3 velocity(worms[j]->velocity);
            }
            String name(worms[j]->name);
            String unused;
            if (Same(name, w3d_string_8037d888))
                w3d_spawn_mine_8008bc78(self, &position);
            else if (Same(name, w3d_string_8037d890))
                w3d_spawn_other_8008df50(self, &position);
        }
    }
}


