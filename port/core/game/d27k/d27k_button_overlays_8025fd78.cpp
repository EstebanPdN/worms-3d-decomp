#include "w3d_ptr.h"
#line 1 "d27k_button_overlays_8025fd78.cpp"
// Button overlays load (Worms 3D GameCube PAL, 0x8025fd78).
// 
// When the settings name a texture base, loads its Highlight, Grey and colour variants through the
// loader at +28 and adds them to the scene, scaling the highlight by the settings scale unless it is
// zero; a failed load formats the error text at +108. Ends with 0x8026026c. Field names are inferred.

struct String_803426b8;
extern "C" void string_finish_8020c5c4(Ptr32<String_803426b8>);
extern "C" void string_release_80341588(Ptr32<String_803426b8>);
struct String_803426b8 {
    Ptr32<char> text;
    String_803426b8();
    String_803426b8(const String_803426b8 &);
    ~String_803426b8() {
        string_finish_8020c5c4(this);
        string_release_80341588(this);
    }
};
struct Vec { float x, y, z; Vec() {} Vec(float a, float b, float c) { x = a; y = b; z = c; } };
struct Object;
struct ObjectTable { Ptr32<void> pad[21]; Ptr32<int (Ptr32<Object>, Ptr32<const Vec>, int)> setSize; Ptr32<int (Ptr32<Object>, int)> setMode; };
struct Object { Ptr32<ObjectTable> table; };
struct Scene;
struct SceneTable { Ptr32<void> pad[23]; Ptr32<int (Ptr32<Scene>, Ptr32<Object>, int)> add; };
struct Scene { Ptr32<SceneTable> table; };
struct Settings { char pad0[20]; Vec size; char pad1[116 - 32]; float scale; int colour; Ptr32<char> name; };
struct Loader { int load_802b1510(Ptr32<char>, Ptr32<Ptr32<Object>>, unsigned char); char pad[4]; unsigned char index; char w3d_tag_rest[3]; };
struct Button { char pad0[28]; Loader loader; char pad1[40 - 36]; Ptr32<Settings> settings; char pad2[108 - 44]; String_803426b8 error; Ptr32<Scene> scene; char pad3[216 - 116]; int alt; char pad4[232 - 220]; Ptr32<Object> colourMesh; Ptr32<Object> highlight; Ptr32<Object> grey; };
extern "C" void format_8020c510(Ptr32<String_803426b8>, Ptr32<const char>, ...);
extern "C" void assign_8020bd38(Ptr32<String_803426b8>, Ptr32<const char>);
extern const char text_803cab08[], text_803cab14[], text_803cab38[], text_803cab40[], text_803cab48[], text_803cab50[], text_803cab58[], text_803cab5c[];
extern float zero_803cab90[], one_803cab94[];
extern "C" void finish_8026026c(Ptr32<Button>);
extern "C" void w3d_d27k_button_overlays_8025fd78(Ptr32<Button> self) {
    Ptr32<Settings> set = self->settings;
    String_803426b8 name;
    if (*(Ptr32<unsigned short>)(set->name - 4)) {
        format_8020c510(&name, set->name, w3d::VA(text_803cab08));
        if (self->loader.load_802b1510(name.text, &self->highlight, self->alt == 0 ? self->loader.index + 31 : self->loader.index + 30) < 0) {
            format_8020c510(&self->error, text_803cab14, w3d::VA(name.text));
        } else {
            self->scene->table->add(self->scene, self->highlight, 0);
            float scale = set->scale;
            if (scale == zero_803cab90[0]) {
                self->highlight->table->setSize(self->highlight, &self->settings->size, 0);
            } else {
                Vec v;
                Ptr32<Vec> p = &v;
                float x = self->settings->size.x, y = self->settings->size.y, z = one_803cab94[0];
                Ptr32<Object> h = self->highlight;
                v.y = y * scale;
                v.x = x * scale;
                p->z = z;
                h->table->setSize(h, p, 0);
            }
            self->highlight->table->setMode(self->highlight, 0);
        }
        format_8020c510(&name, set->name, w3d::VA(text_803cab38));
        if (self->loader.load_802b1510(name.text, &self->grey, self->alt == 0 ? self->loader.index + 31 : self->loader.index + 30) >= 0) {
            self->scene->table->add(self->scene, self->grey, 0);
            self->grey->table->setSize(self->grey, &self->settings->size, 0);
            self->grey->table->setMode(self->grey, 0);
        }
        if (set->colour) {
            switch (set->colour) {
            case 1: format_8020c510(&name, set->name, w3d::VA(text_803cab40)); break;
            case 2: format_8020c510(&name, set->name, w3d::VA(text_803cab48)); break;
            case 3: format_8020c510(&name, set->name, w3d::VA(text_803cab40)); break;
            case 4: format_8020c510(&name, set->name, w3d::VA(text_803cab50)); break;
            case 5: format_8020c510(&name, set->name, w3d::VA(text_803cab58)); break;
            default: assign_8020bd38(&name, text_803cab5c); break;
            }
            if (self->loader.load_802b1510(name.text, &self->colourMesh, self->alt == 0 ? self->loader.index + 31 : self->loader.index + 30) < 0) {
                format_8020c510(&self->error, text_803cab14, w3d::VA(name.text));
            } else {
                self->scene->table->add(self->scene, self->colourMesh, 0);
                self->colourMesh->table->setSize(self->colourMesh, &self->settings->size, 0);
            }
        }
    }
    finish_8026026c(self);
}


