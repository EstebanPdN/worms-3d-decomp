#include "w3d_ptr.h"
#line 1 "d17e_record_vector_append_8023ee88.cpp"
/* Originals 0x8023ee88 and 0x8023f128: two more loaders of the 0x8023f510
 * family (unit d17e_record_vector_append_8023f510). They read the record's id
 * and value arrays (0x80240be4, 0x80240cb4; each reader also reports the
 * shared element count) and append per index either a twelve-byte base entry
 * (vtable 0x80410500) to the vector at +28, or, with a third array of shared
 * strings read through 0x80240d84, a sixteen-byte named entry (vtable
 * 0x804104e0, string at +12) to the vector at +60 of the service object
 * reached through small-data pointer 0x804aaf48.
 *
 * The named entry assigns the string after default-constructing it
 * (0x803426b8), so the reference count of the source header (six bytes before
 * the text) is raised and the old header released through 0x8020bb2c when
 * its count reaches zero. Copies run the string base constructor 0x8020c5c0
 * and raise the count through 0x80341884; destruction calls 0x8020c5c4 and
 * 0x80341588. The append is the STLport-shaped push_back with inlined
 * overflow path; destroying the old range goes through STLport's
 * _Destroy/__destroy/__destroy_aux layering, which fixes the order in which
 * the range bounds are loaded. The service pointer is read at the top of each
 * iteration, before the temporary entry is built.
 *
 * Class, field and container names are inferred; vtables, strings, the
 * service object and the arrays stay external and unowned.
 */

inline void *operator new(__SIZE_TYPE__, void *place) throw() { return place; }
extern "C" Ptr32<void> w3d_handle_storage_allocate(unsigned int size);
extern "C" Ptr32<void> w3d_handle_storage_fallback(unsigned int size);
extern "C" void w3d_handle_storage_release(Ptr32<void> p);

struct D17eArrayRecord;
extern "C" Ptr32<unsigned int> w3d_array_read_80240be4(Ptr32<D17eArrayRecord> record, Ptr32<unsigned int> count);
extern "C" Ptr32<int> w3d_array_read_80240cb4(Ptr32<D17eArrayRecord> record, Ptr32<unsigned int> count);

/* Base entry: vtable 0x80410500 (its virtual functions are not recovered). */
struct D17eEntry {
    unsigned short id;
    int value;
    D17eEntry(unsigned short i, int v) : id(i), value(v) { W3D_SET_VPTR(this->w3d_vptr_D17eEntry, w3d_vt___vt_9D17eEntry, "__vt_9D17eEntry"); }
    D17eEntry(const D17eEntry &o) : id(o.id), value(o.value) { W3D_SET_VPTR(this->w3d_vptr_D17eEntry, w3d_vt___vt_9D17eEntry, "__vt_9D17eEntry"); }
    void w3d_r_unknown_0() __asm__(W3D_SYM("_ZN9D17eEntry9unknown_0Ev"));
 __attribute__((always_inline)) inline void unknown_0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D17eEntry, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D17eEntry; };
