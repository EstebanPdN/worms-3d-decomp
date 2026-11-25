// Observed matrix members and video descriptor prefix; full sizes unknown.
struct d11a_Matrix {float v[3][4];};
struct d11a_MatrixState {unsigned char unknown0[920];d11a_Matrix combined,texture,aspect,extra;};
struct d11a_VideoMode {unsigned unknown0;unsigned short width,height;};
struct d11a_Screen {unsigned char unknown0[40];d11a_VideoMode *mode;};
extern d11a_Screen *d11a_screen_804b1888;
extern "C" void d11a_scale_80302e9c(d11a_Matrix *,float,float,float);
extern "C" void d11a_translate_80302e68(d11a_Matrix *,float,float,float);
extern "C" void d11a_concat_80302b8c(const d11a_Matrix *,const d11a_Matrix *,d11a_Matrix *);
extern "C" void d11a_identity_80302b60(d11a_Matrix *);
extern "C" void d11a_setup_matrices_801685cc(d11a_MatrixState *self)
{
 d11a_Matrix translation,scale;
 d11a_scale_80302e9c(&scale,0.5f,0.5f,0.0f);
 d11a_translate_80302e68(&translation,0.5f,0.5f,1.0f);
 d11a_concat_80302b8c(&translation,&scale,&self->combined);
 d11a_identity_80302b60(&self->texture);
 d11a_VideoMode *mode=d11a_screen_804b1888->mode;
 d11a_identity_80302b60(&self->aspect);
 self->aspect.v[0][0]=(float)mode->height/(float)mode->width;
 self->aspect.v[0][2]=-0.5f;
 self->aspect.v[2][2]=-1.0f;
 self->aspect.v[1][2]=-0.5f;
 self->aspect.v[1][1]=-1.0f;
 d11a_identity_80302b60(&self->extra);
}
