/* cc17d: choice property editors (characters '0'..'n' store 0..n), siblings
   of cx16c 0x8027a248 (integer) and cc17d 0x8027a7fc (boolean).
   Observed: the editor holds the edited object at +92 and a property key at
   +96; the object's vtable slot +20 returns its type, 0x801e9db8 looks the
   key up there and the found descriptor's halfword at +4 is the byte offset
   of the field in the object.  After editing, 0x8027ae00 and 0x8027a98c are
   called with the editor (inferred: refresh and notify). */
typedef struct Cc17dObject { void **methods; } Cc17dObject;
typedef struct Cc17dField { unsigned char reserved[4]; unsigned short offset; } Cc17dField;
typedef struct Cc17dFieldRef { Cc17dField *field; } Cc17dFieldRef;
typedef struct Cc17dEditor {
    unsigned char reserved[92];
    Cc17dObject *receiver;             /* +92 */
    int key;                           /* +96 */
} Cc17dEditor;
extern Cc17dFieldRef *w3d_s21_vector_get_801e9db8(void *, int);
extern void w3d_s21_state_dispatch_8027ae00(Cc17dEditor *);
extern void w3d_auto_8027a98c(Cc17dEditor *);
#define CC17D_TYPE(o) (((void *(*)(Cc17dObject *))(o)->methods[5])(o))
#define CC17D_FIELD(T, o, ref) (*(T *)((char *)(o) + (ref)->field->offset))
void w3d_cc17d_choice6_edit_8027a0cc(Cc17dEditor *self, int ch)
{
    switch (ch) {
    case '0': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 0;
        break;
    }
    case '1': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 1;
        break;
    }
    case '2': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 2;
        break;
    }
    case '3': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 3;
        break;
    }
    case '4': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 4;
        break;
    }
    case '5': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 5;
        break;
    }
    }
    w3d_s21_state_dispatch_8027ae00(self);
    w3d_auto_8027a98c(self);
}
void w3d_cc17d_choice9_edit_8027a348(Cc17dEditor *self, int ch)
{
    switch (ch) {
    case '0': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 0;
        break;
    }
    case '1': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 1;
        break;
    }
    case '2': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 2;
        break;
    }
    case '3': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 3;
        break;
    }
    case '4': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 4;
        break;
    }
    case '5': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 5;
        break;
    }
    case '6': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 6;
        break;
    }
    case '7': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 7;
        break;
    }
    case '8': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 8;
        break;
    }
    }
    w3d_s21_state_dispatch_8027ae00(self);
    w3d_auto_8027a98c(self);
}
void w3d_cc17d_choice6b_edit_8027a568(Cc17dEditor *self, int ch)
{
    switch (ch) {
    case '0': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 0;
        break;
    }
    case '1': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 1;
        break;
    }
    case '2': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 2;
        break;
    }
    case '3': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 3;
        break;
    }
    case '4': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 4;
        break;
    }
    case '5': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 5;
        break;
    }
    }
    w3d_s21_state_dispatch_8027ae00(self);
    w3d_auto_8027a98c(self);
}
void w3d_cc17d_choice4_edit_8027a6e4(Cc17dEditor *self, int ch)
{
    switch (ch) {
    case '0': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 0;
        break;
    }
    case '1': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 1;
        break;
    }
    case '2': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 2;
        break;
    }
    case '3': {
        Cc17dObject *receiver = self->receiver;
        Cc17dFieldRef *ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Cc17dObject **slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 3;
        break;
    }
    }
    w3d_s21_state_dispatch_8027ae00(self);
    w3d_auto_8027a98c(self);
}
