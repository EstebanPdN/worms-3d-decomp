#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef void (*S19Fn2)(void *self, int arg);
extern void FUN_80004394(void *);
extern void FUN_80342a7c(void *);
extern void w3d_vector_free_80342b60(void *);
extern void w3d_auto_800200f4(void *);

void s19_release_owner_8001cac4(void *self)
{
    if (FIELD(self, void *, 68)) {
        FUN_80004394(FIELD(self, void *, 68));
        if (FIELD(self, void *, 68)) {
            ((S19Fn2)FIELD(FIELD(self, void *, 68), void **, 32872)[2])(FIELD(self, void *, 68), 3);
        }
    }
    FIELD(self, void *, 68) = 0;
    FUN_80342a7c((char *)self + 88);
    w3d_vector_free_80342b60((char *)self + 32);
    w3d_auto_800200f4(self);
}
