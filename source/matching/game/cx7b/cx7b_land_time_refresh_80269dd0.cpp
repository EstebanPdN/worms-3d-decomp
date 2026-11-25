struct Cx7bLandTimeOwner { char unknown00[496]; int ready; };
extern "C" char text_803cb980[];
extern "C" int fn_800fc230(const char **,int *);
extern "C" void fn_8026c008(Cx7bLandTimeOwner *,int);
extern "C" void fn_8026b9bc(Cx7bLandTimeOwner *);
extern "C" int w3d_cx7b_land_time_refresh_80269dd0(void *, Cx7bLandTimeOwner *owner) {
 if(owner->ready==0) { const char *name=text_803cb980; int time; fn_800fc230(&name,&time); fn_8026c008(owner,1); fn_8026b9bc(owner); } return 0;
}
