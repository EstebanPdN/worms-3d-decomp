// Formatted text writer (Worms 3D GameCube PAL, 0x8020d750).
//
// Formats into a 512-byte stack buffer with vsnprintf (0x802ed63c). If the
// result fits, it goes to the sink's virtual write (+24). Otherwise it retries
// with temporary buffers (0x801fe0b8, 0x801fe160) starting at 1024 bytes and
// doubling until the length is below the capacity and not -1, writes that and
// releases the buffer. Returns the writer. The retry is a real do/while(1):
// loop depth weighting of register references gives the original's saved
// register order (writer in r27). Sink and writer layouts are partial views.
struct Sink;
struct SinkVtable {
    void *unknown00[6];
    int (*write)(Sink *, const char *, unsigned int, void *);  // +24
};
struct Sink { SinkVtable *vtable; };
struct Writer { Sink *sink; };
extern "C" int vsnprintf_802ed63c(char *, unsigned int, const char *, void *);
extern "C" char *temp_alloc_801fe0b8(unsigned int);
extern "C" void temp_release_801fe160(void *);
extern "C" Writer *w3d_d24k_writer_format_list_8020d750(Writer *self, const char *format, void *args) {
    char local[512];
    unsigned int n = vsnprintf_802ed63c(local, 512, format, args);
    if (n >= 512) {
        int capacity = 1024;
        do {
            char *buffer = temp_alloc_801fe0b8(capacity);
            int length = vsnprintf_802ed63c(buffer, capacity, format, args);
            if (length < capacity && length != -1) {
                self->sink->vtable->write(self->sink, buffer, length, 0);
                temp_release_801fe160(buffer);
                break;
            }
            capacity += capacity;
            temp_release_801fe160(buffer);
        } while (1);
    }
    else {
        self->sink->vtable->write(self->sink, local, n, 0);
    }
    return self;
}
