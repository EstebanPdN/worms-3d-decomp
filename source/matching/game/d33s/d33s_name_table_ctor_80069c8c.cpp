/* GWMP8P rev0 0x80069c8c. Constructor of a game service with 44 held references, a name list, a table of
 * 128 rows of 6 names and two more names; publishes itself in a global and fills a table of 11 default flags.
 * Names are inferred. Each flag clear is written separately because the original merges 1-bit fields only. */
extern "C" void *memset(void *, int, unsigned long);
struct Obj { virtual void s0(); virtual void s1(); virtual void release(); };
struct Ref {
    Obj *p;
    Ref() : p(0) {}
    Ref &operator=(Obj *q) { if (p) p->release(); p = q; return *this; }
};
struct D33sName { char *text; D33sName(); D33sName(const D33sName &); };
struct D33sNameList { D33sNameList(); int u[5]; };
struct D33sList { D33sNameList names; int a, b, u28, c, d, e, u40, u44; unsigned f0 : 1; unsigned f1 : 1; unsigned f2 : 1; unsigned f3 : 1; unsigned f4 : 1; unsigned f5 : 1; unsigned f6 : 1; unsigned f7 : 1; unsigned u8 : 1; unsigned f9 : 1; unsigned f10 : 1; unsigned f11 : 1; unsigned u12 : 20; };
struct D33sRoot { virtual ~D33sRoot(); };
struct D33sBase : D33sRoot { D33sBase(); char u4[24]; };
struct D33sNameTable : D33sBase {
    D33sNameTable();
    ~D33sNameTable();
    Ref r28; Ref r32; Ref r36; Ref r40; Ref r44; Ref r48; Ref r52; Ref r56; Ref r60; Ref r64; Ref r68; Ref r72; Ref r76; Ref r80; Ref r84; Ref r88; Ref r92; Ref r96; Ref r100; Ref r104; Ref r108; Ref r112; Ref r116; Ref r120; Ref r124; Ref r128; Ref r132; Ref r136; Ref r140; Ref r144; Ref r148; Ref r152; Ref r156; Ref r160; Ref r164; Ref r168; Ref r172; Ref r176; Ref r180; Ref r184;
    D33sList list;
    Ref z244, z248, z252, z256; int u260;
    D33sName names[128][6];
    int count;
    D33sName a, b;
};
extern D33sNameTable *d33s_name_table_804aaabc;
extern int d33s_name_defaults_8042e700[11];
D33sNameTable::D33sNameTable()  {
    d33s_name_table_804aaabc = this;
    list.a = 10;
    list.b = 10;
    list.c = -1;
    list.d = -1;
    list.e = -1;
    list.f0 = 1;
    r184 = 0;
    list.f1 = 1;
    count = 5;
    list.f2 = 0;
    list.f3 = 0;
    list.f4 = 0;
    list.f5 = 0;
    list.f6 = 0;
    list.f7 = 0;
    list.f10 = 0;
    list.f11 = 0;
    memset(d33s_name_defaults_8042e700, 1, 44);
    d33s_name_defaults_8042e700[0] = 0;
    d33s_name_defaults_8042e700[1] = 0;
    d33s_name_defaults_8042e700[2] = 0;
    d33s_name_defaults_8042e700[3] = 0;
    d33s_name_defaults_8042e700[4] = 0;
    d33s_name_defaults_8042e700[5] = 1;
    d33s_name_defaults_8042e700[6] = 1;
    d33s_name_defaults_8042e700[7] = 1;
    d33s_name_defaults_8042e700[8] = 0;
    d33s_name_defaults_8042e700[9] = 0;
    d33s_name_defaults_8042e700[10] = 0;
    list.f9 = 0;
}
