/* Hand-matched control flow and inferred field types. */
#define S9_FIELD(p,T,o) (*(T)((char *)(p)+(o)))
int fn_801359EC(void *, void **, int, void *, float, float, float); /* extern */
int fn_80138DAC(void *, int);               /* extern */
int fn_80139234(void *, void **, int);      /* extern */
int fn_8013D440(void *, void **, int);               /* extern */
void *fn_80165254();                                /* extern */
int fn_801817E0(void **, int);              /* extern */
extern float lbl_8039F910[];
extern float lbl_8039F914[];
extern float lbl_8039F918[];
extern int lbl_804AB100;
extern int lbl_804AB328;

void s9_update_actor_transition_8013c9ac(void *self) {
    void **model;
    void **model_again;
    void **effect;

    S9_FIELD(self, int *, 0x2B8) = (int) (S9_FIELD(fn_80165254(), int *, 0x34) + 0x2328);
    if ((int) S9_FIELD(self, int *, 0x2B4) == 0) {
        goto block_9;
    }
    if ((int) S9_FIELD(self, int *, 0x288) == 0) {
        goto block_9;
    }
    fn_801817E0(S9_FIELD(self, void ***, 0x1C), -1);
    fn_801359EC(self, S9_FIELD(self, void ***, 0x1C), lbl_804AB100, self + 0x1EC, (*lbl_8039F910), (*lbl_8039F914), (*lbl_8039F918));
    if ((int) S9_FIELD(self, int *, 0x1F0) != 0xA) {
        goto block_6;
    }
    if ((int) S9_FIELD(self, int *, 0x2AC) != 0) {
        goto block_5;
    }
    fn_80138DAC(self, 1);
    goto block_6;
block_5:
    S9_FIELD(self, float *, 0x244) = (float) (*lbl_8039F918);
    fn_8013D440(self, S9_FIELD(self, void ***, 0x1C),S9_FIELD(self,int *,0x2AC));
    fn_80139234(self, S9_FIELD(self, void ***, 0x1C), 0);
block_6:
    if ((int) S9_FIELD(self, int *, 0x2AC) != 1) {
        goto block_9;
    }
    if ((int) S9_FIELD(self, int *, 0xA4) == 0) {
        goto block_9;
    }
    model = S9_FIELD(self, void ***, 0x1C);
    S9_FIELD(*model, int (**)(void **,int), 0x60)(model,S9_FIELD(self,int *,0xA4));
    model_again = S9_FIELD(self, void ***, 0x1C);
    S9_FIELD(*model_again, int (**)(void **, int, int), 0x5C)(model_again, S9_FIELD(self, int *, 0xA4), lbl_804AB328);
block_9:
    effect = S9_FIELD(self, void ***, 0x214);
    if (effect == 0) {
        goto block_11;
    }
    S9_FIELD(*effect, int (**)(void **), 0x18)(effect);
block_11:
    S9_FIELD(self, int *, 0x2B0) = 0;
    S9_FIELD(self, int *, 0x2B4) = 0;
    return;
}
