/*
 * 0x80138a18: play the fire animation of a worm's current weapon.
 *
 * While the worm is in state 3..6, 26 or 36 nothing happens unless the
 * weapon is 13. The weapon comes from the worm's actor record (index query
 * 0x800fc6dc, word +132); its property block (weapon name table 0x803eb63c,
 * reader 0x800fc330) supplies the fire animation name at +84. The body is
 * aimed (0x80139234) and plays that animation (0x801359ec); the hat plays it
 * too when present. Weapon 49 starts the body animation at a delay. The
 * held item then plays a weapon-specific animation or triggers an effect on
 * the context's effect service (vtable slot 24, at the worm's position):
 * 43 scales effect + reset + "UtilityScales" global effect, 0 bazooka (then
 * 0x8013f2a4), 26 nuke animation + effect, 50 surrender, 10 bat, 12 axe
 * (then the trail attach 0x8013f5c4), 17 quake effect, 53 Redbull effect.
 *
 * Offsets are observed; field names are inferred. Literal floats and strings
 * are referenced as the original read-only objects.
 */
struct D20dFireObject { void **vtable; };
struct D20dFireVec { float x, y, z; };
struct D20dFireWorm {
    char unknown00[28]; D20dFireObject *body;
    char unknown20[20]; D20dFireVec position;
    char unknown40[48]; int handle;
    char unknown74[48]; D20dFireObject *held, *hat;
    char unknownac[300]; int animation;
    char unknown1dc[8]; int hatAnimation, heldAnimation;
    char unknown1ec[4]; int state;
    char unknown1f4[184]; unsigned weapon;
};
struct D20dFireProperty { char unknown00[84]; const char *fire; };
struct D20dFireActor { char unknown00[132]; unsigned weapon; };
struct D20dFireContext { char unknown00[108]; D20dFireObject *effects; };
typedef void (*D20dEffectPlay)(D20dFireObject *service, const char *name, D20dFireVec *at);

extern "C" {
extern D20dFireContext *w3d_context_804b1788;
extern const char *w3d_weapon_names_803eb63c[];
extern float w3d_f32_8039f628[], w3d_f32_8039f62c[], w3d_f32_8039f630[];
extern const char w3d_str_8039f5bc[], w3d_str_8039f5c8[], w3d_str_8039f5d8[], w3d_str_8039f5e4[], w3d_str_8039f5f0[];
extern const char w3d_str_8039f4f4[], w3d_str_8039f5fc[], w3d_str_8039f604[], w3d_str_8039f60c[], w3d_str_8039f618[];
D20dFireActor *s8_index_query_800fc6dc(int index);
void * w3d_auto_800fc330(const char **name, D20dFireProperty **out);
D20dFireObject *w3d_empty_80343584(D20dFireObject *object);
int fn_80139234(D20dFireWorm *worm, D20dFireObject *mesh, int flag);
int w3d_worm_play_named_801359ec(D20dFireWorm *worm, D20dFireObject *mesh, const char *name, int *control, float speed, float start, float end);
void w3d_auto_8013f08c(D20dFireWorm *worm);
void w3d_auto_8013f2a4(D20dFireWorm *worm, D20dFireObject *held);
void k4a_weapon_attach_trail_8013f5c4(D20dFireWorm *worm, D20dFireObject *held);
int w3d_s20_forward_global_800e5ca4(D20dFireVec *at, const char *name, int flag, float value);
void d20d_worm_fire_animation_80138a18(D20dFireWorm *s);
}

void d20d_worm_fire_animation_80138a18(D20dFireWorm *s)
{
    switch (s->state) {
    case 26: case 3: case 4: case 5: case 6: case 36:
        if (s->weapon != 13) return;
        break;
    }
    float delay = w3d_f32_8039f628[0];
    D20dFireActor *a = s8_index_query_800fc6dc(s->handle);
    unsigned weapon = a->weapon;
    D20dFireProperty *output;
    w3d_auto_800fc330(w3d_weapon_names_803eb63c + weapon, &output);
    D20dFireProperty *p = output;
    if (weapon == 49) delay = w3d_f32_8039f62c[0];
    fn_80139234(s, w3d_empty_80343584(s->body), 1);
    w3d_worm_play_named_801359ec(s, s->body, p->fire, &s->animation, w3d_f32_8039f630[0], delay, w3d_f32_8039f628[0]);
    if (s->hat)
        w3d_worm_play_named_801359ec(s, s->hat, p->fire, &s->hatAnimation, w3d_f32_8039f630[0], w3d_f32_8039f628[0], w3d_f32_8039f628[0]);
    if (s->held) {
        switch (weapon) {
        case 43: {
            D20dFireObject *service = w3d_context_804b1788->effects;
            if (service) ((D20dEffectPlay)service->vtable[24])(service, w3d_str_8039f5bc, &s->position);
            w3d_auto_8013f08c(s);
            w3d_s20_forward_global_800e5ca4(&s->position, w3d_str_8039f5c8, 0, w3d_f32_8039f628[0]);
            break;
        }
        case 0:
            w3d_worm_play_named_801359ec(s, s->held, w3d_str_8039f5d8, &s->heldAnimation, w3d_f32_8039f630[0], w3d_f32_8039f628[0], w3d_f32_8039f628[0]);
            w3d_auto_8013f2a4(s, s->held);
            break;
        case 26: {
            w3d_worm_play_named_801359ec(s, s->held, w3d_str_8039f5e4, &s->heldAnimation, w3d_f32_8039f630[0], w3d_f32_8039f628[0], w3d_f32_8039f628[0]);
            D20dFireObject *service = w3d_context_804b1788->effects;
            if (service) ((D20dEffectPlay)service->vtable[24])(service, w3d_str_8039f5f0, &s->position);
            break;
        }
        case 50:
            w3d_worm_play_named_801359ec(s, s->held, w3d_str_8039f4f4, &s->heldAnimation, w3d_f32_8039f630[0], w3d_f32_8039f628[0], w3d_f32_8039f628[0]);
            break;
        case 10:
            w3d_worm_play_named_801359ec(s, s->held, w3d_str_8039f5fc, &s->heldAnimation, w3d_f32_8039f630[0], w3d_f32_8039f628[0], w3d_f32_8039f628[0]);
            break;
        case 12:
            w3d_worm_play_named_801359ec(s, s->held, w3d_str_8039f604, &s->heldAnimation, w3d_f32_8039f630[0], w3d_f32_8039f628[0], w3d_f32_8039f628[0]);
            k4a_weapon_attach_trail_8013f5c4(s, s->held);
            break;
        case 17: {
            D20dFireObject *service = w3d_context_804b1788->effects;
            if (service) ((D20dEffectPlay)service->vtable[24])(service, w3d_str_8039f60c, &s->position);
            break;
        }
        case 53: {
            D20dFireObject *service = w3d_context_804b1788->effects;
            if (service) ((D20dEffectPlay)service->vtable[24])(service, w3d_str_8039f618, &s->position);
            break;
        }
        }
    }
}
