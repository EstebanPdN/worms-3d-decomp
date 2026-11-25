typedef unsigned int cc33b_u32;
struct Cc33bTexture_802e22c0 { unsigned char bytes[32]; };
extern "C" {
extern float cc33b_filter_zero_803db3b8[];
void cc33b_texture_image_80309c88(Cc33bTexture_802e22c0*,void*,cc33b_u32,cc33b_u32,int,int,int,int);
void cc33b_texture_filter_80309f1c(Cc33bTexture_802e22c0*,int,int,float,float,float,unsigned char,unsigned char,int);
void w3d_cc33b_texture_planes_802e22c0(Cc33bTexture_802e22c0* textures,void* y,void* u,void* v,cc33b_u32 width,cc33b_u32 height) {
 cc33b_texture_image_80309c88(textures,y,width,height,1,0,0,0);

 cc33b_texture_filter_80309f1c(textures,0,0,0.0f,0.0f,0.0f,0,0,0);
 cc33b_texture_image_80309c88(textures+1,u,width>>1,height>>1,1,0,0,0);

 cc33b_texture_filter_80309f1c(textures+1,0,0,0.0f,0.0f,0.0f,0,0,0);
 cc33b_texture_image_80309c88(textures+2,v,width>>1,height>>1,1,0,0,0);

 cc33b_texture_filter_80309f1c(textures+2,0,0,0.0f,0.0f,0.0f,0,0,0);
}
}
