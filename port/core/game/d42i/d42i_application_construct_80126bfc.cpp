#include "w3d_ptr.h"
#line 1 "d42i_application_construct_80126bfc.cpp"
// d42i: 0x80126bfc. Constructs the application object: base constructor,
// clears owned references and counters, sets the default state flag word,
// publishes the object in the application global and clears two references.
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[4];
    Ptr32<int (Ptr32<Object>)> release;      // +16
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Ref {
    Ptr32<Object> p;
    void reset() { if (p) p->vtable->release(p); p = 0; }
};
struct String { Ptr32<char> text; };
struct Game {
    Ptr32<const void> vtable;
    unsigned char unknown04[120];
    Ref ref7c;   // +124
    Ref ref80;   // +128
    int value132;    // +132
    int value136;    // +136
    int value140;    // +140
    int value144;    // +144
    String text148;  // +148
    int value152;    // +152
    String text156;  // +156
    String text160;  // +160
    int value164;    // +164
    int value168;    // +168
    int value172;    // +172
    int value176;    // +176
    int value180;    // +180
    float scale;     // +184
    unsigned flags;  // +188
};
extern "C" Ptr32<Game> base_8015c4e0(Ptr32<Game>);
extern "C" Ptr32<String> string_default_803426b8(Ptr32<String>);
extern Ptr32<const void> const vtable_80410c48[];
extern Ptr32<Game> game_804b1788;
extern "C" Ptr32<Game> d42i_application_construct_80126bfc(Ptr32<Game> self) {
    base_8015c4e0(self);
    self->ref7c.p = 0;
    self->ref80.p = 0;
    self->value132 = 0;
    self->value136 = 0;
    self->value140 = 0;
    self->value144 = 0;
    self->vtable = vtable_80410c48;
    string_default_803426b8(&self->text148);
    string_default_803426b8(&self->text156);
    string_default_803426b8(&self->text160);
    game_804b1788 = self;
    self->flags = (self->flags & 0x8fffffff) | 0x02000000;
    self->flags = (self->flags & 0x8e3c3fff) | 0xc0;
    self->flags = (self->flags & 0x8e3c30cf) | 8;
    unsigned f = (self->flags & 0xfffffff9) | 0x2080;
    self->flags = f;
    self->scale = 0.5f;
    self->ref7c.reset();
    self->ref80.reset();
    self->flags = self->flags & 0x7fffffff;
    self->value180 = 0;
    self->value152 = 0;
    self->value164 = 0;
    self->value168 = 0;
    self->value172 = 0;
    f = 10;
    self->value176 = f;
    return self;
}


