// Partial storage/request views from original loads and stores. No sizeof or
// complete interface identity is claimed. Address arithmetic is unsigned 32-bit.
struct cc43b_Span { unsigned int start, bytes; };
struct cc43b_Storage {
    int active; unsigned int start,limit,bytes;
    cc43b_Span spans[256]; unsigned int count;
    inline cc43b_Span *at(unsigned int index) { return &spans[index]; }
};
struct cc43b_Request { unsigned int state, source, unknown08, destination, id, bytes; };
extern "C" int cc43b_activate_8020f3f0(cc43b_Storage *,unsigned int);
extern "C" void cc43b_prepare_8020f3b8(cc43b_Request *,void *,unsigned int,unsigned int);
extern "C" int cc43b_transfer_8020f940(cc43b_Storage *,cc43b_Request *);
extern "C" void cc43b_remove_8020f8ac(cc43b_Storage *,cc43b_Span *);
extern "C" int cc43b_allocate_storage_8020f4b0(cc43b_Storage *self,void *source,unsigned int bytes,cc43b_Request *request) {
    if (!self->active) cc43b_activate_8020f3f0(self,0x900000);
    unsigned int aligned=(bytes+31U)&~31U;
    unsigned int best_bytes=~0U, best_index;
    bool found=false;
    cc43b_Span *span;
    for (unsigned int i=0;i<self->count;++i) {
        span=self->at(i);
        if (span->bytes>=aligned) {
            if (span->bytes==aligned) { found=true; best_index=i; break; }
            if (span->bytes<best_bytes) {
                best_bytes=span->bytes; found=true; best_index=i;
            }
        }
    }
    // Original checks the last examined span, then allocates from best_index.
    if (!found || span->start+span->bytes>self->limit) return 0;
    span=self->at(best_index);
    unsigned int start=span->start;
    cc43b_prepare_8020f3b8(request,source,start,aligned);
    cc43b_transfer_8020f940(self,request);
    if (span->bytes==aligned) cc43b_remove_8020f8ac(self,span);
    else { span->start=start+aligned; span->bytes-=aligned; }
    return 1;
}
