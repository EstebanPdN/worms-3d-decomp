
// Inferred event dispatcher for original 800b96e4. Partial receiver view;
// names describe observed use, not original class declarations or sizeof.
struct cc36a_Message { unsigned short key; };
struct cc36a_State { unsigned char unknown00[64]; unsigned char selection[4]; };
struct cc36a_Cache { unsigned int words[2]; };
extern cc36a_Cache cc36a_cache_804ae528,cc36a_cache_804ae518,cc36a_cache_804ae520,cc36a_cache_804ae540;
extern cc36a_State *cc36a_owner_804aad30;
extern "C" {
int cc36a_base_event_8015fb34(cc36a_State*,cc36a_Message*);
void cc36a_setup_800b983c(cc36a_State*);
void cc36a_shutdown_800ba5f8(cc36a_State*);
int cc36a_key_matches_8015f620(cc36a_Cache*,unsigned short);
void* cc36a_payload_8010a8fc(cc36a_Message*);
int cc36a_apply_800b9c1c(void*,void*);
int cc36a_refresh_800b9e58(cc36a_State*);
int cc36a_clear_800b9a48(cc36a_State*);
int cc36a_reset_800b9b0c(cc36a_State*);
void* cc36a_selection_8004d978(cc36a_Message*);
int cc36a_append_800ba4c4(cc36a_State*,void*);
int cc36a_selection_events_800b96e4(cc36a_State* self,cc36a_Message* message) {
 switch(message->key) {
 case 64:
  if(cc36a_base_event_8015fb34(self,message)>=0){cc36a_setup_800b983c(self);return 0;}
  return (int)0x80004005U;
 case 66:cc36a_shutdown_800ba5f8(self);break;
 default:
  if(cc36a_key_matches_8015f620(&cc36a_cache_804ae528,message->key)){
   cc36a_apply_800b9c1c(cc36a_payload_8010a8fc(message),self->selection);
   cc36a_refresh_800b9e58(self);
  }else if(cc36a_key_matches_8015f620(&cc36a_cache_804ae518,message->key))cc36a_clear_800b9a48(self);
  else if(cc36a_key_matches_8015f620(&cc36a_cache_804ae520,message->key))cc36a_reset_800b9b0c(self);
  else if(cc36a_key_matches_8015f620(&cc36a_cache_804ae540,message->key)){
   void* selection=cc36a_selection_8004d978(message);
   if(cc36a_owner_804aad30)cc36a_append_800ba4c4(cc36a_owner_804aad30,selection);
  }
 }
 return cc36a_base_event_8015fb34(self,message);
}
}
