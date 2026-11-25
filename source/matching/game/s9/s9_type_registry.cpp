/* Inferred static type registration and zero-initialized shared resource slots. */
inline void *operator new(unsigned int,void *p) {return p;}
struct S9RegisteredType;

struct S9RegisteredType {
    int words[8];
    S9RegisteredType(char *name,char *base,void (*factory)(),int flags,int size);
};
struct S9StaticSlot {
    unsigned int value;
    void clear() { value=0; }
};
extern "C" {
extern S9RegisteredType lbl_80361b08;
extern char lbl_803e89c8[],lbl_80361f58[];
void fn_8016fb54(void);

extern S9StaticSlot lbl_804b0128,lbl_804b012c,lbl_804b0130,lbl_804b0134,lbl_804b0138,lbl_804b013c,lbl_804b0140,lbl_804b0144,lbl_804b0148,lbl_804b014c,lbl_804b0150;
extern S9StaticSlot lbl_804b0124;
}
extern "C" void s9_initialize_shared_properties_80172a0c(int initialize,int priority) {
    if(priority==0xffff && initialize) {
        new (&lbl_80361b08) S9RegisteredType(lbl_803e89c8,lbl_80361f58,fn_8016fb54,0,0);
        lbl_804b0124.clear();
        lbl_804b0128.clear();
        lbl_804b012c.clear();
        lbl_804b0130.clear();
        lbl_804b0134.clear();
        lbl_804b0138.clear();
        lbl_804b013c.clear();
        lbl_804b0140.clear();
        lbl_804b0144.clear();
        lbl_804b0148.clear();
        lbl_804b014c.clear();
        lbl_804b0150.clear();

    }
}
