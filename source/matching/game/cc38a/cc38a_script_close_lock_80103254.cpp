
// Close-lock Lua binding. Preserve original validation order, including the
// unchecked tag read before the optional destructor call; do not add guards.
struct cc38a_Lua;
struct cc38a_Lock {unsigned unknown;int tag;bool valid()const{return tag==0xe3a8;}};
struct cc38a_Runtime {unsigned char unknown[68];cc38a_Lua* state;unsigned char gap72[284];int locks;};
extern const char cc38a_count_error_803991f0[],cc38a_type_error_8039922c[],cc38a_lock_error_8039925c[];
extern "C" int cc38a_top_802cd7f4(cc38a_Lua*);
extern "C" int cc38a_type_802cd9e8(cc38a_Lua*,int);
extern "C" cc38a_Lock* cc38a_userdata_802cde08(cc38a_Lua*,int);
extern "C" void cc38a_destroy_80178474(cc38a_Lock*,int);
extern "C" void cc38a_report_801022ec(cc38a_Runtime*,const char*);
extern "C" void cc38a_settop_802cd808(cc38a_Lua*,int);
extern "C" int cc38a_script_close_lock_80103254(cc38a_Runtime* self){
 int count=cc38a_top_802cd7f4(self->state);
 if(count!=1){cc38a_report_801022ec(self,cc38a_count_error_803991f0);cc38a_settop_802cd808(self->state,-count-1);return 0;}
 if(cc38a_type_802cd9e8(self->state,-1)!=2){cc38a_report_801022ec(self,cc38a_type_error_8039922c);cc38a_settop_802cd808(self->state,-2);return 0;}
 cc38a_Lock* lock=cc38a_userdata_802cde08(self->state,-1);
 if(!lock->valid()){cc38a_report_801022ec(self,cc38a_lock_error_8039925c);cc38a_settop_802cd808(self->state,-2);return 0;}
 if(lock)cc38a_destroy_80178474(lock,3);
 --self->locks;
 cc38a_settop_802cd808(self->state,-2);return 0;
}
