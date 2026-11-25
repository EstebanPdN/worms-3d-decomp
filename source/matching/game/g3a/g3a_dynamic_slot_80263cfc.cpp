// Consumed shared-string value and externally allocated two-float entry arrays.
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
struct G3aConsumedText {char*p;~G3aConsumedText(){fn_8020c5c4(this);fn_80341588(this);}};
extern "C" void*fn_8015ae3c(G3aConsumedText*),*fn_80343808(void*);
extern "C" void fn_80171ee0(void*,int);
extern "C" float*fn_80171fa0(void*),*fn_80171ff8(void*);
extern unsigned mask_804abb64;extern const float x_803cb1fc[],y_803cb200[],scale_803cb204[],z_803cb208[];
extern "C" int w3d_g3a_dynamic_slot_80263cfc(G3aConsumedText name,int id,float size){
 int result;
 if(id==-1){unsigned slot=0;while(mask_804abb64&(1u<<slot))++slot;
 void*resource=fn_80343808(fn_8015ae3c(&name));fn_80171ee0(resource,79);float*positions=fn_80171fa0(resource);float*extents=fn_80171ff8(resource);
 unsigned index=slot+15;positions[index*2]=x_803cb1fc[0];positions[index*2+1]=y_803cb200[0];extents[index*2]=z_803cb208[0];mask_804abb64|=1u<<slot;extents[index*2+1]=size*scale_803cb204[0];result=index;
 }else{result=-1;mask_804abb64&=~(1u<<(id-15));}return result;
}
