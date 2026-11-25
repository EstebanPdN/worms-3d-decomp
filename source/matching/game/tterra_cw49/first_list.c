typedef unsigned char u8;
typedef unsigned int u32;
typedef struct First First;
struct First { First *next, *prev; void *owner; u8 pad[4]; u32 flags; u8 rest[40]; u32 handle; };
extern First *tterra_cw49_first;
extern volatile u8 tterra_cw49_counter, tterra_cw49_flags[3];
extern void tterra_cw49_middle1(void), tterra_cw49_middle2(void);
extern void tterra_cw49_checkpoint(First *);
/* Restricted: marked nodes have handle -1; retained nodes have exactly
   0x80000 and a valid owner with byte 28 == 0xff. Checkpoint is a probe. */
void tterra_cw49_tick(void) {
    First *p, *next;
    if (tterra_cw49_counter) { --tterra_cw49_counter; return; }
    tterra_cw49_counter=3;
    p=tterra_cw49_first;
    tterra_cw49_flags[2]=tterra_cw49_flags[1]=tterra_cw49_flags[0]=0;
    while (p) {
        next=p->next;
        if (p->flags & 0x40000u) {
            if (next) next->prev=p->prev;
            if (p->prev) p->prev->next=next;
            else tterra_cw49_first=next;
            p->flags &= 0xffffu;
        }
        tterra_cw49_checkpoint(p);
        p=next;
    }
    tterra_cw49_middle1(); tterra_cw49_middle2();
}
