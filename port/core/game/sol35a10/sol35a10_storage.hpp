// Inferred GC32 byte-storage algorithm, independently seen in each consumer.
// A shared template is a reconstruction convenience, not original class identity.
#ifndef SOL35A10_STORAGE_HPP
#define SOL35A10_STORAGE_HPP
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
extern "C" Ptr32<unsigned char> sol35a10_allocate_80212fd4(unsigned);
extern "C" void sol35a10_release_802134fc(Ptr32<void>);
extern "C" Ptr32<void> sol35a10_copy_802eee50(Ptr32<void>, Ptr32<const void>, ...);
inline const int &sol35a10_larger(const int &a,const int &b) {return a<b?b:a;}
inline const unsigned &sol35a10_smaller(const unsigned &a,const unsigned &b) {return b<a?b:a;}
template<class T> struct Sol35a10Storage {
    Ptr32<unsigned char> begin; Ptr32<unsigned char> end; Ptr32<unsigned char> capacity;
    void push(Ptr32<T> const &value) {
        if (end==capacity) {
            unsigned used=end-begin;
            int next=used+1;
            int grown=used+(used>>1);
            unsigned allocated=sol35a10_larger(next,grown)*4;
            Ptr32<unsigned char> fresh=sol35a10_allocate_80212fd4(allocated);
            if (begin) {
                sol35a10_copy_802eee50(fresh,begin,sol35a10_smaller(allocated,used));
                sol35a10_release_802134fc(begin);
            }
            begin=fresh;
            end=fresh+used;
            capacity=fresh+allocated;
        }
        *(Ptr32<T> *)w3d::w3d_any_host(end) = Ptr32<T>(value);
        end+=4;
    }
};
typedef char sol35a10_pointer_width[sizeof(Ptr32<void>)==4?1:-1];
#endif
