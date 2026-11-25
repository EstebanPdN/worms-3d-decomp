inline void *operator new(unsigned,void *place){return place;}
struct TterraA34DiscObject {void **vtable;};
struct TterraA34DiscHeld {TterraA34DiscObject *pointer;TterraA34DiscHeld():pointer(0){}TterraA34DiscHeld &operator=(TterraA34DiscObject *value){if(pointer)((void(*)(TterraA34DiscObject*))pointer->vtable[4])(pointer);pointer=value;return *this;}};
struct TterraA34DiscRoot {virtual void dispatch();};
struct TterraA34DiscBase_801628b0:TterraA34DiscRoot {unsigned char unknown4[24];TterraA34DiscBase_801628b0();};
struct TterraA34DiscOwner:TterraA34DiscBase_801628b0 {
 unsigned field28;unsigned char unknown32[160];TterraA34DiscHeld entries[8];unsigned field224;TterraA34DiscHeld held;unsigned unknown232,field236,field240,field244,flags;
 virtual void dispatch();
 TterraA34DiscOwner():field236(0),field240(0),field244(0) {field28=0;held=0;field240=0;for(unsigned i=0;i<8;++i)entries[i]=0;field224=0;flags&=0x17ffffff;}
};
extern "C" TterraA34DiscOwner *tterra_a34_disc_initialize_800c6e44(void *self){return new(self)TterraA34DiscOwner;}
