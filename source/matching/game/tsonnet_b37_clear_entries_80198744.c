/* Clears a table of 80 sixteen-byte entries (key, object pointer, word, flags).
   For an entry that holds an object, two virtual calls on it (slots 9 and 10,
   both taking the entry key) are made and the first result plus 8 is handed,
   with the second result, to a record-clearing helper. Every entry is then
   reset: key, object and word to zero, and the top two flag bits cleared.
   Offsets are observed; field names and meanings are inferred. The trailing
   `e++; e--;` has no effect and is a matching device (it keeps the entry
   pointer live past the loop as the original's register use shows), not
   recovered source. */
typedef struct B37Obj { void **vtable; } B37Obj;
typedef struct B37Entry { unsigned int key; B37Obj *obj; int word8; unsigned int word12; } B37Entry;
extern void fn_80197f98(void *records, void *arg);
void tsonnet_b37_clear_entries_80198744(B37Entry *e)
{
    int zero = 0;
    B37Entry *last = e + 79;
    do {
        B37Obj *obj = e->obj;
        if (obj) {
            char *r = ((char *(*)(B37Obj *, unsigned int))obj->vtable[9])(obj, e->key);
            void *s = ((void *(*)(B37Obj *, unsigned int))e->obj->vtable[10])(e->obj, e->key);
            fn_80197f98(r + 8, s);
        }
        e->key = zero;
        e->obj = (B37Obj *)zero;
        e->word12 &= 0x3fffffff;
        e->word8 = zero;
        e++;
    } while (e <= last);
    e++;
    e--;
}
