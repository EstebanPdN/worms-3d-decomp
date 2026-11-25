// Input/selection state: records a pointer position normalised to the
// 320x240 screen in the shared cursor object, then dispatches a vector input
// message (id 4100, value 8) carrying the normalised x, y and a zero z.
// Partial observed layouts; the message type, arena and cursor object are
// original data referenced by address. The literals 320.0f, 240.0f and 0.0f
// are this function's original literal pool at 0x803814d0..0x803814db (owned
// initialized data, 12 bytes). Built with the original paired-single float
// switch (-mps-float), which reserves the 16 frame bytes that pair the two
// saved FPRs.
struct d16b_Message { unsigned short id, pad02; const void *type; };
struct d16b_VectorMessage {
    d16b_Message base;
    int mode, value;
    short first, second;
    unsigned char flag, pad15[3];
    float x, y, z;
};
struct d16b_Cursor { unsigned char unknown00[32]; float x, y; };
struct d16b_PointerState;
extern "C" void *tsonnet_b33_arena_801613f0(void *, int);
extern "C" void w3d_dispatch_800a6c80(d16b_PointerState *, d16b_Message *);
extern void *w3d_arena_804b1754;
extern d16b_Cursor *w3d_cursor_804b17f0;
extern const unsigned char w3d_type_8040db38[];

inline void d16b_vector_init(d16b_VectorMessage *message, int value, float x, float y, float z) {
    message->base.id = 4100;
    message->base.type = w3d_type_8040db38;
    message->mode = 0;
    message->first = 0;
    message->value = value;
    message->second = 0;
    message->flag = 0;
    message->x = x;
    message->y = y;
    message->z = z;
}

extern "C" void d16b_send_pointer_800a79f8(d16b_PointerState *self, float x, float y) {
    x = x / 320.0f;
    y = y / 240.0f;
    w3d_cursor_804b17f0->x = x;
    w3d_cursor_804b17f0->y = y;
    d16b_VectorMessage *message = (d16b_VectorMessage *)tsonnet_b33_arena_801613f0(w3d_arena_804b1754, 36);
    d16b_vector_init(message, 8, x, y, 0.0f);
    w3d_dispatch_800a6c80(self, &message->base);
}
