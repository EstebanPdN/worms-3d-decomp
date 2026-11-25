/* Message slot pool and movie player logic entities (0x800c4e78..0x800c6b50).
 *
 * Names are inferred from behavior; no original symbols survive.
 * Slot pool (type 0x80360a80, 28 bytes): keeps 128 slot pointers in a global
 * table (0x804a85d8), a vector of slot ids (0x8043e438) and a vector of busy
 * ids (0x8043e448); the live instance is recorded in small data (0x804aadfc).
 * Slot items return their storage to the heap at 0x804af100 when freed.
 * Movie player (type 0x80360ab0, 72 bytes): held objects at +0x1c..+0x38,
 * engine string at +0x3c, player object at +0x40, playing flag at +0x44.
 */
#include "g_types2.h"

extern "C" {

typedef struct W3dGIntVector {
    int *begin;
    int *end;
    unsigned char unknown_08[4];
    int *capacity;
} W3dGIntVector;

/* Engine string in an 8-byte local slot (second word not touched here). */
typedef struct W3dGStringLocal {
    W3dGString string;
    unsigned char unknown_04[4];
} W3dGStringLocal;

typedef struct W3dGHeap {
    unsigned char unknown_00[4];
} W3dGHeap;

typedef struct W3dGPoolItem W3dGPoolItem;

typedef struct W3dGPlayer W3dGPlayer;
typedef struct W3dGPlayerVtbl {
    void *unknown_00[2];
    void (*destroy)(W3dGPlayer *player, int flags);
    void *unknown_0c;
    void (*release)(W3dGPlayer *player);
    void *unknown_14;
    void (*stop)(W3dGPlayer *player);
    void *unknown_1c[2];
    void (*update)(W3dGPlayer *player);
    int (*status)(W3dGPlayer *player);
} W3dGPlayerVtbl;
struct W3dGPlayer {
    W3dGPlayerVtbl *vtbl;
};

typedef struct W3dGDisplay W3dGDisplay;
typedef struct W3dGDisplayVtbl {
    void *unknown_00[16];
    void (*present)(W3dGDisplay *display, int flags);
} W3dGDisplayVtbl;
typedef struct W3dGDisplayFlags {
    unsigned int unknown_0 : 1;
    unsigned int flag_1 : 1;
    unsigned int unknown_2 : 1;
    unsigned int flag_3 : 1;
    unsigned int flag_4 : 1;
    unsigned int unknown_5 : 27;
} W3dGDisplayFlags;
struct W3dGDisplay {
    W3dGDisplayVtbl *vtbl;
    unsigned char unknown_04[0x4c - 0x04];
    W3dGDisplayFlags flags;
};

typedef struct W3dLogic_80360a80 {
    void *vtable;
    unsigned short references;
    unsigned char unknown_06[0x1c - 0x06];
} W3dLogic_80360a80;

typedef struct W3dLogic_80360ab0 {
    void *vtable;
    unsigned short references;
    unsigned char unknown_06[0x1c - 0x06];
    W3dGIface *held_1c;
    W3dGIface *held_20;
    W3dGIface *held_24;
    W3dGIface *held_28;
    W3dGIface *held_2c;
    W3dGIface *held_30;
    W3dGIface *held_34;
    W3dGIface *held_38;
    W3dGString name;
    W3dGPlayer *player;
    int playing;
} W3dLogic_80360ab0;

extern W3dLogicType w3d_logic_type_80360a80;
extern W3dLogicType w3d_logic_type_80360ab0;
extern unsigned char w3d_vtable_8040fa28[];
extern unsigned char w3d_vtable_8040fa68[];
extern W3dGIntVector w3d_pool_ids_8043e438;
extern W3dGIntVector w3d_pool_busy_8043e448;
extern W3dGPoolItem *w3d_pool_slots_804a85d8[];
extern W3dLogic_80360a80 *w3d_pool_instance_804aadfc;
extern W3dGHeap w3d_heap_804af100;
extern W3dGCachedMessage w3d_message_804ae7e4;
extern W3dGDisplay *w3d_game_804b1788;
extern W3dLogic_80360ab0 *w3d_movie_instance_804aae0c;
extern const char w3d_str_803877f4[];
extern const char w3d_str_80387410[];

void w3d_int_vector_insert_80344380(W3dGIntVector *vector, int *position, unsigned int count, const int *value);
void w3d_int_vector_reserve_803445d8(W3dGIntVector *vector, unsigned int count);
void w3d_pool_free_800c58a8(unsigned int index);
void *w3d_pool_item_storage_800f7528(W3dGPoolItem *item);
void w3d_pool_item_destroy_800f74d0(W3dGPoolItem *item, int flags);
void w3d_heap_release(W3dGHeap *heap, void *block);
W3dGString *w3d_string_default(W3dGString *string);
void w3d_string_base_finish(W3dGString *string);
void w3d_string_release(W3dGString *string);
W3dGString *w3d_string_assign(W3dGString *string, const char *text);
void w3d_movie_stop_800c6920(W3dLogic_80360ab0 *movie);
int w3d_movie_lookup_800c6100(W3dLogic_80360ab0 *movie, const char *name);
int w3d_movie_start_800c6698(W3dLogic_80360ab0 *movie, const char *file);
void w3d_lookup_text_800fc2b0(const char **name, const char **value);
void w3d_lookup_text_800fc550(const char **name, const char *fallback);
void w3d_display_set_mode_80304b84(int mode);

}

