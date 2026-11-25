// Reconstructed from original GWMP8P rev0; names and full API/class identities
// remain inferred. The handled cases share the final zero return; all other
// paths forward the original message to the base handler. The native unsigned
// arithmetic wraps, and every divisor returned by maxAlpha must be nonzero.
// The graphic's +56/+20 virtual calls retain this and genuine Vec3-copy
// lifetime. Callback targets and effects remain external obligations.
// No portable, runtime, whole-source/game or hardware claim.
// Original operands and partial GC32 views; class/API names inferred.
namespace sol35b9_powerbar {
struct Vec3 {float x,y,z;Vec3(const Vec3&v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}};
struct Graphic {void**table;};
struct Config {char u0[80];Vec3 point;};
struct Owner {char u0[64];int mode,visible,active;unsigned stamp,deadline;unsigned char alpha;char u85[3];Graphic*graphic;void*index;void*fade;void*maxAlpha;};
struct Message {unsigned short id;};
struct Cache {unsigned word[2];};
extern "C" {
int sol35b9_power_base_8015fb34(Owner*,Message*);
void sol35b9_power_setup_800f03a0(Owner*);
void sol35b9_power_toggle_800f0984(Owner*,int);
int sol35b9_power_equal_8015f620(Cache*,unsigned);
unsigned sol35b9_power_value_80178d1c(void*);
unsigned sol35b9_power_index_80178c48(void*);
Config* sol35b9_power_config_800fc6dc(unsigned);
int sol35b9_power_mode_801190d0(Message*);
extern Cache sol35b9_power_cache_804af028,sol35b9_power_cache_804af030,sol35b9_power_cache_804af048,sol35b9_power_cache_804af050,sol35b9_power_cache_804af038,sol35b9_power_cache_804af040,sol35b9_power_cache_804af058;
}
extern "C" int sol35b9_powerbar_messages_800f008c(Owner*s,Message*m){
 if(m->id==64){
  if(sol35b9_power_base_8015fb34(s,m)>=0)sol35b9_power_setup_800f03a0(s);
  else return (int)0x80004005u;
 }
 else if(sol35b9_power_equal_8015f620(&sol35b9_power_cache_804af028,m->id)) sol35b9_power_toggle_800f0984(s,0);
 else if(sol35b9_power_equal_8015f620(&sol35b9_power_cache_804af030,m->id)) sol35b9_power_toggle_800f0984(s,1);
 else {
 if(sol35b9_power_equal_8015f620(&sol35b9_power_cache_804af048,m->id)){
  s->visible=1;
  unsigned fade=sol35b9_power_value_80178d1c(s->fade);
  unsigned maxAlpha=sol35b9_power_value_80178d1c(s->maxAlpha);
  s->deadline=s->stamp-(unsigned(s->alpha)*fade)/maxAlpha;
  s->mode=sol35b9_power_mode_801190d0(m);
 }else if(sol35b9_power_equal_8015f620(&sol35b9_power_cache_804af050,m->id)){
  s->visible=0;
  unsigned maxAlpha=sol35b9_power_value_80178d1c(s->maxAlpha);
  unsigned fade=sol35b9_power_value_80178d1c(s->fade);
  unsigned divisor=sol35b9_power_value_80178d1c(s->maxAlpha);
  s->deadline=s->stamp-((maxAlpha-unsigned(s->alpha))*fade)/divisor;
 }else if(sol35b9_power_equal_8015f620(&sol35b9_power_cache_804af038,m->id)){
  s->active=1;
  if(s->graphic){
   Vec3 point=sol35b9_power_config_800fc6dc(sol35b9_power_index_80178c48(s->index))->point;
   Graphic*g=s->graphic;((void(*)(Graphic*,int,const Vec3*))g->table[14])(g,3,&point);
   g=s->graphic;((void(*)(Graphic*))g->table[5])(g);
  }
 }else if(sol35b9_power_equal_8015f620(&sol35b9_power_cache_804af040,m->id)||sol35b9_power_equal_8015f620(&sol35b9_power_cache_804af058,m->id))s->active=0;
 return sol35b9_power_base_8015fb34(s,m);
 }
 return 0;
}
}

typedef char sol35b9_power_vec_size[(sizeof(sol35b9_powerbar::Vec3)==12)?1:-1];
typedef char sol35b9_power_owner_size[(sizeof(sol35b9_powerbar::Owner)==104)?1:-1];
typedef char sol35b9_power_config_size[(sizeof(sol35b9_powerbar::Config)==92)?1:-1];
typedef char sol35b9_power_cache_size[(sizeof(sol35b9_powerbar::Cache)==8)?1:-1];
