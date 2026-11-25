// Original native shared-string assignment and serialized string table indexes.
namespace Sol35d6ReadStrings {
extern "C" void sol35d6_release_header_8020bb2c(unsigned short *);
struct String {
    char *text;
    String &operator=(const String &other) {
        ++reinterpret_cast<unsigned short *>(other.text)[-3];
        unsigned short *header=reinterpret_cast<unsigned short *>(text)-3;
        if(--*header==0) sol35d6_release_header_8020bb2c(header);
        text=other.text;
        return *this;
    }
};
struct Reader { unsigned prefix[35]; String *strings; };
extern "C" unsigned sol35d6_read_index_802024f4(Reader *);
}
extern "C" int sol35d6_read_strings_80202044(
    Sol35d6ReadStrings::Reader *self,Sol35d6ReadStrings::String *out,unsigned count) {
    using namespace Sol35d6ReadStrings;
    for(unsigned i=0;i<count;++i) {
        unsigned index=sol35d6_read_index_802024f4(self);
        if(out) *out++=self->strings[index];
    }
    return 0;
}
