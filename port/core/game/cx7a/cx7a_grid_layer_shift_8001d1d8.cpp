#include "w3d_ptr.h"
#line 1 "cx7a_grid_layer_shift_8001d1d8.cpp"
// A chunk has bounds at +0x1c and three pairs of 16-byte layer records
// starting at +0x24, +0x44 and +0x64. Shift previous into current, clear bounds.
struct Cx7aBounds { short x_min,z_min,x_max,z_max;Cx7aBounds() {} void tail(short zero){z_min=zero;x_max=zero;z_max=zero;} };
struct Cx7aLayer {unsigned int previous,current,unknown[2];};
struct Cx7aChunk {unsigned char unknown[28];Cx7aBounds bounds;Cx7aLayer layers[6];};
extern "C" void w3d_cx7a_grid_layer_shift_8001d1d8(Ptr32<Cx7aChunk> self) {Cx7aBounds cleared;Ptr32<Cx7aBounds> out=&cleared;int count=2;Ptr32<Cx7aLayer> row=self->layers; Ptr32<Cx7aLayer> tail=self->layers+4;do {row[2].current=row[2].previous;tail->current=row[4].previous;++tail;row->current=row->previous;++row;}while(--count!=0);cleared.x_min=count;out->tail(count);self->bounds=cleared;}


