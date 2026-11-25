#define F(p,T,o) (*(T*)((char*)(p)+(o)))
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
struct G2aVectorText_803426b8 {char*p;G2aVectorText_803426b8();~G2aVectorText_803426b8(){fn_8020c5c4(this);fn_80341588(this);}unsigned length()const{return *(unsigned short*)(p-4);}};
union G2aComponent{float value;unsigned bits;};
struct G2aVector {G2aComponent x,y,z;G2aVector(const G2aVector&s){float a=s.x.value,b=s.y.value,c=s.z.value;x.value=a;y.value=b;z.value=c;}G2aVector&operator=(const G2aVector&s){unsigned a=s.x.bits,b=s.y.bits,c=s.z.bits;x.bits=a;y.bits=b;z.bits=c;return *this;}};
extern "C" void*fn_801e9db8(void*,int);
extern "C" void fn_802cd26c(G2aVectorText_803426b8*,int,int),fn_802cc0ac(G2aVectorText_803426b8*,const char*,int),fn_802cbf2c(G2aVectorText_803426b8*,const char*,int),fn_802cbdf8(void*,const char*,int),fn_802cc2d8(float,G2aVectorText_803426b8*,int),fn_8027a934(void*,int),fn_8027ae00(void*),fn_8027a98c(void*);
extern const char x_803ce594[],y_803ce5b4[],z_803ce5d4[],increment_803cdfec[],blank_803ce014[],toggle_803ce020[];
extern const float step_803ce5f4[],step_803ce5f8[],step_803ce5fc[],step_803ce600[],step_803ce604[];
inline G2aVector& vectorProperty(void*self){void*owner=F(self,void*,92);void*d=fn_801e9db8((*(void*(***)(void*))(owner))[5](owner),F(self,int,96));return F(owner,G2aVector,F(F(d,void*,0),unsigned short,4));}
extern "C" void w3d_g2a_vector_keys_8027978c(void*self,int key){
 bool changed=false;G2aVectorText_803426b8 text;G2aVector value(vectorProperty(self));
 switch(key){
 case 'X':case 'x':fn_802cd26c(&text,0,4);fn_802cc0ac(&text,x_803ce594,7);fn_802cd26c(&text,3,4);F(self,int,44)=0;fn_8027a934(self,0);break;
 case 'Y':case 'y':fn_802cd26c(&text,0,5);fn_802cc0ac(&text,y_803ce5b4,7);fn_802cd26c(&text,3,5);F(self,int,44)=1;fn_8027a934(self,0);break;
 case 'Z':case 'z':fn_802cd26c(&text,0,6);fn_802cc0ac(&text,z_803ce5d4,7);fn_802cd26c(&text,3,6);F(self,int,44)=2;fn_8027a934(self,0);break;
 case 27:fn_8027ae00(self);break;
 case '4':value.x.value-=F(self,float,100);fn_802cd26c(&text,3,4);changed=true;fn_802cc2d8(value.x.value,&text,9);fn_802cd26c(&text,0,14);break;
 case '6':value.x.value+=F(self,float,100);fn_802cd26c(&text,3,4);changed=true;fn_802cc2d8(value.x.value,&text,9);fn_802cd26c(&text,0,14);break;
 case '8':value.y.value+=F(self,float,100);fn_802cd26c(&text,3,5);changed=true;fn_802cc2d8(value.y.value,&text,9);fn_802cd26c(&text,0,14);break;
 case '2':value.y.value-=F(self,float,100);fn_802cd26c(&text,3,5);changed=true;fn_802cc2d8(value.y.value,&text,9);fn_802cd26c(&text,0,14);break;
 case '9':value.z.value-=F(self,float,100);fn_802cd26c(&text,3,6);changed=true;fn_802cc2d8(value.z.value,&text,9);fn_802cd26c(&text,0,14);break;
 case '3':value.z.value+=F(self,float,100);fn_802cd26c(&text,3,6);changed=true;fn_802cc2d8(value.z.value,&text,9);fn_802cd26c(&text,0,14);break;
 case '0':if(F(self,float,100)==step_803ce5f4[0])F(self,float,100)=step_803ce5f8[0];
 else if(F(self,float,100)==step_803ce5f8[0])F(self,float,100)=step_803ce5fc[0];
 else if(F(self,float,100)==step_803ce5fc[0])F(self,float,100)=step_803ce600[0];
 else if(F(self,float,100)==step_803ce600[0])F(self,float,100)=step_803ce604[0];
 else if(F(self,float,100)==step_803ce604[0])F(self,float,100)=step_803ce5f4[0];
 fn_802cd26c(&text,0,12);fn_802cc0ac(&text,increment_803cdfec,9);fn_802cc2d8(F(self,float,100),&text,9);fn_802cbf2c(&text,blank_803ce014,9);fn_802cbf2c(&text,toggle_803ce020,9);break;
 }
 if(changed){vectorProperty(self)=value;fn_8027a98c(self);}
 if(text.length())fn_802cbdf8(F(self,void*,32),text.p,9);
}
