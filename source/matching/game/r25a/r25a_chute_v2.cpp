// Observed stack string is one PPC32 word; ownership services remain external.
struct SharedString_8020bb54 { void *value; SharedString_8020bb54(const char *); };
typedef SharedString_8020bb54 SharedString;
struct ChuteObject { unsigned char unknown[20]; int target; unsigned char gap[8]; int handle; };
struct Message;
extern "C" {
void fn_8020bb54(SharedString *, const char *);
void fn_8020c5c4(SharedString *);
void fn_80341588(SharedString *);
void fn_8015adf4(SharedString *, int *, int);
int fn_8015f5a0(void *, int);
Message *fn_801613f0(void *, unsigned int);
Message *fn_801190b4(Message *, unsigned short, int);
void fn_8016239c(Message *);
extern char lbl_8038975c[];
extern unsigned int lbl_804aeb8c;
extern void *lbl_804b1754;
}
// Field +32 receives the Worm.Chute handle; target +20 is sent in a 12-byte message.
extern "C" void w3d_r25a_initialize_chute_message_800da3fc(ChuteObject *self) {
    SharedString text(lbl_8038975c);
    fn_8015adf4(&text, &self->handle, 255);
    fn_8020c5c4(&text);
    fn_80341588(&text);
    Message *message = fn_801613f0(lbl_804b1754, 12);
    fn_8016239c(fn_801190b4(message, (unsigned short)fn_8015f5a0(&lbl_804aeb8c, 1), self->target));
}
