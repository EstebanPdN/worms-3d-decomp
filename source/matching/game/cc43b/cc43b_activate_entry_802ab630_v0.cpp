// Native vector construction and partial byte-indexed entry-table access.
// Offset +1364 and index stride four are witnessed; table length is unknown.
struct cc43b_Vector3 { float x,y,z; cc43b_Vector3(float a,float b,float c):x(a),y(b),z(c) {} };
struct cc43b_Entry;
struct cc43b_EntryVtable {
    unsigned int unknown00[5]; void (*start)(cc43b_Entry *); void (*stop)(cc43b_Entry *);
    unsigned int unknown1c[2]; int (*active)(cc43b_Entry *);
    unsigned int unknown28[4]; void (*command)(cc43b_Entry *,int,cc43b_Vector3 *);
};
struct cc43b_Entry { cc43b_EntryVtable *vtable; };
struct cc43b_TableView {
    inline cc43b_Entry *&slot(unsigned int index) {
        return reinterpret_cast<cc43b_Entry **>(reinterpret_cast<unsigned char *>(this)+index*4U)[341];
    }
};
extern float cc43b_xy_803d6ae0[],cc43b_z_803d6ae4[];
extern "C" void cc43b_activate_entry_802ab630(cc43b_TableView *self,unsigned int index) {
    if (self->slot(index)) {
        cc43b_Entry *entry=self->slot(index);
        if (entry->vtable->active(entry)) self->slot(index)->vtable->stop(self->slot(index));
        cc43b_Vector3 value(cc43b_xy_803d6ae0[0],cc43b_xy_803d6ae0[0],cc43b_z_803d6ae4[0]);
        self->slot(index)->vtable->command(self->slot(index),3,&value);
        self->slot(index)->vtable->start(self->slot(index));
    }
}
