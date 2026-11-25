// Inferred texture header view. Gaps are unobserved fields, not an object-size claim.
struct cc45a_TextureHeader { unsigned char unknown00[24]; unsigned short format; unsigned char unknown1a[4]; unsigned short width, height; };
struct cc45a_Texture { cc45a_TextureHeader *header; };
struct cc45a_GXTexture { unsigned int words[8]; };
struct cc45a_Matrix { float cells[3][4]; };
extern "C" {
extern const float cc45a_zero_803a6344[];
void cc45a_init_texture_80309c88(cc45a_GXTexture*,void*,unsigned short,unsigned short,unsigned int,unsigned int,unsigned int,unsigned char);
void cc45a_texture_lod_80309f1c(cc45a_GXTexture*,unsigned int,unsigned int,float,float,float,unsigned char,unsigned char,unsigned int);
void cc45a_load_texture_8030a21c(cc45a_GXTexture*,unsigned int);
void cc45a_scale_matrix_80302e9c(cc45a_Matrix*,float,float,float);
void cc45a_load_matrix_8030c0c8(cc45a_Matrix*,unsigned int,unsigned int);
void cc45a_texgen_count_803080a4(unsigned char);
void cc45a_texgen_80307e24(unsigned int,unsigned int,unsigned int,unsigned int,unsigned char,unsigned int);
// SDK bodies inspected in build/cc45a/gx-callee-witness.txt; side-effect-only APIs.
// DOL literals: 803a6344=00000000 (0.0f), 803a6348=4330000080000000
// (signed conversion bias), 803a6350=3f800000 (1.0f).
// Width/height are unsigned 16-bit, promoted to signed int before float conversion.
// Matrix is the observed 3x4 SDK matrix; texture helper accesses 32 bytes.
// Matched stack frame does not establish the size of an original C++ wrapper.
inline void cc45a_lod(cc45a_GXTexture *t, float z) { cc45a_texture_lod_80309f1c(t,1,1,z,z,z,0,0,0); }
void cc45a_texture_coords_8016e09c_v4(cc45a_Texture *self,void *image) {
 cc45a_Matrix matrix;
 cc45a_GXTexture texture;
 cc45a_init_texture_80309c88(&texture,image,self->header->width,self->header->height,self->header->format,0,0,0);
 cc45a_lod(&texture,cc45a_zero_803a6344[0]);
 cc45a_load_texture_8030a21c(&texture,0);
 cc45a_scale_matrix_80302e9c(&matrix,1.0f/(float)(int)self->header->width,1.0f/(float)(int)self->header->height,1.0f);
 cc45a_load_matrix_8030c0c8(&matrix,30,1);
 cc45a_texgen_count_803080a4(1);
 cc45a_texgen_80307e24(0,1,4,30,0,125);
}
}
