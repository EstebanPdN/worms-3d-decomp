// GWMP8P rev0 0x802bc93c. Scrolling list: picks the scroll position for an
// entry index. List and Entry are partial views of the vector at +56/+60 and
// the fields read here; names are inferred.
struct Entry;
extern "C" int fn_802bd2bc(Entry*);
struct Entry{char u[60];float a60;float a64;};
struct List{char u[48];float a48;char u52[4];Entry**begin;Entry**end;char u64[4];float a68;char u72[4];float a76;};
extern "C" void fn_802bc790(List*,float);
extern "C" float fn_802bc778(List*);
extern "C" unsigned fn_802bc71c(List*);
extern "C" float d26l_select_entry_position_802bc93c(List*s,int index,int animate){
 float pos=index;
 for(Entry**it=s->begin;it!=s->end;++it){
  if(fn_802bd2bc(*it)==index){
   Entry*e=*it;
   if(e->a60!=0.0f){
    if(animate)fn_802bc790(s,index);
    return index;
   }
   if(e->a64!=0.0f&&s->a48>s->a76){
    float v=pos+1.0f-(s->a48+s->a48)/(s->a76+s->a76);
    if(animate)fn_802bc790(s,v);
    return v;
   }
   float cur=fn_802bc778(s);
   float n=fn_802bc71c(s);
   if(cur<=n&&n-s->a68<cur&&animate)fn_802bc790(s,n-cur);
   return s->a68;
  }
 }
 float p=index;
 if(p<s->a68){if(animate)fn_802bc790(s,p);return p;}{float d=s->a76+s->a76;float n=s->a48+s->a48;p=pos+1.0f-n/d;}if(animate)fn_802bc790(s,p);return p;
}
