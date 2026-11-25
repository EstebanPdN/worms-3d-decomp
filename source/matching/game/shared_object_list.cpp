/* Reference-counted objects kept in one global intrusive list (0x802c6924..).
 *
 * Names are inferred from behavior; no original symbols survive. Callees
 * outside this unit stay external and are bound to their original addresses
 * by the reference linker. Field offsets are observed, not guessed:
 *   +0x04 u16 reference count (also the list link of the second base)
 *   +0x2c state word, +0x50 cached mode
 * The global list record at 0x80368c08 keeps a u16 element count at +0x22.
 */
extern "C" {

typedef struct W3dSharedList {
    unsigned char unknown_00[0x22];
    unsigned short count;
} W3dSharedList;

typedef struct W3dSharedObject {
    unsigned char unknown_00[4];
    unsigned short references;
    unsigned char unknown_06[0x2c - 0x06];
    int state;
    unsigned char unknown_30[0x50 - 0x30];
    int mode;
} W3dSharedObject;

extern W3dSharedList w3d_shared_list;
void *w3d_operator_new_801fe1d8(unsigned int size);
W3dSharedObject *w3d_shared_object_construct_802c6b10(void *storage);
void w3d_shared_object_destroy_802c6c74(W3dSharedObject *object, int flags);
void w3d_shared_object_apply_mode_802c663c(W3dSharedObject *object);
void w3d_list_insert_8020fd04(W3dSharedList *list, void *link);
void w3d_list_remove_8020fd2c(W3dSharedList *list, void *link);

void w3d_shared_object_set_mode(W3dSharedObject *object, int mode)
{
    if (mode != object->mode) {
        object->mode = mode;
        w3d_shared_object_apply_mode_802c663c(object);
    }
}

void w3d_shared_object_mark_state5(W3dSharedObject *object)
{
    object->state = 5;
}

W3dSharedList *w3d_shared_list_get(void)
{
    return &w3d_shared_list;
}

void w3d_shared_list_unlink(W3dSharedObject *object)
{
    w3d_list_remove_8020fd2c(&w3d_shared_list, &object->references);
    w3d_shared_list.count--;
}

W3dSharedObject *w3d_shared_object_create(void)
{
    W3dSharedObject *object = w3d_shared_object_construct_802c6b10(w3d_operator_new_801fe1d8(0x84));
    w3d_list_insert_8020fd04(&w3d_shared_list, object ? &object->references : 0);
    w3d_shared_list.count++;
    return object;
}

unsigned short w3d_shared_object_release(W3dSharedObject *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_shared_list_unlink(object);
        if (object)
            w3d_shared_object_destroy_802c6c74(object, 3);
    }
    return remaining;
}

unsigned short w3d_shared_object_retain(W3dSharedObject *object)
{
    return object->references++;
}

}
