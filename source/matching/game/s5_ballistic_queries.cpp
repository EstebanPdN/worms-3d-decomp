/* Ballistic deadline and boundary-crossing queries. */
extern "C" {
struct S5BallisticQuery;
struct S5BallisticQueryVec { float x,y,z; };
struct S5BallisticQueryVtable { void (*reserved[11])(); void (*position)(S5BallisticQuery *,unsigned,S5BallisticQueryVec *); void (*velocity)(S5BallisticQuery *,unsigned,S5BallisticQueryVec *); };
struct S5BallisticQuery { S5BallisticQueryVtable *vtable; unsigned char reserved04[32]; S5BallisticQueryVec position,velocity,acceleration; unsigned char reserved72[12]; unsigned deadline; unsigned char reserved88[20]; float target; unsigned char reserved112[80]; void *resource; unsigned char reserved196[172]; unsigned time; };
struct S5BallisticQueryName { unsigned id;const char *text; };
extern S5BallisticQueryName w3d_ballistic_name_804aeb38,w3d_ballistic_name_804aeb00;
extern const float w3d_f32_80389538[];
void *w3d_empty_80341584(void *);
void *w3d_auto_801797b4(void *);
unsigned w3d_cached_message_id(S5BallisticQueryName *,int);
void w3d_ballistic_boundary_query_800d92a8(S5BallisticQuery *actor,unsigned short *message,int *best,S5BallisticQueryVec *position,S5BallisticQueryVec *velocity)
{
    struct { short reserved[3]; } unused;
    w3d_auto_801797b4(w3d_empty_80341584(actor->resource));
    if(actor->acceleration.y!=*w3d_f32_80389538 && actor->target!=*w3d_f32_80389538) {
        float time=(-actor->target-actor->velocity.y)/actor->acceleration.y;
        if(time<*w3d_f32_80389538) time=*w3d_f32_80389538;
        if(*best==-1 || time<(float)*best) {
            *message=w3d_cached_message_id(&w3d_ballistic_name_804aeb38,1);
            *best=(int)time;
            actor->vtable->position(actor,actor->time+*best,position);
            actor->vtable->velocity(actor,actor->time+*best,velocity);
        }
    }
}
static inline void s5_ballistic_zero(S5BallisticQueryVec *vector,float value) { vector->x=value; vector->y=value; vector->z=value; }
void w3d_ballistic_deadline_query_800d93d0(S5BallisticQuery *actor,unsigned short *message,int *remaining,S5BallisticQueryVec *position,S5BallisticQueryVec *velocity,S5BallisticQueryVec *acceleration)
{
    *message=w3d_cached_message_id(&w3d_ballistic_name_804aeb00,1);
    *remaining=actor->deadline-actor->time;
    if(*remaining<0) actor->deadline=actor->time;
    actor->vtable->position(actor,actor->deadline,position);
    actor->vtable->velocity(actor,actor->deadline,velocity);
    S5BallisticQueryVec zero;
    s5_ballistic_zero(&zero,0.0f);
    *acceleration=zero;
}
}
