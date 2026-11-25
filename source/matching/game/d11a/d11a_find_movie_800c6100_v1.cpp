// Inferred movie-name lookup. Table records are twelve bytes, terminated by
// category 29 or an empty name. External records and strings remain unowned.
struct d11a_Movie { const char *name; unsigned category; const char *file; };
extern d11a_Movie d11a_pal_movies_803f5728[];
extern d11a_Movie d11a_ntsc_movies_803f58b4[];
extern const char d11a_movie_source_803876ac[], d11a_tv_error_803876c4[];
extern "C" unsigned d11a_tv_format_80304de0();
extern "C" unsigned d11a_strlen_802ef9c0(const char *);
extern "C" int d11a_compare_802ef074(const char *, const char *);
extern "C" void d11a_panic_802fb82c(const char *, int, const char *, ...);
inline unsigned d11a_search_movies(unsigned i, d11a_Movie *movies, const char *name) {
 for(;d11a_strlen_802ef9c0(movies[i].name) && movies[i].category!=29;++i)
   if(d11a_compare_802ef074(movies[i].name,name)==0) return movies[i].category;
 return 29;
}
extern "C" unsigned d11a_find_movie_800c6100(void *, const char *name)
{
 d11a_Movie *movies;
 switch(d11a_tv_format_80304de0()) {
 case 1: movies=d11a_pal_movies_803f5728; break;
 case 0: case 2: movies=d11a_ntsc_movies_803f58b4; break;
 default: d11a_panic_802fb82c(d11a_movie_source_803876ac,300,d11a_tv_error_803876c4); break;
 }
 return d11a_search_movies(0,movies,name);
}
