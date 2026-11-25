typedef struct S20Rec { char pad[6]; unsigned short slot; } S20Rec;
typedef struct S20Item { char pad[92]; S20Rec *target; } S20Item;
typedef struct S20Self { char pad[24]; int (**table)(struct S20Self *, S20Rec *); } S20Self;
extern int fn_801a4874(S20Self *, S20Item *);
int w3d_s20_x_801a4968(S20Self *self, S20Item *item) {
    if (item->target == 0)
        return 0;
    {
        int result = self->table[item->target->slot](self, item->target);
        if (result < 0)
            return result;
    }
    return fn_801a4874(self, item);
}
