// cc39c: 0x80098240 (300 bytes), reset a worm view and rebind its
// "ActiveWormIndex" object.
// Observed in the original DOL: a 12-byte message from the r13 queue
// 0x804b1754 (0x801613f0) is initialized by 0x800c1620 (returns the message;
// copies the referenced word to +8) from a temporary copy of the word at +20
// and posted (0x8016239c). The view then receives slot word 1024 (0x8003e2e0),
// word 1079 (0x8003e2bc), its own +20 word (0x8003e28c), the scalar at
// 0x8037f754 (9.0f, 0x8003e25c) and a three-float vector of 0x8037f758 (0.0f,
// 0x8003e23c). The original "ActiveWormIndex" literal (0x8037f744) is looked up
// (0x800fc1b0) into a reference holder; its object (identity 0x803426b4)
// replaces the reference at +152 with retain (+12) before release (+16), the
// holder is released at scope end, and the word at +136 receives 0x80178c48 of
// the new reference. All names and views are inferred.
struct cc39c_Vec3 {
    float x, y, z;
    cc39c_Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};
struct cc39c_Object;
struct cc39c_ObjectVtable {
    void *unknown00[3];
    void (*retain)(cc39c_Object *);      // +12
    void (*release)(cc39c_Object *);     // +16
};
struct cc39c_Object { cc39c_ObjectVtable *vtable; };
// Reference holder: assignment retains the new object before releasing the old.
struct cc39c_Ref {
    cc39c_Object *object;
    cc39c_Ref() : object(0) {}
    ~cc39c_Ref() { if (object) object->vtable->release(object); }
    cc39c_Ref &operator=(cc39c_Object *other) {
        if (other) other->vtable->retain(other);
        if (object) object->vtable->release(object);
        object = other;
        return *this;
    }
};
struct cc39c_Queue;
// Word passed by value to 0x800c1620: the SVR4 caller copies the aggregate to a
// temporary and passes its address.
struct cc39c_WormId { int value; };
struct cc39c_WormView {
    unsigned char unknown00[20];
    cc39c_WormId worm;                   // +20
    unsigned char unknown18[112];
    int index;                           // +136
    unsigned char unknown8c[12];
    cc39c_Ref active;                    // +152
};
extern "C" {
void *cc39c_message_alloc_801613f0(cc39c_Queue *, unsigned int);
void *cc39c_created_message_800c1620(void *, cc39c_WormId);
int cc39c_post_current_8016239c(void *);
void cc39c_set_slot_word_8003e2e0(cc39c_WormView *, int);
void cc39c_set_word_8003e2bc(cc39c_WormView *, int);
void cc39c_set_worm_8003e28c(cc39c_WormView *, int);
void cc39c_set_scalar_8003e25c(cc39c_WormView *, float);
void cc39c_set_vector_8003e23c(cc39c_WormView *, const cc39c_Vec3 *);
unsigned int cc39c_lookup_name_800fc1b0(const char **, cc39c_Ref *);
cc39c_Object *cc39c_object_cast_803426b4(cc39c_Object *);
int cc39c_reference_index_80178c48(cc39c_Object *);
extern cc39c_Queue *cc39c_queue_804b1754;
extern const char cc39c_active_worm_index_8037f744[];
extern const float cc39c_scalar_8037f754[], cc39c_zero_8037f758[];
}
extern "C" void cc39c_reset_active_worm_80098240(cc39c_WormView *self) {
    cc39c_post_current_8016239c(cc39c_created_message_800c1620(cc39c_message_alloc_801613f0(cc39c_queue_804b1754, 12), self->worm));
    cc39c_set_slot_word_8003e2e0(self, 1024);
    cc39c_set_word_8003e2bc(self, 1079);
    cc39c_set_worm_8003e28c(self, self->worm.value);
    cc39c_set_scalar_8003e25c(self, cc39c_scalar_8037f754[0]);
    cc39c_Vec3 zero(cc39c_zero_8037f758[0], cc39c_zero_8037f758[0], cc39c_zero_8037f758[0]);
    cc39c_set_vector_8003e23c(self, &zero);
    {
        cc39c_Ref found;
        const char *name = cc39c_active_worm_index_8037f744;
        cc39c_lookup_name_800fc1b0(&name, &found);
        self->active = cc39c_object_cast_803426b4(found.object);
    }
    self->index = cc39c_reference_index_80178c48(self->active.object);
}
