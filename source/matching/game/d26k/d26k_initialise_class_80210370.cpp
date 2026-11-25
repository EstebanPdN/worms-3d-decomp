// Class initialisation (Worms 3D GameCube PAL, 0x80210370).
// 
// Initialises a registered class once: first its parent (a negative result
// propagates), then moves it from the pending list 0x804b1908 to the initialised
// list 0x804b1904, traces its name, size and level, runs its optional callback
// at +28 and marks it initialised. The flags word at +32 is read as bit fields
// (whole-word load with rlwinm/andis/oris in the original).

struct ClassInfo {
    int unknown00;
    ClassInfo *next;
    char pad08[20 - 8];
    ClassInfo *parent;
    char pad18[28 - 24];
    int (*initialise)(ClassInfo *);
    unsigned reserved0 : 10;
    unsigned initialised : 1;
    unsigned reserved1 : 1;
    unsigned level : 4;
    unsigned reserved2 : 16;
};
extern ClassInfo *global_804b1908;
extern ClassInfo *global_804b1904;
extern char global_804b0640;
extern const char text_803b356c[];
extern "C" const char *name_801ffea8(ClassInfo *);
extern "C" int size_80200050(ClassInfo *);
extern "C" void trace_80347324(void *, const char *, ...);
extern "C" void announce_8021020c(int, ClassInfo *);
extern "C" int w3d_d26k_initialise_class_80210370(ClassInfo *c) {
    if (c->initialised) return 0;
    ClassInfo *parent = c->parent;
    if (parent != 0 && parent != c) {
        int r = w3d_d26k_initialise_class_80210370(parent);
        if (r < 0) return r;
    }
    ClassInfo *prev = 0;
    for (ClassInfo *p = global_804b1908; p != 0; prev = p, p = p->next) {
        if (p == c) {
            if (prev != 0) prev->next = c->next;
            else global_804b1908 = c->next;
            break;
        }
    }
    c->next = global_804b1904;
    global_804b1904 = c;
    const char *name = name_801ffea8(c);
    int size = size_80200050(c);
    trace_80347324(&global_804b0640, text_803b356c, name, size, c->level);
    if (c->initialise != 0) {
        int r = c->initialise(c);
        if (r < 0) return r;
    }
    c->initialised = 1;
    announce_8021020c(0, c);
    return 0;
}
