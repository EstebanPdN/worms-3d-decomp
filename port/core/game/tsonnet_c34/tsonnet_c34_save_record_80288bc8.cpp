#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_c34_save_record_80288bc8.c"
/* Reference-only: builds one save record. Allocates a temporary 8268-byte
   buffer, retrieves data into the record at +8268, copies icons into the
   record at +76 with a four-byte colour (0xff, 0, 0xff, 0xff), then calls an
   external record builder with three global string pointers, a field of the
   card object at +696, the record and the temporary buffer, and releases the
   buffer. The eighth builder argument is an uninitialised local: the original
   passes whatever its callee-saved register r31 held, and the source keeps that
   as an unassigned variable. Layouts, names and meanings are inferred; callees
   and globals are external originals declared by address. */
struct Card;
extern Ptr32<void> w3d_temp_alloc_801fe0b8(unsigned int);
extern void w3d_temp_release_801fe160(Ptr32<void>);
extern void w3d_retrieve_8028a098(Ptr32<struct Card>, Ptr32<void>);
extern void w3d_copy_icons_80288fe8(Ptr32<struct Card>, Ptr32<void>, unsigned int);
extern void w3d_build_record_802ab804(Ptr32<const char>, Ptr32<const char>, Ptr32<const char>, int, Ptr32<void>, unsigned int, Ptr32<void>, int, int, Ptr32<void>);
extern Ptr32<const char> w3d_ptr_804abbd4; extern Ptr32<const char> w3d_ptr_804abbd8; extern Ptr32<const char> w3d_ptr_804abbdc;

void tsonnet_c34_save_record_80288bc8(Ptr32<struct Card> card, Ptr32<char> data, int arg) {
    int unused;
    Ptr32<void> buf = w3d_temp_alloc_801fe0b8(8268);
    w3d_retrieve_8028a098(card, data + 8268);
    {
        struct Colour { unsigned char r, g, b, a; } col = {0, 0, 0, 0};
        col.r = 255; col.b = 255; col.a = 255;
        w3d_copy_icons_80288fe8(card, data + 76, *(Ptr32<unsigned int>)&col);
    }
    w3d_build_record_802ab804(w3d_ptr_804abbd4, w3d_ptr_804abbd8, w3d_ptr_804abbdc, *(Ptr32<int>)((Ptr32<char>)card + 696), data, 0x11800, data + 76, unused, arg, buf);
    w3d_temp_release_801fe160(buf);
}

}
