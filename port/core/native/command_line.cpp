// Opciones de la línea de órdenes del juego: mapa inicial, ajustes y modo sin sonido.
#include "native_game.h"

namespace {
struct App {
    char pad[0x94];
    GameString start_map;   // +0x94
    char pad2[0xbc - 0x98];
    w3d_u32 flags;          // +0xbc
};
const w3d_u32 kFlagCheat = 0x100;
const w3d_u32 kFailed = 0x80004005u;
const int kKindMap = 9;
inline GameString copy_of(const GameString &other) {
    GameString copy;
    copy.text = other.text;
    copy.header()->references++;
    return copy;
}
}
extern "C" {
extern const char A8039c704[], A8039c77c[], A8039c7ac[], A8039c7d0[], A8039c7e0[], A8039c820[], A8039c834[];
w3d_u32 A8015c3ec();
w3d_u32 A8015b424(void *args);
w3d_u32 A8015b410(void *args, w3d_u32 index);
void A8020c2e8(GameString *string);
int A802ef234(const char *, const char *);
void A80341588(GameString *string);
w3d_u32 A800fc69c(void *cursor, void *item, ...);
int A800fd504(void *name, w3d_u32 kind, w3d_u32 how);
void A800fc43c(void *key, w3d_u32 value);
void A800fc550(void *key, void *text);

// 0x80128bec
w3d_u32 A80128bec(Ptr32<App> self) {
    void *args = g2h(A8015c3ec());
    const w3d_u32 count = A8015b424(args);
    for (w3d_u32 i = 0; i < count; i++) {
        GameString option = copy_of(*at<GameString>(A8015b410(args, i)));
        A8020c2e8(&option);
        const char *text = option.text;
        if (!A802ef234(text, A8039c704)) {
            if (i == count - 1) { A80341588(&option); return kFailed; }
            self->start_map.assign(*at<GameString>(A8015b410(args, ++i)));
            Ptr32<void> cursor{(void *)nullptr}, item{(void *)nullptr};
            while (((w3d_u32 (*)(void *, void *))A800fc69c)(&cursor, &item)) {
                if (call_virtual<int>(item.get(), 0x24) == kKindMap) call_virtual<void>(item.get(), 0x30, (void *)5);
            }
            if (A800fd504(self->start_map.text.get(), kKindMap, 2) < 0) A800fd504(self->start_map.text.get(), kKindMap, 1);
            release_if_set(item.get());
        } else if (!A802ef234(text, A8039c77c)) {
            // Reservada: en el original solo borra un indicador que nadie pone.
        } else if (!A802ef234(text, A8039c7ac)) {
            Ptr32<const char> key(A8039c7d0);
            A800fc43c(&key, 0);
        } else if (!A802ef234(text, A8039c7e0)) {
            if (i == count - 1) { A80341588(&option); return kFailed; }
            GameString value = copy_of(*at<GameString>(A8015b410(args, ++i)));
            Ptr32<const char> key(A8039c820);
            A800fc550(&key, value.text.get());
            A80341588(&value);
        } else if (!A802ef234(text, A8039c834)) {
            self->flags |= kFlagCheat;
        }
        A80341588(&option);
    }
    return 0;
}
}
