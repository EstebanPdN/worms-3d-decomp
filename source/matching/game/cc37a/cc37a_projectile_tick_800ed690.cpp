// DOL8038b618=00000000 float 0.0. External unowned constant.

// Partial timed-projectile view. Signed deadline comparisons and virtual
// callback ordering are copied from original control flow, not redesigned.
struct cc37a_Vector {float x,y,z;cc37a_Vector(float a,float b,float c):x(a),y(b),z(c){}};
struct cc37a_Actor;
struct cc37a_Table {void* unknown[18];void (*begin)(cc37a_Actor*);void (*prepare)(cc37a_Actor*);void (*finish)(cc37a_Actor*,int);};
struct cc37a_Actor {cc37a_Table* table;unsigned char gap4[32];cc37a_Vector position,velocity;unsigned char gap60[24];int deadline;unsigned char gap88[104];void* resource;};
struct cc37a_Config {unsigned char unknown[476];int enabled;};
extern const float cc37a_zero_8038b618[];
extern "C" int cc37a_paused_8006e71c();
extern "C" void * cc37a_touch_80341584(void*);
extern "C" cc37a_Config* cc37a_config_801797b4(void *);
extern "C" void cc37a_step_800ed784(cc37a_Actor*),cc37a_stop_800ecb20(cc37a_Actor*),cc37a_move_800ec6a8(cc37a_Actor*,cc37a_Vector*,cc37a_Vector*,cc37a_Vector*);
extern "C" int cc37a_projectile_tick_800ed690(cc37a_Actor* self,int now){
 if(cc37a_paused_8006e71c())return 20;
 {cc37a_Config* config=cc37a_config_801797b4((void *)cc37a_touch_80341584(self->resource));
  self->table->begin(self);self->table->prepare(self);
  if(self->deadline==-1||now<self->deadline)cc37a_step_800ed784(self);
  else if(config->enabled){
   cc37a_Vector zero(cc37a_zero_8038b618[0],cc37a_zero_8038b618[0],cc37a_zero_8038b618[0]);
   cc37a_move_800ec6a8(self,&self->position,&self->velocity,&zero);
  }else cc37a_stop_800ecb20(self);
  self->table->finish(self,now);
 }
 return 20;
}
