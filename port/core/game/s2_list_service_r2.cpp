#include "w3d_ptr.h"
#line 1 "s2_list_service_r2.cpp"
/* Selection-list service lifecycle and message routing. */
extern "C" {
struct S2ListObject { Ptr32<Ptr32<void>> vtable; };
struct S2ListService { Ptr32<void> vtable; unsigned char pad04[44]; Ptr32<S2ListObject> lists[19]; };
extern const char w3d_str_8039a110[];
void w3d_list_fill_8010f7d0(Ptr32<S2ListService>);
extern const char w3d_str_8039a118[];
void w3d_list_fill_80110450(Ptr32<S2ListService>);
extern const char w3d_str_8039a124[];
void w3d_list_fill_80113f24(Ptr32<S2ListService>);
extern const char w3d_str_8039a138[];
void w3d_list_fill_80114594(Ptr32<S2ListService>);
extern const char w3d_str_8039a14c[];
void w3d_list_fill_80114a2c(Ptr32<S2ListService>);
extern const char w3d_str_8039a160[];
void w3d_list_fill_8011307c(Ptr32<S2ListService>);
extern const char w3d_str_8039a168[];
void w3d_list_fill_801100ac(Ptr32<S2ListService>);
extern const char w3d_str_8039a178[];
void w3d_list_fill_8010fd08(Ptr32<S2ListService>);
extern const char w3d_str_8039a188[];
void w3d_list_fill_8011711c(Ptr32<S2ListService>);
extern const char w3d_str_8039a190[];
void w3d_list_fill_80110c9c(Ptr32<S2ListService>);
extern const char w3d_str_8039a1a4[];
extern const char w3d_str_8039a1b4[];
void w3d_list_fill_80112cb0(Ptr32<S2ListService>);
extern const char w3d_str_8039a1c4[];
extern const char w3d_str_8039a1d4[];
extern const char w3d_str_8039a1e0[];
void w3d_list_fill_80115088(Ptr32<S2ListService>);
extern const char w3d_str_8039a1ec[];
void w3d_list_fill_8011577c(Ptr32<S2ListService>);
extern const char w3d_str_8039a1f8[];
void w3d_list_fill_8011626c(Ptr32<S2ListService>);
extern const char w3d_str_8039a208[];
void w3d_list_fill_80115cd0(Ptr32<S2ListService>);
extern const char w3d_str_8039a214[];
void w3d_list_fill_8011385c(Ptr32<S2ListService>);
extern const char w3d_str_8039a21c[];
void w3d_list_fill_80113c18(Ptr32<S2ListService>);
extern const char w3d_str_8039a22c[];
void w3d_list_fill_801167d4(Ptr32<S2ListService>);
extern const char w3d_str_8039a238[];
void w3d_list_fill_80111820(Ptr32<S2ListService>);
extern const char w3d_str_8039a244[];
void w3d_list_fill_801175c8(Ptr32<S2ListService>);
int strcmp(Ptr32<const char>, Ptr32<const char>);
int w3d_ctor_801628b0(Ptr32<S2ListService>);
void w3d_service_destroy_801628ec(Ptr32<S2ListService>, int);
int w3d_auto_8016293c(Ptr32<S2ListService>, Ptr32<unsigned short>);
void w3d_list_initialize_8010ee14(Ptr32<S2ListService>);
void w3d_empty_8010f7cc(Ptr32<S2ListService>);
int w3d_fn_8015f65c(unsigned short, Ptr32<void>);
Ptr32<const char> w3d_get_8010a8fc(Ptr32<unsigned short>);
void w3d_list_fill_80112514(Ptr32<S2ListService>, Ptr32<S2ListObject>, int);
extern unsigned char w3d_obj_804108a8[];
extern unsigned int w3d_obj_804af308;


int w3d_list_name_greater_8010e698(Ptr32<Ptr32<const char>> left, Ptr32<Ptr32<const char>> right)
{
    if (strcmp(*left, *right) > 0) return 1;
    return 0;
}


Ptr32<S2ListService> w3d_list_service_construct_8010e6d0(Ptr32<S2ListService> self)
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


void w3d_list_service_destroy_8010e75c(Ptr32<S2ListService> self, int flags)
{
    self->vtable = w3d_obj_804108a8;
    if (self->lists[18]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[18]->vtable[4])(self->lists[18]);
    if (self->lists[17]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[17]->vtable[4])(self->lists[17]);
    if (self->lists[16]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[16]->vtable[4])(self->lists[16]);
    if (self->lists[15]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[15]->vtable[4])(self->lists[15]);
    if (self->lists[14]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[14]->vtable[4])(self->lists[14]);
    if (self->lists[13]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[13]->vtable[4])(self->lists[13]);
    if (self->lists[12]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[12]->vtable[4])(self->lists[12]);
    if (self->lists[11]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[11]->vtable[4])(self->lists[11]);
    if (self->lists[10]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[10]->vtable[4])(self->lists[10]);
    if (self->lists[9]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[9]->vtable[4])(self->lists[9]);
    if (self->lists[8]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[8]->vtable[4])(self->lists[8]);
    if (self->lists[7]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[7]->vtable[4])(self->lists[7]);
    if (self->lists[6]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[6]->vtable[4])(self->lists[6]);
    if (self->lists[5]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[5]->vtable[4])(self->lists[5]);
    if (self->lists[4]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[4]->vtable[4])(self->lists[4]);
    if (self->lists[3]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[3]->vtable[4])(self->lists[3]);
    if (self->lists[2]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[2]->vtable[4])(self->lists[2]);
    if (self->lists[1]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[1]->vtable[4])(self->lists[1]);
    if (self->lists[0]) ((Ptr32<void (Ptr32<S2ListObject>)>)self->lists[0]->vtable[4])(self->lists[0]);
    w3d_service_destroy_801628ec(self, flags);
}


int w3d_list_service_dispatch_8010e9b4(Ptr32<S2ListService> self, Ptr32<unsigned short> message)
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


