// Observed native category vector and pointer iterator, GC32 partial views.
namespace Sol35d6FindSignature {
struct Descriptor { unsigned header[3]; const void *signature; };
struct Object { Descriptor *descriptor; };
struct Vector { Object **begin, **end, **capacity; };
struct Iterator { Object **position, **end; const void *signature; int category; };
extern "C" Vector sol35d6_categories_8045e890[];
extern "C" int sol35d6_compare_802eedc0(const void *, const void *, unsigned);
}
extern "C" Sol35d6FindSignature::Iterator *sol35d6_find_signature_801fca00(
    Sol35d6FindSignature::Iterator *self, int category, const void *signature) {
    using namespace Sol35d6FindSignature;
    self->signature = signature;
    self->category = category;
    self->position = sol35d6_categories_8045e890[category].begin;
    self->end = sol35d6_categories_8045e890[category].end;
    while (self->position != self->end) {
        if (sol35d6_compare_802eedc0((*self->position)->descriptor->signature,
                                  self->signature, 16) == 0) break;
        ++self->position;
    }
    return self;
}
typedef char Sol35d6FindVectorSize[sizeof(Sol35d6FindSignature::Vector)==12?1:-1];
