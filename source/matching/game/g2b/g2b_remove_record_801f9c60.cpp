// Complete24B externally stored record; only pointer/scalar locals are constructed.
struct Guid {unsigned a,b,c,d;bool operator==(const Guid&q)const{return a==q.a&&d==q.d&&b==q.b&&c==q.c;}};
struct Record {unsigned id;Guid guid;unsigned value;};
struct Records {Record*begin;Record*end;};
extern "C" int g2b_remove_record_801f9c60(Records*self,unsigned id,const Guid*guid){
 Record*entry=self->begin;
 for(;entry!=self->end;++entry){
  if(entry->id==id && entry->guid==*guid){
   Record*next=entry+1;
   if(next!=self->end){for(int n=self->end-next;n>0;--n){*entry=*next;++entry;++next;}}
   --self->end;return 0;
  }
 }
 return (int)0x80004005;
}
