#include "w3d_ptr.h"
#line 1 "d24b_object_menu_key_80099aa8.cpp"
/* Debug object-menu key handler (0x80099aa8): dispatches on the menu state (+40). In the
 * list state, N/P page through the entries (19 per page), ?/ show help, T toggles +56, S
 * cycles the filter +60, Y cycles +76, R rebuilds, and any other key selects an entry
 * through the two key tables 0x804aabc8 and 0x804aabcc. In the detail state, N/P move
 * through the entry's lines and R returns. Field and type names are inferred from the
 * original instructions. */
extern "C" Ptr32<char> w3d_strchr_802ef198(Ptr32<const char>, int);
struct MenuEntry;
struct MenuEntryVtable { char unknown00[80]; Ptr32<unsigned int (Ptr32<MenuEntry>)> lineCount; /* +80 */ };
struct MenuEntry { Ptr32<MenuEntryVtable> vtable; };
struct ObjectMenu {
    char unknown00[28];
    int filterCount;    /* +28 */
    char unknown32[8];
    int state;          /* +40 */
    int page;           /* +44 */
    unsigned selected;  /* +48 */
    unsigned line;      /* +52 */
    int toggle;         /* +56 */
    int filter;         /* +60 */
    Ptr32<Ptr32<MenuEntry>> begin;  /* +64 */
    Ptr32<Ptr32<MenuEntry>> end;    /* +68 */
    Ptr32<MenuEntry> & At(unsigned i) { return begin[i]; }
    char unknown72[4];
    int mode;           /* +76 */
};
extern "C" void w3d_rebuild_800994b4(Ptr32<ObjectMenu>);
extern "C" void w3d_refresh_800990a4(Ptr32<ObjectMenu>);
extern "C" void w3d_show_options_80099998(Ptr32<ObjectMenu>);
extern "C" void w3d_show_help_80099a20(Ptr32<ObjectMenu>);
extern "C" void w3d_show_detail_80099dc0(Ptr32<ObjectMenu>);
extern "C" void w3d_page_setup_80098fc8(Ptr32<ObjectMenu>);
extern Ptr32<const char> w3d_keys_804aabc8; extern Ptr32<const char> w3d_keys_804aabcc;

extern "C" void w3d_d24b_object_menu_key_80099aa8(Ptr32<ObjectMenu> self, int key)
{
    switch (self->state) {
    case 1:
        switch (key) {
        case 'N': case 'n': {
            int next = self->page + 1;
            if ((unsigned)(next * 19) < (unsigned)(self->end - self->begin)) {
                self->page = next;
                w3d_refresh_800990a4(self);
            }
            w3d_show_options_80099998(self);
            break;
        }
        case 'P': case 'p':
            if (self->page) {
                self->page--;
                w3d_refresh_800990a4(self);
            }
            w3d_show_options_80099998(self);
            break;
        case '?': case '/':
            w3d_show_help_80099a20(self);
            break;
        case 'T': case 't':
            self->toggle ^= 1;
            w3d_rebuild_800994b4(self);
            w3d_refresh_800990a4(self);
            w3d_show_options_80099998(self);
            break;
        case 'S': case 's':
            if (self->filter == -1) {
                self->filter = 0;
            } else {
                self->filter++;
                if (self->filter >= self->filterCount) self->filter = -1;
            }
            w3d_rebuild_800994b4(self);
            w3d_refresh_800990a4(self);
            w3d_show_options_80099998(self);
            break;
        case 'Y': case 'y':
            self->mode++;
            if (self->mode > 7) self->mode = 0;
            w3d_rebuild_800994b4(self);
            w3d_refresh_800990a4(self);
            w3d_show_options_80099998(self);
            break;
        case 'R': case 'r':
            w3d_rebuild_800994b4(self);
            w3d_refresh_800990a4(self);
            w3d_show_options_80099998(self);
            break;
        default: {
            Ptr32<const char> keys = w3d_keys_804aabc8;
            Ptr32<char> hit = w3d_strchr_802ef198(keys, key);
            if (!hit) {
                keys = w3d_keys_804aabcc;
                hit = w3d_strchr_802ef198(keys, key);
                if (!hit) break;
            }
            unsigned index = self->page * 19 + (hit - keys);
            if (index < (unsigned)(self->end - self->begin)) {
                Ptr32<MenuEntry> entry = self->At(index);
                if (entry->vtable->lineCount(entry)) {
                    self->selected = index;
                    self->line = 0;
                    w3d_show_detail_80099dc0(self);
                }
            }
            break;
        }
        }
        break;
    case 3:
        switch (key) {
        case 'N': case 'n': {
            Ptr32<MenuEntry> entry = self->At(self->selected);
            unsigned count = entry->vtable->lineCount(entry);
            if (self->line < count - 1) {
                self->line++;
                w3d_show_detail_80099dc0(self);
            }
            break;
        }
        case 'P': case 'p':
            if (self->line) {
                self->line--;
                w3d_show_detail_80099dc0(self);
            }
            break;
        case 'R': case 'r':
            w3d_page_setup_80098fc8(self);
            break;
        }
        break;
    case 0:
        w3d_page_setup_80098fc8(self);
        break;
    case 2:
        w3d_page_setup_80098fc8(self);
        break;
    }
}


