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

// Inferred contiguous tail: all seven string slots and following scalar
// fields are independently witnessed. This grouping adds no storage.
struct FlightFields {
    SharedString string0, string1, string2, string3, string4, string5, string6;
    float scalar0, scalar1;
    unsigned flags;
    float scalar2, scalar3, scalar4, scalar5, scalar6, scalar7, scalar8;
    float scalar9, scalar10, scalar11, scalar12, scalar13, scalar14;

    FlightFields(const SharedString &empty)
        : string0(empty), string1(empty), string2(empty), string3(empty),
          string4(empty), string5(empty), string6(empty) {
        float value = sol35e5a_default_803c8058[0];
        scalar0 = value;
        scalar1 = value;
        flags = 0;
        scalar2 = value;
        scalar3 = value;
        scalar4 = value;
        scalar5 = value;
        scalar6 = value;
        scalar7 = value;
        scalar8 = value;
        scalar9 = value;
        scalar10 = value;
        scalar11 = value;
        scalar12 = value;
        scalar13 = value;
        scalar14 = value;
    }
};

typedef char FlightFieldsSize[sizeof(FlightFields) == 92 ? 1 : -1];
extern "C" void *sol35e5a_flight_construct_802555b0_v3(void *object) {
    char *self = static_cast<char *>(object);
    sol35e5a_base_construct_80255120(object);
    *reinterpret_cast<const unsigned char **>(self) = sol35e5a_vtable_8041ba18;
    new (self + 580) FlightFields(sol35e5a_empty_804b06a0[0]);
    return object;
}
