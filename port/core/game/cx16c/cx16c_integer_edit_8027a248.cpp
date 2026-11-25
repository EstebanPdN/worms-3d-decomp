#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "cx16c_integer_edit_8027a248.c"

typedef struct Cx16cObject Cx16cObject;
typedef struct Cx16cField Cx16cField;
typedef struct Cx16cFieldRef Cx16cFieldRef;
typedef struct Cx16cEditor Cx16cEditor;
struct Cx16cObject
{
  Ptr32<Ptr32<void>> methods;
};
struct Cx16cField
{
  unsigned char reserved[4];
  unsigned short offset;
};
struct Cx16cFieldRef
{
  Ptr32<Cx16cField> field;
};
struct Cx16cEditor
{
  unsigned char reserved[92];
  Ptr32<Cx16cObject> receiver;
  int key;
};
extern int cx16c_parse_802ed89c(Ptr32<const char>);
extern Ptr32<Cx16cFieldRef> cx16c_lookup_801e9db8(Ptr32<void>, int);
extern void cx16c_refresh_8027ae00(Ptr32<Cx16cEditor>);
extern void cx16c_notify_8027a98c(Ptr32<Cx16cEditor>);
extern void w3d_cx16c_integer_edit_8027a248(Ptr32<Cx16cEditor> self, Ptr32<const char> text)
{
  Ptr32<Ptr32<Cx16cObject>> new_var;
  if (*text)
  {
    int value = cx16c_parse_802ed89c(text);
    Ptr32<Cx16cObject> receiver = self->receiver;
    Ptr32<void> type = ((Ptr32<Ptr32<void> (Ptr32<Cx16cObject>)>) receiver->methods[5])(receiver);
    Ptr32<Cx16cFieldRef> ref = cx16c_lookup_801e9db8(type, self->key);
    new_var = &receiver;
    *((Ptr32<int>) (((Ptr32<char>) (*new_var)) + ref->field->offset)) = value;
  }
  cx16c_refresh_8027ae00(self);
  cx16c_notify_8027a98c(self);
}

}
