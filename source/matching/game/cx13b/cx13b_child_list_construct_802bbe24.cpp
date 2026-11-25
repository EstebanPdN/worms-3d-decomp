
// PPC32 object layout and all offsets derive from original constructor stores.
struct Vector{void**begin,**end,**capacity;};struct Object{void*table;unsigned char opaque[24];void*parent;unsigned char gap[24];Vector children;float value68;int value72;float value76;int value80,value84;void*held;int unused92,value96,value100;void*held104;};extern "C" int base_8015fef0(Object*);extern "C" unsigned char table_8041c860[];extern "C" const float initial_803d82c0[],secondary_803d82c4[];
extern "C" Object*w3d_cx13b_child_list_construct_802bbe24(Object*self){base_8015fef0(self);self->table=table_8041c860;self->parent=0;Vector*v=&self->children;v->capacity=0;v->end=0;self->value68=initial_803d82c0[0];self->value84=3;self->value76=secondary_803d82c4[0];v->begin=0;self->held=0;self->value72=0;self->value80=0;self->value100=0;self->held104=0;self->value96=1;return self;}




