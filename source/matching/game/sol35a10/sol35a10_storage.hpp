// Inferred GC32 byte-storage algorithm, independently seen in each consumer.
// A shared template is a reconstruction convenience, not original class identity.
#ifndef SOL35A10_STORAGE_HPP
#define SOL35A10_STORAGE_HPP
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
extern "C" unsigned char *sol35a10_allocate_80212fd4(unsigned);
extern "C" void sol35a10_release_802134fc(void *);
extern "C" void *sol35a10_copy_802eee50(void *, const void *, ...);
inline const int &sol35a10_larger(const int &a,const int &b) {return a<b?b:a;}
inline const unsigned &sol35a10_smaller(const unsigned &a,const unsigned &b) {return b<a?b:a;}
template<class T> struct Sol35a10Storage {
    unsigned char *begin,*end,*capacity;
    void push(T *const &value) {
        if (end==capacity) {
            unsigned used=end-begin;
            int next=used+1;
            int grown=used+(used>>1);
            unsigned allocated=sol35a10_larger(next,grown)*4;
            unsigned char *fresh=sol35a10_allocate_80212fd4(allocated);
            if (begin) {
                sol35a10_copy_802eee50(fresh,begin,sol35a10_smaller(allocated,used));
                sol35a10_release_802134fc(begin);
            }
            begin=fresh;
            end=fresh+used;
            capacity=fresh+allocated;
        }
        new (end) T *(value);
        end+=4;
    }
};
typedef char sol35a10_pointer_width[sizeof(void *)==4?1:-1];
#endif
