/* Pool layouts and virtual methods inferred solely from observed offsets. */
typedef int (*S9PoolMethod)(void *);
#define FIELD(p,T,o) (*(T *)((char *)(p) + (o)))
extern unsigned short lbl_804b18a4;
extern char *lbl_804b189c;
extern int fn_80185b0c(void *);
extern void fn_80190458(void *, void *);
extern int lbl_804a89d8[];
extern unsigned short lbl_804ab594;
extern unsigned short *lbl_804ab590;
int s9_pool_find_80171be4(int key)
{
    int index;
    for (index = 0; index < lbl_804b18a4; index++) {
        void *item = lbl_804b189c + index * 136;
        if (fn_80185b0c(item)) {
            item = (void *)(index * 136 + (int)lbl_804b189c);
            if (key == FIELD(FIELD(item, void *, 0), S9PoolMethod, 64)(item))
                break;
        }
    }
    return index == lbl_804b18a4 ? -1 : index;
}
int s9_pool_release_80174798(void *owner, void *item)
{
    int category;
    int id;
    fn_80190458(owner,item);
    { int *counts = lbl_804a89d8;
      category = FIELD(FIELD(item, void *, 0), S9PoolMethod, 48)(item);
      counts[category]--; }
    id = FIELD(FIELD(item, void *, 0), S9PoolMethod, 56)(item);
    lbl_804ab590[lbl_804ab594++] = id;
    return 0;
}
