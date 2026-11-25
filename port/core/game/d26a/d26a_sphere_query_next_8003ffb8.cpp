#include "w3d_ptr.h"
#line 1 "d26a_sphere_query_next_8003ffb8.cpp"
// GWMP8P rev0 0x8003ffb8. Next item of a sphere query: walks the 32-byte
// item vector from a global cursor. Names are inferred from the original
// instructions.
struct Vec { float x, y, z; };
struct Item {
    float x, y, z, radius;
    int unknown10;
    unsigned mask;     /* +20 */
    int owner;         /* +24 */
    int unknown1c;
};
struct Items {
    Ptr32<Item> first; Ptr32<Item> last;
    unsigned size() const { return last - first; }
    Item &operator[](unsigned i) { return first[i]; }
};
extern Items g_items_804273ec[];
extern Vec g_center_80427408[];
extern Vec g_delta_80427444[];
extern Vec g_hit_80427450[];
extern unsigned short g_ignore_804aa950;
extern unsigned g_mask_804aa954;
extern unsigned short g_cursor_804aa95c, g_current_804aa95e;
extern int g_owner_804aa960;
extern float g_radius_804b17b8, g_dist_804b17d0;

extern "C" int w3d_d26a_sphere_query_next_8003ffb8()
{
    while (g_cursor_804aa95c < g_items_804273ec[0].size()) {
        unsigned c = g_cursor_804aa95c;
        unsigned short i = c;
        if (i != g_ignore_804aa950) {
            Item &it = g_items_804273ec[0][i];
            if ((it.mask & g_mask_804aa954) && it.owner != g_owner_804aa960) {
                Vec &d = g_delta_80427444[0];
                d.x = it.x - g_center_80427408[0].x;
                d.y = it.y - g_center_80427408[0].y;
                d.z = it.z - g_center_80427408[0].z;
                g_dist_804b17d0 = d.x * d.x + d.y * d.y + d.z * d.z;
                float r = g_radius_804b17b8 + it.radius;
                if (g_dist_804b17d0 < r * r) {
                    g_hit_80427450[0] = g_delta_80427444[0];
                    g_cursor_804aa95c = c + 1;
                    g_current_804aa95e = c;
                    return i;
                }
            }
        }
        ++g_cursor_804aa95c;
    }
    return 0xffff;
}


