#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "h1_800cc6d0.c"
/* Ninja camera object helpers and two reference-counted registry types
 * (session 47b5d14a, hand-matched). Bodies follow the registry shapes in
 * generated/gen_80100744.cpp. Offsets come from the original instructions;
 * the meaning of each field is inferred. */

typedef struct W3dRegistryList_800cc6d0 {
    unsigned char unknown_00[0x20];
    unsigned short count; unsigned short w3d_flags_high;           /* +34 */
} W3dRegistryList_800cc6d0;

typedef struct W3dRegistryObject_800cc6d0 {
    unsigned char unknown_00[4];
    unsigned short references;      /* +4 */
} W3dRegistryObject_800cc6d0;

typedef struct W3dNinjaCamera_800cc6d0 {
    unsigned char unknown_00[72];
    Ptr32<void> descriptor;               /* +72 */
} W3dNinjaCamera_800cc6d0;

extern char w3d_string_ninja_80387d74[];
extern char w3d_string_ninja_camera_80387d7c[];
extern unsigned char w3d_global_8040fb90[];
extern W3dRegistryList_800cc6d0 w3d_registry_list_80360b70;
extern W3dRegistryList_800cc6d0 w3d_registry_list_80360ba0;
extern unsigned char w3d_global_80360b70[];
extern unsigned char w3d_global_80360ba0[];

Ptr32<void> fn_800d2dec(Ptr32<void> self, int a1, Ptr32<const char> name, int a2);
void w3d_auto_800d31d8(Ptr32<void> self, Ptr32<const char> name);
void fn_800d308c(Ptr32<void> self, Ptr32<void>);
void fn_800d5028(Ptr32<void> self);
void w3d_payload_pending_clear_800ccd54(Ptr32<void> self);
void w3d_owner_list_remove(Ptr32<W3dRegistryList_800cc6d0> list, Ptr32<void> link);
void w3d_payload_state_destroy_800cc908(Ptr32<W3dRegistryObject_800cc6d0> object, int flags);
void s8_destroy_800cdd68(Ptr32<W3dRegistryObject_800cc6d0> object, int flags);

Ptr32<W3dNinjaCamera_800cc6d0> w3d_h1_ninja_camera_construct_800cc6d0(Ptr32<W3dNinjaCamera_800cc6d0> self, int a1, int a2)
{
    fn_800d2dec(self, a1, w3d_string_ninja_80387d74, a2);
    self->descriptor = w3d_global_8040fb90;
    w3d_auto_800d31d8(self, w3d_string_ninja_camera_80387d7c);
    return self;
}

void w3d_h1_ninja_camera_destroy_800cc728(Ptr32<void> self, Ptr32<void> arg_r4)
{
    fn_800d308c(self, arg_r4);
    fn_800d5028(self);
}

void w3d_h1_forward_800cc75c(Ptr32<void> self)
{
    fn_800d5028(self);
}

Ptr32<unsigned char> w3d_address_800cc77c(void)
{
    return w3d_global_80360b70;
}

void w3d_registry_unlink_800cc788(Ptr32<W3dRegistryObject_800cc6d0> object)
{
    w3d_owner_list_remove(&w3d_registry_list_80360b70, &object->references);
    w3d_registry_list_80360b70.count--;
}

unsigned short w3d_registry_release_800cc82c(Ptr32<W3dRegistryObject_800cc6d0> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_registry_unlink_800cc788(object);
        if (object)
            w3d_payload_state_destroy_800cc908(object, 3);
    }
    return remaining;
}

unsigned short w3d_registry_retain_800cc888(Ptr32<W3dRegistryObject_800cc6d0> object)
{
    return object->references++;
}

int w3d_constant_800ccaf0(void)
{
    return -1;
}

void w3d_h1_forward_800ccbf4(Ptr32<void> self)
{
    w3d_payload_pending_clear_800ccd54(self);
}


Ptr32<unsigned char> w3d_address_800cdaa8(void)
{
    return w3d_global_80360ba0;
}

void w3d_registry_unlink_800cdab4(Ptr32<W3dRegistryObject_800cc6d0> object)
{
    w3d_owner_list_remove(&w3d_registry_list_80360ba0, &object->references);
    w3d_registry_list_80360ba0.count--;
}

unsigned short w3d_registry_release_800cdb58(Ptr32<W3dRegistryObject_800cc6d0> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_registry_unlink_800cdab4(object);
        if (object)
            s8_destroy_800cdd68(object, 3);
    }
    return remaining;
}

unsigned short w3d_registry_retain_800cdbb4(Ptr32<W3dRegistryObject_800cc6d0> object)
{
    return object->references++;
}

}
