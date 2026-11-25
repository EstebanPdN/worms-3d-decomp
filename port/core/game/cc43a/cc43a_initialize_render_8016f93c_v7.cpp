#include "w3d_ptr.h"
#line 1 "cc43a_initialize_render_8016f93c_v7.cpp"
// Original file-backed constants at 803a64e4..803a64fc were decoded as
// 20, 600, 16, +0, -0.5, +0.5, +1; see the retained literal witness.
// Partial inferred render state; array extents are witnessed loop counts.
struct cc43a_Channel { unsigned int a,b,c; float value; unsigned int code; };
struct cc43a_RenderSetup { cc43a_Channel channels[4]; unsigned int count,a,b,c,unknown60; unsigned int smallA[5],smallB[5],triple[3],largeA[32],largeB[32]; float left,top,width,height; };
extern "C" Ptr32<cc43a_RenderSetup> cc43a_setup_804b1894;
extern "C" unsigned int cc43a_channelCodes_803fe3c0[];
extern "C" float cc43a_matrix_804559ac[];
extern "C" void cc43a_ortho_80302ec4(Ptr32<float>,float,float,float,float,float,float);
extern "C" Ptr32<cc43a_RenderSetup> cc43a_initialize_render_8016f93c(Ptr32<cc43a_RenderSetup> self) {
 cc43a_setup_804b1894=self;
 self->left=20.0f;self->top=20.0f;self->width=600.0f;self->height=16.0f;
 Ptr32<unsigned int> code=cc43a_channelCodes_803fe3c0;
 for(unsigned int i=0;i<4;++i) {Ptr32<cc43a_Channel> channel=&self->channels[i];channel->a=0;channel->b=0;channel->c=0;channel->value=0.0f;channel->code=code[i];}
 self->count=4;self->b=0;self->a=0;self->c=0;
 for(int i=0;i<5;++i){self->smallA[i]=0;self->smallB[i]=0;}
 for(int i=0;i<32;++i){self->largeA[i]=0;self->largeB[i]=0;}
 Ptr32<unsigned int> p=self->triple;
 for(int n=3;n;--n,++p)*p=0;
 cc43a_ortho_80302ec4(cc43a_matrix_804559ac,-0.5f,0.5f,-0.5f,0.5f,-0.5f,1.0f);
 return self;
}


