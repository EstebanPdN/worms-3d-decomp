#include "w3d_ptr.h"
#line 1 "sol35a8_point_plan_v2.cpp"
// Native pointer/Vec3 lifetimes; names and complete class identities inferred.
inline void *operator new(__SIZE_TYPE__,void *place) { return place; }
extern "C" Ptr32<unsigned char> sol35a8_allocate_80212fd4(unsigned);
extern "C" void sol35a8_release_802134fc(Ptr32<void>);
extern "C" Ptr32<void> sol35a8_copy_802eee50(Ptr32<void>,Ptr32<const void>,...);
inline const int &larger(const int &a,const int &b) {return a<b?b:a;}
inline const unsigned &smaller(const unsigned &a,const unsigned &b) {return b<a?b:a;}
struct PlanBase;
struct Storage {
    Ptr32<unsigned char> begin; Ptr32<unsigned char> end; Ptr32<unsigned char> capacity;
    void push(Ptr32<PlanBase> const &value) {
        if (end==capacity) {
            unsigned used=end-begin;
            int next=used+1;
            int grown=used+(used>>1);
            unsigned allocated=larger(next,grown)*4;
            Ptr32<unsigned char> fresh=sol35a8_allocate_80212fd4(allocated);
            if (begin) {
                sol35a8_copy_802eee50(fresh,begin,smaller(allocated,used));
                sol35a8_release_802134fc(begin);
            }
            begin=fresh;
            end=fresh+used;
            capacity=fresh+allocated;
        }
        *(Ptr32<PlanBase> *)w3d::w3d_any_host(end) = Ptr32<PlanBase>(value);
        end+=4;
    }
};

struct Vec3 {
 float x,y,z;
 Vec3() {}
 Vec3(const Vec3 &v) {float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}
};
extern char sol35a8_table_8040dc68[];
struct PlanBase {unsigned unknown00,link4,link8,type;Ptr32<void> table;};
struct PointPlan : PlanBase {
 Vec3 target __attribute__((aligned(__alignof__(PlanBase))));
 void initialize() {link4=0;link8=0;table=sol35a8_table_8040dc68;type=10;}
 void setTarget(Vec3 value) {target=value;}
};
extern Ptr32<Storage> sol35a8_plans_804aa564;
extern Ptr32<void> sol35a8_registry_804aa5a4;
extern "C" Ptr32<void> sol35a8_allocate_8001523c(unsigned);
extern "C" void sol35a8_register_8002274c(Ptr32<void>,Ptr32<PointPlan>);
extern "C" void sol35a8_point_plan_8000831c(Ptr32<const Vec3> target) {
 Ptr32<PointPlan> plan=new (sol35a8_allocate_8001523c(sizeof(PointPlan))) PointPlan;
 plan->initialize();
 sol35a8_plans_804aa564->push(w3d::sc<PlanBase *>(plan));
 plan->setTarget(*target);
 sol35a8_register_8002274c(sol35a8_registry_804aa5a4,plan);
}
typedef char point_plan_size[sizeof(PointPlan)==32?1:-1];
typedef char vec_size[sizeof(Vec3)==12?1:-1];


