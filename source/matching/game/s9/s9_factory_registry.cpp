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
void fn_80160028(void);
void fn_80160030(void);
extern char lbl_803a4630[],lbl_803e8808[],lbl_80361800[];
extern S9FactoryRecord lbl_80455214;
extern S9FactoryList lbl_80455288;
void fn_8020fbd0(char *,char *,char *,void *,int,int);
}
extern "C" void s9_initialize_factory_type_801600c4(int initialize,int priority) {
    if(priority==0xffff && initialize) {
        S9FactoryRecord *record=&lbl_80455214;
        record->name=lbl_803a4630;
        record->first=fn_80160028;
        record->second=fn_80160030;
        record->list=&lbl_80455288;
        record->priority=0;
        fn_80200af8(record);
        fn_8020fbd0(lbl_80361800,lbl_803e8808,lbl_80361800,0,4,0);
    }
}
