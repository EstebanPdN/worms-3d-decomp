// Inferred HUD message router; offsets and call identities from original DOL.
struct cc33a_Hud_80065314 { unsigned char unknown[112]; int active; };
struct cc33a_Message_80065314 { unsigned short id; };
struct cc33a_Cache_80065314 { unsigned int words[2]; };
extern "C" {
int cc33a_base_8015fb34(cc33a_Hud_80065314*,cc33a_Message_80065314*);
int cc33a_equal_8015f65c(unsigned int,cc33a_Cache_80065314*);
void cc33a_init_800656b4(cc33a_Hud_80065314*);
void cc33a_clear_800654bc(cc33a_Hud_80065314*);
void cc33a_refresh_80065ce0(cc33a_Hud_80065314*);
void cc33a_stamp_800664c4(cc33a_Hud_80065314*);
void cc33a_update_800664f8(cc33a_Hud_80065314*);
extern cc33a_Cache_80065314 cc33a_cache_804ad558;
extern cc33a_Cache_80065314 cc33a_cache_804ad560;
extern cc33a_Cache_80065314 cc33a_cache_804ad568;
extern cc33a_Cache_80065314 cc33a_cache_804ad570;
extern cc33a_Cache_80065314 cc33a_cache_804ad578;
extern cc33a_Cache_80065314 cc33a_cache_804ad580;
extern cc33a_Cache_80065314 cc33a_cache_804ad588;
extern cc33a_Cache_80065314 cc33a_cache_804ad590;
extern cc33a_Cache_80065314 cc33a_cache_804ad598;
extern cc33a_Cache_80065314 cc33a_cache_804ad5a0;
int cc33a_hud_messages_80065314(cc33a_Hud_80065314* self,cc33a_Message_80065314* msg) {
 unsigned int id=msg->id;
 switch(id) {
 case 64:
  if(cc33a_base_8015fb34(self,msg)>=0) cc33a_init_800656b4(self);
  else return (int)0x80004005;
  break;
 case 66: cc33a_clear_800654bc(self); return cc33a_base_8015fb34(self,msg);
 default:
  if(cc33a_equal_8015f65c(msg->id,&cc33a_cache_804ad558)) cc33a_refresh_80065ce0(self);
  else if(cc33a_equal_8015f65c(msg->id,&cc33a_cache_804ad560)) {
   self->active=0;cc33a_stamp_800664c4(self);cc33a_update_800664f8(self);
  } else if(cc33a_equal_8015f65c(msg->id,&cc33a_cache_804ad568)) {
   self->active=1;cc33a_update_800664f8(self);
  } else if(cc33a_equal_8015f65c(id,&cc33a_cache_804ad570)||cc33a_equal_8015f65c(id,&cc33a_cache_804ad578)) self->active=1;
  else if(cc33a_equal_8015f65c(id,&cc33a_cache_804ad588)||cc33a_equal_8015f65c(id,&cc33a_cache_804ad580)||cc33a_equal_8015f65c(id,&cc33a_cache_804ad590)||cc33a_equal_8015f65c(id,&cc33a_cache_804ad598)||cc33a_equal_8015f65c(id,&cc33a_cache_804ad5a0)) cc33a_stamp_800664c4(self);
  else return cc33a_base_8015fb34(self,msg);
 }
 return 0;
}
}
