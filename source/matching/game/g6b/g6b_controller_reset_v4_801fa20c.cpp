// External vector views. Runtime storage belongs to the original controller object.
typedef unsigned int Word;
struct ByteVector;
struct FloatVector;
extern "C" void fn_80359d9c(ByteVector *, char *, Word, const char *);
extern "C" void fn_80359f84(FloatVector *, float *, Word, const float *);
extern const float zero_803b1a98[];
inline float initialFloat() { return zero_803b1a98[0]; }
struct ByteVector {
    char *first, *last; Word unknown08; char *limit;
    inline Word size() const { return last - first; }
    inline void resize(Word count, const char &value = char()) {
        if (size() > count) last = first + count;
        else fn_80359d9c(this, last, count-size(), &value);
    }
};
struct FloatVector {
    float *first, *last; Word unknown08; float *limit;
    inline float &at(Word index) { return *(float *)((char *)first + (index << 2)); }
    inline Word size() const { return last - first; }
    inline void resize(Word count, const float &value = initialFloat()) {
        if (size() > count) last = first + count;
        else fn_80359f84(this, last, count-size(), &value);
    }
};
struct ControllerRecord { char unknown[10]; signed char status; char unknown11; };
extern ControllerRecord records_8045e824[];
extern "C" void fn_80301e04(ControllerRecord *);
struct ControllerView {
    char unknown00[32];
    ByteVector buttons;
    FloatVector axes;
    char unknown40[16];
    FloatVector triggers;
    char unknown60[32];
    int controller;
    char unknown84[76];
    ByteVector previousButtons;
    FloatVector previousAxes;
    FloatVector previousTriggers;
};
extern "C" int g6b_controller_reset_801fa20c(ControllerView *self, int unused, int controller) {
    Word index = 0;
    self->controller = controller;
    self->buttons.resize(16);
    self->previousButtons.resize(16);
    self->axes.resize(8);
    self->previousAxes.resize(8);
    self->triggers.resize(4);
    self->previousTriggers.resize(4);
    index = 0;
    while (index < self->buttons.size()) {
        self->buttons.first[index] = 0;
        self->previousButtons.first[index] = 0;
        ++index;
    }
    index = 0;
    while (index < self->axes.size()) {
        self->axes.at(index) = zero_803b1a98[0];
        self->previousAxes.at(index) = zero_803b1a98[0];
        ++index;
    }
    index = 0;
    while (index < self->triggers.size()) {
        self->triggers.at(index) = zero_803b1a98[0];
        self->previousTriggers.at(index) = zero_803b1a98[0];
        ++index;
    }
    ControllerRecord *selected = records_8045e824 + self->controller;
    fn_80301e04(records_8045e824);
    if (selected->status == -1) return (int)0x80004005;
    while ((unsigned char)(selected->status + 3) < 2) {
        fn_80301e04(records_8045e824);
        if (index++ > 1000) return (int)0x80004005;
    }
    return 0;
}
