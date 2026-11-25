// GWMP8P 0x800167ac: product of two radial influence falloffs.
struct cc24a_FieldVec {float x,y,z;float distance2(const cc24a_FieldVec &other)const{float a=x-other.x,b=y-other.y,c=z-other.z;return c*c+(a*a+b*b);}};
struct cc24a_Field {int unknown0;float cost;char unknown8[12];cc24a_FieldVec target;char unknown32[4];cc24a_FieldVec origin;};
struct cc24a_FieldPlan {char unknown0[24];cc24a_FieldVec origin;};
struct cc24a_FieldConfig {char unknown0[180];float radius;};
extern "C" {extern cc24a_FieldConfig *cc24a_config_804aa6d8;extern float cc24a_zero_8036a684[];float cc24a_sqrt_802e82c0(float);}
extern "C" float cc24a_planner_radial_influence_800167ac(cc24a_Field *self,const cc24a_FieldPlan *plan,const cc24a_FieldVec *origin){
 float radius=cc24a_config_804aa6d8->radius;
 float first=origin->distance2(self->origin);
 float radius2=radius*radius;
 if(first>=radius2)return cc24a_zero_8036a684[0];
 float second=plan->origin.distance2(self->target);
 if(second>=radius2)return cc24a_zero_8036a684[0];
 float a=(radius-cc24a_sqrt_802e82c0(first))/radius;
 float b=(radius-cc24a_sqrt_802e82c0(second))/radius;
 return (a*b)*self->cost;
}
