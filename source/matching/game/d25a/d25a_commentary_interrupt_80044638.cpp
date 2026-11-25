/* Commentary interrupt (0x80044638): erases every queued string of the vector
 * at +72, plays the given string (0x80043134) and advances the commentary
 * (0x800438d4). The queue's stride shows the string object is one word; the
 * parameter is by value and destroyed here. Erasing the whole range is the
 * standard vector erase: copy the tail down, destroy what is left, move the end.
 * The tail is empty, so the copy loop folds away; its distance goes through a
 * reference, which keeps the entry test until after global CSE and leaves the
 * loop notes that fix the scheduling of the first loads in the original. Field
 * and type names are inferred from the original instructions; the unit owns no
 * data. */
struct String;
extern "C" void w3d_string_init_8020c5c0(String *);
extern "C" unsigned short *w3d_string_header_80341884(String *);
extern "C" void w3d_string_finish_8020c5c4(String *);
extern "C" void w3d_string_release_80341588(String *);
struct String {
    const char *text;
    String(const String &o) {
        w3d_string_init_8020c5c0(this);
        text = o.text;
        ++*w3d_string_header_80341884(this);
    }
    String &operator=(const String &o);
    ~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }
};

inline void Distance(String *first, String *last, int &n)
{
    n += last - first;
}

inline String *CopyRange(String *first, String *last, String *result)
{
    int n = 0;
    Distance(first, last, n);
    for (; n > 0; --n) {
        *result = *first;
        ++first;
        ++result;
    }
    return result;
}

struct FalseType {};

inline void DestroyAux(String *first, String *last, const FalseType &)
{
    for (; first != last; ++first) first->~String();
}

inline void DestroyValue(String *first, String *last, String *)
{
    DestroyAux(first, last, FalseType());
}

inline void DestroyRange(String *first, String *last)
{
    DestroyValue(first, last, first);
}

struct StringVector {
    String *first, *last;
    String *erase(String *from, String *to)
    {
        String *end = CopyRange(to, last, from);
        DestroyRange(end, last);
        last = end;
        return from;
    }
    void clear() { erase(first, last); }
};

struct Commentary {
    char unknown00[72];
    StringVector queue;        /* +72 */
};
extern "C" void w3d_commentary_play_80043134(Commentary *, String, int);
extern "C" void w3d_commentary_advance_800438d4(Commentary *, int);

extern "C" void w3d_d25a_commentary_interrupt_80044638(Commentary *self, String text)
{
    self->queue.clear();
    w3d_commentary_play_80043134(self, text, 0);
    w3d_commentary_advance_800438d4(self, 0);
}
