/* Girder preview initialization (0x80091ee0): from the prototype at +532 takes the array
 * data pointers (+400, +396, +428 with its end, +440, +436, +432) and bytes (+453, +452,
 * +449, +448), locks the arrays +480 and +476 for writing (0x801ef048 when shared), keeps
 * +424, uses the holder array at +464 or builds through 0x800919d4, copies the four rows
 * +336, +324, +312, +300 and the offsets +412, +404, fills sixteen corner vectors at +2572
 * from the half size +444 and flags the name "TRANS" (0x802ef234). Field names are
 * inferred from the original instructions. Owns the string and the zero literal at
 * 0x8037e87c. */
struct Vec3 {
    float x, y, z;
    void Set(float a, float b, float c) { Vec3 *p = this; x = a; p->y = b; p->z = c; }
};
struct Vec2 { float x, y; };
struct ArrayHeader {
    char unknown00[4];
    unsigned short refs;  /* +4 */
    char unknown06[18];
    int count;            /* +24 */
    unsigned short gen;   /* +28 */
    char unknown30[2];
    char data[1];         /* +32 */
};
struct Array { ArrayHeader *header; };
extern "C" void *w3d_array_ref_lock_801ef048(Array *, int, int, int);
inline void *Lock(Array *a, int count, int size, int flag)
{
    ArrayHeader *h = a->header;
    if (h->refs == 1) {
        h->gen++;
        return h->data;
    }
    return w3d_array_ref_lock_801ef048(a, count, size, flag);
}
struct Holder { char unknown00[20]; ArrayHeader *array; };
struct Proto {
    char unknown00[36];
    const char *name;       /* +36 */
    char unknown40[260];
    Vec3 rowD;              /* +300 */
    Vec3 rowC;              /* +312 */
    Vec3 rowB;              /* +324 */
    Vec3 rowA;              /* +336 */
    char unknown348[48];
    ArrayHeader *b396;      /* +396 */
    ArrayHeader *b400;      /* +400 */
    Vec2 off404;            /* +404 */
    Vec2 off412;            /* +412 */
    char unknown420[4];
    int u424;               /* +424 */
    ArrayHeader *table;     /* +428 */
    ArrayHeader *a432;      /* +432 */
    ArrayHeader *a436;      /* +436 */
    ArrayHeader *a440;      /* +440 */
    float half;             /* +444 */
    unsigned char b448, b449, b450x, b451x, b452, b453;
    char unknown454[10];
    Holder *holder;         /* +464 */
    char unknown468[8];
    Array lock476;          /* +476 */
    Array lock480;          /* +480 */
};
struct Preview {
    int unknown00;
    char *p4;               /* +4 */
    char *p8;               /* +8 */
    char unknown12[16];
    char *p28;              /* +28 */
    char unknown32[24];
    int isTran;             /* +56 */
    char unknown60[184];
    int x244;               /* +244 */
    char unknown248[140];
    void *l388;             /* +388 */
    void *l392;             /* +392 */
    char *p396;             /* +396 */
    Vec3 rowA, rowB, rowC, rowD; /* +400 */
    Vec2 off448, off456;    /* +448 */
    char unknown464[16];
    unsigned char b480, b481;
    char unknown482[2];
    char *tableBegin;       /* +484 */
    char *tableEnd;         /* +488 */
    unsigned char b492, b493;
    char unknown494[18];
    char *p512;             /* +512 */
    char *p516;             /* +516 */
    char unknown520[12];
    Proto *proto;           /* +532 */
    int z536;               /* +536 */
    char unknown540[1944];
    int u2484;              /* +2484 */
    char unknown2488[84];
    Vec3 grid[17];          /* +2572 */
};
extern "C" void w3d_preview_build_800919d4(Preview *);
extern "C" int strcmp_802ef234(const char *, const char *);
extern "C" void w3d_d26b_preview_init_80091ee0(Preview *self)
{
    {
        Proto *p = self->proto;
        self->p512 = p->b400->data;
        self->p516 = p->b396->data;
        ArrayHeader *t = p->table;
        int n = t->count;
        int *d = (int *)t->data;
        self->tableBegin = (char *)d;
        self->tableEnd = (char *)(d + n);
        self->b492 = p->b453;
        self->b493 = p->b452;
        self->l388 = Lock(&p->lock480, p->lock480.header->count, 1, 2);
    }
    {
        Proto *p = self->proto;
        self->l392 = Lock(&p->lock476, p->lock476.header->count, 1, 2);
    }
    {
        Proto *p = self->proto;
        self->u2484 = p->u424;
        if (self->x244 != 0 || p->holder == 0) w3d_preview_build_800919d4(self);
        else self->p396 = p->holder->array->data;
    }
    self->rowA = self->proto->rowA;
    self->rowB = self->proto->rowB;
    self->rowC = self->proto->rowC;
    self->rowD = self->proto->rowD;
    {
        Proto *p = self->proto;
        self->off448 = p->off412;
        self->off456 = p->off404;
        self->b481 = p->b449;
        self->b480 = p->b448;
        float h = p->half;
        float m = -h;
    self->grid[0].Set(m, 0.0f, 0.0f);
    self->grid[1].Set(m, 0.0f, m);
    self->grid[2].Set(0.0f, 0.0f, m);
    self->grid[3].Set(h, 0.0f, m);
    self->grid[4].Set(h, 0.0f, 0.0f);
    self->grid[5].Set(h, 0.0f, h);
    self->grid[6].Set(0.0f, 0.0f, h);
    self->grid[7].Set(m, 0.0f, h);
    self->grid[8].Set(0.0f, 0.0f, m);
    self->grid[9].Set(h, 0.0f, h);
    self->grid[10].Set(m, 0.0f, h);
    self->grid[11].Set(0.0f, 0.0f, h);
    self->grid[12].Set(h, 0.0f, m);
    self->grid[13].Set(m, 0.0f, 0.0f);
    self->grid[14].Set(m, 0.0f, m);
    self->grid[15].Set(h, 0.0f, 0.0f);
    }
    if (strcmp_802ef234(self->proto->name, "TRANS") == 0) self->isTran = 1; else self->isTran = 0;
    {
        Proto *p = self->proto;
        self->p4 = p->a440->data;
        self->p8 = p->a436->data;
        self->p28 = p->a432->data;
        self->z536 = 0;
    }
}
