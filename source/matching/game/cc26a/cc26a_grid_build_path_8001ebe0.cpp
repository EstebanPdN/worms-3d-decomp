// Original synchronous grid path search and result extraction. Names inferred.
struct cc26a_VecEbe0 {float x,y,z;};
struct cc26a_StepEbe0 {unsigned char unknown[7];unsigned char mode;};
struct cc26a_SearchEbe0 {unsigned char unknown[32828];int limit;};
struct cc26a_GridEbe0 {unsigned char unknown[68];cc26a_SearchEbe0 *search;};
struct cc26a_PathEbe0;
extern void *cc26a_actor_804aa6c0;
extern int cc26a_special_804aa794;
extern "C" void cc26a_refresh_8001ef50(cc26a_GridEbe0*);
extern "C" void cc26a_probe_8001f1d8(cc26a_GridEbe0*,void*);
extern "C" void cc26a_start_80004498(cc26a_SearchEbe0*,const cc26a_VecEbe0*,const cc26a_VecEbe0*);
extern "C" void cc26a_step_800046c8(cc26a_SearchEbe0*);
extern "C" int cc26a_status_80005e10(cc26a_SearchEbe0*);
extern "C" int cc26a_remaining_800062b0(cc26a_SearchEbe0*);
extern "C" cc26a_StepEbe0 *cc26a_next_800062bc(cc26a_SearchEbe0*);
extern "C" void cc26a_position_8000419c(cc26a_VecEbe0*,cc26a_StepEbe0*);
extern "C" void cc26a_append_80003424(cc26a_PathEbe0*,const cc26a_VecEbe0*,int);
extern "C" void cc26a_release_800062ec(cc26a_SearchEbe0*);
extern "C" void cc26a_grid_build_path_8001ebe0(cc26a_GridEbe0 *self,const cc26a_VecEbe0 *from,const cc26a_VecEbe0 *to,cc26a_PathEbe0 *result,int limit){
 if(limit>150)limit=150;
 cc26a_refresh_8001ef50(self);cc26a_probe_8001f1d8(self,cc26a_actor_804aa6c0);
 self->search->limit=limit;cc26a_start_80004498(self->search,from,to);
 while(cc26a_status_80005e10(self->search)==0)cc26a_step_800046c8(self->search);
 if(cc26a_remaining_800062b0(self->search)>0){
  while(cc26a_remaining_800062b0(self->search)>0){
   struct {cc26a_VecEbe0 position;} w;
   cc26a_StepEbe0 *step=cc26a_next_800062bc(self->search);
   cc26a_position_8000419c(&w.position,step);cc26a_append_80003424(result,&w.position,step->mode);
  }
  if(!cc26a_special_804aa794)cc26a_append_80003424(result,to,0);
 }
 cc26a_release_800062ec(self->search);cc26a_special_804aa794=0;
}
