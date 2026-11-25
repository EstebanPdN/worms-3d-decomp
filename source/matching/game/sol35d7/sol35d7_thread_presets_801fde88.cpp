// Native scheduler preset selection, inferred three-word records with 60-byte stride.
namespace sol35d7_thread_presets {
struct Thread { int kind; };
struct Preset { unsigned words[3]; };
struct PresetRow { Preset entries[5]; };
extern PresetRow lbl_803b2700[];
extern PresetRow lbl_803b270c[];
extern PresetRow lbl_803b2718[];
extern PresetRow lbl_803b2724[];
extern PresetRow lbl_803b2730[];
extern "C" int fn_802ff854();
extern "C" void fn_801fdf60(Thread *,unsigned,unsigned,unsigned);
static inline void apply(Thread *t,const PresetRow *p,int mode) {
 const Preset &s=p[mode].entries[0];
 fn_801fdf60(t,s.words[0],s.words[1],s.words[2]);
}
}
extern "C" int sol35d7_thread_presets_801fde88(sol35d7_thread_presets::Thread *self) {
 using namespace sol35d7_thread_presets;
 int result=0;
 int mode=fn_802ff854();
 switch(self->kind) {
 case 1:apply(self,lbl_803b2700,mode);break;
 case 2:apply(self,lbl_803b270c,mode);break;
 case 3:apply(self,lbl_803b2718,mode);break;
 case 4:apply(self,lbl_803b2724,mode);break;
 case 5:apply(self,lbl_803b2730,mode);break;
 default: result=1;
 }
 return result;
}
