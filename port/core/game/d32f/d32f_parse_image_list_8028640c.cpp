#include "w3d_ptr.h"
#line 1 "d32f_parse_image_list_8028640c.cpp"
// GWMP8P rev0 0x8028640c. Parses the box's colon-separated resource list:
// for each entry, takes a resource name, an optional index and a label,
// loads the resource, attaches it to the owner and places it, then appends
// an entry of handle, index and label to the vector at +224. Observed
// partial layouts, roles inferred. Uses unmodified STLport 4.5.3. The by-
// value Note call is the discarded copy the original makes before the error
// format.
#include "compat/stlport_sn_oom.h"
#include <vector>
extern "C" void w3d_string_base_init(Ptr32<void>), w3d_string_base_finish(Ptr32<void>), w3d_string_release(Ptr32<void>), w3d_string_release_header(Ptr32<void>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<void>);
struct String_803426b8 {
    Ptr32<char> text;
    String_803426b8();
    String_803426b8(const String_803426b8 &o) { w3d_string_base_init(this); text = o.text; ++*w3d_string_header(this); }
    ~String_803426b8() { w3d_string_base_finish(this); w3d_string_release(this); }
    String_803426b8 &operator=(const String_803426b8 &other) {
        ++*(Ptr32<unsigned short>)(other.text - 6);
        Ptr32<char> old = text;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short references = --*header;
        if (!references)
            w3d_string_release_header(header);
        text = other.text;
        return *this;
    }
    unsigned Length() const { return ((Ptr32<unsigned short>)text)[-2]; }
};
typedef String_803426b8 String;
struct Obj;
struct ObjVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Obj>)> retain; Ptr32<void (Ptr32<Obj>)> release; Ptr32<void> u20[16]; Ptr32<void (Ptr32<Obj>, Ptr32<void>, int)> place; Ptr32<void> u88; Ptr32<void (Ptr32<Obj>, Ptr32<Obj>, int)> attach; };
struct Obj { Ptr32<ObjVt> vt; };
struct Handle {
    Ptr32<Obj> p;
    Handle() : p(0) {}
    Handle(const Handle &o) : p(o.p) { if (p) p->vt->retain(p); }
    ~Handle() { if (p) p->vt->release(p); }
    Handle &operator=(const Handle &);
};
struct Entry {
    Handle object;
    int index;
    String name;
    Entry() {}
    Entry(const Entry &o) : object(o.object), index(o.index), name(o.name) {}
    Entry &operator=(const Entry &);
};
struct Config { char u0[20]; char place[116]; String names; };
struct Box {
    char u0[28]; char sub[4]; unsigned char base; char u32[3]; char u36[4]; Ptr32<Config> config; char u44[64]; char error[4]; Ptr32<Obj> owner; char u116[100]; int mode; char u220[4];
    std::vector<Entry> items;
};
extern char lbl_803cf460[], lbl_803cf494[], lbl_803cf498[], lbl_803cf418[];
extern "C" void fn_80285ee0(Ptr32<Box>);
extern "C" Ptr32<String> w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" void w3d_cx11b_string_truncate_8020c3a0(Ptr32<String>, int);
extern "C" Ptr32<String> sol35d12_assign_8020c0fc(Ptr32<String>, Ptr32<const String>, int);
extern "C" int fn_802b1510(Ptr32<void>, Ptr32<const char>, Ptr32<Handle>, unsigned char);
extern "C" void w3d_string_format(Ptr32<void>, Ptr32<const char>, ...);
inline void Note(String) {}
extern "C" void d32f_parse_image_list_8028640c(Ptr32<Box> self) {
    Ptr32<Config> c = self->config;
    if (c->names.Length()) {
        fn_80285ee0(self);
        String rest(c->names);
        String part[3];
        int index = 0;
        int left = rest.Length();
        if (left) do {
            Ptr32<const char> text = rest.text;
            Entry e;
            w3d_string_assign(&part[0], lbl_803cf460);
            w3d_string_assign(&part[1], lbl_803cf460);
            w3d_string_assign(&part[2], lbl_803cf460);
            int n = strcspn(text, lbl_803cf494);
            part[0] = rest;
            w3d_cx11b_string_truncate_8020c3a0(&part[0], n);
            int stop = text[n];
            left += -1 - n;
            sol35d12_assign_8020c0fc(&rest, &rest, left < 0 ? 0 : left);
            if (stop == 58) {
                text = rest.text;
                n = strcspn(text, lbl_803cf494);
                part[1] = rest;
                w3d_cx11b_string_truncate_8020c3a0(&part[1], n);
                stop = text[n];
                left += -1 - n;
                sol35d12_assign_8020c0fc(&rest, &rest, left < 0 ? 0 : left);
                if (stop == 58) {
                    n = strcspn(rest.text, lbl_803cf498);
                    part[2] = rest;
                    w3d_cx11b_string_truncate_8020c3a0(&part[2], n);
                    left += -1 - n;
                    sol35d12_assign_8020c0fc(&rest, &rest, left < 0 ? 0 : left);
                }
            }
            if (part[0].Length() == 0)
                break;
            if (fn_802b1510(self->sub, part[0].text, &e.object, self->mode == 1 ? self->base + 31 : self->base + 30) < 0) {
                Note(part[0]);
                w3d_string_format(self->error, lbl_803cf418, w3d::VA(part[0].text));
            } else {
                self->owner->vt->attach(self->owner, e.object.p, 0);
                e.object.p->vt->place(e.object.p, self->config->place, 0);
            }
            if (part[1].Length())
                index = atoi(part[1].text);
            e.index = index;
            index++;
            e.name = part[2];
            self->items.push_back(e);
        } while (rest.Length());
    }
}


