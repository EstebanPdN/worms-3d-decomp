typedef float lua_Number;
typedef struct K6bTObject {
    int tt;
    union { void *p; lua_Number n; int b; } value;
} K6bTObject;
typedef struct K6bNode {
    K6bTObject i_key;
    K6bTObject i_val;
    struct K6bNode *next;
} K6bNode;
typedef struct K6bTable {
    void *next;
    unsigned char tt;
    unsigned char marked;
    unsigned char flags;
    unsigned char lsizenode;
    struct K6bTable *metatable;
    K6bTObject *array;
    K6bNode *node;
    K6bNode *firstfree;
    void *gclist;
    int sizearray;
} K6bTable;
typedef struct K6bCallInfo {
    K6bTObject *base;
} K6bCallInfo;
typedef struct lua_State {
    void *next;
    unsigned char tt;
    unsigned char marked;
    K6bTObject *top;
    K6bTObject *base;
    void *l_G;
    K6bCallInfo *ci;
} lua_State;
extern void __assert(const char *file, int line, const char *expression);
extern K6bTObject *negindex(lua_State *L, int index);
extern void *luaS_newlstr(lua_State *L, const char *str, unsigned int length);
extern const K6bTObject *luaH_getstr(K6bTable *t, void *key);
#define k6b_assert(e, line) ((e) ? (void)0 : __assert("LuaExtras.c", line, #e))
#define k6b_api_check(L, o, line) k6b_assert(o, line)
int w3d_k6b_lua_table_length_802cd408(lua_State *L, int index)
{
    K6bTObject *t;
    const K6bTObject *n;
    lua_Number max;
    if (index > 0) {
        k6b_api_check(L, index <= L->top - L->ci->base, 28);
        t = L->ci->base + index - 1;
    } else
        t = negindex(L, index);
    k6b_api_check(L, ((t)->tt) == 5, 29);
    {
        n = luaH_getstr((K6bTable *)t->value.p, luaS_newlstr(L, "n", sizeof("n") - 1));
        if (n->tt == 3)
            max = n->value.n;
        else {
            K6bTable *h = (K6bTable *)t->value.p;
            int i;
            K6bNode *node;
            i = h->sizearray;
            while (i-- != 0 && h->array[i].tt == 0)
                ;
            max = (lua_Number)(i + 1);
            i = 1 << h->lsizenode;
            node = h->node;
            while (i--) {
                if (node->i_key.tt == 3 && node->i_val.tt != 0 && node->i_key.value.n > max)
                    max = node->i_key.value.n;
                node++;
            }
        }
    }
    return (int)max;
}
// desc: w3d_k6b_lua_table_length_802cd408: Appears to return a table's length (LuaExtras.c): its numeric n field, else the larger of the last non-nil array index and the largest numeric hash key.
