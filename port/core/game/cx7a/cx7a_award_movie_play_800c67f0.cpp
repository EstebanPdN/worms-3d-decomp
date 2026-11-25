#include "w3d_ptr.h"
#line 1 "cx7a_award_movie_play_800c67f0.cpp"

// A scoped shared string receives GameOver.AwardMovie, which is then reset
// to the original empty string before forwarding the selected movie name.
struct Cx7aString {
 Cx7aString(const Cx7aString &);Ptr32<const char> text;Cx7aString();~Cx7aString();};
extern "C" Ptr32<void> init_803426b8(Ptr32<Cx7aString>);
extern "C" int assign_8020bd38(Ptr32<Cx7aString>,Ptr32<const char>);
extern "C" void finish_8020c5c4(Ptr32<Cx7aString>);
extern "C" void release_80341588(Ptr32<Cx7aString>);
inline Cx7aString::Cx7aString(){}inline Cx7aString::~Cx7aString(){finish_8020c5c4(this);release_80341588(this);}
struct Cx7aPlayer;
extern const char key_803877f4[],empty_80387410[];
extern "C" int read_800fc2b0(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<const char>>);
extern "C" int write_800fc550(Ptr32<Ptr32<const char>>,Ptr32<const char>);
extern "C" int play_800c6660(Ptr32<Cx7aPlayer>,Ptr32<const char>);
extern "C" void w3d_cx7a_award_movie_play_800c67f0(Ptr32<Cx7aPlayer> self) {Cx7aString movie;init_803426b8(&movie);Ptr32<const char> key=key_803877f4;Ptr32<const char> text;read_800fc2b0(&key,&text);assign_8020bd38(&movie,text);Ptr32<const char> reset=key_803877f4;write_800fc550(&reset,empty_80387410);play_800c6660(self,movie.text);}


