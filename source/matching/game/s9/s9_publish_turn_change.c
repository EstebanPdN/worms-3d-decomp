/* Hand-matched control flow and inferred field types. */
#define S9_FIELD(p,T,o) (*(T)((char *)(p)+(o)))
int fn_800FC1F0(int **, int *);             /* extern */
int fn_800FC3B0(int **, int);               /* extern */
void *fn_800FC6DC(int);                                /* extern */
int fn_801555F8(void *);                        /* extern */
int fn_80155688(void *);                              /* extern */
int fn_80155784(void *, int);                       /* extern */
int fn_801558DC(void *, int);                       /* extern */
int fn_80155C9C(void *, int);                   /* extern */
short fn_8015F5A0(int *, int);                /* extern */
void *fn_801613F0(void *, int);                    /* extern */
int fn_8016239C(void *);                        /* extern */
int fn_80178C54(void *,int *);                         /* extern */
int fn_8021C32C(void *);                              /* extern */
int fn_803426B4(int);                           /* extern */
extern int lbl_803A27AC[];
extern int lbl_803A27F0[];
extern int lbl_803A2A7C[];
extern int lbl_803A2A90[];
extern int lbl_8040DB38[];
extern int lbl_804ABAC0;
extern int lbl_804AFE50;
extern int lbl_804AFEB8;
extern int lbl_804B1754;

void s9_publish_turn_change_80155e24(void *self) {
    int *active_worm_name;
    int active_worm;
    int *last_worm_name;
    int *last_team_name;
    int *current_team_name;
    int current_team;
    int *next_team_name;
    int next_team;
    int next_worm;
    int last_team;
    void *team_message;
    void *turn_message;

    last_team = -1;
    fn_80155688(self);
    fn_801555F8(self);
    active_worm_name = &(*lbl_803A27AC);
    fn_800FC1F0(&active_worm_name, &active_worm);
    last_worm_name = &(*lbl_803A2A7C);
    fn_800FC3B0(&last_worm_name, active_worm);
    if (active_worm == -1) {
        goto block_2;
    }
    last_team = S9_FIELD(fn_800FC6DC(active_worm), unsigned char *, 0xD5);
    last_team_name = &(*lbl_803A2A90);
    fn_800FC3B0(&last_team_name, (int) last_team);
block_2:
    current_team = -1;
    current_team_name = &(*lbl_803A27F0);
    fn_800FC1F0(&current_team_name, &current_team);
    next_team_name = &(*lbl_803A2A90);
    fn_800FC3B0(&next_team_name, current_team);
    next_team = -1;
    next_team = fn_80155784(self, current_team);
    fn_80155C9C(self, current_team);
    if ((int) last_team <= next_team) {
        goto block_4;
    }
    team_message = fn_801613F0(lbl_804B1754, 8);
    S9_FIELD(team_message, short *, 0) = fn_8015F5A0(&lbl_804AFEB8, 1);
    S9_FIELD(team_message, int **, 4) = &(*lbl_8040DB38);
    fn_8016239C(team_message);
block_4:
    if (next_team == -1) {
        goto block_6;
    }
    fn_80178C54(fn_803426B4(S9_FIELD(self, int *, 0x130)),&next_team);
block_6:
    next_worm = fn_801558DC(self, next_team);
    active_worm = next_worm;
    if (next_worm == -1) {
        goto block_8;
    }
    fn_80178C54(fn_803426B4(S9_FIELD(self, int *, 0x128)),&active_worm);
block_8:
    turn_message = fn_801613F0(lbl_804B1754, 8);
    S9_FIELD(turn_message, short *, 0) = fn_8015F5A0(&lbl_804AFE50, 1);
    S9_FIELD(turn_message, int **, 4) = &(*lbl_8040DB38);
    fn_8016239C(turn_message);
    if ((int) lbl_804ABAC0 == 0) {
        goto block_11;
    }
    if (active_worm == -1) {
        goto block_11;
    }
    fn_8021C32C(lbl_804ABAC0);
block_11:
    S9_FIELD(self, int *, 0x19C) = 0;
    return;
}
