struct K4aSource;
typedef struct K4aSourceVtable { void (*unknown_00[9])(void); int (*is_busy)(struct K4aSource *self); } K4aSourceVtable;
typedef struct K4aSource { const K4aSourceVtable *vtable; } K4aSource;
typedef struct K4aSpeaker { char pad0[524]; K4aSource *source; char pad1[200]; int pending; } K4aSpeaker;
extern char w3d_str_8039f87c[];
extern char w3d_str_8039f880[];
extern unsigned int fn_80162C20(void);
extern void FUN_8013bd0c(K4aSpeaker *self, const char *text);

void k4a_speaker_pick_line_8013f0cc(K4aSpeaker *self)
{
    if (self->pending != 0 && self->source != 0 && self->source->vtable->is_busy(self->source) != 0)
        return;
    self->pending = 0;
    switch (fn_80162C20() & 1) {
    case 0:
        FUN_8013bd0c(self, w3d_str_8039f87c);
        break;
    case 1:
        FUN_8013bd0c(self, w3d_str_8039f880);
        break;
    }
}
