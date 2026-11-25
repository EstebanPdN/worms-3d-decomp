extern void fn_802fa988(void *, unsigned int);
extern void fn_80307d88(int, void *, int);
int terra_only_b_buffer_80168c8c(char *self, char *arg)
{
    char *owner = self ? self - 4 : 0;
    char *buffer = *(char **)(arg + 20);
    unsigned int count = *(unsigned int *)(buffer + 24);
    char *data = buffer + 32;
    if (count) {
        unsigned int size = count << 3;
        if (*(unsigned short *)(buffer + 28)) {
            fn_802fa988(data, size);
            *(unsigned short *)(buffer + 28) = 0;
        }
        fn_80307d88(13, data, 8);
        *(unsigned int *)(owner + 288) |= 128;
        ++*(unsigned int *)(owner + 284);
    }
    return 0;
}
