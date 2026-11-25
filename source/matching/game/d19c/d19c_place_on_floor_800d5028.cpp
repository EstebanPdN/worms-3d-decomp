// d19c: 0x800d5028 (344 bytes). Place an object from its numbered record
// (sol35b10's vector_floor draft, renamed): the id read from +56 (0x80178c48)
// selects one of 17 records (0x800fc6dc). For an enabled record, take its
// position; when that lies above the floor height (height node +64 minus the
// adjustment node +204, both through 0x80178df0) copy the record's position,
// velocity and auxiliary vectors, otherwise put the object on the floor and
// reset its velocity to the shared default vector. Meanings are inferred.
// Built with -mps-float: the function saves an FPR (the floor height) and the
// unflagged build differed only by the 8-byte frame gap below the register
// save area. The vector's user copy constructor reads all three components
// before writing, as the original copies do.
struct d19c_Vec3 {
    float x, y, z;
    d19c_Vec3(const d19c_Vec3 &a) { float ax = a.x, ay = a.y, az = a.z; x = ax; y = ay; z = az; }
};
struct d19c_PlacementRecord {
    unsigned char unknown00[44];
    d19c_Vec3 velocity;                  // +44
    unsigned char unknown56[12];
    d19c_Vec3 auxiliary;                 // +68
    d19c_Vec3 position;                  // +80
    unsigned char unknown92[128];
    int enabled;                         // +220
};
struct d19c_Placed {
    unsigned char unknown00[56];
    void *id_source;                     // +56
    unsigned char unknown60[4];
    void *height_node;                   // +64
    unsigned char unknown68[72];
    d19c_Vec3 position;                  // +140
    d19c_Vec3 auxiliary;                 // +152
    d19c_Vec3 velocity;                  // +164
    unsigned char unknown176[28];
    void *adjustment_node;               // +204
};
extern "C" unsigned d19c_read_id_80178c48(void *);
extern "C" d19c_PlacementRecord *d19c_placement_record_800fc6dc(unsigned);
extern "C" float d19c_node_height_80178df0(void *);
extern d19c_Vec3 d19c_default_velocity_8045e788;

extern "C" void d19c_place_on_floor_800d5028(d19c_Placed *self) {
    unsigned index = d19c_read_id_80178c48(self->id_source);
    if (index <= 16 && d19c_placement_record_800fc6dc(index)->enabled) {
        d19c_Vec3 position(d19c_placement_record_800fc6dc(index)->position);
        float height = d19c_node_height_80178df0(self->height_node) - d19c_node_height_80178df0(self->adjustment_node);
        if (position.y > height) {
            self->position = position;
            self->velocity = d19c_placement_record_800fc6dc(index)->velocity;
            self->auxiliary = d19c_placement_record_800fc6dc(index)->auxiliary;
        } else {
            self->position = position;
            self->position.y = height;
            self->velocity = d19c_default_velocity_8045e788;
        }
    }
}
