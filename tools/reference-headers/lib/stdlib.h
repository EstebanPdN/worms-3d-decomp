#ifndef W3D_REFERENCE_LIBRARY_STDLIB_H
#define W3D_REFERENCE_LIBRARY_STDLIB_H
#include_next <stdlib.h>
/* Candidate only: never accept math_random without full native comparison. */
#ifndef RAND_MAX
#define RAND_MAX 32767
#endif
int rand(void);
void srand(unsigned int);
char *getenv(const char *);
#endif
