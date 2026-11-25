// GWMP8P rev0 0x800a6740. Builds the input modes table of the input object:
// a Holder with fifteen named Mode records, each filled by its action setup,
// then the message subscriptions. Global new explains the holder's store
// order: the result does not alias, so the scheduler moves self->holder
// ahead of h->modes.
extern "C" char *copy_802ef2fc(char *, const char *);
extern "C" void *heap_802098d8(void *, unsigned);
extern int heap_804ae280;
struct Mode {
    char pad; char name[51];
    Mode();
    ~Mode();
    void *operator new[](unsigned n) { return heap_802098d8(&heap_804ae280, n); }
};
struct Words { int *begin, *end, *capacity; Words() { capacity = 0; end = 0; begin = 0; } };
struct Holder {
    Mode *modes; Words a, b;
    Holder() {}
};
typedef long long Callback;
struct Input;
extern void *service_804b17f0;
extern "C" int attach_8015fb6c(void *, Input *, void *, int, Callback *);
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
extern MessageCache m_804ae2d0, m_804ae2d8, m_804ae2e8, m_804ae2f0;
extern "C" unsigned short cached_8015f5a0(MessageCache *, int);
extern "C" int subscribe_80162024(Input *, const unsigned short &, void *);
struct Input { char unknown0[28]; char slot28[80]; char s108[4], s112[4], s116[4], s120[4]; char unknown124[48]; Holder *holder; };
extern "C" void menu_800524d4(Input *, Mode *);
extern "C" void camera_80056178(Input *, Mode *);
extern "C" void aim_80054434(Input *, Mode *);
extern "C" void worm_80054d24(Input *, Mode *);
extern "C" void move_80058a68(Input *, Mode *);
extern "C" void rope_80058f18(Input *, Mode *);
extern "C" void girder_80059ce4(Input *, Mode *);
extern "C" void fly_8005c35c(Input *, Mode *);
extern "C" void view_8005da24(Input *, Mode *);
extern "C" void fire_80058804(Input *, Mode *);
extern "C" void fireu_8005dec0(Input *, Mode *);
extern "C" void crate_8005e35c(Input *, Mode *);
extern "C" void spect_8005e4a4(Input *, Mode *);
extern "C" void quit_8005fbc0(Input *, Mode *);
inline void Build(Input *self, int n) {
    Holder *h = new Holder;
    Mode *m = new Mode[n];
    h->modes = m; self->holder = h; copy_802ef2fc(m->name, "Menu");
}
extern "C" void d42h_input_modes_setup_800a6740(Input *self) {
    Callback cb = 0;
    attach_8015fb6c(service_804b17f0, self, self->slot28, 0, &cb);
    Build(self, 15);
    copy_802ef2fc(self->holder->modes[1].name, "InGame");
    copy_802ef2fc(self->holder->modes[2].name, "WormAiming");
    copy_802ef2fc(self->holder->modes[3].name, "WormFirstPersonAiming");
    copy_802ef2fc(self->holder->modes[4].name, "WormMoving");
    copy_802ef2fc(self->holder->modes[5].name, "WormRoping");
    copy_802ef2fc(self->holder->modes[6].name, "UtilityGirder");
    copy_802ef2fc(self->holder->modes[7].name, "Flying");
    copy_802ef2fc(self->holder->modes[8].name, "CameraSelect");
    copy_802ef2fc(self->holder->modes[9].name, "Fire");
    copy_802ef2fc(self->holder->modes[10].name, "UtilityFire");
    copy_802ef2fc(self->holder->modes[11].name, "CrateChuteRelease");
    copy_802ef2fc(self->holder->modes[12].name, "Spectator");
    copy_802ef2fc(self->holder->modes[13].name, "NetworkSpectator");
    copy_802ef2fc(self->holder->modes[14].name, "AttractMode");
    menu_800524d4(self, &self->holder->modes[0]);
    camera_80056178(self, &self->holder->modes[1]);
    aim_80054434(self, &self->holder->modes[2]);
    worm_80054d24(self, &self->holder->modes[3]);
    move_80058a68(self, &self->holder->modes[4]);
    rope_80058f18(self, &self->holder->modes[5]);
    girder_80059ce4(self, &self->holder->modes[6]);
    fly_8005c35c(self, &self->holder->modes[7]);
    view_8005da24(self, &self->holder->modes[8]);
    fire_80058804(self, &self->holder->modes[9]);
    fireu_8005dec0(self, &self->holder->modes[10]);
    crate_8005e35c(self, &self->holder->modes[11]);
    spect_8005e4a4(self, &self->holder->modes[12]);
    quit_8005fbc0(self, &self->holder->modes[14]);
    subscribe_80162024(self, cached_8015f5a0(&m_804ae2d0, 1), self->s108);
    subscribe_80162024(self, cached_8015f5a0(&m_804ae2d8, 1), self->s112);
    subscribe_80162024(self, cached_8015f5a0(&m_804ae2e8, 1), self->s116);
    subscribe_80162024(self, cached_8015f5a0(&m_804ae2f0, 1), self->s120);
}
