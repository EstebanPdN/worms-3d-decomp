// Observed 32-bit object words and global held interfaces. Semantic names inferred.
struct Cc22aPool8017077c { void *vtable; unsigned char unknown04[48]; unsigned int range34[3]; unsigned int range40[3]; void *held4c; void *rows50; };
extern "C" {
extern unsigned char lbl_80412008[];
extern int lbl_804b1898;
extern void *lbl_804b0124;
extern void *lbl_804b0128;
extern void *lbl_804b012c;
extern void *lbl_804b0130;
extern void *lbl_804b0134;
extern void *lbl_804b0138;
extern void *lbl_804b013c;
extern void *lbl_804b0140;
extern void *lbl_804b0144;
extern void *lbl_804b0148;
extern void *lbl_804b014c;
extern void *lbl_804b0150;
void fn_8034be70(void *,int);
void fn_80210abc(void *,int);
void fn_80190384(void *,int);
}
inline void cc22a_release(void *p) { if(p) ((void (*)(void *))(*(void ***)p)[4])(p); }
inline void cc22a_reset(void *&slot,void *value) { cc22a_release(slot);slot=value; }
extern "C" void cc22a_pool_shared_release_8017077c(Cc22aPool8017077c *self,int flags) {
int remaining=lbl_804b1898-1;
self->vtable=lbl_80412008;
lbl_804b1898=remaining;
if(remaining==0) {
cc22a_reset(lbl_804b0124,(void *)remaining);
cc22a_reset(lbl_804b0128,0);
cc22a_reset(lbl_804b012c,0);
cc22a_reset(lbl_804b0130,0);
cc22a_reset(lbl_804b0134,0);
cc22a_reset(lbl_804b0138,0);
cc22a_reset(lbl_804b013c,0);
cc22a_reset(lbl_804b0140,0);
cc22a_reset(lbl_804b0144,0);
cc22a_reset(lbl_804b0148,0);
cc22a_reset(lbl_804b014c,0);
cc22a_reset(lbl_804b0150,0);
}
if(self->rows50) fn_8034be70(self->rows50,3);
self->rows50=0;
cc22a_release(self->held4c);
fn_80210abc(self->range40,2);fn_80210abc(self->range34,2);fn_80190384(self,flags);
}
