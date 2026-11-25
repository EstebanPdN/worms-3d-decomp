// All layouts below are destruction-only views of external objects.
extern "C" void *copy_802eee50(void *, const void *, ...);
extern "C" void service_destroy_801628ec(void *, int);
extern "C" unsigned vtable_8040e8f8[];
struct F18cServicePrefix;
extern "C" F18cServicePrefix *service_slot_804aa96c;
struct F18cHeldPrefix { void **vtable; };
struct F18cRecord { unsigned char unknown[28]; F18cHeldPrefix *held; ~F18cRecord() { if (held) ((void (*)(F18cHeldPrefix *))held->vtable[4])(held); } };
struct F18cRecordRange { F18cRecord *begin, *end; void clear() { F18cRecord *first=begin; F18cRecord *last=end; for(F18cRecord *p=first;p!=last;++p)p->~F18cRecord(); end=first; } };
struct F18cByteRange { char *begin, *end; void clear() { char *last=end; unsigned removed=last-begin; copy_802eee50(begin,last,0); end-=removed; } };
extern "C" F18cRecordRange records_804273ec[];
extern "C" F18cByteRange bytes_804273fc[];
struct F18cServicePrefix { void *vtable; };
extern "C" void f18c_service_cleanup_8003f2a4(F18cServicePrefix *self,int flags) {
 self->vtable=vtable_8040e8f8;
 service_slot_804aa96c=0;
 records_804273ec[0].clear();
 bytes_804273fc[0].clear();
 service_destroy_801628ec(self,flags);
}
