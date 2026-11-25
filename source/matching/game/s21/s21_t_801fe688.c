// desc: Appears to parse a name into a boolean output (first literal gives one, second gives zero) or return the failure status 0x80004005.
extern const char lbl_803b298c[];
extern const char lbl_803b2994[];
extern int fn_802ef074(const char *, const char *);
int w3d_s21_parse_flag_name_801fe688(void *self, int *out, const char *name)
{
    int result;
    if (fn_802ef074(lbl_803b298c, name) == 0) {
        *out = 1;
        return 0;
    }
    result = fn_802ef074(lbl_803b2994, name);
    if (result != 0)
        return 0x80004005;
    *out = result;
    return 0;
}
