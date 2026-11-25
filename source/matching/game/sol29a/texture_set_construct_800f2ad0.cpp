// Reference ABI reconstruction of the service at original 0x800f2ad0.
// Factory 0x800f29fc allocates 0xc80 bytes. Destructor 0x800f2bac
// independently witnesses the base, three vectors, held interfaces, string,
// and tail member. Original 0x800f5148 indexes category*80 + entry*5
// at +0x494, with 23 category counts at +0xbc4. Its five-byte records
// explain the otherwise empty nested 23-by-16 construction loops.
// Field semantics remain structural; unknown object bytes are untouched.
// The virtual interface is an external ABI view, and its table stays external.
inline void *operator new(unsigned int, void *p) { return p; }
extern "C" void * fn_803426b8(void *);
extern "C" void * fn_8026c714(void *);
struct Sol29aHeld { void *p; Sol29aHeld():p(0){} };
struct Sol29aVector { void *start,*end,*limit; Sol29aVector(){start=end=limit=0;} };
struct Sol29aString {void *data;unsigned info;Sol29aString(){fn_803426b8(this);} };
struct Sol29aChoice {unsigned char values[5];Sol29aChoice(){} };
struct Sol29aCategory {Sol29aChoice choices[16];};
struct Sol29aTail {unsigned char data[96];Sol29aTail(){fn_8026c714(this);} };
struct Sol29aInterface { virtual void slot(); };
struct Sol29aService_801628b0 : Sol29aInterface {
 unsigned char base[24];
 Sol29aService_801628b0();
};
struct Sol29aTextureSet;
extern Sol29aTextureSet *instance_804b184c;
struct Sol29aTextureSet : Sol29aService_801628b0 {
 virtual void slot();
 Sol29aTextureSet() { instance_804b184c=this;active=pending=-1; }
 Sol29aHeld first,second,third;unsigned unknown40;
 Sol29aVector a,b,c;unsigned unknown80[2];
 Sol29aHeld slots[200],top;Sol29aString name;
 unsigned char unknown900[272];Sol29aCategory categories[23];
 unsigned short counts[23];unsigned char unknown3058[14];
 Sol29aTail tail;unsigned state,delay,unknown3176[4];int active,pending;
};
typedef char Sol29aBaseSize[sizeof(Sol29aService_801628b0)==28?1:-1];
typedef char Sol29aChoiceSize[sizeof(Sol29aChoice)==5?1:-1];
typedef char Sol29aCategorySize[sizeof(Sol29aCategory)==80?1:-1];
typedef char Sol29aSizeCheck[sizeof(Sol29aTextureSet)==3200?1:-1];
typedef char Sol29aSlotsOffset[(unsigned)&((Sol29aTextureSet*)0)->slots==88?1:-1];
extern "C" Sol29aTextureSet *sol29a_texture_set_construct_800f2ad0(void *self) {
 return new (self) Sol29aTextureSet;
}
