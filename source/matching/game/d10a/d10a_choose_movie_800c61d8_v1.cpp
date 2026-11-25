// Native movie table selection. Tables and diagnostic strings are original
// external objects, not owned data. Names are inferred. The 12-byte record
// stride and sentinel 29 are witnessed by both movie lookup routines.
struct d10a_Movie { const char *name; unsigned category; const char *file; };
extern d10a_Movie d10a_pal_movies_803f5728[];
extern d10a_Movie d10a_ntsc_movies_803f58b4[];
extern const char d10a_movie_source_803876ac[];
extern const char d10a_tv_error_803876c4[];
extern "C" unsigned d10a_tv_format_80304de0();
extern "C" unsigned d10a_random_80162ba8();
// SDK panic's original prologue is variadic, and its final path halts.
// No invented return/default table is supplied on that nonreturning path.
extern "C" void d10a_panic_802fb82c(const char *, int, const char *, ...);
extern "C" const char *d10a_choose_movie_800c61d8(void *, unsigned category)
{
 d10a_Movie *movies;
 switch(d10a_tv_format_80304de0()) {
 case 1: movies=d10a_pal_movies_803f5728; break;
 case 0: case 2: movies=d10a_ntsc_movies_803f58b4; break;
 default: d10a_panic_802fb82c(d10a_movie_source_803876ac,339,d10a_tv_error_803876c4); break;
 }
 unsigned count=0;
 for(unsigned i=0; movies[i].category!=29; ++i)
   if(movies[i].category==category) ++count;
 unsigned choice=d10a_random_80162ba8()%count;
 for(unsigned i=0; movies[i].category!=29; ++i)
   if(movies[i].category==category) {
      if(choice==0) return movies[i].file;
      --choice;
   }
 return 0;
}
