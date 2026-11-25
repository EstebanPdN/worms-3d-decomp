typedef struct S20EffectMsg {
    unsigned short id;
    unsigned short pad2;
    void *table;
    int kind;
    int variant;
    unsigned short count;
    unsigned short extra;
    unsigned char flag;
    char pad21[3];
    float x;
    float y;
    float z;
} S20EffectMsg;
extern S20EffectMsg *fn_801613f0(void *, int);
extern void fn_8015fc84(char *, S20EffectMsg *);
extern void *lbl_804b1754;
extern char lbl_8040db38[];
extern int lbl_803fe234[];
extern float lbl_803a4660[];

void w3d_s20effect_80160780(char *self, int unused, int index) {
    S20EffectMsg *message = fn_801613f0(lbl_804b1754, 36);
    int variant = lbl_803fe234[index];
    float x = *(float *)(self + 32);
    float y = *(float *)(self + 36);
    float z = lbl_803a4660[0];
    message->id = 4100;
    message->table = lbl_8040db38;
    message->kind = 2;
    message->variant = variant;
    message->extra = 0;
    message->flag = 0;
    message->x = x;
    message->y = y;
    message->z = z;
    message->count = 0;
    fn_8015fc84(self, message);
}
