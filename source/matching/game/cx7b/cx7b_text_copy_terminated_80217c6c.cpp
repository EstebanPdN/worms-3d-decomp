// Observed three arguments: destination, source, and a char terminator.
extern "C" unsigned int strlen(const char *);
extern "C" void *memcpy(void *,const void *,unsigned int);
extern "C" char *w3d_cx7b_text_copy_terminated_80217c6c(char *destination,const char *source,int terminator) {
 unsigned int size=strlen(source); memcpy(destination,source,size);
 destination+=size; *destination=terminator;
 if((signed char)terminator) ++destination;
 return destination;
}

