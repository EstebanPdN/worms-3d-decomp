/* Copies halfwords of a display-list cursor to the graphics write pipe. */
extern volatile unsigned short lbl_cc008000[];

int w3d_s20_write_pipe_command_8016ac3c(int command, unsigned int count, char *object) {
    unsigned int flags = *(unsigned int *)(object + 180);
    if ((int)flags >= 0 && (flags & 0x40000000) == 0 && command == 290) {
        unsigned short *source = *(unsigned short **)(object + 160);
        unsigned short i = 0;
        while (i < count) {
            i++;
            lbl_cc008000[0] = *source;
            lbl_cc008000[0] = *source;
            lbl_cc008000[0] = *source;
            source++;
        }
        *(unsigned short **)(object + 160) = source;
        return 1;
    }
    return 0;
}
