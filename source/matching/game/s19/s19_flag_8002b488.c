#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
typedef struct S19Iface { void **vtable; } S19Iface;
typedef int (*S19Query)(S19Iface *self);
typedef void (*S19Set)(S19Iface *self, int value);
extern void *w3d_s20_lookup_handle_object_80164fc8(int);

int s19_update_flag_8002b488(void *self)
{
    int handle = FIELD(self, int, 28);
    if (handle == -1)
        return 0;
    {
        void *object = w3d_s20_lookup_handle_object_80164fc8(handle);
        if (FIELD(object, int, 96) != 0) {
            if (((S19Query)FIELD(self, S19Iface *, 32)->vtable[28])(FIELD(self, S19Iface *, 32)) == 0)
                ((S19Set)FIELD(self, S19Iface *, 32)->vtable[22])(FIELD(self, S19Iface *, 32), 1);
        } else {
            if (((S19Query)FIELD(self, S19Iface *, 32)->vtable[28])(FIELD(self, S19Iface *, 32)) == 1)
                ((S19Set)FIELD(self, S19Iface *, 32)->vtable[22])(FIELD(self, S19Iface *, 32), 0);
        }
    }
    return 0;
}
