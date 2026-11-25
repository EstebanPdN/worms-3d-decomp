#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_802d6b98.c"
typedef float lua_Number;
typedef struct K6bTObject {
    int tt;
    union { Ptr32<void> p; lua_Number n; int b; } value;
} K6bTObject;
typedef struct K6bNode {
    K6bTObject i_key;
    K6bTObject i_val;
    Ptr32<struct K6bNode> next;
} K6bNode;
typedef struct K6bTable {
    Ptr32<void> next;
    unsigned char tt;
    unsigned char marked;
    unsigned char flags;
    unsigned char lsizenode;
    Ptr32<struct K6bTable> metatable;
    Ptr32<K6bTObject> array;
    Ptr32<K6bNode> node;
    Ptr32<K6bNode> firstfree;
    Ptr32<void> gclist;
    int sizearray;
} K6bTable;
extern K6bTObject luaO_nilobject;
extern Ptr32<K6bNode> hashnum(Ptr32<const K6bTable> t, lua_Number n);
Ptr32<const K6bTObject> w3d_k6b_lua_table_getnum_802d6b98(Ptr32<K6bTable> t, int key)
{
    if (1 <= key && key <= t->sizearray)
        return &t->array[key - 1];
    else {
        lua_Number nk = (lua_Number)key;
        Ptr32<K6bNode> n = hashnum(t, nk);
        do {
            if (n->i_key.tt == 3 && n->i_key.value.n == nk)
                return &n->i_val;
            else n = n->next;
        } while (n);
        return &luaO_nilobject;
    }
}
// desc: w3d_k6b_lua_table_getnum_802d6b98: Appears to be Lua 5.0 ltable luaH_getnum: return the array slot for an in-range integer key, else search the hash chain for the numeric key or return the nil object.

}
