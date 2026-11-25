#include "w3d_ptr.h"
#line 1 "d26k_asset_finish_8021dd04.cpp"
// Asset finish (Worms 3D GameCube PAL, 0x8021dd04).
// 
// Copies the asset name and two owner property strings into discarded by-value
// temporaries, releases the file reader at +76 (0x8020810c) and sets the state to 3.
// The temporaries are the arguments of an empty inline sink in one comma expression,
// which is what keeps their stack slots separate at sp+8, sp+16 and sp+24: most
// likely trace output compiled away in the shipped build.

struct SharedString;
extern "C" void string_init_8020c5c0(Ptr32<SharedString>);
extern "C" Ptr32<unsigned short> string_header_80341884(Ptr32<SharedString>);
extern "C" void string_finish_8020c5c4(Ptr32<SharedString>);
extern "C" void string_release_80341588(Ptr32<SharedString>);
extern "C" void release_header_8020bb2c(Ptr32<unsigned short>);
extern "C" Ptr32<SharedString> string_from_text_8020bb54(Ptr32<SharedString>, Ptr32<const char>);
struct SharedString {
    Ptr32<char> text;
    template <class W3dU> SharedString(Ptr32<W3dU> w3d_p) : SharedString((const char *)w3d_p.get()) {}
 SharedString(const char *s) { string_from_text_8020bb54(this, s); }
    SharedString(const SharedString &other) {
        string_init_8020c5c0(this);
        text = other.text;
        ++*string_header_80341884(this);
    }
    ~SharedString() {
        string_finish_8020c5c4(this);
        string_release_80341588(this);
    }
    SharedString &operator=(const SharedString &other) {
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
struct Props { char pad0[44]; SharedString second; char pad1[52 - 48]; SharedString first;
};
struct Asset { char pad0[36]; Ptr32<void> owner; char pad1[48 - 40]; int state; char pad2[68 - 52]; SharedString name; char pad3[76 - 72]; char held[4]; };
extern "C" Ptr32<Props> object_80240994(Ptr32<void>);
extern "C" int release_held_8020810c(Ptr32<void>);
inline void use(SharedString s) { }
extern "C" void w3d_d26k_asset_finish_8021dd04(Ptr32<Asset> self) {
use(self->name), use(object_80240994(self->owner)->first), use(object_80240994(self->owner)->second); release_held_8020810c(self->held); self->state = 3; }