/* std::vector<int>::resize(count, value) for the id vectors. */
static inline void w3d_int_vector_resize(W3dGIntVector *vector, unsigned int count, const int &value)
{
    unsigned int size = vector->end - vector->begin;
    if (count < size)
        vector->end = vector->begin + count;
    else
        w3d_int_vector_insert_80344380(vector, vector->end, count - size, &value);
}

/* std::vector<int>::operator[]. */
static inline int &w3d_int_at(W3dGIntVector *vector, unsigned int index)
{
    return *(vector->begin + index);
}

/* Local engine string object (8-byte slot). */
struct W3dGTextLocal {
    W3dGString string;
    unsigned char unknown_04[4];
    W3dGTextLocal() { w3d_string_default(&string); }
    ~W3dGTextLocal()
    {
        w3d_string_base_finish(&string);
        w3d_string_release(&string);
    }
    W3dGTextLocal &operator=(const char *text)
    {
        w3d_string_assign(&string, text);
        return *this;
    }
};

/* Reads a text setting by name. */
static inline const char *w3d_setting_text(const char *key)
{
    const char *value;
    w3d_lookup_text_800fc2b0(&key, &value);
    return value;
}

/* Writes a text setting by name. */
static inline void w3d_setting_set_text(const char *key, const char *text)
{
    w3d_lookup_text_800fc550(&key, text);
}

/* Engine string member destructor. */
static inline void w3d_gstring_destroy(W3dGString *string)
{
    w3d_string_base_finish(string);
    w3d_string_release(string);
}

extern "C" {

W3dLogicType *w3d_logic_type_get_800c4e78(void)
{
    return &w3d_logic_type_80360a80;
}

void w3d_logic_unlink_800c4e84(W3dLogic_80360a80 *object)
{
    w3d_owner_list_remove(&w3d_logic_type_80360a80, &object->references);
    w3d_logic_type_80360a80.count--;
}

W3dLogic_80360a80 *w3d_logic_construct_800c4f9c(W3dLogic_80360a80 *object);
W3dLogic_80360a80 *w3d_logic_create_800c4ec8(void)
{
    W3dLogic_80360a80 *object = w3d_logic_construct_800c4f9c((W3dLogic_80360a80 *)w3d_heap_allocate_entry_a(28));
    w3d_state_register(&w3d_logic_type_80360a80, object ? &object->references : 0);
    w3d_logic_type_80360a80.count++;
    return object;
}

void w3d_logic_unlink_800c4e84(W3dLogic_80360a80 *object);
void w3d_logic_destroy_800c5064(W3dLogic_80360a80 *object, int flags);
unsigned short w3d_logic_release_800c4f28(W3dLogic_80360a80 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_logic_unlink_800c4e84(object);
        if (object)
            w3d_logic_destroy_800c5064(object, 3);
    }
    return remaining;
}

