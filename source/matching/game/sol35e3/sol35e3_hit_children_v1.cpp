// Inferred GC32 views from 0x802bc7c0; complete class identities are unknown.
struct Sol35e3Vector {
    float x, y, z;
    Sol35e3Vector(const Sol35e3Vector& v) : x(v.x), y(v.y), z(v.z) {}
};
struct Sol35e3Matrix {
    float rotation[9];
    Sol35e3Vector position;
    Sol35e3Vector translation() const { return position; }
};
struct Sol35e3Transform;
struct Sol35e3TransformTable {
    void (*other[31])();
    void (*matrix)(Sol35e3Transform*, Sol35e3Matrix*);
};
struct Sol35e3Transform { Sol35e3TransformTable* table; };
struct Sol35e3Child;
struct Sol35e3Children { Sol35e3Child** begin; Sol35e3Child** end; };
struct Sol35e3HitOwner {
    unsigned char unknown00[56];
    Sol35e3Children children;
    unsigned char unknown40[24];
    Sol35e3Transform* transform;
};
extern "C" int sol35e3_child_id_802bd2bc(Sol35e3Child*);
extern "C" int sol35e3_child_hit_802bfa70(Sol35e3Child*, int*, float, float);
extern "C" int sol35e3_hit_children_802bc7c0(Sol35e3HitOwner* self, int* index, int* id, float x, float y) {
    Sol35e3Child** child = self->children.begin;
    Sol35e3Children& children = self->children;
    *index = 0;
    *id = 0;
    Sol35e3Matrix matrix;
    self->transform->table->matrix(self->transform, &matrix);
    Sol35e3Vector origin = matrix.translation();
    x -= origin.x;
    y -= origin.y;
    for (; child != children.end; ++child) {
        if (sol35e3_child_id_802bd2bc(*child) != -1 &&
            sol35e3_child_hit_802bfa70(*child, index, x, y) == 1) {
            *id = sol35e3_child_id_802bd2bc(*child);
            return 1;
        }
    }
    return 0;
}
