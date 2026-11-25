#include "w3d_ptr.h"
#line 1 "d28l_keyboard_press_selected_802c40b4.cpp"
// GWMP8P rev0 0x802c40b4. On-screen keyboard press: dispatches on the
// selected key. Back, cursor left and right, shift and accept each animate
// their key and play a named sound from the original data; any other key
// types its character. Key roles come from sound names and the cursor
// arithmetic; field names are inferred. The error arms cross-jump in the
// original.
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020bb2c(Ptr32<void>);
struct Header {
    unsigned short refs, length, capacity;
    void release() {
        if (!--refs)
            fn_8020bb2c(this);
    }
};
struct Str {
    Ptr32<char> p;
    Str();
    Str(const Str &);
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned short len() const { return *(Ptr32<unsigned short>)(p - 4); }
    void assign(const Str &o) {
        ++((Ptr32<Header>)(o.p - 6))->refs;
        ((Ptr32<Header>)(p - 6))->release();
        p = o.p;
    }
};
struct Res;
struct ResVt { char u0[16]; Ptr32<void (Ptr32<Res>)> destroy; };
struct Res { Ptr32<ResVt> vt; };
struct Handle {
    Ptr32<Res> r;
    Handle() { r = 0; }
    Handle(const Handle &);
    ~Handle() { if (r) r->vt->destroy(r); }
};
struct Key { Ptr32<const char> text; };
struct Font;
struct FontOwner;
struct FontOwnerVt { char u0[64]; Ptr32<Ptr32<void> (Ptr32<FontOwner>)> font; };
struct FontOwner { Ptr32<FontOwnerVt> vt; };
struct Keyboard {
    char u0[64];
    int selected;
    char u68[24];
    Ptr32<void> keys[31];
    Ptr32<void> back;
    Ptr32<void> shift;
    Ptr32<void> accept;
    Ptr32<void> right;
    Ptr32<void> left;
    char u236[8];
    Ptr32<FontOwner> fonts;
    Str item;
    char u252[4];
    Str text;
    Str command;
    int cursor;
    char u268[56];
    int commandOn;
    char u328[4];
    int cycle;
    Ptr32<void> box;
    char u340[24];
    unsigned maximum;
    float limit;
    float scale;
    int masked;
};
extern "C" unsigned fn_8020c5cc(Ptr32<Str>);
extern "C" void fn_802c43ec(Ptr32<Keyboard>, Ptr32<const char>);
extern "C" void fn_802c4744(Ptr32<Keyboard>);
extern "C" void fn_802c4998(Ptr32<Keyboard>);
extern "C" void fn_802c4080(Ptr32<Keyboard>);
extern const char s_803d8728[], s_803d8730[], s_803d873c[], s_803d8744[], s_803d874c[], s_803d8764[];
extern "C" void fn_802c814c(Ptr32<void>);
extern "C" int fn_802c8158(Ptr32<void>);
extern "C" void fn_802c6954(Ptr32<void>);
extern "C" void fn_802c4e7c(Ptr32<Keyboard>);
extern "C" void fn_802c4a7c(Ptr32<Keyboard>, int);
extern "C" void fn_802b1258(Ptr32<const char>);
extern "C" int fn_800fc1b0(Ptr32<Key>, Ptr32<Handle>);
extern "C" Ptr32<void> fn_80343744(Ptr32<void>);
extern "C" int fn_801790bc(Ptr32<void>, Ptr32<const char>);
extern "C" Ptr32<void> fn_8020c7e8(Ptr32<Str>, Ptr32<Str>, int);
extern "C" Ptr32<void> fn_8020c6a4(Ptr32<Str>, Ptr32<Str>, int);
extern "C" void fn_8020c510(Ptr32<Str>, Ptr32<const char>, ...);
extern "C" void d28l_keyboard_press_selected_802c40b4(Ptr32<Keyboard> self) {
    switch (self->selected) {
    case 32:
        fn_802c814c(self->left);
        if (self->cursor) {
            self->cursor--;
            fn_802c4744(self);
            fn_802c4998(self);
            fn_802c43ec(self, s_803d8730);
        } else {
            fn_802c43ec(self, s_803d8728);
        }
        break;
    case 33:
        fn_802c6954(self->shift);
        fn_802c4080(self);
        fn_802c43ec(self, s_803d873c);
        break;
    case 34: {
        fn_802c6954(self->accept);
        fn_802c43ec(self, s_803d873c);
        Handle h;
        if (self->item.len()) {
            Key k;
            k.text = self->item.p;
            if (fn_800fc1b0(&k, &h) >= 0) {
                fn_801790bc(fn_80343744(h.r), self->text.p);
            }
        }
        if (self->command.len() && self->commandOn) {
            fn_802b1258(self->command.p);
        }
        fn_802c4e7c(self);
        break;
    }
    case 35:
        fn_802c814c(self->right);
        if (self->cursor != fn_8020c5cc(&self->text)) {
            self->cursor++;
            fn_802c4744(self);
            fn_802c43ec(self, s_803d8730);
            fn_802c4998(self);
        } else {
            fn_802c43ec(self, s_803d8728);
        }
        break;
    case 31:
        fn_802c814c(self->back);
        if (!self->cursor || !self->text.len()) {
            fn_802c43ec(self, s_803d8728);
        } else {
            Str tail;
            Str head;
            fn_8020c7e8(&tail, &self->text, fn_8020c5cc(&self->text) - self->cursor);
            fn_8020c6a4(&head, &self->text, self->cursor - 1);
            fn_8020c510(&self->text, s_803d8744, w3d::VA(head.p), w3d::VA(tail.p));
            self->cursor--;
            fn_802c4744(self);
            fn_802c43ec(self, s_803d874c);
            fn_802c4998(self);
        }
        break;
    default:
        fn_802c814c(self->keys[self->selected]);
        fn_802c4a7c(self, fn_802c8158(self->keys[self->selected]));
        break;
    }
}


