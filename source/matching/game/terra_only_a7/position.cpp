struct Vec {
 float x,y,z;
 Vec() {}
 Vec(float a,float b,float c) : x(a),y(b),z(c) {}
 Vec(const Vec &v) { float a=v.x,b=v.y,c=v.z; x=a; y=b; z=c; }
 Vec operator+(const Vec &v) const { Vec r; const volatile Vec *p=&v; float a=p->x,b=p->y,c=p->z; r.x=x+a; r.y=y+b; r.z=z+c; return r; }
};
struct Item { char pad[80]; Vec pos; };
struct Owner { char pad[32]; void *handle; };
extern "C" void *lookup_803426b4(void *);
extern "C" int index_80178c48(void *);
extern "C" Item *item_800fc6dc(int);
extern "C" float value_8036ca50[], value_8036ca54[];
extern "C" Vec terra_only_a7_position_80026668(Owner *owner) {
 Vec v(item_800fc6dc(index_80178c48(lookup_803426b4(owner->handle)))->pos);
 Vec offset(value_8036ca50[0],value_8036ca54[0],value_8036ca50[0]);
 return v + offset;
}
