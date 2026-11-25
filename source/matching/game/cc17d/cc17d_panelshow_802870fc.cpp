// cc17d: visibility update at 0x802870fc. Observed: 0/1 words at +140 and
// +176; interface pointers at +244, +248 and +252 receive vtable slot +88
// calls with a 0/1 argument.  Meanings inferred.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
struct Cc17dPanel {
    char pad000[140];
    int ready;                         // +140, 0/1
    char pad090[176 - 144];
    int alt;                           // +176, 0/1
    char pad0b4[244 - 180];
    void *a;                           // +244
    void *b;                           // +248
    void *c;                           // +252
};
static inline void cc17d_show(void *p, int on)
{
    if (p)
        VCALL(p, void (*)(void *, int), 88)(p, on);
}
extern "C" void w3d_cc17d_panel_update_802870fc(Cc17dPanel *self)
{
    bool alt = self->alt;
    bool ready = self->ready;
    cc17d_show(self->a, ready ? alt ^ 1 : (self->c == 0) & 1);
    cc17d_show(self->b, ready && alt);
    cc17d_show(self->c, !ready);
}
