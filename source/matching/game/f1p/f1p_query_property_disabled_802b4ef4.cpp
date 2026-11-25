// Original 0x802b4ef4: optional property-to-disabled-state query.
// Branch arms deliberately retain the observed flag computation.
struct Item;
struct VTable { void *pad[6]; int (*kind)(Item *); };
struct Item { VTable *v; };
struct Owner { char pad[220]; int disabled; char pade0[28]; Item *item; };
extern "C" void *fn_803426b4(Item *);
extern "C" int fn_80178c48(void *);
extern "C" void *fn_80342a78(Item *);
extern "C" int fn_80178d1c(void *);
extern "C" int w3d_query_property_disabled_802b4ef4(Owner *self) {
    if(self->item) {
        int value=0;
        switch(self->item->v->kind(self->item)) {
        case 0: value=fn_80178c48(fn_803426b4(self->item)); break;
        case 1: value=fn_80178d1c(fn_80342a78(self->item)); break;
        }
        if(!value) self->disabled=1; else self->disabled=0;
    }
    return self->disabled;
}
