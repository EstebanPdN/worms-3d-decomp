// PPC32 offsets are observed; selector/action names inferred.
extern "C" int play_801359ec(void *,unsigned,const char *,void *,float,float,float);
extern const float first_8039fa84[],second_8039fa88[],third_8039fa8c[];
extern const char name_8039fa20[];
extern const char name_8039fa34[];
extern const char name_8039fa48[];
extern const char name_8039fa54[];
extern const char name_8039fa60[];
extern const char name_8039fa68[];
extern const char name_8039fa78[];
extern "C" void w3d_cx12a_draw_animation_8013d730(void *self,unsigned arg,unsigned kind){switch(kind){
case 2:play_801359ec(self,arg,name_8039fa20,(char *)self+0x1d8,first_8039fa84[0],second_8039fa88[0],third_8039fa8c[0]);break;
case 21:play_801359ec(self,arg,name_8039fa34,(char *)self+0x1d8,first_8039fa84[0],second_8039fa88[0],third_8039fa8c[0]);break;
case 1:play_801359ec(self,arg,name_8039fa48,(char *)self+0x1d8,first_8039fa84[0],second_8039fa88[0],third_8039fa8c[0]);break;
case 6:play_801359ec(self,arg,name_8039fa54,(char *)self+0x1d8,first_8039fa84[0],second_8039fa88[0],third_8039fa8c[0]);break;
case 5:play_801359ec(self,arg,name_8039fa60,(char *)self+0x1d8,first_8039fa84[0],second_8039fa88[0],third_8039fa8c[0]);break;
case 20:play_801359ec(self,arg,name_8039fa68,(char *)self+0x1d8,first_8039fa84[0],second_8039fa88[0],third_8039fa8c[0]);break;
case 34:play_801359ec(self,arg,name_8039fa78,(char *)self+0x1d8,first_8039fa84[0],second_8039fa88[0],third_8039fa8c[0]);break;
default:break;}}
