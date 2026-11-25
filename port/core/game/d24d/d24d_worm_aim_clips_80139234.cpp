#include "w3d_ptr.h"
#line 1 "d24d_worm_aim_clips_80139234.cpp"
// d24d: 0x80139234 (544 bytes). Update a worm graphic's aim clips. With an aim clip
// (+648): take the worm's yaw (+116), blended halfway with the stored one unless
// `snap` is set, store it (+580), fade the clip (+644) by the graphic value 0x8013c844,
// and in mode 16 also fade "AimPigeon" on the secondary mesh (+168). Without one: snap
// the clip (0x80135a70, control +472) and the secondary clip (+656, control +484). If
// an attachment (+164) exists, types 43 and 50 snap the resource's non-empty idle
// (control +488), and type 17 starts the "Hold.Quake" sound (+532) at +52. The float
// literals form this function's pool at 0x8039f66c.
struct d24d_Object { Ptr32<Ptr32<void>> vtable; };
struct d24d_Resource { char pad[80]; Ptr32<const char> idle; };
struct d24d_WormInfo { char pad[116]; float yaw; char pad2[12]; unsigned type; };
struct d24d_WormGraphic { char pad[52]; char pos[60]; int worm; char pad1[48]; Ptr32<d24d_Object> att; Ptr32<d24d_Object> mesh; char pad2[300]; int c472; char pad3[8]; int c484; int c488; char pad4[40]; Ptr32<d24d_Object> sound; char pad5[44]; float yaw; char pad6[60]; Ptr32<const char> clip; int alt; char pad7[4]; Ptr32<const char> clip2; char pad8[24]; int mode; };
extern "C" Ptr32<d24d_WormInfo> d24d_worm_info_800fc6dc(int);
extern "C" float d24d_blend_value_8013c844(Ptr32<d24d_WormGraphic>);
extern "C" int d24d_mesh_fade_80181884(Ptr32<d24d_Object>, Ptr32<const char>, float, float);
extern "C" int d24d_mesh_fade_named_80181814(Ptr32<d24d_Object>, Ptr32<const char>, float, float);
extern "C" int d24d_play_clip_80135a70(Ptr32<d24d_WormGraphic>, Ptr32<d24d_Object>, Ptr32<const char>, Ptr32<int>, float, float, float);
extern "C" int d24d_play_named_801359ec(Ptr32<d24d_WormGraphic>, Ptr32<d24d_Object>, Ptr32<const char>, Ptr32<int>, float, float, float);
extern "C" Ptr32<void> d24d_resource_lookup_800fc330(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<d24d_Resource>>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern Ptr32<const char> d24d_resource_table_803eb63c[];
extern const char d24d_aim_pigeon_8039f3ac[], d24d_empty_8039f59c[], d24d_hold_quake_8039f660[];
extern struct w3d_anon_1980 { char pad[108]; Ptr32<d24d_Object> audio; }; extern Ptr32<w3d_anon_1980> d24d_game_804b1788;
inline bool d24d_differs(Ptr32<const char> a, Ptr32<const char> b) { return strcmp(a, b) != 0; }
inline Ptr32<d24d_Resource> d24d_resource_for(Ptr32<Ptr32<const char>> key) { Ptr32<d24d_Resource> r; d24d_resource_lookup_800fc330(key, &r); return r; }
extern "C" void d24d_worm_aim_clips_80139234(Ptr32<d24d_WormGraphic> self, Ptr32<d24d_Object> mesh, int snap) {
    if (self->alt != 0) {
        float yaw = d24d_worm_info_800fc6dc(self->worm)->yaw;
        self->yaw = snap ? yaw : (yaw - self->yaw) * 0.5f + self->yaw;
        Ptr32<const char> c = self->clip;
        d24d_mesh_fade_80181884(mesh, c, d24d_blend_value_8013c844(self), 1.0f);
        if (self->mode == 16) {
            Ptr32<d24d_Object> m = self->mesh;
            if (m) d24d_mesh_fade_named_80181814(m, d24d_aim_pigeon_8039f3ac, d24d_blend_value_8013c844(self), 1.0f);
        }
    } else {
        d24d_play_clip_80135a70(self, mesh, self->clip, &self->c472, 1.0f, 0.0f, 0.0f);
        if (self->mesh) d24d_play_named_801359ec(self, self->mesh, self->clip2, &self->c484, 1.0f, 0.0f, 0.0f);
        if (self->att) {
            unsigned type = d24d_worm_info_800fc6dc(self->worm)->type;
            switch (type) {
            case 43: case 50: {
                Ptr32<d24d_Resource> r = d24d_resource_for(&d24d_resource_table_803eb63c[type]);
                if (d24d_differs(r->idle, d24d_empty_8039f59c)) d24d_play_named_801359ec(self, self->att, r->idle, &self->c488, 1.0f, 0.0f, 0.0f);
                break; }
            case 17:
                if (d24d_game_804b1788->audio) {
                    ((Ptr32<void (Ptr32<d24d_Object>, Ptr32<const char>, Ptr32<Ptr32<d24d_Object>>)>)d24d_game_804b1788->audio->vtable[23])(d24d_game_804b1788->audio, d24d_hold_quake_8039f660, &self->sound);
                    ((Ptr32<void (Ptr32<d24d_Object>, int, Ptr32<char>)>)self->sound->vtable[14])(self->sound, 3, self->pos);
                    ((Ptr32<void (Ptr32<d24d_Object>)>)self->sound->vtable[5])(self->sound);
                }
                break;
            }
        }
    }
}


