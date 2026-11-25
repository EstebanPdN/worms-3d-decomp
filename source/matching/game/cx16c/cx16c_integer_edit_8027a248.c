
typedef struct Cx16cObject Cx16cObject;
typedef struct Cx16cField Cx16cField;
typedef struct Cx16cFieldRef Cx16cFieldRef;
typedef struct Cx16cEditor Cx16cEditor;
struct Cx16cObject
{
  void **methods;
};
struct Cx16cField
{
  unsigned char reserved[4];
  unsigned short offset;
};
struct Cx16cFieldRef
{
  Cx16cField *field;
};
struct Cx16cEditor
{
  unsigned char reserved[92];
  Cx16cObject *receiver;
  int key;
};
extern int cx16c_parse_802ed89c(const char *);
extern Cx16cFieldRef *cx16c_lookup_801e9db8(void *, int);
extern void cx16c_refresh_8027ae00(Cx16cEditor *);
extern void cx16c_notify_8027a98c(Cx16cEditor *);
extern void w3d_cx16c_integer_edit_8027a248(Cx16cEditor *self, const char *text)
{
  Cx16cObject **new_var;
  if (*text)
  {
    int value = cx16c_parse_802ed89c(text);
    Cx16cObject *receiver = self->receiver;
    void *type = ((void *(*)(Cx16cObject *)) receiver->methods[5])(receiver);
    Cx16cFieldRef *ref = cx16c_lookup_801e9db8(type, self->key);
    new_var = &receiver;
    *((int *) (((char *) (*new_var)) + ref->field->offset)) = value;
  }
  cx16c_refresh_8027ae00(self);
  cx16c_notify_8027a98c(self);
}
