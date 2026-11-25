/* Per-light vector arithmetic and shared sun colour state. */
struct S5Vec { float x,y,z; };
extern "C" {
struct S5LightObject { unsigned char reserved[120]; S5Vec colour,ambient; unsigned char reserved90[12]; S5Vec direction; };
struct S5LightEntry { S5Vec position; S5LightObject *light; void *attachment; float field14; unsigned char field18[8]; float scale; S5Vec colour,base; };
struct S5LightSource { unsigned char reserved[28]; void *ambient,*diffuse; };
extern S5LightSource *w3d_light_source_804aada8;
extern S5Vec w3d_sun_vector_8043c3b8[],w3d_light_direction_8043c3ac[],w3d_diffuse_8043c3c4[],w3d_ambient_8043c3d0[];
extern unsigned w3d_light_hit_804b1764;
extern const float w3d_f32_80382f4c[],w3d_f32_80382f58[],w3d_f32_80382f5c[];
void w3d_light_source_refresh_800c06a0(S5LightSource *);
void w3d_light_trace_800b0824(S5Vec *,S5Vec *,S5Vec *,int,int);
/* 0x800c021c: vector-return temporaries and register allocation differ after two attempts. */
#if 0
void w3d_light_refresh_800c021c(S5LightEntry *entry)
{
    S5Vec start,hit;
    w3d_light_source_refresh_800c06a0(w3d_light_source_804aada8);
    hit.x=hit.z=hit.y=*w3d_f32_80382f4c;
    start = entry->position + *w3d_sun_vector_8043c3b8 * entry->scale;
    w3d_light_trace_800b0824(&start,w3d_sun_vector_8043c3b8,&hit,1000,1);
    float factor = w3d_light_hit_804b1764 < 1000 ? (float)w3d_light_hit_804b1764 / *w3d_f32_80382f58 : *w3d_f32_80382f5c;
    entry->base = *w3d_diffuse_8043c3c4 * (factor*entry->field14);
    S5Vec colour;
    colour.x=entry->base.x*entry->colour.x;
    colour.y=entry->base.y*entry->colour.y;
    colour.z=entry->base.z*entry->colour.z;
    S5Vec ambient;
    ambient.x=w3d_ambient_8043c3d0->x*entry->colour.x;
    ambient.y=w3d_ambient_8043c3d0->y*entry->colour.y;
    ambient.z=w3d_ambient_8043c3d0->z*entry->colour.z;
    entry->light->colour=colour;
    entry->light->ambient=ambient;
    entry->light->direction=*w3d_light_direction_8043c3ac;
}
#endif

extern const char w3d_str_80382f94[];
void w3d_lookup_vector_800fc2f0(const char **,S5Vec *);
void *w3d_empty_80342fa4(void *);
S5Vec *w3d_auto_80178ec4(void *);
/* 0x800c06a0: seven scheduling differences remain after seven attempts. */
#if 0
void w3d_light_source_refresh_800c06a0(S5LightSource *source)
{
    S5Vec vector,duplicate;
    const char *name=w3d_str_80382f94;
    w3d_lookup_vector_800fc2f0(&name,w3d_sun_vector_8043c3b8);
    float x=-w3d_sun_vector_8043c3b8->x;
    float y=-w3d_sun_vector_8043c3b8->y;
    float z=-w3d_sun_vector_8043c3b8->z;
    vector.x=x; vector.y=y; vector.z=z;
    duplicate.x=x; duplicate.y=y; duplicate.z=z;
    *w3d_light_direction_8043c3ac=vector;
    vector=*w3d_auto_80178ec4(w3d_empty_80342fa4(source->ambient));
    w3d_ambient_8043c3d0->x=vector.x;
    w3d_ambient_8043c3d0->y=vector.y;
    w3d_ambient_8043c3d0->z=vector.z;
    vector=*w3d_auto_80178ec4(w3d_empty_80342fa4(source->diffuse));
    w3d_diffuse_8043c3c4->x=vector.x;
    w3d_diffuse_8043c3c4->y=vector.y;
    w3d_diffuse_8043c3c4->z=vector.z;
}
#endif
}
