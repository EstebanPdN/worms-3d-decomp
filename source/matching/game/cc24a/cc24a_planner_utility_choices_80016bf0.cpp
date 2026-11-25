// Original GWMP8P 0x80016bf0: append eligible utility plans; names inferred.
// Native new-expression preserves allocation/constructor ownership and cleanup ABI.
typedef unsigned int cc24a_u32;
extern "C" void *cc24a_allocate_8001523c(unsigned int);
inline void *operator new(unsigned int size) { return cc24a_allocate_8001523c(size); }
struct cc24a_UtilityBase { int state; float cost; int unknown8; cc24a_u32 *dispatch; cc24a_UtilityBase() __asm__("cc24a_base_80006360"); };
extern cc24a_u32 cc24a_dispatch_8040da58[],cc24a_dispatch_8040da28[],cc24a_dispatch_8040d9c8[],cc24a_dispatch_8040d9f8[];
struct cc24a_UtilityA:cc24a_UtilityBase { cc24a_UtilityA(){dispatch=cc24a_dispatch_8040da58;} };
struct cc24a_UtilityB:cc24a_UtilityBase { cc24a_UtilityB(){dispatch=cc24a_dispatch_8040da28;} };
struct cc24a_UtilityC:cc24a_UtilityBase { cc24a_UtilityC(){dispatch=cc24a_dispatch_8040d9c8;} };
struct cc24a_UtilityD:cc24a_UtilityBase { cc24a_UtilityD(){dispatch=cc24a_dispatch_8040d9f8;} };
extern int cc24a_ready_804aa6dc,cc24a_busy_804aa6e0,cc24a_mode_804aa5a0,cc24a_extra_804aa58c,cc24a_done_804aa594;
extern "C" void cc24a_push_80007514(cc24a_UtilityBase*);
extern "C" int cc24a_available_80007ccc(int);
inline bool cc24a_ready(){return cc24a_ready_804aa6dc && !cc24a_busy_804aa6e0;}
extern "C" int cc24a_planner_utility_choices_80016bf0() {
 if(cc24a_ready()) {
  if(!cc24a_mode_804aa5a0) {
   cc24a_push_80007514(new cc24a_UtilityA);
   if(!cc24a_extra_804aa58c) {
    cc24a_push_80007514(new cc24a_UtilityB);
    cc24a_push_80007514(new cc24a_UtilityC);
   }
  }
  if(cc24a_available_80007ccc(47))cc24a_push_80007514(new cc24a_UtilityD);
  return 1;
 }
 cc24a_done_804aa594=1; return 0;
}
