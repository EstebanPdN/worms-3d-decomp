// Inferred native archive end-record decoding. GC32 fields and reader are external.
namespace sol35d10_read_end_record_v3 {
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
typedef char RecordSize[(sizeof(EndRecord)==24)?1:-1];
}
extern "C" int sol35d10_read_end_record_801f8c48_v3(sol35d10_read_end_record_v3::Archive *self,
    sol35d10_read_end_record_v3::EndRecord *out,int with_signature) {
    using namespace sol35d10_read_end_record_v3;
    char bytes[24];
    unsigned byte_count=20;
    if(with_signature) byte_count=24;
    if(self->stream->table->read(self->stream,bytes,byte_count,0)!=0)
        return static_cast<int>(0x80004005u);
    unsigned cursor=0;
    const char *data=bytes;
    if(with_signature) {
        out->signature=fn_801f87f0(data);
        cursor=4;
    }
    out->disk[0]=fn_801f8830(data+cursor); ++cursor;
    out->disk[1]=fn_801f8830(data+cursor); ++cursor;
    out->disk[2]=fn_801f8830(data+cursor); ++cursor;
    out->disk[3]=fn_801f8830(data+cursor); ++cursor;
    out->disk_entries=fn_801f881c(data+cursor); cursor+=2;
    out->entries=fn_801f881c(data+cursor); cursor+=2;
    out->directory_bytes=fn_801f87f0(data+cursor); cursor+=4;
    out->directory_offset=fn_801f87f0(data+cursor); cursor+=4;
    out->comment_bytes=fn_801f881c(data+cursor);
    return 0;
}
