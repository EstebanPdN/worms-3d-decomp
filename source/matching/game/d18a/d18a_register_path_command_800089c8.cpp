/* Path command registration (0x800089c8). Appends the command to the global
 * command storage at 0x804aa564 (growing it by half through 0x80212fd4 /
 * 0x802eee50 / 0x802134fc when full; the stored value is the base-class
 * pointer) and registers it with 0x8002274c on the registry 0x804aa5a4.
 * When the path jitter setting (+140 of 0x804aa6d8) is not 0.0f, every
 * waypoint after the first whose type is 3, 4 or 5 is moved to
 * previous + randomized(waypoint - previous) through 0x80015910. Finally
 * the last waypoint position is published at 0x8041d3a0, the flag
 * 0x804aa58c is set and the world map 0x804b1758 is refreshed through
 * 0x8001f2cc. The type test is a switch (case range 3..5 compares > 5 then
 * < 3). The vector keeps a member-wise float copy constructor and the
 * default word-copy assignment. Names are inferred; offsets are observed.
 * Built with -mps-float (frame keeps 8 bytes below the save area for the
 * saved FPR). */
extern "C" unsigned char *d18a_allocate_80212fd4(unsigned);
extern "C" void d18a_release_802134fc(void *);
extern "C" void *d18a_copy_802eee50(void *, const void *, ...);
inline const int &larger(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &smaller(const unsigned &a, const unsigned &b) { return b < a ? b : a; }

struct D18aVec3 {
    float x, y, z;
    D18aVec3() {}
    D18aVec3(const D18aVec3 &v) : x(v.x), y(v.y), z(v.z) {}
};
inline D18aVec3 operator-(const D18aVec3 &a, const D18aVec3 &b) { D18aVec3 r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline D18aVec3 operator+(const D18aVec3 &a, const D18aVec3 &b) { D18aVec3 r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }

struct D18aWaypoint { int type; D18aVec3 position; };
struct D18aWaypointList {
    D18aWaypoint **begin, **end;
    int size() const { return end - begin; }
    D18aWaypoint *&operator[](int i) { return begin[i]; }
    D18aWaypoint *&back() { return end[-1]; }
};
struct D18aCommandBase { unsigned char unknown00[20]; };
struct D18aPathCommand : D18aCommandBase { D18aWaypointList points; };

struct D18aCommandStorage {
    unsigned char *begin, *end, *capacity;
    void push(D18aCommandBase *const &value)
    {
        if (end == capacity) {
            unsigned used = end - begin;
            int next = used + 1;
            int grown = used + (used >> 1);
            unsigned allocated = larger(next, grown) * 4;
            unsigned char *fresh = d18a_allocate_80212fd4(allocated);
            if (begin) {
                d18a_copy_802eee50(fresh, begin, smaller(allocated, used));
                d18a_release_802134fc(begin);
            }
            begin = fresh;
            end = fresh + used;
            capacity = fresh + allocated;
        }
        *(D18aCommandBase **)end = value;
        end += 4;
    }
};
struct D18aSettings { unsigned char unknown00[140]; float path_jitter; };

extern D18aCommandStorage *d18a_commands_804aa564;
extern void *d18a_registry_804aa5a4;
extern D18aSettings *d18a_settings_804aa6d8;
extern D18aVec3 d18a_path_end_8041d3a0;
extern int d18a_path_end_set_804aa58c;
extern void *d18a_world_map_804b1758;
extern "C" void d18a_register_8002274c(void *, D18aCommandBase *);
extern "C" void d18a_randomize_80015910(D18aVec3 *v, float amount);
extern "C" void d18a_world_map_refresh_8001f2cc(void *map);

extern "C" void w3d_d18a_register_path_command_800089c8(D18aPathCommand *command)
{
    d18a_commands_804aa564->push(command);
    d18a_register_8002274c(d18a_registry_804aa5a4, command);
    D18aWaypointList &points = command->points;
    D18aVec3 &last = points.back()->position;
    float jitter = d18a_settings_804aa6d8->path_jitter;
    if (jitter != 0.0f) {
        for (int i = 1; i < points.size(); ++i) {
            D18aWaypoint *point = points[i];
            switch (point->type) {
            case 3:
            case 4:
            case 5: {
                D18aWaypoint *previous = points[i - 1];
                D18aVec3 delta = point->position - previous->position;
                d18a_randomize_80015910(&delta, jitter);
                point->position = previous->position + delta;
                break;
            }
            }
        }
    }
    d18a_path_end_set_804aa58c = 1;
    d18a_path_end_8041d3a0 = last;
    d18a_world_map_refresh_8001f2cc(d18a_world_map_804b1758);
}
