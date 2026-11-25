// Observed native stream word operations; class and field names are inferred.
inline unsigned swap_word(unsigned value) {
    return (value << 24) | ((value & 0xff00) << 8) |
           ((value >> 8) & 0xff00) | (value >> 24);
}
struct Stream;
struct StreamTable { void (*slots[5])(); void (*read)(Stream *,void *,unsigned,unsigned); };
struct Stream { StreamTable *table; };
struct Owner { unsigned prefix[5]; Stream *stream; };
extern "C" void sol35d5_read_word_80201630(Owner *owner, unsigned *value) {
    Stream *stream = owner->stream;
    stream->table->read(stream,value,4,0);
    *value = swap_word(*value);
}
