#include "w3d_ptr.h"
#line 1 "s2_trigger_components_r3.cpp"
/* Trigger component fields and lightweight handle operations. */
extern "C" {
struct Object { Ptr32<Ptr32<void>> vtable; };
struct Vector { float x,y,z; };
struct String { Ptr32<char> text;int reserved; };
struct Key { Ptr32<const char> name; };
struct Member { unsigned short unused,id;int slot; };
struct Trigger { Ptr32<void> vtable;char unknown04[16];int id;char unknown18[20];int index,hp,team;char unknown38[8];int filterA,filterB;int unknown48,done,dead,enabled,pending;Ptr32<Object> first; Ptr32<Object> second;Member member;Ptr32<Object> actor;int action,collector; };
struct Graphic { char unknown00[28];Ptr32<Object> actor; Ptr32<Object> mesh; };
struct Entity { char unknown00[20];int type,id; };
struct Worm { char unknown00[213];unsigned char team; };
struct Registry { Ptr32<const char> name;int zero04,unknown08,zero0c;Ptr32<void> vtable;int unknown14;Ptr32<void> storage;int unknown1c,unknown20,zero24; };
void w3d_actor_base_initialize(Ptr32<Trigger>);
void w3d_actor_handle_member_initialize(Ptr32<Member>);
Ptr32<void> w3d_string_from_text(Ptr32<String>,Ptr32<const char>);
void w3d_string_base_finish(Ptr32<String>);
void w3d_string_release(Ptr32<String>);
Ptr32<void> w3d_handle_set_name(Ptr32<String>,Ptr32<Ptr32<Object>>,int);
Ptr32<Trigger> w3d_fn_80164fc8(Ptr32<Object>);
Ptr32<float> w3d_component_radius_801256e4(Ptr32<Trigger>);
Ptr32<Vector> w3d_component_position_801256ec(Ptr32<Trigger>);
Ptr32<Object> w3d_auto_80178c48(Ptr32<Object>);
Ptr32<Worm> w3d_fn_800fc6dc(Ptr32<Object>);
int w3d_fn_800fc3b0(Ptr32<Key>,int);
Ptr32<void> w3d_fn_801613f0(Ptr32<void>,int);
int w3d_cached_message_id(Ptr32<void>,int);
int w3d_message_post_current(Ptr32<void>);
void w3d_auto_8015fd1c(Ptr32<Trigger>);
void w3d_handle_member_call_80126334(Ptr32<Member>);
int w3d_handle_clock_801264fc(Ptr32<Member>);
void w3d_handle_member_query_80126524(Ptr32<Member>);
Ptr32<Entity> w3d_auto_8003f240(unsigned short);
void w3d_component_on_worm_entered_80125aa0(Ptr32<Trigger>,int);
void w3d_trigger_zone_check_team_a_80125c80(Ptr32<Trigger>);
void w3d_trigger_zone_check_team_b_80125d0c(Ptr32<Trigger>);
void w3d_trigger_zone_trigger_now_80125d98(Ptr32<Trigger>);
void w3d_trigger_collect_80125b44(Ptr32<Trigger>);
void w3d_fn_80200a70(Ptr32<Registry>);
unsigned int w3d_fn_8003f400(int);
void w3d_handle_set_bounds(unsigned short,int,float);
void w3d_handle_set_slot_word(unsigned short,int);
void w3d_fn_8003fc70(unsigned short,int,Ptr32<Vector>,int,int);
void w3d_auto_8003ffac(unsigned short);
void w3d_light_set_attachment_800c1294(unsigned short,Ptr32<Ptr32<Object>>);
extern char w3d_obj_80410bd8[],w3d_obj_8040db38[],w3d_obj_8040cac0[],w3d_obj_8044fae4[];
extern Registry w3d_registry_8044fae8[];
extern const char w3d_str_8039b900[],w3d_str_8039b944[],w3d_str_8039b964[],w3d_str_8039baac[],w3d_str_8039bb9c[];
extern Ptr32<void> w3d_obj_804b1754;
extern int w3d_obj_804af564,w3d_obj_804af55c,w3d_obj_804af56c,w3d_obj_804af574,w3d_obj_804af57c,w3d_obj_804af584;
extern unsigned short w3d_obj_804aa95e;
extern unsigned int w3d_obj_804b1790;
extern float w3d_obj_804b17a4;
extern Ptr32<int (void)> w3d_obj_804b17b4;
struct Message { unsigned short id,reserved;Ptr32<void> vtable; };
inline void post(Ptr32<void> key) { Ptr32<Message> m=(Ptr32<Message>)w3d_fn_801613f0(w3d_obj_804b1754,8);m->id=w3d_cached_message_id(key,1);m->vtable=w3d_obj_8040db38;w3d_message_post_current(m); }
void w3d_trigger_graphic_setup_80124c5c(Ptr32<Graphic> self) {
    struct Gap {float a,b;Gap(){}} scratch;
    struct { String name;Vector scale; } local;
    w3d_string_from_text(&local.name,w3d_str_8039b900);
    Ptr32<String> name=&local.name;
    w3d_handle_set_name(name,&self->mesh,255);
    w3d_string_base_finish(name);w3d_string_release(name);
    Ptr32<Trigger> actor=w3d_fn_80164fc8(self->actor);
    if(actor) {
        float radius=*w3d_component_radius_801256e4(actor);
        local.scale.x=radius;local.scale.y=radius;local.scale.z=radius;
        ((Ptr32<void (Ptr32<Object>, Ptr32<Vector>, int)>)self->mesh->vtable[21])(self->mesh,&local.scale,0);
        ((Ptr32<void (Ptr32<Object>, Ptr32<Vector>, int)>)self->mesh->vtable[19])(self->mesh,w3d_component_position_801256ec(actor),0);
    }
}
#if 0 // Excluded after five compilation passes: constructor initialization scheduling differs.
Trigger *w3d_trigger_construct_80124edc(Trigger *self) {
    struct Gap {float a,b;Gap(){}} scratch;
    w3d_actor_base_initialize(self);
    self->first=0;self->second=0;self->vtable=w3d_obj_80410bd8;
    w3d_actor_handle_member_initialize(&self->member);
    self->action=0;self->collector=-1;self->actor=0;
    self->dead=0;self->enabled=0;self->pending=0;self->done=0;
    return self;
}
#endif
#if 0 // Excluded after five compilation passes: eight bytes of stack spacing remain unresolved.
void w3d_trigger_damage_801257f0(Trigger *self,float damage) {
    struct Gap {float a,b;Gap(){}} scratch;
    if(self->team!=-1 && w3d_fn_800fc6dc(w3d_auto_80178c48(self->actor))->team!=self->team) return;
    self->hp-=(int)damage;
    if(self->hp<=0) {
        self->dead=1;Key index;index.name=w3d_str_8039b944;w3d_fn_800fc3b0(&index,self->index);
        post(&w3d_obj_804af564);w3d_auto_8015fd1c(self);
    } else {
        Key index;index.name=w3d_str_8039b944;w3d_fn_800fc3b0(&index,self->index);
        Key hp;hp.name=w3d_str_8039b964;w3d_fn_800fc3b0(&hp,self->hp);
        post(&w3d_obj_804af55c);
    }
}
#endif
#if 0 // Excluded after five compilation passes: iterator copy and register allocation differ.
void w3d_trigger_scan_80125934(Trigger *self) {
    Member *member=&self->member;
    int id=self->id;
    w3d_handle_member_call_80126334(member);
    int result=w3d_handle_clock_801264fc(member);
    while(!self->done && !self->dead && !self->pending && result!=65535) {
        if(w3d_auto_8003f240(w3d_obj_804aa95e)->id!=id) {
            int type=w3d_auto_8003f240(w3d_obj_804aa95e)->type;
            if(type==1) w3d_component_on_worm_entered_80125aa0(self,w3d_auto_8003f240(w3d_obj_804aa95e)->id);
            else if(self->filterA<=3 && type==136) w3d_trigger_zone_check_team_a_80125c80(self);
            else if(self->filterB<=3 && type==8) w3d_trigger_zone_check_team_b_80125d0c(self);
            else if(self->enabled && type==512) w3d_trigger_zone_trigger_now_80125d98(self);
        }
        result=w3d_handle_clock_801264fc(member);
    }
    w3d_handle_member_query_80126524(&self->member);
    if(self->pending) w3d_trigger_collect_80125b44(self);
}
#endif
void w3d_trigger_collect_80125b44(Ptr32<Trigger> self) {
    Key index;index.name=w3d_str_8039b944;w3d_fn_800fc3b0(&index,self->index);
    Key collector;collector.name=w3d_str_8039baac;w3d_fn_800fc3b0(&collector,self->collector);
    self->done=1;
    switch(self->action) {
    case 1:post(&w3d_obj_804af56c);break;
    case 3:post(&w3d_obj_804af574);break;
    case 2:post(&w3d_obj_804af57c);break;
    case 4:post(&w3d_obj_804af584);break;
    }
    w3d_auto_8015fd1c(self);
}
int w3d_handle_registry_init_8012609c() {
    Ptr32<Registry> self=w3d_registry_8044fae8;
    self->name=w3d_str_8039bb9c;self->vtable=w3d_obj_8040cac0;self->storage=w3d_obj_8044fae4;
    self->zero04=0;self->zero0c=0;self->zero24=0;
    w3d_fn_80200a70(self);return 0;
}
#if 0 // Excluded after five compilation passes: eight bytes of stack spacing remain unresolved.
Member *w3d_handle_member_construct_801261bc(Member *self,int bounds,int slot,int value,float radius) {
    struct Gap {float a,b;Gap(){}} scratch;
    unsigned int id=w3d_fn_8003f400(0);self->id=id;
    w3d_handle_set_bounds((unsigned short)id,bounds,radius);
    w3d_handle_set_slot_word(self->id,slot);self->slot=value;return self;
}
#endif
#if 0 // Excluded after five compilation passes: distance and sentinel register allocation and stack spacing differ.
int w3d_handle_member_find_closest_801263fc(Member *self,Vector *vector,int maximum,int ignore) {
    struct Gap {float a,b;Gap(){}} scratch;
    w3d_fn_8003fc70(self->id,self->slot,vector,maximum,ignore);
    int found=65535;
    int distance=maximum;
    float fraction=(float)maximum;
    int current=w3d_obj_804b17b4();
    while(current!=65535) {
        if(w3d_obj_804b1790<(unsigned int)distance && w3d_auto_8003f240(w3d_obj_804aa95e)->id!=ignore) {
            distance=w3d_obj_804b1790;found=current;fraction=w3d_obj_804b17a4;
        }
        current=w3d_obj_804b17b4();
    }
    w3d_obj_804b1790=distance;w3d_obj_804b17a4=fraction;w3d_obj_804aa95e=found;
    w3d_auto_8003ffac(self->id);return found;
}
#endif
struct Ref {Ptr32<Object> object;int reserved;Ref(Ptr32<Object> const &p) {object=p;if(object) ((Ptr32<void (Ptr32<Object>)>)object->vtable[3])(object);} };
void w3d_light_member_attach_80126610(Ptr32<Member> self,Ptr32<Ptr32<Object>> source) {
    Ref ref(*source);
    w3d_light_set_attachment_800c1294(self->id,&ref.object);
    // El argumento es por valor y, en GCC 2.95, lo destruye quien lo recibe.
    if(*source) ((Ptr32<void (Ptr32<Object>)>)(*source)->vtable[4])(*source);
}
}


