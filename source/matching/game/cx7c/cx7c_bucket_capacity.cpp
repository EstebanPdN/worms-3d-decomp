/* Inferred prime-bucket count selector, original 0x8035c518.
 * 28 original u32 entries begin at 0x803e7650. The lower-bound route
 * receives its original iterator tag and null distance-type pointer.
 */
struct Cx7cSearchTag {unsigned char empty; ~Cx7cSearchTag() {}};
extern "C" {
extern unsigned int cx7c_prime_table_803e7650[];
void cx7c_tag_initialize_8035c4c4(Cx7cSearchTag *,...);
unsigned int *cx7c_prime_lower_bound_8035c4d0(unsigned int *,unsigned int *,const unsigned int &,const Cx7cSearchTag &,int *);
}
extern "C" unsigned int w3d_cx7c_bucket_capacity_8035c518(void *,unsigned int requested)
{
    unsigned int *begin=cx7c_prime_table_803e7650;
    unsigned int *end=begin+28;
    Cx7cSearchTag tag;
    cx7c_tag_initialize_8035c4c4(&tag,0);
    unsigned int *found=cx7c_prime_lower_bound_8035c4d0(begin,end,requested,tag,0);
    return found==end ? *(found-1) : *found;
}
