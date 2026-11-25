#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_80181814.c"
struct K4bMeshInstance;
extern int w3d_mesh_instance_find_clip(Ptr32<struct K4bMeshInstance> self, Ptr32<const char> name, Ptr32<unsigned int> index);
extern int w3d_mesh_instance_fade_index_80181884(Ptr32<struct K4bMeshInstance> self, unsigned int index, float time, float weight);
int w3d_k4b_mesh_instance_fade_named_80181814(Ptr32<struct K4bMeshInstance> self, Ptr32<const char> name, float time, float weight)
{
    /* The original reserves a 20-byte slot; only the first word is the clip index. */
    unsigned int index[5];
    if (w3d_mesh_instance_find_clip(self, name, index) >= 0)
        return w3d_mesh_instance_fade_index_80181884(self, index[0], time, weight);
    return 0x80004005;
}
// desc: w3d_k4b_mesh_instance_fade_named_80181814: Appears to look up a mesh animation clip by name and fade it to a weight over a time, returning E_FAIL when the clip is missing.

}
