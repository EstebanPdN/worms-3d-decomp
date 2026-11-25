// Replacement for parent-rejected symbol-alias draft; no assembly or symbol aliases.
// Original GWMP8P 0x80016bf0: append eligible utility plans; names inferred.
// Native new-expression preserves allocation/constructor ownership and cleanup ABI.
typedef unsigned int cc24a_u32;
extern "C" void *cc24a_allocate_8001523c(unsigned int);
inline void *operator new(unsigned int size) { return cc24a_allocate_8001523c(size); }
struct cc24a_UtilityV2Base;
extern "C" void cc24a_base_80006360(cc24a_UtilityV2Base*);
struct cc24a_UtilityV2Base { int state; float cost; int unknown8; cc24a_u32 *dispatch; cc24a_UtilityV2Base(){cc24a_base_80006360(this);} };
extern cc24a_u32 cc24a_dispatch_8040da58[],cc24a_dispatch_8040da28[],cc24a_dispatch_8040d9c8[],cc24a_dispatch_8040d9f8[];
struct cc24a_UtilityV2A:cc24a_UtilityV2Base { cc24a_UtilityV2A(){dispatch=cc24a_dispatch_8040da58;} };
struct cc24a_UtilityV2B:cc24a_UtilityV2Base { cc24a_UtilityV2B(){dispatch=cc24a_dispatch_8040da28;} };
struct cc24a_UtilityV2C:cc24a_UtilityV2Base { cc24a_UtilityV2C(){dispatch=cc24a_dispatch_8040d9c8;} };
struct cc24a_UtilityV2D:cc24a_UtilityV2Base { cc24a_UtilityV2D(){dispatch=cc24a_dispatch_8040d9f8;} };
extern int cc24a_ready_804aa6dc,cc24a_busy_804aa6e0,cc24a_mode_804aa5a0,cc24a_extra_804aa58c,cc24a_done_804aa594;
extern "C" void cc24a_push_80007514(cc24a_UtilityV2Base*);
extern "C" int cc24a_available_80007ccc(int);
inline bool cc24a_ready(){return cc24a_ready_804aa6dc && !cc24a_busy_804aa6e0;}
extern "C" int cc24a_planner_utility_choices_v2_80016bf0() {
 if(cc24a_ready()) {
  if(!cc24a_mode_804aa5a0) {
   cc24a_push_80007514(new cc24a_UtilityV2A);
   if(!cc24a_extra_804aa58c) {
    cc24a_push_80007514(new cc24a_UtilityV2B);
    cc24a_push_80007514(new cc24a_UtilityV2C);
   }
  }
  if(cc24a_available_80007ccc(47))cc24a_push_80007514(new cc24a_UtilityV2D);
  return 1;
 }
 cc24a_done_804aa594=1; return 0;
}
