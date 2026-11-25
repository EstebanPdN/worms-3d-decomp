// desc: Appears to scan a global list of registered objects for one whose 16-byte identifier equals the given one and return its packed field.
struct S21Item { char pad[32]; unsigned packed; };
struct S21ItemList { struct S21Item **begin; struct S21Item **end; };
extern struct S21ItemList lbl_8045e080[];
extern const void *fn_801fff3c(struct S21Item *);
extern int fn_802eedc0(const void *, const void *, int);
int w3d_s21_find_item_class_801e8f64(const void *id, unsigned *out)
{
    struct S21Item **item = lbl_8045e080[0].begin;
    struct S21Item **end = lbl_8045e080[0].end;
    for (; item != end; item++) {
        if (*item && fn_802eedc0(fn_801fff3c(*item), id, 16) == 0) {
            *out = (*item)->packed >> 22;
            return 0;
        }
    }
    return 0x80004005;
}
