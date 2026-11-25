// Observed external receiver prefix. Never locally constructed.
extern "C" void free_802134fc(void*),base_801628ec(void*,int);
extern void *vtable_80410f40[];
extern int singleton_804ab400;
struct G5aInterface {void **vtable;};
struct G5aHeld {G5aInterface *p;~G5aHeld(){if(p)((void(*)(G5aInterface*))p->vtable[4])(p);}};
// Two fixed four-element arrays have original stride twelve and first-pointer cleanup.
struct G5aBuffer {void *begin;unsigned unknown4,unknown8;~G5aBuffer(){if(begin)free_802134fc(begin);}};
struct G5aTurnsPrefix {
 void **vtable;char unknown4[24];
 G5aHeld held28;
 G5aHeld held32;
 G5aHeld held36;
 G5aHeld held40;
 G5aHeld held44;
 G5aHeld held48;
 G5aBuffer first[4],second[4];char unknown148[52];
 G5aHeld held200;
 G5aHeld held204;
 G5aHeld held208;
 G5aHeld held212;
 G5aHeld held216;
 G5aHeld held220;
 G5aHeld held224;
 G5aHeld held228;
 G5aHeld held232;
 G5aHeld held236;
 G5aHeld held240;
 G5aHeld held244;
 G5aHeld held248;
 G5aHeld held252;
 G5aHeld held256;
 G5aHeld held260;
 G5aHeld held264;
 G5aHeld held268;
 G5aHeld held272;
 G5aHeld held276;
 G5aHeld held280;
 G5aHeld held284;
 G5aHeld held288;
 G5aHeld held292;
 G5aHeld held296;
 G5aHeld held300;
 G5aHeld held304;
 G5aHeld held308;
 char unknown312[76];G5aHeld held388;char unknown392[24];G5aHeld held416,held420;
 ~G5aTurnsPrefix(){vtable=vtable_80410f40;singleton_804ab400=0;}
};
extern "C" void g5a_turns_cleanup_80154aa8(G5aTurnsPrefix *self,int flags){self->~G5aTurnsPrefix();base_801628ec(self,flags);}
