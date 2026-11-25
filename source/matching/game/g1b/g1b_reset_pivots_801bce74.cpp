// External binding/object views remain partial and are never constructed here.
// Each local vector is exactly three float members; assignments copy all twelve bytes.
struct G1bVec3 { float x,y,z; G1bVec3(float a):x(a),y(a),z(a){} };
struct G1bBinding { unsigned prefix[2]; G1bVec3 value; };
extern "C" G1bBinding *fn_801f0504(void*,const void*);
extern "C" void fn_801e8d9c(void*);
extern unsigned char key_803ab9f8[],key_803aba28[];
extern const float value_803aba4c[];
extern "C" int g1b_reset_pivots_801bce74(void*self){
 G1bBinding *rotation=fn_801f0504(self,key_803ab9f8);
 rotation->value=G1bVec3(value_803aba4c[0]);
 G1bBinding *scale=fn_801f0504(self,key_803aba28);
 scale->value=G1bVec3(value_803aba4c[0]);
 fn_801e8d9c(self);return 0;
}
