struct K2aPoint { float x, y, z; };
struct K2aVec3 {
    float x, y, z;
    K2aVec3(const K2aPoint &p) : x(p.x), y(p.y), z(p.z) {}
};
extern "C" int FUN_8001e328(void *self, void *cell, short *column, short *row, int *layer);
extern "C" K2aPoint FUN_8001e224(void *self, int column, int row, int layer);

extern "C" K2aVec3 k2a_grid_position_8001f9f0(void *self, int cell)
{
    short column;
    short row;
    int layer;
    FUN_8001e328(self, (void *)cell, &column, &row, &layer);
    return K2aVec3(FUN_8001e224(self, column, row, layer));
}
