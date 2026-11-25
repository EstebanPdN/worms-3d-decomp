#include "w3d_ptr.h"
#line 1 "sol35a10_request_pair_v2.cpp"
#include "sol35a10_storage.hpp"
// Independent 80015f80 consumer: constructor-return pointers and real boolean accessor.
struct Sol35a10Marker;
struct Sol35a10Spec {unsigned unknown00[2],mode,unknown0c;float point[3];unsigned flags;};
struct Sol35a10SpecTable {Ptr32<Ptr32<Sol35a10Spec>> begin;};
struct Sol35a10Request {
    unsigned unknown00[4],index,argument;
    unsigned char unknown18[40],ready;
    bool isReady()const {return ready!=0;}
};
extern Ptr32<Sol35a10SpecTable> sol35a10_specs_804aa750;
extern unsigned sol35a10_context_804aa6c0;
extern Ptr32<Sol35a10Marker> sol35a10_active_804aa6f4;
extern Ptr32<Sol35a10Storage < Sol35a10Marker >> sol35a10_markers_804aa6fc;
extern "C" Ptr32<void> sol35a10_allocate_8001523c(unsigned);
extern "C" Ptr32<Sol35a10Marker> sol35a10_construct_80015c6c(Ptr32<void>,unsigned,unsigned,unsigned,Ptr32<const float>,unsigned);
extern "C" void sol35a10_request_pair_80015f80(Ptr32<Sol35a10Request> self) {
    if (!self->isReady()) {
        Ptr32<Sol35a10Spec> spec=*reinterpret_cast<Sol35a10Spec **>(w3d::R(reinterpret_cast<unsigned char *>(w3d::R(sol35a10_specs_804aa750->begin))+(self->index<<2)));
        sol35a10_active_804aa6f4=sol35a10_construct_80015c6c(sol35a10_allocate_8001523c(48),self->argument,sol35a10_context_804aa6c0,spec->mode,spec->point,spec->flags);
        sol35a10_markers_804aa6fc->push(sol35a10_construct_80015c6c(sol35a10_allocate_8001523c(48),self->argument,sol35a10_context_804aa6c0,spec->mode,spec->point,spec->flags));
    }
}


