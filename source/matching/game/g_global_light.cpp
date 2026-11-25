/* Global light logic object and its per-light entry table (0x800c000c..0x800c136c).
 *
 * Names are inferred from behavior; no original symbols survive. The active
 * global light is kept in small data (0x804aada8). Light entries are 60-byte
 * records in a vector whose begin pointer lives at 0x8043c384:
 *   +0x00 vec3 position, +0x0c held light object, +0x10 held attachment,
 *   +0x1c u8 enabled, +0x20 float, +0x24..+0x2c colour scale, +0x30 vec3.
 * The global light object holds two looked-up resources at +0x1c and +0x20.
 */
#include "g_types.h"

extern "C" {

typedef struct W3dLightEntry {
    W3dGVec3 position;
    W3dGIface *light;
    W3dGIface *attachment;
    unsigned char unknown_14[0x1c - 0x14];
    unsigned char enabled;
    unsigned char unknown_1d[3];
    float scale;
    float colour[3];
    W3dGVec3 base_colour;
} W3dLightEntry;

typedef struct W3dLightEntryVector {
    W3dLightEntry *begin;
    W3dLightEntry *end;
    unsigned char unknown_08[8];
} W3dLightEntryVector;

typedef struct W3dGlobalLight {
    void *vtable;
    unsigned char unknown_04[0x1c - 0x04];
    W3dGIface *ambient;
    W3dGIface *diffuse;
} W3dGlobalLight;

extern unsigned char w3d_vtable_8040f8a8[];
extern W3dGlobalLight *w3d_global_light_804aada8;
extern W3dLightEntryVector w3d_light_entries_8043c384;
extern const char w3d_str_80382f60[];
extern const char w3d_str_80382f74[];

}

/* Vector element access through an unsigned index, as std::vector::operator[]. */
static inline W3dLightEntry &w3d_light_entry(unsigned int index)
{
    return *(w3d_light_entries_8043c384.begin + index);
}

extern "C" {

void w3d_logic_base_destroy_801628ec(void *object, int flags);
int w3d_logic_base_handle_8016293c(void *object, W3dGMessage *message);
void w3d_global_light_refresh_800c06a0(W3dGlobalLight *light);
void w3d_global_light_detach_800c04a4(W3dGlobalLight *light);
int w3d_light_attach_80182410(W3dGIface *attachment, W3dGIface *light);

void w3d_global_light_destroy_800c000c(W3dGlobalLight *light, int flags)
{
    light->vtable = w3d_vtable_8040f8a8;
    w3d_global_light_804aada8 = 0;
    if (light->diffuse)
        light->diffuse->vtbl->release(light->diffuse);
    if (light->ambient)
        light->ambient->vtbl->release(light->ambient);
    w3d_logic_base_destroy_801628ec(light, flags);
}

void w3d_global_light_attach_800c0440(W3dGlobalLight *light);

int w3d_global_light_handle_800c0090(W3dGlobalLight *light, W3dGMessage *message)
{
    switch (message->id) {
    case 64:
        if (w3d_logic_base_handle_8016293c(light, message) >= 0) {
            w3d_global_light_attach_800c0440(light);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_global_light_detach_800c04a4(light);
        break;
    }
    return w3d_logic_base_handle_8016293c(light, message);
}

void w3d_global_light_attach_800c0440(W3dGlobalLight *light)
{
    const char *ambient_name;
    const char *diffuse_name;
    ambient_name = w3d_str_80382f60;
    w3d_constructor_lookup_name(&ambient_name, &light->ambient);
    diffuse_name = w3d_str_80382f74;
    w3d_constructor_lookup_name(&diffuse_name, &light->diffuse);
    w3d_global_light_refresh_800c06a0(light);
    w3d_global_light_804aada8 = light;
}

void w3d_light_set_position_800c125c(int index, W3dGVec3 *position)
{
    if (w3d_global_light_804aada8)
        w3d_light_entry(index).position = *position;
}

void w3d_light_set_attachment_800c1294(int index, W3dGIface **attachment)
{
    if (w3d_global_light_804aada8) {
        W3dLightEntry *entry = &w3d_light_entry(index);
        if (*attachment)
            (*attachment)->vtbl->retain(*attachment);
        if (entry->attachment)
            entry->attachment->vtbl->release(entry->attachment);
        entry->attachment = *attachment;
        w3d_light_attach_80182410(*attachment, w3d_light_entry(index).light);
    }
    if (*attachment)
        (*attachment)->vtbl->release(*attachment);
}

void w3d_light_set_scale_800c1348(int index, float scale)
{
    if (w3d_global_light_804aada8)
        w3d_light_entry(index).scale = scale;
}

#if 0 /* 0x800c06a0: the negated sun vector is stored to two stack temporaries in the original; not reproduced. */
void w3d_global_light_refresh_800c06a0(W3dGlobalLight *light)
{
    const char *name = w3d_str_80382f94;
    w3d_lookup_vector_800fc2f0(&name, &w3d_sun_vector_8043c3b8);
    w3d_light_direction_8043c3ac = -w3d_sun_vector_8043c3b8;
    w3d_ambient_8043c3d0 = *w3d_colour_80178ec4(w3d_empty_80342fa4(light->ambient));
    w3d_diffuse_8043c3c4 = *w3d_colour_80178ec4(w3d_empty_80342fa4(light->diffuse));
}
#endif

#if 0 /* 0x800c136c: only the ambient product copy differs (an extra address register for the stack temporary). */
void w3d_light_set_colour_800c136c(int index, float r, float g, float b)
{
    if (w3d_global_light_804aada8) {
        W3dLightEntry &e = w3d_light_entry(index);
        e.colour.x = r;
        e.colour.y = g;
        e.colour.z = b;
        W3dGVec3 c = e.base_colour;
        c.x *= e.colour.x;
        c.y *= e.colour.y;
        c.z *= e.colour.z;
        W3dGVec3 a;
        a.x = w3d_ambient_8043c3d0.x * e.colour.x;
        a.y = w3d_ambient_8043c3d0.y * e.colour.y;
        a.z = w3d_ambient_8043c3d0.z * e.colour.z;
        e.light->colour = c;
        e.light->ambient = a;
    }
}
#endif

}
