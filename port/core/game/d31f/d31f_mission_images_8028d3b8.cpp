#include "w3d_ptr.h"
#line 1 "d31f_mission_images_8028d3b8.cpp"
// GWMP8P rev0 0x8028d3b8. Resolves the two image names of a frontend mission
// panel and loads each into its view, using a temporary mission texture when
// the image is a cached one, and reports a missing file through the error
// text and the info fallback.
struct Obj { Ptr32<Ptr32<void>> vtable; };
inline void release(Ptr32<Obj> p) { ((Ptr32<void (Ptr32<Obj>)>)p->vtable[4])(p); }
extern "C" void w3d_string_base_init(Ptr32<void>), w3d_string_base_finish(Ptr32<void>), w3d_string_release(Ptr32<void>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<void>);
struct String {
    Ptr32<char> text;
    String();
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &o) {
        w3d_string_base_init(this);
        text = o.text;
        ++*w3d_string_header(this);
    }
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
    unsigned short length() const { return *(Ptr32<unsigned short>)(text - 4); }
};
struct Ref {
    Ptr32<Obj> p;
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 Ref &operator=(Obj *q) {
        if (p) release(p);
        p = q;
        return *this;
    }
};
struct Data { char pad[20]; char transform[104]; String second; String first; };
struct Self { char pad[28]; char owner[4]; unsigned char level; char w3d_tag_rest[3]; char pad36[4]; Ptr32<Data> data; char pad44[64]; String error; Ptr32<Obj> list; char pad116[100]; Ref a, b; };
extern char lbl_803cff40[], lbl_803cff88[], lbl_803cffac[];
extern "C" int w3d_f9a_image_resolve_8028d8ec(Ptr32<Self>, String, String &);
extern "C" int w3d_f3a_suffix_8028dcd8(Ptr32<Self>, String);
extern "C" int w3d_named_suffix_802b1510(Ptr32<char>, Ptr32<const char>, Ptr32<Ref>, unsigned char);
extern "C" int w3d_handle_set_name(Ptr32<String>, Ptr32<Ref>, unsigned char);
extern "C" Ptr32<Obj> w3d_empty_8034357c(Ptr32<Obj>); Ptr32<Obj> w3d_empty_80343808(Ptr32<Obj>);
extern "C" int fn_801712c4(Ptr32<Obj>, Ptr32<const char>);
extern "C" void w3d_string_format(Ptr32<String>, Ptr32<const char>, ...);
extern "C" int w3d_s20_store_byte_value_80173f88(Ptr32<Obj>, const unsigned char &);
inline void Add(Ptr32<Self> self, Ptr32<Obj> o) { ((Ptr32<int (Ptr32<Obj>, Ptr32<Obj>, int)>)self->list->vtable[23])(self->list, o, 0); }
inline void Remove(Ptr32<Self> self, Ptr32<Obj> o) { ((Ptr32<int (Ptr32<Obj>, Ptr32<Obj>)>)self->list->vtable[24])(self->list, o); }
inline void Place(Ptr32<Self> self, Ptr32<Obj> o) { ((Ptr32<int (Ptr32<Obj>, Ptr32<char>, int)>)o->vtable[21])(o, self->data->transform, 0); }
inline Ptr32<Obj> Sub(Ptr32<Obj> o) { return ((Ptr32<Ptr32<Obj> (Ptr32<Obj>)>)o->vtable[16])(o); }
extern "C" void d31f_mission_images_8028d3b8(Ptr32<Self> self) {
    Ptr32<Data> data = self->data;
    String file;
    int mode = w3d_f9a_image_resolve_8028d8ec(self, data->first, file);
    if (w3d_f3a_suffix_8028dcd8(self, file)) {
        Ptr32<Ref> slot = &self->a;
        if (self->a.p == 0) {
            w3d_named_suffix_802b1510(self->pad + 28, lbl_803cff40, slot, self->level + 30);
            Add(self, self->a.p);
            Place(self, self->a.p);
        }
        if (fn_801712c4(w3d_empty_80343808(Sub(w3d_empty_8034357c(self->a.p))), file.text) < 0) {
            w3d_string_format(&self->error, lbl_803cff88, w3d::VA(file.text));
            String name(lbl_803cffac);
            w3d_handle_set_name(&name, slot, self->level + 30);
        }
    } else if (file.length() != 0) {
        if (self->a.p) {
            Remove(self, self->a.p);
            self->a = 0;
        }
        Ptr32<Ref> slot = &self->a;
        if (w3d_named_suffix_802b1510(self->pad + 28, file.text, slot, self->level + 30) < 0) {
            w3d_string_format(&self->error, lbl_803cff88, w3d::VA(file.text));
            String name(lbl_803cffac);
            w3d_handle_set_name(&name, slot, self->level + 30);
        }
        Add(self, self->a.p);
        Place(self, self->a.p);
        w3d_s20_store_byte_value_80173f88(w3d_empty_8034357c(self->a.p), mode);
    }
    if (data->second.length() != 0) {
        mode = w3d_f9a_image_resolve_8028d8ec(self, data->second, file);
        if (w3d_f3a_suffix_8028dcd8(self, file)) {
            Ptr32<Ref> slot = &self->b;
            if (self->b.p == 0) {
                w3d_named_suffix_802b1510(self->pad + 28, lbl_803cff40, slot, self->level + 30);
                Add(self, self->b.p);
                Place(self, self->b.p);
            }
            if (fn_801712c4(w3d_empty_80343808(Sub(w3d_empty_8034357c(self->b.p))), file.text) < 0) {
                w3d_string_format(&self->error, lbl_803cff88, w3d::VA(file.text));
                String name(lbl_803cffac);
                w3d_handle_set_name(&name, slot, self->level + 30);
            }
        } else {
            if (self->b.p) {
                Remove(self, self->b.p);
                self->b = 0;
            }
            if (w3d_named_suffix_802b1510(self->pad + 28, file.text, &self->b, self->level + 30) < 0) {
                w3d_string_format(&self->error, lbl_803cff88, w3d::VA(file.text));
                self->b = 0;
            } else {
                Add(self, self->b.p);
                Place(self, self->b.p);
                w3d_s20_store_byte_value_80173f88(w3d_empty_8034357c(self->b.p), mode);
            }
        }
    }
}


