// Appears to flush the pending records of an owner: each 40-byte record is reported
// through the owner's handler, then the record list is emptied.
struct K8aRecord
{
    char flag;
    char text[35];
    int value;               // +36
};
struct K8aRecordVector
{
    K8aRecord *begin;
    K8aRecord *end;
};
struct K8aRecordList
{
    int pad0;
    K8aRecordVector records; // +4
};
struct K8aOwner
{
    char pad0[172];
    K8aRecordList *list;     // +172
};
extern "C" void w3d_memcpy_802eee50(void *dest, const void *source, unsigned int size, ...);
extern "C" void w3d_record_report_800a76a4(K8aOwner *self, char *text, int value);
static inline void k8a_clear(K8aRecordVector *v)
{
    K8aRecord *first = v->begin;
    K8aRecord *last = v->end;
    int removed = (char *)last - (char *)first;
    w3d_memcpy_802eee50(first, last, (char *)v->end - (char *)last);
    v->end = (K8aRecord *)((char *)v->end - removed);
}
extern "C" void w3d_k8a_record_flush_800a7964(K8aOwner *self)
{
    for (K8aRecord *record = self->list->records.begin; record != self->list->records.end; record++)
        w3d_record_report_800a76a4(self, record->text, record->value);
    k8a_clear(&self->list->records);
}
