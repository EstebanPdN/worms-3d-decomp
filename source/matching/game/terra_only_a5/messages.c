typedef unsigned int u32;
typedef unsigned short u16;
struct List { struct Msg **begin, **end; int capacity; };
struct Entry { char name[36]; struct List list; int active; };
struct Msg { int unknown; char id[8]; int type; };
struct Entries { struct Entry *data; };
struct State { char pad[96]; u32 flags; volatile int first, second; char pad2[16]; float low, high; char pad3[32]; u32 start, end; struct Entries *entries; };
extern char cache_804ae2b8, cache_804ae2a0, cache_804ae298;
extern int id_8015f5a0(void *, int);
extern void range_800a7d18(struct State *, u16, float, float);
extern void send_800a7c24(struct State *, u16, int, int);
extern void text_800a7b24(struct State *, u16, char *);
void terra_only_a5_messages_800a7fdc(struct State *s) {
    if (s->flags & 0x800000) {
        if (s->flags & 0x1000000)
            range_800a7d18(s, id_8015f5a0(&cache_804ae2b8, 1), s->low, s->high);
        else
            range_800a7d18(s, id_8015f5a0(&cache_804ae2a0, 1), s->low, s->high);
        {
            u32 end = s->end;
            int all = (s->flags >> 21) & 1;
            u32 i = s->start;
            if (i <= end) do {
                struct Entry *entry = &s->entries->data[i];
                if (all || entry->active) {
                    struct List *list = &entry->list;
                    struct Msg **p = list->begin;
                    if (p != list->end) do {
                        struct Msg *m = *p;
                        if (m->type == 3) {
                            send_800a7c24(s, id_8015f5a0(m->id, 1), s->first, s->second);
                            text_800a7b24(s, id_8015f5a0(&cache_804ae298, 1), entry->name + 1);
                        }
                    } while (++p != list->end);
                }
            } while (++i <= end);
        }
        s->second = 0;
        s->first = 0;
        s->flags &= ~0x800000;
    }
}
