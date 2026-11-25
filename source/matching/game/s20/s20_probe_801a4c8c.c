typedef struct S20KindSource { char pad[32]; unsigned int word; } S20KindSource;
extern S20KindSource *lbl_80363938[];
extern void fn_801a4278(char *);
int w3d_s20_dispatch_kind_801a4c8c(char *self, char *item) {
    if ((*(unsigned char *)(item + 11) & 2) != 0)
        fn_801a4278(item);
    {
        void **table = *(void ***)(self + 24);
        unsigned int kind = (lbl_80363938[0]->word >> 22) & 1023;
        return ((int (*)(char *, char *))table[kind])(self, item);
    }
}

