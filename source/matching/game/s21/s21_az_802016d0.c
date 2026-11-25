// desc: Appears to read a sixteen-byte identifier from the inner stream and byte-swap its leading word and two halfwords when the read succeeds, returning the status.
struct S21Stream;
struct S21StreamMethods { void (*reserved[5])(void); int (*read)(struct S21Stream *, void *, int, int); };
struct S21Stream { struct S21StreamMethods *methods; };
struct S21Reader { char pad[20]; struct S21Stream *stream; };
struct S21Guid { unsigned data1; unsigned short data2; unsigned short data3; unsigned char data4[8]; };
int w3d_s21_read_guid_802016d0(struct S21Reader *self, struct S21Guid *guid)
{
    int status = self->stream->methods->read(self->stream, guid, 16, 0);
    if (status >= 0) {
        unsigned a = guid->data1;
        unsigned short b = guid->data2;
        unsigned short c = guid->data3;
        guid->data1 = (a << 24) | ((a << 8) & 0xff0000) | ((a >> 8) & 0xff00) | (a >> 24);
        guid->data2 = ((b & 0xff) << 8) | ((b >> 8) & 0xff);
        guid->data3 = ((c & 0xff) << 8) | ((c >> 8) & 0xff);
    }
    return status;
}