struct D17eString;
struct D17eStringHeader { unsigned short references; unsigned short length, capacity; };
extern "C" Ptr32<void> w3d_string_default(Ptr32<D17eString> s);
extern "C" void w3d_string_base_init(Ptr32<D17eString> s);
extern "C" void w3d_string_base_finish(Ptr32<D17eString> s);
extern "C" void w3d_string_release(Ptr32<D17eString> s);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<D17eString> s);
extern "C" void w3d_string_release_header(Ptr32<D17eStringHeader> h);
extern "C" Ptr32<D17eString> w3d_array_read_80240d84(Ptr32<D17eArrayRecord> record, Ptr32<unsigned int> count);
struct D17eString {
    Ptr32<char> data;
    D17eString() { w3d_string_default(this); }
    D17eString(const D17eString &x)
    {
        w3d_string_base_init(this);
        data = x.data;
        ++*w3d_string_header(this);
    }
    ~D17eString()
    {
        w3d_string_base_finish(this);
        w3d_string_release(this);
    }
    Ptr32<D17eStringHeader> header() const { return ((Ptr32<D17eStringHeader>)data) - 1; }
    static void release(Ptr32<D17eStringHeader> h) { if (--h->references == 0) w3d_string_release_header(h); }
    D17eString &operator=(const D17eString &x)
    {
        ++x.header()->references;
        release(header());
        data = x.data;
        return *this;
    }
};
/* vtable 0x804104e0 */
struct D17eNamedEntry : D17eEntry {
    D17eString name __attribute__((aligned(__alignof__(D17eEntry))));
    D17eNamedEntry(unsigned short i, int v, const D17eString &n) : D17eEntry(i, v) { W3D_SET_VPTR(this->D17eEntry::w3d_vptr_D17eEntry, w3d_vt___vt_14D17eNamedEntry, "__vt_14D17eNamedEntry");  name = n; }
    D17eNamedEntry(const D17eNamedEntry &o) : D17eEntry(o), name(o.name) { W3D_SET_VPTR(this->D17eEntry::w3d_vptr_D17eEntry, w3d_vt___vt_14D17eNamedEntry, "__vt_14D17eNamedEntry"); }
    void w3d_r_unknown_0() __asm__(W3D_SYM("_ZN14D17eNamedEntry9unknown_0Ev"));
 __attribute__((always_inline)) inline void unknown_0() { this->D17eEntry::unknown_0(); } };
struct D17eFalseType { char w3d_empty; };
template<class T> inline const T &d17e_max(const T &a, const T &b) { return a < b ? b : a; }
template<class T> inline void d17e_construct(T *p, const T &value) { new (p) T(value); }
template<class T> inline void d17e_destroy(T *p) { p->~T(); }
struct D17eFalse { char w3d_empty; };
template<class T> inline void d17e_destroy_aux(T *first, T *last, D17eFalse)
{
    for (; first != last; ++first)
        d17e_destroy(w3d::R(first));
}
template<class T, class V> inline void d17e_destroy_value(T *first, T *last, V *)
{
    d17e_destroy_aux(w3d::R(first), w3d::R(last), D17eFalse());
}
template<class T> inline void d17e_destroy_range(T *first, T *last)
{
    d17e_destroy_value(w3d::R(first), w3d::R(last), w3d::R((Ptr32<T>)0));
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
    char unknown_00[28];
    D17eVector<D17eEntry> entries;            /* +28 */
    char unknown_40[16];
    D17eVector<D17eNamedEntry> named_entries; /* +60 */
};
extern Ptr32<D17eEntryService> lbl_804aaf48;

extern "C" void w3d_d17e_load_entries_8023ee88(Ptr32<D17eArrayRecord> record)
{
    unsigned int count;
    Ptr32<unsigned int> ids = w3d_array_read_80240be4(record, &count);
    Ptr32<int> values = w3d_array_read_80240cb4(record, &count);
    for (unsigned int i = 0; i < count; i++) {
        Ptr32<D17eEntryService> service = lbl_804aaf48;
        service->entries.push_back(D17eEntry(*ids++, *values++));
    }
}

extern "C" void w3d_d17e_load_named_entries_8023f128(Ptr32<D17eArrayRecord> record)
{
    unsigned int count;
    Ptr32<unsigned int> ids = w3d_array_read_80240be4(record, &count);
    Ptr32<int> values = w3d_array_read_80240cb4(record, &count);
    Ptr32<D17eString> names = w3d_array_read_80240d84(record, &count);
    for (unsigned int i = 0; i < count; i++) {
        Ptr32<D17eEntryService> service = lbl_804aaf48;
        service->named_entries.push_back(D17eNamedEntry(*ids++, *values++, *names++));
    }
}


