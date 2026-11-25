#pragma once
struct W3dCardUi {
    int active, ready, selected, count, operation;
    char title[96], options[5][96];
};
extern "C" int w3d_card_ui_read(W3dCardUi *out);
extern "C" void w3d_card_ui_choose(int index);
