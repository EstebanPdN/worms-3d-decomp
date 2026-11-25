/* HUD backing coordinates and dimensions, from observed field accesses. */
extern "C" {
struct HudBacking { char unknown00[28]; void *text; void *backing; };
struct Pair { float x,y; void set(float a,float b) {x=a;y=b;} };
struct Vector { float x,y,z; void set(float a,float b,float c) { x=a; y=b; z=c; } };
void *w3d_empty_80343580(void *);
void *w3d_empty_8034380c(void *);
float w3d_fn_8018c8bc(void *);
float w3d_getf_8018ca14(void *);
Pair *w3d_fn_8018963c(void *);
Vector *w3d_fn_80189518(void *);
extern const float w3d_f32_8039af64[],w3d_f32_8039af68[],w3d_f32_8039af6c[],w3d_f32_8039af70[],w3d_f32_8039af74[],w3d_f32_8039af78[],w3d_f32_8039af7c[];
void w3d_hud_backing_refresh_8011bc28(HudBacking *self) {
    struct { float unused[10]; } scratch;
    void *text=w3d_empty_80343580(self->text);
    float width=w3d_fn_8018c8bc(text); width=width+width;
    float height=w3d_getf_8018ca14(text);
    void *backing=w3d_empty_8034380c(self->backing);
    height=height*w3d_f32_8039af64[0];
    float edge=height*w3d_f32_8039af68[0];
    Pair *p=w3d_fn_8018963c(backing);
    p->y=height;
    float border=edge*w3d_f32_8039af6c[0];
    p->x=border;
    p=w3d_fn_8018963c(backing);
    float scale=w3d_f32_8039af70[0];
    p[1].y=height;
    width=width*scale;
    p[1].x=width*scale;
    w3d_fn_8018963c(backing)[2].set(border,height);
    Vector *v=w3d_fn_80189518(backing);
    float zero=w3d_f32_8039af78[0];
    v[0].set((edge*w3d_f32_8039af74[0]-width)*scale,zero,zero);
    w3d_fn_80189518(backing)[1].set(zero,zero,zero);
    w3d_fn_80189518(backing)[2].set((edge*w3d_f32_8039af7c[0]+width)*scale,zero,zero);
}
}
