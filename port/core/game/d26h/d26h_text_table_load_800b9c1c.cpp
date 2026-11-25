#include "w3d_ptr.h"
#line 1 "d26h_text_table_load_800b9c1c.cpp"
// GWMP8P rev0 0x800b9c1c. Text table loader. File and String layouts are
// partial views; the string length and reference count sit at -4 and -6 of
// the text pointer. Rows are 128 by 6 strings. The end-of-file arm repeats
// the separator logic, and its row and column updates are dead.
extern "C" void release_header_8020bb2c(Ptr32<unsigned short>);
struct String {
    Ptr32<char> text;
    unsigned short Length() const { return reinterpret_cast<unsigned short *>(w3d::R(text))[-2]; }
    String &operator=(const String &other) {
        ++reinterpret_cast<unsigned short *>(w3d::R(other.text))[-3];
        Ptr32<unsigned short> header = reinterpret_cast<unsigned short *>(w3d::R(text)) - 3;
        if (--*header == 0) {
            release_header_8020bb2c(header);
        }
        text = other.text;
        return *this;
    }
};
extern "C" Ptr32<String> string_assign_8020bd38(Ptr32<String>, Ptr32<const char>);
extern "C" Ptr32<String> string_append_8020c00c(Ptr32<String>, char);
struct File { unsigned char u[24]; };
extern "C" Ptr32<File> file_ctor_80207fec(Ptr32<File>);
extern "C" int file_open_802080a0(Ptr32<File>, Ptr32<void>, int);
extern "C" int file_read_80208298(Ptr32<File>, Ptr32<unsigned char>, int, Ptr32<int>);
extern "C" int file_close_8020810c(Ptr32<File>);
extern "C" void file_dtor_8020803c(Ptr32<File>, int);
extern "C" int d26h_text_table_load_800b9c1c(Ptr32<void> path, Ptr32<String [6]> table) {
    File file;
    file_ctor_80207fec(&file);
    if (file_open_802080a0(&file, path, 1) != 0) {
        file_dtor_8020803c(&file, 2);
        return 0x80004005;
    }
    unsigned char row = 0;
    unsigned char col = 0;
    do {
        for (unsigned i = 0; i < 6; i++) string_assign_8020bd38(&table[row][i], "");
        row++;
    } while (row < 128);
    row = 0;
    do {
        unsigned char c;
        int n;
        if (file_read_80208298(&file, &c, 1, &n) == 0 && n != 0) {
            if (c >= 32) {
                string_append_8020c00c(&table[row][col], c);
            } else {
                file_read_80208298(&file, &c, 1, &n);
                if (table[row][col].Length() != 0) {
                    col++;
                    if (col == 6) { row++; col = 0; }
                } else if (col == 5) {
                    table[row][5] = table[row][0];
                    row++;
                    col = 0;
                }
            }
        } else {
            if (table[row][col].Length() != 0) {
                col++;
                if (col == 6) { row++; col = 0; }
            } else if (col == 5) {
                table[row][5] = table[row][0];
                row++;
                col = 0;
            }
            break;
        }
    } while (row < 128);
    file_close_8020810c(&file);
    file_dtor_8020803c(&file, 2);
    return 0;
}


