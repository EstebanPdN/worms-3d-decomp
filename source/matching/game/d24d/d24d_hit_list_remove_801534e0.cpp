// d24d: 0x801534e0 (236 bytes). Remove an actor from a worm's 16-slot hit list
// (+1280, ends at -1): resolve the id (0x800a830c), ignore the worm itself (+584)
// and owners that do not match (0x8014c488). On a hit post a message with the worm
// id, shift the remaining slots down and set the last slot (+1340) to -1.
extern "C" int d24d_actor_id_800a830c(void *);
extern "C" int d24d_owner_matches_8014c488(void *);
extern "C" void *d24d_arena_alloc_801613f0(void *, int);
extern "C" unsigned d24d_message_id_8015f5a0(int *, int);
extern "C" void *d24d_message_init_800a82f0(void *, unsigned short, int);
extern "C" int d24d_message_post_8016239c(void *);
extern void *d24d_arena_804b1754;
extern int d24d_removed_key_804afc70;
struct d24d_WormActor { char pad[584]; int current; char pad2[692]; int list[16]; };
extern "C" void d24d_hit_list_remove_801534e0(d24d_WormActor *self, int arg) {
    int id = d24d_actor_id_800a830c((void *)arg);
    if (id == self->current) return;
    if (!d24d_owner_matches_8014c488(self)) return;
    for (int i = 0; i <= 15; i++) {
        if (self->list[i] == -1) return;
        if (self->list[i] == id) {
            void *m = d24d_arena_alloc_801613f0(d24d_arena_804b1754, 12);
            d24d_message_post_8016239c(d24d_message_init_800a82f0(m, d24d_message_id_8015f5a0(&d24d_removed_key_804afc70, 1), self->current));
            for (int j = i; j <= 14; j++) self->list[j] = self->list[j + 1];
            self->list[15] = -1;
            return;
        }
    }
}
