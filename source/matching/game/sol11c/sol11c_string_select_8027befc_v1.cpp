// External shared-string ABI: 8-byte wrapper, reference count six bytes before text.
// The second wrapper word is observed storage whose meaning remains unknown.
extern "C" void string_from_text_8020bb54(void*,const char*);
extern "C" void string_release_header_8020bb2c(void*);
extern "C" void string_base_init_8020c5c0(void*);
extern "C" void string_base_finish_8020c5c4(void*);
extern "C" void string_release_80341588(void*);
extern "C" unsigned short* string_header_80341884(void*);
struct SharedString {
    char* text;
    unsigned unknown;
    SharedString(const char* p) { string_from_text_8020bb54(this,p); }
    SharedString(const SharedString& s) {
        string_base_init_8020c5c0(this);
        text=s.text;
        ++*string_header_80341884(this);
    }
    ~SharedString() { string_base_finish_8020c5c4(this); string_release_80341588(this); }
    SharedString& operator=(const SharedString& s) {
        ++*(unsigned short*)(s.text-6);
        if (--*(unsigned short*)(text-6)==0) string_release_header_8020bb2c(text-6);
        text=s.text;
        return *this;
    }
};
#define MEMBER(p,T,n) (*(T*)((char*)(p)+(n)))
extern const char failure_text_803cea20[];
extern "C" SharedString sol11c_string_select_8027befc(void* owner,int category,int index) {
    SharedString result(failure_text_803cea20);
    SharedString* strings;
    switch(category) {
    case 0: strings=MEMBER(owner,SharedString*,28); break;
    case 4: strings=MEMBER(owner,SharedString*,44); break;
    case 3: strings=MEMBER(owner,SharedString*,60); break;
    case 5: strings=MEMBER(owner,SharedString*,76); break;
    case 6: strings=MEMBER(owner,SharedString*,92); break;
    default: return result;
    }
    // Each selected table contains pointers to the string text, not wrappers.
    char** text_table=(char**)strings;
    ++*(unsigned short*)(text_table[index]-6);
    if (--*(unsigned short*)(result.text-6)==0) string_release_header_8020bb2c(result.text-6);
    result.text=text_table[index];
    return result;
}
