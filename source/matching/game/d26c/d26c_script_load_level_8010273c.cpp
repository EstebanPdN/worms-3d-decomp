// d26c: 0x8010273c. ScriptService::LoadLevelScriptFiles (name from its own messages): load stdlib, then each comma
// separated file of the GameLogic.CurrentScript setting, logging each result. Script is opaque; String is one word.
// The strings stay extern: the pool also holds "Script load failed : stdlib", which no instruction here reads.
struct String {
    char *text;
    String();
    String(const String &);
    ~String();
    int format(const char *, ...);
};
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
extern "C" int forward_800fd4c8(int, int);
extern "C" int read_800fc2b0(const char **, const char **);
extern "C" void clear_80102474(void *);
extern "C" int file_80102530(void *, const char *);
extern "C" void hook_801022e8(void *, const char *);
extern "C" char *strcpy(char *, const char *);
extern "C" char *strtok(char *, const char *);
extern char name_80398e7c[], stdlib_80398e94[], comma_80398ebc[], failed_80398ec0[], loaded_80398ef8[];
extern "C" int d26c_script_load_level_8010273c(void *self) {
    if (forward_800fd4c8(8, 2) < 0) forward_800fd4c8(8, 1);
    const char *name = name_80398e7c;
    const char *value;
    read_800fc2b0(&name, &value);
    clear_80102474(self);
    int hr = file_80102530(self, stdlib_80398e94);
    if (hr >= 0) {
        if (value == 0 || *value == 0) {
            hr = 0x80004005;
        } else {
            char buf[256];
            strcpy(buf, value);
            char *tok = strtok(buf, comma_80398ebc);
            if (tok) do {
                String s;
                hr = file_80102530(self, tok);
                if (hr < 0) s.format(failed_80398ec0, tok);
                else s.format(loaded_80398ef8, tok);
                hook_801022e8(self, s.text);
                tok = strtok(0, comma_80398ebc);
            } while (tok);
            return hr;
        }
    }
    return hr;
}
