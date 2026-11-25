// The temporary vector is copied as floats and compared as the three raw
// 32-bit representations, as witnessed by original stfs/lwz/cmpw instructions.
union cc43b_Component { float value; unsigned int bits; };
struct cc43b_Vector {
    cc43b_Component x,y,z;
    cc43b_Vector(const cc43b_Vector &v) {
        float first=v.x.value, second=v.y.value, third=v.z.value;
        x.value=first; y.value=second; z.value=third;
    }
    inline bool same_bits(const cc43b_Vector &v) const {
        return x.bits==v.x.bits && y.bits==v.y.bits && z.bits==v.z.bits;
    }
};
struct cc43b_PositionOwner { unsigned char unknown00[32]; cc43b_Vector position; };
extern float cc43b_minimum_804668d0[],cc43b_maximum_804668dc[];
inline const float &cc43b_maximum(const float &a,const float &b) { return a<b?b:a; }
inline const float &cc43b_minimum(const float &a,const float &b) { return b<a?b:a; }
extern "C" bool cc43b_clamp_position_802852c4(cc43b_PositionOwner *self) {
    cc43b_Vector previous(self->position);
    self->position.x.value=cc43b_minimum(cc43b_maximum(self->position.x.value,cc43b_minimum_804668d0[0]),cc43b_maximum_804668dc[0]);
    self->position.y.value=cc43b_minimum(cc43b_maximum(self->position.y.value,cc43b_minimum_804668d0[1]),cc43b_maximum_804668dc[1]);
    self->position.z.value=cc43b_minimum(cc43b_maximum(self->position.z.value,cc43b_minimum_804668d0[2]),cc43b_maximum_804668dc[2]);
    return !previous.same_bits(self->position);
}
