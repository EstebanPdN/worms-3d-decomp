#ifndef SOL35P8_RETAINED_RECORD_ABI_HPP
#define SOL35P8_RETAINED_RECORD_ABI_HPP
// Shared GC32 observed interface/retained-array view; native full class identities remain inferred.
// Standard size_t declaration keeps the placement-new signature valid on each frontend.
#include <stddef.h>
inline void *operator new(size_t,void *place) throw() { return place; }
extern "C" void *sol35f6a_allocate_80212fd4(unsigned);
extern "C" void *sol35f6a_fallback_803413d8(unsigned);
extern "C" void sol35f6a_release_802134fc(void *);
namespace sol35p8_abi {
struct Interface {
 virtual void slot0()=0;
 virtual void retain()=0;
 virtual void release()=0;
};
struct HeldInterface {
 Interface *pointer;
 HeldInterface(const HeldInterface &x):pointer(x.pointer) { if(pointer) pointer->retain(); }
 ~HeldInterface() { if(pointer) pointer->release(); }
};
// Explicit ownership assignment is required by the native providers.
inline void assign_held(HeldInterface &destination,const HeldInterface &source) {
 if(source.pointer) source.pointer->retain();
 if(destination.pointer) destination.pointer->release();
 destination.pointer=source.pointer;
}
struct CountedRefs;
extern "C" CountedRefs *sol35f6a_copy_refs_802109fc(CountedRefs *,const CountedRefs *);
extern "C" void sol35f6a_destroy_refs_80210abc(CountedRefs *,int);
extern "C" CountedRefs *sol35i7_assign_refs_80210eb4(CountedRefs *,const CountedRefs *);
extern "C" void sol35i7_clear_refs_80210afc(CountedRefs *);
// 80210b90 is not present in the admitted ledger. This is a boundary only;
// native capacity comparison is signed, subsequent count loops unsigned.
extern "C" void sol35i7_resize_refs_80210b90(CountedRefs *,unsigned);
extern "C" void sol35i7_delete_801fe1f8(void *);
extern "C" void sol35i7_array_free_801fe240(void *);
struct CountedRefs {
 unsigned count;
 unsigned short capacity,growth;
 Interface **slots;
 CountedRefs(const CountedRefs &x) { sol35f6a_copy_refs_802109fc(this,&x); }
 ~CountedRefs() { sol35f6a_destroy_refs_80210abc(this,2); }
};
}
#endif
