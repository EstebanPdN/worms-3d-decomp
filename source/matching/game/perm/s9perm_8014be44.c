/* Control-flow scope reproduces the reference compiler's conditional argument move. */
typedef struct S9RouteState { char unknown[300]; int active; } S9RouteState;
extern void fn_8015aa04(void *, void *);
extern void fn_801f67e0(void *);
extern int lbl_804aa8c8;
void s9_permute_8014be44(const S9RouteState *self,int value)
{
    do {
        if(!self->active)goto global_setting;
        fn_801f67e0(value);
        return;
global_setting:
        fn_8015aa04(lbl_804aa8c8+328, (void *)value);
    } while(0);
}
