// Abre un sonido en dos canales de disco, izquierdo y derecho, y lanza la primera lectura de cada uno.
#include "native_common.h"

namespace {
struct StreamFile { Ptr32<const char> path; w3d_u32 pad; w3d_u32 buffer; };
struct StreamSlot {
    uint8_t in_use;
    char pad[7];
    Ptr32<StreamSlot> right;   // +8
    Ptr32<StreamSlot> left;    // +0xc
    Ptr32<StreamFile> file;    // +0x10
    char pad2[4];
    char disc_file[0x60 - 0x18];  // +0x18
    w3d_u32 length;            // +0x60
};
}
extern "C" {
void A801e3eb8();
void A801e3e70();
int A801e3d44(Ptr32<StreamSlot> *slot);
w3d_u32 A801e4074(void *slot, w3d_u32 name, w3d_u32 volume, w3d_u32 pan);
int A802f51e4(const char *path, void *file);
void A802f5568(void *file, w3d_u32 length, w3d_u32 offset, void *buffer, void *done, w3d_u32 priority);
void A802fb7ac(const void *text, ...);
void A801e4a4c();
extern const char A803b0698[], A803b06c0[];

static void start_reading(StreamSlot *slot, w3d_u32 offset, const char *failure) {
    if (!A802f51e4(slot->file->path, slot->disc_file)) A802fb7ac(failure);
    A802f5568(slot->disc_file, slot->length, offset, arg(slot->file->buffer), (void *)A801e4a4c, 2);
}
// 0x801e41d0: devuelve el número del canal izquierdo, o -1 si no quedan dos libres.
int A801e41d0(w3d_u32, w3d_u32 left_name, w3d_u32 right_name, w3d_u32 volume) {
    Ptr32<StreamSlot> left, right;
    A801e3eb8();
    const int number = A801e3d44(&left);
    if (number == -1) { A801e3e70(); return -1; }
    if (A801e3d44(&right) == -1) {
        left->in_use = 0;
        A801e3e70();
        return -1;
    }
    left->right = right;
    right->left = left;
    const w3d_u32 left_offset = A801e4074(left.get(), left_name, volume, 0);
    const w3d_u32 right_offset = A801e4074(right.get(), right_name, volume, 0x7f);
    A801e3e70();
    start_reading(left, left_offset, A803b0698);
    start_reading(right, right_offset, A803b06c0);
    return number;
}
}
