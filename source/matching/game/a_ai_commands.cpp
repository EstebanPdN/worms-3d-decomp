/* AI command objects (0x80007d58..0x80009670).
 *
 * Names are inferred from behavior; no original symbols survive. Each
 * function allocates a command object, fills in its type number, type table
 * and parameters, appends it to the global command list (vector pointer at
 * 0x804aa564) and hands it to the registry object at 0x804aa5a4.
 * Command layout: +0x04/+0x08 cleared words, +0x0c type number, +0x10 type
 * table, +0x14.. parameters.
 */
extern "C" {

typedef struct W3dCommand {
    unsigned char unknown_00[4];
    int unknown_04;
    int unknown_08;
    int type;
    void *vtable;
} W3dCommand;

typedef struct W3dCommandVector {
    W3dCommand **begin;
    W3dCommand **end;
    W3dCommand **capacity;
} W3dCommandVector;

struct W3dCommandVec3 {
    float x;
    float y;
    float z;
    W3dCommandVec3() {}
    W3dCommandVec3(float vx, float vy, float vz) : x(vx), y(vy), z(vz) {}
};

typedef struct W3dCommandInt {
    W3dCommand base;
    int value;
} W3dCommandInt;

typedef struct W3dCommandIntInt {
    W3dCommand base;
    int value;
    int extra;
} W3dCommandIntInt;

typedef struct W3dCommandIntFloat {
    W3dCommand base;
    int value;
    float amount;
} W3dCommandIntFloat;

typedef struct W3dCommandPoint {
    W3dCommand base;
    W3dCommandVec3 point;
} W3dCommandPoint;

typedef struct W3dCommandIntPoint {
    W3dCommand base;
    int value;
    W3dCommandVec3 point;
} W3dCommandIntPoint;

/* Commands built by out-of-line constructors keep a float parameter here. */
typedef struct W3dCommandFloat24 {
    W3dCommand base;
    unsigned char unknown_14[4];
    float amount;
} W3dCommandFloat24;

typedef struct W3dCommandFloat28 {
    W3dCommand base;
    unsigned char unknown_14[8];
    float amount;
} W3dCommandFloat28;

extern W3dCommandVector *w3d_command_list_804aa564;
extern void *w3d_command_registry_804aa5a4;
extern unsigned char w3d_command_vtable_1_8040dd68[];
extern unsigned char w3d_command_vtable_3_8040dd28[];
extern unsigned char w3d_command_vtable_6_8040dce8[];
extern unsigned char w3d_command_vtable_7_8040dcc8[];
extern unsigned char w3d_command_vtable_10_8040dc68[];
extern unsigned char w3d_command_vtable_11_8040dc08[];
extern unsigned char w3d_command_vtable_15_8040dbe8[];
extern unsigned char w3d_command_vtable_16_8040dbc8[];
extern unsigned char w3d_command_vtable_17_8040dba8[];
extern unsigned char w3d_command_vtable_18_8040db88[];
extern unsigned char w3d_command_vtable_19_8040db68[];
extern unsigned char w3d_command_vtable_21_8040db48[];
extern W3dCommandVec3 w3d_vec3_origin_8041d3a0[];
extern int w3d_ai_state_804aa584;
extern int w3d_ai_flag_804aa58c;
extern int w3d_ai_team_804aa6c4;
extern void *w3d_world_map_804b1758;

void *w3d_alloc_8001523c(unsigned int size);
void *w3d_handle_storage_allocate(unsigned int bytes);
void w3d_handle_storage_release(void *storage);
void w3d_memcpy_802eee50(void *dest, const void *source, unsigned int size, ...);
void w3d_command_register_8002274c(void *registry, W3dCommand *command);
W3dCommand *w3d_command_construct_80021514(void *storage);
W3dCommand *w3d_command_construct_80021768(void *storage);
void w3d_command_set_count_80021838(W3dCommand *command, int count);
void w3d_world_map_refresh_8001f2cc(void *map);

extern "C++" {
template<class T> inline const T &w3d_command_max(const T &first, const T &second)
{ return first < second ? second : first; }
template<class T> inline const T &w3d_command_min(const T &first, const T &second)
{ return second < first ? second : first; }
}

/* Pointer vector growth: capacity grows to max(n + 1, 1.5 n) entries. */
inline void w3d_command_vector_push(W3dCommandVector *vector, W3dCommand *const &item)
{
    if (vector->end == vector->capacity) {
        unsigned int used = (unsigned char *)vector->end - (unsigned char *)vector->begin;
        unsigned int bytes = 4 * w3d_command_max((int)(used + 1), (int)(used + (used >> 1)));
        unsigned char *replacement = (unsigned char *)w3d_handle_storage_allocate(bytes);
        if (vector->begin) {
            w3d_memcpy_802eee50(replacement, vector->begin, w3d_command_min(bytes, used));
            w3d_handle_storage_release(vector->begin);
        }
        vector->begin = (W3dCommand **)replacement;
        vector->end = (W3dCommand **)(replacement + used);
        vector->capacity = (W3dCommand **)(replacement + bytes);
    }
    *vector->end = item;
    vector->end++;
}

static inline void w3d_command_init(W3dCommand *command, void *vtable, int type)
{
    command->unknown_04 = 0;
    command->unknown_08 = 0;
    command->vtable = vtable;
    command->type = type;
}

static inline void w3d_command_submit(W3dCommand *command)
{
    w3d_command_vector_push(w3d_command_list_804aa564, (W3dCommand *)command);
    w3d_command_register_8002274c(w3d_command_registry_804aa5a4, command);
}


void w3d_command_create_1(int value)
{
    if (w3d_ai_state_804aa584 == 60 || value == 49) {
        W3dCommandInt *command = (W3dCommandInt *)w3d_alloc_8001523c(28);
        w3d_command_init(&command->base, w3d_command_vtable_1_8040dd68, 1);
        w3d_command_vector_push(w3d_command_list_804aa564, (W3dCommand *)&command->base);
        command->value = value;
        w3d_command_register_8002274c(w3d_command_registry_804aa5a4, &command->base);
    }
}




void w3d_command_create_3(int value)
{
    W3dCommandIntPoint *command = (W3dCommandIntPoint *)w3d_alloc_8001523c(36);
    w3d_command_init(&command->base, w3d_command_vtable_3_8040dd28, 3);
    w3d_command_vector_push(w3d_command_list_804aa564, (W3dCommand *)&command->base);
    command->value = value;
    command->point = w3d_vec3_origin_8041d3a0[0];
    w3d_command_register_8002274c(w3d_command_registry_804aa5a4, &command->base);
    w3d_ai_flag_804aa58c = 0;
    w3d_world_map_refresh_8001f2cc(w3d_world_map_804b1758);
}


void w3d_command_create_6(int count);

void w3d_command_create_7(void)
{
    W3dCommand *command;
    w3d_command_create_6(100);
    command = (W3dCommand *)w3d_alloc_8001523c(20);
    w3d_command_init(command, w3d_command_vtable_7_8040dcc8, 7);
    w3d_command_submit(command);
}

void w3d_command_create_6(int count)
{
    W3dCommand *command;
    if (count < 0)
        count = 0;
    command = (W3dCommand *)w3d_alloc_8001523c(28);
    w3d_command_init(command, w3d_command_vtable_6_8040dce8, 6);
    w3d_command_vector_push(w3d_command_list_804aa564, (W3dCommand *)command);
    w3d_command_set_count_80021838(command, count);
    w3d_command_register_8002274c(w3d_command_registry_804aa5a4, command);
}

void w3d_command_create_15(int value)
{
    W3dCommandInt *command = (W3dCommandInt *)w3d_alloc_8001523c(24);
    w3d_command_init(&command->base, w3d_command_vtable_15_8040dbe8, 0);
    command->value = value;
    command->base.type = 15;
    w3d_command_submit(&command->base);
}


void w3d_command_create_17(const W3dCommandVec3 *point)
{
    W3dCommandPoint *command = (W3dCommandPoint *)w3d_alloc_8001523c(32);
    w3d_command_init(&command->base, w3d_command_vtable_17_8040dba8, 17);
    command->point = *point;
    w3d_command_submit(&command->base);
}

void w3d_command_create_18(int value)
{
    W3dCommandIntInt *command = (W3dCommandIntInt *)w3d_alloc_8001523c(32);
    w3d_command_init(&command->base, w3d_command_vtable_18_8040db88, 18);
    command->value = value;
    command->extra = w3d_ai_team_804aa6c4;
    w3d_command_submit(&command->base);
}

void w3d_command_create_19(void)
{
    W3dCommand *command = (W3dCommand *)w3d_alloc_8001523c(20);
    w3d_command_init(command, w3d_command_vtable_19_8040db68, 19);
    w3d_command_submit(command);
}

void w3d_command_create_21(void)
{
    W3dCommand *command = (W3dCommand *)w3d_alloc_8001523c(20);
    w3d_command_init(command, w3d_command_vtable_21_8040db48, 21);
    w3d_command_submit(command);
}


#if 0
/* 0x8000831c, 0x8000848c: the original copies the point through one 12-byte
 * temporary placed after the vector item temporary; this source allocates the
 * temporary first (stack offsets differ) and adds one instruction. */
static inline W3dCommandVec3 w3d_command_vec3(float x, float y, float z)
{
    W3dCommandVec3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

void w3d_command_create_10(const W3dCommandVec3 *point)
{
    W3dCommandPoint *command = (W3dCommandPoint *)w3d_alloc_8001523c(32);
    w3d_command_init(&command->base, w3d_command_vtable_10_8040dc68, 10);
    w3d_command_vector_push(w3d_command_list_804aa564, (W3dCommand *)&command->base);
    command->point = W3dCommandVec3(point->x, point->y, point->z);
    w3d_command_register_8002274c(w3d_command_registry_804aa5a4, &command->base);
}

void w3d_command_create_11(const W3dCommandVec3 *point)
{
    W3dCommandPoint *command = (W3dCommandPoint *)w3d_alloc_8001523c(32);
    w3d_command_init(&command->base, w3d_command_vtable_11_8040dc08, 11);
    w3d_command_vector_push(w3d_command_list_804aa564, (W3dCommand *)&command->base);
    command->point = w3d_command_vec3(point->x, point->y, point->z);
    w3d_command_register_8002274c(w3d_command_registry_804aa5a4, &command->base);
}

/* 0x800085fc, 0x8000889c, 0x80009014: the original frame has 8 extra bytes
 * for the float parameter kept across calls; not reproduced. */
void w3d_command_create_80021514(float amount)
{
    W3dCommandFloat28 *command = (W3dCommandFloat28 *)w3d_command_construct_80021514(w3d_alloc_8001523c(32));
    w3d_command_vector_push(w3d_command_list_804aa564, (W3dCommand *)&command->base);
    command->amount = amount;
    w3d_command_register_8002274c(w3d_command_registry_804aa5a4, &command->base);
}

void w3d_command_create_80021768(float amount)
{
    W3dCommandFloat24 *command = (W3dCommandFloat24 *)w3d_command_construct_80021768(w3d_alloc_8001523c(28));
    w3d_command_vector_push(w3d_command_list_804aa564, (W3dCommand *)&command->base);
    command->amount = amount;
    w3d_command_register_8002274c(w3d_command_registry_804aa5a4, &command->base);
}

void w3d_command_create_16(int value, float amount)
{
    W3dCommandIntFloat *command = (W3dCommandIntFloat *)w3d_alloc_8001523c(28);
    w3d_command_init(&command->base, w3d_command_vtable_16_8040dbc8, 16);
    command->value = value;
    command->amount = amount;
    w3d_command_submit(&command->base);
}
#endif

}
