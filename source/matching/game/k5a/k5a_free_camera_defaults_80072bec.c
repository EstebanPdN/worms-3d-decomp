typedef struct K5aVec3 { float x, y, z; } K5aVec3;
typedef struct K5aFreeCameraTuning
{
  char pad0[4];
  K5aVec3 up;
  K5aVec3 forward;
  K5aVec3 right;
  char pad2[36];
  float move_speed;
  float rotate_speed;
  float roll_a;
  float roll_b;
} K5aFreeCameraTuning;
extern const float w3d_f32_8037cd6c[];
extern const float w3d_f32_8037cd70[];
extern const float w3d_f32_8037cd74[];
extern const float w3d_f32_8037cd78[];
extern const float w3d_f32_8037cd7c[];
extern char w3d_string_8037cd38[];
extern char w3d_string_8037cd50[];
extern int w3d_auto_800fc270(const char **name, float *value);

inline static void k5a_vec3_set(K5aVec3 *v, float x, float y, float z)
{
  v->x = x;
  v->y = y;
  v->z = z;
}

void k5a_free_camera_defaults_80072bec(K5aFreeCameraTuning *self)
{
  const char *move_name;
  const char *rotate_name;
  float zero = w3d_f32_8037cd6c[0];
  float one = w3d_f32_8037cd70[0];
  float c74 = w3d_f32_8037cd74[0];
  float c78 = w3d_f32_8037cd78[0];
  float c7c = w3d_f32_8037cd7c[0];
  k5a_vec3_set(&self->up, zero, one, c74);
  k5a_vec3_set(&self->forward, zero, one, c78);
  k5a_vec3_set(&self->right, zero, c7c, zero);
  self->roll_a = zero;
  self->roll_b = zero;
  move_name = w3d_string_8037cd38;
  w3d_auto_800fc270(&move_name, &self->move_speed);
  rotate_name = w3d_string_8037cd50;
  w3d_auto_800fc270(&rotate_name, &self->rotate_speed);
}
