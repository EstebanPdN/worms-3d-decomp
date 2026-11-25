/* Effect trigger, error-code check and global object initializer. */
extern short fn_800fc2b0(char **, unsigned char **);
extern void * fn_800fd4c8(int, int);
extern int fn_800fd504(unsigned char *, int, int);
extern char lbl_8038a62c[];
void w3d_s20_trigger_effect_800e64e8(void)
{
  char *key;
  unsigned char *flag;
  flag = 0;
  key = lbl_8038a62c;
  fn_800fc2b0(&key, &flag);
  fn_800fd4c8(6, 1);
  if ((flag != 0) && ((*flag) != 0))
  {
    fn_800fd504(flag, 6, 1);
  }
}

extern int fn_8016b488(char *, void *);
int w3d_s20_check_then_count_8016b6d8(char *self, char *item) {
    int result;
    unsigned int count;
    unsigned int i;
    result = fn_8016b488(self, (void *)item);
    if (result != 0)
        return result;
    count = *(unsigned int *)(item + 84);
    for (i = 0; i < count; i++) {
    }
    return 0;
}

extern char lbl_80455984[];
extern char lbl_80455980[];
extern char lbl_803a64ac[];
extern char lbl_8040ef68[];
extern void fn_80200a70(char *);
int w3d_s20_init_global_object_8016f574(void) {
    *(char **)lbl_80455984 = lbl_803a64ac;
    *(int *)(lbl_80455984 + 4) = 1;
    *(char **)(lbl_80455984 + 16) = lbl_8040ef68;
    *(char **)(lbl_80455984 + 24) = lbl_80455980;
    *(int *)(lbl_80455984 + 12) = 0;
    *(int *)(lbl_80455984 + 36) = 0;
    fn_80200a70(lbl_80455984);
    return 0;
}
