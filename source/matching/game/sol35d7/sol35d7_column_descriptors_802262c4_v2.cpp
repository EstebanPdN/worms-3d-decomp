namespace sol35d7_column_descriptors_v2 {
// Partial GC32 views; descriptor identities and all external calls have original witnesses.
struct Sol35d7ColumnBindingString;
extern "C" void fn_8020c5c0(Sol35d7ColumnBindingString *);
extern "C" void fn_8020c5c4(Sol35d7ColumnBindingString *);
extern "C" void fn_80341588(Sol35d7ColumnBindingString *);
extern "C" unsigned short *fn_80341884(Sol35d7ColumnBindingString *);
extern "C" void fn_8020bb2c(void *);
struct Sol35d7ColumnBindingString {
    char *data;
    Sol35d7ColumnBindingString(const Sol35d7ColumnBindingString &other) {
        fn_8020c5c0(this);
        data = other.data;
        ++*fn_80341884(this);
    }
    ~Sol35d7ColumnBindingString() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    Sol35d7ColumnBindingString &operator=(const Sol35d7ColumnBindingString &other) {
        ++*(unsigned short *)(other.data - 6);
        char *old = data;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short references = --*header;
        if (!references) fn_8020bb2c(header);
        data = other.data;
        return *this;
    }
};
struct Sol35d7ColumnTextBinding {
    unsigned unknown_00[2];
    Sol35d7ColumnBindingString value;
};

extern "C" void *fn_801eb674(void *,void *);
extern "C" void *fn_801ec52c(void *,void *);
extern "C" void *fn_801ece2c(void *,void *);
extern "C" Sol35d7ColumnTextBinding *fn_801ed24c(void *,void *);
extern "C" void fn_801e8d9c(void *);
extern Sol35d7ColumnBindingString lbl_804b06a0[];
extern unsigned char lbl_803b7ed8[],lbl_803b7f0c[],lbl_803b7f3c[],lbl_803b7f64[],lbl_803b7f9c[];
extern unsigned char lbl_803b7fc4[],lbl_803b7fcc[],lbl_8045ed94[],lbl_8045ed58[];
extern "C" void *fn_802eefe0(void *,int,unsigned,...);
struct Descriptor {
 const char *name;
 unsigned short size;
 unsigned char family,kind;
 void *type;
 unsigned metadata[2];
 Descriptor() { fn_802eefe0(this,0,sizeof(*this)); }
};
extern Descriptor lbl_80464a54[],lbl_80464a68[];
extern unsigned lbl_804b07dc,lbl_804b07e0;
extern "C" void *fn_801efff0(void *,Descriptor *);
extern "C" void *fn_801efe60(void *,Descriptor *);
typedef char DescriptorSize[(sizeof(Descriptor)==20)?1:-1];
}
extern "C" int sol35d7_column_descriptors_802262c4_v2(void *self) {
 using namespace sol35d7_column_descriptors_v2;
 {
  Sol35d7ColumnTextBinding *binding=fn_801ed24c(self,lbl_803b7ed8);
  Sol35d7ColumnBindingString text(lbl_804b06a0[0]);
  binding->value=text;
 }
 fn_801ec52c(self,lbl_803b7f0c);
 fn_801ec52c(self,lbl_803b7f3c);
 fn_801ece2c(self,lbl_803b7f64);
 fn_801eb674(self,lbl_803b7f9c);
 if(!lbl_804b07dc) {
  Descriptor d; d.size=24;d.family=5;d.kind=9;d.type=lbl_8045ed94;d.name=reinterpret_cast<const char *>(lbl_803b7fc4);
  lbl_80464a54[0]=d;
  lbl_804b07dc=1;
 }
 fn_801efff0(self,lbl_80464a54);
 if(!lbl_804b07e0) {
  Descriptor d; d.size=20;d.family=6;d.kind=9;d.type=lbl_8045ed58;d.name=reinterpret_cast<const char *>(lbl_803b7fcc);
  lbl_80464a68[0]=d;
  lbl_804b07e0=1;
 }
 fn_801efe60(self,lbl_80464a68);
 fn_801e8d9c(self);
 return 0;
}
