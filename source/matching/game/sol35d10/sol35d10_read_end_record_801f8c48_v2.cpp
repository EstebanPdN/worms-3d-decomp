// Inferred native archive end-record decoding. GC32 fields and reader are external.
namespace sol35d10_read_end_record_v2 {
struct Stream;
struct StreamTable {
    void (*unknown[5])();
    int (*read)(Stream *,void *,unsigned,unsigned *);
};
struct Stream { StreamTable *table; };
struct Archive { unsigned prefix[5]; Stream *stream; };
struct EndRecord {
    unsigned signature;
    unsigned char disk[4];
    unsigned short disk_entries,entries;
    unsigned directory_bytes,directory_offset;
    unsigned short comment_bytes;
};
extern "C" unsigned fn_801f87f0(const char *);
extern "C" unsigned fn_801f881c(const char *);
extern "C" unsigned fn_801f8830(const char *);
struct Reader {
    const char *bytes;
    unsigned cursor;
    Reader(const char *p) : bytes(p),cursor(0) {}
    unsigned byte() { unsigned v=fn_801f8830(bytes+cursor);++cursor;return v; }
    unsigned half() { unsigned v=fn_801f881c(bytes+cursor);cursor+=2;return v; }
    unsigned word() { unsigned v=fn_801f87f0(bytes+cursor);cursor+=4;return v; }
};
typedef char RecordSize[(sizeof(EndRecord)==24)?1:-1];
}
extern "C" int sol35d10_read_end_record_801f8c48_v2(sol35d10_read_end_record_v2::Archive *self,
    sol35d10_read_end_record_v2::EndRecord *out,int with_signature) {
    using namespace sol35d10_read_end_record_v2;
    char bytes[24];
    unsigned byte_count=20;
    if(with_signature) byte_count=24;
    if(self->stream->table->read(self->stream,bytes,byte_count,0)!=0)
        return static_cast<int>(0x80004005u);
    Reader reader(bytes);
    if(with_signature) out->signature=reader.word();
    out->disk[0]=reader.byte();
    out->disk[1]=reader.byte();
    out->disk[2]=reader.byte();
    out->disk[3]=reader.byte();
    out->disk_entries=reader.half();
    out->entries=reader.half();
    out->directory_bytes=reader.word();
    out->directory_offset=reader.word();
    out->comment_bytes=reader.half();
    return 0;
}
