/* Forwarding helper that calls two virtual methods of objects held by a global. */
typedef struct S20Object { void **vtable; } S20Object;
typedef struct S20Services { char pad0[100]; S20Object *service100; char pad1[4]; S20Object *service108; } S20Services;
extern S20Services *lbl_804b1788;
typedef void (*S20Call0)(S20Object *);

void w3d_s20_notify_if_flagged_800e8ee0(char *self, char *flag, S20Object **target) {
    S20Object **copy;
    copy = target;
    if (*flag != 0) {
        S20Object *second;
        S20Object *first = lbl_804b1788->service108;
        do {
            ((S20Call0)first->vtable[23])(first);
        } while (0);
        second = *copy;
        ((S20Call0)second->vtable[5])(second);
    }
}
