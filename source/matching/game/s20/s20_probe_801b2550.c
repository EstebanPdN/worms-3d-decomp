/* Padded buffer registration and a category count dump. */
extern void *memset();
extern int fn_8020bf2c(char *, char *);

int w3d_s20_pad_and_register_801b2550(char *self) {
    char buffer[64];
    memset(buffer, 32, *(int *)(self + 44));
    {
        int sum = *(int *)(self + 56);
        char *text = buffer;
        int length = *(int *)(self + 44);
        text[length] = 0;
        *(int *)(self + 56) = sum + length;
        return fn_8020bf2c(self + 60, text);
    }
}
