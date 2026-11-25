/* Recovered complete reference-ABI bodies; names and source types are inferred.
 * Exact original instruction comparisons are retained in source-proof receipts.
 * Storage setup, free/coalescing, backend hardware and state ownership remain
 * external. Append continues after reporting overflow, as the original does.
 * Cleanup is void; raw r3 leftovers do not establish pointer-return semantics.
 */
namespace w3d_native_request_detail {
typedef unsigned int u32;
struct Request { volatile u32 state; void *write_source; void *read_destination; u32 backing; u32 serial_id; u32 bytes; unsigned char backend[32]; };
struct Block { u32 start,bytes; };
struct Service { u32 initialized,start,end,reserved; Block free[256]; u32 count; };
extern "C" {
extern u32 w3d_request_backend_initialize();
extern u32 w3d_request_backend_base();
extern u32 w3d_request_backend_size();
extern void w3d_request_report_failure(const char *,u32);
extern const char w3d_request_capacity_failure[];
extern Service w3d_request_service_storage;
extern void *w3d_buffer_request_service();
extern void w3d_actor_member_delete_backend(void *);
extern int w3d_request_storage_backing_initialize(Service *,u32);
extern Block *w3d_request_storage_append_block(Service *);
extern int w3d_request_storage_release(Service *,Request *);
extern u32 w3d_request_storage_finalize(Service *);
extern u32 w3d_request_storage_reset(Service *);
extern u32 w3d_request_storage_finish(Service *);

int w3d_request_storage_backing_initialize(Service *s, u32 bytes) {
    w3d_request_backend_initialize();
    u32 a = w3d_request_backend_base();
    u32 b = w3d_request_backend_size();
    s->start = a + b - bytes;
    u32 c = w3d_request_backend_base();
    u32 d = w3d_request_backend_size();
    s->reserved = bytes;
    s->end = c + d;
    return 1;
}

Block *w3d_request_storage_append_block(Service *s) {
    if (s->count > 255)
        w3d_request_report_failure(w3d_request_capacity_failure, 0);
    return &s->free[s->count++];
}

extern u32 w3d_request_storage_coalesce(Service *);
void w3d_request_destroy(Request *r, u32 flags) {
    if (r->backing)
        w3d_request_storage_release((Service *)w3d_buffer_request_service(), r);
    if (flags & 1)
        w3d_actor_member_delete_backend(r);
}

extern void w3d_request_service_destroy(Service *, u32);
void w3d_request_service_shutdown() {
    w3d_request_service_destroy(&w3d_request_service_storage, 2);
}

void w3d_request_service_destroy(Service *s, u32 flags) {
    w3d_request_storage_finalize(s);
    if (flags & 1)
        w3d_actor_member_delete_backend(s);
}

u32 w3d_request_storage_finalize(Service *s) {
    u32 result = 0;
    if (s->initialized == 1) {
        w3d_request_storage_reset(s);
        result = w3d_request_storage_finish(s);
    }
    return result;
}

u32 w3d_request_storage_reset(Service *s) {
    volatile Service *v = s;
    register u32 start = v->start;
    register u32 bytes = v->reserved;
    v->count = 1;
    v->free[0].bytes = bytes;
    v->free[0].start = start;
    return 1;
}

/* The complete original body at 0x8020f938 also returns one. */
u32 w3d_request_storage_finish(Service *) {
    return 1;
}

extern u32 w3d_request_maintenance_a(u32);
extern u32 w3d_request_maintenance_b(u32);
u32 w3d_request_storage_maintenance(u32 raw) {
    raw = w3d_request_maintenance_a(raw);
    w3d_request_maintenance_b(raw);
    return w3d_request_storage_coalesce((Service *)w3d_buffer_request_service());
}
}
}
