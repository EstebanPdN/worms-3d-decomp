// desc: Appears to initialize a record's default words and a mode-dependent code (0xa0..0xa4).
void w3d_k1f_init_mode_record_802abc28(int *p)
{
    int a = p[0];
    int b = p[4];
    int mode = p[5];
    p[9] = 176;
    p[16] = 208;
    p[42] = 0;
    p[47] = 224;
    p[107] = 192;
    p[104] = a;
    p[105] = b;
    p[2] = -1;
    p[6] = a;
    p[13] = a;
    p[14] = b;
    p[44] = a;
    p[46] = b;
    switch (mode) {
    case 1: p[1] = 161; break;
    case 3: p[1] = 163; break;
    case 2: p[1] = 164; break;
    case 0: p[1] = 160; break;
    }
}
