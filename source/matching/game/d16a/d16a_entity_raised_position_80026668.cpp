/* Returns an entity's position raised by 8 units on the y axis. The caller's
 * object keeps an entity handle at +32; it is viewed through 0x803426b4,
 * resolved to an entity index by 0x80178c48 and to the entity record by
 * 0x800fc6dc, whose position vector sits at +80 (observed offsets). The
 * offset (0, 8, 0) uses the literals pooled at 0x8036ca50 (0.0f) and
 * 0x8036ca54 (8.0f). Names are inferred. */

struct D16aVec3 {
    float x, y, z;
    D16aVec3() {}
    D16aVec3(const D16aVec3 &v) { float a = v.x, b = v.y, c = v.z; x = a; y = b; z = c; }
    D16aVec3 &operator=(const D16aVec3 &v)
    {
        float a = v.x, b = v.y, c = v.z;
        x = a; y = b; z = c;
        return *this;
    }
    D16aVec3 operator+(const D16aVec3 &v) const
    {
        D16aVec3 r;
        r.x = x + v.x; r.y = y + v.y; r.z = z + v.z;
        return r;
    }
};

struct D16aEntityRecord { unsigned char unknown00[80]; D16aVec3 position; };
struct D16aHandleOwner { unsigned char unknown00[32]; void *entity; };

extern "C" void *d16a_view_entity_803426b4(void *handle);
extern "C" int d16a_entity_index_80178c48(void *entity);
extern "C" D16aEntityRecord *d16a_entity_record_800fc6dc(int index);

extern "C" D16aVec3 w3d_d16a_entity_raised_position_80026668(D16aHandleOwner *owner)
{
    D16aEntityRecord *record = d16a_entity_record_800fc6dc(
        d16a_entity_index_80178c48(d16a_view_entity_803426b4(owner->entity)));
    D16aVec3 position;
    D16aVec3 *p = &position;
    *p = record->position;
    D16aVec3 offset;
    D16aVec3 *o = &offset;
    o->x = 0.0f;
    o->y = 8.0f;
    o->z = 0.0f;
    return position + offset;
}

typedef char d16a_vec3_size[sizeof(D16aVec3) == 12 ? 1 : -1];
typedef char d16a_record_position[sizeof(D16aEntityRecord) == 92 ? 1 : -1];
