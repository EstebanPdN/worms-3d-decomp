// desc: Appears to initialize an embedded component from the engine context, call two virtual setup slots on it and post a cached message.
struct S21ComponentMethods { void (*reserved[5])(void *, int); void (*enable)(void *, int); char pad[28]; void (*start)(void *, int); };
struct S21Clock { char pad[52]; int tick; };
struct S21Entity { char pad[28]; char component[180]; struct S21ComponentMethods *methods; char pad1[12]; char target[4]; };
extern struct S21Clock *fn_80165254(void);
extern void fn_802b0b84(void *, void *, int);
extern short fn_8015f5a0(void *, int);
extern int fn_80162024(void *, short *, void *);
struct S21Id { int word; };
extern struct S21Id lbl_804b0f44;
void w3d_s21_entity_start_802af894(struct S21Entity *self)
{
    short message;
    void *component = self->component;
    fn_802b0b84(component, self, fn_80165254()->tick);
    self->methods->enable(component, 1);
    self->methods->start(component, 1);
    message = fn_8015f5a0(&lbl_804b0f44, 1);
    fn_80162024(self, &message, self->target);
}
