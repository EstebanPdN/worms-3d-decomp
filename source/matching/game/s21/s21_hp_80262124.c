// desc: Appears to build a property key for the game-over game type string and pass it to the property reader.
struct S21Key { const char *name; };
extern const char lbl_803cae50[];
extern int fn_800fc550(struct S21Key *, int);
int w3d_s21_read_game_type_80262124(void *self, int fallback)
{
    struct S21Key key;
    key.name = lbl_803cae50;
    return fn_800fc550(&key, fallback);
}
