/* Forwarding helpers that call virtual methods of objects held by a global. */
typedef struct S20Object { void **vtable; } S20Object;
typedef struct S20Services { char pad0[100]; S20Object *service100; char pad1[4]; S20Object *service108; } S20Services;
extern S20Services *lbl_804b1788;
typedef void (*S20Call0)(S20Object *);
typedef void (*S20Call4)(S20Object *, int, int, int, int);
typedef void (*S20Call3)(S20Object *, int, int, unsigned char);

void w3d_s20_service_call_800fc668(void) {
    S20Object *object = lbl_804b1788->service100;
    ((S20Call0)object->vtable[28])(object);
}

void w3d_s20_service_call4_800fc110(int a, int b, int c, int d) {
    S20Object *object = lbl_804b1788->service100;
    ((S20Call4)object->vtable[13])(object, a, b, c, d);
}

void w3d_s20_service_call4_800fc160(int a, int b, int c, int d) {
    S20Object *object = lbl_804b1788->service100;
    ((S20Call4)object->vtable[14])(object, a, b, c, d);
}

void w3d_s20_service_call3_800fd440(int a, int b, int c) {
    S20Object *object = lbl_804b1788->service100;
    ((S20Call3)object->vtable[42])(object, a, b, c);
}
