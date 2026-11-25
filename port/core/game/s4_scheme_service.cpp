#include "w3d_ptr.h"
#line 1 "s4_scheme_service.cpp"
/* Observed scheme service construction and retained-member cleanup. */
extern "C" {
struct ServiceObject { Ptr32<Ptr32<void (Ptr32<ServiceObject>)>> vtable; };
struct ServiceString { Ptr32<char> text; };
struct SchemeService { Ptr32<void> vtable; char unknown04[24]; Ptr32<ServiceObject> members[23]; ServiceString name; Ptr32<ServiceObject> last; };
extern const unsigned char w3d_vtable_8041c270[];
extern Ptr32<SchemeService> w3d_global_804abc0c;
int w3d_ctor_801628b0(Ptr32<SchemeService>);
void w3d_service_destroy_801628ec(Ptr32<SchemeService>, int);
Ptr32<void> w3d_string_default(Ptr32<ServiceString>);
void w3d_string_assign(Ptr32<ServiceString>, Ptr32<const char>);
void w3d_string_base_finish(Ptr32<ServiceString>);
void w3d_string_release(Ptr32<ServiceString>);
Ptr32<SchemeService> w3d_s4_scheme_service_construct(Ptr32<SchemeService> self)
{
    register Ptr32<ServiceString> name = &self->name;
    w3d_ctor_801628b0(self);
    self->members[0] = 0;
    self->members[1] = 0;
    self->members[2] = 0;
    self->members[3] = 0;
    self->members[4] = 0;
    self->members[5] = 0;
    self->members[6] = 0;
    self->members[7] = 0;
    self->members[8] = 0;
    self->members[9] = 0;
    self->members[10] = 0;
    self->members[11] = 0;
    self->members[12] = 0;
    self->members[13] = 0;
    self->members[14] = 0;
    self->members[15] = 0;
    self->members[16] = 0;
    self->members[17] = 0;
    self->members[18] = 0;
    self->members[19] = 0;
    self->members[20] = 0;
    self->members[21] = 0;
    self->members[22] = 0;
    self->vtable = (Ptr32<void>)w3d_vtable_8041c270;
    w3d_string_default(name);
    self->last = 0;
    w3d_global_804abc0c = self;
    w3d_string_assign(name, 0);
    return self;
}
void w3d_s4_scheme_service_destroy(Ptr32<SchemeService> self, int flags)
{
    self->vtable = (Ptr32<void>)w3d_vtable_8041c270;
    if (self->last) self->last->vtable[4](self->last);
    w3d_string_base_finish(&self->name);
    w3d_string_release(&self->name);
    if (self->members[22]) self->members[22]->vtable[4](self->members[22]);
    if (self->members[21]) self->members[21]->vtable[4](self->members[21]);
    if (self->members[20]) self->members[20]->vtable[4](self->members[20]);
    if (self->members[19]) self->members[19]->vtable[4](self->members[19]);
    if (self->members[18]) self->members[18]->vtable[4](self->members[18]);
    if (self->members[17]) self->members[17]->vtable[4](self->members[17]);
    if (self->members[16]) self->members[16]->vtable[4](self->members[16]);
    if (self->members[15]) self->members[15]->vtable[4](self->members[15]);
    if (self->members[14]) self->members[14]->vtable[4](self->members[14]);
    if (self->members[13]) self->members[13]->vtable[4](self->members[13]);
    if (self->members[12]) self->members[12]->vtable[4](self->members[12]);
    if (self->members[11]) self->members[11]->vtable[4](self->members[11]);
    if (self->members[10]) self->members[10]->vtable[4](self->members[10]);
    if (self->members[9]) self->members[9]->vtable[4](self->members[9]);
    if (self->members[8]) self->members[8]->vtable[4](self->members[8]);
    if (self->members[7]) self->members[7]->vtable[4](self->members[7]);
    if (self->members[6]) self->members[6]->vtable[4](self->members[6]);
    if (self->members[5]) self->members[5]->vtable[4](self->members[5]);
    if (self->members[4]) self->members[4]->vtable[4](self->members[4]);
    if (self->members[3]) self->members[3]->vtable[4](self->members[3]);
    if (self->members[2]) self->members[2]->vtable[4](self->members[2]);
    if (self->members[1]) self->members[1]->vtable[4](self->members[1]);
    if (self->members[0]) self->members[0]->vtable[4](self->members[0]);
    w3d_service_destroy_801628ec(self, flags);
}
}


