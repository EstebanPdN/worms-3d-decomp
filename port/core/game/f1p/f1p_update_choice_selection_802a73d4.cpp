#include "w3d_ptr.h"
#line 1 "f1p_update_choice_selection_802a73d4.cpp"
// Observed current-choice property and retained by-value name transfer.
extern "C" void fn_8020c5c0(Ptr32<void>),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);struct F1pChoiceHeader{unsigned short refs,length,capacity;};extern "C" Ptr32<F1pChoiceHeader> fn_80341884(Ptr32<void>);
struct F1pChoiceNameView{Ptr32<char> text;};struct F1pChoiceName{Ptr32<char> text;F1pChoiceName(const F1pChoiceNameView&s){fn_8020c5c0(this);text=s.text;Ptr32<F1pChoiceHeader> h=fn_80341884(this);++h->refs;}F1pChoiceName(const F1pChoiceName&s){fn_8020c5c0(this);text=s.text;Ptr32<F1pChoiceHeader> h=fn_80341884(this);++h->refs;}~F1pChoiceName(){fn_8020c5c4(this);fn_80341588(this);}};
struct F1pChoiceIface{Ptr32<Ptr32<void>> table;};struct F1pChoiceOwner{char unknown0[240];int resolved;char unknown244[144];Ptr32<F1pChoiceIface> property;char unknown392[108];F1pChoiceNameView names[26];int selected;};extern Ptr32<void> table_804abbac;extern "C" int fn_80178c48(Ptr32<void>),fn_80178d1c(Ptr32<void>),fn_8028496c(Ptr32<void>,F1pChoiceName);extern "C" Ptr32<void> fn_803426b4(Ptr32<F1pChoiceIface>); Ptr32<void> fn_80342a78(Ptr32<F1pChoiceIface>);
extern "C" void w3d_update_choice_selection_802a73d4(Ptr32<F1pChoiceOwner> s){switch(((Ptr32<int (Ptr32<F1pChoiceIface>)>)s->property->table[6])(s->property)){case 0:s->selected=fn_80178c48(fn_803426b4(s->property));break;case 1:s->selected=fn_80178d1c(fn_80342a78(s->property));break;default:break;}s->resolved=fn_8028496c(table_804abbac,F1pChoiceName(s->names[s->selected]));}


