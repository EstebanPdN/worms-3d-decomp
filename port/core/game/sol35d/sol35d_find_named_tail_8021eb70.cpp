#include "w3d_ptr.h"
#line 1 "sol35d_find_named_tail_8021eb70.cpp"
// The table header is followed by count live entry pointers in native storage.
// Observed GC32 views. Names describe the operation; original class names are unknown.
struct Sol35dSharedString;
extern "C" void fn_8020c5c0(Ptr32<Sol35dSharedString>);
extern "C" void fn_8020c5c4(Ptr32<Sol35dSharedString>);
extern "C" void fn_80341588(Ptr32<Sol35dSharedString>);
extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<Sol35dSharedString>);
extern "C" int fn_802ef234(Ptr32<const char>, Ptr32<const char>);

struct Sol35dSharedString {
    Ptr32<char> data;
    Sol35dSharedString(const Sol35dSharedString &other) {
        fn_8020c5c0(this);
        data = other.data;
        ++*fn_80341884(this);
    }
    ~Sol35dSharedString() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    int compare(Ptr32<const char> name) { return fn_802ef234(data, name); }
};
struct Sol35dNamedObject {
    unsigned char unknown_00[52];
    Sol35dSharedString name;
    Sol35dSharedString getName() const { return name; }
};
extern "C" Ptr32<Sol35dNamedObject> fn_80240994(Ptr32<void>);
struct Sol35dNameTable {
    unsigned char unknown_00[24];
    unsigned count, unknown_1c;
};
struct Sol35dNameOwner {
    unsigned char unknown_00[20];
    Ptr32<Sol35dNameTable> table;
};
extern "C" Ptr32<void> w3d_sol35d_find_named_tail_8021eb70(Ptr32<Sol35dNameOwner> self, Ptr32<const char> key) {
    Ptr32<Sol35dNameTable> table = self->table;
    unsigned count = table->count;
    Ptr32<Ptr32<void>> items = (Ptr32<Ptr32<void>>)((Ptr32<unsigned char>)table + 32);
    unsigned index = 0;
    if (index < count) {
        do {
            Ptr32<Sol35dNamedObject> object = fn_80240994(items[index]);
            int comparison;
            {
                Sol35dSharedString name = object->getName();
                comparison = name.compare(key);
            }
            if (comparison == 0) return items[index];
            ++index;
        } while (index < count);
    }
    return 0;
}


