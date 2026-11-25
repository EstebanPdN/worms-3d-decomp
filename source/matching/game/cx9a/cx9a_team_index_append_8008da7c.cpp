// Inferred raw byte-storage vector: begin +0, end +4, capacity +8.
extern "C" unsigned char *storage_allocate_80212fd4(unsigned int);
extern "C" void storage_release_802134fc(void *);
extern "C" void *storage_copy_802eee50(void *,const void *,...);
static inline const int &larger(const int &a,const int &b){return a<b?b:a;}
static inline const unsigned int &smaller(const unsigned int &a,const unsigned int &b){return b<a?b:a;}
struct Cx9aStorage {unsigned char *begin,*end,*capacity;
 void push(const unsigned int &value){
  if(end==capacity){unsigned int used=end-begin;int next=used+1;int grown=used+(used>>1);unsigned int allocated=larger(next,grown)*4;
   unsigned char *fresh=storage_allocate_80212fd4(allocated);
   if(begin){storage_copy_802eee50(fresh,begin,smaller(allocated,used));storage_release_802134fc(begin);}
   begin=fresh;end=fresh+used;capacity=fresh+allocated;
  }
  *(unsigned int *)end=value;end+=4;
 }
};
struct Cx9aTeam {unsigned char unknown00[0x158];Cx9aStorage storage;};
extern "C" unsigned int team_index_801190d0(void *);
extern "C" void w3d_cx9a_team_index_append_8008da7c(Cx9aTeam *self,void *team){self->storage.push(team_index_801190d0(team));}
