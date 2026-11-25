typedef struct S20Object { void **vtable; } S20Object;
typedef struct S20Services { char pad0[100]; S20Object *service100; } S20Services;
extern S20Services *lbl_804b1788;
typedef void (*S20Call5)(S20Object *, int *, int, int, int);

void w3d_s20_service_call_with_value_800fd62c(int *value, int a, int b, int c) {
    int copy;
    S20Object *object = lbl_804b1788->service100;
    copy = *value;
    ((S20Call5)object->vtable[32])(object, &copy, a, b, c);
}
