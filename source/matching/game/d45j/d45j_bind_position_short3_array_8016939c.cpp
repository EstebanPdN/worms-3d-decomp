// Vertex array binding command handler recovered from 0x8016939c.
// The second read of the buffer pointer is volatile: the original keeps the
// command pointer alive past the count load and copies the buffer register.
extern "C" {
void DCFlushRange(void *start, unsigned bytes);
void GXSetArray(int attr, void *base, unsigned char stride);
}

struct VertexBuffer {
    unsigned char header[24];
    unsigned count;
    unsigned short dirty;
    unsigned short pad;
    unsigned char data[16];

    void Sync(void *start, unsigned bytes)
    {
        if (dirty) {
            DCFlushRange(start, bytes);
            dirty = 0;
        }
    }
};

struct ArrayCommand {
    unsigned char header[20];
    VertexBuffer *buffer;
    unsigned char type;
};

struct ArrayState {
    unsigned char header[124];
    void *override_;
    unsigned char a[284 - 128];
    int changes;
    unsigned dirty;
    unsigned char b[24];
    unsigned char posType;
    unsigned char normalType;
    unsigned char texType;
};

struct ArraySink {
    void *vtable;
};

extern "C" int bind_position_short3_array_8016939c(ArraySink *sink, ArrayCommand *cmd)
{
    ArrayState *self = sink ? (ArrayState *)((char *)sink - 4) : 0;
    VertexBuffer *b = cmd->buffer;
    unsigned n = b->count;
    unsigned char *data = b->data;
    if (n != 0) {
        VertexBuffer *held = *(VertexBuffer *volatile *)&cmd->buffer;
        held->Sync(data, n * 6);
        if (self->override_ == 0) {
            GXSetArray(9, data, 6);
            self->posType = cmd->type;
            self->dirty |= 2;
            self->changes++;
        }
    }
    return 0;
}
