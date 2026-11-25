#include "w3d_ptr.h"
#line 1 "h1_stlport_vector_owners.cpp"
/* Destructors of small STLport vector owners (session b169b320): a
 * four-table record, a row table whose rows own a vector each, and a holder
 * that deletes its two owned lists. STLport's ~vector destroys the
 * elements (no loop for trivial types) and frees the storage when present;
 * memory goes back to the game heap. */

extern "C" void w3d_handle_storage_release(Ptr32<void> p);
extern "C" void w3d_actor_member_delete_backend(Ptr32<void> p);

/* STLport vector<T> for trivially destructible T: { start, finish, end_of_storage }. */
template <class T> inline void w3d_destroy(T *first, T *last)
{
    for (; first != last; ++first)
        first->~T();
}
template <class T> struct W3dVector
{
    Ptr32<T> start;
    Ptr32<T> finish;
    Ptr32<T> end_of_storage;
    ~W3dVector()
    {
        Ptr32<T> last = finish;
        w3d_destroy(w3d::R(start), w3d::R(last));
        if (start)
            w3d_handle_storage_release(start);
    }
};
/* Trivial element types: the destroy loop disappears. */
template <> inline W3dVector<int>::~W3dVector()
{
    if (start)
        w3d_handle_storage_release(start);
}

struct W3dVec4Tables
{
    int unknown_00;
    W3dVector<int> first;      /* 0x04 */
    int unknown_10;
    W3dVector<int> second;     /* 0x14 */
    int unknown_20;
    W3dVector<int> third;      /* 0x24 */
    int unknown_30;
    W3dVector<int> fourth;     /* 0x34 */
};

struct W3dRow
{
    W3dVector<int> cells;
    int unknown_0c;
};
struct W3dRowTable
{
    W3dVector<W3dRow> rows;    /* 0x00 */
    int unknown_0c;
    W3dVector<int> extra;      /* 0x10 */
};
struct W3dPairEntry
{
    int a;
    int b;
    ~W3dPairEntry() {}
};
struct W3dIntList
{
    W3dVector<int> items;
};
struct W3dPairList
{
    W3dVector<W3dPairEntry> items;
};
struct W3dListHolder
{
    Ptr32<W3dPairList> pairs;        /* 0x00 */
    Ptr32<W3dIntList> ints;          /* 0x04 */
};
inline void operator delete(void *p) { w3d_actor_member_delete_backend(p); }
extern "C" void w3d_vec4_tables_destroy_8035a244(Ptr32<W3dVec4Tables> self, int flags)
{
    self->fourth.~W3dVector<int>();
    self->third.~W3dVector<int>();
    self->second.~W3dVector<int>();
    self->first.~W3dVector<int>();
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}

extern "C" void w3d_row_table_destroy_8034be70(Ptr32<W3dRowTable> self, int flags)
{
    self->extra.~W3dVector<int>();
    self->rows.~W3dVector<W3dRow>();
    if (flags & 1)
        w3d_actor_member_delete_backend(self);
}

extern "C" void w3d_list_holder_clear_8034aef4(Ptr32<W3dListHolder> self)
{
    delete self->ints;
    self->ints = 0;
    delete self->pairs;
    self->pairs = 0;
}


