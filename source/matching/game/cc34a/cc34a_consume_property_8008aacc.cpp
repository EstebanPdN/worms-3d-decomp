// Three-tier signed property decrement. Byte ids widen to signed helper parameters.
struct cc34a_Actor_8008aacc { unsigned char unknown[264]; void* context; };
struct cc34a_Player_8008aacc {unsigned char unknown[213];unsigned char team;};
struct cc34a_Team_8008aacc {unsigned char unknown[60];unsigned char group;};
struct cc34a_Handle_8008aacc;
extern "C" {
void * cc34a_context_803426b4(void*);
int cc34a_current_80178c48(void *);
cc34a_Player_8008aacc* cc34a_player_800fc6dc(int);
cc34a_Team_8008aacc* cc34a_team_800fc7f8(int);
void* cc34a_teamdata_800fcc68(int); void* cc34a_groupdata_800fcd84(int); void* cc34a_playerdata_800fca30(int);
int cc34a_read_8025cbe0(void*,unsigned int);
void* cc34a_teamwrite_800fcc9c(int,cc34a_Handle_8008aacc*); void* cc34a_groupwrite_800fcdb8(int,cc34a_Handle_8008aacc*); void* cc34a_playerwrite_800fca64(int,cc34a_Handle_8008aacc*);
void cc34a_write_8025d020(void*,unsigned int,signed char);
void cc34a_destroy_80178474(cc34a_Handle_8008aacc*,int);
}
struct cc34a_Handle_8008aacc { unsigned int object,tag; cc34a_Handle_8008aacc():object(0),tag(0xe3a8){} ~cc34a_Handle_8008aacc(){cc34a_destroy_80178474(this,2);} };
inline void cc34a_teamcount_8008aacc(int id,unsigned int property,int& value) {if(id>=0)value=cc34a_read_8025cbe0(cc34a_teamdata_800fcc68(id),property);}
inline void cc34a_groupcount_8008aacc(int id,unsigned int property,int& value) {if(id>=0)value=cc34a_read_8025cbe0(cc34a_groupdata_800fcd84(id),property);}
extern "C" void cc34a_consume_property_8008aacc(cc34a_Actor_8008aacc* self,unsigned int property) {
 int groupCount=0,teamCount=0;int player=cc34a_current_80178c48((void *)cc34a_context_803426b4(self->context));
 cc34a_Player_8008aacc* p=cc34a_player_800fc6dc(player);
 cc34a_Team_8008aacc* team=cc34a_team_800fc7f8(p->team);
 int teamId=p->team;if(teamId>=0)teamCount=cc34a_read_8025cbe0(cc34a_teamdata_800fcc68(teamId),property);
 int groupId=team->group;if(groupId>=0)groupCount=cc34a_read_8025cbe0(cc34a_groupdata_800fcd84(groupId),property);
 int playerCount=cc34a_read_8025cbe0(cc34a_playerdata_800fca30(player),property);
 if(groupCount>=0 && teamCount>=0 && playerCount>=0) {
  if(groupCount>0) {cc34a_Handle_8008aacc handle;cc34a_write_8025d020(cc34a_groupwrite_800fcdb8(groupId,&handle),property,(signed char)(groupCount-1));}
  else if(teamCount>0) {cc34a_Handle_8008aacc handle;cc34a_write_8025d020(cc34a_teamwrite_800fcc9c(teamId,&handle),property,(signed char)(teamCount-1));}
  else if(playerCount>0) {cc34a_Handle_8008aacc handle;cc34a_write_8025d020(cc34a_playerwrite_800fca64(player,&handle),property,(signed char)(playerCount-1));}
 }
}
