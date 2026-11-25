// Órdenes del juego a un gusano: guarda la orden y hace lo que cada tipo pide en el mismo momento.
#include "native_common.h"

namespace {
struct Vector3 { float x, y, z; };
struct CameraState { char bytes[184]; };
struct WormCommand {
    char pad[8];
    int type;                 // +8
    w3d_u32 value;            // +0xc
    Vector3 target;           // +0x10
    char pad2[0x28 - 0x1c];
    float amount;             // +0x28
    w3d_u32 team;             // +0x2c
    float team_value;         // +0x30
    CameraState camera;       // +0x34
};
struct Message { uint16_t id; uint16_t pad; w3d_u32 table; };
struct Worm {
    char pad[0x130];
    w3d_u32 active;           // +0x130
    int command;              // +0x134
    Vector3 target;           // +0x138
    char pad2[0x144 - 0x144];
    w3d_u32 team;             // +0x144
    float team_value;         // +0x148
    w3d_u32 started, updated; // +0x14c
    Vector3 start;            // +0x154
    char pad3[0x160 - 0x160];
    CameraState camera;       // +0x160
    char pad4[0x230 - 0x218];
    Vector3 position;         // +0x230
    char pad5[0x248 - 0x23c];
    w3d_u32 inventory;        // +0x248
};
struct ItemKey { w3d_u32 first, second; };
struct InventoryItem { char pad[0x74]; float amount; char pad2[0x84 - 0x78]; w3d_u32 count; };
struct EngineContext { char pad[0x34]; w3d_u32 time; };
enum { kCommandEnd, kCommandSetCount, kCommandNop2, kCommandSetAmount, kCommandCheckArrived, kCommandNop5, kCommandMirror, kCommandTeam, kCommandCamera = 12, kCommandHoldHere = 15, kCommandHoldCamera, kCommandCancel };
}
extern "C" {
extern Ptr32<void> A804b1754;   // Fondo de mensajes.
extern w3d_u32 A8040db38;
extern char A804afc40, A804afbc8, A804ac9d4, A804afc90, A804afbf0;
extern w3d_u32 A804aaef8, A804aaefc;
extern Vector3 A80448c90;
extern const float A803a0e08;
w3d_u32 A801613f0(void *pool, w3d_u32 bytes);
uint16_t A8015f5a0(void *name, w3d_u32 create);
w3d_u32 A8016239c(void *message);
w3d_u32 A80165254();
w3d_u32 A800fc710(void *inventory, ItemKey *key);
void A80007bf4();
w3d_u32 A80015564(w3d_u32 team);
void A80178474(ItemKey *key, w3d_u32 how);

static void post(char *name) {
    Message *message = at<Message>(A801613f0(A804b1754.get(), 8));
    message->id = A8015f5a0(name, 1);
    message->table = h2g(&A8040db38);
    A8016239c(message);
}
static void hold_position(const Vector3 &where) {
    A804aaefc = 0;
    A80448c90 = where;
    A804aaef8 = 1;
}
static void copy_camera(Worm *self, const CameraState &camera) {
    // La palabra de +0x24 del estado no viene de la orden.
    w3d_u32 *kept = (w3d_u32 *)(self->camera.bytes + 0x24);
    const w3d_u32 value = *kept;
    self->camera = camera;
    *kept = value;
}
// 0x801431fc
w3d_u32 A801431fc(Ptr32<Worm> self, Ptr32<WormCommand> command) {
    post(&A804afc40);
    self->active = 1;
    self->command = command->type;
    self->started = at<EngineContext>(A80165254())->time;
    self->updated = at<EngineContext>(A80165254())->time;
    self->start = self->position;
    self->target = command->target;
    ItemKey key = {0, 0xe3a8};
    switch (command->type) {
    case kCommandSetCount:
        at<InventoryItem>(A800fc710(arg(self->inventory), &key))->count = command->value;
        post(&A804afbc8);
        self->active = 0;
        break;
    case kCommandEnd:
        self->active = 0;
        break;
    case kCommandSetAmount:
        at<InventoryItem>(A800fc710(arg(self->inventory), &key))->amount = command->amount;
        self->active = 0;
        break;
    case kCommandCheckArrived: {
        const float dy = (float)(self->target.y - self->position.y);
        const float dx = (float)(self->target.x - self->position.x);
        const float dz = (float)(self->target.z - self->position.z);
        const float squared = fused_madd(dz, dz, fused_madd(dx, dx, (float)(dy * dy)));
        if (squared < A803a0e08) {
            post(&A804ac9d4);
            A80007bf4();
        } else {
            post(&A804afc90);
        }
        break;
    }
    case kCommandMirror:
        self->target = {(float)((float)(self->position.x + self->position.x) - command->target.x),
                        (float)((float)(self->position.y + self->position.y) - command->target.y),
                        (float)((float)(self->position.z + self->position.z) - command->target.z)};
        self->command = kCommandNop5;
        break;
    case kCommandTeam:
        self->team = command->team;
        self->team_value = command->team_value;
        A80015564(command->team);
        break;
    case kCommandCamera:
        copy_camera(self, command->camera);
        break;
    case kCommandHoldHere:
        hold_position(self->target);
        break;
    case kCommandHoldCamera:
        hold_position(self->target);
        copy_camera(self, command->camera);
        break;
    case kCommandCancel:
        self->active = 0;
        post(&A804afbf0);
        break;
    }
    A80178474(&key, 2);
    return 0;
}
}
