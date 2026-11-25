#include "w3d_ptr.h"
#line 1 "d17e_record_vector_append_8023f510.cpp"
/* Originals 0x8023f510, 0x8023fb48, 0x8023f808, 0x8023fe40: four loaders that
 * read parallel arrays from a record (id array through 0x80240be4, value
 * array through 0x80240cb4 and one or two extra arrays through further
 * readers; every reader also reports the shared element count) and append one
 * sixteen- or twenty-byte polymorphic entry per index to a vector held in the
 * service object reached through small-data pointer 0x804aaf48 (vectors at
 * +44, +92, +76 and +108).
 *
 * Each entry has a base part (halfword id at +0, word value at +4, vtable
 * pointer at +8, base vtable 0x80410500) and a derived part with the extra
 * fields from +12; the derived vtables are 0x804104f0, 0x804104c0, 0x804104d0
 * and 0x804104b0. The ids are read as words and narrowed to their low
 * halfword. The append is an STLport-shaped vector push_back whose overflow
 * path is inlined: grow to size + max(size, 1), copy-construct the old
 * entries, construct the new one, run the (empty) destructor loop over the
 * old range, release the old block and store start, finish and capacity.
 * The allocator tries 0x80212fd4 and falls back to 0x803413d8.
 *
 * Class, field and container names are inferred; the vtables, the service
 * object and the arrays stay external and unowned.
 */

inline void *operator new(__SIZE_TYPE__, void *place) throw() { return place; }
extern "C" Ptr32<void> w3d_handle_storage_allocate(unsigned int size);
extern "C" Ptr32<void> w3d_handle_storage_fallback(unsigned int size);
extern "C" void w3d_handle_storage_release(Ptr32<void> p);

struct D17eArrayRecord;
extern "C" Ptr32<unsigned int> w3d_array_read_80240be4(Ptr32<D17eArrayRecord> record, Ptr32<unsigned int> count);
extern "C" Ptr32<int> w3d_array_read_80240cb4(Ptr32<D17eArrayRecord> record, Ptr32<unsigned int> count);
extern "C" Ptr32<int> w3d_array_read_80240e54(Ptr32<D17eArrayRecord> record, Ptr32<unsigned int> count);
extern "C" Ptr32<float> w3d_array_read_802410c4(Ptr32<D17eArrayRecord> record, Ptr32<unsigned int> count);
extern "C" Ptr32<int> w3d_array_read_80240f24(Ptr32<D17eArrayRecord> record, Ptr32<unsigned int> count);
extern "C" Ptr32<int> w3d_array_read_80240ff4(Ptr32<D17eArrayRecord> record, Ptr32<unsigned int> count);
extern "C" Ptr32<float> w3d_array_read_80241194(Ptr32<D17eArrayRecord> record, Ptr32<unsigned int> count);
extern "C" Ptr32<float> w3d_array_read_80241264(Ptr32<D17eArrayRecord> record, Ptr32<unsigned int> count);

/* Base entry: vtable 0x80410500 (its virtual functions are not recovered). */
struct D17eEntry {
    unsigned short id;
    int value;
    D17eEntry(unsigned short i, int v) : id(i), value(v) { W3D_SET_VPTR(this->w3d_vptr_D17eEntry, w3d_vt___vt_9D17eEntry, "__vt_9D17eEntry"); }
    D17eEntry(const D17eEntry &o) : id(o.id), value(o.value) { W3D_SET_VPTR(this->w3d_vptr_D17eEntry, w3d_vt___vt_9D17eEntry, "__vt_9D17eEntry"); }
    void w3d_r_unknown_0() __asm__(W3D_SYM("_ZN9D17eEntry9unknown_0Ev"));
 __attribute__((always_inline)) inline void unknown_0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D17eEntry, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D17eEntry; };
/* vtable 0x804104f0 */
struct D17eIntEntry : D17eEntry {
    int extra __attribute__((aligned(__alignof__(D17eEntry))));
    D17eIntEntry(unsigned short i, int v, int e) : D17eEntry(i, v), extra(e) { W3D_SET_VPTR(this->D17eEntry::w3d_vptr_D17eEntry, w3d_vt___vt_12D17eIntEntry, "__vt_12D17eIntEntry"); }
    D17eIntEntry(const D17eIntEntry &o) : D17eEntry(o), extra(o.extra) { W3D_SET_VPTR(this->D17eEntry::w3d_vptr_D17eEntry, w3d_vt___vt_12D17eIntEntry, "__vt_12D17eIntEntry"); }
    void w3d_r_unknown_0() __asm__(W3D_SYM("_ZN12D17eIntEntry9unknown_0Ev"));
 __attribute__((always_inline)) inline void unknown_0() { this->D17eEntry::unknown_0(); } };
