struct S9InitReference {
    void *pointer;
    void initialize() { pointer=0; }
};
extern "C" {
struct S9TypeInfo {int words[8];};
extern S9TypeInfo lbl_80361b08;
extern char lbl_803e89c8[],lbl_80361f58[];
void fn_8016fb54();
void fn_8020fbd0(S9TypeInfo &,char *,char *,void (*)(),int,int);
extern S9InitReference lbl_804b0150,lbl_804b0128,lbl_804b012c,lbl_804b0130,lbl_804b0134,lbl_804b0138,lbl_804b013c,lbl_804b0140,lbl_804b0144,lbl_804b0148,lbl_804b014c;
extern int lbl_804b0124;
void s9_initialize_bitmap_resources_80172a0c(int initialize,int priority) {
    if(priority==0xffff && initialize) {
        fn_8020fbd0(lbl_80361b08,lbl_803e89c8,lbl_80361f58,fn_8016fb54,0,0);
        ((S9InitReference *)&lbl_804b0124)->initialize();
        lbl_804b0150.initialize();
        lbl_804b0128.initialize();
        lbl_804b012c.initialize();
        lbl_804b0130.initialize();
        lbl_804b0134.initialize();
        lbl_804b0138.initialize();
        lbl_804b013c.initialize();
        lbl_804b0140.initialize();
        lbl_804b0144.initialize();
        lbl_804b0148.initialize();
        lbl_804b014c.initialize();

    }
}
}
