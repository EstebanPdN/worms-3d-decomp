/* Randomised sound volume (0x801e1308), split from c_sound_volume because its
 * int-to-float conversion constant must own its own .rodata placement.
 *
 * Names are inferred from behavior; no original symbols survive. The original
 * frame keeps 16 bytes of locals that no surviving instruction uses; an unused
 * 3-float vector local reproduces that reservation.
 */
extern "C" {

typedef struct W3dVec3 {
    float x, y, z;
} W3dVec3;

typedef struct W3dSoundEmitter W3dSoundEmitter;

extern const float w3d_f32_803b04e8[];
extern const float w3d_f32_803b04ec[];
extern const float w3d_f32_803b04f0[];

int w3d_rand_802ee7dc(void);

float w3d_sound_emitter_vary_volume_801e1308(W3dSoundEmitter *emitter, float base, float spread)
{
    W3dVec3 unused;
    float range = base * spread;
    float low = base - range;
    float value = low + (float)w3d_rand_802ee7dc() * w3d_f32_803b04e8[0] * range * 2.0f;

    if (value > w3d_f32_803b04ec[0])
        value = w3d_f32_803b04ec[0];
    else if (value < w3d_f32_803b04f0[0])
        value = w3d_f32_803b04f0[0];
    return value;
}

}
