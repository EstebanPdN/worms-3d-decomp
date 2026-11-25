// Original DOL 0x80388f64=00000000 float 0.0. External, unowned.
// Original DOL 0x80388f60=41100000 float 9.0. External, unowned.

// Oil-drum explosion; observed offsets only, with inferred field meanings.
// Local copy uses native float copy construction, preserving rounding/order.
struct cc37a_Vector {float x,y,z;cc37a_Vector(const cc37a_Vector& q){float a=q.x,b=q.y,c=q.z;x=a;y=b;z=c;}};
struct cc37a_Drum {unsigned char unknown[28];cc37a_Vector position;unsigned char gap40[48];int exploded;};
struct cc37a_Sound;
struct cc37a_SoundTable {void* unknown[24];void (*play)(cc37a_Sound*,const char*,cc37a_Vector*);};
struct cc37a_Sound {cc37a_SoundTable* table;};
struct cc37a_Services {unsigned char unknown[108];cc37a_Sound* sound;};
extern cc37a_Services* cc37a_services_804b1788;
extern void* cc37a_messages_804b1754;
extern const char cc37a_damage_80388eb0[],cc37a_impulse_80388ec8[],cc37a_worm_80388ee4[],cc37a_land_80388f00[],cc37a_radius_80388f1c[],cc37a_effect_80388f34[],cc37a_sound_80388f4c[];
extern float cc37a_offset_80388f60[],cc37a_scale_80388f64[];
extern "C" int cc37a_read_800fc270(const char**,float*);
extern "C" void* cc37a_alloc_801613f0(void*,int);
extern "C" void* cc37a_explosion_800666b4(void*,cc37a_Vector*,cc37a_Vector*,float,float,float,float,float);
extern "C" int cc37a_post_8016239c(void*);
extern "C" int cc37a_effect_800e5ca4(cc37a_Vector*,const char*,int,float);
extern "C" void cc37a_oil_explosion_800d65ec(cc37a_Drum* self){
 self->exploded=1;
 cc37a_Vector position(self->position);position.y-=cc37a_offset_80388f60[0];
 const char* damageKey=cc37a_damage_80388eb0;float damage;cc37a_read_800fc270(&damageKey,&damage);
 const char* impulseKey=cc37a_impulse_80388ec8;float impulse;cc37a_read_800fc270(&impulseKey,&impulse);
 const char* wormKey=cc37a_worm_80388ee4;float worm;cc37a_read_800fc270(&wormKey,&worm);
 const char* landKey=cc37a_land_80388f00;float land;cc37a_read_800fc270(&landKey,&land);
 const char* radiusKey=cc37a_radius_80388f1c;float radius;cc37a_read_800fc270(&radiusKey,&radius);
 cc37a_post_8016239c(cc37a_explosion_800666b4(cc37a_alloc_801613f0(cc37a_messages_804b1754,52),&self->position,&position,damage,impulse,worm,land,radius));
 cc37a_effect_800e5ca4(&self->position,cc37a_effect_80388f34,0,cc37a_scale_80388f64[0]);
 cc37a_Sound* sound=cc37a_services_804b1788->sound;
 if(sound)sound->table->play(sound,cc37a_sound_80388f4c,&self->position);
}
