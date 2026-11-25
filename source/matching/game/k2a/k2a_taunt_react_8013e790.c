typedef struct K2aSlotInfo { char pad0[213]; unsigned char team; } K2aSlotInfo;
typedef struct K2aTaunter { char pad0[84]; void *current; char pad58[24]; int actor; } K2aTaunter;
extern char w3d_str_8039fcc0[];
extern char w3d_str_8039fcc8[];
extern char w3d_str_8039fcd4[];
extern char w3d_str_8039fcdc[];
extern char w3d_str_8039fcec[];
extern char w3d_str_8039fcf8[];
extern char w3d_str_8039e988[];
extern char w3d_str_8039e990[];
extern int w3d_get_800a830c(void *message);
extern K2aSlotInfo *s8_index_query_800fc6dc(unsigned int index);
extern void *w3d_empty_803426b4(void *);
extern unsigned int w3d_auto_80178c48(void *);
extern unsigned int fn_80162C20(void);
extern void FUN_8013bd0c(K2aTaunter *self, const char *text);

void k2a_taunt_react_8013e790(K2aTaunter *self, void *message)
{
    int who = w3d_get_800a830c(message);
    if (who == self->actor) {
        K2aSlotInfo *attacker = s8_index_query_800fc6dc(who);
        K2aSlotInfo *me = s8_index_query_800fc6dc(w3d_auto_80178c48(w3d_empty_803426b4(self->current)));
        if (me->team == attacker->team) {
            FUN_8013bd0c(self, w3d_str_8039fcc0);
        } else {
            unsigned int roll = fn_80162C20();
            int pick = roll % 7;
            switch (pick) {
            case 0: FUN_8013bd0c(self, w3d_str_8039fcc8); break;
            case 1: FUN_8013bd0c(self, w3d_str_8039fcd4); break;
            case 2: FUN_8013bd0c(self, w3d_str_8039fcdc); break;
            case 3: FUN_8013bd0c(self, w3d_str_8039fcec); break;
            case 4: FUN_8013bd0c(self, w3d_str_8039fcf8); break;
            case 5: FUN_8013bd0c(self, w3d_str_8039e988); break;
            case 6: FUN_8013bd0c(self, w3d_str_8039e990); break;
            }
        }
    }
}
