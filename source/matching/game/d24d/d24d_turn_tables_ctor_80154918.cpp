// d24d: 0x80154918 (400 bytes). Turn table constructor: base 0x801628b0, vtable
// 0x80410f40, null references at +28..+48 and +200..+308, empty team lists (+52)
// and queues (+100), registers itself in the global 0x804ab400, then the team
// tables (+148 = 0, +164 = -1), 16 actor slots (+312 = -1) and flags (+376, +380,
// +384 = 1; +388, +412, +416, +420 = 0). A real polymorphic class places the
// vtable store right after the base constructor; the undefined virtual keeps
// the vtable external. Field names are inferred.
struct d24d_ZeroList { int *start, *finish, *end; d24d_ZeroList() { end = 0; finish = 0; start = 0; } };
struct d24d_NullRef { void *value; d24d_NullRef() { value = 0; } };
struct d24d_TurnRoot { virtual void key0(); };
struct d24d_TurnBase : d24d_TurnRoot { char pad[24]; d24d_TurnBase(); };
struct d24d_TurnTables;
extern d24d_TurnTables *d24d_turn_instance_804ab400;
struct d24d_TurnTables : d24d_TurnBase {
    d24d_NullRef r28, r32, r36, r40, r44, r48;
    d24d_ZeroList lists[4];
    d24d_ZeroList other[4];
    int cursor[4];
    int actor[4];
    char pad180[20];
    
    d24d_NullRef s0; d24d_NullRef s1; d24d_NullRef s2; d24d_NullRef s3; d24d_NullRef s4; d24d_NullRef s5; d24d_NullRef s6; d24d_NullRef s7; d24d_NullRef s8; d24d_NullRef s9; d24d_NullRef s10; d24d_NullRef s11; d24d_NullRef s12; d24d_NullRef s13; d24d_NullRef s14; d24d_NullRef s15; d24d_NullRef s16; d24d_NullRef s17; d24d_NullRef s18; d24d_NullRef s19; d24d_NullRef s20; d24d_NullRef s21; d24d_NullRef s22; d24d_NullRef s23; d24d_NullRef s24; d24d_NullRef s25; d24d_NullRef s26; d24d_NullRef s27;
    int actors[16];
    int f376, f380, f384, f388;
    char pad392[20];
    int f412, f416, f420;
    d24d_TurnTables();
    virtual void key();
};
d24d_TurnTables::d24d_TurnTables() {
    f388 = 0;
    f416 = 0;
    f420 = 0;
    d24d_turn_instance_804ab400 = this;
    f384 = 1;
    for (int i = 0; i < 4; i++) { actor[i] = -1; cursor[i] = 0; }
    { int *p = actors; for (int j = 0; j < 16; j++) { *p = -1; p++; } }
    f412 = 0;
    f376 = 1;
    f380 = 1;
}
