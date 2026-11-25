// (Worms 3D GameCube PAL, 0x801d6ca8).
//
// General filtered image rescaling, the two-pass zoom of Schumacher's filter
// code from Graphics Gems III: builds contributor lists for the horizontal
// pass into a temporary image, filters each column, then does the same
// vertically into the destination. Below unit scale the filter is stretched
// by the inverse scale; out-of-range indices reflect at the edges. Weights
// and sums are floats and results clamp to 0..255.

typedef unsigned char Pixel;
struct Image { int xsize, ysize; Pixel *data; int span; };
struct Contrib { int pixel; float weight; };
struct CList { int n; Contrib *p; };
extern CList *contrib_804b0550;
extern "C" Image *w3d_auto_801d67e4(int, ...);
extern "C" void w3d_auto_801d6850(Image *, ...);
extern "C" void *g3c_allocate_80213c30(int, int);
extern "C" void w3d_handle_storage_release_802134fc(void *);
extern "C" float w3d_cx9c_ceilf_802e85fc(float);
extern "C" float w3d_cx9c_floorf_802e87d4(float);
extern "C" void read_column_801d6888(Pixel *, Image *, int);
extern "C" void read_row_801d68e0(Pixel *, Image *, int);
extern "C" int write_pixel_801d6940(Image *, int, int, unsigned char);
extern "C" void w3d_d27e_zoom_image_801d6ca8(Image *dst, Image *src, float (*filterf)(float), float fwidth) {
    Image *tmp;
    float xscale, yscale;
    float width, fscale, weight, center, left, right;
    int i, j, k, n;
    Pixel *raster;
    tmp = w3d_auto_801d67e4(dst->xsize, src->ysize);
    xscale = (float)dst->xsize / (float)src->xsize;
    yscale = (float)dst->ysize / (float)src->ysize;
    contrib_804b0550 = (CList *)g3c_allocate_80213c30(dst->xsize, sizeof(CList));
    if (xscale < 1.0f) {
        width = fwidth / xscale;
        fscale = 1.0f / xscale;
        for (i = 0; i < dst->xsize; ++i) {
            contrib_804b0550[i].n = 0;
            contrib_804b0550[i].p = (Contrib *)g3c_allocate_80213c30((int)(width * 2 + 1.0f), sizeof(Contrib));
            center = (float)i / xscale;
            left = w3d_cx9c_ceilf_802e85fc(center - width);
            right = w3d_cx9c_floorf_802e87d4(center + width);
            for (j = (int)left; (float)j <= right; ++j) {
                weight = center - (float)j;
                weight = (*filterf)(weight / fscale) / fscale;
                if (j < 0) n = -j;
                else if (j >= src->xsize) n = (src->xsize - j) + src->xsize - 1;
                else n = j;
                k = contrib_804b0550[i].n++;
                contrib_804b0550[i].p[k].pixel = n;
                contrib_804b0550[i].p[k].weight = weight;
            }
        }
    } else {
        for (i = 0; i < dst->xsize; ++i) {
            contrib_804b0550[i].n = 0;
            contrib_804b0550[i].p = (Contrib *)g3c_allocate_80213c30((int)(fwidth * 2 + 1.0f), sizeof(Contrib));
            center = (float)i / xscale;
            left = w3d_cx9c_ceilf_802e85fc(center - fwidth);
            right = w3d_cx9c_floorf_802e87d4(center + fwidth);
            for (j = (int)left; (float)j <= right; ++j) {
                weight = center - (float)j;
                weight = (*filterf)(weight);
                if (j < 0) n = -j;
                else if (j >= src->xsize) n = (src->xsize - j) + src->xsize - 1;
                else n = j;
                k = contrib_804b0550[i].n++;
                contrib_804b0550[i].p[k].pixel = n;
                contrib_804b0550[i].p[k].weight = weight;
            }
        }
    }
    raster = (Pixel *)g3c_allocate_80213c30(src->xsize, sizeof(Pixel));
    for (k = 0; k < tmp->ysize; ++k) {
        read_column_801d6888(raster, src, k);
        for (i = 0; i < tmp->xsize; ++i) {
            weight = 0.0f;
            for (j = 0; j < contrib_804b0550[i].n; ++j)
                weight += (float)(int)raster[contrib_804b0550[i].p[j].pixel] * contrib_804b0550[i].p[j].weight;
            write_pixel_801d6940(tmp, i, k, (Pixel)(weight < 0.0f ? 0 : weight > 255.0f ? 255 : (Pixel)weight));
        }
    }
    w3d_handle_storage_release_802134fc(raster);
    for (i = 0; i < tmp->xsize; ++i) w3d_handle_storage_release_802134fc(contrib_804b0550[i].p);
    w3d_handle_storage_release_802134fc(contrib_804b0550);
    contrib_804b0550 = (CList *)g3c_allocate_80213c30(dst->ysize, sizeof(CList));
    if (yscale < 1.0f) {
        width = fwidth / yscale;
        fscale = 1.0f / yscale;
        for (i = 0; i < dst->ysize; ++i) {
            contrib_804b0550[i].n = 0;
            contrib_804b0550[i].p = (Contrib *)g3c_allocate_80213c30((int)(width * 2 + 1.0f), sizeof(Contrib));
            center = (float)i / yscale;
            left = w3d_cx9c_ceilf_802e85fc(center - width);
            right = w3d_cx9c_floorf_802e87d4(center + width);
            for (j = (int)left; (float)j <= right; ++j) {
                weight = center - (float)j;
                weight = (*filterf)(weight / fscale) / fscale;
                if (j < 0) n = -j;
                else if (j >= tmp->ysize) n = (tmp->ysize - j) + tmp->ysize - 1;
                else n = j;
                k = contrib_804b0550[i].n++;
                contrib_804b0550[i].p[k].pixel = n;
                contrib_804b0550[i].p[k].weight = weight;
            }
        }
    } else {
        for (i = 0; i < dst->ysize; ++i) {
            contrib_804b0550[i].n = 0;
            contrib_804b0550[i].p = (Contrib *)g3c_allocate_80213c30((int)(fwidth * 2 + 1.0f), sizeof(Contrib));
            center = (float)i / yscale;
            left = w3d_cx9c_ceilf_802e85fc(center - fwidth);
            right = w3d_cx9c_floorf_802e87d4(center + fwidth);
            for (j = (int)left; (float)j <= right; ++j) {
                weight = center - (float)j;
                weight = (*filterf)(weight);
                if (j < 0) n = -j;
                else if (j >= tmp->ysize) n = (tmp->ysize - j) + tmp->ysize - 1;
                else n = j;
                k = contrib_804b0550[i].n++;
                contrib_804b0550[i].p[k].pixel = n;
                contrib_804b0550[i].p[k].weight = weight;
            }
        }
    }
    raster = (Pixel *)g3c_allocate_80213c30(tmp->ysize, sizeof(Pixel));
    for (k = 0; k < dst->xsize; ++k) {
        read_row_801d68e0(raster, tmp, k);
        for (i = 0; i < dst->ysize; ++i) {
            weight = 0.0f;
            for (j = 0; j < contrib_804b0550[i].n; ++j)
                weight += (float)(int)raster[contrib_804b0550[i].p[j].pixel] * contrib_804b0550[i].p[j].weight;
            write_pixel_801d6940(dst, k, i, (Pixel)(weight < 0.0f ? 0 : weight > 255.0f ? 255 : (Pixel)weight));
        }
    }
    w3d_handle_storage_release_802134fc(raster);
    for (i = 0; i < dst->ysize; ++i) w3d_handle_storage_release_802134fc(contrib_804b0550[i].p);
    w3d_handle_storage_release_802134fc(contrib_804b0550);
    w3d_auto_801d6850(tmp);
}
