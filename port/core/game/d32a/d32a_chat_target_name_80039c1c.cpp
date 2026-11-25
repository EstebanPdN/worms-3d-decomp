#include "w3d_ptr.h"
#line 1 "d32a_chat_target_name_80039c1c.cpp"
// GWMP8P rev0 0x80039c1c. Fills in the name a chat command addresses: the
// text's command class selects an empty result, the owner's team number as a
// string, or a search through the player list for the name that follows the
// command prefix, followed by a space. Names are inferred from the original
// instructions.
struct String;
extern "C" void w3d_string_base_init(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<String>);
extern "C" void w3d_string_base_finish(Ptr32<String>);
extern "C" void w3d_string_release(Ptr32<String>);
extern "C" int w3d_string_append(Ptr32<String>, Ptr32<const char>);
extern "C" void w3d_string_release_header(Ptr32<void>);
extern "C" Ptr32<String> w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" void w3d_k6b_string_from_int_8020bcc0(Ptr32<String>, int);
struct String {
    Ptr32<const char> text;
    String();
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(int);
    String(const String &o) {
        w3d_string_base_init(this);
        text = o.text;
        ++*w3d_string_header(this);
    }
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
    String &operator=(const String &o) {
        ++*(Ptr32<unsigned short>)(o.text - 6);
        Ptr32<unsigned short> h = (Ptr32<unsigned short>)(text - 6);
        if (--*h == 0) w3d_string_release_header(h);
        text = o.text;
        return *this;
    }
};
inline String operator+(const String &a, const String &b)
{
    String r = a;
    w3d_string_append(&r, b.text);
    return r;
}
struct Owner { char pad[60]; unsigned char id; };
struct Self { char pad[44]; Ptr32<const char> prefix; char pad2[12]; Ptr32<Owner> owner; };
struct Holder { char pad[36]; Ptr32<void> list; };
struct Counted { char pad[24]; unsigned int count; };
struct Named { char pad[52]; String name; String Name() const { return name; } };
extern Ptr32<Holder> g_holder_804abac0;
extern char s_80374060[], s_80373fe8[];
extern "C" int w3d_auto_80039b6c(Ptr32<Self>, Ptr32<const char>);
extern "C" unsigned int strlen(Ptr32<const char>);
extern "C" Ptr32<char> strcpy(Ptr32<char>, Ptr32<const char>);
extern "C" Ptr32<char> strstr(Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<char> w3d_heap_allocate_entry_b(unsigned int);
extern "C" Ptr32<Counted> w3d_props_get_i32_80240bcc(Ptr32<void>);
extern "C" Ptr32<void> w3d_s21_get_item_8021eb48(Ptr32<void>, unsigned int);
extern "C" Ptr32<Named> w3d_props_get_object_80240994(Ptr32<void>);
inline String FromInt(int v) { String r; w3d_k6b_string_from_int_8020bcc0(&r, v); return r; }
extern "C" int w3d_d32a_chat_target_name_80039c1c(Ptr32<Self> self, Ptr32<const char> text, Ptr32<String> out)
{
    switch (w3d_auto_80039b6c(self, text)) {
    case 0:
    case 3:
        w3d_string_assign(out, s_80374060);
        break;
    case 2:
        *out = String(self->owner->id);
        break;
    case 1: {
        Ptr32<void> list = g_holder_804abac0->list;
        if (list) {
            w3d_string_assign(out, s_80374060);
            Ptr32<char> p = w3d_heap_allocate_entry_b(strlen(text));
            strcpy(p, text);
            p = strstr(p, self->prefix) + *(Ptr32<unsigned short>)(self->prefix - 4);
            while (*p == ' ') p++;
            unsigned int i = 0;
            unsigned int n = w3d_props_get_i32_80240bcc(list)->count;
            String name;
            for (; i < n; i++) {
                Ptr32<Named> o = w3d_props_get_object_80240994(w3d_s21_get_item_8021eb48(list, i));
                name = o->Name();
                bool hit = strstr(p, (name + String(s_80373fe8)).text) == p;
                if (hit) {
                    *out = name;
                    break;
                }
            }
        }
        break;
    }
    }
    return 0;
}


