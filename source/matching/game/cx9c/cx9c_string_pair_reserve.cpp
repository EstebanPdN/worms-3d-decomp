/* Inferred vector reserve with nontrivial values. begin/end +0/+4,
 * allocator word +8, capacity-end +12. Placement copy constructs new values
 * before destroying old values; original string hooks retain ownership.
 */
inline void *operator new(unsigned int,void *p) throw() {return p;}
struct Cx9cReserveString;
extern "C" {
void *cx9c_allocate_80212fd4(unsigned int);
void *cx9c_allocation_fallback_803413d8(unsigned int);
void cx9c_deallocate_802134fc(void *);
void cx9c_string_init_8020c5c0(Cx9cReserveString *);
void cx9c_string_finish_8020c5c4(Cx9cReserveString *);
void cx9c_string_release_80341588(Cx9cReserveString *);
unsigned short *cx9c_string_header_80341884(Cx9cReserveString *);
}
static inline void *cx9c_storage(unsigned int bytes){void *p=cx9c_allocate_80212fd4(bytes);if(!p)p=cx9c_allocation_fallback_803413d8(bytes);return p;}
struct Cx9cReserveString {
    char *data;
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
static inline Cx9cReserveValue *cx9c_uninitialized_copy(Cx9cReserveValue *first,Cx9cReserveValue *last,Cx9cReserveValue *result){while(first!=last){new(result) Cx9cReserveValue(*first);++first;++result;}return result;}
static inline void cx9c_construct_range(Cx9cReserveValue *first,Cx9cReserveValue *last,Cx9cReserveValue *destination){cx9c_uninitialized_copy(first,last,destination);}
struct Cx9cReserveVector {
    Cx9cReserveValue *begin,*end;unsigned int allocator;Cx9cReserveValue *capacity_end;
    Cx9cReserveValue *allocate(unsigned int count) {return count?(Cx9cReserveValue *)cx9c_storage(count*sizeof(Cx9cReserveValue)):0;}
    Cx9cReserveValue *allocate_copy(unsigned int count,Cx9cReserveValue *first,Cx9cReserveValue *last) {
        Cx9cReserveValue *replacement=allocate(count);
        cx9c_construct_range(first,last,replacement);
        return replacement;
    }
    void destroy_range(Cx9cReserveValue *last,Cx9cReserveValue *first) {
        while (first!=last) {first->~Cx9cReserveValue();++first;}
    }
};
extern "C" void w3d_cx9c_string_pair_reserve_8035c9f8(Cx9cReserveVector *self,unsigned int requested)
{
    if ((unsigned int)(self->capacity_end-self->begin)<requested) {
        unsigned int count=self->end-self->begin;
        Cx9cReserveValue *replacement;
        if (self->begin) {
            replacement=self->allocate_copy(requested,self->begin,self->end);
            self->destroy_range(self->end,self->begin);
            if (self->begin) cx9c_deallocate_802134fc(self->begin);
        } else replacement=self->allocate(requested);
        Cx9cReserveValue *new_end=(Cx9cReserveValue *)(count*sizeof(Cx9cReserveValue)+(unsigned int)replacement);
        Cx9cReserveValue *new_capacity=(Cx9cReserveValue *)(requested*sizeof(Cx9cReserveValue)+(unsigned int)replacement);
        self->begin=replacement;self->end=new_end;*(Cx9cReserveValue **)&self->capacity_end=new_capacity;
    }
}
