#include "w3d_ptr.h"
#line 1 "cc17b_catalog_tables_800fbc00.cpp"
/* Observed startup partitions and null-name-terminated catalogs with
   twenty-, twenty-four- and eight-byte record widths. */
struct Cc17bCatalog20 { Ptr32<const char> name; unsigned fields[4]; };
struct Cc17bCatalog24 { Ptr32<const char> name; unsigned fields[5]; };
struct Cc17bCatalog8 { Ptr32<const char> name; unsigned field; };
extern "C" {
extern Ptr32<unsigned char> arena_804aaf58;
extern Ptr32<unsigned char> part_804af108; extern Ptr32<unsigned char> part_804af110; extern Ptr32<unsigned char> part_804af114; extern Ptr32<unsigned char> part_804af11c; extern Ptr32<unsigned char> part_804af120; extern Ptr32<unsigned char> part_804af124; extern Ptr32<unsigned char> part_804af128; extern Ptr32<unsigned char> part_804af10c; extern Ptr32<unsigned char> part_804af118;
extern Cc17bCatalog20 catalog_803f5e60[],catalog_803f7a6c[];
extern Cc17bCatalog24 catalog_803fcbc0[];
extern Cc17bCatalog8 catalog_803fcc80[];
extern unsigned count_804af12c,count_804af130,count_804af134,count_804af138;
void w3d_cc17b_catalog_tables_800fbc00(int initialize,int priority) {
 if(priority!=65535)return;
 if(!initialize)return;
 Ptr32<Cc17bCatalog20> first=catalog_803f5e60;
 Ptr32<unsigned char> base=arena_804aaf58;
 part_804af108=base+16384;part_804af110=base+736;
 part_804af114=base+12400;part_804af11c=base+16368;
 part_804af120=base+16304;part_804af124=base+16176;
 part_804af10c=base;part_804af118=base;part_804af128=base;
 {unsigned count=0; if(catalog_803f5e60[0].name) { Ptr32<Cc17bCatalog20> current=catalog_803f5e60;do{++current;++count;}while(current->name);}count_804af12c=count;}
 {unsigned count=0; if(catalog_803f7a6c[0].name) { Ptr32<Cc17bCatalog20> current=catalog_803f7a6c;do{++current;++count;}while(current->name);}count_804af130=count;}
 {unsigned count=0; if(catalog_803fcbc0[0].name) { Ptr32<Cc17bCatalog24> current=catalog_803fcbc0;do{++current;++count;}while(current->name);}count_804af134=count;}
 {unsigned count=0; if(catalog_803fcc80[0].name) { Ptr32<Cc17bCatalog8> current=catalog_803fcc80;do{++current;++count;}while(current->name);}count_804af138=count;}

}
}


