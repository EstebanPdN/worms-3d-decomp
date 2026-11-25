// Inferred structural names and observed PPC32 offsets; externs remain unresolved.
extern "C" {
struct Pair { float first, second; Pair(float value) { first = value; second = value; } };
extern float constant_8037821c[];
void pair_sink_80052044(void *, void *, Pair *);
void w3d_r23a_default_pair_8005200c(void *object, void *argument) { Pair pair(constant_8037821c[0]); pair_sink_80052044(object, argument, &pair); }
struct DualInterface { void *primary; unsigned char unknown4[8]; void *secondary; };
extern unsigned char table_80411728[], table_80411750[], table_80411868[], table_80411890[];
void base_destroy_8020fc60(DualInterface *, void *);
void w3d_r23a_dual_teardown_801611a4(DualInterface *object, void * arg_r4) { object->secondary=table_80411728;object->primary=table_80411750;base_destroy_8020fc60(object, arg_r4); }
void w3d_r23a_dual_teardown_80162a40(DualInterface *object, void * arg_r4) { object->secondary=table_80411868;object->primary=table_80411890;base_destroy_8020fc60(object, arg_r4); }
struct LuaState;
extern char const_error_text_803a9a28[];
void push_string_802cdfd4(LuaState *, const char *);
void concatenate_802ce920(LuaState *, int);
int raise_error_802ce89c(LuaState *);
int w3d_r23a_const_member_error_8019f8f0(LuaState *state) { push_string_802cdfd4(state,const_error_text_803a9a28);concatenate_802ce920(state,2);raise_error_802ce89c(state);return 0; }
// Only the result flag at +104 is observed; virtual lookup is slot +20.
struct FlagResult { unsigned char unknown[104]; unsigned char flag; };
struct Interface;
struct Dispatch { void *unknown[5]; FlagResult *(*lookup)(Interface *); };
struct Interface { Dispatch *dispatch; };
struct Holder { void *unknown0; Interface *held; };
int w3d_r23a_query_flag_800dfd48(Holder *self) { FlagResult *value=self->held->dispatch->lookup(self->held);return value->flag ? 1 : 0; }
// The constructor increments the shared instance count and clears +168.
struct SharedNode { void *dispatch; unsigned char unknown4[164]; int state; };
void * construct_shared_8017990c(SharedNode *);
extern int shared_count_804ab69c;
extern unsigned char table_80412e20[];
SharedNode *w3d_r23a_shared_node_construct_80188a68(SharedNode *self) { construct_shared_8017990c(self);int count=shared_count_804ab69c;self->dispatch=table_80412e20;self->state=0;shared_count_804ab69c=count+1;return self; }
}
