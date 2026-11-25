// GWMP8P rev0 0x80285b28. Starts a frontend value control: initialises the
// base at +28 with the display context, copies two record values, sets up
// its selection and layout, binds the record's named property (retained at
// +256, with a change callback), reads the property's value by kind (0 or
// 1), selects that value, and acquires two message holders. Offsets come
// from the original instructions; roles are inferred; the unit owns no data.
// Observed value box and record views; roles inferred.
struct Obj { void **table; };
struct String { char *text; };
struct Record { char pad[132]; String name; char pad2[8]; int value144; int value148; };
struct MessageId { unsigned short value; };
struct Holder { char pad[16]; int count; };
struct Context { char pad[52]; void *display; };
struct Key { const char *text; Key(const char *p) : text(p) {} };
struct Cache { unsigned short id; char unknown[6]; };
extern Cache lbl_804b0bac, lbl_804b0bb4;
extern "C" int lbl_80286d14(void *, void *);
extern "C" Context *w3d_engine_get_context();
extern "C" void fn_802b0b84(void *, void *, void *);
extern "C" void w3d_f11a_setup_selection_80286100(void *);
extern "C" void fn_8028640c(void *);
extern "C" int w3d_constructor_lookup_name(const Key &, Obj **);
extern "C" int w3d_cc17b_service_forward_800fd62c(String *, int (*)(void *, void *), void *, void *);
extern "C" Obj *w3d_empty_803426b4(Obj *), *w3d_constructor_native_c_80342a78(Obj *);
extern "C" void *w3d_auto_80178c48(Obj *), *w3d_auto_80178d1c(Obj *);
extern "C" void w3d_f15a_select_value_80286b40(void *, void *);
extern "C" unsigned w3d_cached_message_id(Cache *, int);
extern "C" int d24d_acquire_message_80162024(void *, MessageId *, Holder **);
#define AT(T, off) (*(T *)(self + (off)))
extern "C" void d27f_value_control_start_80285b28(char *self) {
    void *value = 0;
    fn_802b0b84(self + 28, self, w3d_engine_get_context()->display);
    Record *record = AT(Record *, 40);
    String *name = &record->name;
    AT(int, 212) = record->value148;
    AT(int, 216) = record->value144;
    w3d_f11a_setup_selection_80286100(self);
    fn_8028640c(self);
    if (((unsigned short *)record->name.text)[-2] != 0 && w3d_constructor_lookup_name(record->name.text, &AT(Obj *, 256)) >= 0) {
        w3d_cc17b_service_forward_800fd62c(name, lbl_80286d14, self, self + 260);
        Obj *o = AT(Obj *, 256);
        switch (((int (*)(Obj *))o->table[6])(o)) {
        case 0:
            value = w3d_auto_80178c48(w3d_empty_803426b4(AT(Obj *, 256)));
            break;
        case 1:
            value = w3d_auto_80178d1c(w3d_constructor_native_c_80342a78(AT(Obj *, 256)));
            break;
        }
    }
    w3d_f15a_select_value_80286b40(self, value);
    MessageId first;
    first.value = w3d_cached_message_id(&lbl_804b0bac, 1);
    d24d_acquire_message_80162024(self, &first, &AT(Holder *, 264));
    MessageId second;
    second.value = w3d_cached_message_id(&lbl_804b0bb4, 1);
    d24d_acquire_message_80162024(self, &second, &AT(Holder *, 268));
    AT(Holder *, 264)->count = 0;
    AT(Holder *, 268)->count = 0;
    AT(int, 176) = 1;
    ((void (*)(void *, int))AT(void **, 208)[5])(self + 28, 0);
}
