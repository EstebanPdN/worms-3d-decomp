// Partial layout and structural names inferred from original instructions.
extern unsigned char lbl_80416a90[],lbl_80416a38[];
extern const float lbl_803b02fc[];
struct Tag {unsigned short a,b;union {unsigned value;volatile unsigned char byte[4];} u;};
struct Thing {void **vtable;unsigned pad[9];Tag tag;};
extern "C" Thing *f2c_tag_init_801de524(Thing *self){float v=lbl_803b02fc[0];Tag *tag=&self->tag; self->vtable=(void **)lbl_80416a90;tag->u.byte[3]=2;tag->u.value=tag->u.byte[3];self->vtable=(void **)lbl_80416a38;*(float *)((char *)self+24)=v;
*(unsigned *)((char *)self+32)=0;
*(unsigned *)((char *)self+28)=0;
*(unsigned *)((char *)self+36)=0;return self;}
