// Inferred explosion property event; vector has only three observed float fields.
struct cc34a_Vector_8008c718 { float x,y,z; };
extern "C" {
extern char cc34a_name_8037e010[],cc34a_name_8037e028[],cc34a_name_8037e040[],cc34a_name_8037e060[],cc34a_name_8037e07c[],cc34a_name_8037e098[],cc34a_name_8037e0b4[];
extern void* cc34a_pool_804b1754;
int cc34a_readtext_800fc2b0(const char**,const char**);
int cc34a_readfloat_800fc270(const char**,float*);
void cc34a_find_8008bad0(void*,const char*,cc34a_Vector_8008c718*);
void* cc34a_alloc_801613f0(void*,unsigned int);
void* cc34a_init_800666b4(void*,const cc34a_Vector_8008c718*,const cc34a_Vector_8008c718*,float,float,float,float,float);
int cc34a_post_8016239c(void*);
void cc34a_explosion_properties_8008c718(void* self) {
 cc34a_Vector_8008c718 damage,impulse;
 const char* detailName=cc34a_name_8037e010; const char* detail;
 cc34a_readtext_800fc2b0(&detailName,&detail);
 cc34a_find_8008bad0(self,detail,&damage);
 const char* offsetName=cc34a_name_8037e028;float offset;
 cc34a_readfloat_800fc270(&offsetName,&offset);
 impulse=damage;impulse.y+=offset;
 const char* damageMagnitudeName=cc34a_name_8037e040;float damageMagnitude;
 cc34a_readfloat_800fc270(&damageMagnitudeName,&damageMagnitude);
 const char* impulseMagnitudeName=cc34a_name_8037e060;float impulseMagnitude;
 cc34a_readfloat_800fc270(&impulseMagnitudeName,&impulseMagnitude);
 const char* damageRadiusName=cc34a_name_8037e07c;float damageRadius;
 cc34a_readfloat_800fc270(&damageRadiusName,&damageRadius);
 const char* landRadiusName=cc34a_name_8037e098;float landRadius;
 cc34a_readfloat_800fc270(&landRadiusName,&landRadius);
 const char* impulseRadiusName=cc34a_name_8037e0b4;float impulseRadius;
 cc34a_readfloat_800fc270(&impulseRadiusName,&impulseRadius);
 cc34a_post_8016239c(cc34a_init_800666b4(cc34a_alloc_801613f0(cc34a_pool_804b1754,52),&damage,&impulse,damageMagnitude,impulseMagnitude,damageRadius,landRadius,impulseRadius));
}
}
