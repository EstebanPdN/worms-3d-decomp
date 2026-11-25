typedef unsigned int u32;
typedef struct Obj Obj;
struct Obj { void **v; };
extern void *fn_801e9db8(void *, int);
extern void *fn_801ffea8(void *);
extern int fn_801d6000(void *, const char *, ...);
extern char lbl_803af340[];
extern char lbl_803af394[];

int terra_only_c5_check_801d60cc(void *out, int index, Obj *obj)
{
    u32 count, i, j;
    int ok;
    void *type;
    void *container;
    Obj **items;
    i = 0;
    ok = 1;
    type = ((void *(*)(Obj *))obj->v[5])(obj);
    container = fn_801e9db8(type, index);
    items = ((Obj **(*)(void *, Obj *, u32 *))(*(void ***)((char *)container + 4))[8])(container, obj, &count);
    while (i < count) {
        j = i + 1;
        while (j < count) {
            if (items[j] == items[i]) {
                void *name = **(void ***)container;
                ok = 0;
                type = ((void *(*)(Obj *))obj->v[5])(obj);
                fn_801d6000(out, lbl_803af340, name, fn_801ffea8(type), obj, i, j);
                type = ((void *(*)(Obj *))items[i]->v[5])(items[i]);
                fn_801d6000(out, lbl_803af394, fn_801ffea8(type), items[i]);
            }
            j++;
        }
        i++;
    }
    return ok;
}
