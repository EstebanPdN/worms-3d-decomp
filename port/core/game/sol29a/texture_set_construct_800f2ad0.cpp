#include "w3d_ptr.h"
#line 1 "texture_set_construct_800f2ad0.cpp"
// Reference ABI reconstruction of the service at original 0x800f2ad0.
// Factory 0x800f29fc allocates 0xc80 bytes. Destructor 0x800f2bac
// independently witnesses the base, three vectors, held interfaces, string,
// and tail member. Original 0x800f5148 indexes category*80 + entry*5
// at +0x494, with 23 category counts at +0xbc4. Its five-byte records
// explain the otherwise empty nested 23-by-16 construction loops.
// Field semantics remain structural; unknown object bytes are untouched.
// The virtual interface is an external ABI view, and its table stays external.
inline void *operator new(__SIZE_TYPE__, void *p) { return p; }
extern "C" Ptr32<void> fn_803426b8(Ptr32<void>);
extern "C" Ptr32<void> fn_8026c714(Ptr32<void>);
struct Sol29aHeld { Ptr32<void> p; Sol29aHeld():p(0){} };
struct Sol29aVector { Ptr32<void> start; Ptr32<void> end; Ptr32<void> limit; Sol29aVector(){start=end=limit=0;} };
struct Sol29aString {Ptr32<void> data;unsigned info;Sol29aString(){fn_803426b8(this);} };
struct Sol29aChoice {unsigned char values[5];Sol29aChoice(){} };
struct Sol29aCategory {Sol29aChoice choices[16];};
struct Sol29aTail {unsigned char data[96];Sol29aTail(){fn_8026c714(this);} };
struct Sol29aInterface { void w3d_r_slot() __asm__(W3D_SYM("_ZN15Sol29aInterface4slotEv"));  __attribute__((always_inline)) inline void slot() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sol29aInterface, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Sol29aInterface; };
struct Sol29aService_801628b0 : Sol29aInterface {
 unsigned char base[24] __attribute__((aligned(__alignof__(Sol29aInterface))));
 Sol29aService_801628b0();
};
struct Sol29aTextureSet;
extern Ptr32<Sol29aTextureSet> instance_804b184c;
struct Sol29aTextureSet : Sol29aService_801628b0 {
 void w3d_r_slot() __asm__(W3D_SYM("_ZN16Sol29aTextureSet4slotEv"));
 Sol29aTextureSet() { W3D_SET_VPTR(this->Sol29aService_801628b0::w3d_vptr_Sol29aInterface, w3d_vt___vt_16Sol29aTextureSet, "__vt_16Sol29aTextureSet");  instance_804b184c=this;active=pending=-1; }
 Sol29aHeld first __attribute__((aligned(__alignof__(Sol29aService_801628b0)))),second,third;unsigned unknown40;
 Sol29aVector a,b,c;unsigned unknown80[2];
 Sol29aHeld slots[200],top;Sol29aString name;
 unsigned char unknown900[272];Sol29aCategory categories[23];
 unsigned short counts[23];unsigned char unknown3058[14];
 Sol29aTail tail;unsigned state,delay,unknown3176[4];int active,pending;
 __attribute__((always_inline)) inline void slot() { this->Sol29aService_801628b0::slot(); } };
typedef char Sol29aBaseSize[sizeof(Sol29aService_801628b0)==28?1:-1];
typedef char Sol29aChoiceSize[sizeof(Sol29aChoice)==5?1:-1];
typedef char Sol29aCategorySize[sizeof(Sol29aCategory)==80?1:-1];
typedef char Sol29aSizeCheck[sizeof(Sol29aTextureSet)==3200?1:-1];
typedef char Sol29aSlotsOffset[__builtin_offsetof(Sol29aTextureSet,slots)==88?1:-1];
extern "C" Ptr32<Sol29aTextureSet> sol29a_texture_set_construct_800f2ad0(Ptr32<void> self) {
 return new (self) Sol29aTextureSet;
}


