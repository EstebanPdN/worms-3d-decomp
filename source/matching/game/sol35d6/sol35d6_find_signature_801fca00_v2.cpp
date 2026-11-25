// Observed native category vector and pointer iterator, GC32 partial views.
namespace Sol35d6FindSignatureV2 {
struct Object { unsigned header[3]; const void *signature; };
struct Vector { Object **begin, **end, **capacity; };
struct Iterator { Object **position, **end; const void *signature; int category; };
extern "C" Vector sol35d6_categories_8045e890[];
extern "C" int sol35d6_compare_802eedc0(const void *, const void *, unsigned);
}
extern "C" Sol35d6FindSignatureV2::Iterator *sol35d6_find_signature_801fca00_v2(
    Sol35d6FindSignatureV2::Iterator *self, int category, const void *signature) {
    using namespace Sol35d6FindSignatureV2;
    self->signature = signature;
    self->category = category;
    Vector &values=sol35d6_categories_8045e890[category];
    self->position=values.begin;
    self->end=values.end;
    if (self->position != self->end) do {
        if (sol35d6_compare_802eedc0((*self->position)->signature,
                                  self->signature, 16) == 0) break;
        ++self->position;
    } while (self->position != self->end);
    return self;
}
typedef char Sol35d6FindVectorSize[sizeof(Sol35d6FindSignatureV2::Vector)==12?1:-1];
