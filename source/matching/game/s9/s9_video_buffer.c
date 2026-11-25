/* Inferred video buffer setup and platform format branch. */
typedef struct S9VideoBuffer {
    void *buffer;
    char unknown4[552];
    int ready;
} S9VideoBuffer;
extern int fn_802fce18(void);
extern void *fn_801fe2a8(unsigned int,unsigned int);
extern int fn_802fb7ac(const char *,...);
extern void fn_802fd8e4(void *);
extern char lbl_803a6368[],lbl_803a6380[];
void s9_initialize_video_buffer_8016e608(S9VideoBuffer *self)
{
    if(fn_802fce18()==1) {
        self->buffer=fn_801fe2a8(0x120f00,0x20);
        fn_802fb7ac(lbl_803a6368);
    } else {
        self->buffer=fn_801fe2a8(0x20120,0x20);
        fn_802fb7ac(lbl_803a6380);
    }
    fn_802fd8e4(self->buffer);
    self->ready=1;
}
