#include "w3d_ptr.h"
#line 1 "sol35e2_choose_string_8027befc.cpp"
// GWMP8P rev0: observed GC32 shared-string selection and lifetimes.
// Names and complete container identities remain inferred. Only each list's
// first pointer and the sixteen-byte spacing are established in this body.
struct Sol35e2String_8020bb54;
extern "C" void sol35e2_string_init_8020c5c0(Ptr32<Sol35e2String_8020bb54>);
extern "C" Ptr32<unsigned short> sol35e2_string_header_80341884(Ptr32<Sol35e2String_8020bb54>);
extern "C" void sol35e2_string_finish_8020c5c4(Ptr32<Sol35e2String_8020bb54>);
extern "C" void sol35e2_string_release_80341588(Ptr32<Sol35e2String_8020bb54>);
extern "C" void sol35e2_release_header_8020bb2c(Ptr32<unsigned short>);
extern const char sol35e2_failed_803cea20[];

struct Sol35e2String_8020bb54 {
    Ptr32<char> text;

    // A real external C++ constructor preserves the observed call lifetime.
    template <class W3dU> Sol35e2String_8020bb54(Ptr32<W3dU> w3d_p) : Sol35e2String_8020bb54((const char *)w3d_p.get()) {}
 Sol35e2String_8020bb54(const char *);

    Sol35e2String_8020bb54(const Sol35e2String_8020bb54 &other) {
        sol35e2_string_init_8020c5c0(this);
        text = other.text;
        ++*sol35e2_string_header_80341884(this);
    }

    ~Sol35e2String_8020bb54() {
        sol35e2_string_finish_8020c5c4(this);
        sol35e2_string_release_80341588(this);
    }

    Sol35e2String_8020bb54 &operator=(const Sol35e2String_8020bb54 &other) {
        // The original allocation header begins six bytes before the text;
        // its reference counter is unsigned sixteen-bit, including wrapping.
        ++reinterpret_cast<unsigned short *>(w3d::R(other.text))[-3];
        Ptr32<unsigned short> header = reinterpret_cast<unsigned short *>(w3d::R(text)) - 3;
        if (--*header == 0) {
            sol35e2_release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};

struct Sol35e2StringIterator {
    Ptr32<Sol35e2String_8020bb54> position;

    template <class W3dU> Sol35e2StringIterator(Ptr32<W3dU> w3d_p) : Sol35e2StringIterator((Sol35e2String_8020bb54 *)w3d_p.get()) {}
 Sol35e2StringIterator(Sol35e2String_8020bb54 *value) : position(value) {}

    Sol35e2StringIterator operator+(int index) const {
        return Sol35e2StringIterator(position + index);
    }

    Sol35e2String_8020bb54 &operator*() const {
        return *position;
    }
};

struct Sol35e2StringList {
    Ptr32<Sol35e2String_8020bb54> first;
    unsigned char unknown04[12];

    Sol35e2String_8020bb54 &operator[](unsigned index) {
        return *(Sol35e2StringIterator(first) + index);
    }
};

struct Sol35e2StringTable {
    unsigned char unknown00[28];
    Sol35e2StringList first, second, third, fourth, fifth;
};

extern "C" Sol35e2String_8020bb54 sol35e2_choose_string_8027befc(
    Ptr32<Sol35e2StringTable> self, int kind, unsigned index) {
    Sol35e2String_8020bb54 result(sol35e2_failed_803cea20);
    switch (kind) {
    case 0:
        result = self->first[index];
        break;
    case 4:
        result = self->second[index];
        break;
    case 3:
        result = self->third[index];
        break;
    case 5:
        result = self->fourth[index];
        break;
    case 6:
        result = self->fifth[index];
        break;
    }
    return result;
}

#define SOL35E2_OFFSET(M, N) typedef char sol35e2_offset_##M[(__builtin_offsetof(Sol35e2StringTable,M)) == N ? 1 : -1]
SOL35E2_OFFSET(first, 28);
SOL35E2_OFFSET(second, 44);
SOL35E2_OFFSET(third, 60);
SOL35E2_OFFSET(fourth, 76);
SOL35E2_OFFSET(fifth, 92);
#undef SOL35E2_OFFSET
typedef char sol35e2_string_size[sizeof(Sol35e2String_8020bb54) == 4 ? 1 : -1];
typedef char sol35e2_string_list_stride[sizeof(Sol35e2StringList) == 16 ? 1 : -1];


