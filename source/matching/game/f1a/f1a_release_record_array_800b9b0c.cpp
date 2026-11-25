// Original 0x800b9b0c; observed slots and virtual table offsets only.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
typedef void (*F1aReleaseFn)(void *);
inline void release_slot(void **slot,void *zero) {
 if(*slot) ((F1aReleaseFn)(*(void ***)*slot)[4])(*slot);
 *slot=zero;
}
extern "C" {
extern char *lbl_804b183c;
int w3d_f1a_release_record_array_800b9b0c(char *self) {
 unsigned i=0;void *zero=0;
 void **e=(void **)(self+3152);
void **d=(void **)(self+3148);
void **c=(void **)(self+3144);
void **b=(void **)(self+3140);
 do {
  release_slot(e-4,zero);
  if(e[-3])((F1aReleaseFn)(*(void ***)e[-3])[4])(e[-3]);*b=zero;
  if(e[-2])((F1aReleaseFn)(*(void ***)e[-2])[4])(e[-2]);*c=zero;
  if(e[-1])((F1aReleaseFn)(*(void ***)e[-1])[4])(e[-1]);*d=zero;
  release_slot(e,zero);
  ++i;e+=6;d+=6;c+=6;b+=6;
 }while(i<128);
 ((F1aReleaseFn)FIELD(lbl_804b183c,void **,2792)[4])(lbl_804b183c);
 return 0;
}
}
