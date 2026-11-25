/* Triangle-strip index emission and parity tracking. */
extern "C" {

void w3d_strip_emit_8010a918(int a, int b, int c, unsigned short *buffer, unsigned short *count, int parity)
{
    if (*count != 0) {
        if (buffer[*count - 2] == a && buffer[*count - 1] == b) {
            buffer[(*count)++] = c;
            return;
        }
        int previous = buffer[*count - 1];
        if (previous == a) {
            buffer[(*count)++] = a;
            if (!parity) buffer[(*count)++] = a;
            buffer[(*count)++] = b;
            buffer[(*count)++] = c;
            return;
        }
        buffer[*count] = previous;
        buffer[*count + 1] = a;
        buffer[*count + 2] = a;
        *count += 3;
        if (!parity) buffer[(*count)++] = a;
        buffer[(*count)++] = b;
        buffer[(*count)++] = c;
        return;
    }
    if (!parity) buffer[(*count)++] = a;
    buffer[(*count)++] = a;
    buffer[(*count)++] = b;
    buffer[(*count)++] = c;
}



void w3d_strip_emit_8010aa60(int a, int b, int c, unsigned char *buffer, unsigned short *count, int parity)
{
    a = (unsigned char)a;
    b = (unsigned char)b;
    c = (unsigned char)c;
    if (*count != 0) {
        if (buffer[*count - 2] == a && buffer[*count - 1] == b) {
            buffer[(*count)++] = c;
            return;
        }
        int previous = buffer[*count - 1];
        if (previous == a) {
            buffer[(*count)++] = a;
            if (!parity) buffer[(*count)++] = a;
            buffer[(*count)++] = b;
            buffer[(*count)++] = c;
            return;
        }
        buffer[*count] = previous;
        buffer[*count + 1] = a;
        buffer[*count + 2] = a;
        *count += 3;
        if (!parity) buffer[(*count)++] = a;
        buffer[(*count)++] = b;
        buffer[(*count)++] = c;
        return;
    }
    if (!parity) buffer[(*count)++] = a;
    buffer[(*count)++] = a;
    buffer[(*count)++] = b;
    buffer[(*count)++] = c;
}



void w3d_strip_emit_8010abc8(int a, int b, int c, unsigned short *buffer, unsigned short *count, int parity)
{
    if (*count != 0) {
        if (buffer[((*count - 2) & 3)] == a && buffer[((*count - 1) & 3)] == b) {
            buffer[(((*count)++) & 3)] = c;
            return;
        }
        int previous = buffer[((*count - 1) & 3)];
        if (previous == a) {
            buffer[(((*count)++) & 3)] = a;
            if (!parity) buffer[(((*count)++) & 3)] = a;
            buffer[(((*count)++) & 3)] = b;
            buffer[(((*count)++) & 3)] = c;
            return;
        }
        buffer[((*count) & 3)] = previous;
        buffer[((*count + 1) & 3)] = a;
        buffer[((*count + 2) & 3)] = a;
        *count += 3;
        if (!parity) buffer[(((*count)++) & 3)] = a;
        buffer[(((*count)++) & 3)] = b;
        buffer[(((*count)++) & 3)] = c;
        return;
    }
    if (!parity) buffer[(((*count)++) & 3)] = a;
    buffer[(((*count)++) & 3)] = a;
    buffer[(((*count)++) & 3)] = b;
    buffer[(((*count)++) & 3)] = c;
}



typedef void (*S2StripEmit)(int, int, int, void *, unsigned short *, int);
struct S2StripRenderer {
    unsigned char pad00[44]; S2StripEmit emitGroup, emitVisible;
    unsigned char pad34[688-52]; unsigned int *vertexFlags;
    unsigned char pad2b4[2304-692]; void **groups;
    unsigned char pad904[2364-2308]; unsigned short *groupCounts;
    unsigned char pad940[2472-2368]; void *indices; unsigned short count;
};
extern unsigned char w3d_obj_804af2ac;
extern unsigned char w3d_obj_8044c6ec[];
void w3d_strip_emit_visible_8010ad24(S2StripRenderer *self, int a, int b, int c, int parity)
{
    if (self->vertexFlags[a] | self->vertexFlags[b] | self->vertexFlags[c]) {
        self->emitVisible(a, b, c, self->indices, &self->count, parity == w3d_obj_804af2ac);
        w3d_obj_804af2ac = 1 - parity;
    }
}


#if 0 /* 3 attempts; one indexed-load operand order differs in the best candidate */
void w3d_strip_emit_group_8010adb0(S2StripRenderer *self, int a, int b, int c, unsigned int group, int parity)
{
    unsigned char previous = w3d_obj_8044c6ec[group];
    self->emitGroup(a, b, c, self->groups[group], self->groupCounts + group, parity == previous);
    w3d_obj_8044c6ec[group] = 1 - parity;
}
#endif

}
