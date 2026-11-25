/* Copies the observed three-word default vector into two object fields. */
typedef struct S11VectorWords {int x,y,z;} S11VectorWords;
typedef struct S11VectorOwner {char unknown00[32];S11VectorWords first,second;} S11VectorOwner;
extern S11VectorWords lbl_8045E788[];
void s11_reset_vectors_802bc020(S11VectorOwner *owner) {
    owner->first=lbl_8045E788[0];
    owner->second=lbl_8045E788[0];
}
