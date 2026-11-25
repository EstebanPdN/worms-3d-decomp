struct K8cBounds { char pad00[20]; float width; float height; };
struct K8cPanel {
    char pad00[28];
    char body[12];
    struct K8cBounds *bounds;
    char pad2c[244];
    int mode;
    char pad124[24];
    float margin;
};
extern float fn_802b1880(void *body);
extern void fn_802a0f98(struct K8cPanel *self, float size, float width, float height);
extern void fn_802a06ac(struct K8cPanel *self, float size, float width, float height);
void w3d_k8c_panel_layout_802a0c48(struct K8cPanel *self)
{
    float margin = self->margin;
    float size = fn_802b1880(self->body);
    struct K8cBounds *bounds = self->bounds;
    float width = bounds->width - margin;
    float height = bounds->height - margin;
    float full_width = width + width;
    float full_height = height + height;
    if (self->mode == 1)
        fn_802a0f98(self, size, full_width, full_height);
    else
        fn_802a06ac(self, size, full_width, full_height);
}
