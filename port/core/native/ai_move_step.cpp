// Siguiente paso de la cola de movimientos de un gusano de la IA: un mensaje de movimiento por cada orden, con una pequeña máquina de estados por tipo.
#include "native_common.h"

namespace {
struct Vector3 { float x, y, z; };
enum { kPayloadBytes = 184, kKeepOffset = 0x24 };
struct AiMove {
    int kind;               // +0
    Vector3 position;       // +4
    char payload[kPayloadBytes];  // +0x10
};
struct MoveQueue {
    char pad[0x14];
    Ptr32<Ptr32<AiMove>> begin, end;  // +0x14
    char pad2[0x24 - 0x1c];
    w3d_u32 busy;           // +0x24
    w3d_u32 phase;          // +0x28
};
struct MotionMessage {
    char pad[8];
    w3d_u32 command;        // +8
    char pad2[4];
    Vector3 position;       // +0x10
    char pad3[0x34 - 0x1c];
    char payload[kPayloadBytes];  // +0x34
};
// Objeto de pila cuyo método 0x14 hace el trabajo: la tabla va tras los campos, al uso de GCC 2.95 con base no polimórfica.
struct WormAnimation {
    w3d_u32 unused, a, b, c;  // +0
    w3d_u32 table;            // +0x10
    w3d_u32 animation;        // +0x14
};
enum { kMoveWalk = 7, kMoveJump = 8, kMoveTurn = 9, kMoveFire = 10, kMoveAim = 11, kMoveWait = 12 };
enum { kAnimationAim = 0x30, kAnimationJump = 0x2a, kPauseTicks = 0xfa };
}
extern "C" {
extern w3d_u32 A804aa79c, A8040dd68;
extern Ptr32<void> A804b1754;
void A80004038(int kind);
void A8000415c(void *self, w3d_u32 ticks);
w3d_u32 A801613f0(void *arena, w3d_u32 bytes);
w3d_u32 A80131a84(w3d_u32 memory);
w3d_u32 A8016239c(void *message);
void A80021468(void *object, w3d_u32 how);

static void copy_payload(MotionMessage *message, const AiMove *move) {
    w3d_u32 kept;
    memcpy(&kept, message->payload + kKeepOffset, 4);
    memcpy(message->payload, move->payload, kPayloadBytes);
    memcpy(message->payload + kKeepOffset, &kept, 4);
}
static void play_animation(MoveQueue *self, MotionMessage *message, w3d_u32 animation) {
    WormAnimation object = {0, 0, 1, 1, h2g(&A8040dd68), animation};
    call_in_table<void>(&object, object.table, 0x14);
    A80021468(&object, 0);
    message->command = 0;
    A8000415c(self, kPauseTicks);
}
// 0x800039e4
w3d_u32 A800039e4(Ptr32<MoveQueue> self) {
    if (self->begin.v == self->end.v || self->busy) return 0;
    self->busy = 1;
    AiMove *move = (*self->begin).get();
    if (A804aa79c == 2) A80004038(move->kind);
    MotionMessage *message = at<MotionMessage>(A80131a84(A801613f0(A804b1754.get(), 0xec)));
    message->position = move->position;
    switch (move->kind) {
    case 0: case 1: case 2:
        message->command = 2;
        break;
    case 3: case 4: case 5: case 6:
        switch (self->phase) {
        case 0:
            message->command = move->kind == 4 ? 6 : 5;
            self->phase = 1;
            break;
        case 1:
            self->phase = 2;
            switch (move->kind) {
            case 3: message->command = 8; break;
            case 4: message->command = 9; break;
            case 5: message->command = 10; break;
            case 6: message->command = 10; self->phase = 0; break;
            }
            break;
        case 2: message->command = 11; self->phase = 3; break;
        case 3: message->command = 2; self->phase = 0; break;
        }
        break;
    case kMoveWalk:
        switch (self->phase) {
        case 0: play_animation(self.get(), message, kAnimationAim); break;
        case 4:
            copy_payload(message, (*self->begin).get());
            message->command = 12;
            self->phase = 5;
            break;
        case 5: message->command = 2; self->phase = 0; break;
        case 6: message->command = 5; self->phase = 4; break;
        }
        break;
    case kMoveJump:
        if (self->phase == 0) {
            play_animation(self.get(), message, kAnimationJump);
        } else if (self->phase == 6) {
            message->command = 5;
            self->phase = 0;
        }
        break;
    case kMoveTurn:
        message->command = 0xd;
        break;
    case kMoveAim:
        message->command = 0x10;
        copy_payload(message, (*self->begin).get());
        break;
    case kMoveWait:
        message->command = 0;
        if (self->phase == 0) A8000415c(self.get(), (w3d_u32)ppc_ftoi((*self->begin)->position.x));
        else if (self->phase == 6) self->phase = 0;
        break;
    }
    A8016239c(message);
    return 0;
}
}
