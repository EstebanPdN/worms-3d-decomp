/* Triangle-strip group dispatch and parity updates. */
extern "C" {
typedef void (*S2Emit)(int, int, int, void *, unsigned short *, int);
struct S2Renderer {
    unsigned char pad00[44]; S2Emit emit;
    unsigned char pad30[680-48]; int *flags;
    unsigned char pad2ac[768-684]; unsigned char lowA[256], lowB[256], lowC[256], highA[256], highB[256], highC[256]; void **groups;
    unsigned char pad904[2364-2308]; unsigned short *counts;
    unsigned char pad940[2376-2368]; void **groups2;
    unsigned char pad94c[2436-2380]; unsigned short *counts2;
};
extern unsigned char w3d_obj_8044c6ec[];
extern unsigned char w3d_obj_8044c86c[];
void w3d_strip_group_8010b118(S2Renderer *, int, int, int, int, int);
void w3d_strip_group_8010b198(S2Renderer *, int, int, int, int, int);
void w3d_strip_group_8010b218(S2Renderer *, int, int, int, int, int);
void w3d_strip_group_8010b298(S2Renderer *, int, int, int, int, int);
void w3d_strip_emit_visible_8010ad24(S2Renderer *, int, int, int, int);


#if 0 /* 5 attempts; one indexed-load operand order differs */
void w3d_strip_group_8010ae30(S2Renderer *self, int a, int b, int c, int group, int parity)
{
    unsigned char previous = w3d_obj_8044c86c[group];
    self->emit(a, b, c, self->groups2[group], self->counts2 + group, parity == previous);
    w3d_obj_8044c86c[group] = 1 - parity;
}
#endif


#if 0 /* 1 attempt; one indexed-load operand order differs */
void w3d_strip_group_8010b118(S2Renderer *self, int a, int b, int c, int group, int parity)
{
    unsigned char previous = w3d_obj_8044c6ec[group];
    self->emit(a, b, c, self->groups[group], self->counts + group, parity == previous);
    w3d_obj_8044c6ec[group] = 1 - parity;
}
#endif


#if 0 /* 1 attempt; one indexed-load operand order differs */
void w3d_strip_group_8010b198(S2Renderer *self, int a, int b, int c, int group, int parity)
{
    unsigned char previous = w3d_obj_8044c86c[group];
    self->emit(a, b, c, self->groups2[group], self->counts2 + group, parity == previous);
    w3d_obj_8044c86c[group] = 1 - parity;
}
#endif


#if 0 /* 1 attempt; one indexed-load operand order differs */
void w3d_strip_group_8010b218(S2Renderer *self, int a, int b, int c, int group, int parity)
{
    unsigned char previous = w3d_obj_8044c6ec[group];
    self->emit(a, b, c, self->groups[group], self->counts + group, parity == previous);
    w3d_obj_8044c6ec[group] = 1 - parity;
}
#endif


#if 0 /* 1 attempt; one indexed-load operand order differs */
void w3d_strip_group_8010b298(S2Renderer *self, int a, int b, int c, int group, int parity)
{
    unsigned char previous = w3d_obj_8044c86c[group];
    self->emit(a, b, c, self->groups2[group], self->counts2 + group, parity == previous);
    w3d_obj_8044c86c[group] = 1 - parity;
}
#endif


#if 0 /* 3 attempts; flag-test temporary register allocation differs */
void w3d_strip_dispatch_8010b318(S2Renderer *self, unsigned short group, int a, int b, int c, int parity)
{
    w3d_strip_emit_visible_8010ad24(self, (unsigned short)a, (unsigned short)b, (unsigned short)c, parity);
    int *flags = self->flags;
    if ((flags[a] & 0xff00) <= 0xfd00U || (flags[b] & 0xff00) <= 0xfd00U || (flags[c] & 0xff00) <= 0xfd00U)
        w3d_strip_group_8010b118(self, (unsigned short)a, (unsigned short)b, (unsigned short)c, self->lowA[(unsigned char)group], parity);
    flags = self->flags;
    if ((flags[a] & 0xff00) || (flags[b] & 0xff00) || (flags[c] & 0xff00))
        w3d_strip_group_8010b198(self, (unsigned short)a, (unsigned short)b, (unsigned short)c, self->highA[group >> 8], parity);
}
#endif


#if 0 /* 3 attempts; flag-test temporary register allocation differs */
void w3d_strip_dispatch_8010b43c(S2Renderer *self, unsigned short group, int a, int b, int c, int parity)
{
    w3d_strip_emit_visible_8010ad24(self, (unsigned short)a, (unsigned short)b, (unsigned short)c, parity);
    int *flags = self->flags;
    if ((flags[a] & 0xff00) <= 0xfd00U || (flags[b] & 0xff00) <= 0xfd00U || (flags[c] & 0xff00) <= 0xfd00U)
        w3d_strip_group_8010b218(self, (unsigned short)a, (unsigned short)b, (unsigned short)c, self->lowC[(unsigned char)group], parity);
    flags = self->flags;
    if ((flags[a] & 0xff00) || (flags[b] & 0xff00) || (flags[c] & 0xff00))
        w3d_strip_group_8010b298(self, (unsigned short)a, (unsigned short)b, (unsigned short)c, self->highC[group >> 8], parity);
}
#endif


int w3d_grid_cell_low_8010b560(const unsigned char *grid, int x, int y)
{
    y *= 81;
    y += x * 9;
    return grid[y] & 15;
}


int w3d_grid_cell_8010b57c(const unsigned char *grid, int x, int y)
{
    y *= 81;
    y += x * 9;
    return grid[y];
}


extern int w3d_bounds_80399f28[];
#if 0 /* 3 attempts; three indexed-load operand orders differ */
int w3d_grid_inside_8010b594(int x, int y, int direction)
{
    direction *= 4;
    if (x >= w3d_bounds_80399f28[direction] &&
        x <= (w3d_bounds_80399f28 + 2)[direction] &&
        y >= (w3d_bounds_80399f28 + 1)[direction] &&
        y <= (w3d_bounds_80399f28 + 3)[direction]) return 1;
    return 0;
}
#endif

}
