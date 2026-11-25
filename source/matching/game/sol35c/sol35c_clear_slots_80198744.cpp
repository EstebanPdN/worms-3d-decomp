// Eighty observed sixteen-byte entries. Unknown bits retain their exact value.
struct Sol35cProvider { void **vtable; };
struct Sol35cEntry { unsigned key; Sol35cProvider *provider; unsigned count; unsigned flags:2; unsigned preserved:30; };
extern "C" void fn_80197f98(void *,unsigned);
extern "C" void sol35c_clear_slots_80198744(Sol35cEntry *entry) {
 Sol35cEntry *last=entry+79;
 do {
  Sol35cProvider *provider=entry->provider;
  if(provider) {
   char *records=((char *(*)(Sol35cProvider *,unsigned))provider->vtable[9])(provider,entry->key);
   provider=entry->provider;
   unsigned count=((unsigned (*)(Sol35cProvider *,unsigned))provider->vtable[10])(provider,entry->key);
   fn_80197f98(records+8,count);
  }
  entry->key=0;
  entry->provider=0;
  entry->flags=0;
  entry->count=0;
  ++entry;
 }while(entry<=last);
}
