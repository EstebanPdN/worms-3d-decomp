/* Observed: a global STLport-style byte vector (start, finish, end of storage) at 0x8045ce40. */
struct Cc17cByteVector { unsigned char *start; unsigned char *finish; unsigned char *end_of_storage; };
extern Cc17cByteVector lbl_8045ce40;
/* Observed: the virtual slot at +20 returns a record whose word at +32 holds a 10-bit index in its top bits. */
struct Cc17cStateRecord { char pad0[32]; unsigned int packed; };
struct Cc17cStateItem { void **vtable; char pad4[17]; unsigned char state; };
typedef Cc17cStateRecord *(*Cc17cRecordGetter)(Cc17cStateItem *);
/* Observed: the owner keeps a vector of item pointers at +20/+24. */
struct Cc17cStateOwner { char pad0[20]; Cc17cStateItem **items; Cc17cStateItem **items_end; };
static inline void cc17c_fill(unsigned char *first, unsigned char *last, const int &value)
{
    for (; first != last; ++first) *first = value;
}
extern "C" void w3d_cc17c_state_table_refresh_801a2360(Cc17cStateOwner *self)
{
    unsigned char *start = lbl_8045ce40.start;
    unsigned char *finish = lbl_8045ce40.finish;
    unsigned int size = finish - start;
    cc17c_fill(start, finish, 0);
    Cc17cStateItem **it = self->items;
    Cc17cStateItem **end = self->items_end;
    for (; it != end; ++it) {
        if (*it) {
            unsigned int index = ((Cc17cRecordGetter)(*it)->vtable[5])(*it)->packed >> 22;
            if (index < size) lbl_8045ce40.start[index] = (*it)->state;
        }
    }
}
