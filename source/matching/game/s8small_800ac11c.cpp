struct s8_PropertyOwner { char pad0[128]; void *property; };
extern "C" void *fn_803426b4(void *);
extern "C" int fn_80178c54(void *,int *);
extern "C" void s8_set_member_property_800ac11c(s8_PropertyOwner *self,int value) { fn_80178c54(fn_803426b4(self->property),&value); }
