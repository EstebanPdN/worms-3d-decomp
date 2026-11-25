// Shut down the resource pools, GWMP8P rev0 0x8017c26c. If the owner is active:
// pumps 128 channels through its virtual slot, flushes, and when any of the six
// pools reports entries in use, walks the 1920 slots; a busy slot's name string
// is copied and its use count raised, then the copy is released. Flushes again.
// Then clears the active bit, stops the owner and resizes every pool to zero.
// Virtual slot meanings are inferred; offsets come from the original.
extern "C" void fn_8020c5c0(void *);
extern "C" unsigned short *fn_80341884(void *);
struct Str {
    char *text;
    Str(const Str &o) { fn_8020c5c0(this); text = o.text; ++*fn_80341884(this); }
    ~Str();
};
extern "C" void fn_8020c5c4(Str *);
extern "C" void fn_80341588(Str *);
inline Str::~Str() { fn_8020c5c4(this); fn_80341588(this); }
struct Slot {
    virtual void s8(); virtual void s12(); virtual void s16(); virtual void s20(); virtual void s24(); virtual void s28(); virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52(); virtual void s56(); virtual void s60(); virtual void s64();
    virtual const Str *s68();
    virtual void s72(); virtual void s76();
    virtual int busy();
};
struct H { Slot *p; Slot *operator->() const { return p; } Slot *get() const { return p; } };
struct OwnerBase {
    virtual void s8(); virtual void s12(); virtual void s16(); virtual void s20(); virtual void s24(); virtual void s28(); virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52();
    virtual void stop();
    virtual void s60(); virtual void s64();
    virtual void flush();
    virtual void pump(unsigned char *counter, int n);
};
struct Owner : OwnerBase {
    char u4[16];
    int active : 1;
    H slots[1920];
};
extern "C" int fn_80170b18();
extern "C" int fn_8017f52c();
extern "C" int fn_80174528();
extern "C" int fn_80187754();
extern "C" int fn_8018a7ec();
extern "C" int fn_801829c4();
extern "C" int fn_801709b0(int);
extern "C" int fn_8017f3b8(int);
extern "C" int fn_801743b4(int);
extern "C" int fn_801875e0(int);
extern "C" int fn_8018a678(int);
extern "C" int fn_80182850(int);
extern "C" int fn_80183d48(int);

extern "C" int d29j_shut_down_pools_8017c26c(Owner *self)
{
    if (self->active) {
        unsigned char i = 0;
        do {
            self->pump(&i, 1);
            i++;
        } while (!(i & 128));
        self->flush();
        int a = fn_80170b18();
        int b = fn_8017f52c();
        int c = fn_80174528();
        int d = fn_80187754();
        int e = fn_8018a7ec();
        if (a + b + c + d + e + fn_801829c4()) {
            for (unsigned short k = 0; k <= 1919; k++) {
                if (self->slots[k].get() && self->slots[k]->busy()) {
                    self->slots[k]->busy();
                    Str s(*self->slots[k]->s68());
                }
            }
            self->flush();
        }
        unsigned char j = 0;
        do { j++; } while (!(j & 128));
        }
    self->active = 0;
    self->stop();
    fn_801709b0(0);
    fn_8017f3b8(0);
    fn_801743b4(0);
    fn_801875e0(0);
    fn_8018a678(0);
    fn_80182850(0);
    fn_80183d48(0);
    return 0;
}

