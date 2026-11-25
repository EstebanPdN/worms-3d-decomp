// desc: Appears to pass two fields of the linked record to a helper and then store minus 34 into a status field of the object.
struct S21Record { char pad[32]; int first; int second; };
struct S21Object { char pad[4]; struct S21Record *record; char pad1[4]; int status; };
extern void fn_802fa95c(int, int);
void w3d_s21_apply_record_802ac1e4(struct S21Object *self)
{
    struct S21Record *record = self->record;
    fn_802fa95c(record->second, record->first);
    self->status = -34;
}
