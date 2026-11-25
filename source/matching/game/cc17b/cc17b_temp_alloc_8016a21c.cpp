/* Observed allocator header at +224: cursor, base address, capacity.
   The diagnostic identifies the temporary-buffer role. */
struct Cc17bTemporaryArena { char reserved[224]; unsigned cursor; unsigned char *base; unsigned capacity; };
extern "C" {
extern char message_803a50c4[];
void fn_801fcb64(const char *,unsigned);
void *w3d_cc17b_temp_alloc_8016a21c(Cc17bTemporaryArena *self,unsigned bytes) {
 unsigned cursor=self->cursor;
 unsigned char *base=self->base;
 unsigned next=cursor+((bytes+127)&~127u);
 unsigned char *result=base+cursor;
 self->cursor=next;
 if(next>self->capacity)fn_801fcb64(message_803a50c4,bytes);
 return result;
}
}
