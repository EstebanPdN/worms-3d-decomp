// Inferred native GC32 owning slots. External interfaces and allocator remain native.
namespace sol35d10_resize_refs {
struct Interface;
typedef void (*Method)(Interface *);
struct Interface { Method *vtable; };
extern "C" void *fn_801fe220(unsigned);
extern "C" void fn_801fe240(void *);
struct Held {
    Interface *pointer;
    Held() : pointer(0) {}
    ~Held() { if (pointer) pointer->vtable[4](pointer); }
    Held &operator=(const Held &other) {
        if (other.pointer) other.pointer->vtable[3](other.pointer);
        if (pointer) pointer->vtable[4](pointer);
        pointer=other.pointer;
        return *this;
    }
    void clear() {
        if (pointer) pointer->vtable[4](pointer);
        pointer=0;
    }
    static void *operator new[](unsigned bytes) { return fn_801fe220(bytes); }
    static void operator delete[](void *allocation) { fn_801fe240(allocation); }
};
struct Array {
    unsigned count;
    unsigned short capacity, growth;
    Held *data;
};
typedef char HeldSize[(sizeof(Held)==4)?1:-1];
typedef char ArraySize[(sizeof(Array)==12)?1:-1];
}
extern "C" void sol35d10_resize_refs_801f282c(sol35d10_resize_refs::Array *self,int count) {
    using namespace sol35d10_resize_refs;
    if (self->capacity<count) {
        Held *replacement=new Held[count];
        if (self->data) {
            for (unsigned i=0;i<self->count;++i) {
                Held *source=self->data;
                replacement[i]=source[i];
            }
            delete[] self->data;
        }
        self->capacity=count;
        self->data=replacement;
    } else {
        for (unsigned i=count;i<self->count;++i) {
            Held *data=self->data;
            data[i].clear();
        }
    }
    self->count=count;
}
