/* Experimental candidate: relocation-masked differences remain; no linked proof. */
struct Vec { float x,y,z; Vec(const Vec &v) { float a=v.x, b=v.y, c=v.z; x=a; y=b; z=c; } };
struct Source { char pad[20]; Vec value; };
struct Message { char pad[8]; int kind; char pad2[4]; Vec value; };
extern "C" {
extern void *tterra_a26_queue_804b1754;
void tterra_a26_prepare_801613f0(void *, int);
Message *tterra_a26_construct_80131a84(void);
void tterra_a26_post_8016239c(Message *);
int tterra_a26_motion_80021c60(Source *s) { tterra_a26_prepare_801613f0(tterra_a26_queue_804b1754,236); Message *m=tterra_a26_construct_80131a84(); m->kind=5; m->value=Vec(s->value); tterra_a26_post_8016239c(m); return 0; }
int tterra_a26_motion_80021d8c(Source *s) { tterra_a26_prepare_801613f0(tterra_a26_queue_804b1754,236); Message *m=tterra_a26_construct_80131a84(); m->kind=15; m->value=Vec(s->value); tterra_a26_post_8016239c(m); return 0; }
}
