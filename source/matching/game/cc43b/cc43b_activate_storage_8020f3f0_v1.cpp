// Partial observed storage view. Full class identity and sizeof are unknown.
struct cc43b_Span { unsigned int start, bytes; };
struct cc43b_Storage {
    int active;
    unsigned int start, limit, bytes;
    inline void set_active(int value) { active=value; }
};
extern "C" int cc43b_initialize_backing_8020f8d4(cc43b_Storage *, unsigned int);
extern "C" cc43b_Span *cc43b_append_span_8020f850(cc43b_Storage *);
extern "C" int cc43b_activate_storage_8020f3f0(cc43b_Storage *self, unsigned int bytes) {
    int previous=self->active;
    if (previous!=1) {
        cc43b_initialize_backing_8020f8d4(self,bytes);
        cc43b_Span *span=cc43b_append_span_8020f850(self);
        self->start=(self->start+31U)&~31U;
        span->start=self->start;
        span->bytes=self->bytes&~31U;
        self->set_active(1);

    }
    return previous!=1;
}
