/* Engine vector of 16-bit glyph indices (start +0, finish +4, end of storage +8).
   Not the SGI vector: growth works in byte counts, takes
   max(capacity + missing, capacity * 3 / 2) where capacity is in bytes,
   allocates twice that through 0x80212fd4, copies min(new, used) bytes and
   releases the old block through 0x802134fc. Erase copies with memcpy.
   The insert path that does not append fills only the first slot, as in the
   original code; resize only ever appends. Names are inferred. */
#ifndef D22D_GLYPH_VECTOR_H
#define D22D_GLYPH_VECTOR_H
extern "C" {
void *memcpy(void *,const void *,unsigned,...);
void *memmove(void *,const void *,unsigned);
void *w3d_handle_storage_allocate(unsigned);
void w3d_handle_storage_release(void *);
}
static inline const int &glyph_max(const int &left,const int &right) { return left<right?right:left; }
static inline const unsigned &glyph_min(const unsigned &left,const unsigned &right) { return left>right?right:left; }
struct GlyphVector {
    unsigned short *start,*finish,*end_of_storage;
    unsigned short &operator[](unsigned i) { return start[i]; }
    unsigned size() const { return finish-start; }
    void erase(unsigned short *first,unsigned short *last)
    {
        int removed=(char*)last-(char*)first;
        memcpy(first,last,(char*)finish-(char*)last);
        finish=(unsigned short*)((char*)finish-removed);
    }
    void clear() { erase(start,finish); }
    void insert(unsigned short *pos,unsigned n,const unsigned short &x)
    {
        int index=pos-start;
        if (pos+n>end_of_storage) {
            unsigned capacity=(char*)end_of_storage-(char*)start;
            unsigned used=(char*)finish-(char*)start;
            int minimum=capacity+(n-(end_of_storage-pos));
            int grown=capacity+(capacity>>1);
            unsigned bytes=glyph_max(minimum,grown)*2;
            unsigned short *replacement=(unsigned short*)w3d_handle_storage_allocate(bytes);
            if (start) {
                memcpy(replacement,start,glyph_min(bytes,used));
                w3d_handle_storage_release(start);
            }
            start=replacement;
            finish=(unsigned short*)((char*)replacement+used);
            end_of_storage=(unsigned short*)((char*)replacement+bytes);
            pos=start+index;
        }
        if (pos==finish) {
            for (unsigned i=0;i<n;i++) finish[i]=x;
            finish+=n;
        } else {
            unsigned short value=x;
            memmove(pos+n,pos,(char*)finish-(char*)pos);
            finish+=n;
            for (unsigned i=0;i<n;i++) *pos=value;
        }
    }
    void resize(unsigned n,const unsigned short &x)
    {
        unsigned count=size();
        if (n<count) erase(start+n,finish);
        else insert(finish,n-count,x);
    }
};
#endif
