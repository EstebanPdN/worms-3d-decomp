// d24d: 0x80162f0c (928 bytes). Build the handle tables from settings: read the four "Core.*"
// settings MessageBufferSize, MaxTasks, MaxLogicTasks, MaxServiceTasks (0x80206920) with
// defaults 0x8000, 256, half of the second, and 32. The first sizes the object at +32 (0x8016136c). Two 88-byte tables are created (+20,
// +24; +28 starts as the first): each has an array of 36-byte slots (0x801fe220 with
// an 8-byte count cookie, witnessed by the store at -8; hence the destructor
// declaration), three index ranges (0x8034aa64), two 8 KB buffers and three lists
// (0x8034ae84). d24d_HandleSlot 0's id is 0x0babe000. Returns 0. Names are inferred.
extern void *operator new(unsigned);
extern void *operator new[](unsigned);
extern "C" int d24d_setting_read_80206920(const char *, unsigned *);
extern const char d24d_setting_803a4a7c[], d24d_setting_803a4a94[], d24d_setting_803a4aa4[], d24d_setting_803a4ab8[];
struct d24d_HandleSlot {
    char pad[6]; unsigned short a, b, c; int d; unsigned short e, f; int id; char pad2[8]; int g;
    d24d_HandleSlot() { d = 0; e = 0; a = 0; b = 0; c = 0; f = 0; g = 0; }
    ~d24d_HandleSlot();
};
struct d24d_HandleBuffer { char *base, *end, *top;
    d24d_HandleBuffer(unsigned n) { char *p = (char *)operator new[](n); base = p; end = p + n; top = p; } };
struct d24d_TableMember { d24d_TableMember(); char pad[12]; };
struct d24d_HandleTable;
extern "C" void d24d_table_range_8034aa64(d24d_HandleTable *, int, int, unsigned);
extern "C" void d24d_table_list_8034ae84(void *, d24d_HandleTable *);
struct d24d_HandleTable {
    d24d_HandleSlot *slots; int f4; char pad[6]; unsigned short h14, h16, h18, h20; char pad2[2]; d24d_HandleBuffer *b24; d24d_HandleBuffer *b28; int f32, f36;
    char lists[36];
    d24d_TableMember m76;
    d24d_HandleTable(unsigned n, unsigned b, unsigned c) {
        d24d_HandleSlot *sl = new d24d_HandleSlot[n];
        slots = sl;
        unsigned t = c + 1;
        h18 = 1; h16 = t + b; h20 = n; h14 = t; sl->c = 0; sl->b = 0; sl->id = 0xbabe000;
        d24d_table_range_8034aa64(this, 0, 1, (unsigned short)t);
        d24d_table_range_8034aa64(this, 1, h14, h16);
        d24d_table_range_8034aa64(this, 2, h16, h20);
        b24 = new d24d_HandleBuffer(8192);
        b28 = new d24d_HandleBuffer(8192);
        f32 = 0; f36 = 0; f4 = 0;
        for (unsigned i = 0; i <= 2; i++) d24d_table_list_8034ae84(lists + i * 12, this);
    }
};
struct d24d_HandleTables { char pad[20]; d24d_HandleTable *t20; d24d_HandleTable *t24; d24d_HandleTable *t28; char limit[16]; int f48, f52, f56; };
extern "C" void d24d_limit_init_8016136c(void *, unsigned);
extern "C" int d24d_handle_tables_init_80162f0c(d24d_HandleTables *self) {
    unsigned a, b, c, d;
    a = 0x8000;
    d24d_setting_read_80206920(d24d_setting_803a4a7c, &a);
    d24d_limit_init_8016136c(self->limit, a);
    b = 256;
    d24d_setting_read_80206920(d24d_setting_803a4a94, &b);
    c = b >> 1;
    d24d_setting_read_80206920(d24d_setting_803a4aa4, &c);
    d = 32;
    d24d_setting_read_80206920(d24d_setting_803a4ab8, &d);
    self->t20 = new d24d_HandleTable(b, c, d);
    self->t24 = new d24d_HandleTable(b, c, d);
    self->t28 = self->t20;
    self->f56 = 0; self->f48 = 0; self->f52 = 0;
    return 0;
}
