// Native GC32 partial owning interface array. Inferred identities; genuine new[].
namespace Sol35d12CountedRefs {
struct Interface {
    virtual void slot0()=0;
    virtual void retain()=0;
    virtual void release()=0;
};
extern "C" void *sol35d12_array_allocate_801fe220(unsigned);
extern "C" void sol35d12_array_free_801fe240(void *);
extern "C" void sol35d12_report_802fb7ac(const char *,...);
extern "C" const char sol35d12_allocation_message_803b35bc[];
struct HeldInterface {
    Interface *pointer;
    HeldInterface():pointer(0) {}
    ~HeldInterface() { if(pointer) pointer->release(); }
    HeldInterface &operator=(const HeldInterface &source) {
        if(source.pointer) source.pointer->retain();
        if(pointer) pointer->release();
        pointer=source.pointer;
        return *this;
    }
    void clear() {
        if(pointer) pointer->release();
        pointer=0;
    }
    static void *operator new[](unsigned bytes) { return sol35d12_array_allocate_801fe220(bytes); }
    static void operator delete[](void *storage) { sol35d12_array_free_801fe240(storage); }
};
struct CountedRefs {
    unsigned count;
    unsigned short capacity,growth;
    HeldInterface *slots;
};
typedef char HeldSize[(sizeof(HeldInterface)==4)?1:-1];
typedef char CountedRefsSize[(sizeof(CountedRefs)==12)?1:-1];
}
extern "C" void sol35d12_resize_refs_80210b90(Sol35d12CountedRefs::CountedRefs *self,unsigned count) {
    using namespace Sol35d12CountedRefs;
    if(int(self->capacity)>=int(count)) {
        for(unsigned i=count;i<self->count;++i) {
            HeldInterface *slots=self->slots;
            slots[i].clear();
        }
    } else {
        HeldInterface *replacement=new HeldInterface[count];
        if(!replacement) {
            sol35d12_report_802fb7ac(sol35d12_allocation_message_803b35bc,count);
            return;
        }
        if(self->slots) {
            for(unsigned i=0;i<self->count;++i) {
                HeldInterface *slots=self->slots;
                replacement[i]=slots[i];
            }
            delete[] self->slots;
        }
        self->capacity=count;
        self->slots=replacement;
    }
    self->count=count;
}
