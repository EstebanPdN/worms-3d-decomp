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

inline void *operator new(unsigned int, void *place) throw() { return place; }
extern "C" void *w3d_handle_storage_allocate(unsigned int size);
extern "C" void *w3d_handle_storage_fallback(unsigned int size);
extern "C" void w3d_handle_storage_release(void *p);

struct D17eArrayRecord;
extern "C" unsigned int *w3d_array_read_80240be4(D17eArrayRecord *record, unsigned int *count);
extern "C" int *w3d_array_read_80240cb4(D17eArrayRecord *record, unsigned int *count);

/* Base entry: vtable 0x80410500 (its virtual functions are not recovered). */
struct D17eEntry {
    unsigned short id;
    int value;
    D17eEntry(unsigned short i, int v) : id(i), value(v) {}
    D17eEntry(const D17eEntry &o) : id(o.id), value(o.value) {}
    virtual void unknown_0();
};
struct D17eString;
struct D17eStringHeader { unsigned short references; unsigned short length, capacity; };
extern "C" void * w3d_string_default(D17eString *s);
extern "C" void w3d_string_base_init(D17eString *s);
extern "C" void w3d_string_base_finish(D17eString *s);
extern "C" void w3d_string_release(D17eString *s);
extern "C" unsigned short *w3d_string_header(D17eString *s);
extern "C" void w3d_string_release_header(D17eStringHeader *h);
extern "C" D17eString *w3d_array_read_80240d84(D17eArrayRecord *record, unsigned int *count);
struct D17eString {
    char *data;
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
    D17eStringHeader *header() const { return ((D17eStringHeader *)data) - 1; }
    static void release(D17eStringHeader *h) { if (--h->references == 0) w3d_string_release_header(h); }
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
    D17eString name;
    D17eNamedEntry(unsigned short i, int v, const D17eString &n) : D17eEntry(i, v) { name = n; }
    D17eNamedEntry(const D17eNamedEntry &o) : D17eEntry(o), name(o.name) {}
    virtual void unknown_0();
};
struct D17eFalseType {};
template<class T> inline const T &d17e_max(const T &a, const T &b) { return a < b ? b : a; }
template<class T> inline void d17e_construct(T *p, const T &value) { new (p) T(value); }
template<class T> inline void d17e_destroy(T *p) { p->~T(); }
struct D17eFalse {};
template<class T> inline void d17e_destroy_aux(T *first, T *last, D17eFalse)
{
    for (; first != last; ++first)
        d17e_destroy(first);
}
template<class T, class V> inline void d17e_destroy_value(T *first, T *last, V *)
{
    d17e_destroy_aux(first, last, D17eFalse());
}
template<class T> inline void d17e_destroy_range(T *first, T *last)
{
    d17e_destroy_value(first, last, (T *)0);
}
template<class T> inline T *d17e_uninitialized_copy(T *first, T *last, T *result)
{
    T *cur = result;
    for (; first != last; ++first, ++cur)
        d17e_construct(cur, *first);
    return cur;
}
template<class T> inline T *d17e_uninitialized_fill_n(T *first, unsigned int n, const T &value)
{
    T *cur = first;
    for (; n > 0; --n, ++cur)
        d17e_construct(cur, value);
    return cur;
}
template<class T> struct D17eAllocator {
    static void *allocate_bytes(unsigned int n)
    {
        void *p = w3d_handle_storage_allocate(n);
        if (p == 0)
            p = w3d_handle_storage_fallback(n);
        return p;
    }
    T *allocate(unsigned int n) { return n ? (T *)allocate_bytes(n * sizeof(T)) : 0; }
    void deallocate(T *p, unsigned int) { if (p) w3d_handle_storage_release(p); }
};
template<class T> struct D17eEndOfStorage : D17eAllocator<T> { T *data; };
template<class T> struct D17eVector {
    T *start;
    T *finish;
    D17eEndOfStorage<T> end_of_storage;
    unsigned int size() const { return finish - start; }
    void clear()
    {
        d17e_destroy_range(start, finish);
        end_of_storage.deallocate(start, end_of_storage.data - start);
    }
    void set(T *s, T *f, T *e)
    {
        start = s;
        finish = f;
        end_of_storage.data = e;
    }
    void insert_overflow(T *position, const T &x, const D17eFalseType &, unsigned int fill_len, bool atend)
    {
        const unsigned int old_size = size();
        const unsigned int len = old_size + d17e_max(old_size, fill_len);
        T *new_start = end_of_storage.allocate(len);
        T *new_finish = new_start;
        new_finish = d17e_uninitialized_copy(start, position, new_start);
        if (fill_len == 1) {
            d17e_construct(new_finish, x);
            ++new_finish;
        } else
            new_finish = d17e_uninitialized_fill_n(new_finish, fill_len, x);
        if (!atend)
            new_finish = d17e_uninitialized_copy(position, finish, new_finish);
        clear();
        set(new_start, new_finish, new_start + len);
    }
    void push_back(const T &x)
    {
        if (finish != end_of_storage.data) {
            d17e_construct(finish, x);
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
extern D17eEntryService *lbl_804aaf48;

extern "C" void w3d_d17e_load_entries_8023ee88(D17eArrayRecord *record)
{
    unsigned int count;
    unsigned int *ids = w3d_array_read_80240be4(record, &count);
    int *values = w3d_array_read_80240cb4(record, &count);
    for (unsigned int i = 0; i < count; i++) {
        D17eEntryService *service = lbl_804aaf48;
        service->entries.push_back(D17eEntry(*ids++, *values++));
    }
}

extern "C" void w3d_d17e_load_named_entries_8023f128(D17eArrayRecord *record)
{
    unsigned int count;
    unsigned int *ids = w3d_array_read_80240be4(record, &count);
    int *values = w3d_array_read_80240cb4(record, &count);
    D17eString *names = w3d_array_read_80240d84(record, &count);
    for (unsigned int i = 0; i < count; i++) {
        D17eEntryService *service = lbl_804aaf48;
        service->named_entries.push_back(D17eNamedEntry(*ids++, *values++, *names++));
    }
}
