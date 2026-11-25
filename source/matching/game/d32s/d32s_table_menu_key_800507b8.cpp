/* GWMP8P rev0 0x800507b8. Key handler of the table menu: in mode 1 pages through the list (20 lines a page),
 * refills it, saves, loads or shows help and file lines; the other modes pass to their own screens. Names are
 * inferred from the callees and the N, P, R, S, L, F and ? key codes. */
struct D32sTableMenu {
    char u0[36]; int mode; unsigned page; unsigned total;
    void refresh();
    void show_help();
    void show_file();
    void refill();
    void save();
    void load();
    void show_line();
    void setup();
    void other();
    void bank();
    void key(int c);
};
void D32sTableMenu::key(int c) {
    switch (mode) {
    case 1:
        switch (c) {
        case 'N': case 'n': {
            unsigned next = page + 1;
            if (next * 20 < total) { page = next; refresh(); }
            show_line();
            break;
        }
        case 'P': case 'p':
            if (page) { page = page - 1; refresh(); }
            show_line();
            break;
        case '?': case '/':
            show_help();
            break;
        case 'F': case 'f':
            show_file();
            break;
        case 'R': case 'r':
            refill();
            refresh();
            show_line();
            break;
        case 'S': case 's':
            save();
            break;
        case 'L': case 'l':
            load();
            break;
        default:
            show_line();
            break;
        }
        break;
    case 0:
        setup();
        break;
    case 2:
        setup();
        break;
    case 3:
        setup();
        break;
    case 5:
        other();
        break;
    case 4:
        bank();
        break;
    }
}
