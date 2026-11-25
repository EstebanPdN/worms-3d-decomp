// Inferred object construction using observed shared-string subobject lifetimes.
struct SharedString;
extern "C" void sol35e5a_string_init_8020c5c0(SharedString *);
extern "C" unsigned short *sol35e5a_string_header_80341884(SharedString *);
extern "C" void sol35e5a_string_finish_8020c5c4(SharedString *);
extern "C" void sol35e5a_string_release_80341588(SharedString *);
extern "C" void sol35e5a_release_header_8020bb2c(unsigned short *);

struct SharedString {
    char *text;

    // A real external C++ constructor preserves the observed call lifetime.

    SharedString(const SharedString &other) {
        sol35e5a_string_init_8020c5c0(this);
        text = other.text;
        ++*sol35e5a_string_header_80341884(this);
    }

    ~SharedString() {
        sol35e5a_string_finish_8020c5c4(this);
        sol35e5a_string_release_80341588(this);
    }

    SharedString &operator=(const SharedString &other) {
        // The original allocation header begins six bytes before the text;
        // its reference counter is unsigned sixteen-bit, including wrapping.
        ++reinterpret_cast<unsigned short *>(other.text)[-3];
        unsigned short *header = reinterpret_cast<unsigned short *>(text) - 3;
        if (--*header == 0) {
            sol35e5a_release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};

struct StringBinding {
    unsigned header[2];
    SharedString value;
};

extern SharedString sol35e5a_empty_804b06a0[];
inline void *operator new(unsigned, void *place) {
    return place;
}

extern "C" void *sol35e5a_base_construct_80255120(void *);
extern const unsigned char sol35e5a_vtable_8041ba18[];
extern const float sol35e5a_default_803c8058[];

extern "C" void *sol35e5a_flight_construct_802555b0(void *object) {
    char *self = static_cast<char *>(object);
    sol35e5a_base_construct_80255120(object);
    *reinterpret_cast<const unsigned char **>(self) = sol35e5a_vtable_8041ba18;
    new (self + 580) SharedString(sol35e5a_empty_804b06a0[0]);
    new (self + 584) SharedString(sol35e5a_empty_804b06a0[0]);
    new (self + 588) SharedString(sol35e5a_empty_804b06a0[0]);
    new (self + 592) SharedString(sol35e5a_empty_804b06a0[0]);
    new (self + 596) SharedString(sol35e5a_empty_804b06a0[0]);
    new (self + 600) SharedString(sol35e5a_empty_804b06a0[0]);
    new (self + 604) SharedString(sol35e5a_empty_804b06a0[0]);
    float value = sol35e5a_default_803c8058[0];
    *reinterpret_cast<float *>(self + 608) = value;
    *reinterpret_cast<float *>(self + 612) = value;
    *reinterpret_cast<unsigned *>(self + 616) = 0;
    *reinterpret_cast<float *>(self + 620) = value;
    *reinterpret_cast<float *>(self + 624) = value;
    *reinterpret_cast<float *>(self + 628) = value;
    *reinterpret_cast<float *>(self + 632) = value;
    *reinterpret_cast<float *>(self + 636) = value;
    *reinterpret_cast<float *>(self + 640) = value;
    *reinterpret_cast<float *>(self + 644) = value;
    *reinterpret_cast<float *>(self + 648) = value;
    *reinterpret_cast<float *>(self + 652) = value;
    *reinterpret_cast<float *>(self + 656) = value;
    *reinterpret_cast<float *>(self + 660) = value;
    *reinterpret_cast<float *>(self + 664) = value;
    *reinterpret_cast<float *>(self + 668) = value;
    return object;
}

typedef char StringSize[sizeof(SharedString) == 4 ? 1 : -1];
