// Partial preview owner, service and reference-counted collection interfaces.
// Unknown prefixes document observed offsets without asserting complete sizes.
struct d11b_PreviewControl;
struct d11b_PreviewTable {
    unsigned int unknown00[4]; void (*release)(d11b_PreviewControl *);
    unsigned int unknown14[19]; void (*remove)(d11b_PreviewControl *,d11b_PreviewControl *);
    unsigned int unknown64[4]; d11b_PreviewControl *(*item)(d11b_PreviewControl *,unsigned int);
    unsigned int (*count)(d11b_PreviewControl *);
};
struct d11b_PreviewControl { d11b_PreviewTable *vtable; };
struct d11b_PreviewHandle {
    d11b_PreviewControl *value;
    void reset(d11b_PreviewControl *next) { if(value)value->vtable->release(value);value=next; }
};
struct d11b_PreviewOwner { unsigned char unknown00[68]; d11b_PreviewControl *root; d11b_PreviewHandle first,second; };
struct d11b_PreviewService;
struct d11b_PreviewServiceTable { unsigned int unknown00[49]; void (*removeLight)(d11b_PreviewService *,const char *,int); };
struct d11b_PreviewService { d11b_PreviewServiceTable *vtable; };
struct d11b_PreviewServices { unsigned char unknown00[116]; d11b_PreviewService *scene; };
extern d11b_PreviewServices *d11b_preview_services_804b17ec;
extern const char d11b_preview_light_803cbd18[];
extern "C" void d11b_release_preview_root_8015fd1c(d11b_PreviewControl *);
extern "C" void d11b_clear_preview_8026d328(d11b_PreviewOwner *self) {
    if(self->root) {
        d11b_preview_services_804b17ec->scene->vtable->removeLight(d11b_preview_services_804b17ec->scene,d11b_preview_light_803cbd18,4);
        if(self->second.value) while(self->second.value->vtable->count(self->second.value)) {
            d11b_PreviewControl *object=self->second.value;
            d11b_PreviewTable *table=object->vtable;
            table->remove(object,table->item(object,0));
        }
        if(self->first.value) while(self->first.value->vtable->count(self->first.value)) {
            d11b_PreviewControl *object=self->first.value;
            d11b_PreviewTable *table=object->vtable;
            table->remove(object,table->item(object,0));
        }
        self->first.reset(0);self->second.reset(0);
        d11b_release_preview_root_8015fd1c(self->root);
        self->root=0;
    }
}
