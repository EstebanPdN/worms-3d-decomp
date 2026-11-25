// GWMP8P rev0 0x8002013c. Reads the grid height value and, when it changed,
// raises each layer's low and high cell tables and marks raised cells
// blocked. Layer and table names are inferred.
struct Rect { short x0, y0, x1, y1; };
template <class T> struct Table {
    T *data;
    int unknown[3];
    T &operator[](int i) { return data[i]; }
};
struct Layer {
    char unknown00[28];
    Rect r;
    Table<unsigned char> blocked[2];
    Table<float> low[2];
    Table<float> high[2];
    int Index(short x, short y) const { return (y - r.y0) * (r.x1 - r.x0) + x - r.x0; }
};
struct Grid {
    char unknown00[88];
    Layer **first, **last;
    Layer *&at(int i) { return first[i]; }
    char unknown60[12];
    float height;
    float last_height;
    char unknown74[44];
    void *value;
};
extern "C" void *w3d_empty_80342a74(void *);
extern "C" float w3d_value_80178df0(void *);
extern "C" void w3d_d43a_grid_height_refresh_8002013c(Grid *self)
{
    self->height = w3d_value_80178df0(w3d_empty_80342a74(self->value));
    if (self->height != self->last_height) {
        int n = self->last - self->first;
        for (int i = 0; i < n; i++) {
            Layer *l = self->at(i);
            const Rect &r = l->r;
            int x1 = r.x1, y0 = r.y0, y1 = r.y1;
            for (int x = l->r.x0; x < x1; x++) {
                for (int y = y0; y < y1; y++) {
                    for (int k = 0; k < 2; k++) {
                        int a = l->Index(x, y);
                        float &low = l->low[k][a];
                        if (low <= self->height) {
                            low = self->height;
                            int b = l->Index(x, y);
                            float &high = l->high[k][b];
                            if (high < self->height) high = self->height;
                            l->blocked[k][l->Index(x, y)] = 1;
                        }
                    }
                }
            }
        }
    }
    self->last_height = self->height;
}
