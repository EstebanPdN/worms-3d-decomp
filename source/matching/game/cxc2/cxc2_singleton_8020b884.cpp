/* Original 0x8020b884. Observed lazy interface slot with a shared fallback.
 * The assignment returns whether its supplied pointer is null. This preserves
 * the condition across retain/release calls in the original nonvolatile CR.
 * Interface meanings and names are inferred; vtable byte offsets are observed.
 */
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
extern "C" void *lbl_804abaa4;
extern "C" void *lbl_804b0698;
extern "C" void *fn_801fe1d8(unsigned int);
extern "C" void *fn_80218284(void *);
static inline bool cxc2_assign(void **slot, void *p) {
 if (p) (*(void (**)(void *))((char *)FIELD(p,void *,0)+12))(p);
 if (*slot) {void *old=*slot; (*(void (**)(void *))((char *)FIELD(old,void *,0)+16))(old);}
 *slot=p; return p==0;
}
extern "C" void *cxc2_singleton_8020b884(void) {
 if (!lbl_804b0698) {
  void *fallback=lbl_804abaa4;
  bool missing=cxc2_assign(&lbl_804b0698,fallback);
  if (missing) cxc2_assign(&lbl_804b0698,fn_80218284(fn_801fe1d8(28)));
 }
 return lbl_804b0698;
}
