#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "cc17d_prop_edit_8027a2c4.c"
/* cc17d: property editor setters, siblings of cx16c 0x8027a248 (integer).
   Observed: the editor holds the edited object at +92 and a property key at
   +96; the object's vtable slot +20 returns its type, 0x801e9db8 looks the
   key up there and the found descriptor's halfword at +4 is the byte offset
   of the field in the object.  After editing, 0x8027ae00 and 0x8027a98c are
   called with the editor (inferred: refresh and notify). */
typedef struct Cc17dObject { Ptr32<Ptr32<void>> methods; } Cc17dObject;
typedef struct Cc17dField { unsigned char reserved[4]; unsigned short offset; } Cc17dField;
typedef struct Cc17dFieldRef { Ptr32<Cc17dField> field; } Cc17dFieldRef;
typedef struct Cc17dEditor {
    unsigned char reserved[92];
    Ptr32<Cc17dObject> receiver;             /* +92 */
    int key;                           /* +96 */
} Cc17dEditor;
extern double atof(Ptr32<const char>);
extern Ptr32<Cc17dFieldRef> w3d_s21_vector_get_801e9db8(Ptr32<void>, int);
extern void w3d_s21_state_dispatch_8027ae00(Ptr32<Cc17dEditor>);
extern void w3d_auto_8027a98c(Ptr32<Cc17dEditor>);
#define CC17D_TYPE(o) (((void *(*)(Cc17dObject *))(o)->methods[5])(o))
#define CC17D_FIELD(T, o, ref) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(o) + (ref)->field->offset))
void w3d_cc17d_float_edit_8027a2c4(Ptr32<Cc17dEditor> self, Ptr32<const char> text)
{
    if (*text) {
        float value = atof(text);
        Ptr32<Cc17dObject> receiver = self->receiver;
        Ptr32<Cc17dFieldRef> ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Ptr32<Ptr32<Cc17dObject>> slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(float, *slot, ref) = value;
    }
    w3d_s21_state_dispatch_8027ae00(self);
    w3d_auto_8027a98c(self);
}
void w3d_cc17d_bool_edit_8027a7fc(Ptr32<Cc17dEditor> self, int ch)
{
    switch (ch) {
    case '0': {
        Ptr32<Cc17dObject> receiver = self->receiver;
        Ptr32<Cc17dFieldRef> ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Ptr32<Ptr32<Cc17dObject>> slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 0;
        break;
    }
    case '1': {
        Ptr32<Cc17dObject> receiver = self->receiver;
        Ptr32<Cc17dFieldRef> ref = w3d_s21_vector_get_801e9db8(CC17D_TYPE(receiver), self->key);
        Ptr32<Ptr32<Cc17dObject>> slot = &receiver; /* address-taken receiver: original register choice */
        CC17D_FIELD(int, *slot, ref) = 1;
        break;
    }
    }
    w3d_s21_state_dispatch_8027ae00(self);
    w3d_auto_8027a98c(self);
}

}
