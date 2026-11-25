#include "w3d_ptr.h"
#line 1 "f1p_export_scheme_8028fb10.cpp"
// Inferred property export; original address-named text and scheme offsets.
struct F1pExportIface{Ptr32<Ptr32<void>> table;};
struct F1pExportHeld{
 F1pExportHeld(const F1pExportHeld &);Ptr32<F1pExportIface> p;F1pExportHeld():p(0){}~F1pExportHeld(){if(p)((Ptr32<void (Ptr32<F1pExportIface>)>)p->table[4])(p);}};
// Original held local occupies stack8..15; only its first word is accessed.
struct F1pExportKey{Ptr32<const char> text;template <class W3dU> F1pExportKey(Ptr32<W3dU> w3d_p) : F1pExportKey((const char *)w3d_p.get()) {}
 F1pExportKey(const char*p):text(p){}};
struct F1pExportText{Ptr32<const char> text;Ptr32<const char> c_str()const{return text;}};struct F1pExportScheme{unsigned pre[5];F1pExportText name;unsigned rest[78];unsigned&at(unsigned n){return ((Ptr32<unsigned int>)this)[n];}};
extern const char key_803d0174[],key_803d01c8[],key_803d01dc[],key_803d01e8[],key_803d01f0[],key_803d01f8[],key_803d0204[],key_803d0210[],key_803d0218[],key_803d0220[],key_803d0228[],key_803d0230[],key_803d0238[],key_803d0244[],key_803d024c[],key_803d0254[],key_803d025c[],key_803d0264[],key_803d0270[],key_803d0278[],key_803d0284[],key_803d0290[],key_803d0298[],key_803d02a0[],key_803d02ac[],key_803d02b4[],key_803d02bc[],key_803d02c4[],key_803d02cc[],key_803d02d4[],key_803d02dc[],key_803d02e4[],key_803d02ec[],key_803d02f8[],key_803d0300[],key_803d0308[],key_803d0310[],key_803d031c[],key_803d0324[],key_803d0330[],key_803d0338[],key_803d0340[],key_803d0348[],key_803d0350[],key_803d0358[],key_803d0360[],key_803d0368[],key_803d0370[],key_803d037c[],key_803d0384[],key_803d038c[],key_803d0394[],key_803d039c[],key_803d03a8[],key_803d03b0[],key_803d03b8[],key_803d03c4[],key_803d03cc[],key_803d03d4[],key_803d03e0[],key_803d03e8[],key_803d03f0[],key_803d03f8[],key_803d0400[],key_803d0408[],key_803d0414[],key_803d041c[],key_803d0428[],key_803d0430[],key_803d0438[],key_803d0444[],key_803d044c[],key_803d0454[],key_803d0460[],key_803d046c[],key_803d0478[],key_803d0484[],key_803d0494[];
extern "C" int fn_800fc1b0(Ptr32<F1pExportKey>,Ptr32<F1pExportHeld>),fn_800fc43c(Ptr32<F1pExportKey>,int),fn_800fc3b0(Ptr32<F1pExportKey>,unsigned),fn_800fc550(Ptr32<F1pExportKey>,Ptr32<const char>);
extern "C" Ptr32<void> fn_80341584(Ptr32<F1pExportIface>);extern "C" Ptr32<F1pExportScheme> fn_801797b4(Ptr32<void>);extern "C" void fn_8028f93c(Ptr32<void>,Ptr32<const char>,Ptr32<void>);
extern "C" void w3d_export_scheme_8028fb10(Ptr32<void> self){F1pExportHeld held;F1pExportKey lookup(key_803d0174);if(fn_800fc1b0(&lookup,&held)>=0){F1pExportKey changing(key_803d01c8);fn_800fc43c(&changing,1);Ptr32<F1pExportScheme> scheme=fn_801797b4(fn_80341584(held.p));
F1pExportKey property_78(key_803d01dc);fn_800fc3b0(&property_78,scheme->at(45));
F1pExportKey property_74(key_803d01e8);fn_800fc3b0(&property_74,scheme->at(70));
F1pExportKey property_70(key_803d01f0);fn_800fc3b0(&property_70,scheme->at(67));
F1pExportKey property_6c(key_803d01f8);fn_800fc3b0(&property_6c,scheme->at(75));
F1pExportKey property_68(key_803d0204);fn_800fc3b0(&property_68,scheme->at(74));
F1pExportKey property_64(key_803d0210);fn_800fc3b0(&property_64,scheme->at(66));
F1pExportKey property_60(key_803d0218);fn_800fc3b0(&property_60,scheme->at(69));
F1pExportKey property_5c(key_803d0220);fn_800fc3b0(&property_5c,scheme->at(78));
F1pExportKey property_58(key_803d0228);fn_800fc3b0(&property_58,scheme->at(68));
F1pExportKey property_54(key_803d0230);fn_800fc3b0(&property_54,scheme->at(80));
F1pExportKey property_50(key_803d0238);fn_800fc3b0(&property_50,scheme->at(72));
F1pExportKey property_4c(key_803d0244);fn_800fc3b0(&property_4c,scheme->at(14));
F1pExportKey property_48(key_803d024c);fn_800fc3b0(&property_48,scheme->at(82));
F1pExportKey property_44(key_803d0254);fn_800fc3b0(&property_44,scheme->at(44));
F1pExportKey property_40(key_803d025c);fn_800fc3b0(&property_40,scheme->at(79));
F1pExportKey property_3c(key_803d0264);fn_800fc3b0(&property_3c,scheme->at(76));
F1pExportKey property_38(key_803d0270);fn_800fc3b0(&property_38,scheme->at(71));
F1pExportKey property_34(key_803d0278);fn_800fc3b0(&property_34,scheme->at(77));
F1pExportKey property_30(key_803d0284);fn_800fc3b0(&property_30,scheme->at(81));
F1pExportKey property_2c(key_803d0290);fn_800fc3b0(&property_2c,scheme->at(64));
F1pExportKey property_28(key_803d0298);fn_800fc3b0(&property_28,scheme->at(63));
F1pExportKey property_24(key_803d02a0);fn_800fc3b0(&property_24,scheme->at(65));
Ptr32<const char> text=scheme->name.c_str();F1pExportKey property_20(key_803d02ac);fn_800fc550(&property_20,text);
F1pExportKey property_1c(key_803d02b4);fn_800fc3b0(&property_1c,scheme->at(83));
fn_8028f93c(self,key_803d02bc,(Ptr32<void>)w3d::G(scheme->at(20)));
fn_8028f93c(self,key_803d02c4,(Ptr32<void>)w3d::G(scheme->at(18)));
fn_8028f93c(self,key_803d02cc,(Ptr32<void>)w3d::G(scheme->at(17)));
fn_8028f93c(self,key_803d02d4,(Ptr32<void>)w3d::G(scheme->at(16)));
fn_8028f93c(self,key_803d02dc,(Ptr32<void>)w3d::G(scheme->at(13)));
fn_8028f93c(self,key_803d02e4,(Ptr32<void>)w3d::G(scheme->at(12)));
fn_8028f93c(self,key_803d02ec,(Ptr32<void>)w3d::G(scheme->at(11)));
fn_8028f93c(self,key_803d02f8,(Ptr32<void>)w3d::G(scheme->at(25)));
fn_8028f93c(self,key_803d0300,(Ptr32<void>)w3d::G(scheme->at(24)));
fn_8028f93c(self,key_803d0308,(Ptr32<void>)w3d::G(scheme->at(42)));
fn_8028f93c(self,key_803d0310,(Ptr32<void>)w3d::G(scheme->at(41)));
fn_8028f93c(self,key_803d031c,(Ptr32<void>)w3d::G(scheme->at(40)));
fn_8028f93c(self,key_803d0324,(Ptr32<void>)w3d::G(scheme->at(39)));
fn_8028f93c(self,key_803d0330,(Ptr32<void>)w3d::G(scheme->at(38)));
fn_8028f93c(self,key_803d0338,(Ptr32<void>)w3d::G(scheme->at(37)));
fn_8028f93c(self,key_803d0340,(Ptr32<void>)w3d::G(scheme->at(36)));
fn_8028f93c(self,key_803d0348,(Ptr32<void>)w3d::G(scheme->at(35)));
fn_8028f93c(self,key_803d0350,(Ptr32<void>)w3d::G(scheme->at(34)));
fn_8028f93c(self,key_803d0358,(Ptr32<void>)w3d::G(scheme->at(33)));
fn_8028f93c(self,key_803d0360,(Ptr32<void>)w3d::G(scheme->at(30)));
fn_8028f93c(self,key_803d0368,(Ptr32<void>)w3d::G(scheme->at(29)));
fn_8028f93c(self,key_803d0370,(Ptr32<void>)w3d::G(scheme->at(23)));
fn_8028f93c(self,key_803d037c,(Ptr32<void>)w3d::G(scheme->at(22)));
fn_8028f93c(self,key_803d0384,(Ptr32<void>)w3d::G(scheme->at(43)));
fn_8028f93c(self,key_803d038c,(Ptr32<void>)w3d::G(scheme->at(62)));
fn_8028f93c(self,key_803d0394,(Ptr32<void>)w3d::G(scheme->at(61)));
fn_8028f93c(self,key_803d039c,(Ptr32<void>)w3d::G(scheme->at(60)));
fn_8028f93c(self,key_803d03a8,(Ptr32<void>)w3d::G(scheme->at(59)));
fn_8028f93c(self,key_803d03b0,(Ptr32<void>)w3d::G(scheme->at(58)));
fn_8028f93c(self,key_803d03b8,(Ptr32<void>)w3d::G(scheme->at(57)));
fn_8028f93c(self,key_803d03c4,(Ptr32<void>)w3d::G(scheme->at(55)));
fn_8028f93c(self,key_803d03cc,(Ptr32<void>)w3d::G(scheme->at(53)));
fn_8028f93c(self,key_803d03d4,(Ptr32<void>)w3d::G(scheme->at(50)));
fn_8028f93c(self,key_803d03e0,(Ptr32<void>)w3d::G(scheme->at(49)));
fn_8028f93c(self,key_803d03e8,(Ptr32<void>)w3d::G(scheme->at(48)));
fn_8028f93c(self,key_803d03f0,(Ptr32<void>)w3d::G(scheme->at(47)));
fn_8028f93c(self,key_803d03f8,(Ptr32<void>)w3d::G(scheme->at(19)));
fn_8028f93c(self,key_803d0400,(Ptr32<void>)w3d::G(scheme->at(26)));
fn_8028f93c(self,key_803d0408,(Ptr32<void>)w3d::G(scheme->at(32)));
fn_8028f93c(self,key_803d0414,(Ptr32<void>)w3d::G(scheme->at(28)));
fn_8028f93c(self,key_803d041c,(Ptr32<void>)w3d::G(scheme->at(54)));
fn_8028f93c(self,key_803d0428,(Ptr32<void>)w3d::G(scheme->at(7)));
fn_8028f93c(self,key_803d0430,(Ptr32<void>)w3d::G(scheme->at(6)));
fn_8028f93c(self,key_803d0438,(Ptr32<void>)w3d::G(scheme->at(10)));
fn_8028f93c(self,key_803d0444,(Ptr32<void>)w3d::G(scheme->at(56)));
fn_8028f93c(self,key_803d044c,(Ptr32<void>)w3d::G(scheme->at(9)));
fn_8028f93c(self,key_803d0454,(Ptr32<void>)w3d::G(scheme->at(73)));
fn_8028f93c(self,key_803d0460,(Ptr32<void>)w3d::G(scheme->at(31)));
fn_8028f93c(self,key_803d046c,(Ptr32<void>)w3d::G(scheme->at(8)));
fn_8028f93c(self,key_803d0478,(Ptr32<void>)w3d::G(scheme->at(27)));
fn_8028f93c(self,key_803d0484,(Ptr32<void>)w3d::G(scheme->at(51)));
fn_8028f93c(self,key_803d0494,(Ptr32<void>)w3d::G(scheme->at(15)));
F1pExportKey done(key_803d01c8);fn_800fc43c(&done,0);}}


