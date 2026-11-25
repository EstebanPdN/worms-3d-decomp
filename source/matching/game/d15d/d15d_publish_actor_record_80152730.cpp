/* Actor record publication recovered from 0x80152730 (SN ProDG g++ 2.95).
 * The global record assignment is the implicit g++ 2.95 copy assignment, which
 * keeps the destination's virtual table word. */
/* Observed 184-byte record (see cx9c_copy_transform_record.cpp): 36 data bytes,
 * the virtual table word at +36, then 144 derived bytes. Partial views. */
struct D15dRecordBase {
    float triples[9];
    virtual ~D15dRecordBase();
};
struct D15dRecord : D15dRecordBase {
    unsigned int words[36];
    D15dRecord(const D15dRecord &);
    ~D15dRecord();
};
struct D15dContext { unsigned char pad00[52]; int time; };
struct D15dCache { int id; const char *name; };
struct D15dMessage { short id; short pad02; void *type; };
struct D15dActor {
    unsigned char pad000[332];
    int record_time;
    unsigned char pad150[352 - 336];
    D15dRecord record;
};
extern "C" {
D15dContext *w3d_engine_get_context(void);
extern void *w3d_global_804b1754;
D15dMessage *tsonnet_b33_arena_801613f0(void *, int);
short w3d_cached_message_id(D15dCache *, int);
extern D15dCache w3d_cached_804afdfc;
extern void *w3d_message_type_8040db38[];
int w3d_message_post_current(D15dMessage *);
extern int w3d_flag_804aaae8;
extern D15dRecord w3d_record_8042ff68;
void w3d_actor_reset_construction_words(D15dActor *);
D15dMessage *w3d_auto_80131b50(D15dMessage *, int);
void d15d_actor_publish_record_80152730(D15dActor *self);
}

void d15d_actor_publish_record_80152730(D15dActor *self)
{
    if (w3d_engine_get_context()->time - self->record_time > 500) {
        D15dMessage *message = tsonnet_b33_arena_801613f0(w3d_global_804b1754, 8);
        message->id = w3d_cached_message_id(&w3d_cached_804afdfc, 1);
        message->type = w3d_message_type_8040db38;
        w3d_message_post_current(message);
        {
            D15dRecord copy(self->record);
            w3d_flag_804aaae8 = 1;
            w3d_record_8042ff68 = copy;
        }
        w3d_actor_reset_construction_words(self);
        w3d_message_post_current(w3d_auto_80131b50(tsonnet_b33_arena_801613f0(w3d_global_804b1754, 12), 5));
    }
}
