/* newlib 1.10.0 strcasecmp.c (Copyright (c) 1987 Regents of the University of California, BSD notice in
 * source/vendor/newlib-1.10.0). The ctype table stays external at its original address. */
#define __GNUC__ 2
#define __GNUC_MINOR__ 95
#define _ctype_ d24z_ctype_803db448
#include <string.h>
#include <ctype.h>
int w3d_d24z_strcasecmp_802ef074(const char *s1, const char *s2)
{
    while (*s1 != '\0' && tolower(*s1) == tolower(*s2)) {
        s1++;
        s2++;
    }
    return tolower(*(unsigned char *) s1) - tolower(*(unsigned char *) s2);
}
