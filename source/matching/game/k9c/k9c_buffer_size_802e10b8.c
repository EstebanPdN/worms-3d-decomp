int w3d_k9c_buffer_size_802e10b8(char *self) {
    char *o = *(char **)(self + 4);
    unsigned width;
    unsigned chroma;
    unsigned total;
    unsigned aligned;
    if (*(int *)(o + 160) != 0) {
        unsigned h = *(unsigned *)(o + 132);
        unsigned w = *(unsigned *)(o + 128);
        unsigned plane = *(unsigned *)(o + 68);
        width = w * h;
        // PERM
        total = ((plane + 31) & ~31u) * 10;
        chroma = ((width >> 2) + 31) & ~31u;
        aligned = (width + 31) & ~31u;
        // ENDPERM
        total = total + aligned + chroma + chroma;
        if (*(int *)(o + 172) != 0)
            total += (((*(unsigned *)(o + 72) << 2) + 31) & ~31u) << 2;
        return total + 4096;
    }
    return 0;
}
