/* SN ProDG's strtod: John Ousterhout's public strtod (tcl/compat/strtod.c) in single precision,
 * with a float powers-of-ten table. atof 0x802ed878 calls it. Names follow that source.
 *
 * Notice of the upstream file (strtod.c 1.7 94/12/17, as shipped in STk-2.2.0/Tcl/compat):
 *
 * Copyright (c) 1988-1993 The Regents of the University of California.
 * Copyright (c) 1994 Sun Microsystems, Inc.
 *
 * See the file "license.terms" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * That file's text, from the same tree (STk-2.2.0/Tcl/license.terms), verbatim:
 *
 * This software is copyrighted by the Regents of the University of
 * California, Sun Microsystems, Inc., and other parties.  The following
 * terms apply to all files associated with the software unless explicitly
 * disclaimed in individual files.
 *
 * The authors hereby grant permission to use, copy, modify, distribute,
 * and license this software and its documentation for any purpose, provided
 * that existing copyright notices are retained in all copies and that this
 * notice is included verbatim in any distributions. No written agreement,
 * license, or royalty fee is required for any of the authorized uses.
 * Modifications to this software may be copyrighted by their authors
 * and need not follow the licensing terms described here, provided that
 * the new terms are clearly indicated on the first page of each file where
 * they apply.
 *
 * IN NO EVENT SHALL THE AUTHORS OR DISTRIBUTORS BE LIABLE TO ANY PARTY
 * FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
 * ARISING OUT OF THE USE OF THIS SOFTWARE, ITS DOCUMENTATION, OR ANY
 * DERIVATIVES THEREOF, EVEN IF THE AUTHORS HAVE BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * THE AUTHORS AND DISTRIBUTORS SPECIFICALLY DISCLAIM ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.  THIS SOFTWARE
 * IS PROVIDED ON AN "AS IS" BASIS, AND THE AUTHORS AND DISTRIBUTORS HAVE
 * NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR
 * MODIFICATIONS.
 *
 * RESTRICTED RIGHTS: Use, duplication or disclosure by the government
 * is subject to the restrictions as set forth in subparagraph (c) (1) (ii)
 * of the Rights in Technical Data and Computer Software Clause as DFARS
 * 252.227-7013 and FAR 52.227-19.
 */
#define UCHAR(c) ((unsigned char)(c))
extern int w3d_sda_max_exponent_804ac57c;
extern float powers_of_10_80404ae4[];
extern int *w3d_heap_errno_802eafc4(void);
int isspace();
int isdigit();

float w3d_d40z_strtod_802ee800(const char *string, char **endPtr)
{
    int sign, expSign = 0;
    float fraction, dblExp, *d;
    const char *p;
    int c;
    int exp = 0;
    int fracExp = 0;
    int mantSize;
    int decPt;
    const char *pExp;

    p = string;
    while (isspace(UCHAR(*p)))
        p += 1;
    if (*p == '-') {
        sign = 1;
        p += 1;
    } else {
        if (*p == '+')
            p += 1;
        sign = 0;
    }
    decPt = -1;
    for (mantSize = 0; ; mantSize += 1) {
        c = *p;
        if (!isdigit(c)) {
            if ((c != '.') || (decPt >= 0))
                break;
            decPt = mantSize;
        }
        p += 1;
    }
    pExp = p;
    p -= mantSize;
    if (decPt < 0)
        decPt = mantSize;
    else
        mantSize -= 1;
    if (mantSize > 18) {
        fracExp = decPt - 18;
        mantSize = 18;
    } else
        fracExp = decPt - mantSize;
    if (mantSize == 0) {
        fraction = 0.0f;
        p = string;
        goto done;
    } else {
        int frac1, frac2;
        frac1 = 0;
        for (; mantSize > 9; mantSize -= 1) {
            c = *p;
            p += 1;
            if (c == '.') {
                c = *p;
                p += 1;
            }
            frac1 = 10 * frac1 + (c - '0');
        }
        frac2 = 0;
        for (; mantSize > 0; mantSize -= 1) {
            c = *p;
            p += 1;
            if (c == '.') {
                c = *p;
                p += 1;
            }
            frac2 = 10 * frac2 + (c - '0');
        }
        fraction = (1.0e9 * frac1) + frac2;
    }
    p = pExp;
    if ((*p == 'E') || (*p == 'e')) {
        p += 1;
        if (*p == '-') {
            expSign = 1;
            p += 1;
        } else {
            if (*p == '+')
                p += 1;
            expSign = 0;
        }
        if (!isdigit(UCHAR(*p))) {
            p = pExp;
            goto done;
        }
        while (isdigit(UCHAR(*p))) {
            exp = exp * 10 + (*p - '0');
            p += 1;
        }
    }
    if (expSign)
        exp = fracExp - exp;
    else
        exp = fracExp + exp;
    if (exp < 0) {
        expSign = 1;
        exp = -exp;
    } else
        expSign = 0;
    if (exp > w3d_sda_max_exponent_804ac57c) {
        exp = w3d_sda_max_exponent_804ac57c;
        *w3d_heap_errno_802eafc4() = 34;
    }
    dblExp = 1.0f;
    for (d = powers_of_10_80404ae4; exp != 0; exp >>= 1, d += 1) {
        if (exp & 01)
            dblExp *= *d;
    }
    if (expSign)
        fraction /= dblExp;
    else
        fraction *= dblExp;
done:
    if (endPtr != 0)
        *endPtr = (char *)p;
    if (sign)
        return -fraction;
    return fraction;
}
