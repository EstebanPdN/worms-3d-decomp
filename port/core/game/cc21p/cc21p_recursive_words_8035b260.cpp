#include "w3d_ptr.h"
#line 1 "cc21p_recursive_words_8035b260.cpp"
// The original direct call at 0x8035b284 targets this entry itself.
// Preserve that observed dependency; its intent and reachability are unknown.
typedef unsigned long long Cc21pU64;
typedef unsigned int Cc21pU32;
extern "C" Cc21pU64 dependency_8035b260(Cc21pU64);
static inline Cc21pU32 cc21pPermuteWord(Cc21pU32 word)
{
    return (word << 24) | ((word & 0xff00) << 8) |
           ((word >> 8) & 0xff00) | (word >> 24);
}
extern "C" Cc21pU64 w3d_cc21p_recursive_words_8035b260(Cc21pU64 words)
{
    return dependency_8035b260((Cc21pU64)(Cc21pU32)words << 32) |
           cc21pPermuteWord((Cc21pU32)(words >> 32));
}


