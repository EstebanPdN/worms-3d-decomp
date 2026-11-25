// desc: Appears to initialize a lookup iterator over one row of a global table of 12-byte rows, advancing to the first entry whose 16-byte identifier equals the key, and return the iterator.
struct S21Entry { char pad[12]; const void *id; };
struct S21Row { struct S21Entry **begin; struct S21Entry **end; int pad; };
struct S21Iterator { struct S21Entry **current; struct S21Entry **end; const void *key; int row; };
extern struct S21Row lbl_8045e890[];
extern int fn_802eedc0(const void *, const void *, int);
struct S21Iterator *w3d_s21_find_begin_801fca00(struct S21Iterator *it, int row, const void *key)
{
    it->key = key;
    it->current = lbl_8045e890[row].begin;
    it->row = row;
    it->end = lbl_8045e890[row].end;
    for (; it->current != it->end; it->current++) {
        if (fn_802eedc0((*it->current)->id, it->key, 16) == 0)
            break;
    }
    return it;
}
