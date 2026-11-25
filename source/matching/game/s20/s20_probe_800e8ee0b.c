/* near miss: 4 register words */
typedef struct S20Object { void **vtable; } S20Object;
typedef struct S20Services { char pad0[100]; S20Object *service100; char pad1[4]; S20Object *service108; } S20Services;
extern S20Services *lbl_804b1788;
typedef void (*S20Call0)(S20Object *);

void w3d_s20_notify_if_flagged_800e8ee0(char *self, char *flag, S20Object **target) {
    if (*flag != 0) {
        S20Object *first = lbl_804b1788->service108;
        S20Object *second = *target;
        ((S20Call0)first->vtable[23])(first);
        ((S20Call0)second->vtable[5])(second);
    }
}
