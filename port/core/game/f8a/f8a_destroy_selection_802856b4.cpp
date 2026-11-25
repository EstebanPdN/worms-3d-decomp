#include "w3d_ptr.h"
#line 1 "f8a_destroy_selection_802856b4.cpp"
// Selection: complete272-byte storage, matching factory allocation0x110.
// Observed interface ownership at offsets 212,216,220.
struct Iface{Ptr32<Ptr32<void>> table;};
struct Held{Ptr32<Iface> pointer;~Held(){if(pointer)((Ptr32<void (Ptr32<Iface>)>)pointer->table[4])(pointer);}};
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>),fn_802134fc(Ptr32<void>);
struct Text{Ptr32<char> text;~Text(){fn_8020c5c4(this);fn_80341588(this);}};
struct Entry{Held held;int index;Text text;};
struct Entries{Ptr32<Entry> begin; Ptr32<Entry> end; Ptr32<Entry> capacity;int unknown;~Entries(){Ptr32<Entry> last=end;for(Ptr32<Entry> item=begin;item!=last;++item)item->~Entry();if(begin)fn_802134fc(begin);}};
struct F8aBase_8015ff2c {Ptr32<Ptr32<void>> table;char unknown4[24];~F8aBase_8015ff2c();}; struct F8aMember_802afc40{char unknown[180];Ptr32<Ptr32<void>> baseTable;~F8aMember_802afc40();};struct F8aSelection_802856b4:F8aBase_8015ff2c,F8aMember_802afc40{char unknown212[12] __attribute__((aligned(__alignof__(F8aBase_8015ff2c)), aligned(__alignof__(F8aMember_802afc40))));Entries entries;int unknown240;Held small[3];Held first,second,third,fourth;~F8aSelection_802856b4();};
extern Ptr32<void> vt_8041bf40[]; extern Ptr32<void> vt_8041bf90[];
F8aSelection_802856b4::~F8aSelection_802856b4(){baseTable=vt_8041bf40;table=vt_8041bf90;}


