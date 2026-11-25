// Inferred collection cleanup; offsets and identities verified against the original.
extern "C" void* cc34a_copy_802eee50(void*,const void*,unsigned int,...);
struct cc34a_Range_80078db8 {
 char* begin; char* end; char* capacity;
 void clear() { char* first=begin; char* last=end; unsigned int removed=last-first; cc34a_copy_802eee50(first,last,0); end-=removed; }
};
struct cc34a_List_80078db8 { unsigned int count; void* data; unsigned int other; };
struct cc34a_Collections_80078db8 {
 unsigned char unknown0[60]; cc34a_List_80078db8 lists[11];
 unsigned char unknown192[572]; int state;
 unsigned char unknown768[1536]; cc34a_Range_80078db8 range900,range90c;
 unsigned char unknown2328[48]; cc34a_Range_80078db8 range948;
 unsigned char unknown2388[60]; cc34a_Range_80078db8 range990;
 void resetRemaining(int v) { range90c.clear(); range948.clear(); range990.clear(); state=v; }
};
extern "C" {
extern int cc34a_global_804b17f4;
extern unsigned char cc34a_heap_804adde4[8];
void cc34a_clear_801f2798(cc34a_List_80078db8*);
void cc34a_free_80209920(void*,void*);
int cc34a_collections_clear_80078db8(cc34a_Collections_80078db8* self) {
 unsigned int count=self->lists[0].count;
 cc34a_global_804b17f4=0;
 unsigned int i=0;
 cc34a_clear_801f2798(&self->lists[0]);
 cc34a_clear_801f2798(&self->lists[1]);
 cc34a_clear_801f2798(&self->lists[2]);
 cc34a_clear_801f2798(&self->lists[3]);
 cc34a_clear_801f2798(&self->lists[6]);
 cc34a_clear_801f2798(&self->lists[8]);
 cc34a_clear_801f2798(&self->lists[9]);
 cc34a_clear_801f2798(&self->lists[7]);
 cc34a_clear_801f2798(&self->lists[4]);
 cc34a_clear_801f2798(&self->lists[5]);
 cc34a_clear_801f2798(&self->lists[10]);
 for(;i<count;++i) { void* p=*(void**)(self->range990.begin+(i<<2)); if(p) cc34a_free_80209920(cc34a_heap_804adde4,p); }
 self->range900.clear(); self->resetRemaining(0);
 return 0;
}
}
