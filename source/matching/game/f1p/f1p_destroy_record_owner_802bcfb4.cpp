// Inferred record list and interface fields; native destructor forwards delete flags.
struct F1pRecordIface{void**table;};struct F1pRecordHeld{F1pRecordIface*p;~F1pRecordHeld(){if(p)((void(*)(F1pRecordIface*))p->table[4])(p);}};
struct F1pRecordEntry{F1pRecordHeld held;char unknown[20];};
extern "C" void fn_802134fc(void*),fn_802bf658(void*);
struct F1pRecordList{F1pRecordEntry*begin,*end,*capacity;int unknown;~F1pRecordList(){F1pRecordEntry*last=end;for(F1pRecordEntry*p=begin;p!=last;++p)p->~F1pRecordEntry();if(begin)fn_802134fc(begin);}};
struct F1pRecordOwner{char unknown[68];F1pRecordHeld held68,held72;int unknown76;F1pRecordList list;F1pRecordHeld held96,held100,held104,held108,held112,held116,held120,held124;~F1pRecordOwner();};
F1pRecordOwner::~F1pRecordOwner(){fn_802bf658(this);}
