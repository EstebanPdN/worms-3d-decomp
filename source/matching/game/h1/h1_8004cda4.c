/* Team handle application (session 47b5d14a; hand-written, register order
 * found with decomp-permuter). The local owned reference {0, 0xe3a8} is
 * destroyed with flags 2 at scope exit, as a C++ local object would be. */


typedef struct W3dOwnedRef_8004cda4
{
  int object;
  int type;
} W3dOwnedRef_8004cda4;
typedef struct W3dTeam_8004cda4
{
  unsigned char unknown_00[60];
  unsigned char index;
} W3dTeam_8004cda4;
typedef struct W3dSlot_8004cda4
{
  unsigned char unknown_00[36];
  int key;
  unsigned char unknown_28[28];
  union 
  {
    int word;
    unsigned char bytes[4];
  } state;
} W3dSlot_8004cda4;
W3dTeam_8004cda4 *s8_index_query_800fc7f8(int index);
int s8_handle_800fcdb8(int index, W3dOwnedRef_8004cda4 *ref);
int fn_8025cbe0(void *handle, int key);
int fn_8025d020(void *handle, int key, int value);
int w3d_s20_destroy_owned_80178474(W3dOwnedRef_8004cda4 *ref, int flags);
void w3d_h1_apply_team_handle_8004cda4(W3dSlot_8004cda4 *self, int team)
{
    W3dOwnedRef_8004cda4 *ref_ptr;
    int value;
    W3dOwnedRef_8004cda4 ref;
    int handle;
    int found;
    ref_ptr = &ref;
    ref.object = 0;
    ref.type = 0xe3a8;
    handle = s8_handle_800fcdb8(s8_index_query_800fc7f8(team)->index, ref_ptr);
    found = fn_8025cbe0(handle, self->key);
    if (found != -1) {
        value = found + self->state.bytes[3];
        fn_8025d020(handle, self->key, (signed char)value);
    }
    self->state.word = 0;
    w3d_s20_destroy_owned_80178474(&ref, 2);
}
