/* Observed worm graphic fields; names are inferred from local behavior. */
typedef struct S3WormGraphic {
    unsigned char pad00[0x1c];
    void *mesh;
    unsigned char pad20[0x70-0x20];
    int entity;
    unsigned char pad74[0x1d8-0x74];
    int animation;
    unsigned char pad1dc[0x240-0x1dc];
    void *effect;
    unsigned char pad244[0x2e0-0x244];
    int blink;
} S3WormGraphic;
typedef struct S3Entity {
    unsigned char pad00[0xd5];
    unsigned char player;
} S3Entity;
extern int w3d_auto_8013fecc(S3WormGraphic *, void *);
extern int w3d_get_800a830c(void *);
extern S3Entity *w3d_fn_800fc6dc(int);
extern int w3d_fn_80139158(S3WormGraphic *);
extern void *w3d_empty_80343584(void *);
extern int w3d_mesh_instance_is_playing(void *, int);
extern int fn_80162C20(void);
extern int w3d_fn_801359ec(S3WormGraphic *, void *, int, int *, float, float, float);
extern const float w3d_f32_8039fe40[];
extern const float w3d_f32_8039fe44[];
extern int w3d_global_804ab2f0;
extern int w3d_global_804ab394;
extern int w3d_global_804ab398;
extern int w3d_global_804ab39c;
extern const char w3d_str_8039fe48[];
extern void * w3d_fn_800fc1f0(const char **, int *);
extern void w3d_fn_800e5bb8(void *);

void w3d_worm_graphic_random_animation(S3WormGraphic *self, void *message)
{
    int player;
    void *mesh;
    if (!w3d_auto_8013fecc(self, message)) return;
    player = w3d_get_800a830c(message);
    if (player != w3d_fn_800fc6dc(self->entity)->player) return;
    if (w3d_fn_80139158(self)) return;
    mesh = w3d_empty_80343584(self->mesh);
    if (!w3d_mesh_instance_is_playing(mesh, self->animation)) return;
    switch ((unsigned int)fn_80162C20() & 3) {
    case 0: w3d_fn_801359ec(self, mesh, w3d_global_804ab2f0, &self->animation, w3d_f32_8039fe40[0], w3d_f32_8039fe44[0], w3d_f32_8039fe44[0]); break;
    case 1: w3d_fn_801359ec(self, mesh, w3d_global_804ab394, &self->animation, w3d_f32_8039fe40[0], w3d_f32_8039fe44[0], w3d_f32_8039fe44[0]); break;
    case 2: w3d_fn_801359ec(self, mesh, w3d_global_804ab398, &self->animation, w3d_f32_8039fe40[0], w3d_f32_8039fe44[0], w3d_f32_8039fe44[0]); break;
    default: w3d_fn_801359ec(self, mesh, w3d_global_804ab39c, &self->animation, w3d_f32_8039fe40[0], w3d_f32_8039fe44[0], w3d_f32_8039fe44[0]); break;
    }
}
void w3d_worm_graphic_set_blink(S3WormGraphic *self, void *message)
{
    const char *key;
    int value;
    int result;
    if (w3d_get_800a830c(message) == self->entity) {
        key = w3d_str_8039fe48;
        w3d_fn_800fc1f0(&key, &value);
        result = value;
        if (result) result = 1;
        self->blink = result;
    }
}
void w3d_worm_graphic_release_effect(S3WormGraphic *self)
{
    if (self->effect) {
        w3d_fn_800e5bb8(self->effect);
        self->effect = 0;
    }
}
