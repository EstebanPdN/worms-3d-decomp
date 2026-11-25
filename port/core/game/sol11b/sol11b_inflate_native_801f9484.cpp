#include "w3d_ptr.h"
#line 1 "sol11b_inflate_native_801f9484.cpp"
#include "sol11b_zlib_abi.h"
// Partial external owner view. The zlib member has the vendored zlib ABI size;
// this view is never constructed locally. Only the observed source slot is used.
struct Sol11bInput { Ptr32<Ptr32<void>> methods; };
struct Sol11bInflateReader {
    unsigned char external_prefix[24];
    Ptr32<Sol11bInput> input;
    unsigned start;
    unsigned compressed_size;
    unsigned output_size;
    unsigned position;
    z_stream state;
    unsigned char input_buffer[32768];
};
extern "C" unsigned sol11b_inflate_native_801f9484(Ptr32<Sol11bInflateReader> self, Ptr32<unsigned char> output, unsigned requested, Ptr32<unsigned int> received)
{
    unsigned available=0;
    if (self->state.total_out == self->output_size) {
        if (received) *received=0;
        return 0x90000001U;
    }
    self->state.next_out=output;
    self->state.avail_out=requested;
    while (self->state.total_out != self->output_size) {
        if (inflate(&self->state, Z_PARTIAL_FLUSH)==Z_STREAM_END) {
            inflateEnd(&self->state);
            break;
        }
        if (!self->state.avail_out) break;
        if (self->state.total_in+32768U < self->compressed_size) available=32768;
        else available=self->compressed_size-self->state.total_in;
        unsigned current;
        Ptr32<Sol11bInput> input=self->input;
        ((Ptr32<int (Ptr32<Sol11bInput>, unsigned int, int, Ptr32<unsigned int>)>)input->methods[7])(input,0,1,&current);
        unsigned expected=self->start+self->state.total_in;
        if (current != expected) {
            input=self->input;
            if (((Ptr32<int (Ptr32<Sol11bInput>, unsigned int, int, Ptr32<unsigned int>)>)input->methods[7])(input,expected,0,0)<0) {
                inflateEnd(&self->state);
                return 0x80004005U;
            }
        }
        input=self->input;
        if (((Ptr32<int (Ptr32<Sol11bInput>, Ptr32<void>, unsigned int, Ptr32<unsigned int>)>)input->methods[5])(input,self->input_buffer,available,&available)!=0) {
            inflateEnd(&self->state);
            return 0x80004005U;
        }
        self->state.next_in=self->input_buffer;
        self->state.avail_in=available;
    }
    if (received) *received=requested-self->state.avail_out;
    self->position+=requested-self->state.avail_out;
    return 0;
}


