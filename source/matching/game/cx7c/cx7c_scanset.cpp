/* Inferred newlib scanset parser, original 0x802ed50c. table has 256
 * byte flags. Input follows '['; returns just after closing ']' (or at
 * terminal NUL). Leading '^' inverts; first ']'/'-' is literal. Ranges
 * extend the previous character, preserving the original descending case.
 */
extern "C" const char *w3d_cx7c_scan_character_set_802ed50c(char *table,const char *format)
{
    int character=*format++;
    int invert;
    if (character=='^') {invert=1;character=*format++;}
    else invert=0;
    for (int index=0;index<256;++index) table[index]=invert;
    if (character==0) return format-1;
    invert=1-invert;
    for (;;) {
        table[character]=invert;
    next_character:
        int next=*format++;
        switch (next) {
        case 0:return format-1;
        case '-': {
            next=*format;
            if (next==']' || next<character) {character='-';break;}
            ++format;
            do {table[++character]=invert;} while (character<next);
            goto next_character;
        }
        case ']':return format;
        default:character=next;break;
        }
    }
}
