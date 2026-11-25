#include "w3d_ptr.h"
#line 1 "cc42b_coalesce_spans_8020f778_v0.cpp"
// Partial fixed-array view witnessed through +0x810 count and 8-byte spans.
// No validation of count, addresses or span overflow is added.
struct cc42b_Span { unsigned int start, bytes; };
struct cc42b_SpanPool { unsigned char unknown00[16]; cc42b_Span spans[256]; unsigned int count; };
extern "C" void cc42b_remove_span_8020f8ac(Ptr32<cc42b_SpanPool>, Ptr32<cc42b_Span>);
extern "C" void cc42b_coalesce_spans_8020f778(Ptr32<cc42b_SpanPool> self) {
    for (unsigned int i=0; i<self->count-1U; ++i) {
        Ptr32<cc42b_Span> span=&self->spans[i];
        for (unsigned int j=0; j<self->count; ++j) {
            if (i!=j) {
                Ptr32<cc42b_Span> next=&self->spans[j];
                if (span->start+span->bytes==next->start) {
                    span->bytes+=next->bytes;
                    cc42b_remove_span_8020f8ac(self,next);
                    break;
                }
            }
        }
    }
}


