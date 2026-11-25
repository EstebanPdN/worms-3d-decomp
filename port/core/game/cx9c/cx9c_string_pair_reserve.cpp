#include "w3d_ptr.h"
#line 1 "cx9c_string_pair_reserve.cpp"
/* Inferred vector reserve with nontrivial values. begin/end +0/+4,
 * allocator word +8, capacity-end +12. Placement copy constructs new values
 * before destroying old values; original string hooks retain ownership.
 */
inline void *operator new(__SIZE_TYPE__,void *p) throw() {return p;}
struct Cx9cReserveString;
extern "C" {
Ptr32<void> cx9c_allocate_80212fd4(unsigned int);
Ptr32<void> cx9c_allocation_fallback_803413d8(unsigned int);
void cx9c_deallocate_802134fc(Ptr32<void>);
void cx9c_string_init_8020c5c0(Ptr32<Cx9cReserveString>);
void cx9c_string_finish_8020c5c4(Ptr32<Cx9cReserveString>);
void cx9c_string_release_80341588(Ptr32<Cx9cReserveString>);
Ptr32<unsigned short> cx9c_string_header_80341884(Ptr32<Cx9cReserveString>);
}
static inline Ptr32<void> cx9c_storage(unsigned int bytes){Ptr32<void> p=cx9c_allocate_80212fd4(bytes);if(!p)p=cx9c_allocation_fallback_803413d8(bytes);return p;}
struct Cx9cReserveString {
    Ptr32<char> data;
    Cx9cReserveString(const Cx9cReserveString &other) {
        cx9c_string_init_8020c5c0(this);data=other.data;
        ++*cx9c_string_header_80341884(this);
    }
    ~Cx9cReserveString() {
        cx9c_string_finish_8020c5c4(this);cx9c_string_release_80341588(this);
    }
};
struct Cx9cReserveValue {
    Cx9cReserveString name;unsigned short first,second;
    Cx9cReserveValue(const Cx9cReserveValue &other):name(other.name),first(other.first),second(other.second) {}
};
static inline Ptr32<Cx9cReserveValue> cx9c_uninitialized_copy(Ptr32<Cx9cReserveValue> first,Ptr32<Cx9cReserveValue> last,Ptr32<Cx9cReserveValue> result){while(first!=last){new(result) Cx9cReserveValue(*first);++first;++result;}return result;}
static inline void cx9c_construct_range(Ptr32<Cx9cReserveValue> first,Ptr32<Cx9cReserveValue> last,Ptr32<Cx9cReserveValue> destination){cx9c_uninitialized_copy(first,last,destination);}
struct Cx9cReserveVector {
    Ptr32<Cx9cReserveValue> begin; Ptr32<Cx9cReserveValue> end;unsigned int allocator;Ptr32<Cx9cReserveValue> capacity_end;
    Ptr32<Cx9cReserveValue> allocate(unsigned int count) {return count?w3d::R((Ptr32<Cx9cReserveValue>)cx9c_storage(count*sizeof(Cx9cReserveValue))):0;}
    Ptr32<Cx9cReserveValue> allocate_copy(unsigned int count,Ptr32<Cx9cReserveValue> first,Ptr32<Cx9cReserveValue> last) {
        Ptr32<Cx9cReserveValue> replacement=allocate(count);
        cx9c_construct_range(first,last,replacement);
        return replacement;
    }
    void destroy_range(Ptr32<Cx9cReserveValue> last,Ptr32<Cx9cReserveValue> first) {
        while (first!=last) {first->~Cx9cReserveValue();++first;}
    }
};
extern "C" void w3d_cx9c_string_pair_reserve_8035c9f8(Ptr32<Cx9cReserveVector> self,unsigned int requested)
{
    if ((unsigned int)(self->capacity_end-self->begin)<requested) {
        unsigned int count=self->end-self->begin;
        Ptr32<Cx9cReserveValue> replacement;
        if (self->begin) {
            replacement=self->allocate_copy(requested,self->begin,self->end);
            self->destroy_range(self->end,self->begin);
            if (self->begin) cx9c_deallocate_802134fc(self->begin);
        } else replacement=self->allocate(requested);
        Ptr32<Cx9cReserveValue> new_end=(Ptr32<Cx9cReserveValue>)w3d::G((count*sizeof(Cx9cReserveValue)+(unsigned int)w3d::H(replacement)));
        Ptr32<Cx9cReserveValue> new_capacity=(Ptr32<Cx9cReserveValue>)w3d::G((requested*sizeof(Cx9cReserveValue)+(unsigned int)w3d::H(replacement)));
        self->begin=replacement;self->end=new_end;*(Ptr32<Ptr32<Cx9cReserveValue>>)&self->capacity_end=new_capacity;
    }
}


