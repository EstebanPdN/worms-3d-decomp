#include "w3d_ptr.h"
#line 1 "d43a_path_search_step_800046c8.cpp"
// GWMP8P rev0 0x800046c8. Runs up to one hundred expansions of the path
// search: pops the best open node, finishes on reaching the goal, else
// closes and expands it. Node and table field names are inferred.
extern "C" void w3d_path_table_clear_80005398(Ptr32<struct PathTable>);
struct PathNode {
    short unknown0;
    short x;             /* +2 */
    union { unsigned int cell; struct { char pad[3]; unsigned char layer; } b; };   /* PPC +4 y, +6 layer, +7 direction: b.layer es +7 */
    char unknown8[8];
    int cost;            /* +16 */
    bool operator==(const PathNode &o) const { return x == o.x && (cell & 0x00ffffff) == (o.cell & 0x00ffffff); }
};
struct PathTable { char cells[16384]; int count; bool Empty() const { return count == 0; } void Clear() { w3d_path_table_clear_80005398(this); } };
extern "C" void w3d_empty_8034144c();
extern "C" void w3d_auto_80015264(Ptr32<void>);
inline void DeleteNode(Ptr32<PathNode> n) { if (n) { w3d_empty_8034144c(); w3d_auto_80015264(n); } }
struct PtrVec { int start, finish; void clear() { finish = start; } };
struct PathSearch {
    int unknown0;
    PathTable open;         /* +4 */
    PathTable closed;       /* +16392 */
    Ptr32<PathNode> a;            /* +32780 */
    Ptr32<PathNode> goal;         /* +32784 */
    int steps;              /* +32788 */
    int found;              /* +32792 */
    char unknown801c[32];
    int limit;              /* +32828 */
    char unknown8040[12];
    PtrVec list;
    int Next() { return steps++; }
};
extern "C" void w3d_cx16a_rebuild_path_80005d4c(Ptr32<PathSearch>);
extern "C" Ptr32<PathNode> w3d_path_search_pop(Ptr32<PathSearch>);
extern "C" void FUN_80005e1c(Ptr32<PathSearch>);
extern "C" void d29s_push_tagged_800053e4(Ptr32<PathTable>, Ptr32<PathNode>);
extern "C" void FUN_800047f0(Ptr32<PathSearch>, Ptr32<PathNode>);
extern "C" void w3d_d43a_path_search_step_800046c8(Ptr32<PathSearch> self)
{
    PathTable &open = self->open;
    for (int i = 0; i <= 99; i++) {
        if (open.Empty()) {
            w3d_cx16a_rebuild_path_80005d4c(self);
            return;
        }
        if (self->Next() >= self->limit) {
            w3d_cx16a_rebuild_path_80005d4c(self);
            return;
        }
        Ptr32<PathNode> node = w3d_path_search_pop(self);
        if (*node == *self->goal) {
            self->found = 1;
            self->goal->cost = node->cost;
            unsigned char layer = node->b.layer; self->goal->b.layer = layer;
            DeleteNode(node);
            FUN_80005e1c(self);
            open.Clear();
            self->closed.Clear();
            self->list.clear();
            return;
        }
        d29s_push_tagged_800053e4(&self->closed, node);
        FUN_800047f0(self, node);
    }
}


