#if 0 /* Unmatched floating-point scheduling and conversion. */
/* Scan sphere records for the next ray intersection. */
extern "C" {
struct W3dS1Vec { float x,y,z; };
struct W3dS1Sphere { W3dS1Vec position; float radius; int field10; unsigned int mask; int owner; int field1c; };
struct W3dS1Spheres { W3dS1Sphere *begin,*end; };
extern W3dS1Spheres w3d_spheres_804273ec[];
extern W3dS1Vec w3d_origin_80427408[], w3d_direction_80427414[], w3d_delta_80427444[];
extern unsigned short w3d_exclude_804aa950, w3d_cursor_804aa95c, w3d_hit_804aa95e;
extern unsigned int w3d_mask_804aa954;
extern int w3d_owner_804aa960, w3d_beyond_804aa964, w3d_distance_804b1790, w3d_limit_804b17bc;
extern float w3d_hit_distance_804b17a4, w3d_radius_804b17b8, w3d_speed2_804b17c0, w3d_delta2_804b17d0;
float w3d_sqrt_802e82c0(float value);
unsigned short w3d_fn_800400f0(void)
{
    struct { short unknown[11]; } frame_slot;
    if (w3d_cursor_804aa95c < (unsigned int)(w3d_spheres_804273ec[0].end - w3d_spheres_804273ec[0].begin)) {
      do {
        if (w3d_cursor_804aa95c != w3d_exclude_804aa950) {
            W3dS1Sphere *sphere = w3d_spheres_804273ec[0].begin + w3d_cursor_804aa95c;
            if ((sphere->mask & w3d_mask_804aa954) && sphere->owner != w3d_owner_804aa960) {
                w3d_delta_80427444[0].x = w3d_origin_80427408[0].x - sphere->position.x;
                w3d_delta_80427444[0].y = w3d_origin_80427408[0].y - sphere->position.y;
                w3d_delta_80427444[0].z = w3d_origin_80427408[0].z - sphere->position.z;
                float x=w3d_delta_80427444[0].x, y=w3d_delta_80427444[0].y, z=w3d_delta_80427444[0].z;
                w3d_delta2_804b17d0 = z*z + (x*x + y*y);
                float dot = z*w3d_direction_80427414[0].z + (x*w3d_direction_80427414[0].x+y*w3d_direction_80427414[0].y);
                float b = dot+dot;
                float radius = sphere->radius + w3d_radius_804b17b8;
                float discriminant = b*b - (w3d_speed2_804b17c0*4.0f)*(w3d_delta2_804b17d0-radius*radius);
                if (discriminant >= 0.0f) {
                    float root = w3d_sqrt_802e82c0(discriminant);
                    float first = -b-root;
                    float distance = -1.0f;
                    if (first > 0.0f) distance = first/(w3d_speed2_804b17c0+w3d_speed2_804b17c0);
                    else if (root-b > 0.0f) distance=0.0f;
                    if (distance >= 0.0f && distance < (float)w3d_limit_804b17bc) {
                        float last=(-b+root)/(w3d_speed2_804b17c0+w3d_speed2_804b17c0);
                        w3d_hit_distance_804b17a4=distance;
                        unsigned short cursor=w3d_cursor_804aa95c++;
                        w3d_hit_804aa95e=cursor;
                        w3d_beyond_804aa964=last>(float)w3d_limit_804b17bc;
                        w3d_distance_804b1790=(int)distance;
                        return cursor;
                    }
                }
            }
        }
        ++w3d_cursor_804aa95c;
      } while (w3d_cursor_804aa95c < (unsigned int)(w3d_spheres_804273ec[0].end-w3d_spheres_804273ec[0].begin));
    }
    return 65535;
}
}

#endif
