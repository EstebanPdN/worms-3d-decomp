#include "w3d_ptr.h"
#line 1 "d26k_read_team_item_8021bb9c.cpp"
// Read a team item from a stream (Worms 3D GameCube PAL, 0x8021bb9c).
// 
// Reads a 4-byte header, deserializes an item through the reader service
// 0x80418de0, walks the item's type chain to the root type 0x80366ca8, and when
// the group matches 0x804af594 looks the item's name up in the owner. Stores the
// result in *out and returns 1 when it has a nonzero property value; otherwise 0.

struct Object;
struct ObjectTable {
    Ptr32<void> reserved[3];
    Ptr32<int (Ptr32<Object>)> retain;
    Ptr32<int (Ptr32<Object>)> release;
};
struct Object { Ptr32<ObjectTable> table; };
struct Ref {
    Ptr32<Object> p;
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Object *)w3d_p.get()) {}
 Ref(Object *o) : p(o) { if (p) p->table->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->table->release(p); }
};

struct Type { char pad[20]; Ptr32<Type> base; };
struct Stream;
struct StreamTable { Ptr32<void> pad[5]; Ptr32<int (Ptr32<Stream>, Ptr32<void>, int, int)> read; };
struct Stream { Ptr32<StreamTable> table; };
struct Item;
struct ItemTable { Ptr32<void> pad[4]; Ptr32<int (Ptr32<Item>)> release; Ptr32<Ptr32<Type> (Ptr32<Item>)> type; };
struct Item { Ptr32<ItemTable> table; char pad[24 - 4]; int name; int group; };
struct Reader;
struct ReaderTable { Ptr32<void> pad[5]; Ptr32<int (Ptr32<Reader>, Ptr32<Stream>)> bind; Ptr32<void> pad2[2]; Ptr32<int (Ptr32<Reader>, Ptr32<Ptr32<Item>>, int)> get; };
struct Reader { Ptr32<ReaderTable> table; };
struct Team { char pad[36]; Ptr32<void> owner; };
extern Type type_80366ca8[];
extern int global_804af594;
extern const char key_80418de0[];
extern "C" Ptr32<Object> lookup_8020b680(Ptr32<const void>);
extern "C" Ptr32<void> find_8021eb70(Ptr32<void>, int);
extern "C" Ptr32<void> props_80240994(Ptr32<void>);
extern "C" int get_8021ed0c(Ptr32<void>);
inline bool isKind(Ptr32<Type> t) {
    while (t != type_80366ca8) {
        Ptr32<Type> next = t->base;
        if (t == next) return false;
        t = next;
    }
    return true;
}
extern "C" int w3d_d26k_read_team_item_8021bb9c(Ptr32<Team> self, Ptr32<Stream> stream, Ptr32<Ptr32<void>> out) {
    int header;
    Ptr32<Item> item;
    stream->table->read(stream, &header, 4, 0);
    Ref r(lookup_8020b680(key_80418de0));
    reinterpret_cast<Reader *>(w3d::R(r.p))->table->bind(reinterpret_cast<Reader *>(w3d::R(r.p)), stream);
    reinterpret_cast<Reader *>(w3d::R(r.p))->table->get(reinterpret_cast<Reader *>(w3d::R(r.p)), &item, 0);
    if (isKind(item->table->type(item))) {
        if (item->group != global_804af594) {
            item->table->release(item);
            return 0;
        }
        Ptr32<void> found = find_8021eb70(self->owner, item->name);
        *out = found;
        if (found && get_8021ed0c(props_80240994(found))) {
            item->table->release(item);
            return 1;
        }
    }
    item->table->release(item);
    return 0;
}


