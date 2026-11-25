// Recovered editor key dispatch. Names describe observed behavior; original C++
// class names are unknown. Editor, target, type and array-header objects below
// are borrowed external views, never allocated or constructed by this unit.
namespace H1cEditorKeys {
struct TypeInfo;
struct Target;
struct Editor;

template<class T> inline T& field(void* object, unsigned offset) {
    return *reinterpret_cast<T*>(static_cast<char*>(object) + offset);
}
inline TypeInfo* typeOf(Target* object) {
    typedef TypeInfo* (*Query)(Target*);
    return field<Query*>(object, 0)[5](object);
}
inline int derivesFrom(TypeInfo* type, const TypeInfo* requested) {
    while (type != requested) {
        TypeInfo* parent = field<TypeInfo*>(type, 20);
        if (type == parent) return 0;
        type = parent;
    }
    return 1;
}
inline void release(Target* object) {
    if (object) {
        typedef void (*Release)(Target*);
        field<Release*>(object, 0)[4](object);
    }
}
}
using namespace H1cEditorKeys;
extern const TypeInfo type_80365b78[], type_80366028[], type_80365bc8[],
    type_80365c18[], type_80365c68[], type_80365b28[], type_80365d58[],
    type_80365d08[], type_80365fd8[], type_80365da8[], type_80365df8[],
    type_80366078[], type_80365e48[], type_80365e98[], type_80365cb8[],
    type_80365f38[], type_80365ee8[], type_80365f88[];
extern const char* keys_804abb9c;
extern const char* keys_804abba0;
extern "C" char* fn_802ef198(const char*, int);
extern "C" void fn_80271c94(Editor*), fn_8027a98c(Editor*),
    fn_80272968(Editor*), fn_802757c0(Editor*), fn_80272cc0(Editor*),
    fn_80272e28(Editor*), fn_80273054(Editor*), fn_80272644(Editor*),
    fn_80273dc4(Editor*), fn_8027410c(Editor*), fn_80275320(Editor*),
    fn_80274328(Editor*), fn_80274724(Editor*), fn_80275b08(Editor*),
    fn_80274a4c(Editor*), fn_80274e4c(Editor*), fn_80273560(Editor*),
    fn_802737d8(Editor*), fn_80273af0(Editor*), fn_8027ae70(Editor*),
    fn_8027aa3c(Editor*), fn_802761b8(Editor*, Target*, unsigned),
    fn_801ef380(void*, unsigned, unsigned, unsigned, unsigned);

extern "C" void w3d_h1c_editor_keys_80278e38(Editor* self, int key) {
    if (key == 27) {
        fn_80271c94(self);
    } else if (key == 32) {
        if (derivesFrom(typeOf(field<Target*>(self,92)), type_80365b78)) fn_80272968(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80366028)) fn_802757c0(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80365bc8)) fn_80272cc0(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80365c18)) fn_80272e28(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80365c68)) fn_80273054(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80365b28)) fn_80272644(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80365d58)) fn_80273dc4(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80365d08)) fn_8027410c(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80365fd8)) fn_80275320(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80365da8)) fn_80274328(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80365df8)) fn_80274724(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80366078)) fn_80275b08(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80365e48)) fn_80274a4c(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80365e98)) fn_80274e4c(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80365cb8)) fn_80273560(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80365f38)) fn_802737d8(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80365ee8)) fn_80273af0(self);
        else if (derivesFrom(typeOf(field<Target*>(self,92)), type_80365f88)) fn_8027ae70(self);
        else {
            release(field<Target*>(self,92));
            field<Target*>(self,92) = 0;
            fn_80271c94(self);
        }
    } else if (key == 127) {
        void* header = field<void*>(field<void*>(self,88),20);
        unsigned index=0;
        for (Target** current = reinterpret_cast<Target**>(static_cast<char*>(header)+32);
             index<field<unsigned>(field<void*>(field<void*>(self,88),20),24); ++index) {
            Target* entry = *current++;
            if (entry == field<Target*>(self,92)) {
                fn_801ef380(field<void*>(self,88),20,6,index,1);
                fn_80271c94(self);
                fn_8027a98c(self);
                return;
            }
        }
    } else {
        const char* match = fn_802ef198(keys_804abb9c,key);
        const char* alphabet = keys_804abb9c;
        if (match || (match=fn_802ef198(keys_804abba0,key), alphabet=keys_804abba0, match)) {
            switch (static_cast<unsigned>(match-alphabet)) {
            case 0: fn_802761b8(self,field<Target*>(self,92),2); break;
            case 2: fn_802761b8(self,field<Target*>(self,92),3); break;
            case 3: fn_802761b8(self,field<Target*>(self,92),8); break;
            case 4: fn_802761b8(self,field<Target*>(self,92),9); break;
            case 5: fn_802761b8(self,field<Target*>(self,92),10); break;
            case 6: fn_802761b8(self,field<Target*>(self,92),11); break;
            case 7: fn_802761b8(self,field<Target*>(self,92),12); break;
            case 8: fn_802761b8(self,field<Target*>(self,92),13); break;
            case 9: fn_802761b8(self,field<Target*>(self,92),14); break;
            case 10: fn_802761b8(self,field<Target*>(self,92),15); break;
            case 11: fn_8027aa3c(self); return;
            default: return;
            }
        }
    }
}
