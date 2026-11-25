struct S21Entry;
struct S21EntryMethods { void (*reserved[4])(struct S21Entry *); void (*release)(struct S21Entry *); };
struct S21Entry { struct S21EntryMethods *methods; char pad[20]; unsigned start; char pad1[20]; int state; };
struct S21Timing { char pad[52]; unsigned limit; };
struct S21Slot { char pad[52]; struct S21Entry *entry; struct S21Timing *timing; };
struct S21Clock { char pad[52]; unsigned now; };
struct S21Inner { char pad[24]; struct S21Slot *slot; };
struct S21Object { char pad[36]; struct S21Inner *inner; };
extern struct S21Clock *fn_80165254(void);
extern void fn_8021dd04(struct S21Entry *);
void w3d_s21_expire_entry_8021bf3c(struct S21Object *self)
{
    struct S21Slot *slot = self->inner->slot;
    struct S21Entry *entry = slot->entry;
    if (entry) {
        if (entry->state == 1) goto go;
        if (entry->state == 2) goto go;
        return;
go:
            if (fn_80165254()->now - entry->start > slot->timing->limit) {
                struct S21Entry *old;
                fn_8021dd04(entry);
                old = slot->entry;
                slot->entry = 0;
                if (old)
                    old->methods->release(old);
            }
    }
}
