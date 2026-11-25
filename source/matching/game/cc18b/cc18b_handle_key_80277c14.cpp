extern "C" {
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-23 (third session), eleventh batch: a key
 * handler mapping a character's position in one of two sets to a command. */
struct Cc18bKeyOwner { unsigned char unknown[92]; int selection; };

extern char *lbl_804abb9c;
extern char *lbl_804abba0;
char *fn_802ef198(const char *, int);
void fn_80275f18(void *);
void fn_802761b8(void *, void *, int);

void w3d_cc18b_handle_key_80277c14(Cc18bKeyOwner *self, int key)
{
    char *set;
    char *found;
    if (key == 27) {
        fn_80275f18(self);
        return;
    }
    found = fn_802ef198(lbl_804abb9c, key);
    set = lbl_804abb9c;
    if (!found) {
        set = lbl_804abba0;
        found = fn_802ef198(set, key);
        if (!found)
            return;
    }
    switch (found - set) {
    case 0: fn_802761b8(self, (void *)self->selection, 20); break;
    case 1: fn_802761b8(self, (void *)self->selection, 21); break;
    case 2: fn_802761b8(self, (void *)self->selection, 23); break;
    case 3: fn_802761b8(self, (void *)self->selection, 24); break;
    case 4: fn_802761b8(self, (void *)self->selection, 25); break;
    case 5: fn_802761b8(self, (void *)self->selection, 26); break;
    case 6: fn_802761b8(self, (void *)self->selection, 27); break;
    case 7: fn_802761b8(self, (void *)self->selection, 28); break;
    case 8: fn_802761b8(self, (void *)self->selection, 29); break;
    }
}

}
