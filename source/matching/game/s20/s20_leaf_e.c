/* Small vector copies and virtual forwarding helpers. */
typedef struct S20Vec { float x; float y; float z; } S20Vec;
typedef void (*S20Call0)(void *);
typedef void (*S20Call1)(void *, int);

void w3d_s20_set_pending_vector_800ecec0(char *self, S20Vec *value) {
    *(S20Vec *)(self + 236) = *value;
    *(int *)(self + 248) = 1;
}

void w3d_s20_get_vector_800ed070(char *self, S20Vec *out) {
    *out = *(S20Vec *)(self + 72);
}

void w3d_s20_update_span_800ecee8(char *self, int first, int second, S20Vec *value) {
    S20Vec *current;
    if (*(int *)(self + 248) != 0) {
        *(int *)(self + 248) = 0;
        current = (S20Vec *)(self + 224);
    } else {
        current = (S20Vec *)(self + 224);
        *(S20Vec *)(self + 236) = *current;
    }
    *(int *)(self + 216) = first;
    *(int *)(self + 220) = second;
    *(S20Vec *)(self + 224) = *value;
}

void w3d_s20_release_object_800e0400(char *self) {
    void *object = *(void **)(self + 4);
    if (object != 0)
        ((S20Call1)*(void **)(*(char **)object + 8))(object, 3);
    *(int *)(self + 4) = 0;
}
