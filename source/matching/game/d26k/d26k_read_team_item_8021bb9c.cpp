// Read a team item from a stream (Worms 3D GameCube PAL, 0x8021bb9c).
// 
// Reads a 4-byte header, deserializes an item through the reader service
// 0x80418de0, walks the item's type chain to the root type 0x80366ca8, and when
// the group matches 0x804af594 looks the item's name up in the owner. Stores the
// result in *out and returns 1 when it has a nonzero property value; otherwise 0.

struct Object;
struct ObjectTable {
    void *reserved[3];
    int (*retain)(Object *);
    int (*release)(Object *);
};
struct Object { ObjectTable *table; };
struct Ref {
    Object *p;
    Ref(Object *o) : p(o) { if (p) p->table->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->table->release(p); }
};

struct Type { char pad[20]; Type *base; };
struct Stream;
struct StreamTable { void *pad[5]; int (*read)(Stream *, void *, int, int); };
struct Stream { StreamTable *table; };
struct Item;
struct ItemTable { void *pad[4]; int (*release)(Item *); Type *(*type)(Item *); };
struct Item { ItemTable *table; char pad[24 - 4]; int name; int group; };
struct Reader;
struct ReaderTable { void *pad[5]; int (*bind)(Reader *, Stream *); void *pad2[2]; int (*get)(Reader *, Item **, int); };
struct Reader { ReaderTable *table; };
struct Team { char pad[36]; void *owner; };
extern Type type_80366ca8[];
extern int global_804af594;
extern const char key_80418de0[];
extern "C" Object *lookup_8020b680(const void *);
extern "C" void *find_8021eb70(void *, int);
extern "C" void *props_80240994(void *);
extern "C" int get_8021ed0c(void *);
inline bool isKind(Type *t) {
    while (t != type_80366ca8) {
        Type *next = t->base;
        if (t == next) return false;
        t = next;
    }
    return true;
}
extern "C" int w3d_d26k_read_team_item_8021bb9c(Team *self, Stream *stream, void **out) {
    int header;
    Item *item;
    stream->table->read(stream, &header, 4, 0);
    Ref r(lookup_8020b680(key_80418de0));
    reinterpret_cast<Reader *>(r.p)->table->bind(reinterpret_cast<Reader *>(r.p), stream);
    reinterpret_cast<Reader *>(r.p)->table->get(reinterpret_cast<Reader *>(r.p), &item, 0);
    if (isKind(item->table->type(item))) {
        if (item->group != global_804af594) {
            item->table->release(item);
            return 0;
        }
        void *found = find_8021eb70(self->owner, item->name);
        *out = found;
        if (found && get_8021ed0c(props_80240994(found))) {
            item->table->release(item);
            return 1;
        }
    }
    item->table->release(item);
    return 0;
}
