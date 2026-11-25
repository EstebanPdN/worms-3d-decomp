#include "w3d_ptr.h"
#line 1 "d24c_script_handle_message_80100250.cpp"
// d24c: 0x80100250 (524 bytes). Message handler of a script object. Message 64
// and 66: forward to the base, then start or stop on success, or return
// 0x80004005. Otherwise look the id up in the bindings at +384: on a match mark
// it fired and call its named handler. Script-range ids (bit 15) go to the
// substitute and format handlers or, unless the run state is 2, to a handler
// named after the message with dots replaced by underscores. Everything else
// forwards to the base. Names are inferred. One-word String and handle classes
// with user copy constructors (d24r).
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Message {
    unsigned short id;
    unsigned short Id() const { return id; }
};
struct Binding {
    unsigned char u0[4];
    Ptr32<const char> handler;  // +4
    unsigned char u8[8];
    int cache[3];         // +16
    int fired;            // +28
};
struct List {
    Ptr32<Ptr32<Binding>> start; Ptr32<Ptr32<Binding>> finish;
    unsigned size() const { return finish - start; }
    Ptr32<Binding> & operator[](int i) { return start[i]; }
};
struct Script { unsigned char u[384]; List bindings; };
extern "C" int base_8016293c(Ptr32<Script>, Ptr32<Message>);
extern "C" void start_80100490(Ptr32<Script>);
extern "C" void stop_80100744(Ptr32<Script>);
extern "C" short message_id_8015f5a0(Ptr32<int>, int);
extern "C" int id_equals_8015f65c(unsigned short, Ptr32<int>);
extern "C" void substitute_80103a5c(Ptr32<Script>);
extern "C" void format_80103c44(Ptr32<Script>);
extern "C" void call_801036f0(Ptr32<Script>, Ptr32<const char>);
extern "C" int state_80102734(Ptr32<Script>);
extern "C" int find_name_80161ffc(unsigned short, Ptr32<Ptr32<const char>>);
extern "C" Ptr32<char> strcpy(Ptr32<char>, Ptr32<const char>);
extern int a_804af16c, b_804af174;
extern "C" int d24c_script_handle_message_80100250(Ptr32<Script> self, Ptr32<Message> m) {
    unsigned short id = m->Id();
    unsigned flags = id;
    switch (m->Id()) {
    case 64:
        if (base_8016293c(self, m) >= 0) {
            start_80100490(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        if (base_8016293c(self, m) >= 0) {
            stop_80100744(self);
            return 0;
        }
        return 0x80004005;
    default: {
        for (unsigned i = 0; i < self->bindings.size(); i++) {
            if (id == (unsigned short)message_id_8015f5a0(self->bindings[i]->cache, 1)) {
                self->bindings[i]->fired = 1;
                String s(self->bindings[i]->handler);
                call_801036f0(self, s.text);
                return 0;
            }
        }
        if (flags & 0x8000) {
            if (id_equals_8015f65c(id, &a_804af16c)) {
                substitute_80103a5c(self);
            } else if (id_equals_8015f65c(id, &b_804af174)) {
                format_80103c44(self);
            } else if (state_80102734(self) != 2) {
                Ptr32<const char> name;
                char buffer[256];
                find_name_80161ffc(m->id, &name);
                strcpy(buffer, name);
                Ptr32<char> p = buffer;
                if (buffer[0]) {
                    do {
                        if (*p == '.') *p = '_';
                    } while (*++p);
                }
                call_801036f0(self, buffer);
            }
        }
        break;
    }
    }
    return base_8016293c(self, m);
}


