/* Target cursor lifecycle, shadow setup and camera routing. */
extern "C" {
struct S2TargetObject { void **vtable; };
struct S2Target { void **vtable; unsigned short refs; unsigned char pad06[22]; S2TargetObject *cursor, *object; unsigned char pad24[4]; int subscription; unsigned char pad2c[48]; S2TargetObject *shadow; int active, mode; };
struct S2Registry { unsigned char pad00[34]; unsigned short count; };
struct S2TargetRef { S2TargetObject *value; int reserved;
    S2TargetRef() { value = 0; }
    S2TargetRef(S2TargetObject *object) { value = object; if (object) ((void (*)(S2TargetObject *))object->vtable[3])(object); }
    ~S2TargetRef() { if (value) ((void (*)(S2TargetObject *))value->vtable[4])(value); }
};
struct S2TargetArg { S2TargetObject *value; int reserved;
    S2TargetArg() {}
    S2TargetArg(S2TargetObject *object) { value = object; if (object) ((void (*)(S2TargetObject *))object->vtable[3])(object); }
};
struct S2TargetString { char *text; int reserved; };
struct S2TargetKey { const char *text; };
void *w3d_heap_allocate_entry_a(unsigned int);
int w3d_fn_8004db14(S2Target *);
void w3d_fn_8004dc38(S2Target *, int);
void w3d_registry_unlink_80118bac(S2Target *);
void w3d_state_register(S2Registry *, void *);
void w3d_fn_8004e0dc(S2Target *, const char *, const char *, const char *, const char *, const char *, const char *);
int w3d_cached_message_id(void *, int);
void w3d_fn_80162024(void *, unsigned short *, void *);
void w3d_string_from_text(S2TargetString *, const char *);
void w3d_string_base_finish(S2TargetString *);
void w3d_string_release(S2TargetString *);
void w3d_handle_set_name(S2TargetString *, S2TargetObject **, int);
S2TargetObject *w3d_empty_8034357c(S2TargetObject *);
void w3d_fn_80173df0(S2TargetObject *, void *);
int w3d_fn_8004e384(S2Target *, int, int);
void w3d_fn_8004e2a4(S2Target *, S2TargetArg *, int);
int w3d_constant_8015fb2c(S2Target *, int);
int w3d_fn_8015f65c(unsigned short, void *);
void w3d_fn_800fc230(S2TargetKey *, int *);
int w3d_fn_8004ddc8(S2Target *, unsigned short *);
extern unsigned char w3d_obj_80410908[];
extern S2Registry w3d_registry_80361260[];
extern unsigned int w3d_obj_804ad424, w3d_obj_804af314;
extern const char w3d_str_8039aa00[], w3d_str_8039aa18[], w3d_str_8039aa30[], w3d_str_8039aa38[], w3d_str_8039aa48[], w3d_str_8039aa54[], w3d_str_8039aa64[], w3d_str_8039aa7c[], w3d_str_8039aa8c[];


S2Target *w3d_target_cursor_create_80118bf0()
{
    S2Target *self = (S2Target *)w3d_heap_allocate_entry_a(104);
    w3d_fn_8004db14(self);
    self->shadow = 0;
    self->vtable = (void **)w3d_obj_80410908;
    w3d_state_register(w3d_registry_80361260, self ? &self->refs : 0);
    ++w3d_registry_80361260[0].count;
    return self;
}


unsigned short w3d_target_cursor_release_80118c68(S2Target *self)
{
    unsigned short remaining = --self->refs;
    if (!remaining) {
        w3d_registry_unlink_80118bac(self);
        if (self) {
            self->vtable = (void **)w3d_obj_80410908;
            if (self->shadow) ((void (*)(S2TargetObject *))self->shadow->vtable[4])(self->shadow);
            w3d_fn_8004dc38(self, 3);
        }
    }
    return remaining;
}


#if 0 /* 3 attempts; four argument setup instructions differ in best candidate */
void w3d_target_cursor_setup_80118d04(S2Target *self)
{
    w3d_fn_8004e0dc(self, w3d_str_8039aa00, w3d_str_8039aa18, w3d_str_8039aa30, w3d_str_8039aa38, w3d_str_8039aa48, w3d_str_8039aa54);
    struct { S2TargetArg temporary; S2TargetString name; unsigned short message; } local;
    local.message = w3d_cached_message_id(&w3d_obj_804ad424, 1);
    w3d_fn_80162024(self, &local.message, &self->subscription);
    S2TargetArg *temporary = &local.temporary;
    temporary->value = 0;
    w3d_string_from_text(&local.name, w3d_str_8039aa64);
    w3d_handle_set_name(&local.name, (S2TargetObject **)temporary, 255);
    w3d_string_base_finish(&local.name);
    w3d_string_release(&local.name);
    S2TargetObject *shadow = w3d_empty_8034357c(temporary->value);
    if (shadow) ((void (*)(S2TargetObject *))shadow->vtable[3])(shadow);
    if (self->shadow) ((void (*)(S2TargetObject *))self->shadow->vtable[4])(self->shadow);
    self->shadow = shadow;
    w3d_fn_80173df0(shadow, &w3d_obj_804af314);
    ((void (*)(S2TargetObject *, S2TargetObject *, const char *))self->cursor->vtable[23])(self->cursor, self->shadow, w3d_str_8039aa7c);
    self->active = 0;
    self->mode = 0;
    if (temporary->value) ((void (*)(S2TargetObject *))temporary->value->vtable[4])(temporary->value);
}
#endif


int w3d_target_cursor_tick_80118edc(S2Target *self, int now)
{
    int state = w3d_fn_8004e384(self, self->active, self->mode);
    S2TargetArg object(self->object);
    w3d_fn_8004e2a4(self, &object, state);
    w3d_constant_8015fb2c(self, now);
    return 0;
}


int w3d_target_cursor_dispatch_80118f5c(S2Target *self, unsigned short *message)
{
    if (w3d_fn_8015f65c(*message, &w3d_obj_804ad424) && self->active) {
        S2TargetKey key;
        int mode;
        key.text = w3d_str_8039aa8c;
        w3d_fn_800fc230(&key, &mode);
        if (mode == 1) ((void (*)(S2Target *))self->vtable[11])(self);
        else ((void (*)(S2Target *))self->vtable[12])(self);
    } else return w3d_fn_8004ddc8(self, message);
    return 0;
}

}
