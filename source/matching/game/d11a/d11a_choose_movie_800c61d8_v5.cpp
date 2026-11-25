// Native movie table selection. Tables and diagnostic strings are original
// external objects, not owned data. Names are inferred. The 12-byte record
// stride and sentinel 29 are witnessed by both movie lookup routines.
struct d11a_Movie { const char *name; unsigned category; const char *file; };
extern d11a_Movie d11a_pal_movies_803f5728[];
extern d11a_Movie d11a_ntsc_movies_803f58b4[];
extern const char d11a_movie_source_803876ac[];
extern const char d11a_tv_error_803876c4[];
extern "C" unsigned d11a_tv_format_80304de0();
extern "C" unsigned d11a_random_80162ba8();
// SDK panic's original prologue is variadic, and its final path halts.
// No invented return/default table is supplied on that nonreturning path.
extern "C" void d11a_panic_802fb82c(const char *, int, const char *, ...);
inline const char *d11a_select_movie(unsigned category, d11a_Movie *movies) {
 unsigned count=0;
 for(unsigned i=0; movies[i].category!=29; ++i)
   if(movies[i].category==category) ++count;
 unsigned choice=d11a_random_80162ba8()%count;
 for(unsigned i=0; movies[i].category!=29; ++i)
   if(movies[i].category==category) {
      if(choice==0) return movies[i].file;
      --choice;
   }
 return 0;
}
extern "C" const char *d11a_choose_movie_800c61d8(void *, unsigned category)
{
 d11a_Movie *movies;
 switch(d11a_tv_format_80304de0()) {
 case 1: movies=d11a_pal_movies_803f5728; break;
 case 0: case 2: movies=d11a_ntsc_movies_803f58b4; break;
 default: d11a_panic_802fb82c(d11a_movie_source_803876ac,339,d11a_tv_error_803876c4); break;
 }
 return d11a_select_movie(category,movies);
}
