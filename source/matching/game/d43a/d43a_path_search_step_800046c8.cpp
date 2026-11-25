// GWMP8P rev0 0x800046c8. Runs up to one hundred expansions of the path
// search: pops the best open node, finishes on reaching the goal, else
// closes and expands it. Node and table field names are inferred.
extern "C" void w3d_path_table_clear_80005398(struct PathTable *);
struct PathNode {
    short unknown0;
    short x;             /* +2 */
    union { unsigned int cell; struct { char pad[3]; unsigned char layer; } b; };   /* +4; low byte is the layer */
    char unknown8[8];
    int cost;            /* +16 */
    bool operator==(const PathNode &o) const { return x == o.x && (cell & ~0xff) == (o.cell & ~0xff); }
};
struct PathTable { char cells[16384]; int count; bool Empty() const { return count == 0; } void Clear() { w3d_path_table_clear_80005398(this); } };
extern "C" void w3d_empty_8034144c();
extern "C" void w3d_auto_80015264(void *);
inline void DeleteNode(PathNode *n) { if (n) { w3d_empty_8034144c(); w3d_auto_80015264(n); } }
struct PtrVec { int start, finish; void clear() { finish = start; } };
struct PathSearch {
    int unknown0;
    PathTable open;         /* +4 */
    PathTable closed;       /* +16392 */
    PathNode *a;            /* +32780 */
    PathNode *goal;         /* +32784 */
    int steps;              /* +32788 */
    int found;              /* +32792 */
    char unknown801c[32];
    int limit;              /* +32828 */
    char unknown8040[12];
    PtrVec list;
    int Next() { return steps++; }
};
extern "C" void w3d_cx16a_rebuild_path_80005d4c(PathSearch *);
extern "C" PathNode *w3d_path_search_pop(PathSearch *);
extern "C" void FUN_80005e1c(PathSearch *);
extern "C" void d29s_push_tagged_800053e4(PathTable *, PathNode *);
extern "C" void FUN_800047f0(PathSearch *, PathNode *);
extern "C" void w3d_d43a_path_search_step_800046c8(PathSearch *self)
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
        PathNode *node = w3d_path_search_pop(self);
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
