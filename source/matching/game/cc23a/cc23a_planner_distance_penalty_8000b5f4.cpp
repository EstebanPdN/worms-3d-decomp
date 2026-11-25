// Typed distance formula; field meanings inferred from observed access pattern.
struct Cc23aVec8000b5f4{float x,y,z;float distance2(const Cc23aVec8000b5f4 &p){float a=x-p.x,b=y-p.y,c=z-p.z;return c*c+(a*a+b*b);}};
struct Cc23aEntry8000b5f4{unsigned char unknown00[16];Cc23aVec8000b5f4 position10;};
struct Cc23aRange8000b5f4{Cc23aEntry8000b5f4 **begin;};
struct Cc23aPlan8000b5f4{unsigned char unknown00[16];int index10;unsigned int unknown14;Cc23aVec8000b5f4 origin18;};
struct Cc23aSettings8000b5f4{unsigned char unknown00[76];float scale4c;};
extern "C"{extern Cc23aRange8000b5f4 *lbl_804aa750;extern Cc23aSettings8000b5f4 *lbl_804aa6d8;extern float lbl_80369c5c[],lbl_80369c60[];float fn_802e82c0(float);}
extern "C" float cc23a_planner_distance_penalty_8000b5f4(Cc23aPlan8000b5f4 *self,float range){
 float zero=lbl_80369c5c[0];if(range==zero)return zero;
 Cc23aEntry8000b5f4 *entry=*(Cc23aEntry8000b5f4 **)((char *)lbl_804aa750->begin+(self->index10<<2));
 float distance=fn_802e82c0(self->origin18.distance2(entry->position10));
 float factor=lbl_80369c60[0];if(distance>zero){factor=range/distance;if(factor<lbl_80369c60[0])factor=lbl_80369c60[0];}
 return factor*lbl_804aa6d8->scale4c;
}
