#include "w3d_ptr.h"
#line 1 "d29s_service_add_unique_801b3e88.cpp"
/* Adds an item to the owner's list unless the service reports an equal one, holding
 * the service's lock slot around the search. Returns the existing or the new item. */
#include "compat/stlport_sn_oom.h"
#include <vector>

class D29sItem_801b3e88 {
public:
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN17D29sItem_801b3e885slot0Ev"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN17D29sItem_801b3e886retainEv"));
 __attribute__((always_inline)) inline void slot0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D29sItem_801b3e88, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D29sItem_801b3e88, 3))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D29sItem_801b3e88; };
class D29sService_801b3e88 {
public:
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN20D29sService_801b3e885slot0Ev"));
    void w3d_r_slot1() __asm__(W3D_SYM("_ZN20D29sService_801b3e885slot1Ev"));
    void w3d_r_slot2() __asm__(W3D_SYM("_ZN20D29sService_801b3e885slot2Ev"));
    void w3d_r_slot3() __asm__(W3D_SYM("_ZN20D29sService_801b3e885slot3Ev"));
    int w3d_r_differs(Ptr32<D29sItem_801b3e88> item) __asm__(W3D_SYM("_ZN20D29sService_801b3e887differsEP17D29sItem_801b3e88"));
    void w3d_r_slot5() __asm__(W3D_SYM("_ZN20D29sService_801b3e885slot5Ev"));
    void w3d_r_slot6() __asm__(W3D_SYM("_ZN20D29sService_801b3e885slot6Ev"));
    void w3d_r_slot7() __asm__(W3D_SYM("_ZN20D29sService_801b3e885slot7Ev"));
    void w3d_r_slot8() __asm__(W3D_SYM("_ZN20D29sService_801b3e885slot8Ev"));
    void w3d_r_slot9() __asm__(W3D_SYM("_ZN20D29sService_801b3e885slot9Ev"));
    void w3d_r_hold(Ptr32<D29sItem_801b3e88> item) __asm__(W3D_SYM("_ZN20D29sService_801b3e884holdEP17D29sItem_801b3e88"));
 __attribute__((always_inline)) inline void slot0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D29sService_801b3e88, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D29sService_801b3e88, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D29sService_801b3e88, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D29sService_801b3e88, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int differs(Ptr32<D29sItem_801b3e88> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<D29sItem_801b3e88>))w3d::vfn(this->w3d_vptr_D29sService_801b3e88, 6))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void slot5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D29sService_801b3e88, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D29sService_801b3e88, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D29sService_801b3e88, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D29sService_801b3e88, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D29sService_801b3e88, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void hold(Ptr32<D29sItem_801b3e88> w3d_a0) { ((void (*)(w3d_u32, Ptr32<D29sItem_801b3e88>))w3d::vfn(this->w3d_vptr_D29sService_801b3e88, 12))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_D29sService_801b3e88; };
class D29sOwner_801b3e88 {
public:
    Ptr32<D29sItem_801b3e88> add_unique(Ptr32<D29sItem_801b3e88> item);

private:
    char head[24];
    Ptr32<D29sService_801b3e88> service;
    char gap[60];
    _STL::vector <Ptr32<D29sItem_801b3e88> > items;
};

Ptr32<D29sItem_801b3e88> D29sOwner_801b3e88::add_unique(Ptr32<D29sItem_801b3e88> item) {
    service->hold(item);
    for (Ptr32<D29sItem_801b3e88> *it = items.begin(),*end = items.end(); it != end; ++it) {
        if (!service->differs(*it)) {
            service->hold(0);
            return *it;
        }
    }
    items.push_back(item);
    item->retain();
    service->hold(0);
    return item;
}


