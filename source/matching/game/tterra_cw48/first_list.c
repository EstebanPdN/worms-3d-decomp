typedef unsigned char u8;
typedef unsigned int u32;
typedef struct First First;
struct First { First *next, *prev; u8 pad[8]; u32 flags; u8 rest[40]; u32 handle; };
extern First *tterra_cw48_first;
extern volatile u8 tterra_cw48_counter, tterra_cw48_flags[3];
extern void tterra_cw48_middle1(void), tterra_cw48_middle2(void);
/* This restricted hypothesis accepts only marked nodes with handle == -1. */
void tterra_cw48_tick(void) {
    First *p, *next;
    if (tterra_cw48_counter) { --tterra_cw48_counter; return; }
    tterra_cw48_counter=3;
    p=tterra_cw48_first;
    tterra_cw48_flags[2]=tterra_cw48_flags[1]=tterra_cw48_flags[0]=0;
    while (p) {
        next=p->next;
        if (p->flags & 0x40000u) {
            if (next) next->prev=p->prev;
            if (p->prev) p->prev->next=next;
            else tterra_cw48_first=next;
            p->flags &= 0xffffu;
        }
        p=next;
    }
    tterra_cw48_middle1(); tterra_cw48_middle2();
}
