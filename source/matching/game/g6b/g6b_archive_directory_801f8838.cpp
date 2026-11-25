typedef unsigned int Word;
typedef unsigned short Half;
struct Stream;
struct StreamTable {
    void *unknown00[5];
    int (*read)(Stream *, void *, Word, Word *);
    void *unknown18;
    int (*seek)(Stream *, int, int, Word *);
    void *unknown20;
    int (*information)(Stream *, void *);
};
struct Stream { StreamTable *table; };
struct EndRecord {
    Word signature;
    unsigned char diskBytes[4];
    Half diskEntries, entries;
    Word directoryBytes, directoryOffset;
    Half commentBytes;
};
struct CentralRecord {
    Word signature;
    Half version;
    unsigned char versionNeeded, host;
    Half flags, method;
    Word date, crc, compressedBytes, rawBytes;
    Half nameBytes, extraBytes, commentBytes;
    Half disk;
    Word attributes, externalAttributes, localOffset;
};
struct DirectoryEntry { char name[52]; Word payloadOffset, compressedBytes, rawBytes; };
struct ArchiveView {
    char unknown00[20];
    Stream *stream;
    Word unknown18;
    unsigned char scanned;
    char unknown1d[3];
    int entries;
    DirectoryEntry *directory;
};
struct StreamInformation { Word words[4]; };
extern "C" int fn_801f8c48(ArchiveView *, EndRecord *, int);
extern "C" int fn_801f8b7c(ArchiveView *, CentralRecord *, const char *);
extern "C" Word fn_801f87f0(const char *);
extern "C" void *fn_801fe2a8(Word, Word);
extern "C" char *fn_801fe0b8(Word);
extern "C" char *fn_802efbfc(char *, const char *, Word);
extern "C" void fn_80347324(void *, const char *, ...);
extern char trace_804b0640[];
extern const char format_803b1974[];
extern "C" int g6b_archive_directory_801f8838(ArchiveView *self) {
    if (self->scanned) return self->directory ? 0 : (int)0x80004005;
    self->scanned = 1;
    int result = 0;
    Word position;
    self->stream->table->seek(self->stream,0,0,&position);
    self->stream->table->seek(self->stream,0,2,&position);
    self->stream->table->seek(self->stream,0,1,&position);
    StreamInformation information;
    self->stream->table->information(self->stream,&information);
    self->stream->table->seek(self->stream,position-24,0,&position);
    EndRecord end;
    fn_801f8c48(self,&end,1);
    if (end.signature != 0x06054b50) {
        result = (int)0x80004005;
        if (position) {
            Word scan = position;
            do {
                --scan;
                self->stream->table->seek(self->stream,scan,0,0);
                char signature[4];
                Word bytesRead;
                self->stream->table->read(self->stream,signature,4,&bytesRead);
                end.signature = fn_801f87f0(signature);
                if (end.signature == 0x06054b50) {
                    result = fn_801f8c48(self,&end,0);
                    break;
                }
            } while (scan);
        }
    }
    if (result == 0) {
        int index = 0;
        self->directory = (DirectoryEntry *)fn_801fe2a8((Word)end.entries << 6,64);
        self->entries = end.entries;
        char *cursor = fn_801fe0b8(end.directoryBytes);
        self->stream->table->seek(self->stream,end.directoryOffset,0,0);
        self->stream->table->read(self->stream,cursor,end.directoryBytes,0);
        while (index < self->entries) {
            CentralRecord header;
            fn_801f8b7c(self,&header,cursor);
            DirectoryEntry *entry = self->directory + index;
            ++index;
            fn_802efbfc(entry->name,cursor+46,header.nameBytes);
            entry->name[header.nameBytes] = 0;
            entry->payloadOffset = header.localOffset + header.nameBytes + 30;
            entry->compressedBytes = header.compressedBytes;
            entry->rawBytes = header.rawBytes;
            char *name = entry->name;
            while (*name) { if (*name == '\\') *name='/'; ++name; }
            fn_80347324(trace_804b0640,format_803b1974,entry->name);
            cursor += header.commentBytes + header.nameBytes +46 +header.extraBytes;
        }
        result = 0;
    }
    return result;
}
