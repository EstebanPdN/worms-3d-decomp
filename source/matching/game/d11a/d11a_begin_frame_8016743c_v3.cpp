// Partial renderer and video-mode views; no complete class sizes are asserted.
// The next-field result is consumed only by the interlaced viewport setup.
struct d11a_Pair {float first,second; d11a_Pair(float a,float b):first(a),second(b){} };
struct d11a_ByteColor { unsigned char r,g,b,a; };
struct d11a_Matrix34 { float values[3][4]; };
struct d11a_Renderer { unsigned char unknown0[40];d11a_ByteColor clear;unsigned char unknown44[1068];d11a_Matrix34 matrix; };
struct d11a_VideoMode { unsigned unknown0;unsigned short width,height;unsigned char unknown8[16];unsigned char field_rendering; };
struct d11a_Screen { unsigned char unknown0[40];d11a_VideoMode *mode; };
extern d11a_Screen *d11a_screen_804b1888;
extern d11a_Renderer *d11a_renderer_804b1884;
extern unsigned d11a_sync_enabled_804ab4fc;
extern const float d11a_zero_803a4e0c[],d11a_one_803a4e10[];
extern "C" void d11a_swap_8016eed0(d11a_Screen *);
extern "C" void d11a_flush_80167094(d11a_Renderer *);
extern "C" void d11a_draw_sync_803084e0(unsigned short);
extern "C" void d11a_reset_counter_8030ce00();
extern "C" unsigned d11a_next_field_80304cac();
extern "C" void d11a_viewport_jitter_8030c20c(float,float,float,float,float,float,unsigned);
extern "C" void d11a_viewport_8030c264(float,float,float,float,float,float);
extern "C" void d11a_invalidate_vertices_80307e14();
extern "C" void d11a_invalidate_textures_8030a46c();
extern "C" void d11a_set_copy_clear_80308fc0(d11a_ByteColor,unsigned);
extern "C" void d11a_cull_80308be8(unsigned);
extern "C" void d11a_load_position_8030bff4(const d11a_Matrix34 *,unsigned);
extern "C" void d11a_reset_state_80167fe0(d11a_Renderer *);
extern "C" int d11a_begin_frame_8016743c(d11a_Renderer *self)
{
 d11a_swap_8016eed0(d11a_screen_804b1888);
 d11a_flush_80167094(self);
 if(d11a_sync_enabled_804ab4fc) {
   d11a_draw_sync_803084e0(0xfeeb);
   d11a_reset_counter_8030ce00();
 }
 d11a_Pair origin(0.0f,0.0f),depth(0.0f,1.0f);
 d11a_VideoMode *mode=d11a_screen_804b1888->mode;
 if(mode->field_rendering) {
   float width=mode->width,height=mode->height;
   unsigned field=d11a_next_field_80304cac();
   d11a_viewport_jitter_8030c20c(origin.first,origin.second,width,height,depth.first,depth.second,field);
 } else {
   d11a_viewport_8030c264(origin.first,origin.second,mode->width,mode->height,depth.first,depth.second);
 }
 d11a_invalidate_vertices_80307e14();
 d11a_invalidate_textures_8030a46c();
 d11a_set_copy_clear_80308fc0(self->clear,0x00ffffff);
 d11a_cull_80308be8(1);
 d11a_load_position_8030bff4(&d11a_renderer_804b1884->matrix,0);
 d11a_reset_state_80167fe0(self);
 return 0;
}
