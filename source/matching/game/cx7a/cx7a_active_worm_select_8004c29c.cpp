
// Reads ActiveWormIndex into a stack output and forwards it with the caller.
struct Cx7aIndex { int value; Cx7aIndex() {} };
struct Cx7aController;
extern const char name_803772bc[];
extern "C" int property_800fc1f0(const char **,int *);
extern "C" int select_8004c2f0(Cx7aController *,int);
extern "C" void w3d_cx7a_active_worm_select_8004c29c(Cx7aController *self) { Cx7aIndex index; const char *name;index.value=0;name=name_803772bc;property_800fc1f0(&name,&index.value);select_8004c2f0(self,index.value); }
