struct K5aWormRecord { char pad0[220]; int alive; };
struct K5aCameraView { char pad0[60]; const char *name; };
struct K5aOrbit { char pad0[312]; int current; K5aCameraView **views; char pad1[500]; float blend; };
extern "C" char w3d_string_8037327c[];
extern "C" char w3d_string_803733d8[];
extern "C" char w3d_string_80373348[];
extern "C" const float w3d_f32_803733f4[];
extern "C" unsigned int w3d_message_804acffc;
extern "C" void *w3d_message_pool_804b1754;
extern "C" int w3d_auto_800fc1f0(const char **name, int *value);
extern "C" K5aWormRecord *s8_index_query_800fc6dc(int index);
extern "C" void *FUN_801613f0(void *pool, int size);
extern "C" unsigned int w3d_cached_message_id(void *cache, int create);
extern "C" void *w3d_message_int_init(void *storage, unsigned short id, int value);
extern "C" int w3d_message_post_current(void *message);
extern "C" int s8_property_write_800fc43c(const char **name, int value);
extern "C" int strcmp(const char *a, const char *b);
extern "C" int FUN_80035714(K5aOrbit *self, const char *name, float blend);

extern "C" void k5a_orbit_camera_select_80035a30(K5aOrbit *self)
{
    const char *name = w3d_string_8037327c;
    int worm;
    w3d_auto_800fc1f0(&name, &worm);
    if (worm != -1)
    {
        if (s8_index_query_800fc6dc(worm)->alive != 0)
        {
        announce:
            w3d_message_post_current(w3d_message_int_init(FUN_801613f0(w3d_message_pool_804b1754, 12), w3d_cached_message_id(&w3d_message_804acffc, 1), worm));
            return;
        }
        int index;
        worm = 0;
        index = 0;
        do
        {
            if (s8_index_query_800fc6dc(index)->alive != 0)
                goto announce;
        } while ((index = ++worm) <= 15);
    }
    const char *flag = w3d_string_803733d8;
    s8_property_write_800fc43c(&flag, 1);
    if (strcmp((*(K5aCameraView **)((char *)self->views + (self->current << 2)))->name, w3d_string_80373348) != 0)
        FUN_80035714(self, w3d_string_80373348, w3d_f32_803733f4[0]);
    self->blend = w3d_f32_803733f4[0];
}
