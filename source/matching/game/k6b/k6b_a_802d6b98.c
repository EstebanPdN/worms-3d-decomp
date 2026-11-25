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
extern K6bTObject luaO_nilobject;
extern K6bNode *hashnum(const K6bTable *t, lua_Number n);
const K6bTObject *w3d_k6b_lua_table_getnum_802d6b98(K6bTable *t, int key)
{
    if (1 <= key && key <= t->sizearray)
        return &t->array[key - 1];
    else {
        lua_Number nk = (lua_Number)key;
        K6bNode *n = hashnum(t, nk);
        do {
            if (n->i_key.tt == 3 && n->i_key.value.n == nk)
                return &n->i_val;
            else n = n->next;
        } while (n);
        return &luaO_nilobject;
    }
}
// desc: w3d_k6b_lua_table_getnum_802d6b98: Appears to be Lua 5.0 ltable luaH_getnum: return the array slot for an in-range integer key, else search the hash chain for the numeric key or return the nil object.
