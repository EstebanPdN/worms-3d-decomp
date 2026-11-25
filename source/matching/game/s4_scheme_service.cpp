/* Observed scheme service construction and retained-member cleanup. */
extern "C" {
struct ServiceObject { void (**vtable)(ServiceObject *); };
struct ServiceString { char *text; };
struct SchemeService { void *vtable; char unknown04[24]; ServiceObject *members[23]; ServiceString name; ServiceObject *last; };
extern const unsigned char w3d_vtable_8041c270[];
extern SchemeService *w3d_global_804abc0c;
int w3d_ctor_801628b0(SchemeService *);
void w3d_service_destroy_801628ec(SchemeService *, int);
void * w3d_string_default(ServiceString *);
void w3d_string_assign(ServiceString *, const char *);
void w3d_string_base_finish(ServiceString *);
void w3d_string_release(ServiceString *);
SchemeService *w3d_s4_scheme_service_construct(SchemeService *self)
{
    register ServiceString *name = &self->name;
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
    self->vtable = (void *)w3d_vtable_8041c270;
    w3d_string_default(name);
    self->last = 0;
    w3d_global_804abc0c = self;
    w3d_string_assign(name, 0);
    return self;
}
void w3d_s4_scheme_service_destroy(SchemeService *self, int flags)
{
    self->vtable = (void *)w3d_vtable_8041c270;
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
