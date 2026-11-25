#include "w3d_ptr.h"
#line 1 "a_path_search.cpp"
/* AI path search (0x800041e0..0x80006388).
 *
 * Names are inferred from behavior; no original symbols survive. The search
 * object keeps two node hash tables (1024 buckets each, keyed by the node's
 * x coordinate), an ordered candidate list and the resulting path:
 *   +0x0004 open table, +0x4008 closed table (bucket count word at +0x4000)
 *   +0x800c current node, +0x8010 best node, +0x8018 status, +0x801c remaining
 *   +0x8024 path vector, +0x8034 path cursor, +0x8038 height tolerance
 *   +0x8048/+0x804a lowest/highest candidate cost, +0x804c candidate vector
 *   +0x805c/+0x8060 pop counters, +0x8068 vtable
 * Nodes: +0x02 x, +0x04 y, +0x06 layer byte, +0x0c cost.
 */
extern "C" {

typedef struct W3dPathNode {
    unsigned char unknown_00[2];
    short x;
    union {
        struct { short y; unsigned char layer; unsigned char direction; } cell; /* orden PPC: +4 y, +6 layer, +7 direction, escritos con sth/stb */
        unsigned int key;   /* y and layer: PPC, top 24 bits; host, low 24 bits */
    } u;
    short estimate;     /* heuristic distance to the goal */
    short travelled;    /* cost from the start */
    short cost;         /* travelled + estimate */
    unsigned char unknown_0e[2];
    int link;
} W3dPathNode;

typedef struct W3dPathLimit {
    int unknown_00;
    Ptr32<Ptr32<W3dPathNode>> capacity;
} W3dPathLimit;

/* Node vector: begin, end, then a {word, capacity} pair. */
typedef struct W3dPathVector {
    Ptr32<Ptr32<W3dPathNode>> begin;
    Ptr32<Ptr32<W3dPathNode>> end;
    W3dPathLimit limit;
} W3dPathVector;

typedef struct W3dPathTable {
    W3dPathVector buckets[1024];
    int count;
} W3dPathTable;

typedef struct W3dPathWhere {
    int bucket;
    int index;
} W3dPathWhere;

typedef struct W3dPathSearch {
    unsigned char unknown_0000[4];
    W3dPathTable open;
    W3dPathTable closed;
    Ptr32<W3dPathNode> current;
    Ptr32<W3dPathNode> best;
    int iterations;
    int status;
    int remaining;
    int unknown_8020;
    W3dPathVector path;
    int cursor;
    float tolerance;
    int max_iterations;
    int limit_8040;
    int limit_8044;
    short lowest_cost;
    short highest_cost;
    W3dPathVector candidates;
    int list_pops;
    int table_pops;
    int unknown_8064;
    Ptr32<void> vtable;
} W3dPathSearch;

typedef struct W3dPathCost {
    unsigned char unknown_00[4];
    float limit;
    int enabled;
    Ptr32<void> vtable;
} W3dPathCost;

extern unsigned char w3d_path_search_vtable_8040cb10[];
extern unsigned char w3d_path_cost_vtable_8040cba0[];
extern const float w3d_f32_minus_1e20_803694cc[];
extern Ptr32<W3dPathSearch> w3d_path_search_instance_804aa54c;
extern int w3d_path_search_enabled_804aa794;
extern Ptr32<void> w3d_world_map_804b1758;
extern int w3d_path_result_804b175c;
extern Ptr32<unsigned char> w3d_game_settings_804aa6d8;

int abs(int value);
void w3d_empty_8034144c(void);
void w3d_operator_delete_80015264(Ptr32<void> object);
void w3d_handle_storage_release(Ptr32<void> storage);
Ptr32<void> w3d_memmove_802eeef4(Ptr32<void> dest, Ptr32<const void> source, unsigned int size);
Ptr32<void> w3d_handle_storage_allocate(unsigned int bytes);
Ptr32<void> w3d_handle_storage_fallback(unsigned int bytes);
Ptr32<float> w3d_world_map_floor_8001e11c(Ptr32<void> map, int x, int y, int z);
Ptr32<float> w3d_world_map_ceiling_8001e1a0(Ptr32<void> map, int x, int y, int z);
Ptr32<W3dPathNode> w3d_path_table_take_80005858(Ptr32<W3dPathTable> table, int mode);
void w3d_path_search_build_80005e1c(Ptr32<W3dPathSearch> search);
void w3d_path_table_insert_800053e4(Ptr32<W3dPathTable> table, Ptr32<W3dPathNode> node);
void w3d_path_search_expand_800047f0(Ptr32<W3dPathSearch> search, Ptr32<W3dPathNode> node);
Ptr32<void> w3d_alloc_8001523c(unsigned int size);
void w3d_range_limits_reset(Ptr32<W3dPathNode> node);
void w3d_empty_80341448(void);
float w3d_world_map_tolerance_8001e2dc(Ptr32<void> map);
int w3d_world_map_locate_8001e328(Ptr32<void> map, Ptr32<const void> position, Ptr32<short> x, Ptr32<short> y, Ptr32<int> layer);
Ptr32<unsigned char> w3d_world_map_cell_8001dff8(Ptr32<void> map, int x, int y, int layer);
void w3d_path_search_finish_80005d4c(Ptr32<W3dPathSearch> search);

void w3d_path_search_reset_80004394(Ptr32<W3dPathSearch> search);
void w3d_path_search_clear_path_800062ec(Ptr32<W3dPathSearch> search);

static inline void w3d_path_limit_init(Ptr32<W3dPathLimit> limit)
{
    limit->capacity = 0;
}

static inline void w3d_path_vector_init(Ptr32<W3dPathVector> vector)
{
    vector->begin = 0;
    vector->end = 0;
    w3d_path_limit_init(&vector->limit);
}

static inline Ptr32<W3dPathNode> & w3d_path_vector_at(Ptr32<W3dPathVector> vector, int n)
{
    return vector->begin[n];
}

static inline void w3d_path_vector_clear(Ptr32<W3dPathVector> vector)
{
    vector->end = vector->begin;
}

static inline void w3d_path_node_delete(Ptr32<W3dPathNode> node)
{
    w3d_empty_8034144c();
    w3d_operator_delete_80015264(node);
}


void w3d_path_search_destroy(Ptr32<W3dPathSearch> search, int flags)
{
    Ptr32<W3dPathVector> base;
    Ptr32<W3dPathVector> bucket;

    search->vtable = w3d_path_search_vtable_8040cb10;
    w3d_path_search_reset_80004394(search);
    w3d_path_search_clear_path_800062ec(search);
    w3d_path_search_instance_804aa54c = 0;
    if (search->candidates.begin)
        w3d_handle_storage_release(search->candidates.begin);
    if (search->path.begin)
        w3d_handle_storage_release(search->path.begin);
    base = search->closed.buckets;
    if (base) {
        bucket = base + 1024;
        while (base != bucket) {
            --bucket;
            if (bucket->begin)
                w3d_handle_storage_release(bucket->begin);
        }
    }
    base = search->open.buckets;
    if (base) {
        bucket = base + 1024;
        while (base != bucket) {
            --bucket;
            if (bucket->begin)
                w3d_handle_storage_release(bucket->begin);
        }
    }
    if (flags & 1)
        w3d_operator_delete_80015264(search);
}

void w3d_path_table_clear_80005398(Ptr32<W3dPathTable> table);
void w3d_path_bucket_clear_8000532c(Ptr32<W3dPathVector> bucket);


static inline bool w3d_path_node_same_cell(Ptr32<const W3dPathNode> a, Ptr32<const W3dPathNode> b)
{
    return a->x == b->x && (a->u.key & 0x00ffffff) == (b->u.key & 0x00ffffff); /* PPC ~0xff quita +7, que en el anfitrión es el byte alto */
}

static inline void w3d_path_copy(Ptr32<Ptr32<W3dPathNode>> first, Ptr32<Ptr32<W3dPathNode>> last, Ptr32<Ptr32<W3dPathNode>> result)
{
    if (last != first)
        w3d_memmove_802eeef4(result, first, (Ptr32<char>)last - (Ptr32<char>)first);
}

static inline void w3d_path_vector_erase(Ptr32<W3dPathVector> vector, Ptr32<Ptr32<W3dPathNode>> at)
{
    if (at + 1 != vector->end)
        w3d_path_copy(at + 1, vector->end, at);
    vector->end--;
}

extern "C++" {
template<class T> inline const T &w3d_path_max(const T &first, const T &second)
{ return first < second ? second : first; }
}

static inline Ptr32<Ptr32<W3dPathNode>> w3d_path_copy_range(Ptr32<Ptr32<W3dPathNode>> first, Ptr32<Ptr32<W3dPathNode>> last, Ptr32<Ptr32<W3dPathNode>> result)
{
    if (last != first) {
        unsigned int bytes = (Ptr32<char>)last - (Ptr32<char>)first;
        return (Ptr32<Ptr32<W3dPathNode>>)((Ptr32<char>)w3d_memmove_802eeef4(result, first, bytes) + bytes);
    }
    return result;
}

static inline Ptr32<Ptr32<W3dPathNode>> w3d_path_fill_n(Ptr32<Ptr32<W3dPathNode>> first, unsigned int n, Ptr32<W3dPathNode> const &value)
{
    for (; n != 0; --n, ++first)
        *first = value;
    return first;
}

static inline Ptr32<Ptr32<W3dPathNode>> w3d_path_allocate(unsigned int n)
{
    if (n != 0) {
        Ptr32<void> storage = w3d_handle_storage_allocate(n * sizeof(Ptr32<W3dPathNode>));
        if (storage == 0)
            storage = w3d_handle_storage_fallback(n * sizeof(Ptr32<W3dPathNode>));
        return (Ptr32<Ptr32<W3dPathNode>>)storage;
    }
    return 0;
}

static inline void w3d_path_vector_fill_insert(Ptr32<W3dPathVector> vector, Ptr32<Ptr32<W3dPathNode>> at, unsigned int n,
                                               Ptr32<W3dPathNode> const &value)
{
    unsigned int old_size = vector->end - vector->begin;
    unsigned int len = old_size + w3d_path_max(old_size, n);
    Ptr32<Ptr32<W3dPathNode>> start = w3d_path_allocate(len);
    Ptr32<Ptr32<W3dPathNode>> finish = w3d_path_copy_range(vector->begin, at, start);
    finish = w3d_path_fill_n(finish, n, value);
    if (vector->begin)
        w3d_handle_storage_release(vector->begin);
    vector->limit.capacity = start + len;
    vector->end = finish;
    vector->begin = start;
}

static inline Ptr32<W3dPathVector> w3d_path_table_bucket(Ptr32<W3dPathTable> table, unsigned int hash)
{
    return &table->buckets[hash];
}

static inline void w3d_path_vector_push(Ptr32<W3dPathVector> vector, Ptr32<W3dPathNode> const &value)
{
    if (vector->end != vector->limit.capacity) {
        Ptr32<Ptr32<W3dPathNode>> slot = vector->end;
        if (slot)
            *slot = value;
        vector->end++;
    } else {
        w3d_path_vector_fill_insert(vector, vector->end, 1, value);
    }
}

short w3d_path_node_distance(Ptr32<const W3dPathNode> a, Ptr32<const W3dPathNode> b);
Ptr32<W3dPathNode> w3d_path_bucket_find(Ptr32<W3dPathVector> bucket, Ptr32<const W3dPathNode> key, Ptr32<int> index);
Ptr32<W3dPathNode> w3d_path_table_find(Ptr32<W3dPathTable> table, Ptr32<const W3dPathNode> key, Ptr32<W3dPathWhere> where);
void w3d_path_table_erase(Ptr32<W3dPathTable> table, Ptr32<const W3dPathWhere> where);



Ptr32<W3dPathNode> w3d_path_search_pop(Ptr32<W3dPathSearch> search);


Ptr32<W3dPathNode> w3d_path_search_pop(Ptr32<W3dPathSearch> search)
{
    Ptr32<W3dPathNode> node;
    Ptr32<W3dPathVector> candidates = &search->candidates;
    if (search->candidates.begin != candidates->end) {
        W3dPathWhere where;
        node = *search->candidates.begin;
        w3d_path_vector_erase(candidates, search->candidates.begin);
        w3d_path_table_find(&search->open, node, &where);
        w3d_path_table_erase(&search->open, &where);
        search->list_pops++;
    } else {
        node = w3d_path_table_take_80005858(&search->open, 0);
        if (node->cost > search->highest_cost)
            search->highest_cost = node->cost;
        search->table_pops++;
    }
    return node;
}

void w3d_path_search_remove_candidate(Ptr32<W3dPathSearch> search, Ptr32<W3dPathNode> node)
{
    int index;
    int n;
    if (node->cost > search->lowest_cost)
        return;
    if (!w3d_path_bucket_find(&search->candidates, node, &index))
        return;
    {
        Ptr32<Ptr32<W3dPathNode>> at = search->candidates.begin + index;
        w3d_path_vector_erase(&search->candidates, at);
    }
    n = search->candidates.end - search->candidates.begin;
    if (n > 0)
        search->lowest_cost = w3d_path_vector_at(&search->candidates, n - 1)->cost;
}


short w3d_path_node_distance(Ptr32<const W3dPathNode> a, Ptr32<const W3dPathNode> b)
{
    int dx = abs(a->x - b->x);
    int dy = abs(a->u.cell.y - b->u.cell.y);
    if (dx < dy) {
        int t = dx;
        dx = dy;
        dy = t;
    }
    return dy * 14 + (dx - dy) * 10;
}



Ptr32<W3dPathNode> w3d_path_bucket_find(Ptr32<W3dPathVector> bucket, Ptr32<const W3dPathNode> key, Ptr32<int> index)
{
    int i;
    int n = bucket->end - bucket->begin;
    for (i = 0; i < n; i++) {
        Ptr32<W3dPathNode> node = w3d_path_vector_at(bucket, i);
        if (w3d_path_node_same_cell(key, node)) {
            if (index)
                *index = i;
            return node;
        }
    }
    return 0;
}

Ptr32<W3dPathNode> w3d_path_table_find(Ptr32<W3dPathTable> table, Ptr32<const W3dPathNode> key, Ptr32<W3dPathWhere> where)
{
    Ptr32<int> index = 0;
    unsigned int hash = (key->x + key->x * 33) & 0x3ff;
    if (where) {
        where->bucket = hash;
        index = &where->index;
    }
    return w3d_path_bucket_find(&table->buckets[hash], key, index);
}

void w3d_path_bucket_clear_8000532c(Ptr32<W3dPathVector> bucket)
{
    while (bucket->begin != bucket->end) {
        Ptr32<W3dPathNode> node = bucket->end[-1];
        if (node)
            w3d_path_node_delete(node);
        bucket->end--;
    }
}

void w3d_path_table_clear_80005398(Ptr32<W3dPathTable> table)
{
    int i;
    for (i = 0; i < 1024; i++)
        w3d_path_bucket_clear_8000532c(&table->buckets[i]);
    table->count = 0;
}




void w3d_path_table_erase(Ptr32<W3dPathTable> table, Ptr32<const W3dPathWhere> where)
{
    Ptr32<W3dPathVector> bucket = &table->buckets[where->bucket];
    Ptr32<Ptr32<W3dPathNode>> at = bucket->begin + where->index;
    w3d_path_vector_erase(bucket, at);
    table->count--;
}

int w3d_path_search_status(Ptr32<W3dPathSearch> search)
{
    return search->status;
}

int w3d_path_search_remaining(Ptr32<W3dPathSearch> search)
{
    return search->remaining;
}

Ptr32<W3dPathNode> w3d_path_search_next_step(Ptr32<W3dPathSearch> search)
{
    int cursor;
    search->remaining--;
    cursor = search->cursor++;
    return w3d_path_vector_at(&search->path, cursor);
}


Ptr32<W3dPathCost> w3d_path_cost_construct(Ptr32<W3dPathCost> cost)
{
    cost->vtable = w3d_path_cost_vtable_8040cba0;
    cost->limit = w3d_f32_minus_1e20_803694cc[0];
    cost->enabled = 1;
    return cost;
}

void w3d_path_cost_destroy(Ptr32<W3dPathCost> cost, int flags)
{
    cost->vtable = w3d_path_cost_vtable_8040cba0;
    if (flags & 1)
        w3d_operator_delete_80015264(cost);
}


#if 0
/* 0x800041e0: matches except the frame; the original reserves 32 extra bytes
 * of stack (likely allocator temporaries of the four vector constructors). */
static inline void w3d_path_table_init(W3dPathTable *table)
{
    W3dPathVector *bucket = table->buckets;
    int n = 1024;
    do {
        w3d_path_vector_init(bucket);
        bucket++;
    } while (--n);
    table->count = 0;
}

W3dPathSearch *w3d_path_search_construct(W3dPathSearch *search)
{
    search->vtable = w3d_path_search_vtable_8040cb10;
    w3d_path_table_init(&search->open);
    w3d_path_table_init(&search->closed);
    w3d_path_vector_init(&search->path);
    w3d_path_vector_init(&search->candidates);
    w3d_path_search_instance_804aa54c = search;
    search->current = 0;
    search->best = 0;
    w3d_path_search_reset_80004394(search);
    return search;
}

/* 0x80004394: original copies search+0x10000 into a second register before
 * clearing the candidate vector; not reproduced. */
void w3d_path_search_reset_80004394(W3dPathSearch *search)
{
    W3dPathNode *node;

    w3d_path_table_clear_80005398(&search->open);
    w3d_path_table_clear_80005398(&search->closed);
    w3d_path_vector_clear(&search->candidates);
    node = search->current;
    if (node)
        w3d_path_node_delete(node);
    search->current = 0;
    node = search->best;
    if (node)
        w3d_path_node_delete(node);
    search->best = 0;
    search->status = 0;
    search->remaining = -1;
    w3d_path_bucket_clear_8000532c(&search->path);
    search->unknown_8020 = 0;
    search->highest_cost = 0x7fff;
    search->lowest_cost = 0;
}

/* 0x8000519c: matches except the frame; the original reserves an 8-byte stack
 * slot per float kept across the calls (24 bytes). */
int w3d_path_search_height_ok(W3dPathSearch *search, int x, int y, int z, float low, float high)
{
    void *map = w3d_world_map_804b1758;
    float floor = *w3d_world_map_floor_8001e11c(map, x, y, z);
    float ceiling = *w3d_world_map_ceiling_8001e1a0(map, x, y, z);
    if (ceiling - low > search->tolerance)
        return 0;
    if (high - floor > search->tolerance)
        return 0;
    return 1;
}

/* 0x800062ec: original computes the path vector address in a scratch register
 * and copies it into a saved register inside the loop guard. */
void w3d_path_search_clear_path_800062ec(W3dPathSearch *search)
{
    W3dPathVector *path = &search->path;
    while (search->path.begin != path->end) {
        W3dPathNode **end = path->end;
        W3dPathNode *node = *--end;
        path->end = end;
        if (node)
            w3d_path_node_delete(node);
    }
}
/* 0x80004498: same instructions, but callee-saved register assignment and
 * the placement of the "finished" flag differ. */
static inline W3dPathNode *w3d_path_node_init(W3dPathNode *node, short x, short y, int layer)
{
    w3d_range_limits_reset(node);
    node->x = x;
    node->u.cell.y = y;
    node->u.cell.layer = layer;
    w3d_empty_80341448();
    return node;
}

void w3d_path_search_start(W3dPathSearch *search, const void *from, const void *to)
{
    short from_x, from_y;
    short to_x, to_y;
    int from_layer, to_layer;
    bool finished = false;
    int found;
    unsigned char *settings;
    W3dPathNode *node;

    w3d_path_search_reset_80004394(search);
    search->iterations = 0;
    search->list_pops = 0;
    search->table_pops = 0;
    search->unknown_8064 = 0;
    w3d_path_result_804b175c = 10;
    search->tolerance = w3d_world_map_tolerance_8001e2dc(w3d_world_map_804b1758);
    w3d_world_map_locate_8001e328(w3d_world_map_804b1758, from, &from_x, &from_y, &from_layer);
    node = (W3dPathNode *)w3d_alloc_8001523c(sizeof(W3dPathNode));
    search->current = w3d_path_node_init(node, from_x, from_y, from_layer);
    w3d_path_table_insert_800053e4(&search->open, search->current);
    found = w3d_world_map_locate_8001e328(w3d_world_map_804b1758, to, &to_x, &to_y, &to_layer);
    node = (W3dPathNode *)w3d_alloc_8001523c(sizeof(W3dPathNode));
    search->best = w3d_path_node_init(node, to_x, to_y, to_layer);
    search->current->travelled = 0;
    search->current->estimate = w3d_path_node_distance(search->current, search->best);
    search->current->cost = search->current->travelled + search->current->estimate;
    if (w3d_path_search_enabled_804aa794 == 0) {
        unsigned char cell;
        if (found == 0) {
            w3d_path_result_804b175c = 5;
            finished = true;
        }
        cell = *w3d_world_map_cell_8001dff8(w3d_world_map_804b1758, to_x, to_y, to_layer);
        if (cell != 0) {
            finished = true;
            switch (cell) {
            case 1: w3d_path_result_804b175c = 6; break;
            case 2: w3d_path_result_804b175c = 7; break;
            case 3: w3d_path_result_804b175c = 8; break;
            case 4: w3d_path_result_804b175c = 9; break;
            }
        }
    }
    if (from_x == to_x && from_y == to_y && from_layer == to_layer) {
        w3d_path_search_enabled_804aa794 = 0;
        finished = true;
        w3d_path_result_804b175c = 11;
    }
    if (finished)
        w3d_path_search_finish_80005d4c(search);
    settings = w3d_game_settings_804aa6d8;
    search->limit_8040 = *(int *)(settings + 0x1f0);
    search->limit_8044 = *(int *)(settings + 0x1ec);
}

/* 0x800046c8: original keeps the constant 1 for the status store inside the
 * loop; this source lets the loop optimizer hoist it into a saved register. */
void w3d_path_search_step(W3dPathSearch *search)
{
    W3dPathTable *open = &search->open;
    W3dPathNode *node;
    int i = 0;
    for (;;) {
        if (open->count == 0 || search->iterations++ >= search->max_iterations) {
            w3d_path_search_finish_80005d4c(search);
            return;
        }
        node = w3d_path_search_pop(search);
        if (w3d_path_node_same_cell(node, search->best))
            break;
        w3d_path_table_insert_800053e4(&search->closed, node);
        i++;
        w3d_path_search_expand_800047f0(search, node);
        if (i > 99)
            return;
    }
    search->status = 1;
    search->best->link = node->link;
    search->best->u.cell.direction = node->u.cell.direction;
    if (node)
        w3d_path_node_delete(node);
    w3d_path_search_build_80005e1c(search);
    w3d_path_table_clear_80005398(open);
    w3d_path_table_clear_80005398(&search->closed);
    w3d_path_vector_clear(&search->candidates);
}

/* 0x80005d4c: original places the null-node branch before the success branch
 * and shares the reset call; block layout not reproduced. */
void w3d_path_search_finish_80005d4c(W3dPathSearch *search)
{
    W3dPathNode *node;
    if (w3d_path_search_enabled_804aa794 == 0) {
        search->current = 0;
        w3d_path_search_reset_80004394(search);
    } else {
        node = w3d_path_table_take_80005858(&search->closed, 1);
        if (node) {
            W3dPathNode *old = search->best;
            if (old)
                w3d_path_node_delete(old);
            search->best = node;
            search->status = 1;
            w3d_path_search_build_80005e1c(search);
            w3d_path_table_clear_80005398(&search->open);
            w3d_path_table_clear_80005398(&search->closed);
            w3d_path_vector_clear(&search->candidates);
        } else {
            search->current = 0;
            w3d_path_search_reset_80004394(search);
        }
    }
    search->status = 1;
}
/* 0x800053e4: same instructions except register choice in the vector growth
 * path (constant 1 / begin load / copy result registers). */
void w3d_path_table_insert_800053e4(W3dPathTable *table, W3dPathNode *node)
{
    unsigned int hash = (node->x + node->x * 33) & 0x3ff;
    w3d_path_vector_push(w3d_path_table_bucket(table, hash), node);
    table->count++;
}
#endif

}


