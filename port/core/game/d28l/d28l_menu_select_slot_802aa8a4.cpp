#include "w3d_ptr.h"
#line 1 "d28l_menu_select_slot_802aa8a4.cpp"
// GWMP8P rev0 0x802aa8a4. Selects the menu slot whose id matches: stops the
// current slot's control and plays its leave clip, stores the new index,
// plays the new slot's clip and restarts the highlight effect, then calls
// the refresh entry. Field names are inferred; the +208 table is a function-
// pointer view; callee prototypes follow admitted units.
struct Vec { float x, y, z; Vec(float a, float b, float c) { x = a; y = b; z = c; } };
struct Slot {
    int id;
    char u4[32];
    Ptr32<const void> clip;
    int u40;
    Ptr32<const void> fade;
    int control;
    int u52;
    int fadeHandle;
    int u60;
    int w64;
    char u68[4];
};
struct Effect;
struct EffectVt { char u[20]; Ptr32<void (Ptr32<Effect>)> start; char u24[32]; Ptr32<void (Ptr32<Effect>, int, Ptr32<Vec>)> set; };
struct Effect { Ptr32<EffectVt> vt; };
struct Menu;
struct Menu {
    char u0[140];
    int w140;
    char u144[64];
    Ptr32<Ptr32<void (Ptr32<void>)>> table;
    char u212[32];
    Ptr32<void> mesh;
    char u248[20];
    Slot slots[11];
    char u1060[12];
    int current;
    char u1076[264];
    unsigned flags;
    char u1344[16];
    Ptr32<Effect> effect;
};
extern "C" int fn_80181d00(Ptr32<void>, int);
extern "C" int fn_8018179c(Ptr32<void>, int, int);
extern "C" int fn_801817e0(Ptr32<void>, int);
extern "C" int fn_80181640(Ptr32<void>, Ptr32<const void>, Ptr32<int>, float, float, int, float);
extern "C" int d28l_menu_select_slot_802aa8a4(Ptr32<Menu> self, int id) {
    if (self->flags & 3) return 0;
    Ptr32<Slot> cur = &self->slots[self->current];
    if (cur->id == id) return 0;
    if (id == 12) return 1;
    for (int i = 0; i <= 10; i++) {
        if (self->slots[i].id == id) {
            if (!self->w140 && !self->slots[i].w64) return 1;
            if (cur->control && fn_80181d00(self->mesh, cur->control)) {
                fn_8018179c(self->mesh, cur->control, 0);
                if (cur->fade) {
                    fn_801817e0(self->mesh, cur->control);
                    fn_80181640(self->mesh, cur->fade, &cur->fadeHandle, 1.0f, 0.0f, 0, 0.0f);
                }
            }
            self->current = i;
            Ptr32<Slot> s = &self->slots[i];
            if (s->clip) {
                fn_80181640(self->mesh, s->clip, &self->slots[i].control, 1.0f, 0.0f, 0, 0.0f);
                fn_8018179c(self->mesh, s->control, 1);
            }
            if (id && self->effect) {
                Vec v(0.0f, 0.0f, 1.0f);
                self->effect->vt->set(self->effect, 3, &v);
                self->effect->vt->start(self->effect);
            }
            break;
        }
    }
    self->table[14]((Ptr32<char>)self + 28);
    return 0;
}


