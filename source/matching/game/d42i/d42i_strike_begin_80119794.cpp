// d42i: 0x80119794. Starts a strike target object once: reads the strike
// target position from settings or the owner, posts the placement and target
// messages, or spawns the marker and posts the start messages.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Descriptor_80178474 {
    void *value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Key { const char *text; };
struct Info { char u0[80]; Vec spawn; char u92[168]; int moved; };
struct Self { char u0[36]; int started; char u40[4]; void *p44; };
struct Message { unsigned short id; void *vt; };
extern char s_8039ab14[], s_8039ab2c[], s_8039ab90[], s_8039abb0[];
extern char vt_8040db38[];
extern void *arena_804b1754;
extern void *ai_804b1760;
extern int c_804af36c, c_804af334, c_804af364, c_804af34c, c_804af38c, c_804af374;
extern "C" {
void *val_80178c48(void *);
Info *info_800fc6dc(int);
int cond_80119aa8(Self *);
int readv_800fc2f0(Key *, Vec *);
int act_80020834(void *);
Info *hand_800fc710(int, Descriptor_80178474 *);
void *alloc_801613f0(void *, int);
int id_8015f5a0(int *, int);
Message *msgp_800a82f0(void *, unsigned short, void *);
Message *msgv_80126000(void *, unsigned short, const Vec *);
Message *msgi_80125fdc(void *, unsigned short, int);
int post_8016239c(Message *);
void *place_800e5ca4(Vec *, const char *, float, int);
}
inline void postPlain(int *cache) {
    Message *m = (Message *)alloc_801613f0(arena_804b1754, 8);
    m->id = id_8015f5a0(cache, 1);
    m->vt = vt_8040db38;
    post_8016239c(m);
}
extern "C" void d42i_strike_begin_80119794(Self *self) {
    if (self->started == 0) {
        self->started = 1;
        void *obj = val_80178c48(self->p44);
        Info *info = info_800fc6dc((int)obj);
        Vec v;
        if (cond_80119aa8(self)) {
            Key k;
            k.text = s_8039ab14;
            readv_800fc2f0(&k, &v);
        } else {
            v = info->spawn;
        }
        if (ai_804b1760 && act_80020834(ai_804b1760)) {
            Key k;
            k.text = s_8039ab2c;
            readv_800fc2f0(&k, &v);
            { Vec a = v; }
        }
        { Vec b = v; }
        if (info->moved) {
            {
                Descriptor_80178474 d;
                hand_800fc710((int)obj, &d)->spawn = v;
            }
            {
                void *m = alloc_801613f0(arena_804b1754, 12);
                post_8016239c(msgp_800a82f0(m, id_8015f5a0(&c_804af36c, 1), obj));
            }
            {
                void *m = alloc_801613f0(arena_804b1754, 20);
                post_8016239c(msgv_80126000(m, id_8015f5a0(&c_804af334, 1), &v));
            }
            {
                Descriptor_80178474 d;
                hand_800fc710((int)obj, &d)->moved = 0;
            }
        } else {
            Vec start;
            {
                void *m = alloc_801613f0(arena_804b1754, 20);
                post_8016239c(msgv_80126000(m, id_8015f5a0(&c_804af334, 1), &v));
            }
            {
                void *m = alloc_801613f0(arena_804b1754, 12);
                post_8016239c(msgi_80125fdc(m, id_8015f5a0(&c_804af364, 1), 47));
            }
            postPlain(&c_804af34c);
            Key k;
            k.text = s_8039ab90;
            readv_800fc2f0(&k, &start);
            place_800e5ca4(&start, s_8039abb0, 0.0f, 0);
            postPlain(&c_804af38c);
        }
        postPlain(&c_804af374);
    }
}
