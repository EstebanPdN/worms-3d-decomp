// Inferred reference ABI constructor; original field meanings are provisional.
struct SharedString;
extern "C" void sol35e6a_string_init_8020c5c0(SharedString *);
extern "C" unsigned short *sol35e6a_string_header_80341884(SharedString *);
struct SharedString {
 char *text;
 SharedString(const SharedString &other) {
  sol35e6a_string_init_8020c5c0(this);
  text = other.text;
  ++*sol35e6a_string_header_80341884(this);
 }
};
struct Vec3 { float x,y,z; Vec3(float v):x(v),y(v),z(v) {} };
inline void *operator new(unsigned, void *p) { return p; }
extern SharedString sol35e6a_empty_804b06a0[];
extern const unsigned char sol35e6a_table_8041b9c8[];
extern const float sol35e6a_default_803c8d98[];
extern "C" void *sol35e6a_base_80251f40(void *);
extern "C" void *sol35e6a_particle_construct_8025693c(void *object) {
 char *self = static_cast<char *>(object);
 sol35e6a_base_80251f40(object);
 *reinterpret_cast<const unsigned char **>(self) = sol35e6a_table_8041b9c8;
 float v = sol35e6a_default_803c8d98[0];
 new (self+164) Vec3(v);
 new (self+176) Vec3(v);
 *reinterpret_cast<float *>(self+188) = v;
 *reinterpret_cast<float *>(self+192) = v;
 *reinterpret_cast<float *>(self+196) = v;
 *reinterpret_cast<float *>(self+200) = v;
 *reinterpret_cast<float *>(self+204) = v;
 *reinterpret_cast<float *>(self+208) = v;
 *reinterpret_cast<float *>(self+212) = v;
 new (self+216) SharedString(sol35e6a_empty_804b06a0[0]);
 new (self+220) SharedString(sol35e6a_empty_804b06a0[0]);
 new (self+224) SharedString(sol35e6a_empty_804b06a0[0]);
 new (self+228) SharedString(sol35e6a_empty_804b06a0[0]);
 *reinterpret_cast<float *>(self+232) = v;
 *reinterpret_cast<float *>(self+236) = v;
 *reinterpret_cast<float *>(self+240) = v;
 *reinterpret_cast<unsigned *>(self+244) = 0;
 *reinterpret_cast<unsigned *>(self+248) = 0;
 *reinterpret_cast<unsigned *>(self+252) = 0;
 *reinterpret_cast<unsigned *>(self+256) = 0;
 return object;
}
typedef char StringSize[sizeof(SharedString)==4?1:-1];
typedef char VectorSize[sizeof(Vec3)==12?1:-1];
