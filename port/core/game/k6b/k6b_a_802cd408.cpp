#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_802cd408.c"
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
typedef struct K6bCallInfo {
    Ptr32<K6bTObject> base;
} K6bCallInfo;
typedef struct lua_State {
    Ptr32<void> next;
    unsigned char tt;
    unsigned char marked;
    Ptr32<K6bTObject> top;
    Ptr32<K6bTObject> base;
    Ptr32<void> l_G;
    Ptr32<K6bCallInfo> ci;
} lua_State;
extern void __assert(Ptr32<const char> file, int line, Ptr32<const char> expression);
extern Ptr32<K6bTObject> negindex(Ptr32<lua_State> L, int index);
extern Ptr32<void> luaS_newlstr(Ptr32<lua_State> L, Ptr32<const char> str, unsigned int length);
extern Ptr32<const K6bTObject> luaH_getstr(Ptr32<K6bTable> t, Ptr32<void> key);
#define k6b_assert(e, line) ((e) ? (void)0 : __assert("LuaExtras.c", line, #e))
#define k6b_api_check(L, o, line) k6b_assert(o, line)
int w3d_k6b_lua_table_length_802cd408(Ptr32<lua_State> L, int index)
{
    Ptr32<K6bTObject> t;
    Ptr32<const K6bTObject> n;
    lua_Number max;
    if (index > 0) {
        k6b_api_check(L, index <= L->top - L->ci->base, 28);
        t = L->ci->base + index - 1;
    } else
        t = negindex(L, index);
    k6b_api_check(L, ((t)->tt) == 5, 29);
    {
        n = luaH_getstr((Ptr32<K6bTable>)t->value.p, luaS_newlstr(L, "n", sizeof("n") - 1));
        if (n->tt == 3)
            max = n->value.n;
        else {
            Ptr32<K6bTable> h = (Ptr32<K6bTable>)t->value.p;
            int i;
            Ptr32<K6bNode> node;
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

}
