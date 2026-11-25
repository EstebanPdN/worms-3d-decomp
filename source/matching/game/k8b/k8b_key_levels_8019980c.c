typedef struct K8bTarget { void (**vtable)(struct K8bTarget *, int, float); } K8bTarget;
struct K8bKey { char pad0[8]; float start; float end; unsigned short channel; char pad12[2]; unsigned short kind; char pad16[2]; };
struct K8bKeyVector { struct K8bKey *begin; struct K8bKey *end; };
struct K8bTrack { char pad0[20]; K8bTarget *target; float time; char pad28[4]; struct K8bKeyVector keys; };
extern float lbl_803a86e0[];
extern float lbl_803a86e4[];
static inline struct K8bKey *k8b_keys_end(struct K8bKeyVector *keys) { return keys->end; }

void w3d_k8b_key_levels_8019980c(struct K8bTrack *self)
{
    struct K8bKey *key;
    for (key = self->keys.begin; key != k8b_keys_end(&self->keys); key++) {
        float level = lbl_803a86e0[0];
        switch (key->kind) {
        case 3:
        case 4:
            level = lbl_803a86e4[0];
            break;
        case 1:
            level = (self->time - key->start) / (key->end - key->start);
            break;
        case 2:
            level = (key->end - self->time) / (key->end - key->start);
            break;
        }
        self->target->vtable[16](self->target, key->channel, level);
    }
}
