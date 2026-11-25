// Selection: complete272-byte storage, matching factory allocation0x110.
// Observed interface ownership at offsets 212,216,220.
struct Iface{void**table;};
struct Held{Iface*pointer;~Held(){if(pointer)((void(*)(Iface*))pointer->table[4])(pointer);}};
extern "C" void fn_8020c5c4(void*),fn_80341588(void*),fn_802134fc(void*);
struct Text{char*text;~Text(){fn_8020c5c4(this);fn_80341588(this);}};
struct Entry{Held held;int index;Text text;};
struct Entries{Entry*begin,*end,*capacity;int unknown;~Entries(){Entry*last=end;for(Entry*item=begin;item!=last;++item)item->~Entry();if(begin)fn_802134fc(begin);}};
struct F8aBase_8015ff2c {void**table;char unknown4[24];~F8aBase_8015ff2c();}; struct F8aMember_802afc40{char unknown[180];void**baseTable;~F8aMember_802afc40();};struct F8aSelection_802856b4:F8aBase_8015ff2c,F8aMember_802afc40{char unknown212[12];Entries entries;int unknown240;Held small[3];Held first,second,third,fourth;~F8aSelection_802856b4();};
extern void*vt_8041bf40[],*vt_8041bf90[];
F8aSelection_802856b4::~F8aSelection_802856b4(){baseTable=vt_8041bf40;table=vt_8041bf90;}
