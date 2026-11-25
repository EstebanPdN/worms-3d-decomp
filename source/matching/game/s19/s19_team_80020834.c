struct S19Rec { char pad0[213]; unsigned char team; };
struct S19Team { char pad0[52]; int value; };
extern void *w3d_empty_803426b4(void *);
extern int w3d_auto_80178c48(void *);
extern struct S19Rec *s8_index_query_800fc6dc(int);
extern struct S19Team *s8_index_query_800fc7f8(int);

int s19_active_team_value_80020834(void *self)
{
    int handle = w3d_auto_80178c48(w3d_empty_803426b4(*(void **)((char *)self + 28)));
    if (handle == -1)
        return 0;
    return s8_index_query_800fc7f8(s8_index_query_800fc6dc(handle)->team)->value;
}
