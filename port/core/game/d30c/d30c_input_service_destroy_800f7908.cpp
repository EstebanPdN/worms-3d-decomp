#include "w3d_ptr.h"
#line 1 "d30c_input_service_destroy_800f7908.cpp"
// d30c: 0x800f7908. Input service destructor body: clears the singleton, releases the raw buffer, destroys the 24 record queues in reverse order and forwards to the base destructor with the caller's flags. Names are inferred.
#include "d25c_input_queue.h"
extern char table_80410480[];
struct Service {
    Ptr32<const void> vtable;
    char u4[24];
    D24fVector<D24fTimedRecord> a0; D24fVector<D24fTimedWord> a1; D24fVector<D24fTimedString> a2; D24fVector<D24fTimedWord2> a3; D24fVector<D24fTimedFloat> a4; D24fVector<D24fTimedFloat2> a5;
    D24fVector<D24fTimedRecord> b0; D24fVector<D24fTimedWord> b1; D24fVector<D24fTimedString> b2; D24fVector<D24fTimedWord2> b3; D24fVector<D24fTimedFloat> b4; D24fVector<D24fTimedFloat2> b5;
    D24fVector<D24fTimedRecord> c0; D24fVector<D24fTimedWord> c1; D24fVector<D24fTimedString> c2; D24fVector<D24fTimedWord2> c3; D24fVector<D24fTimedFloat> c4; D24fVector<D24fTimedFloat2> c5;
    D24fVector<D24fTimedRecord> d0; D24fVector<D24fTimedWord> d1; D24fVector<D24fTimedString> d2; D24fVector<D24fTimedWord2> d3; D24fVector<D24fTimedFloat> d4; D24fVector<D24fTimedFloat2> d5;
    Ptr32<void> raw412;
};
extern Ptr32<Service> service_804aaf48;
extern "C" void base_destroy_801628ec(Ptr32<Service>, int);
extern "C" void d30c_input_service_destroy_800f7908(Ptr32<Service> s, int flags) {
    Ptr32<Service> self = s;
    self->vtable = table_80410480;
    service_804aaf48 = 0;
    if (self->raw412) w3d_handle_storage_release(self->raw412);
    self->d5.clear_storage();
    self->d4.clear_storage();
    self->d3.clear_storage();
    self->d2.clear_storage();
    self->d1.clear_storage();
    self->d0.clear_storage();
    self->c5.clear_storage();
    self->c4.clear_storage();
    self->c3.clear_storage();
    self->c2.clear_storage();
    self->c1.clear_storage();
    self->c0.clear_storage();
    self->b5.clear_storage();
    self->b4.clear_storage();
    self->b3.clear_storage();
    self->b2.clear_storage();
    self->b1.clear_storage();
    self->b0.clear_storage();
    self->a5.clear_storage();
    self->a4.clear_storage();
    self->a3.clear_storage();
    self->a2.clear_storage();
    self->a1.clear_storage();
    self->a0.clear_storage();
    base_destroy_801628ec(self, flags);
}


