/* Tables map external reel values to their visible indices. */
extern "C" {
extern const int w3d_table_803d6b7c[],w3d_table_803d6bd0[],w3d_table_803d6c24[];
int w3d_s4_wormpot_find_value(void *,int reel,int value)
{
    const int *table;
    unsigned count;
    if(reel==0) { table=w3d_table_803d6b7c;count=21; }
    else if(reel==1) { table=w3d_table_803d6bd0;count=21; }
    else { table=w3d_table_803d6c24;count=16; }
    unsigned i=0;
    if(i<count) {
        const int *cursor=table;
        do {
            if(*cursor++==value) return i;
            ++i;
        } while(i<count);
    }
    return -1;
}
}
