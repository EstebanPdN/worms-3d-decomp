typedef struct S9VideoRelease {
    void *buffer;
    char unknown4[552];
    int ready;
} S9VideoRelease;
extern void fn_801fe2e0(void *);
extern int fn_802fb7ac(const char *,...);
extern char lbl_803a6398[];
void s9_release_video_buffer_8016e698(S9VideoRelease *self)
{
    if(self->ready) {
        if(self->buffer)fn_801fe2e0(self->buffer);
        self->buffer=0;
        fn_802fb7ac(lbl_803a6398);
    }
    self->ready=0;
}
