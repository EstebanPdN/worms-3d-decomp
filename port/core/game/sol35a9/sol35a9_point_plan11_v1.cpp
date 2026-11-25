#include "w3d_ptr.h"
#line 1 "sol35a9_point_plan11_v1.cpp"
// Fresh declaration-consistent alternative; 8002274c consumes and stores a base pointer.
// Prior exact draft/proof remains frozen. Same original extent; never double-count.
// Independent native entry 8000848c, type 11, table 8040dc08.
// New inferred types; no shared-provider identity or whole-program ODR claim.
// Native pointer/Sol35a9Vec3 lifetimes; names and complete class identities inferred.
inline void *operator new(__SIZE_TYPE__,void *place) { return place; }
extern "C" Ptr32<unsigned char> sol35a9_allocate_80212fd4(unsigned);
extern "C" void sol35a9_release_802134fc(Ptr32<void>);
extern "C" Ptr32<void> sol35a9_copy_802eee50(Ptr32<void>,Ptr32<const void>,...);
inline const int &sol35a9_larger(const int &a,const int &b) {return a<b?b:a;}
inline const unsigned &sol35a9_smaller(const unsigned &a,const unsigned &b) {return b<a?b:a;}
struct Sol35a9PlanBase;
struct Sol35a9PlanStorage {
    Ptr32<unsigned char> begin; Ptr32<unsigned char> end; Ptr32<unsigned char> capacity;
    void push(Ptr32<Sol35a9PlanBase> const &value) {
        if (end==capacity) {
            unsigned used=end-begin;
            int next=used+1;
            int grown=used+(used>>1);
            unsigned allocated=sol35a9_larger(next,grown)*4;
            Ptr32<unsigned char> fresh=sol35a9_allocate_80212fd4(allocated);
            if (begin) {
                sol35a9_copy_802eee50(fresh,begin,sol35a9_smaller(allocated,used));
                sol35a9_release_802134fc(begin);
            }
            begin=fresh;
            end=fresh+used;
            capacity=fresh+allocated;
        }
        *(Ptr32<Sol35a9PlanBase> *)w3d::w3d_any_host(end) = Ptr32<Sol35a9PlanBase>(value);
        end+=4;
    }
};

struct Sol35a9Vec3 {
 float x,y,z;
 Sol35a9Vec3() {}
 Sol35a9Vec3(const Sol35a9Vec3 &v) {float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}
};
extern char sol35a9_table_8040dc08[];
struct Sol35a9PlanBase {unsigned unknown00,link4,link8,type;Ptr32<void> table;};
struct Sol35a9PointPlan11 : Sol35a9PlanBase {
 Sol35a9Vec3 target __attribute__((aligned(__alignof__(Sol35a9PlanBase))));
 void initialize() {link4=0;link8=0;table=sol35a9_table_8040dc08;type=11;}
 void setTarget(Sol35a9Vec3 value) {target=value;}
};
extern Ptr32<Sol35a9PlanStorage> sol35a9_plans_804aa564;
extern Ptr32<void> sol35a9_registry_804aa5a4;
extern "C" Ptr32<void> sol35a9_allocate_8001523c(unsigned);
extern "C" void sol35a9_register_8002274c(Ptr32<void>,Ptr32<Sol35a9PlanBase>);
extern "C" void sol35a9_point_plan11_v1_8000848c(Ptr32<const Sol35a9Vec3> target) {
 Ptr32<Sol35a9PointPlan11> plan=new (sol35a9_allocate_8001523c(sizeof(Sol35a9PointPlan11))) Sol35a9PointPlan11;
 plan->initialize();
 sol35a9_plans_804aa564->push(w3d::sc<Sol35a9PlanBase *>(plan));
 plan->setTarget(*target);
 sol35a9_register_8002274c(sol35a9_registry_804aa5a4,plan);
}
typedef char sol35a9_point_plan_size[sizeof(Sol35a9PointPlan11)==32?1:-1];
typedef char sol35a9_vec_size[sizeof(Sol35a9Vec3)==12?1:-1];


