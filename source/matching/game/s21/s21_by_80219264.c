// desc: Appears to close a handle held at offset 24 when it is not negative, reset it to minus one and return 0x80004005 if closing failed, else zero.
struct S21Object { char pad[24]; int handle; };
extern int fn_802e4cec(int);
int w3d_s21_close_handle_80219264(struct S21Object *self)
{
    if (self->handle >= 0) {
        int result = fn_802e4cec(self->handle);
        self->handle = -1;
        if (result < 0)
            return 0x80004005;
    }
    return 0;
}