unsigned short w3d_logic_retain_800c4f84(W3dLogic_80360a80 *object)
{
    return object->references++;
}

W3dLogic_80360a80 *w3d_logic_construct_800c4f9c(W3dLogic_80360a80 *object)
{
    unsigned int index;
    w3d_logic_base_init_801628b0(object);
    object->vtable = w3d_vtable_8040fa28;
    w3d_int_vector_resize(&w3d_pool_ids_8043e438, 128, 0);
    w3d_int_vector_reserve_803445d8(&w3d_pool_busy_8043e448, 128);
    for (index = 0; index < 128; index++) {
        w3d_int_at(&w3d_pool_ids_8043e438, index) = index;
        w3d_pool_slots_804a85d8[index] = 0;
    }
    w3d_pool_instance_804aadfc = object;
    return object;
}

void w3d_logic_destroy_800c5064(W3dLogic_80360a80 *object, int flags)
{
    unsigned int index;
    object->vtable = w3d_vtable_8040fa28;
    for (index = 0; index < 128; index++) {
        if (w3d_pool_slots_804a85d8[index])
            w3d_pool_free_800c58a8(index);
    }
    w3d_pool_ids_8043e438.end = w3d_pool_ids_8043e438.begin;
    w3d_pool_busy_8043e448.end = w3d_pool_busy_8043e448.begin;
    w3d_pool_instance_804aadfc = 0;
    w3d_logic_base_destroy_801628ec(object, flags);
}

void w3d_logic_hook_800c539c(W3dLogic_80360a80 *object);
int w3d_logic_handle_800c5100(W3dLogic_80360a80 *object, W3dGMessage *message)
{
    if (message->id == 64) {
        if (w3d_logic_base_handle_8016293c(object, message) >= 0) {
            w3d_logic_hook_800c539c(object);
            return 0;
        }
        return 0x80004005;
    }
    return w3d_logic_base_handle_8016293c(object, message);
}

void w3d_logic_hook_800c539c(W3dLogic_80360a80 *object)
{
}

void w3d_pool_free_800c58a8(unsigned int index)
{
    W3dGPoolItem *item = w3d_pool_slots_804a85d8[index];
    w3d_heap_release(&w3d_heap_804af100, w3d_pool_item_storage_800f7528(item));
    if (item)
        w3d_pool_item_destroy_800f74d0(item, 3);
    w3d_pool_slots_804a85d8[index] = 0;
}

W3dLogicType *w3d_logic_type_get_800c5fdc(void)
{
    return &w3d_logic_type_80360ab0;
}

void w3d_logic_unlink_800c5fe8(W3dLogic_80360ab0 *object)
{
    w3d_owner_list_remove(&w3d_logic_type_80360ab0, &object->references);
    w3d_logic_type_80360ab0.count--;
}

W3dLogic_80360ab0 *w3d_logic_construct_800c62dc(W3dLogic_80360ab0 *object);
W3dLogic_80360ab0 *w3d_logic_create_800c602c(void)
{
    W3dLogic_80360ab0 *object = w3d_logic_construct_800c62dc((W3dLogic_80360ab0 *)w3d_heap_allocate_entry_a(72));
    w3d_state_register(&w3d_logic_type_80360ab0, object ? &object->references : 0);
    w3d_logic_type_80360ab0.count++;
    return object;
}

void w3d_logic_unlink_800c5fe8(W3dLogic_80360ab0 *object);
void w3d_logic_destroy_800c6344(W3dLogic_80360ab0 *object, int flags);
unsigned short w3d_logic_release_800c608c(W3dLogic_80360ab0 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_logic_unlink_800c5fe8(object);
        if (object)
            w3d_logic_destroy_800c6344(object, 3);
    }
    return remaining;
}

