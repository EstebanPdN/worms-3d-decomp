
// Original 800c70e4: disc-status transition with distinct localized key
// temporaries. State fields are inferred partial views, not full class sizes.
struct cc36a_DiscView { unsigned char gap00[28]; int state; unsigned char gap20[216]; unsigned int flags; };
extern const char cc36a_cover_80387984[],cc36a_insert_80387998[],cc36a_error_803879a8[],cc36a_fatal_803879bc[];
extern "C" void cc36a_animate_800c7ff4(cc36a_DiscView*);
extern "C" int cc36a_localize_800fc2b0(const char**,unsigned int*);
extern "C" void cc36a_display_800c71f8(cc36a_DiscView*,unsigned int);
extern "C" void cc36a_clear_800c770c(cc36a_DiscView*);
extern "C" void cc36a_disc_status_800c70e4(cc36a_DiscView* self,int state){
 if(self->flags&0x20000000U)return;
 cc36a_animate_800c7ff4(self);
 if(state==self->state)return;
 self->state=state;
 unsigned int text;
 switch(state){
 case 1:{const char* key=cc36a_cover_80387984;cc36a_localize_800fc2b0(&key,&text);cc36a_display_800c71f8(self,text);break;}
 case 2:{const char* key=cc36a_insert_80387998;cc36a_localize_800fc2b0(&key,&text);cc36a_display_800c71f8(self,text);break;}
 case 3:{const char* key=cc36a_insert_80387998;cc36a_localize_800fc2b0(&key,&text);cc36a_display_800c71f8(self,text);break;}
 case 4:{const char* key=cc36a_error_803879a8;cc36a_localize_800fc2b0(&key,&text);cc36a_display_800c71f8(self,text);break;}
 case 5:{const char* key=cc36a_fatal_803879bc;cc36a_localize_800fc2b0(&key,&text);cc36a_display_800c71f8(self,text);break;}
 case 0:
 default:cc36a_clear_800c770c(self);break;
 }
}
