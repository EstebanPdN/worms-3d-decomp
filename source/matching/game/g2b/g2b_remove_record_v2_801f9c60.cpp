// Complete original key20B and record24B; default key state and full copy are independently observed.
struct Key {unsigned a,b,c,d,e;Key():a(3),b(4),c(0),d(0){}bool operator==(const Key&q)const{return a==q.a&&d==q.d&&b==q.b&&c==q.c;} int operator!=(const Key&q)const{return !(*this==q);}Key&operator=(const Key&q){unsigned aa=q.a,bb=q.b,cc=q.c,dd=q.d,ee=q.e;a=aa;b=bb;c=cc;d=dd;e=ee;return *this;}};
struct Record {unsigned id;Key key;Record(){id=0;}bool matches(const Record&q)const{if(id!=q.id)return false;return !(key!=q.key);}};
struct Records {Record*begin;Record*end;};
inline Record*copy(Record*first,Record*last,Record*out){for(int n=last-first;n>0;--n){*out=*first;++out;++first;}return out;}
extern "C" int g2b_remove_record_801f9c60(Records*self,unsigned id,const Key*key){
 Record query;query.key=*key;query.id=id;
 Record*entry=self->begin;
 for(;entry!=self->end;++entry){if(entry->matches(query)){Record*next=entry+1;if(next!=self->end)copy(next,self->end,entry);--self->end;return 0;}}
 return (int)0x80004005;
}
