#include "w3d_ptr.h"
#line 1 "d24g_target_messages_8004ddc8.cpp"
/* Worms 3D GameCube PAL 0x8004ddc8. Target message handler: start and stop messages with the base handler; one message clips the target; one searches and stores found and calls virtual slot +44 or +48; one ends through 0x8015fd1c; others go to the base handler. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Msg { unsigned short id; unsigned short Id() const { return id; } };
struct Self;
struct Vt { Ptr32<void> u[11]; Ptr32<int (Ptr32<Self>)> a; Ptr32<int (Ptr32<Self>)> b; };
struct Self { Ptr32<Vt> vtable; char u4[76]; int found; };
extern MessageCache c_804ad43c, c_804ad424, c_804ad444;
extern "C" int base_8015fb34(Ptr32<Self>, Ptr32<Msg>);
extern "C" void init_8004def0(Ptr32<Self>);
extern "C" void stop_8004e0d8(Ptr32<Self>);
extern "C" int id_equals_8015f65c(int, Ptr32<MessageCache>);
extern "C" void clips_8004e5ac(Ptr32<Self>);
extern "C" int search_8004e324(Ptr32<Self>);
extern "C" void end_8015fd1c(Ptr32<Self>);
extern "C" int w3d_d24g_target_messages_8004ddc8(Ptr32<Self> self, Ptr32<Msg> msg)
{
    unsigned short id = msg->Id();
    switch (msg->Id()) {
    case 64:
        if (base_8015fb34(self, msg) >= 0) {
            init_8004def0(self);
            break;
        }
        return 0x80004005;
    case 66:
        stop_8004e0d8(self);
        return base_8015fb34(self, msg);
    default:
        if (id_equals_8015f65c(id, &c_804ad43c)) {
            clips_8004e5ac(self);
        } else if (id_equals_8015f65c(id, &c_804ad424)) {
            int r = search_8004e324(self);
            if (r) {
                self->found = 1;
                self->vtable->a(self);
            } else {
                self->found = r;
                self->vtable->b(self);
            }
        } else if (!id_equals_8015f65c(id, &c_804ad444)) {
            return base_8015fb34(self, msg);
        } else {
            end_8015fd1c(self);
        }
    }
    return 0;
}


