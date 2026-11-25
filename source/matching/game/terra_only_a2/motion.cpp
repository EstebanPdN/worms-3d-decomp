// GC32 views inferred from the original accesses; ownership is external.
struct Vec {
 float x,y,z;
 Vec(const Vec &v) { x=v.x; z=v.z; y=v.y; }
};
struct Source { char pad[20]; Vec value; Vec get() const { return value; } };
struct Message { char pad[8]; int kind; char pad2[4]; Vec value; };
extern "C" {
extern void *queue_804b1754;
void *allocate_801613f0(void *, int);
Message *construct_80131a84(void *);
void post_8016239c(Message *);
int terra_only_a2_motion_80021c60(Source *s) { Message *m=construct_80131a84(allocate_801613f0(queue_804b1754,236)); m->kind=5; m->value=s->get(); post_8016239c(m); return 0; }
int terra_only_a2_motion_80021d8c(Source *s) { Message *m=construct_80131a84(allocate_801613f0(queue_804b1754,236)); m->kind=15; m->value=s->get(); post_8016239c(m); return 0; }
}
