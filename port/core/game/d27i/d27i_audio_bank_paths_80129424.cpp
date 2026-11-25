#include "w3d_ptr.h"
#line 1 "d27i_audio_bank_paths_80129424.cpp"
// GWMP8P rev0 0x80129424. Rewrites the file and stream paths of a 63 entry
// audio table to a new base directory (entries whose name holds Default) and
// loads the result through the game's audio bank object. The string default
// constructor is out of line.
extern "C" void str_finish_8020c5c4(Ptr32<void>);
extern "C" void str_release_80341588(Ptr32<void>);
extern "C" void str_free_8020bb2c(Ptr32<void>);
struct String_803426b8 {
    Ptr32<char> text;
    String_803426b8();
    String_803426b8(const String_803426b8 &);
    ~String_803426b8() { str_finish_8020c5c4(this); str_release_80341588(this); }
    String_803426b8 &set(Ptr32<const char>);
    String_803426b8 &add(Ptr32<const char>);
    String_803426b8 &add(char);
    void left(String_803426b8 &out, int n);
    Ptr32<const char> c_str() const { return text; }
    int length() const { return ((Ptr32<unsigned short>)text)[-2]; }
    String_803426b8 &operator=(const String_803426b8 &o) {
        ((Ptr32<unsigned short>)o.text)[-3]++;
        Ptr32<char> t = text;
        Ptr32<char> rep = t - 6;
        if (--((Ptr32<unsigned short>)t)[-3] == 0) str_free_8020bb2c(rep);
        text = o.text;
        return *this;
    }
};
extern "C" {

Ptr32<String_803426b8> String_set_8020bd38(Ptr32<String_803426b8>, Ptr32<const char>);
Ptr32<String_803426b8> String_addc_8020bf2c(Ptr32<String_803426b8>, Ptr32<const char>);
Ptr32<String_803426b8> String_addch_8020c00c(Ptr32<String_803426b8>, int);
int String_left_8020c0fc(Ptr32<String_803426b8>, Ptr32<String_803426b8>, int);
Ptr32<char> strstr_802efd14(Ptr32<const char>, Ptr32<const char>);
unsigned strlen_802ef9c0(Ptr32<const char>);
}

struct Entry { Ptr32<const char> name; int u4; int u8; Ptr32<const char> path; int rest[12]; };
struct Bank;
struct BankVt { char u0[64]; Ptr32<void (Ptr32<Bank>, Ptr32<const char>, Ptr32<Entry>)> load; };
struct Bank { Ptr32<BankVt> vt; };
struct Game { char u0[108]; Ptr32<Bank> bank; };
extern Ptr32<Game> game_804b1788;
extern char s_8039c944[], s_8039c94c[], s_8039c988[];
extern "C" void d27i_audio_bank_paths_80129424(Ptr32<void> self, const String_803426b8 &dir, Ptr32<const Entry> src) {
    Entry out[63];
    String_803426b8 a[63];
    String_803426b8 b[63];
    if (dir.length() == 0) return;
    for (int i = 0, next; i <= 62; i = next) {
        out[i] = src[i];
        next = i + 1;
        if (out[i].name && strstr_802efd14(out[i].name, s_8039c944)) {
            String_set_8020bd38(&a[i], out[i].name);
            String_803426b8 tmp;
            String_left_8020c0fc(&tmp, &a[i], a[i].length() - 7);
            a[i] = dir;
            String_addc_8020bf2c(&a[i], tmp.text);
            out[i].name = a[i].c_str();
            String_set_8020bd38(&b[i], s_8039c94c);
            String_addc_8020bf2c(&b[i], dir.text);
            Ptr32<const char> d = dir.text;
            if ((d + strlen_802ef9c0(d))[-1] != '/') String_addch_8020c00c(&b[i], '/');
            String_addc_8020bf2c(&b[i], out[i].path);
            out[i].path = b[i].c_str();
            out[i].u8 = 5;
        }
    }
    game_804b1788->bank->vt->load(game_804b1788->bank, s_8039c988, out);
}


