/* Custom and random level list construction. */
extern "C" {
struct S2Type { unsigned char pad00[20]; S2Type *parent;
    int matches(S2Type *target) {
        S2Type *type = this;
        while (type != target) {
            S2Type *next = type->parent;
            if (type == next) return 0;
            type = next;
        }
        return 1;
    }
};
struct S2Header { unsigned char pad00[4]; unsigned short sharing; unsigned char pad06[18]; int length; unsigned short users; unsigned char pad1e[2]; unsigned char data[1]; };
unsigned char *w3d_fn_801ef048(S2Header **, int, int, int);
struct S2Buffer { S2Header *header;
    void clear() {
        S2Header *h = header;
        if (h->sharing == 1 && h->length == 0) ++h->users;
        else w3d_fn_801ef048(&header, 0, 4, 0);
    }
    unsigned char *resize(int count, int stride, int mode) {
        S2Header *h = header;
        if (h->sharing == 1 && count == h->length) { ++h->users; return h->data; }
        return w3d_fn_801ef048(&header, count, stride, mode);
    }
};
void w3d_string_release_header(void *);
struct S2String { char *value;
    void copy(const S2String &other) {
        ++*(unsigned short *)(other.value - 6);
        char *old = value;
        if (--*(unsigned short *)(old - 6) == 0) w3d_string_release_header(old - 6);
        value = other.value;
    }
};
void w3d_string_assign(S2String *, const char *);
struct S2Object { void **vtable; unsigned char pad04[20]; S2Buffer names, values, metadata; unsigned char pad24[8]; int mode; unsigned char pad30[24]; S2String name; };
struct S2ListOwner { unsigned char pad00[60]; S2Object *custom, *random; };
struct S2Ref {
    S2Object *value; int reserved;
    S2Ref() { value = 0; }
    S2Ref(S2Object *object) { value = object; if (object) ((void (*)(S2Object *))object->vtable[3])(object); }
    ~S2Ref() { if (value) ((void (*)(S2Object *))value->vtable[4])(value); }
    void assign(S2Object *object) {
        if (object) ((void (*)(S2Object *))object->vtable[3])(object);
        if (value) ((void (*)(S2Object *))value->vtable[4])(value);
        value = object;
    }
};
struct S2Reference;
void w3d_fn_80178474(S2Reference *, int);
struct S2Reference { int value, tag;
};
struct S2Key { const char *text; };
struct S2Iterator { int cursor, reserved; S2Iterator() { cursor = 0; } };
S2Object *w3d_empty_80341584(S2Object *);
S2Object *w3d_auto_80179598(S2Object *, S2Reference *);
S2Object *w3d_fn_8020b680(void *);
S2Object *w3d_auto_801797b4(S2Object *);
void w3d_fn_801ef380(S2Object *, int, int, int, int);
void w3d_fn_801ef174(S2Object *, int, int, S2Object *);
int w3d_fn_800fc69c(S2Iterator *, S2Ref *);
int w3d_fn_800fc2b0(S2Key *, const char **);
extern unsigned char w3d_obj_80419e68[], w3d_type_803667a8[];


#if 0 /* 2 attempts; reference temporary stack layout and inline register allocation differ */
void w3d_level_list_8010fd08(S2ListOwner *self)
{
    S2Reference reference;
    reference.value = 0;
    S2Reference *referencePtr = &reference;
    referencePtr->tag = 0xe3a8;
    {
    S2Ref selected;
    {
        S2Ref temporary(w3d_auto_80179598(w3d_empty_80341584(self->custom), referencePtr));
        if (temporary.value) selected.assign(temporary.value);
    }
    w3d_fn_801ef380(selected.value, 32, 0, 0, selected.value->metadata.header->length);
    selected.value->values.clear();
    S2Ref list(w3d_fn_8020b680(w3d_obj_80419e68));
    S2Ref item;
    S2Iterator iterator;
    while (w3d_fn_800fc69c(&iterator, &item)) {
        if (((int (*)(S2Object *))item.value->vtable[6])(item.value) != 5) continue;
        S2Object *candidate = w3d_auto_801797b4(w3d_empty_80341584(item.value));
        if (((S2Type *(*)(S2Object *))candidate->vtable[5])(candidate)->matches((S2Type *)w3d_type_803667a8)) {
            S2Object *level = w3d_auto_801797b4(w3d_empty_80341584(item.value));
            if (level->mode == 2) {
                int count = list.value->names.header->length;
                S2String *names = (S2String *)list.value->names.resize(count + 1, 4, 2);
                S2String *values = (S2String *)selected.value->values.resize(selected.value->values.header->length + 1, 4, 2);
                names[count].copy(level->name);
                w3d_string_assign(&values[count], ((const char *(*)(S2Object *))item.value->vtable[8])(item.value));
                S2Key key;
                const char *translated;
                key.text = level->name.value;
                if (w3d_fn_800fc2b0(&key, &translated) >= 0) w3d_string_assign(&names[count], translated);
            }
        }
    }
    w3d_fn_801ef174(selected.value, 32, 0, list.value);
    }
    w3d_fn_80178474(&reference, 2);
}
#endif


#if 0 /* 2 attempts; reference temporary stack layout and inline register allocation differ */
void w3d_level_list_801100ac(S2ListOwner *self)
{
    S2Reference reference;
    reference.value = 0;
    S2Reference *referencePtr = &reference;
    referencePtr->tag = 0xe3a8;
    {
    S2Ref selected;
    {
        S2Ref temporary(w3d_auto_80179598(w3d_empty_80341584(self->random), referencePtr));
        if (temporary.value) selected.assign(temporary.value);
    }
    w3d_fn_801ef380(selected.value, 32, 0, 0, selected.value->metadata.header->length);
    selected.value->values.clear();
    S2Ref list(w3d_fn_8020b680(w3d_obj_80419e68));
    S2Ref item;
    S2Iterator iterator;
    while (w3d_fn_800fc69c(&iterator, &item)) {
        if (((int (*)(S2Object *))item.value->vtable[6])(item.value) != 5) continue;
        S2Object *candidate = w3d_auto_801797b4(w3d_empty_80341584(item.value));
        if (((S2Type *(*)(S2Object *))candidate->vtable[5])(candidate)->matches((S2Type *)w3d_type_803667a8)) {
            S2Object *level = w3d_auto_801797b4(w3d_empty_80341584(item.value));
            if (level->mode == 1) {
                int count = list.value->names.header->length;
                S2String *names = (S2String *)list.value->names.resize(count + 1, 4, 2);
                S2String *values = (S2String *)selected.value->values.resize(selected.value->values.header->length + 1, 4, 2);
                names[count].copy(level->name);
                w3d_string_assign(&values[count], ((const char *(*)(S2Object *))item.value->vtable[8])(item.value));
                S2Key key;
                const char *translated;
                key.text = level->name.value;
                if (w3d_fn_800fc2b0(&key, &translated) >= 0) w3d_string_assign(&names[count], translated);
            }
        }
    }
    w3d_fn_801ef174(selected.value, 32, 0, list.value);
    }
    w3d_fn_80178474(&reference, 2);
}
#endif

}
