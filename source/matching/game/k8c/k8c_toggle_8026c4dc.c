struct K8cHolder { char pad00[4]; };
struct K8cOwner { char pad00[0x90]; const char *name; };
struct K8cWidget {
    char pad00[0x28];
    struct K8cOwner *owner;
    char pad2c[0x16c];
    void *target;
    int state;
};
extern void *fn_80342a78(void *p);
extern int fn_80178d28(void *p, int *value);
extern void fn_802b1258(const char *name);
void w3d_k8c_widget_set_state_8026c4dc(struct K8cWidget *self, int state)
{
    int flag;
    void *target;
    if (state != self->state) {
        self->state = state;
        target = fn_80342a78(self->target);
        flag = state == 0;
        fn_80178d28(target, &flag);
        if (((unsigned short *)self->owner->name)[-2] != 0)
            fn_802b1258(self->owner->name);
    }
}
