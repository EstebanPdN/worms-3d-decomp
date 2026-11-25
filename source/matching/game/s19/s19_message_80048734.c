
struct S19Message
{
  unsigned short id;
};
struct S19Cache
{
  int words[2];
};
struct S19Engine
{
  char pad0[52];
  int tick;
};
extern struct S19Cache lbl_804ad2e8;
extern struct S19Cache lbl_804ad310;
extern struct S19Cache lbl_804ad2f0;
extern struct S19Cache lbl_804ad318;
extern int w3d_auto_8015fb34(void *, struct S19Message *);
extern int w3d_message_id_equals_cache(int, struct S19Cache *);
extern struct S19Engine *w3d_engine_get_context(void);
extern void FUN_80048a90(void *);
extern void w3d_fn_80048ec4(void *);
extern void w3d_fn_80048f1c(void *);
extern void w3d_auto_80048fac(void *);
extern void FUN_80048840(void *, int);
int s19_handle_message_80048734(void *self, struct S19Message *msg)
{
  switch (msg->id)
  {
    case 64:
      if (w3d_auto_8015fb34(self, msg) >= 0)
    {
      FUN_80048a90(self);
      return 0;
    }
      return 0x80004005;

    case 66:
      w3d_fn_80048ec4(self);
      break;

    default:
      if (w3d_message_id_equals_cache(msg->id, &lbl_804ad2e8) || w3d_message_id_equals_cache(msg->id, &lbl_804ad310))
    {
      w3d_fn_80048f1c(self);
    }
    else
      if (w3d_message_id_equals_cache(msg->id, &lbl_804ad2f0))
    {
      w3d_auto_80048fac(self);
    }
    else
      if (w3d_message_id_equals_cache(msg->id, &lbl_804ad318))
    {
 do { FUN_80048840(self, w3d_engine_get_context()->tick); } while (0);
    }
      break;

  }

  return w3d_auto_8015fb34(self, msg);
}
