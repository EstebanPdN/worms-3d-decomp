// Inferred team descriptor registration and observed shared-string lifetimes.
struct SharedString;
extern "C" void sol35e4a_string_init_8020c5c0(SharedString *);
extern "C" unsigned short *sol35e4a_string_header_80341884(SharedString *);
extern "C" void sol35e4a_string_finish_8020c5c4(SharedString *);
extern "C" void sol35e4a_string_release_80341588(SharedString *);
extern "C" void sol35e4a_release_header_8020bb2c(unsigned short *);

struct SharedString {
    char *text;

    // Copy construction preserves the observed external retain boundary.

    SharedString(const SharedString &other) {
        sol35e4a_string_init_8020c5c0(this);
        text = other.text;
        ++*sol35e4a_string_header_80341884(this);
    }

    ~SharedString() {
        sol35e4a_string_finish_8020c5c4(this);
        sol35e4a_string_release_80341588(this);
    }

    SharedString &operator=(const SharedString &other) {
        // The original allocation header begins six bytes before the text;
        // its reference counter is unsigned sixteen-bit, including wrapping.
        ++reinterpret_cast<unsigned short *>(other.text)[-3];
        unsigned short *header = reinterpret_cast<unsigned short *>(text) - 3;
        if (--*header == 0) {
            sol35e4a_release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};

struct StringBinding {
    unsigned header[2];
    SharedString value;
};

extern SharedString sol35e4a_empty_804b06a0[];
extern "C" {
StringBinding* sol35e4a_register_string_801ed24c(void*, const void*);
void* sol35e4a_register_scalar_801ec52c(void*, const void*);
void* sol35e4a_register_u32_801ebf38(void*, const void*);
void sol35e4a_finish_801e8d9c(void*);
extern const unsigned char sol35e4a_desc_803c806c[];
extern const unsigned char sol35e4a_desc_803c80a8[];
extern const unsigned char sol35e4a_desc_803c80d8[];
extern const unsigned char sol35e4a_desc_803c810c[];
extern const unsigned char sol35e4a_desc_803c8144[];
extern const unsigned char sol35e4a_desc_803c817c[];
extern const unsigned char sol35e4a_desc_803c81b8[];
extern const unsigned char sol35e4a_desc_803c81ec[];
extern const unsigned char sol35e4a_desc_803c8228[];
extern const unsigned char sol35e4a_desc_803c8268[];
extern const unsigned char sol35e4a_desc_803c82a8[];
extern const unsigned char sol35e4a_desc_803c82e4[];
extern const unsigned char sol35e4a_desc_803c8324[];
extern const unsigned char sol35e4a_desc_803c835c[];
extern const unsigned char sol35e4a_desc_803c8394[];
extern const unsigned char sol35e4a_desc_803c83cc[];
extern const unsigned char sol35e4a_desc_803c83fc[];
extern const unsigned char sol35e4a_desc_803c842c[];
extern const unsigned char sol35e4a_desc_803c846c[];
extern const unsigned char sol35e4a_desc_803c84a0[];
extern const unsigned char sol35e4a_desc_803c84d4[];
extern const unsigned char sol35e4a_desc_803c8500[];
extern const unsigned char sol35e4a_desc_803c8530[];

int sol35e4a_flight_descriptors_80255850(void* owner) {
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c806c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c80a8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c80d8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c810c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c8144);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c817c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c81b8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c81ec);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c8228);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c8268);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c82a8);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c82e4);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c8324);
    sol35e4a_register_u32_801ebf38(owner, sol35e4a_desc_803c835c);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c8394);
    sol35e4a_register_scalar_801ec52c(owner, sol35e4a_desc_803c83cc);
    sol35e4a_register_string_801ed24c(owner, sol35e4a_desc_803c83fc)->value =
        SharedString(sol35e4a_empty_804b06a0[0]);
    sol35e4a_register_string_801ed24c(owner, sol35e4a_desc_803c842c)->value =
        SharedString(sol35e4a_empty_804b06a0[0]);
    sol35e4a_register_string_801ed24c(owner, sol35e4a_desc_803c846c)->value =
        SharedString(sol35e4a_empty_804b06a0[0]);
    sol35e4a_register_string_801ed24c(owner, sol35e4a_desc_803c84a0)->value =
        SharedString(sol35e4a_empty_804b06a0[0]);
    sol35e4a_register_string_801ed24c(owner, sol35e4a_desc_803c84d4)->value =
        SharedString(sol35e4a_empty_804b06a0[0]);
    sol35e4a_register_string_801ed24c(owner, sol35e4a_desc_803c8500)->value =
        SharedString(sol35e4a_empty_804b06a0[0]);
    sol35e4a_register_string_801ed24c(owner, sol35e4a_desc_803c8530)->value =
        SharedString(sol35e4a_empty_804b06a0[0]);
    sol35e4a_finish_801e8d9c(owner);
    return 0;
}
}

typedef char StringSize[sizeof(SharedString) == 4 ? 1 : -1];
typedef char StringValueOffset[(unsigned)&((StringBinding*)0)->value == 8 ? 1 : -1];
