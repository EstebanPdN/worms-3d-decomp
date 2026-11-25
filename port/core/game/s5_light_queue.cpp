#include "w3d_ptr.h"
#line 1 "s5_light_queue.cpp"
/* Lighting update queue; field names describe observed offsets. */
extern "C" {
struct W3dS5Light { unsigned char reserved[28]; unsigned char active; unsigned char tail[31]; };
struct W3dS5LightRange { Ptr32<W3dS5Light> begin; Ptr32<W3dS5Light> end; };
struct W3dS5IndexRange { Ptr32<unsigned short> begin; Ptr32<unsigned short> end; };
extern W3dS5LightRange w3d_light_range_8043c384[];
extern W3dS5IndexRange w3d_light_queue_8043c3a0[];
extern unsigned short w3d_light_cursor_804b185c;
void w3d_light_refresh_800c021c(Ptr32<W3dS5Light> light);
int w3d_light_process_queue_800c0118(void)
{
    int queued = w3d_light_queue_8043c3a0->end - w3d_light_queue_8043c3a0->begin;
    if (queued) {
        do {
            unsigned offset = ((unsigned)(w3d_light_queue_8043c3a0->end - w3d_light_queue_8043c3a0->begin) - 1) * sizeof(unsigned short);
            unsigned short index = *(Ptr32<unsigned short>)w3d::G(((unsigned)w3d::H(w3d_light_queue_8043c3a0->begin) + offset));
            --w3d_light_queue_8043c3a0->end;
            Ptr32<W3dS5Light> light = w3d_light_range_8043c384->begin + index;
            if (light->active) w3d_light_refresh_800c021c(light);
        } while ((unsigned)(w3d_light_queue_8043c3a0->end - w3d_light_queue_8043c3a0->begin));
    } else {
        unsigned count = w3d_light_range_8043c384->end - w3d_light_range_8043c384->begin;
        if (count) {
            if (++w3d_light_cursor_804b185c >= count) w3d_light_cursor_804b185c = queued;
            Ptr32<W3dS5Light> light = w3d_light_range_8043c384->begin + w3d_light_cursor_804b185c;
            if (light->active) w3d_light_refresh_800c021c(light);
        }
    }
    return 0;
}
}


