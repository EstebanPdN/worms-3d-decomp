inline void *operator new(unsigned int,void *p) {return p;}
struct S9InitReference {
    void *pointer;
    S9InitReference() { pointer=0; }
};
extern "C" {
extern char lbl_80361b08[],lbl_803e89c8[],lbl_80361f58[];
void fn_8016fb54();
void fn_8020fbd0(char *,char *,char *,void (*)(),int,int);
extern S9InitReference lbl_804b0150,lbl_804b0128,lbl_804b012c,lbl_804b0130,lbl_804b0134,lbl_804b0138,lbl_804b013c,lbl_804b0140,lbl_804b0144,lbl_804b0148,lbl_804b014c;
extern int lbl_804b0124;
void s9_initialize_bitmap_resources_80172a0c(int initialize,int priority) {
    if(priority==0xffff && initialize) {
        fn_8020fbd0(lbl_80361b08,lbl_803e89c8,lbl_80361f58,fn_8016fb54,0,0);
        new (&lbl_804b0150) S9InitReference;
        new (&lbl_804b0128) S9InitReference;
        new (&lbl_804b012c) S9InitReference;
        new (&lbl_804b0130) S9InitReference;
        new (&lbl_804b0134) S9InitReference;
        new (&lbl_804b0138) S9InitReference;
        new (&lbl_804b013c) S9InitReference;
        new (&lbl_804b0140) S9InitReference;
        new (&lbl_804b0144) S9InitReference;
        new (&lbl_804b0148) S9InitReference;
        new (&lbl_804b014c) S9InitReference;
        lbl_804b0124=0;
    }
}
}
