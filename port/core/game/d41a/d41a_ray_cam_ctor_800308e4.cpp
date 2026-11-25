#include "w3d_ptr.h"
#line 1 "d41a_ray_cam_ctor_800308e4.cpp"
// GWMP8P rev0 0x800308e4. Constructor of the RayCam camera object: base
// construction, name, zeroed fields, member objects, two cleared slots,
// stores itself in the global 0x804aa8c8, and loads the Land, Airstrike,
// Ninja, Camera and Water properties it reads. Names are inferred.
struct Object;
struct ObjectVtable { Ptr32<void> unknown00[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Handle {
    Ptr32<Object> value;
    Handle() {}
    Handle(const Handle &);
};
struct PropertyKey { Ptr32<const char> name; };
struct Array { Ptr32<void> start; Ptr32<void> finish; Ptr32<void> end; Array() { end = 0; finish = 0; start = 0; } };
struct Slot {
    unsigned word;
    float f; int g; int h; int i;
    void Clear() { word &= 0x7fffff; f = 0.0f; g = 0; h = 0; i = 0; }
};
inline void *operator new(__SIZE_TYPE__, void *q) { return q; }
struct Name { char u[76]; };
struct Local { char u[192]; };
struct Member;
extern "C" int w3d_actor_handle_member_set_slot_word(Ptr32<void>, int);
extern "C" void w3d_actor_handle_member_set_word(Ptr32<void>, int);
extern "C" int w3d_handle_member_query_8012629c(Ptr32<void>, float);
struct Member { int SetSlot(int v) { return w3d_actor_handle_member_set_slot_word(this, v); } void SetWord(int v) { w3d_actor_handle_member_set_word(this, v); } int Query(float v) { return w3d_handle_member_query_8012629c(this, v); }  char w3d_empty; };
struct Self { Member &handle() { return *(Ptr32<Member>)member; } Ptr32<void> vt; char u4[28]; char name[76]; int z108; int z112; int z116; int z120; int z124; int z128; int z132; int z136; int z140; int z144; int z148; int z152; int z156; int z160; int z164; int z168; int z172; int z176; int z180; int z184; int z188; int z192; int z196; int z200; int z204; int z208; int z212; int z216; int z220; int z224; int z228; int z232; int z236; int z240; int z244; int z248; int z252; int z256; int z260; int z264; int z268; int z272; int z276; int z280; int z284; int z288; int z292; int z296; int z300; int z304; int z308; char u312[4]; Array items; char local[76]; char view[184]; int z588; int z592; Slot s596; char u616[4]; int z620; int z624; int z628; int z632; int z636; int z640; int z644; int z648; int z652; int z656; int z660; int z664; int z668; int z672; int z676; int z680; int z684; int z688; int z692; int z696; int z700; int z704; int z708; int z712; int z716; int z720; int z724; Slot s728; Ptr32<Object> z748; Ptr32<Object> z752; Ptr32<Object> z756; Ptr32<Object> z760; Ptr32<Object> z764; Ptr32<Object> z768; Ptr32<Object> z772; Ptr32<Object> z776; Ptr32<Object> z780; Ptr32<Object> z784; Ptr32<Object> z788; Ptr32<Object> z792; Ptr32<Object> z796; Ptr32<Object> z800; Ptr32<Object> z804; Array list; float f820; int z824; char camera[32]; int z860; char member[8]; };
extern Ptr32<Self> g_self_804aa8c8;
extern Ptr32<void> t_8040e588[];
extern "C" int w3d_ctor_801628b0(Ptr32<void>);
extern "C" Ptr32<void> __16d24d_WaterTargetPCci(Ptr32<void>, Ptr32<const char>, int);
extern "C" Ptr32<void> w3d_spectator_message_801081dc(Ptr32<void>);
extern "C" void fn_80343748(Ptr32<Slot>);
extern "C" Ptr32<void> terra_only_a11_camera_80036218(Ptr32<void>);
extern "C" Ptr32<void> w3d_actor_handle_member_initialize(Ptr32<void>);
extern "C" int w3d_constructor_lookup_name(Ptr32<PropertyKey>, Ptr32<Handle>);
extern "C" Ptr32<Object> w3d_empty_80342a74(Ptr32<Object>);
extern "C" Ptr32<Object> w3d_empty_80342fa4(Ptr32<Object>);
extern "C" Ptr32<Object> w3d_constructor_native_cast(Ptr32<Object>);
template <Ptr32<Object> (*Cast)(Ptr32<Object>)>
inline void Load(Handle &h, Ptr32<const char> name, Ptr32<Object> &slot)
{
    PropertyKey key;
    key.name = name;
    h.value = 0;
    w3d_constructor_lookup_name(&key, &h);
    Ptr32<Object> o = Cast(h.value);
    if (o) o->vtable->retain(o);
    if (slot) slot->vtable->release(slot);
    slot = o;
    if (h.value) h.value->vtable->release(h.value);
}
inline void Drop(Ptr32<Object> &slot, Ptr32<Object> q) { if (slot) slot->vtable->release(slot); slot = q; }
extern "C" Ptr32<Self> w3d_d41a_ray_cam_ctor_800308e4(Ptr32<Self> self)
{
    Ptr32<Slot> s596 = &self->s596;
    w3d_ctor_801628b0(self);
    Ptr32<Slot> s728 = &self->s728;
    self->vt = t_8040e588;
    __16d24d_WaterTargetPCci(self->name, "RayCam", 2);
    self->z108 = 0;
    self->z112 = 0;
    self->z116 = 0;
    self->z120 = 0;
    self->z124 = 0;
    self->z128 = 0;
    self->z132 = 0;
    self->z136 = 0;
    self->z140 = 0;
    self->z144 = 0;
    self->z148 = 0;
    self->z152 = 0;
    self->z156 = 0;
    self->z160 = 0;
    self->z164 = 0;
    self->z168 = 0;
    self->z172 = 0;
    self->z176 = 0;
    self->z180 = 0;
    self->z184 = 0;
    self->z188 = 0;
    self->z192 = 0;
    self->z196 = 0;
    self->z200 = 0;
    self->z204 = 0;
    self->z208 = 0;
    self->z212 = 0;
    self->z216 = 0;
    self->z220 = 0;
    self->z224 = 0;
    self->z228 = 0;
    self->z232 = 0;
    self->z236 = 0;
    self->z240 = 0;
    self->z244 = 0;
    self->z248 = 0;
    self->z252 = 0;
    self->z256 = 0;
    self->z260 = 0;
    self->z264 = 0;
    self->z268 = 0;
    self->z272 = 0;
    self->z276 = 0;
    self->z280 = 0;
    self->z284 = 0;
    self->z288 = 0;
    self->z292 = 0;
    self->z296 = 0;
    self->z300 = 0;
    self->z304 = 0;
    self->z308 = 0;
    new (&self->items) Array;
    __16d24d_WaterTargetPCci(self->local, "Local", 2);
    w3d_spectator_message_801081dc(self->view);
    fn_80343748(s596);
    self->z620 = 0;
    self->z624 = 0;
    self->z628 = 0;
    self->z632 = 0;
    self->z636 = 0;
    self->z640 = 0;
    self->z644 = 0;
    self->z648 = 0;
    self->z652 = 0;
    self->z656 = 0;
    self->z660 = 0;
    self->z664 = 0;
    self->z668 = 0;
    self->z672 = 0;
    self->z676 = 0;
    self->z680 = 0;
    self->z684 = 0;
    self->z688 = 0;
    self->z692 = 0;
    self->z696 = 0;
    self->z700 = 0;
    self->z704 = 0;
    self->z708 = 0;
    self->z712 = 0;
    self->z716 = 0;
    self->z720 = 0;
    self->z724 = 0;
    fn_80343748(s728);
    self->z748 = 0;
    self->z752 = 0;
    self->z756 = 0;
    self->z760 = 0;
    self->z764 = 0;
    self->z768 = 0;
    self->z772 = 0;
    self->z776 = 0;
    self->z780 = 0;
    self->z784 = 0;
    self->z788 = 0;
    self->z792 = 0;
    self->z796 = 0;
    self->z800 = 0;
    self->z804 = 0;
    new (&self->list) Array;
    self->z824 = 0;
    terra_only_a11_camera_80036218(self->camera);
    self->z860 = 0;
    w3d_actor_handle_member_initialize(self->member);
    g_self_804aa8c8 = self;
    s728->Clear();
    s728->word &= ~0x600000;
    s596->Clear();
    s596->word &= ~0x600000;
    Drop(self->z804, 0);
    Drop(self->z800, 0);
    Drop(self->z796, 0);
    Drop(self->z792, 0);
    self->f820 = 0.0f;
    self->z588 = 0;
    self->z592 = 0;
    Handle h;
    Load<w3d_empty_80342a74>(h, "Land.Radius", self->z756);
    Load<w3d_empty_80342fa4>(h, "Land.Center", self->z760);
    Load<w3d_constructor_native_cast>(h, "Airstrike.HasTarget", self->z764);
    Load<w3d_empty_80342fa4>(h, "Airstrike.Direction", self->z768);
    Load<w3d_empty_80342fa4>(h, "Airstrike.TargetPoint", self->z772);
    Load<w3d_constructor_native_cast>(h, "Airstrike.IsWormValidTarget", self->z776);
    Load<w3d_empty_80342a74>(h, "Ninja.MaxLength", self->z780);
    Load<w3d_constructor_native_cast>(h, "Camera.CurrentMode", self->z784);
    Load<w3d_empty_80342a74>(h, "Water.Level", self->z788);
    self->handle().SetSlot(0);
    self->handle().SetWord(17);
    self->handle().Query(1.0f);
    return self;
}