unsigned short w3d_logic_retain_800c60e8(W3dLogic_80360ab0 *object)
{
    return object->references++;
}

W3dLogic_80360ab0 *w3d_logic_construct_800c62dc(W3dLogic_80360ab0 *object)
{
    w3d_logic_base_init_801628b0(object);
    object->vtable = w3d_vtable_8040fa68;
    object->held_1c = 0;
    object->held_20 = 0;
    object->held_24 = 0;
    object->held_28 = 0;
    object->held_2c = 0;
    object->held_30 = 0;
    object->held_34 = 0;
    object->held_38 = 0;
    w3d_string_default(&object->name);
    return object;
}

void w3d_logic_destroy_800c6344(W3dLogic_80360ab0 *object, int flags)
{
    object->vtable = w3d_vtable_8040fa68;
    w3d_gstring_destroy(&object->name);
    if (object->held_38)
        object->held_38->vtbl->release(object->held_38);
    if (object->held_34)
        object->held_34->vtbl->release(object->held_34);
    if (object->held_30)
        object->held_30->vtbl->release(object->held_30);
    if (object->held_2c)
        object->held_2c->vtbl->release(object->held_2c);
    if (object->held_28)
        object->held_28->vtbl->release(object->held_28);
    if (object->held_24)
        object->held_24->vtbl->release(object->held_24);
    if (object->held_20)
        object->held_20->vtbl->release(object->held_20);
    if (object->held_1c)
        object->held_1c->vtbl->release(object->held_1c);
    w3d_logic_base_destroy_801628ec(object, flags);
}

void w3d_movie_detach_800c6640(W3dLogic_80360ab0 *movie)
{
    w3d_movie_stop_800c6920(movie);
}

void w3d_movie_play_named_800c6660(W3dLogic_80360ab0 *movie, const char *name)
{
    w3d_movie_start_800c6698(movie, (const char *)w3d_movie_lookup_800c6100(movie, name));
}

#if 0 /* 0x800c67f0: argument set-up order and one rematerialised string address differ; 5 attempts. */
void w3d_movie_play_award_800c67f0(W3dLogic_80360ab0 *movie)
{
    W3dGTextLocal file;
    file = w3d_setting_text(w3d_str_803877f4);
    w3d_setting_set_text(w3d_str_803877f4, w3d_str_80387410);
    w3d_movie_play_named_800c6660(movie, file.string.data);
}
#endif

int w3d_movie_update_800c6878(W3dLogic_80360ab0 *movie)
{
    if (movie->playing) {
        movie->player->vtbl->update(movie->player);
        if ((unsigned int)(movie->player->vtbl->status(movie->player) - 3) > 1) {
            w3d_movie_stop_800c6920(movie);
            w3d_post_plain_message(&w3d_message_804ae7e4);
        }
    }
    return 0;
}

void w3d_movie_stop_800c6920(W3dLogic_80360ab0 *movie)
{
    if (movie->player && movie->playing) {
        unsigned int pass;
        movie->player->vtbl->stop(movie->player);
        movie->player->vtbl->release(movie->player);
        w3d_post_plain_message(&w3d_message_804ae7e4);
        w3d_game_804b1788->flags.flag_3 = 0;
        w3d_display_set_mode_80304b84(1);
        for (pass = 0; pass < 2; pass++)
            w3d_game_804b1788->vtbl->present(w3d_game_804b1788, 0);
        w3d_display_set_mode_80304b84(0);
        w3d_game_804b1788->flags.flag_3 = 1;
        w3d_game_804b1788->flags.flag_4 = 0;
        w3d_game_804b1788->flags.flag_1 = 0;
    }
    movie->playing = 0;
}

void w3d_movie_shutdown_800c6b50(W3dLogic_80360ab0 *movie)
{
    w3d_movie_stop_800c6920(movie);
    if (movie->player)
        movie->player->vtbl->destroy(movie->player, 3);
    movie->player = 0;
    w3d_movie_instance_804aae0c = 0;
}

}
