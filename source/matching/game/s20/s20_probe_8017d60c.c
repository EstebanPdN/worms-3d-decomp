extern void *memset(void *, int, unsigned int);
typedef struct W3dString { char *text; } W3dString;
typedef struct S20Object { void **vtable; } S20Object;
extern void fn_80170b2c(int *);
extern void fn_8017453c(int *);
extern void fn_8017f540(int *);
extern void fn_8018a800(int *);
extern void fn_80187768(int *);
extern void fn_8020c5c0(W3dString *);
extern unsigned short *fn_80341884(W3dString *);
extern void fn_8020c5c4(W3dString *);
extern void fn_80341588(W3dString *);

int w3d_s20_count_categories_8017d60c(char *self) {
    int counts[1920];
    W3dString name;
    unsigned short i;
    memset(counts, 0, sizeof counts);
    i = 0;
    fn_80170b2c(counts);
    fn_8017453c(counts);
    fn_8017f540(counts);
    fn_8018a800(counts);
    fn_80187768(counts);
    do {
        if (counts[i] != 0) {
            S20Object *entry = *(S20Object **)(self + 24 + i * 4);
            char **text = ((char **(*)(S20Object *))entry->vtable[17])(entry);
            unsigned short *references;
            fn_8020c5c0(&name);
            name.text = *text;
            references = fn_80341884(&name);
            *references += 1;
            fn_8020c5c4(&name);
            fn_80341588(&name);
        }
        i++;
    } while (i <= 1919);
    return 0;
}
