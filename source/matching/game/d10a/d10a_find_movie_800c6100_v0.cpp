// Inferred movie-name lookup. Table records are twelve bytes, terminated by
// category 29 or an empty name. External records and strings remain unowned.
struct d10a_Movie { const char *name; unsigned category; const char *file; };
extern d10a_Movie d10a_pal_movies_803f5728[];
extern d10a_Movie d10a_ntsc_movies_803f58b4[];
extern const char d10a_movie_source_803876ac[], d10a_tv_error_803876c4[];
extern "C" unsigned d10a_tv_format_80304de0();
extern "C" unsigned d10a_strlen_802ef9c0(const char *);
extern "C" int d10a_compare_802ef074(const char *, const char *);
extern "C" void d10a_panic_802fb82c(const char *, int, const char *, ...);
extern "C" unsigned d10a_find_movie_800c6100(void *, const char *name)
{
 d10a_Movie *movies;
 switch(d10a_tv_format_80304de0()) {
 case 1: movies=d10a_pal_movies_803f5728; break;
 case 0: case 2: movies=d10a_ntsc_movies_803f58b4; break;
 default: d10a_panic_802fb82c(d10a_movie_source_803876ac,300,d10a_tv_error_803876c4); break;
 }
 for(unsigned i=0;d10a_strlen_802ef9c0(movies[i].name) && movies[i].category!=29;++i)
   if(d10a_compare_802ef074(movies[i].name,name)==0) return movies[i].category;
 return 29;
}
