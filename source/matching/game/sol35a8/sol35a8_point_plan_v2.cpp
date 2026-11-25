// Native pointer/Vec3 lifetimes; names and complete class identities inferred.
inline void *operator new(__SIZE_TYPE__,void *place) { return place; }
extern "C" unsigned char *sol35a8_allocate_80212fd4(unsigned);
extern "C" void sol35a8_release_802134fc(void *);
extern "C" void *sol35a8_copy_802eee50(void *,const void *,...);
inline const int &larger(const int &a,const int &b) {return a<b?b:a;}
inline const unsigned &smaller(const unsigned &a,const unsigned &b) {return b<a?b:a;}
struct PlanBase;
struct Storage {
    unsigned char *begin,*end,*capacity;
    void push(PlanBase *const &value) {
        if (end==capacity) {
            unsigned used=end-begin;
            int next=used+1;
            int grown=used+(used>>1);
            unsigned allocated=larger(next,grown)*4;
            unsigned char *fresh=sol35a8_allocate_80212fd4(allocated);
            if (begin) {
                sol35a8_copy_802eee50(fresh,begin,smaller(allocated,used));
                sol35a8_release_802134fc(begin);
            }
            begin=fresh;
            end=fresh+used;
            capacity=fresh+allocated;
        }
        new (end) PlanBase *(value);
        end+=4;
    }
};

struct Vec3 {
 float x,y,z;
 Vec3() {}
 Vec3(const Vec3 &v) {float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}
};
extern char sol35a8_table_8040dc68[];
struct PlanBase {unsigned unknown00,link4,link8,type;void *table;};
struct PointPlan : PlanBase {
 Vec3 target;
 void initialize() {link4=0;link8=0;table=sol35a8_table_8040dc68;type=10;}
 void setTarget(Vec3 value) {target=value;}
};
extern Storage *sol35a8_plans_804aa564;
extern void *sol35a8_registry_804aa5a4;
extern "C" void *sol35a8_allocate_8001523c(unsigned);
extern "C" void sol35a8_register_8002274c(void *,PointPlan *);
extern "C" void sol35a8_point_plan_8000831c(const Vec3 *target) {
 PointPlan *plan=new (sol35a8_allocate_8001523c(sizeof(PointPlan))) PointPlan;
 plan->initialize();
 sol35a8_plans_804aa564->push(static_cast<PlanBase *>(plan));
 plan->setTarget(*target);
 sol35a8_register_8002274c(sol35a8_registry_804aa5a4,plan);
}
typedef char point_plan_size[sizeof(PointPlan)==32?1:-1];
typedef char vec_size[sizeof(Vec3)==12?1:-1];
