typedef unsigned char u8;
typedef unsigned int u32;
typedef struct First First;
struct First { First *next, *prev; void *owner; u8 pad[4]; u32 flags; u8 rest[40]; u32 handle; };
extern First *tterra_cw50_first;
extern volatile u8 tterra_cw50_counter, tterra_cw50_flags[3];
extern void tterra_cw50_middle1(void), tterra_cw50_middle2(void);
extern void tterra_cw50_checkpoint(First *);
extern void tterra_cw50_destroy(u32);
/* Restricted model: retained nodes have 0x80000, lack 0x40000 and
   0x20001, and have an owner whose byte 28 is 0xff. Destruction and
   checkpoint are external probes; no destructor behavior is modeled. */
void tterra_cw50_tick(void) {
    First *p, *next;
    if (tterra_cw50_counter) { --tterra_cw50_counter; return; }
    tterra_cw50_counter=3;
    p=tterra_cw50_first;
    tterra_cw50_flags[2]=tterra_cw50_flags[1]=tterra_cw50_flags[0]=0;
    while (p) {
        next=p->next;
        if (p->flags & 0x40000u) {
            if (next) next->prev=p->prev;
            if (p->prev) p->prev->next=next;
            else tterra_cw50_first=next;
            p->flags &= 0xffffu;
            if (p->handle != 0xffffffffu) tterra_cw50_destroy(p->handle);
        }
        tterra_cw50_checkpoint(p);
        p=next;
    }
    tterra_cw50_middle1(); tterra_cw50_middle2();
}
