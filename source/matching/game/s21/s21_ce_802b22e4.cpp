// desc: Appears to return by value a three-float vector obtained from a virtual slot of the linked object.
struct S21Vec3 {
    float x, y, z;
    S21Vec3(const S21Vec3 &other) { float a = other.x, b = other.y, c = other.z; x = a; y = b; z = c; }
};
struct S21Source;
struct S21SourceMethods { void (*reserved[25])(void); S21Vec3 *(*position)(S21Source *); };
struct S21Source { S21SourceMethods *methods; };
struct S21Object { char pad[88]; S21Source *source; };
extern "C" S21Vec3 w3d_s21_get_position_802b22e4(S21Object *self)
{
    return *self->source->methods->position(self->source);
}
