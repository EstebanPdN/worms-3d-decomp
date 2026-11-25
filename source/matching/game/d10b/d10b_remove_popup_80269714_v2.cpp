// Partial reference-counted interface, owner, and service views.
// The temporary handle owns one acquired reference; its destructor releases it.
struct d10b_PopupControl;
struct d10b_PopupTable {
    unsigned int unknown00[4]; void (*release)(d10b_PopupControl *);
    unsigned int unknown14[19]; void (*remove)(d10b_PopupControl *,d10b_PopupControl *);
    unsigned int unknown64[4]; d10b_PopupControl *(*item)(d10b_PopupControl *,unsigned int);
    unsigned int (*count)(d10b_PopupControl *);
};
struct d10b_PopupControl { d10b_PopupTable *vtable; };
struct d10b_PopupHandle;
struct d10b_PopupManager;
extern "C" d10b_PopupHandle *d10b_acquire_popup_8026d850(d10b_PopupHandle *,d10b_PopupManager *);
struct d10b_PopupHandle {
    d10b_PopupControl *value;
    d10b_PopupHandle(d10b_PopupManager *manager) { d10b_acquire_popup_8026d850(this,manager); }
    ~d10b_PopupHandle() { if (value) value->vtable->release(value); }
    d10b_PopupControl *get() const { return value; }
};
struct d10b_PopupManager;
struct d10b_PopupBase;
struct d10b_PopupOwner { unsigned char unknown00[112]; d10b_PopupControl *parent; };
extern d10b_PopupManager *d10b_popup_manager_804abb7c;
extern "C" void d10b_show_popup_8026d8e8(d10b_PopupManager *,int);
extern "C" void d10b_finish_popup_owner_8015fd1c(d10b_PopupOwner *);
extern "C" void d10b_popup_base_action_802b1f98(d10b_PopupBase *);
extern "C" void d10b_remove_popup_80269714(d10b_PopupOwner *self,int action) {
    if (action==1) {
        if (d10b_PopupHandle(d10b_popup_manager_804abb7c).get()) {
            for (unsigned int i=0;i<self->parent->vtable->count(self->parent);++i) {
                d10b_PopupControl *item=self->parent->vtable->item(self->parent,i);
                if (item==d10b_PopupHandle(d10b_popup_manager_804abb7c).get()) {
                    d10b_PopupControl *parent=self->parent;
                    d10b_PopupTable *table=parent->vtable;
                    table->remove(parent,d10b_PopupHandle(d10b_popup_manager_804abb7c).get());
                    d10b_show_popup_8026d8e8(d10b_popup_manager_804abb7c,0);
                    break;
                }
            }
        }
        d10b_finish_popup_owner_8015fd1c(self);
    } else {
        d10b_popup_base_action_802b1f98(reinterpret_cast<d10b_PopupBase *>(reinterpret_cast<unsigned char *>(self)+28));
    }
}
