// Native GC32 retained array; global array allocation/deallocation boundary inferred.
void *operator new[](unsigned);
void operator delete[](void *);
namespace Sol35d13FactoryArray {
struct Interface {
    virtual void slot0()=0;
    virtual void retain()=0;
    virtual void release()=0;
};
extern "C" void sol35d13_report_802fb7ac(const char *,...);
extern "C" const char sol35d13_allocation_message_803b35bc[];
struct HeldInterface {
    Interface *pointer;
    HeldInterface():pointer(0) {}
    ~HeldInterface() { if(pointer) pointer->release(); }
    void clear() {
        if(pointer) pointer->release();
        pointer=0;
    }
};
// Same explicit retain/release/reload contract as the frozen I7 component.
inline void assign_held(HeldInterface &destination,const HeldInterface &source) {
    if(source.pointer) source.pointer->retain();
    if(destination.pointer) destination.pointer->release();
    destination.pointer=source.pointer;
}
// Allocation/cookie construction belongs to this real array factory.
inline HeldInterface *make_slots(unsigned count) { return new HeldInterface[count]; }
struct CountedRefs {
    unsigned count;
    unsigned short capacity,growth;
    HeldInterface *slots;
};
typedef char HeldSize[(sizeof(HeldInterface)==4)?1:-1];
typedef char CountedRefsSize[(sizeof(CountedRefs)==12)?1:-1];
}
extern "C" void sol35d13_resize_refs_80210b90_factory(Sol35d13FactoryArray::CountedRefs *self,unsigned count) {
    using namespace Sol35d13FactoryArray;
    if(int(self->capacity)>=int(count)) {
        for(unsigned i=count;i<self->count;++i) {
            HeldInterface *slots=self->slots;
            slots[i].clear();
        }
    } else {
        HeldInterface *replacement=make_slots(count);
        if(!replacement) {
            sol35d13_report_802fb7ac(sol35d13_allocation_message_803b35bc,count);
            return;
        }
        if(self->slots) {
            for(unsigned i=0;i<self->count;++i) {
                HeldInterface *slots=self->slots;
                assign_held(replacement[i],slots[i]);
            }
            delete[] self->slots;
        }
        self->capacity=count;
        self->slots=replacement;
    }
    self->count=count;
}
