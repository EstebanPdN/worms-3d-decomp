// desc: Appears to split a text at its first newline: it terminates the first line, copies the remainder to the destination and returns one, or returns zero without a newline.
extern char *fn_802ef2fc(char *, const char *);
int w3d_s21_split_line_8028a2b0(int unused, char *dest, char *text)
{
    int found = 0;
    while (*text) {
        if (*text == 10) {
            found = 1;
            break;
        }
        text++;
    }
    if (found) {
        *text = 0;
        fn_802ef2fc(dest, text + 1);
        return 1;
    }
    return 0;
}
