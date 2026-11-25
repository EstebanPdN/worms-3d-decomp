/* Slot-table lookups and record copies. */
typedef struct S20Object { void **vtable; } S20Object;
extern int fn_80177eb0(char *, void *, unsigned short *);

int w3d_s20_query_slot_80176cd4(char *self, int key, int *out) {
    unsigned short index;
    int result;
    if (fn_80177eb0(self, key, &index) >= 0) {
        S20Object *object = ((S20Object **)*(void **)(self + 24))[index];
        *out = ((int (*)(S20Object *))object->vtable[6])(object);
        result = 0;
    } else {
        *out = 8;
        result = 0x80004005;
    }
    return result;
}

extern void fn_8020bd38(char *, int);

int w3d_s20_copy_record_80174274(char *self, int unused, char *source) {
    unsigned int flags;
    int first;
    int second;
    unsigned short third;
    fn_8020bd38(self + 20, *(int *)source);
    *(unsigned char *)(self + 24) = *(unsigned char *)(source + 4);
    *(unsigned char *)(self + 25) = *(unsigned char *)(source + 5);
    first = *(int *)(source + 8);
    flags = *(unsigned int *)(self + 24);
    *(int *)(self + 32) = first;
    flags &= 0xffff7fff;
    *(int *)(self + 36) = *(int *)(source + 12);
    third = *(unsigned short *)(source + 20);
    *(unsigned short *)(self + 44) = third;
    second = *(int *)(source + 16);
    *(unsigned int *)(self + 24) = flags;
    *(int *)(self + 48) = second;
    return 0;
}