/* vtable 0x804104c0 */
struct D17eFloatEntry : D17eEntry {
    float extra __attribute__((aligned(__alignof__(D17eEntry))));
    D17eFloatEntry(unsigned short i, int v, float e) : D17eEntry(i, v), extra(e) { W3D_SET_VPTR(this->D17eEntry::w3d_vptr_D17eEntry, w3d_vt___vt_14D17eFloatEntry, "__vt_14D17eFloatEntry"); }
    D17eFloatEntry(const D17eFloatEntry &o) : D17eEntry(o), extra(o.extra) { W3D_SET_VPTR(this->D17eEntry::w3d_vptr_D17eEntry, w3d_vt___vt_14D17eFloatEntry, "__vt_14D17eFloatEntry"); }
    void w3d_r_unknown_0() __asm__(W3D_SYM("_ZN14D17eFloatEntry9unknown_0Ev"));
 __attribute__((always_inline)) inline void unknown_0() { this->D17eEntry::unknown_0(); } };
/* vtable 0x804104d0 */
struct D17eIntPairEntry : D17eEntry {
    int first __attribute__((aligned(__alignof__(D17eEntry))));
    int second;
    D17eIntPairEntry(unsigned short i, int v, int a, int b) : D17eEntry(i, v), first(a), second(b) { W3D_SET_VPTR(this->D17eEntry::w3d_vptr_D17eEntry, w3d_vt___vt_16D17eIntPairEntry, "__vt_16D17eIntPairEntry"); }
    D17eIntPairEntry(const D17eIntPairEntry &o) : D17eEntry(o), first(o.first), second(o.second) { W3D_SET_VPTR(this->D17eEntry::w3d_vptr_D17eEntry, w3d_vt___vt_16D17eIntPairEntry, "__vt_16D17eIntPairEntry"); }
    void w3d_r_unknown_0() __asm__(W3D_SYM("_ZN16D17eIntPairEntry9unknown_0Ev"));
 __attribute__((always_inline)) inline void unknown_0() { this->D17eEntry::unknown_0(); } };
/* vtable 0x804104b0 */
struct D17eFloatPairEntry : D17eEntry {
    float first __attribute__((aligned(__alignof__(D17eEntry))));
    float second;
    D17eFloatPairEntry(unsigned short i, int v, float a, float b) : D17eEntry(i, v), first(a), second(b) { W3D_SET_VPTR(this->D17eEntry::w3d_vptr_D17eEntry, w3d_vt___vt_18D17eFloatPairEntry, "__vt_18D17eFloatPairEntry"); }
    D17eFloatPairEntry(const D17eFloatPairEntry &o) : D17eEntry(o), first(o.first), second(o.second) { W3D_SET_VPTR(this->D17eEntry::w3d_vptr_D17eEntry, w3d_vt___vt_18D17eFloatPairEntry, "__vt_18D17eFloatPairEntry"); }
    void w3d_r_unknown_0() __asm__(W3D_SYM("_ZN18D17eFloatPairEntry9unknown_0Ev"));
 __attribute__((always_inline)) inline void unknown_0() { this->D17eEntry::unknown_0(); } };

struct D17eFalseType { char w3d_empty; };
template<class T> inline const T &d17e_max(const T &a, const T &b) { return a < b ? b : a; }
template<class T> inline void d17e_construct(T *p, const T &value) { new (p) T(value); }
template<class T> inline void d17e_destroy(T *p) { p->~T(); }
template<class T> inline void d17e_destroy_range(T *first, T *last)
{
    for (; first != last; ++first)
        d17e_destroy(w3d::R(first));
}
template<class T> inline Ptr32<T> d17e_uninitialized_copy(T *first, T *last, T *result)
{
    Ptr32<T> cur = result;
    for (; first != last; ++first, ++cur)
        d17e_construct(w3d::R(cur), *first);
    return cur;
}
template<class T> inline Ptr32<T> d17e_uninitialized_fill_n(T *first, unsigned int n, const T &value)
{
    Ptr32<T> cur = first;
    for (; n > 0; --n, ++cur)
        d17e_construct(w3d::R(cur), value);
    return cur;
}
template<class T> struct D17eAllocator {
    static Ptr32<void> allocate_bytes(unsigned int n)
    {
        Ptr32<void> p = w3d_handle_storage_allocate(n);
        if (p == 0)
            p = w3d_handle_storage_fallback(n);
        return p;
    }
    Ptr32<T> allocate(unsigned int n) { return n ? (Ptr32<T>)allocate_bytes(n * sizeof(T)) : 0; }
    void deallocate(Ptr32<T> p, unsigned int) { if (p) w3d_handle_storage_release(p); }
 char w3d_empty; };
