/* Observed 24-byte entry: graph word at +0, type value at +4, name value at +20 (passed by address). */
struct Cc17cGraphEntry { int graph; int type[4]; int name; };
struct Cc17cWriter;
/* Observed writer virtual slots (4-byte entries): +32 integer field, +128 and +136 addressed
 * fields with a trailing zero, +160 array header with element count. Inferred roles. */
struct Cc17cWriterTable {
    char pad0[32];
    int (*write_int)(Cc17cWriter *, int, const char *);
    char pad36[92];
    int (*write_name)(Cc17cWriter *, int *, const char *, int);
    char pad132[4];
    int (*write_type)(Cc17cWriter *, int *, const char *, int);
    char pad140[20];
    int (*begin_array)(Cc17cWriter *, int, const char *);
};
struct Cc17cWriter { Cc17cWriterTable *vtable; };
struct Cc17cGraphVector {
    Cc17cGraphEntry *start; Cc17cGraphEntry *finish;
    int size() const { return finish - start; }
};
struct Cc17cGraphOwner { char pad0[20]; Cc17cGraphVector entries; };
extern "C" char lbl_803aa754[], lbl_803aa75c[], lbl_803aa764[];
extern "C" int w3d_cc17c_graph_entries_write_801aec00(Cc17cGraphOwner *self, Cc17cWriter *writer)
{
    Cc17cGraphVector *entries = &self->entries;
    writer->vtable->begin_array(writer, entries->size(), lbl_803aa754);
    Cc17cGraphEntry *end = entries->finish;
    for (Cc17cGraphEntry *it = self->entries.start; it != end; ++it) {
        writer->vtable->write_type(writer, it->type, lbl_803aa754, 0);
        writer->vtable->write_int(writer, it->graph, lbl_803aa75c);
        writer->vtable->write_name(writer, &it->name, lbl_803aa764, 0);
    }
    return 0;
}
