
extern char *lbl_804b1788;

void w3d_s20_notify_if_flagged_800e8ee0(char *self, char *flag, void **target) {
    if (*flag != 0) {
        void *first = *(void **)(lbl_804b1788 + 108);
        void *second;
        ((S20Call0)*(void **)(*(char **)first + 92))(first);
        second = *target;
        ((S20Call0)*(void **)(*(char **)second + 20))(second);
    }
}
