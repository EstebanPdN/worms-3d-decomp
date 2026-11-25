#include "w3d_ptr.h"
#line 1 "cx7c_bucket_capacity.cpp"
/* Inferred prime-bucket count selector, original 0x8035c518.
 * 28 original u32 entries begin at 0x803e7650. The lower-bound route
 * receives its original iterator tag and null distance-type pointer.
 */
struct Cx7cSearchTag {unsigned char empty; ~Cx7cSearchTag() {}};
extern "C" {
extern unsigned int cx7c_prime_table_803e7650[];
void cx7c_tag_initialize_8035c4c4(Ptr32<Cx7cSearchTag>,...);
Ptr32<unsigned int> cx7c_prime_lower_bound_8035c4d0(Ptr32<unsigned int>,Ptr32<unsigned int>,const unsigned int &,const Cx7cSearchTag &,Ptr32<int>);
}
extern "C" unsigned int w3d_cx7c_bucket_capacity_8035c518(Ptr32<void>,unsigned int requested)
{
    Ptr32<unsigned int> begin=cx7c_prime_table_803e7650;
    Ptr32<unsigned int> end=begin+28;
    Cx7cSearchTag tag;
    cx7c_tag_initialize_8035c4c4(&tag,0);
    Ptr32<unsigned int> found=cx7c_prime_lower_bound_8035c4d0(begin,end,requested,tag,0);
    return found==end ? *(found-1) : *found;
}


