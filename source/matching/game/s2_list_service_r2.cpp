/* Selection-list service lifecycle and message routing. */
extern "C" {
struct S2ListObject { void **vtable; };
struct S2ListService { void *vtable; unsigned char pad04[44]; S2ListObject *lists[19]; };
extern const char w3d_str_8039a110[];
void w3d_list_fill_8010f7d0(S2ListService *);
extern const char w3d_str_8039a118[];
void w3d_list_fill_80110450(S2ListService *);
extern const char w3d_str_8039a124[];
void w3d_list_fill_80113f24(S2ListService *);
extern const char w3d_str_8039a138[];
void w3d_list_fill_80114594(S2ListService *);
extern const char w3d_str_8039a14c[];
void w3d_list_fill_80114a2c(S2ListService *);
extern const char w3d_str_8039a160[];
void w3d_list_fill_8011307c(S2ListService *);
extern const char w3d_str_8039a168[];
void w3d_list_fill_801100ac(S2ListService *);
extern const char w3d_str_8039a178[];
void w3d_list_fill_8010fd08(S2ListService *);
extern const char w3d_str_8039a188[];
void w3d_list_fill_8011711c(S2ListService *);
extern const char w3d_str_8039a190[];
void w3d_list_fill_80110c9c(S2ListService *);
extern const char w3d_str_8039a1a4[];
extern const char w3d_str_8039a1b4[];
void w3d_list_fill_80112cb0(S2ListService *);
extern const char w3d_str_8039a1c4[];
extern const char w3d_str_8039a1d4[];
extern const char w3d_str_8039a1e0[];
void w3d_list_fill_80115088(S2ListService *);
extern const char w3d_str_8039a1ec[];
void w3d_list_fill_8011577c(S2ListService *);
extern const char w3d_str_8039a1f8[];
void w3d_list_fill_8011626c(S2ListService *);
extern const char w3d_str_8039a208[];
void w3d_list_fill_80115cd0(S2ListService *);
extern const char w3d_str_8039a214[];
void w3d_list_fill_8011385c(S2ListService *);
extern const char w3d_str_8039a21c[];
void w3d_list_fill_80113c18(S2ListService *);
extern const char w3d_str_8039a22c[];
void w3d_list_fill_801167d4(S2ListService *);
extern const char w3d_str_8039a238[];
void w3d_list_fill_80111820(S2ListService *);
extern const char w3d_str_8039a244[];
void w3d_list_fill_801175c8(S2ListService *);
int strcmp(const char *, const char *);
int w3d_ctor_801628b0(S2ListService *);
void w3d_service_destroy_801628ec(S2ListService *, int);
int w3d_auto_8016293c(S2ListService *, unsigned short *);
void w3d_list_initialize_8010ee14(S2ListService *);
void w3d_empty_8010f7cc(S2ListService *);
int w3d_fn_8015f65c(unsigned short, void *);
const char *w3d_get_8010a8fc(unsigned short *);
void w3d_list_fill_80112514(S2ListService *, S2ListObject *, int);
extern unsigned char w3d_obj_804108a8[];
extern unsigned int w3d_obj_804af308;


int w3d_list_name_greater_8010e698(const char **left, const char **right)
{
    if (strcmp(*left, *right) > 0) return 1;
    return 0;
}


S2ListService *w3d_list_service_construct_8010e6d0(S2ListService *self)
{
    struct { unsigned int first, second; } scratch;
    w3d_ctor_801628b0(self);
    self->vtable = w3d_obj_804108a8;
    self->lists[0] = 0;
    self->lists[1] = 0;
    self->lists[2] = 0;
    self->lists[3] = 0;
    self->lists[4] = 0;
    self->lists[5] = 0;
    self->lists[6] = 0;
    self->lists[7] = 0;
    self->lists[8] = 0;
    self->lists[9] = 0;
    self->lists[10] = 0;
    self->lists[11] = 0;
    self->lists[12] = 0;
    self->lists[13] = 0;
    self->lists[14] = 0;
    self->lists[15] = 0;
    self->lists[16] = 0;
    self->lists[17] = 0;
    self->lists[18] = 0;
    return self;
}


void w3d_list_service_destroy_8010e75c(S2ListService *self, int flags)
{
    self->vtable = w3d_obj_804108a8;
    if (self->lists[18]) ((void (*)(S2ListObject *))self->lists[18]->vtable[4])(self->lists[18]);
    if (self->lists[17]) ((void (*)(S2ListObject *))self->lists[17]->vtable[4])(self->lists[17]);
    if (self->lists[16]) ((void (*)(S2ListObject *))self->lists[16]->vtable[4])(self->lists[16]);
    if (self->lists[15]) ((void (*)(S2ListObject *))self->lists[15]->vtable[4])(self->lists[15]);
    if (self->lists[14]) ((void (*)(S2ListObject *))self->lists[14]->vtable[4])(self->lists[14]);
    if (self->lists[13]) ((void (*)(S2ListObject *))self->lists[13]->vtable[4])(self->lists[13]);
    if (self->lists[12]) ((void (*)(S2ListObject *))self->lists[12]->vtable[4])(self->lists[12]);
    if (self->lists[11]) ((void (*)(S2ListObject *))self->lists[11]->vtable[4])(self->lists[11]);
    if (self->lists[10]) ((void (*)(S2ListObject *))self->lists[10]->vtable[4])(self->lists[10]);
    if (self->lists[9]) ((void (*)(S2ListObject *))self->lists[9]->vtable[4])(self->lists[9]);
    if (self->lists[8]) ((void (*)(S2ListObject *))self->lists[8]->vtable[4])(self->lists[8]);
    if (self->lists[7]) ((void (*)(S2ListObject *))self->lists[7]->vtable[4])(self->lists[7]);
    if (self->lists[6]) ((void (*)(S2ListObject *))self->lists[6]->vtable[4])(self->lists[6]);
    if (self->lists[5]) ((void (*)(S2ListObject *))self->lists[5]->vtable[4])(self->lists[5]);
    if (self->lists[4]) ((void (*)(S2ListObject *))self->lists[4]->vtable[4])(self->lists[4]);
    if (self->lists[3]) ((void (*)(S2ListObject *))self->lists[3]->vtable[4])(self->lists[3]);
    if (self->lists[2]) ((void (*)(S2ListObject *))self->lists[2]->vtable[4])(self->lists[2]);
    if (self->lists[1]) ((void (*)(S2ListObject *))self->lists[1]->vtable[4])(self->lists[1]);
    if (self->lists[0]) ((void (*)(S2ListObject *))self->lists[0]->vtable[4])(self->lists[0]);
    w3d_service_destroy_801628ec(self, flags);
}


int w3d_list_service_dispatch_8010e9b4(S2ListService *self, unsigned short *message)
{
    switch (*message) {
    case 64:
        if (w3d_auto_8016293c(self, message) >= 0) {
            w3d_list_initialize_8010ee14(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_empty_8010f7cc(self);
        break;
    default:
        if (w3d_fn_8015f65c(*message, &w3d_obj_804af308)) {
            if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a110))
                w3d_list_fill_8010f7d0(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a118))
                w3d_list_fill_80110450(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a124))
                w3d_list_fill_80113f24(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a138))
                w3d_list_fill_80114594(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a14c))
                w3d_list_fill_80114a2c(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a160))
                w3d_list_fill_8011307c(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a168))
                w3d_list_fill_801100ac(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a178))
                w3d_list_fill_8010fd08(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a188))
                w3d_list_fill_8011711c(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a190))
                w3d_list_fill_80110c9c(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a1a4))
                w3d_list_fill_80112514(self, self->lists[1], 3);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a1b4))
                w3d_list_fill_80112cb0(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a1c4))
                w3d_list_fill_80112514(self, self->lists[2], 4);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a1d4))
                w3d_list_fill_80112514(self, self->lists[8], 5);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a1e0))
                w3d_list_fill_80115088(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a1ec))
                w3d_list_fill_8011577c(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a1f8))
                w3d_list_fill_8011626c(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a208))
                w3d_list_fill_80115cd0(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a214))
                w3d_list_fill_8011385c(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a21c))
                w3d_list_fill_80113c18(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a22c))
                w3d_list_fill_801167d4(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a238))
                w3d_list_fill_80111820(self);
            else if (!strcmp(w3d_get_8010a8fc(message), w3d_str_8039a244))
                w3d_list_fill_801175c8(self);
            else w3d_get_8010a8fc(message);
        }
    }
    return w3d_auto_8016293c(self, message);
}

}
