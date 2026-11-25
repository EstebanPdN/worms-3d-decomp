#include "w3d_ptr.h"
#line 1 "d26c_chute_message_800dac50.cpp"
// d26c: 0x800dac50. Message handler of a parachute-like entity: start on id 64, stop on id 66, react to nine cached ids
// and hand the rest to the base handler. Names are inferred.
struct Message { unsigned short id; };
struct Chute { char u0[72]; int active; int t76; char u80[68]; int s148; int s152; char u156[8]; int owner_id; };
extern "C" int base_8015fb34(Ptr32<Chute>, Ptr32<Message>);
extern "C" void fields_800dae1c(Ptr32<Chute>);
extern "C" void stop_800dafa4(Ptr32<Chute>);
extern "C" void start_800db014(Ptr32<Chute>);
extern "C" void off_800daffc(Ptr32<Chute>);
extern "C" void finish_8015fd1c(Ptr32<Chute>);
extern "C" int value_800a830c(Ptr32<Message>);
extern "C" int id_equals_8015f65c(unsigned, Ptr32<int>);
extern int id_804aec04, id_804aec0c, id_804aebf4, id_804aebe4, id_804aebec, id_804aebc4, id_804aebcc, id_804aebd4, id_804aebdc;
extern "C" int d26c_chute_message_800dac50(Ptr32<Chute> self, Ptr32<Message> m) {
    unsigned short id = m->id;
    switch (id) {
    case 64:
        if (base_8015fb34(self, m) >= 0) { fields_800dae1c(self); goto done; }
        return 0x80004005;
    case 66:
        stop_800dafa4(self);
        return base_8015fb34(self, m);
    }
    if (id_equals_8015f65c(id, &id_804aec04)) { start_800db014(self); goto done; }
    if (id_equals_8015f65c(id, &id_804aec0c)) { off_800daffc(self); goto done; }
    if (id_equals_8015f65c(id, &id_804aebf4)) {
        int a = self->active;
        if (a == 0) { start_800db014(self); self->t76 = a; }
        goto done;
    }
    if (id_equals_8015f65c(id, &id_804aebe4)) {
    finish:
        finish_8015fd1c(self);
        goto done;
    }
    if (id_equals_8015f65c(id, &id_804aebec)) {
        if (value_800a830c(m) != self->owner_id) goto done;
        goto finish;
    }
    if (id_equals_8015f65c(id, &id_804aebc4)) { self->s148 = 1; return 0; }
    if (id_equals_8015f65c(id, &id_804aebcc)) { self->s148 = 0; goto done; }
    if (id_equals_8015f65c(id, &id_804aebd4)) { self->s152 = 1; goto done; }
    if (id_equals_8015f65c(id, &id_804aebdc)) goto clear;
    return base_8015fb34(self, m);
clear:
    self->s152 = 0;
done:
    return 0;
}


