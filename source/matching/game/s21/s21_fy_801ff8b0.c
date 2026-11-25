// desc: Appears to call virtual slot 21 of the stream object a given number of times with a shared context, stopping at the first negative status and returning zero otherwise.
struct S21Stream;
struct S21StreamMethods { void (*reserved[21])(void); int (*step)(struct S21Stream *, int, int, int); };
struct S21Stream { struct S21StreamMethods *methods; };
int w3d_s21_repeat_step_801ff8b0(int unused, struct S21Stream *stream, int unused2, int context, unsigned count)
{
    unsigned i = 0;
    if (i < count) {
        do {
            int status = stream->methods->step(stream, 0, context, 0);
            if (status < 0)
                return status;
            i++;
        } while (i < count);
    }
    return 0;
}
