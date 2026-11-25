typedef unsigned int u32;
typedef unsigned short u16;
struct Source { char pad[36]; void *display; char pad2[64]; void *model; char pad3[28]; u32 index; };
struct Item { char pad[164]; volatile int used; char pad2[2]; volatile u16 total; };
struct Model { char pad[60]; int mode; };
extern struct Item *query_800fc6dc(u32);
extern void *display_80343580(void *);
extern struct Model *model_801797b4(void *);
extern int set_text_8018c5b0(void *, const char *);
extern int sprintf(char *, const char *, ...);
extern char empty_804b1920;
extern char format_8036c738[];
void terra_only_a3_display_800248f8(struct Source *s) {
    char text[16];
    if (s->index < 16) {
        struct Item *item = query_800fc6dc(s->index);
        void *display = display_80343580(s->display);
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
