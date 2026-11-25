/* Video-format-specific movie tables and category selection. */
extern "C" {
struct S5MovieRecord { const char *name; int category; unsigned value; };
extern S5MovieRecord w3d_movie_table_803f5728[],w3d_movie_table_803f58b4[];
extern const char w3d_str_803876ac[],w3d_str_803876c4[];
unsigned w3d_tv_format_80304de0(void);
void w3d_panic_802fb82c(const char *,int,const char *,...);
unsigned strlen(const char *);
int w3d_text_case_compare_802ef074(const char *,const char *);
unsigned fn_80162BA8(void);
/* 0x800c6100: induction setup differs after two attempts. */
#if 0
int w3d_movie_category_for_name_800c6100(void *unused,const char *name)
{
    S5MovieRecord *table;
    switch (w3d_tv_format_80304de0()) {
    case 1: table=w3d_movie_table_803f5728; break;
    case 0:
    case 2: table=w3d_movie_table_803f58b4; break;
    default: w3d_panic_802fb82c(w3d_str_803876ac,300,w3d_str_803876c4); break;
    }
    for (unsigned index=0;strlen(table[index].name) && table[index].category!=29;++index) {
        if (!w3d_text_case_compare_802ef074(table[index].name,name)) return table[index].category;
    }
    return 29;
}
#endif
/* 0x800c61d8: table/category register pair remains swapped after five attempts. */
#if 0
unsigned w3d_movie_choose_category_800c61d8(void *unused,int category)
{
    S5MovieRecord *table;
    switch (w3d_tv_format_80304de0()) {
    case 1: table=w3d_movie_table_803f5728; break;
    case 0:
    case 2: table=w3d_movie_table_803f58b4; break;
    default: w3d_panic_802fb82c(w3d_str_803876ac,339,w3d_str_803876c4); break;
    }
    int count=0;
    if (table->category!=29) {
        int *tag=&table->category;
        do { if (*tag==category) ++count; tag+=3; } while (*tag!=29);
    }
    unsigned choice=fn_80162BA8()%count;
    if (table->category!=29) {
        int *tag=&table->category;
        S5MovieRecord *entry=table;
        do {
            if (*tag==category) {
                if (!choice) return entry->value;
                --choice;
            }
            tag+=3; ++entry;
        } while (*tag!=29);
    }
    return 0;
}
#endif
}