template<class T> struct D17eEndOfStorage : D17eAllocator<T> { Ptr32<T> data __attribute__((aligned(__alignof__(D17eAllocator<T>)))); };
template<class T> struct D17eVector {
    Ptr32<T> start;
    Ptr32<T> finish;
    D17eEndOfStorage<T> end_of_storage;
    unsigned int size() const { return finish - start; }
    void clear()
    {
        d17e_destroy_range(w3d::R(start), w3d::R(finish));
        end_of_storage.deallocate(start, end_of_storage.data - start);
    }
    void set(Ptr32<T> s, Ptr32<T> f, Ptr32<T> e)
    {
        start = s;
        finish = f;
        end_of_storage.data = e;
    }
    void insert_overflow(Ptr32<T> position, const T &x, const D17eFalseType &, unsigned int fill_len, bool atend)
    {
        const unsigned int old_size = size();
        const unsigned int len = old_size + d17e_max(old_size, fill_len);
        Ptr32<T> new_start = end_of_storage.allocate(len);
        Ptr32<T> new_finish = new_start;
        new_finish = d17e_uninitialized_copy(w3d::R(start), w3d::R(position), w3d::R(new_start));
        if (fill_len == 1) {
            d17e_construct(w3d::R(new_finish), x);
            ++new_finish;
        } else
            new_finish = d17e_uninitialized_fill_n(w3d::R(new_finish), fill_len, x);
        if (!atend)
            new_finish = d17e_uninitialized_copy(w3d::R(position), w3d::R(finish), w3d::R(new_finish));
        clear();
        set(new_start, new_finish, new_start + len);
    }
    void push_back(const T &x)
    {
        if (finish != end_of_storage.data) {
            d17e_construct(w3d::R(finish), x);
            ++finish;
        } else
            insert_overflow(finish, x, D17eFalseType(), 1, true);
    }
};

struct D17eEntryService {
    char unknown_00[44];
    D17eVector<D17eIntEntry> int_entries;              /* +44 */
    char unknown_60[16];                               /* not used here */
    D17eVector<D17eIntPairEntry> int_pair_entries;     /* +76 */
    D17eVector<D17eFloatEntry> float_entries;          /* +92 */
    D17eVector<D17eFloatPairEntry> float_pair_entries; /* +108 */
};
extern Ptr32<D17eEntryService> lbl_804aaf48;

extern "C" void w3d_d17e_load_int_entries_8023f510(Ptr32<D17eArrayRecord> record)
{
    unsigned int count;
    Ptr32<unsigned int> ids = w3d_array_read_80240be4(record, &count);
    Ptr32<int> values = w3d_array_read_80240cb4(record, &count);
    Ptr32<int> extras = w3d_array_read_80240e54(record, &count);
    for (unsigned int i = 0; i < count; i++)
        lbl_804aaf48->int_entries.push_back(D17eIntEntry(*ids++, *values++, *extras++));
}

extern "C" void w3d_d17e_load_float_entries_8023fb48(Ptr32<D17eArrayRecord> record)
{
    unsigned int count;
    Ptr32<unsigned int> ids = w3d_array_read_80240be4(record, &count);
    Ptr32<int> values = w3d_array_read_80240cb4(record, &count);
    Ptr32<float> extras = w3d_array_read_802410c4(record, &count);
    for (unsigned int i = 0; i < count; i++)
        lbl_804aaf48->float_entries.push_back(D17eFloatEntry(*ids++, *values++, *extras++));
}

extern "C" void w3d_d17e_load_int_pair_entries_8023f808(Ptr32<D17eArrayRecord> record)
{
    unsigned int count;
    Ptr32<unsigned int> ids = w3d_array_read_80240be4(record, &count);
    Ptr32<int> values = w3d_array_read_80240cb4(record, &count);
    Ptr32<int> firsts = w3d_array_read_80240f24(record, &count);
    Ptr32<int> seconds = w3d_array_read_80240ff4(record, &count);
    for (unsigned int i = 0; i < count; i++)
        lbl_804aaf48->int_pair_entries.push_back(D17eIntPairEntry(*ids++, *values++, *firsts++, *seconds++));
}

extern "C" void w3d_d17e_load_float_pair_entries_8023fe40(Ptr32<D17eArrayRecord> record)
{
    unsigned int count;
    Ptr32<unsigned int> ids = w3d_array_read_80240be4(record, &count);
    Ptr32<int> values = w3d_array_read_80240cb4(record, &count);
    Ptr32<float> firsts = w3d_array_read_80241194(record, &count);
    Ptr32<float> seconds = w3d_array_read_80241264(record, &count);
    for (unsigned int i = 0; i < count; i++)
        lbl_804aaf48->float_pair_entries.push_back(D17eFloatPairEntry(*ids++, *values++, *firsts++, *seconds++));
}


