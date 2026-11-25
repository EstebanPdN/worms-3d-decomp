#include "w3d_ptr.h"
#line 1 "d28l_panel_update_802b0668.cpp"
// GWMP8P rev0 0x802b0668. Per-frame panel update: finishes a pending load,
// resets or enters the mesh control, clears the scale once the control is
// ready, moves or restarts the highlight effect at the panel's position,
// tracks the activity flag and runs the check entry. Field names are
// inferred; the +180 table is a function-pointer view.
struct Vec { float x, y, z; Vec() {} Vec(float a) { x = a; y = a; z = a; } };
struct Panel;
struct Effect;
struct EffectVt { char u20[20]; Ptr32<void (Ptr32<Effect>)> start; char u24[12]; Ptr32<int (Ptr32<Effect>)> playing; char u40[16]; Ptr32<void (Ptr32<Effect>, int, Ptr32<Vec>)> set; };
struct Effect { Ptr32<EffectVt> vt; };
struct Node;
struct NodeVt { char u76[76]; Ptr32<void (Ptr32<Node>, Ptr32<Vec>, int)> scale; };
struct Node { Ptr32<NodeVt> vt; };
struct PanelVt {
    char u0[20];
    Ptr32<void (Ptr32<Panel>, int)> finish;
    char u24[16];
    Ptr32<void (Ptr32<Panel>, int)> enable;
    char u44[12];
    Ptr32<void (Ptr32<Panel>)> leave;
    Ptr32<int (Ptr32<Panel>)> check;
};
struct Panel {
    int id;
    char u4[80];
    Ptr32<Node> node;
    Ptr32<void> mesh;
    int control;
    int w96;
    char u100[8];
    int w108;
    char u112[4];
    int w116;
    int w120;
    char u124[4];
    int active;
    Ptr32<Effect> effect;
    char u136[12];
    int w148;
    int w152;
    int w156;
    char u160[4];
    int w164;
    char u168[12];
    Ptr32<PanelVt> vt;
};
extern int current_804abb5c;
extern "C" Ptr32<void> fn_80343584(Ptr32<void>);
extern "C" int fn_80181ccc(Ptr32<void>, int);
extern "C" int fn_80181d00(Ptr32<void>, int);
extern "C" void fn_802b1cec(Ptr32<Panel>);
extern "C" void fn_802b2164(Ptr32<Panel>);
extern "C" void fn_802b24bc(Ptr32<Panel>);
extern "C" Vec fn_802b22e4(Ptr32<Panel>);
extern "C" void d28l_panel_update_802b0668(Ptr32<Panel> self) {
    if (self->w152 && !self->w164) {
        self->vt->finish(self, self->w156);
        self->w152 = 0;
    }
    if (self->mesh) {
        if (self->w96) {
            if (fn_80181ccc(fn_80343584(self->mesh), self->control)) {
                fn_802b1cec(self);
            }
        } else if (!self->w164 && self->w148 == 1) {
            fn_802b2164(self);
        }
    }
    if (self->w120) {
        int ready = 0;
        if (!self->w96 || fn_80181d00(fn_80343584(self->mesh), self->control)) {
            ready = 1;
        }
        if (ready) {
            self->w120 = 0;
            Vec v(0.0f);
            self->node->vt->scale(self->node, &v, 0);
        }
    }
    if (self->effect) {
        Vec pos;
        pos = fn_802b22e4(self);
        if (self->w108) {
            if (self->w116 == 1) {
                if (!self->w96) {
                    self->effect->vt->set(self->effect, 3, &pos);
                    self->effect->vt->start(self->effect);
                    self->w116 = 0;
                } else if (fn_80181d00(fn_80343584(self->mesh), self->control)) {
                    self->effect->vt->set(self->effect, 3, &pos);
                    self->effect->vt->start(self->effect);
                    self->w116 = 0;
                }
            } else if (!self->effect->vt->playing(self->effect)) {
                fn_802b24bc(self);
            } else {
                self->effect->vt->set(self->effect, 3, &pos);
            }
        }
    }
    int active = current_804abb5c == self->id;
    if (active != self->active) {
        if (!self->active && self->w148) {
            self->vt->leave(self);
        }
        self->active = active;
    }
    if (self->vt->check(self)) {
        self->vt->enable(self, 1);
    }
}


