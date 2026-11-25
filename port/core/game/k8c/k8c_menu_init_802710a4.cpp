#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8c_menu_init_802710a4.c"
struct K8cMenu {
    char pad00[28];
    Ptr32<void> next_menu;
    int endpoint;
    int zero36;
    int one40;
    char pad44[36];
    int zero80;
    int zero84;
    char pad88[12];
    float scale;
};
struct K8cKeyHolder { Ptr32<void> value; unsigned reserved04; Ptr32<const char> key; };
extern const char w3d_str_803cc450[];
extern const char w3d_str_803cc460[];
extern float w3d_f32_803cc46c[];
extern int fn_802cc4f0(Ptr32<const char> name);
extern int fn_800fc1b0(Ptr32<Ptr32<const char>> key, Ptr32<Ptr32<void>> out);
void w3d_k8c_menu_init_802710a4(Ptr32<struct K8cMenu> self)
{
    Ptr32<const char> key;
    int endpoint = fn_802cc4f0(w3d_str_803cc450);
    self->scale = w3d_f32_803cc46c[0];
    self->one40 = 1;
    self->zero36 = 0;
    self->zero80 = 0;
    self->zero84 = 0;
    self->endpoint = endpoint;
    key = w3d_str_803cc460;
    fn_800fc1b0(&key, &self->next_menu);
}

}
