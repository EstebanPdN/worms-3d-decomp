#include "w3d_ptr.h"
#line 1 "cx11b_static_descriptor_table_80210f5c.cpp"
// PPC32 original table: three twelve-byte entries; inferred names, original extern identities.
extern "C" Ptr32<void> clear_802eefe0(Ptr32<void>,int,unsigned int,...);
struct Entry {Ptr32<void> type;unsigned int size,count;};
extern int guard_804b06bc;extern unsigned char type_8040c9a0[],type_804138b0[];
struct Table {Entry first,second,third;void initialize(unsigned int size,unsigned int count){
 clear_802eefe0(&first,0,12);first.type=type_8040c9a0;
first.count=count;clear_802eefe0(&second,0,12);second.type=type_804138b0;second.size=20;second.count=count;clear_802eefe0(&third,0,12);guard_804b06bc=count;}};
extern Table table_80463c10[];
extern "C" Ptr32<Table> w3d_cx11b_static_descriptor_table_80210f5c(){if(!guard_804b06bc)table_80463c10[0].initialize(0,1);return table_80463c10;}



