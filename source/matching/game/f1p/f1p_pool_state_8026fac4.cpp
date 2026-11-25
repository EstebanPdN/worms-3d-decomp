// Original 0x8026fac4. Layout and role inferred from byte witnesses.
struct Carrier { char pad[160];int active; };
struct Owner { char pad[40];Carrier *carrier;char pad2c[244];void *pool;int active; };
extern "C" unsigned fn_802bc71c(void *);
extern "C" float fn_802bc778(void *);
extern "C" void fn_8026f6e0(Owner *);
extern "C" void fn_8026fa7c(Owner *);
extern "C" void w3d_pool_state_8026fac4(Owner *self) {
 int desired=0;Carrier *carrier=self->carrier;
 if(self->pool) {
  float count=(float)fn_802bc71c(self->pool);
  if(count>fn_802bc778(self->pool)) desired=1;
 }
 if(carrier->active) desired=1;
 if(!self->active) {if(desired==1)fn_8026f6e0(self);}
 if(self->active && !desired)fn_8026fa7c(self);
}
