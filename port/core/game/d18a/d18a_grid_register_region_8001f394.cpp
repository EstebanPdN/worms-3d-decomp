#include "w3d_ptr.h"
#line 1 "d18a_grid_register_region_8001f394.cpp"
/* Grid region registration (0x8001f394). Looks up an existing region with the
 * same centre and radius through 0x8001f30c and marks it requested; otherwise
 * allocates a 28-byte region (0x8001523c), initializes it inline and appends
 * the pointer to the grid's region storage at +32. The storage grows from its
 * byte count (used + 1 versus used * 1.5, times 4) exactly as the original
 * does; this is the original policy, not a normalized vector. Built with
 * -mps-float (frame keeps 8 bytes below the save area for the saved FPR). */
struct D18aVec { float x, y, z; };

struct D18aRegion {
    unsigned unknown00;
    D18aVec position;
    float radius;
    int active;
    int requested;
    D18aRegion(const D18aVec &p, float r) { position = p; radius = r; active = 0; requested = 1; }
};

extern "C" Ptr32<void> d18a_allocate_8001523c(unsigned);
inline void *operator new(__SIZE_TYPE__ size) { return d18a_allocate_8001523c(size); }
extern "C" Ptr32<void> d18a_allocate_80212fd4(unsigned);
extern "C" void d18a_release_802134fc(Ptr32<void>);
extern "C" Ptr32<void> d18a_copy_802eee50(Ptr32<void>, Ptr32<const void>, unsigned, ...);
inline const int &larger(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &smaller(const unsigned &a, const unsigned &b) { return a > b ? b : a; }

struct D18aRegionStorage {
    Ptr32<Ptr32<D18aRegion>> begin; Ptr32<Ptr32<D18aRegion>> end; Ptr32<Ptr32<D18aRegion>> limit;
    void append(Ptr32<D18aRegion> const &value)
    {
        if (end == limit) {
            unsigned used = (Ptr32<char>)end - (Ptr32<char>)begin;
            int next = used + 1, grown = used + (used >> 1);
            unsigned allocated = larger(next, grown) * 4;
            Ptr32<Ptr32<D18aRegion>> fresh = (Ptr32<Ptr32<D18aRegion>>)d18a_allocate_80212fd4(allocated);
            if (begin) {
                d18a_copy_802eee50(fresh, begin, smaller(allocated, used));
                d18a_release_802134fc(begin);
            }
            begin = fresh;
            end = (Ptr32<Ptr32<D18aRegion>>)((Ptr32<char>)fresh + used);
            limit = (Ptr32<Ptr32<D18aRegion>>)((Ptr32<char>)fresh + allocated);
        }
        *end = value;
        ++end;
    }
};

struct D18aGrid { unsigned char unknown00[32]; D18aRegionStorage regions; };

extern "C" Ptr32<D18aRegion> d18a_grid_find_region_8001f30c(float radius, Ptr32<D18aGrid> self, Ptr32<const D18aVec> point);

extern "C" void w3d_d18a_grid_register_region_8001f394(Ptr32<D18aGrid> self, Ptr32<const D18aVec> position, float radius)
{
    Ptr32<D18aRegion> region = d18a_grid_find_region_8001f30c(radius, self, position);
    if (region)
        region->requested = 1;
    else {
        Ptr32<D18aRegion> created = new D18aRegion(*position, radius);
        self->regions.append(created);
    }
}


