#include "w3d_ptr.h"
#line 1 "d29d_turn_manager_setup_80156ff0.cpp"
// GWMP8P rev0 0x80156ff0. Turn manager setup: binds global properties and
// subscribes to its messages. Names are read from the strings in the original.
struct Triple { int a, b, c; };
extern "C" { struct String; void string_finish_8020c5c4(Ptr32<String>); void string_release_80341588(Ptr32<String>); }
struct String { Ptr32<void> rep; template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *); String(const String &); ~String() { string_finish_8020c5c4(this); string_release_80341588(this); } };
struct Event { unsigned short id; };
extern "C" {
void defaults_8015776c();
int bind_800fc1b0(Ptr32<Ptr32<const char>>, Ptr32<void>);
unsigned short message_id_8015f5a0(Ptr32<int>, int);
int subscribe_80162024(Ptr32<void>, Ptr32<unsigned short>, Ptr32<void>);
int watch_800fd62c(Ptr32<String>, Ptr32<void (Ptr32<void>)>, int, Ptr32<void>);
int water_changed_80158fbc(Ptr32<void>);
}
extern Triple triple_8045e788[];
extern const char str_803a27ac[];
extern const char str_803a27f0[];
extern const char str_803a2b4c[];
extern const char str_803a2b60[];
extern const char str_803a2b70[];
extern const char str_803a2b84[];
extern const char str_803a2b90[];
extern const char str_803a2ba0[];
extern const char str_803a2bb8[];
extern const char str_803a2bd0[];
extern const char str_803a2be4[];
extern int cache_804afe40;
extern int cache_804afe58;
extern int cache_804afe60;
extern int cache_804afe68;
extern int cache_804afe78;
extern int cache_804afe80;
extern int cache_804afec0;
extern int cache_804afed0;
extern int cache_804afee0;
extern int cache_804afef8;
extern int cache_804aff00;
extern int cache_804afe98;
extern int cache_804afea8;
extern int cache_804afeb0;
extern int cache_804aff10;
extern int cache_804aff18;
extern int cache_804aff28;
extern int cache_804aff30;
extern int cache_804aff38;
extern int cache_804aff40;
extern int cache_804aff68;
extern int cache_804aff70;
extern int cache_804aff78;
extern int cache_804aff80;
extern const char str_803a2bf8[];
struct TurnManager { char u[392]; Triple water; int f404; int f408; };
extern "C" void d29d_turn_manager_setup_80156ff0(Ptr32<TurnManager> self) {
    defaults_8015776c();
    Ptr32<const char> n0 = str_803a27ac; bind_800fc1b0(&n0, (Ptr32<char>)self + 296);
    Ptr32<const char> n1 = str_803a27f0; bind_800fc1b0(&n1, (Ptr32<char>)self + 304);
    Ptr32<const char> n2 = str_803a2b4c; bind_800fc1b0(&n2, (Ptr32<char>)self + 308);
    Ptr32<const char> n3 = str_803a2b60; bind_800fc1b0(&n3, (Ptr32<char>)self + 40);
    Ptr32<const char> n4 = str_803a2b70; bind_800fc1b0(&n4, (Ptr32<char>)self + 44);
    Ptr32<const char> n5 = str_803a2b84; bind_800fc1b0(&n5, (Ptr32<char>)self + 48);
    Event e0; e0.id = message_id_8015f5a0(&cache_804afe40, 1); subscribe_80162024(self, &e0.id, (Ptr32<char>)self + 200);
    Event e1; e1.id = message_id_8015f5a0(&cache_804afe58, 1); subscribe_80162024(self, &e1.id, (Ptr32<char>)self + 204);
    Event e2; e2.id = message_id_8015f5a0(&cache_804afe60, 1); subscribe_80162024(self, &e2.id, (Ptr32<char>)self + 208);
    Event e3; e3.id = message_id_8015f5a0(&cache_804afe68, 1); subscribe_80162024(self, &e3.id, (Ptr32<char>)self + 212);
    Event e4; e4.id = message_id_8015f5a0(&cache_804afe78, 1); subscribe_80162024(self, &e4.id, (Ptr32<char>)self + 216);
    Event e5; e5.id = message_id_8015f5a0(&cache_804afe80, 1); subscribe_80162024(self, &e5.id, (Ptr32<char>)self + 220);
    Event e6; e6.id = message_id_8015f5a0(&cache_804afec0, 1); subscribe_80162024(self, &e6.id, (Ptr32<char>)self + 224);
    Event e7; e7.id = message_id_8015f5a0(&cache_804afed0, 1); subscribe_80162024(self, &e7.id, (Ptr32<char>)self + 228);
    Event e8; e8.id = message_id_8015f5a0(&cache_804afee0, 1); subscribe_80162024(self, &e8.id, (Ptr32<char>)self + 232);
    Event e9; e9.id = message_id_8015f5a0(&cache_804afef8, 1); subscribe_80162024(self, &e9.id, (Ptr32<char>)self + 236);
    Event e10; e10.id = message_id_8015f5a0(&cache_804aff00, 1); subscribe_80162024(self, &e10.id, (Ptr32<char>)self + 240);
    Event e11; e11.id = message_id_8015f5a0(&cache_804afe98, 1); subscribe_80162024(self, &e11.id, (Ptr32<char>)self + 244);
    Event e12; e12.id = message_id_8015f5a0(&cache_804afea8, 1); subscribe_80162024(self, &e12.id, (Ptr32<char>)self + 248);
    Event e13; e13.id = message_id_8015f5a0(&cache_804afeb0, 1); subscribe_80162024(self, &e13.id, (Ptr32<char>)self + 252);
    Event e14; e14.id = message_id_8015f5a0(&cache_804aff10, 1); subscribe_80162024(self, &e14.id, (Ptr32<char>)self + 256);
    Event e15; e15.id = message_id_8015f5a0(&cache_804aff18, 1); subscribe_80162024(self, &e15.id, (Ptr32<char>)self + 260);
    Event e16; e16.id = message_id_8015f5a0(&cache_804aff28, 1); subscribe_80162024(self, &e16.id, (Ptr32<char>)self + 264);
    Event e17; e17.id = message_id_8015f5a0(&cache_804aff30, 1); subscribe_80162024(self, &e17.id, (Ptr32<char>)self + 268);
    Event e18; e18.id = message_id_8015f5a0(&cache_804aff38, 1); subscribe_80162024(self, &e18.id, (Ptr32<char>)self + 272);
    Event e19; e19.id = message_id_8015f5a0(&cache_804aff40, 1); subscribe_80162024(self, &e19.id, (Ptr32<char>)self + 276);
    Event e20; e20.id = message_id_8015f5a0(&cache_804aff68, 1); subscribe_80162024(self, &e20.id, (Ptr32<char>)self + 280);
    Event e21; e21.id = message_id_8015f5a0(&cache_804aff70, 1); subscribe_80162024(self, &e21.id, (Ptr32<char>)self + 284);
    Event e22; e22.id = message_id_8015f5a0(&cache_804aff78, 1); subscribe_80162024(self, &e22.id, (Ptr32<char>)self + 288);
    Event e23; e23.id = message_id_8015f5a0(&cache_804aff80, 1); subscribe_80162024(self, &e23.id, (Ptr32<char>)self + 292);
    Ptr32<const char> n6 = str_803a2b90; bind_800fc1b0(&n6, (Ptr32<char>)self + 28);
    Ptr32<const char> n7 = str_803a2ba0; bind_800fc1b0(&n7, (Ptr32<char>)self + 32);
    Ptr32<const char> n8 = str_803a2bb8; bind_800fc1b0(&n8, (Ptr32<char>)self + 36);
    Ptr32<const char> n9 = str_803a2bd0; bind_800fc1b0(&n9, (Ptr32<char>)self + 416);
    Ptr32<const char> n10 = str_803a2be4; bind_800fc1b0(&n10, (Ptr32<char>)self + 420);
    {
        String water(str_803a2bf8);
        watch_800fd62c(&water, (Ptr32<void (Ptr32<void>)>)water_changed_80158fbc, 0, (Ptr32<char>)self + 388);
    }
    self->water = *triple_8045e788;
    self->f408 = 0;
    self->f404 = 0;
}


