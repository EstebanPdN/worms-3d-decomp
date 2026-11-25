char *w3d_s20_add_entry_8016e908(char *self) {
    int offset = *(int *)(self + 548) * 20 + 388;
    char *entry;
    *(int *)(self + offset) = 0;
    entry = self + offset;
    *(int *)(entry + 12) = 0;
    *(int *)(entry + 4) = 0;
    *(int *)(entry + 8) = 0;
    ++*(int *)(self + 548);
    return entry;
}
