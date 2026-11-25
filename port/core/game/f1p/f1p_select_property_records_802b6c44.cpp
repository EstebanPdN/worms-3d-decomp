#include "w3d_ptr.h"
#line 1 "f1p_select_property_records_802b6c44.cpp"
// Native shared-string ownership and partial external property views.
extern "C" void fn_803426b8(Ptr32<void>),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>),fn_8020bb2c(Ptr32<void>);
struct F1pRecordHeader{unsigned short refs,length,capacity;void release(){if(!--refs)fn_8020bb2c(this);}};
struct F1pRecordView{Ptr32<char> p;};struct F1pRecordText_803426b8{
 F1pRecordText_803426b8(const F1pRecordText_803426b8 &);Ptr32<char> p;F1pRecordText_803426b8();~F1pRecordText_803426b8(){fn_8020c5c4(this);fn_80341588(this);}void assign(const F1pRecordView&s){++((Ptr32<F1pRecordHeader>)(s.p-6))->refs;((Ptr32<F1pRecordHeader>)(p-6))->release();p=s.p;}};
struct F1pRecordIface{Ptr32<Ptr32<void>> table;};struct F1pRecordHeld{
 F1pRecordHeld(const F1pRecordHeld &);Ptr32<F1pRecordIface> p;F1pRecordHeld():p(0){}~F1pRecordHeld(){if(p)((Ptr32<void (Ptr32<F1pRecordIface>)>)p->table[4])(p);}};
struct F1pRecordKey{Ptr32<const char> p;template <class W3dU> F1pRecordKey(Ptr32<W3dU> w3d_p) : F1pRecordKey((const char *)w3d_p.get()) {}
 F1pRecordKey(const char*t):p(t){}};struct F1pRecordData{char unknown0[164];F1pRecordView name;};struct F1pRecordOwner{char unknown0[40];Ptr32<F1pRecordData> data;char unknown44[212];int busy;};
extern "C" int fn_800fc1b0(Ptr32<F1pRecordKey>,Ptr32<F1pRecordHeld>),fn_80178c48(Ptr32<void>),fn_80178d1c(Ptr32<void>);extern "C" Ptr32<void> fn_803426b4(Ptr32<F1pRecordIface>); Ptr32<void> fn_80342a78(Ptr32<F1pRecordIface>); Ptr32<void> fn_80343744(Ptr32<F1pRecordIface>);extern "C" Ptr32<F1pRecordView> fn_80179170(Ptr32<void>);extern "C" void fn_8020c510(Ptr32<F1pRecordText_803426b8>,Ptr32<const char>,...),fn_802b9ae0(Ptr32<F1pRecordOwner>,Ptr32<const char>);extern char format_803d7ff4[];
inline void formatRecord(F1pRecordText_803426b8&text,F1pRecordHeld&h){switch(((Ptr32<int (Ptr32<F1pRecordIface>)>)h.p->table[6])(h.p)){case 0:fn_8020c510(&text,format_803d7ff4,fn_80178c48(fn_803426b4(h.p)));break;case 1:fn_8020c510(&text,format_803d7ff4,fn_80178d1c(fn_80342a78(h.p)));break;case 4:text.assign(*fn_80179170(fn_80343744(h.p)));break;default:break;}}
extern "C" int w3d_select_property_record_802b6da8(Ptr32<void>,Ptr32<F1pRecordOwner> s){if(s->busy)return 0;F1pRecordHeld h;Ptr32<F1pRecordData> d=s->data;F1pRecordText_803426b8 text;F1pRecordKey key(d->name.p);fn_800fc1b0(&key,&h);formatRecord(text,h);fn_802b9ae0(s,text.p);return 0;}
extern "C" int w3d_select_nonempty_property_record_802b6c44(Ptr32<void>,Ptr32<F1pRecordOwner> s){if(s->busy)return 0;if(!*(Ptr32<unsigned short>)(s->data->name.p-4))return 0;F1pRecordHeld h;F1pRecordKey key(s->data->name.p);fn_800fc1b0(&key,&h);F1pRecordText_803426b8 text;formatRecord(text,h);fn_802b9ae0(s,text.p);return 0;}


