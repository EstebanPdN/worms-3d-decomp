#include "w3d_ptr.h"
#line 1 "cc44a_release_resource_801656d4_v0.cpp"
// Inferred views from the original offsets; these are not complete class layouts.
struct cc44a_Queue;
extern Ptr32<cc44a_Queue> cc44a_queue_804b1884;
// Wrapper 80166ff8 forwards to 8016703c, which queues a pointer and has no result definition.
extern "C" void cc44a_enqueue_80166ff8(Ptr32<cc44a_Queue>, Ptr32<void>);
struct cc44a_Owner;
// Concrete indirect targets and return types remain unknown. Results are discarded.
typedef Ptr32<void (Ptr32<cc44a_Owner>, unsigned int)> cc44a_ReleaseSlot;
struct cc44a_OwnerVtable {
    unsigned int unknown[6];
    cc44a_ReleaseSlot single;
    unsigned int unknown28;
    cc44a_ReleaseSlot pair;
    unsigned int unknown36;
    cc44a_ReleaseSlot group;
};
struct cc44a_Owner { Ptr32<cc44a_OwnerVtable> vtable; };
struct cc44a_Chunk { unsigned int unknown[3]; Ptr32<void> allocation; };
struct cc44a_Resource {
    Ptr32<void> vtable;
    unsigned short references;
    unsigned char unknown6[6];
    int kind;
    Ptr32<void> payload[4];
    unsigned int token;
    Ptr32<cc44a_Owner> owner;
};
extern "C" unsigned short cc44a_release_resource_801656d4(Ptr32<cc44a_Resource> self) {
    unsigned short count = --self->references;
    if (count == 0) {
        Ptr32<cc44a_Queue> queue = cc44a_queue_804b1884;
        switch (self->kind) {
        case 2: {
            Ptr32<Ptr32<void>> current = self->payload;
            Ptr32<Ptr32<void>> last = self->payload + 3;
            do {
                Ptr32<cc44a_Chunk> chunk = (Ptr32<cc44a_Chunk>)*current++;
                if (chunk) {
                    cc44a_enqueue_80166ff8(queue, chunk->allocation);
                    cc44a_enqueue_80166ff8(queue, chunk);
                }
            } while (current <= last);
            self->owner->vtable->group(self->owner, self->token);
            break;
        }
        case 1: {
            Ptr32<Ptr32<void>> pair = (Ptr32<Ptr32<void>>)self->payload[0];
            cc44a_enqueue_80166ff8(queue, pair[0]);
            cc44a_enqueue_80166ff8(queue, pair[1]);
            cc44a_enqueue_80166ff8(queue, pair);
            self->payload[0] = 0;
            self->owner->vtable->pair(self->owner, self->token);
            break;
        }
        case 0:
            cc44a_enqueue_80166ff8(queue, self->payload[0]);
            self->payload[0] = 0;
            self->owner->vtable->single(self->owner, self->token);
            break;
        }
    }
    return count;
}


