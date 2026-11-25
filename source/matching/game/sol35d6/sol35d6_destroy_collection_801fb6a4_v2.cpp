// Partial native owner and release interfaces from original offsets.
namespace Sol35d6DestroyCollectionV2 {
struct Service;
struct Table { void *unknown[4]; int (*release)(Service *); };
struct Service { Table *table; };
extern "C" {
extern unsigned char sol35d6_derived_80418210[],sol35d6_base_804182d0[];
void sol35d6_storage_release_802134fc(void *);
void sol35d6_node_destroy_80210990(void *,int);
void sol35d6_delete_801fe1f8(void *);
}
struct Vector {
    Service **begin,**end,**capacity;
    void release_elements() {
        Service **position=begin;
        if(position!=end) do {
            Service *element=*position;
            if(element) element->table->release(element);
            ++position;
        } while(position!=end);
    }
};
struct Owner {
    void *table; unsigned prefix[8];
    Vector values; unsigned unknown48; void *storage;
};
}
extern "C" void sol35d6_destroy_collection_801fb6a4_v2(
    Sol35d6DestroyCollectionV2::Owner *self,unsigned flags) {
    using namespace Sol35d6DestroyCollectionV2;
    self->table=sol35d6_derived_80418210;
    self->values.release_elements();
    if(self->storage) sol35d6_storage_release_802134fc(self->storage);
    if(self->values.begin) sol35d6_storage_release_802134fc(self->values.begin);
    self->table=sol35d6_base_804182d0;
    sol35d6_node_destroy_80210990((char *)self+8,0);
    if(flags&1) sol35d6_delete_801fe1f8(self);
}
typedef char Sol35d6CollectionOffset[(unsigned)&((Sol35d6DestroyCollectionV2::Owner*)0)->values==36?1:-1];
