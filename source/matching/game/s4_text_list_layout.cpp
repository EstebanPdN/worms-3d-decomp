/* Observed text-list layout selection and label visibility management. */
extern "C" {
struct LayoutObject { void (**vtable)(LayoutObject *); };
struct LayoutConfig { char unknown00[20]; float width, height; };
struct LayoutWidget { char unknown00[40]; LayoutConfig *config; char unknown2c[96]; int enabled; char unknown90[32]; int active; char unknownb4[52]; LayoutObject *labels[3]; LayoutObject *images[3]; char unknown100[32]; int mode; char unknown124[24]; float border; char unknown140[56]; LayoutObject *box; };
void w3d_auto_8015fd1c(LayoutObject *);
void w3d_list_apply_8029fc78(LayoutWidget *);
float w3d_font_height_802b1880(void *);
void w3d_list_layout_a_802a0f98(LayoutWidget *, float, float, float);
void w3d_list_layout_b_802a06ac(LayoutWidget *, float, float, float);
void w3d_label_destroy_8025e0c4(LayoutObject *, int);
void w3d_scroll_destroy_80293528(LayoutObject *, int);
void w3d_base_visibility_802b2344(void *);
void *memset(void *, ...);
void w3d_label_visible_8025f064(LayoutObject *, int);
void w3d_scroll_refresh_8029459c(LayoutObject *, int);
void w3d_auto_8029677c(LayoutObject *, int);
void w3d_s4_text_list_remove_box(LayoutWidget *self)
{
    if (self->box) {
        w3d_auto_8015fd1c(self->box);
        self->box = 0;
        w3d_list_apply_8029fc78(self);
    }
}
#if 0 /* Floating-point temporary storage and argument scheduling differ. */
void w3d_s4_text_list_update_layout(LayoutWidget *self)
{
    float border = self->border;
    float height = w3d_font_height_802b1880((char *)self + 28);
    LayoutConfig *config = self->config;
    register struct { float y, x; } dimensions;
    dimensions.y = config->height - border;
    dimensions.x = config->width - border;
    dimensions.x += dimensions.x;
    dimensions.y += dimensions.y;
    if (self->mode == 1) w3d_list_layout_a_802a0f98(self, height, dimensions.x, dimensions.y);
    else w3d_list_layout_b_802a06ac(self, height, dimensions.x, dimensions.y);
}

#endif
void w3d_s4_text_list_clear_labels(LayoutWidget *self, int labels, int images)
{
    unsigned int i = 0;
    register LayoutObject *empty = 0;
    for (; i < 3; ++i) {
        if (labels && self->labels[i]) {
            w3d_label_destroy_8025e0c4(self->labels[i], 3);
            self->labels[i] = empty;
        }
        if (images && self->images[i]) {
            w3d_scroll_destroy_80293528(self->images[i], 3);
            self->images[i] = empty;
        }
    }
}
#if 0 /* The visibility-array pointer is cached in different registers. */
void w3d_s4_text_list_update_visibility(LayoutWidget *self, int highlighted)
{
    w3d_base_visibility_802b2344((char *)self + 28);
    int visible[3];
    register int *visiblePtr = (int *)memset(visible, 0, 12);
    if (self->active) visible[1] = 1;
    else if (!highlighted) visible[2] = 1;
    else visible[0] = 1;
    for (unsigned int i = 0; i < 3; ++i) {
        if (self->labels[i]) w3d_label_visible_8025f064(self->labels[i], visiblePtr[i]);
        if (self->images[i]) w3d_scroll_refresh_8029459c(self->images[i], visiblePtr[i]);
    }
    if (self->box) w3d_auto_8029677c(self->box, self->enabled);
}
#endif

}
