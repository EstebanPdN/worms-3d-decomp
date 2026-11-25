struct K9cVec { float x; float y; float z; };
struct K9cVec4 { float x; float y; float z; float w; float v; float u; };
extern float lbl_8039d228[];
extern "C" void *k9c_empty_80341584(void *);
extern "C" void k9c_refresh_801797b4(void);
extern "C" int k9c_apply_800eac84(void *, void *);
extern "C" int k9c_update_800eb6e4(void *);
extern "C" int k9c_post_800ed090(void *);
extern "C" int k9c_sound_800edca0(void *);
extern "C" void w3d_k9c_reset_state_8012a618(char *self) {
    K9cVec4 local;
    k9c_empty_80341584(*(void **)(self + 192));
    k9c_refresh_801797b4();
    *(int *)(self + 308) = 1;
    *(K9cVec *)(self + 312) = *(K9cVec *)(self + 48);
    float f = lbl_8039d228[0];
    *(float *)(self + 316) = f;
    k9c_apply_800eac84(self, self + 36);
    k9c_update_800eb6e4(self);
    local.x = f;
    K9cVec4 *p = &local;
    p->z = f;
    p->y = f;
    k9c_post_800ed090(self);
    k9c_sound_800edca0(self);
}
