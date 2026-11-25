/* GWMP8P rev0 0x8017d60c: per-category pool census.
   Zeroes 1920 category counters, lets five pool counters fill them
   (0x80170b2c, 0x8017453c, 0x8017f540, 0x8018a800, 0x80187768), then for
   every non-empty category copies the name string returned by the
   category object's slot 17 (+68) into a temporary that is destroyed at
   once (its use was compiled out). The string copy follows the admitted
   reference-counted string shape (0x8020c5c0, ++*0x80341884, destructor
   0x8020c5c4 then 0x80341588). Category table at +24 is a partial view;
   names are inferred. */
extern "C" {
void *memset(void *,int,unsigned);
void fn_80170b2c(int *);
void fn_8017453c(int *);
void fn_8017f540(int *);
void fn_8018a800(int *);
void fn_80187768(int *);
void fn_8020c5c0(void *);
void fn_8020c5c4(void *);
void fn_80341588(void *);
unsigned short *fn_80341884(void *);
}
struct D22dString {
    char *text;
    D22dString(const D22dString &other) { fn_8020c5c0(this); text=other.text; ++*fn_80341884(this); }
    ~D22dString() { fn_8020c5c4(this); fn_80341588(this); }
};
struct D22dCategory;
struct D22dCategoryTable { void *slots[17]; const D22dString &(*name)(D22dCategory *); };
struct D22dCategory { D22dCategoryTable *vtable; };
struct D22dPools { unsigned char pad[24]; D22dCategory *categories[1920]; };
extern "C" int w3d_d22d_count_categories_8017d60c(D22dPools *self)
{
    int counts[1920];
    unsigned short i;
    memset(counts,0,sizeof counts);
    fn_80170b2c(counts);
    fn_8017453c(counts);
    fn_8017f540(counts);
    fn_8018a800(counts);
    fn_80187768(counts);
    i=0;
    do {
        if (counts[i]) {
            D22dCategory *category=*(self->categories+i);
            D22dString name(category->vtable->name(category));
        }
        i++;
    } while (i<=1919);
    return 0;
}
