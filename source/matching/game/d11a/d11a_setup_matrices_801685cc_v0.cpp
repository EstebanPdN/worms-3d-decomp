// Observed matrix members and video descriptor prefix; full sizes unknown.
struct d11a_Matrix {float v[3][4];};
struct d11a_MatrixState {unsigned char unknown0[920];d11a_Matrix combined,texture,aspect,extra;};
struct d11a_VideoMode {unsigned unknown0;unsigned short width,height;};
struct d11a_Screen {unsigned char unknown0[40];d11a_VideoMode *mode;};
extern d11a_Screen *d11a_screen_804b1888;
extern const float d11a_xy_803a4f84[],d11a_scale_z_803a4f88[],d11a_translate_z_803a4f8c[],d11a_bias_803a4f90[],d11a_unit_803a4f94[];
extern "C" void d11a_scale_80302e9c(d11a_Matrix *,float,float,float);
extern "C" void d11a_translate_80302e68(d11a_Matrix *,float,float,float);
extern "C" void d11a_concat_80302b8c(const d11a_Matrix *,const d11a_Matrix *,d11a_Matrix *);
extern "C" void d11a_identity_80302b60(d11a_Matrix *);
extern "C" void d11a_setup_matrices_801685cc(d11a_MatrixState *self)
{
 d11a_Matrix translation,scale;
 d11a_scale_80302e9c(&scale,d11a_xy_803a4f84[0],d11a_xy_803a4f84[0],d11a_scale_z_803a4f88[0]);
 d11a_translate_80302e68(&translation,d11a_xy_803a4f84[0],d11a_xy_803a4f84[0],d11a_translate_z_803a4f8c[0]);
 d11a_concat_80302b8c(&translation,&scale,&self->combined);
 d11a_identity_80302b60(&self->texture);
 d11a_VideoMode *mode=d11a_screen_804b1888->mode;
 d11a_identity_80302b60(&self->aspect);
 self->aspect.v[0][0]=(float)mode->height/(float)mode->width;
 self->aspect.v[1][1]=d11a_unit_803a4f94[0];
 self->aspect.v[0][2]=d11a_bias_803a4f90[0];
 self->aspect.v[1][2]=d11a_bias_803a4f90[0];
 self->aspect.v[2][2]=d11a_unit_803a4f94[0];
 d11a_identity_80302b60(&self->extra);
}
