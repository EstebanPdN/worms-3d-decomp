// GWMP8P rev0 0x801fb0e8. Sets a device's strength from two byte levels:
// zero for both stops it, otherwise the larger of the scaled first level and
// twice the scaled second level sets a 0 to 15 inverse amount. Partial class
// view; names are inferred.
// Partial view of the device class; only the slot used here is named.
// 255.0f at 0x803b1c0c follows the string "Joypad" in the original module pool,
// read through a data view so the remaining literals keep their addresses.
extern const float kByteScale_803b1c0c[];
struct DevBase {
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
  virtual void stop();
};
struct Dev : DevBase {
  char p[256];
  unsigned amount;
  unsigned flag : 1;
};
extern "C" int w3d_d45e_device_strength_set_801fb0e8(Dev *self, unsigned a, int b) {
  if (a == 0 && b == 0) {
    self->amount = b;
    self->stop();
    return 0;
  }
  unsigned char ca = a, cb = b;
  float k = kByteScale_803b1c0c[0];
  float x = (float)ca / k; float y = (float)cb / k; float w = y + y; float v = x > b ? x : w; if (v > 1.0f) v = 1.0f; unsigned n = (unsigned)((1.0f - v) * 15.0f);
  self->amount = n;
  if (n <= 14) self->flag = 1;
  else self->stop();
  return 0;
}
