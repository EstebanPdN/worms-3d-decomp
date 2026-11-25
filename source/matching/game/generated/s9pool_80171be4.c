/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pool layouts and virtual methods inferred solely from observed offsets. */
typedef int (*S9PoolMethod)(void *);
#define FIELD(p,T,o) (*(T *)((char *)(p) + (o)))
extern unsigned short lbl_804b18a4;
extern char *lbl_804b189c;
extern int fn_80185b0c(void *);
extern int fn_80190458(void *, void *);
extern int lbl_804a89d8[];
extern unsigned short lbl_804ab594;
extern unsigned short *lbl_804ab590;
extern unsigned short lbl_804ab58c;
extern char *lbl_804ab588;
extern unsigned short lbl_804ab610;
extern char *lbl_804ab60c;
extern unsigned short lbl_804ab644;
extern unsigned short *lbl_804ab640;
extern unsigned short lbl_804ab668;
extern unsigned short *lbl_804ab664;
extern unsigned short lbl_804ab65c;
extern char *lbl_804ab658;
extern unsigned short lbl_804ab690;
extern unsigned short *lbl_804ab68c;
extern unsigned short lbl_804ab684;
extern char *lbl_804ab680;
extern unsigned short lbl_804b18b8;
extern unsigned short *lbl_804b18b4;

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

int s9_pool_find_80174884(int key)
{
    int index;
    for (index = 0; index < lbl_804ab58c; index++) {
        void *item = lbl_804ab588 + index * 172;
        if (fn_80185b0c(item)) {
            item = (void *)(index * 172 + (int)lbl_804ab588);
            if (key == FIELD(FIELD(item, void *, 0), S9PoolMethod, 64)(item))
                break;
        }
    }
    return index == lbl_804ab58c ? -1 : index;
}

int s9_pool_find_8017f8c4(int key)
{
    int index;
    for (index = 0; index < lbl_804ab610; index++) {
        void *item = lbl_804ab60c + index * 204;
        if (fn_80185b0c(item)) {
            item = (void *)(index * 204 + (int)lbl_804ab60c);
            if (key == FIELD(FIELD(item, void *, 0), S9PoolMethod, 64)(item))
                break;
        }
    }
    return index == lbl_804ab610 ? -1 : index;
}

int s9_pool_release_80182b20(void *owner, void *item)
{
    int category;
    int id;
    fn_80190458(owner,item);
    { int *counts = lbl_804a89d8;
      category = FIELD(FIELD(item, void *, 0), S9PoolMethod, 48)(item);
      counts[category]--; }
    id = FIELD(FIELD(item, void *, 0), S9PoolMethod, 56)(item);
    lbl_804ab640[lbl_804ab644++] = id;
    return 0;
}

int s9_pool_release_80184ae8(void *owner, void *item)
{
    int category;
    int id;
    fn_80190458(owner,item);
    { int *counts = lbl_804a89d8;
      category = FIELD(FIELD(item, void *, 0), S9PoolMethod, 48)(item);
      counts[category]--; }
    id = FIELD(FIELD(item, void *, 0), S9PoolMethod, 56)(item);
    lbl_804ab664[lbl_804ab668++] = id;
    return 0;
}

int s9_pool_find_80184d68(int key)
{
    int index;
    for (index = 0; index < lbl_804ab65c; index++) {
        void *item = lbl_804ab658 + index * 172;
        if (fn_80185b0c(item)) {
            item = (void *)(index * 172 + (int)lbl_804ab658);
            if (key == FIELD(FIELD(item, void *, 0), S9PoolMethod, 64)(item))
                break;
        }
    }
    return index == lbl_804ab65c ? -1 : index;
}

int s9_pool_release_80188440(void *owner, void *item)
{
    int category;
    int id;
    fn_80190458(owner,item);
    { int *counts = lbl_804a89d8;
      category = FIELD(FIELD(item, void *, 0), S9PoolMethod, 48)(item);
      counts[category]--; }
    id = FIELD(FIELD(item, void *, 0), S9PoolMethod, 56)(item);
    lbl_804ab68c[lbl_804ab690++] = id;
    return 0;
}

int s9_pool_find_801886c0(int key)
{
    int index;
    for (index = 0; index < lbl_804ab684; index++) {
        void *item = lbl_804ab680 + index * 172;
        if (fn_80185b0c(item)) {
            item = (void *)(index * 172 + (int)lbl_804ab680);
            if (key == FIELD(FIELD(item, void *, 0), S9PoolMethod, 64)(item))
                break;
        }
    }
    return index == lbl_804ab684 ? -1 : index;
}

int s9_pool_release_8018b0ac(void *owner, void *item)
{
    int category;
    int id;
    fn_80190458(owner,item);
    { int *counts = lbl_804a89d8;
      category = FIELD(FIELD(item, void *, 0), S9PoolMethod, 48)(item);
      counts[category]--; }
    id = FIELD(FIELD(item, void *, 0), S9PoolMethod, 56)(item);
    lbl_804b18b4[lbl_804b18b8++] = id;
    return 0;
}
