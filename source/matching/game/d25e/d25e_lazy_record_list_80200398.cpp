// (Worms 3D GameCube PAL, 0x80200398).
//
// Lazily builds and caches an array of wrappers, one per 12-byte record of
// the info block from 0x80200460: stores the byte count at info+17 to
// *count, allocates count pointers with the global operator new[]
// (0x801fe220), and fills it with objects made by operator new(8)
// (0x801fe1d8) and 0x80200970. Returns the cached array at self+16.

extern "C" void *fn_80200460(void *);
void *operator new(unsigned);
void *operator new[](unsigned);
extern "C" void *fn_80200970(void *, void *);
struct Record { char u[12]; };
struct Info { char u[17]; unsigned char count; char v[10]; Record *records; };
struct Owner { char u[16]; void **cache; };
extern "C" void **w3d_d25e_lazy_record_list_80200398(Owner *self, unsigned *count) {
    Info *info = (Info *)fn_80200460(self);
    unsigned n = info->count;
    *count = n;
    if (self->cache == 0) {
        void **list = new void *[n];
        Record *records = info->records;
        for (unsigned i = 0; i < *count; ++i) {
            list[i] = fn_80200970(operator new(8), &records[i]);
        }
        self->cache = list;
    }
    return self->cache;
}
