
// Partial original actor/type views. Type ancestry stops at a self-parent;
// the two type queries are deliberately separate virtual calls.
struct cc37a_Type {unsigned char unknown[20];cc37a_Type* parent;};
struct cc37a_Actor;
struct cc37a_Table {void* unknown[5];cc37a_Type* (*type)(cc37a_Actor*);};
struct cc37a_Actor {cc37a_Table* table;unsigned char gap4[16];int owner;unsigned char gap24[64];int exploded;unsigned char gap92[28];int activated;unsigned gap124;unsigned activationTime;unsigned debugValue;};
struct cc37a_Message {unsigned char unknown[8];int owner;int damage;};
struct cc37a_Context {unsigned char unknown[52];unsigned time;};
extern cc37a_Type cc37a_type_80361860[],cc37a_type_803618f0[];
extern const char cc37a_text_80388e78[],cc37a_file_80388e94[];
extern "C" cc37a_Context* cc37a_context_80165254();
extern "C" int cc37a_log_80022e20(const char*,const char*,int,unsigned*);
inline bool cc37a_isType(cc37a_Type* type,cc37a_Type* target){
 while(type!=target){if(type==type->parent)return false;type=type->parent;}return true;
}
extern "C" void cc37a_oil_damage_800d67d8(cc37a_Actor* self,const cc37a_Message* message){
 if(message->owner==self->owner&&!self->exploded&&!self->activated&&message->damage>0){
  self->activated=1;self->activationTime=cc37a_context_80165254()->time;
  if(cc37a_isType(self->table->type(self),cc37a_type_80361860)||cc37a_isType(self->table->type(self),cc37a_type_803618f0))
   cc37a_log_80022e20(cc37a_text_80388e78,cc37a_file_80388e94,374,&self->debugValue);
 }
}
