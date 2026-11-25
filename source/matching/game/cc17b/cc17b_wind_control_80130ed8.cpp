/* Observed wind control name, scalar at +84, instance at +28 and state at +56. */
struct Cc17bWindContext { char pad[56]; unsigned paused; };
struct Cc17bWindSource { char pad[28]; void *instance; unsigned control; char pad2[20]; void *state; char pad3[24]; float scalar; };
extern "C" {
Cc17bWindContext *fn_80165254();
void *fn_80343584(void *);
void *fn_80342a74(void *);
float fn_80178df0(void *);
extern float value_8039e1b0[],value_8039e1b4[];
extern char name_8039e19c[];
int fn_80181640(void *,const char *,unsigned *,int,float,float,float);
int fn_8018179c(void *,unsigned,int);
void w3d_cc17b_wind_control_80130ed8(Cc17bWindSource *self) {
 if(!fn_80165254()->paused) {
  void *instance=fn_80343584(self->instance);
  float scale=fn_80178df0(fn_80342a74(self->state));
  float scalar=self->scalar;
  if(scalar>value_8039e1b0[0]) {
   float rate=value_8039e1b4[0]/(scalar*scale);
   fn_80181640(instance,name_8039e19c,&self->control,1,rate,value_8039e1b0[0],value_8039e1b0[0]);
   fn_8018179c(instance,self->control,1);
  }
 }
}
}
