/* Observed planner globals; names and ownership are provisional. */
typedef unsigned int u32;
typedef unsigned char u8;
extern int lbl_804aa6c0, lbl_804aa6c4, lbl_804aa6c8, lbl_804aa6cc, lbl_804aa6d0, lbl_804aa6d8, lbl_804aa6dc, lbl_804aa598, lbl_804aa59c;
extern u32 lbl_8041d3a0[], lbl_8041d3ac[];
extern char lbl_8036a588[];
extern u8 *fn_800fc6dc(int); extern int fn_800154b4(int); extern u32 *fn_80015588(int);
extern int fn_800154e0(int), fn_800fcb4c(int); extern void fn_800fc230(char **, int *); extern void fn_80006ff4(void);
void tterra_z37_init_800152fc(int x) {
 u32 *v; char *key; int result;
 lbl_804aa6c0=x; lbl_804aa6cc=fn_800fc6dc(x)[0xd5]; lbl_804aa6d0=fn_800154b4(x);
 v=fn_80015588(x);
 lbl_8041d3a0[0]=v[0]; lbl_8041d3a0[2]=v[2]; lbl_8041d3a0[1]=v[1];
 lbl_8041d3ac[0]=lbl_8041d3a0[0]; lbl_8041d3ac[1]=lbl_8041d3a0[1]; lbl_8041d3ac[2]=lbl_8041d3a0[2];
 lbl_804aa6dc=fn_800154e0(x); lbl_804aa6d8=fn_800fcb4c(lbl_804aa6c0);
 key=lbl_8036a588; lbl_804aa6c8=x; fn_800fc230(&key,&result);
 if(result && !lbl_804aa598) { lbl_804aa6c4=x; fn_80006ff4(); lbl_804aa59c=1; }
}
