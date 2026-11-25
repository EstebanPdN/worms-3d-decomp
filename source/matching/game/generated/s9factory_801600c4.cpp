/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Inferred static factory record fields and registration. */
struct S9FactoryRecord;
struct S9FactoryList;
typedef void (*S9FactoryCallback)(void);
extern "C" void fn_80200af8(S9FactoryRecord *);
struct S9FactoryRecord {
    S9FactoryRecord *next;
    char *name;
    S9FactoryCallback first;
    S9FactoryCallback second;
    int priority;
    S9FactoryList *list;

};
extern "C" {
int fn_80160028(void);
int fn_80160030(void);
extern char lbl_803a4630[],lbl_803e8808[],lbl_80361800[];
extern S9FactoryRecord lbl_80455214;
extern S9FactoryList lbl_80455288;
void * fn_8020fbd0(char *,char *,char *,void *,int,int);
}
extern "C" {
int fn_8016114c(void);
int fn_80161154(void);
extern char lbl_803a46f0[],lbl_803e885c[],lbl_80361890[];
extern S9FactoryRecord lbl_8045522c;
extern S9FactoryList lbl_80455288;
void * fn_8020fbd0(char *,char *,char *,void *,int,int);
}
extern "C" {
int fn_801629e8(void);
int fn_801629f0(void);
extern char lbl_803a4a04[],lbl_803e88b0[],lbl_80361920[];
extern S9FactoryRecord lbl_8045525c;
extern S9FactoryList lbl_80455288;
void * fn_8020fbd0(char *,char *,char *,void *,int,int);
}

extern "C" void s9_initialize_factory_type_801600c4(int initialize,int priority) {
    if(priority==0xffff && initialize) {
        S9FactoryRecord *record=&lbl_80455214;
        record->name=lbl_803a4630;
        record->first=(void (*)(void))fn_80160028;
        record->second=(void (*)(void))fn_80160030;
        record->list=&lbl_80455288;
        record->priority=0;
        fn_80200af8(record);
        fn_8020fbd0(lbl_80361800,lbl_803e8808,lbl_80361800,0,4,0);
    }
}

extern "C" void s9_initialize_factory_type_801611e8(int initialize,int priority) {
    if(priority==0xffff && initialize) {
        S9FactoryRecord *record=&lbl_8045522c;
        record->name=lbl_803a46f0;
        record->first=(void (*)(void))fn_8016114c;
        record->second=(void (*)(void))fn_80161154;
        record->list=&lbl_80455288;
        record->priority=0;
        fn_80200af8(record);
        fn_8020fbd0(lbl_80361890,lbl_803e885c,lbl_80361890,0,4,0);
    }
}

extern "C" void s9_initialize_factory_type_80162a84(int initialize,int priority) {
    if(priority==0xffff && initialize) {
        S9FactoryRecord *record=&lbl_8045525c;
        record->name=lbl_803a4a04;
        record->first=(void (*)(void))fn_801629e8;
        record->second=(void (*)(void))fn_801629f0;
        record->list=&lbl_80455288;
        record->priority=0;
        fn_80200af8(record);
        fn_8020fbd0(lbl_80361920,lbl_803e88b0,lbl_80361920,0,4,0);
    }
}
