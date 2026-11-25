// Initialize the original grid service's observed fields and property handles.
struct cc27a_RangeC844 {void *begin,*end,*limit;void init(){limit=0;end=0;begin=0;}};
struct cc27a_PairC844 {void*begin,*end;void init(){begin=0;end=0;}};
struct cc27a_TailC844 {unsigned int unknown;void*end;void init(){end=0;}};
struct cc27a_GridC844 {void*dispatch;char unknown4[28];cc27a_RangeC844 regions;unsigned int unknown44;int count;char unknown52[8];void*slots[2];int field68;cc27a_PairC844 pair;cc27a_TailC844 tail;cc27a_RangeC844 pending;char unknown100[44];float field144;int field148;void*minimum,*maximum,*water,*field164,*field168,*field172,*field176;};
extern char cc27a_table_8040dac8[],cc27a_water_8036b6a8[],cc27a_min_8036b6b4[],cc27a_max_8036b6c4[];
extern cc27a_GridC844 *cc27a_grid_804b1758;
extern "C" int cc27a_base_801628b0(void*);
extern "C" void* cc27a_lookup_800fc1b0(const char**,void**);
extern "C" cc27a_GridC844* cc27a_grid_initialize_8001c844(cc27a_GridC844*self){
 volatile char unknownFrame[8];
 void**minimumSlot=&self->minimum;cc27a_base_801628b0(self);void**maximumSlot=&self->maximum;self->dispatch=cc27a_table_8040dac8;
 self->regions.init();self->pair.init();self->tail.init();self->pending.init();
 self->minimum=0;self->maximum=0;self->water=0;self->field164=0;self->field168=0;self->field172=0;self->field176=0;
 cc27a_grid_804b1758=self;self->field68=0;self->field144=0.0f;self->field148=1;self->count=0;
 const char*water=cc27a_water_8036b6a8;cc27a_lookup_800fc1b0(&water,&self->water);
 const char*minimum=cc27a_min_8036b6b4;cc27a_lookup_800fc1b0(&minimum,minimumSlot);
 const char*maximum=cc27a_max_8036b6c4;cc27a_lookup_800fc1b0(&maximum,maximumSlot);
 int remaining=1;void **slot=&self->slots[1];for(;remaining>=0;--remaining){*slot=0;--slot;}
 return self;
}