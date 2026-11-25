// desc: Appears to handle a message: ids 64 and 66 run dedicated handlers, other ids are forwarded to the owner's embedded context and then to the base handler.
struct S21Message { unsigned short id; };
struct S21Object { char pad[28]; char context[4]; };
extern int fn_8015fb34(struct S21Object *, struct S21Message *);
extern void fn_802707f0(struct S21Object *);
extern int fn_80270bdc(struct S21Object *);
extern int fn_802b264c(void *);
extern void fn_802aff9c(void *, struct S21Message *);
int w3d_s21_handle_message_80270710(struct S21Object *self, struct S21Message *message)
{
    switch (message->id) {
    case 64:
        if (fn_8015fb34(self, message) < 0)
            return 0x80004005;
        fn_802707f0(self);
        return 0;
    case 66:
        fn_80270bdc(self);
        break;
    default:
        if (fn_802b264c(self->context))
            fn_802aff9c(self->context, message);
        break;
    }
    return fn_8015fb34(self, message);
}
