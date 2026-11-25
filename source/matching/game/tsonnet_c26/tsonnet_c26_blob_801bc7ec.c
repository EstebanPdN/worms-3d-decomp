struct Blob { int w[12]; };
struct Rec { int head[2]; struct Blob blob; };
extern char lbl_803ab88c[];
extern char lbl_803ab8b0[];
extern struct Blob lbl_8045e748;
extern struct Rec *fn_801f0e4c(void *, char *);
extern void * fn_801ebf38(void *, char *);
extern void fn_801e8d9c(void *);
int tsonnet_c26_register_blob_801bc7ec(void *self) {
 struct Rec *r = fn_801f0e4c(self, lbl_803ab88c);
 r->blob = lbl_8045e748;
 fn_801ebf38(self, lbl_803ab8b0);
 fn_801e8d9c(self);
 return 0;
}
