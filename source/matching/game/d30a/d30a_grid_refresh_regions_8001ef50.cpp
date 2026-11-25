// GWMP8P rev0 0x8001ef50. Rebuilds a grid layer's regions once: clears each
// item's used flag, registers a region around every player, active body and
// mark, then refreshes and removes items no longer used and marks the new
// ones. Names are inferred from the original instructions.
extern "C" void *memcpy_802eee50(void *, const void *, unsigned int, ...);
struct Vec { float x, y, z; };
struct Item { char pad[20]; int marked; int used; };
struct Items {
    Item **start, **finish;
    int size() const { return finish - start; }
    Item *&operator[](int i) { return start[i]; }
    void erase(Item **pos) {
        if (pos + 1 != finish) { Item **last = finish - 1; memcpy_802eee50(pos, pos + 1, (char *)last - (char *)pos); }
        finish--;
    }
};
struct Player { char pad[28]; Vec pos; };
struct Settings { char pad[388]; float radius; };
struct Holder { Settings *data; };
struct Grid { char pad[32]; Items items; char pad2[8]; int ready; char pad3[52]; float base; };
struct VecList { Vec *start, *finish; int size() const { return finish - start; } };
extern int w3d_players_804aab4c;
extern VecList *w3d_marks_804aa754;
extern char w3d_settings_803eb658[];
extern "C" int w3d_player_list_weapon_count_8008c534(void *);
extern "C" Player *s19_lookup_slot_8008c548(void *, int);
extern "C" void w3d_register_8001f394(Grid *, const Vec *, float);
extern "C" int w3d_auto_800153dc(int);
extern "C" Vec *w3d_auto_80015588(int);
extern "C" void * w3d_auto_800fc330(void *, Holder *);
extern "C" void cc26a_grid_refresh_8001f904(Grid *, Item *);
extern "C" void cc26a_grid_mark_8001f4f4(Grid *, Item *);
extern "C" void w3d_auto_80015264(Item *);
extern "C" void w3d_d30a_grid_refresh_regions_8001ef50(Grid *self)
{
    if (self->ready) return;
    for (int i = 0; i < self->items.size(); i++) self->items[i]->used = 0;
    int n = w3d_player_list_weapon_count_8008c534((void *)w3d_players_804aab4c);
    for (int p = 0; p < n; p++) {
        Vec v = s19_lookup_slot_8008c548((void *)w3d_players_804aab4c, p)->pos;
        w3d_register_8001f394(self, &v, self->base + 9.0f);
    }
    for (int b = 0; b < 16; b++) {
        if (w3d_auto_800153dc(b)) w3d_register_8001f394(self, w3d_auto_80015588(b), self->base + 10.0f);
    }
    Holder h;
    w3d_auto_800fc330(w3d_settings_803eb658, &h);
    float radius = h.data->radius;
    int c = w3d_marks_804aa754->size();
    for (int m = 0; m < c; m++)
        w3d_register_8001f394(self, &w3d_marks_804aa754->start[m], radius + self->base + 30.0f);
    for (int k = 0; k < self->items.size(); k++) {
        Item *it = self->items[k];
        if (!it->used) {
            cc26a_grid_refresh_8001f904(self, it);
            self->items.erase(&self->items[k]);
            w3d_auto_80015264(it);
            k--;
        } else if (!it->marked) {
            cc26a_grid_mark_8001f4f4(self, it);
        }
    }
    self->ready = 1;
}
