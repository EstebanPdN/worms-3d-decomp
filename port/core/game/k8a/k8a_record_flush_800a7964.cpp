#include "w3d_ptr.h"
#line 1 "k8a_record_flush_800a7964.cpp"
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
    Ptr32<K8aRecord> begin;
    Ptr32<K8aRecord> end;
};
struct K8aRecordList
{
    int pad0;
    K8aRecordVector records; // +4
};
struct K8aOwner
{
    char pad0[172];
    Ptr32<K8aRecordList> list;     // +172
};
extern "C" void w3d_memcpy_802eee50(Ptr32<void> dest, Ptr32<const void> source, unsigned int size, ...);
extern "C" void w3d_record_report_800a76a4(Ptr32<K8aOwner> self, Ptr32<char> text, int value);
static inline void k8a_clear(Ptr32<K8aRecordVector> v)
{
    Ptr32<K8aRecord> first = v->begin;
    Ptr32<K8aRecord> last = v->end;
    int removed = (Ptr32<char>)last - (Ptr32<char>)first;
    w3d_memcpy_802eee50(first, last, (Ptr32<char>)v->end - (Ptr32<char>)last);
    v->end = (Ptr32<K8aRecord>)((Ptr32<char>)v->end - removed);
}
extern "C" void w3d_k8a_record_flush_800a7964(Ptr32<K8aOwner> self)
{
    for (Ptr32<K8aRecord> record = self->list->records.begin; record != self->list->records.end; record++)
        w3d_record_report_800a76a4(self, record->text, record->value);
    k8a_clear(&self->list->records);
}


