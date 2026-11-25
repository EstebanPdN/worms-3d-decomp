struct Mark { unsigned int addr; unsigned int size; };
extern unsigned int lbl_804ab954;
extern int lbl_804ab950;
extern struct Mark lbl_8045ebf8[];
extern char lbl_803b28e4[];
extern unsigned int fn_802fa668(void);
extern unsigned int fn_802fa670(void);
extern int fn_802fb7ac(const char *, ...);
unsigned int tsonnet_c26_temp_alloc_801fe0b8(unsigned int size) {
 unsigned int top, low;
 int i;
 size = (size + 31) & ~31u;
 if (lbl_804ab954 == 0) lbl_804ab954 = fn_802fa668() & ~31u;
 lbl_804ab954 = lbl_804ab954 - size;
 low = (fn_802fa670() + 31) & ~31u;
 top = lbl_804ab954;
 if (top > low) {
  i = lbl_804ab950;
  lbl_8045ebf8[i].addr = top;
  lbl_8045ebf8[i].size = size;
  lbl_804ab950 = i + 1;
  return top;
 }
 fn_802fb7ac(lbl_803b28e4);
 return 0;
}
