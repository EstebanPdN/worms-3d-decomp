#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "display.c"
typedef unsigned int u32;
typedef unsigned short u16;
struct Source { char pad[36]; Ptr32<void> display; char pad2[64]; Ptr32<void> model; char pad3[28]; u32 index; };
struct Item { char pad[164]; volatile int used; char pad2[2]; volatile u16 total; };
struct Model { char pad[60]; int mode; };
extern Ptr32<struct Item> query_800fc6dc(u32);
extern Ptr32<void> display_80343580(Ptr32<void>);
extern Ptr32<struct Model> model_801797b4(Ptr32<void>);
extern int set_text_8018c5b0(Ptr32<void>, Ptr32<const char>);
extern int sprintf(Ptr32<char>, Ptr32<const char>, ...);
extern char empty_804b1920;
extern char format_8036c738[];
void terra_only_a3_display_800248f8(Ptr32<struct Source> s) {
    char text[16];
    if (s->index < 16) {
        Ptr32<struct Item> item = query_800fc6dc(s->index);
        Ptr32<void> display = display_80343580(s->display);
        if (model_801797b4(s->model)->mode == 1)
            set_text_8018c5b0(display, &empty_804b1920);
        else {
            int total = item->total;
            int used = item->used;
            sprintf(text, format_8036c738, total - used);
            set_text_8018c5b0(display, text);
        }
    }
}

}
