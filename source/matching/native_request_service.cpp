/* Private reference-ABI reconstruction; inferred names, observed 32-bit offsets.
 * No hardware implementation or whole-program equivalence claim. */
namespace w3d_native_request_detail {
typedef unsigned int u32;
struct Request { volatile u32 state; void *write_source; void *read_destination; u32 backing; u32 serial_id; u32 bytes; unsigned char backend[32]; };
struct Block { u32 start,bytes; };
struct Service { u32 initialized,start,end,reserved; Block free[256]; u32 count; };
extern "C" {
extern Service w3d_request_service_storage; extern u32 w3d_request_service_guard, w3d_request_serial; extern Request *w3d_active_request;
extern Service *w3d_request_service_initialize(Service *); extern void w3d_request_service_shutdown(); extern int w3d_register_shutdown(void(*)());
extern int w3d_request_storage_setup(Service *,u32);
extern void w3d_request_prepare_write(Request *,void *,u32,u32); extern void w3d_request_prepare_read(Request *,void *);
extern int w3d_request_transfer_write(Service *,Request *);extern int w3d_request_transfer_read(Service *,Request *);
extern void w3d_request_remove_block(Service *,Block *);
extern u32 w3d_request_interrupts_disable();extern void w3d_request_interrupts_restore(u32);
extern void w3d_request_cache_flush(void *,u32);extern void w3d_request_cache_invalidate(void *,u32);
extern void w3d_request_hardware_post(void *,u32,u32,u32,u32,u32,u32,void(*)(void *));
extern void w3d_request_write_complete(void *); extern void w3d_request_read_complete(void *);
extern void w3d_request_report_failure(const char *,u32);
extern const char w3d_request_write_timeout[],w3d_request_read_timeout[],w3d_request_write_bad_callback[],w3d_request_read_bad_callback[];
void *w3d_buffer_request_service() { if(!w3d_request_service_guard) {w3d_request_service_initialize(&w3d_request_service_storage);w3d_request_service_guard=1;w3d_register_shutdown(w3d_request_service_shutdown);} return &w3d_request_service_storage; }
int w3d_buffer_request_state(void *request) {return ((Request *)request)->state;}
void w3d_request_prepare_write(Request *r,void *src,u32 backing,u32 bytes) { u32 id=w3d_request_serial;r->bytes=bytes;r->state=1;r->write_source=src;r->read_destination=0;r->backing=backing;r->serial_id=id;w3d_request_serial=id+1; }
void w3d_request_prepare_read(Request *r,void *dst) {r->read_destination=dst;}
Service *w3d_request_service_initialize(Service *s) {volatile Service *p=s;p->count=0;p->initialized=0;p->start=0;p->reserved=0;p->end=0;return s;}

int w3d_buffer_request_read(void *service,void *request,void *dst,u32 /* original r6 ignored */) {Service *s=(Service *)service;Request *r=(Request *)request;w3d_request_prepare_read(r,dst);w3d_request_transfer_read(s,r);return 1;}

int w3d_request_transfer_write(Service *,Request *r) {
 u32 count=0;u32 irq=w3d_request_interrupts_disable();w3d_request_cache_flush(r->write_source,r->bytes);
 w3d_request_hardware_post(r->backend,0,0,1,(u32)r->write_source,r->backing,r->bytes,w3d_request_write_complete);
 w3d_active_request=r;r->state=4;w3d_request_interrupts_restore(irq);
 while(r->state!=2) {if(++count>1000000)w3d_request_report_failure(w3d_request_write_timeout,0);}
 w3d_active_request=0;return 1;
}
int w3d_request_transfer_read(Service *,Request *r) {
 u32 count=0;u32 irq=w3d_request_interrupts_disable();
 w3d_request_hardware_post(r->backend,0,1,1,r->backing,(u32)r->read_destination,r->bytes,w3d_request_read_complete);
 w3d_active_request=r;r->state=5;w3d_request_interrupts_restore(irq);
 while(r->state!=3) {if(++count>1000000)w3d_request_report_failure(w3d_request_read_timeout,0);}
 w3d_request_cache_invalidate(r->read_destination,r->bytes);w3d_active_request=0;return 1;
}
void w3d_request_write_complete(void *backend) {if(backend==w3d_active_request->backend)w3d_active_request->state=2;else w3d_request_report_failure(w3d_request_write_bad_callback,0);}
void w3d_request_read_complete(void *backend) {if(backend==w3d_active_request->backend)w3d_active_request->state=3;else w3d_request_report_failure(w3d_request_read_bad_callback,0);}
}

}
