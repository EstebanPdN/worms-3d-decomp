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
Ptr32<void> memcpy(Ptr32<void>,Ptr32<const void>,unsigned,...);
Ptr32<void> memmove(Ptr32<void>,Ptr32<const void>,unsigned);
Ptr32<void> w3d_handle_storage_allocate(unsigned);
void w3d_handle_storage_release(Ptr32<void>);
}
static inline const int &glyph_max(const int &left,const int &right) { return left<right?right:left; }
static inline const unsigned &glyph_min(const unsigned &left,const unsigned &right) { return left>right?right:left; }
struct GlyphVector {
    Ptr32<unsigned short> start; Ptr32<unsigned short> finish; Ptr32<unsigned short> end_of_storage;
    unsigned short &operator[](unsigned i) { return start[i]; }
    unsigned size() const { return finish-start; }
    void erase(Ptr32<unsigned short> first,Ptr32<unsigned short> last)
    {
        int removed=(Ptr32<char>)last-(Ptr32<char>)first;
        memcpy(first,last,(Ptr32<char>)finish-(Ptr32<char>)last);
        finish=(Ptr32<unsigned short>)((Ptr32<char>)finish-removed);
    }
    void clear() { erase(start,finish); }
    void insert(Ptr32<unsigned short> pos,unsigned n,const unsigned short &x)
    {
        int index=pos-start;
        if (pos+n>end_of_storage) {
            unsigned capacity=(Ptr32<char>)end_of_storage-(Ptr32<char>)start;
            unsigned used=(Ptr32<char>)finish-(Ptr32<char>)start;
            int minimum=capacity+(n-(end_of_storage-pos));
            int grown=capacity+(capacity>>1);
            unsigned bytes=glyph_max(minimum,grown)*2;
            Ptr32<unsigned short> replacement=(Ptr32<unsigned short>)w3d_handle_storage_allocate(bytes);
            if (start) {
                memcpy(replacement,start,glyph_min(bytes,used));
                w3d_handle_storage_release(start);
            }
            start=replacement;
            finish=(Ptr32<unsigned short>)((Ptr32<char>)replacement+used);
            end_of_storage=(Ptr32<unsigned short>)((Ptr32<char>)replacement+bytes);
            pos=start+index;
        }
        if (pos==finish) {
            for (unsigned i=0;i<n;i++) finish[i]=x;
            finish+=n;
        } else {
            unsigned short value=x;
            memmove(pos+n,pos,(Ptr32<char>)finish-(Ptr32<char>)pos);
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
