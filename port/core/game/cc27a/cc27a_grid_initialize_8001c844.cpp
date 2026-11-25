#include "w3d_ptr.h"
#line 1 "cc27a_grid_initialize_8001c844.cpp"
// Initialize the original grid service's observed fields and property handles.
struct cc27a_RangeC844 {Ptr32<void> begin; Ptr32<void> end; Ptr32<void> limit;void init(){limit=0;end=0;begin=0;}};
struct cc27a_PairC844 {Ptr32<void> begin; Ptr32<void> end;void init(){begin=0;end=0;}};
struct cc27a_TailC844 {unsigned int unknown;Ptr32<void> end;void init(){end=0;}};
struct cc27a_GridC844 {Ptr32<void> dispatch;char unknown4[28];cc27a_RangeC844 regions;unsigned int unknown44;int count;char unknown52[8];Ptr32<void> slots[2];int field68;cc27a_PairC844 pair;cc27a_TailC844 tail;cc27a_RangeC844 pending;char unknown100[44];float field144;int field148;Ptr32<void> minimum; Ptr32<void> maximum; Ptr32<void> water; Ptr32<void> field164; Ptr32<void> field168; Ptr32<void> field172; Ptr32<void> field176;};
extern char cc27a_table_8040dac8[],cc27a_water_8036b6a8[],cc27a_min_8036b6b4[],cc27a_max_8036b6c4[];
extern Ptr32<cc27a_GridC844> cc27a_grid_804b1758;
extern "C" int cc27a_base_801628b0(Ptr32<void>);
extern "C" Ptr32<void> cc27a_lookup_800fc1b0(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<void>>);
extern "C" Ptr32<cc27a_GridC844> cc27a_grid_initialize_8001c844(Ptr32<cc27a_GridC844> self){
 volatile char unknownFrame[8];
 Ptr32<Ptr32<void>> minimumSlot=&self->minimum;cc27a_base_801628b0(self);Ptr32<Ptr32<void>> maximumSlot=&self->maximum;self->dispatch=cc27a_table_8040dac8;
 self->regions.init();self->pair.init();self->tail.init();self->pending.init();
 self->minimum=0;self->maximum=0;self->water=0;self->field164=0;self->field168=0;self->field172=0;self->field176=0;
 cc27a_grid_804b1758=self;self->field68=0;self->field144=0.0f;self->field148=1;self->count=0;
 Ptr32<const char> water=cc27a_water_8036b6a8;cc27a_lookup_800fc1b0(&water,&self->water);
 Ptr32<const char> minimum=cc27a_min_8036b6b4;cc27a_lookup_800fc1b0(&minimum,minimumSlot);
 Ptr32<const char> maximum=cc27a_max_8036b6c4;cc27a_lookup_800fc1b0(&maximum,maximumSlot);
 int remaining=1;Ptr32<Ptr32<void>> slot=&self->slots[1];for(;remaining>=0;--remaining){*slot=0;--slot;}
 return self;
}

