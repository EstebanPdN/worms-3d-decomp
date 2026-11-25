// Gauge panel setup (Worms 3D GameCube PAL, 0x80265d34).
//
// Forwards the context service (+52 of 0x80165254) to the panel base at +28
// (0x802b0b84), copies a setting from the object at +40 and reads the
// "FE.BorderThickness" property (0x800fc1b0) through a handle. The border size
// becomes +556 and, scaled by 0.7, +560. The limits at settings +128 and +124
// are clamped to at least 0 and at most 100 and written back; +548 and +552
// start at the lower limit. It then runs 0x802663dc, activates the panel, runs
// 0x802672cc, reads the optional named value (settings +120) with watcher
// 0x8026836c at +564, calls slot 23 of the optional root service +108 for the
// target name (settings +116), applies the value (default 0.42857146) through
// 0x802683b8, subscribes to the messages 0x804b0aac and 0x804b0ab4 with
// handler slots +696 and +700, resets with 0x80268568 and stores the context
// service in +492. The handle is released on exit.
//
// The handle is one word with a user copy constructor, as in
// d23a_worm_aim_start_80026e74 (same property reader and handle family): the
// original places the first key at sp+16 right after the handle at sp+8, and
// never writes sp+12. Message ids are temporaries bound to a const reference, so
// they take slots after the earlier temporaries (sp+32, sp+34). Built with
// -mps-float (one saved FPR in a non-leaf function). Field roles are inferred.
struct GaugeObject;
struct GaugeObjectVtable {
    void *unknown00[4];
    void (*release)(GaugeObject *);  // +16
    void (*finish)(GaugeObject *);   // +20
};
struct GaugeObject { GaugeObjectVtable *vtable; };
struct GaugeHandle {
 GaugeHandle(const GaugeHandle &);
    GaugeObject *value;
    GaugeHandle() : value(0) {}
    ~GaugeHandle() {
        if (value) {
            value->vtable->release(value);
        }
    }
};
struct GaugeKey {
    const char *name;
    GaugeKey(const char *s) : name(s) {}
};
struct GaugeMessage {
    unsigned short id;
    unsigned short state;
    const char *name;
};
struct GaugeSettings {
    char unknown00[116];
    const char *target;     // +116
    const char *valueName;  // +120
    float upperLimit;       // +124
    float lowerLimit;       // +128
    char unknown132[20];
    int setting152;         // +152
    int setting156;         // +156
};
struct GaugeContext {
    char unknown00[52];
    void *service;          // +52
};
struct RootService;
struct RootServiceVtable {
    void *unknown00[23];
    void (*attach)(RootService *, const char *, void *);  // +92
};
struct RootService { RootServiceVtable *vtable; };
struct GaugeRoot {
    char unknown00[108];
    RootService *service;   // +108
};
typedef void (*GaugePanelCall)(void *, int);
struct Gauge {
    char unknown00[28];
    char panel[12];         // +28
    GaugeSettings *settings;  // +40
    char unknown44[132];
    int active;             // +176
    char unknown180[28];
    GaugePanelCall *panelCalls;  // +208
    char unknown212[220];
    int setting432;         // +432
    int setting436;         // +436
    char unknown440[52];
    void *service;          // +492
    char unknown496[44];
    float lowerLimit;       // +540
    float upperLimit;       // +544
    float value548;         // +548
    float value552;         // +552
    float border;           // +556
    float innerBorder;      // +560
    char watcher[132];      // +564
    char handler696[4];     // +696
    char handler700[28];    // +700
    GaugeObject *attached;  // +728
    GaugeObject *named;     // +732
};
extern "C" {
void *fn_80165254();
void fn_802b0b84(void *, void *, void *);
void fn_802663dc(Gauge *);
void fn_802672cc(Gauge *);
void fn_800fd62c(const void *, void *, void *, void *);
void fn_80268568(Gauge *, int);
int fn_8026836c(void *, void *);
int fn_800fc1b0(const GaugeKey &, void *);
void *fn_80342a74(void *);
float fn_80178df0(void *);
void fn_802683b8(Gauge *, float);
unsigned short fn_8015f5a0(void *, int);
int fn_80162024(Gauge *, const unsigned short &, void *);
}
extern const char border_803cb5a0[];
extern GaugeRoot *root_804b1788;
extern GaugeMessage message_804b0aac, message_804b0ab4;
inline const float &maximum(const float &a, const float &b) { return a < b ? b : a; }
inline const float &minimum(const float &a, const float &b) { return b < a ? b : a; }
extern "C" void w3d_d24k_gauge_setup_80265d34(Gauge *self) {
    GaugeContext *context = (GaugeContext *)fn_80165254();
    void *panel = self->panel;
    fn_802b0b84(panel, self, context->service);
    GaugeSettings *settings = self->settings;
    self->setting436 = settings->setting152;
    GaugeHandle border;
    GaugeKey key(border_803cb5a0);
    fn_800fc1b0(key, &border);
    self->border = fn_80178df0(fn_80342a74(border.value));
    self->innerBorder = fn_80178df0(fn_80342a74(border.value)) * 0.699999988079071f;
    self->lowerLimit = settings->lowerLimit;
    self->upperLimit = settings->upperLimit;
    self->lowerLimit = maximum(self->lowerLimit, float(0.0f));
    settings->lowerLimit = self->lowerLimit;
    self->upperLimit = minimum(self->upperLimit, float(100.0f));
    settings->upperLimit = self->upperLimit;
    self->value552 = self->value548 = self->lowerLimit;
    fn_802663dc(self);
    self->active = 1;
    self->panelCalls[5](panel, 0);
    self->setting432 = settings->setting156;
    fn_802672cc(self);
    const char **name = &settings->valueName;
    float value = 0.4285714626312256f;
    if (*(unsigned short *)(*name - 4)) {
        if (fn_800fc1b0(GaugeKey(*name), &self->named) >= 0) {
            fn_800fd62c(name, (void *)fn_8026836c, self, self->watcher);
            value = fn_80178df0(fn_80342a74(self->named));
        }
    }
    const char *target = settings->target;
    if (*(unsigned short *)(target - 4)) {
        RootService *service = root_804b1788->service;
        if (service) {
            service->vtable->attach(service, target, &self->attached);
        }
    }
    fn_802683b8(self, value);
    GaugeObject *attached = self->attached;
    if (attached) {
        attached->vtable->finish(attached);
    }
    fn_80162024(self, fn_8015f5a0(&message_804b0aac, 1), self->handler696);
    fn_80162024(self, fn_8015f5a0(&message_804b0ab4, 1), self->handler700);
    fn_80268568(self, 0);
    self->service = ((GaugeContext *)fn_80165254())->service;
}
