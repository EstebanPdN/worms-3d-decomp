#pragma once
#include <math.h>

// One layout for Metal presentation and mouse hit testing, including small windows.
struct DualLayout {
    double scale, x, y;
    DualLayout(double w, double h) {
        scale = fmax(0.01, fmin(w / 400.0, h / 480.0));
        x = (w - 400 * scale) * 0.5;
        y = (h - 480 * scale) * 0.5;
    }
    bool touch(double px, double py, int &tx, int &ty) const {
        double fx = (px - x) / scale - 40, fy = (py - y) / scale - 240;
        tx = (int)floor(fx); ty = (int)floor(fy);
        return fx >= 0 && fx < 320 && fy >= 0 && fy < 240;
    }
};
