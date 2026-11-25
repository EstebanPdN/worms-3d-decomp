/* SN ProDG's integer printf core: newlib 1.10.0 vfprintf.c built with INTEGER_ONLY and
 * 64-bit formats. SN replaced newlib's __sprint buffering: every PRINT either copies into
 * a string stream or goes through the console writer at 0x802f1be0, so there is no uio
 * vector and no error path. Names follow newlib; the FILE view is partial.
 * The notice of the upstream file, verbatim from newlib-1.10.0/newlib/libc/stdio/vfprintf.c, follows. */
/*-
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
typedef struct d40z_va {
    signed char gpr;     /* 0x00 */
    signed char fpr;     /* 0x01 */
    char *overflow;      /* 0x04 */
    char *save;          /* 0x08 */
} d40z_va, va_list[1];

/* SN's library va_arg, integer classes only here. The bounds test comes before alignment,
 * and each overflow branch fetches and advances on its own. */
#define va_arg(ap, TYPE) (*({ \
    TYPE *__p; \
    int __g = (ap)->gpr; \
    if ((unsigned)(__g + sizeof(TYPE) / 4) <= 8) { \
        if (sizeof(TYPE) == 8 && ((ap)->gpr & 1)) \
            (ap)->gpr++; \
        __p = (TYPE *)((ap)->save + (ap)->gpr * 4); \
        (ap)->gpr += sizeof(TYPE) / 4; \
    } else if (__g < 8) { \
        __p = (TYPE *)(ap)->overflow; \
        (ap)->gpr = 8; \
        (ap)->overflow = (char *)(__p + 1); \
    } else { \
        __p = (TYPE *)(ap)->overflow; \
        (ap)->overflow = (char *)(__p + 1); \
    } \
    __p; }))

typedef unsigned long u_long;
typedef unsigned short u_short;
typedef unsigned int u_int;
#define quad_t long long
#define u_quad_t unsigned long long
#define NULL 0

typedef struct d40z_file {
    unsigned char *_p;   /* 0x00 */
    int _r;              /* 0x04 */
    int _w;              /* 0x08 */
    union {
        struct {
            unsigned short _flags; /* 0x0c */
            short _file;           /* 0x0e */
        } s;
        int word;
    } u;
} d40z_file;

struct _reent;
extern struct _reent *w3d_sda_impure_ptr_804ac570;
extern int w3d_sda_mb_cur_max_804ac598;
extern const char xdigits_lower_803dbd68[], xdigits_upper_803dbd84[];
extern char null_text_803dbd7c[], bad_base_text_803dbd98[];
extern const char blanks_803dbd48[16], zeroes_803dbd58[16];

int w3d_cx9c_multibyte_decode_802edb28(struct _reent *r, int *pwc, const char *s, unsigned int n, int *state);
void *memchr(const void *s, int c, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);
unsigned int strlen(const char *s);
unsigned int w3d_vfiprintf_console_write_802f1be0(int fd, const void *data, unsigned int length, int flush);

#define is_digit(c) ((unsigned)to_digit(c) <= 9)
#define to_digit(c) ((c) - '0')
#define to_char(n) ((n) + '0')
#define BUF 40
#define ALT 0x001
#define HEXPREFIX 0x002
#define LADJUST 0x004
#define LONGINT 0x010
#define QUADINT 0x020
#define SHORTINT 0x040
#define ZEROPAD 0x080
#define PADSIZE 16

#define PRINT(ptr, len) { \
    if (fp->u.s._flags & 0x200) { \
        memcpy(fp->_p, (ptr), (len)); \
        fp->_p += (len); \
    } else { \
        if (fp->u.word == 0) \
            fp->u.s._file = 1; \
        w3d_vfiprintf_console_write_802f1be0(fp->u.s._file, (ptr), (len), 0); \
    } \
}
#define PAD(howmany, with) { \
    if ((n = (howmany)) > 0) { \
        while (n > PADSIZE) { \
            PRINT(with, PADSIZE); \
            n -= PADSIZE; \
        } \
        PRINT(with, n); \
    } \
}
#define SARG() \
    (flags&QUADINT ? va_arg(ap, quad_t) : \
        flags&LONGINT ? va_arg(ap, long) : \
        flags&SHORTINT ? (long)(short)va_arg(ap, int) : \
        (long)va_arg(ap, int))
#define UARG() \
    (flags&QUADINT ? va_arg(ap, u_quad_t) : \
        flags&LONGINT ? va_arg(ap, u_long) : \
        flags&SHORTINT ? (u_long)(u_short)va_arg(ap, int) : \
        (u_long)va_arg(ap, u_int))

int w3d_d40z_vfiprintf_r_802f1cf4(struct _reent *data, d40z_file *fp, const char *fmt0, d40z_va *ap)
{
    register char *fmt;
    register int ch;
    register int n, m;
    register char *cp;
    register int flags;
    int ret;
    int width;
    int prec;
    char sign;
    int wc;
    u_quad_t _uquad;
    enum { OCT, DEC, HEX } base;
    int dprec;
    int realsz;
    int size;
    const char *xdigs;
    char buf[BUF];
    char ox[2];
    int state = 0;

    fmt = (char *)fmt0;
    ret = 0;
    for (;;) {
        cp = fmt;
        while ((n = w3d_cx9c_multibyte_decode_802edb28(w3d_sda_impure_ptr_804ac570, &wc, fmt, w3d_sda_mb_cur_max_804ac598, &state)) > 0) {
            fmt += n;
            if (wc == '%') {
                fmt--;
                break;
            }
        }
        if ((m = fmt - cp) != 0) {
            PRINT(cp, m);
            ret += m;
        }
        if (n <= 0)
            goto done;
        fmt++;
        flags = 0;
        dprec = 0;
        width = 0;
        prec = -1;
        sign = '\0';
rflag:		ch = *fmt++;
reswitch:	switch (ch) {
		case ' ':
			if (!sign)
				sign = ' ';
			goto rflag;
		case '#':
			flags |= ALT;
			goto rflag;
		case '*':
			if ((width = va_arg(ap, int)) >= 0)
				goto rflag;
			width = -width;
		case '-':
			flags |= LADJUST;
			goto rflag;
		case '+':
			sign = '+';
			goto rflag;
		case '.':
			if ((ch = *fmt++) == '*') {
				n = va_arg(ap, int);
				prec = n < 0 ? -1 : n;
				goto rflag;
			}
			n = 0;
			while (is_digit(ch)) {
				n = 10 * n + to_digit(ch);
				ch = *fmt++;
			}
			prec = n < 0 ? -1 : n;
			goto reswitch;
		case '0':
			flags |= ZEROPAD;
			goto rflag;
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			n = 0;
			do {
				n = 10 * n + to_digit(ch);
				ch = *fmt++;
			} while (is_digit(ch));
			width = n;
			goto reswitch;
		case 'h':
			flags |= SHORTINT;
			goto rflag;
		case 'l':
			if (*fmt == 'l') {
				fmt++;
				flags |= QUADINT;
			} else {
				flags |= LONGINT;
			}
			goto rflag;
		case 'q':
			flags |= QUADINT;
			goto rflag;
		case 'c':
			*(cp = buf) = va_arg(ap, int);
			size = 1;
			sign = '\0';
			break;
		case 'D':
			flags |= LONGINT;
		case 'd':
		case 'i':
			_uquad = SARG();
			if ((quad_t)_uquad < 0)
			{
				_uquad = -_uquad;
				sign = '-';
			}
			base = DEC;
			goto number;
		case 'n':
			if (flags & QUADINT)
				*va_arg(ap, quad_t *) = ret;
			else 
			if (flags & LONGINT)
				*va_arg(ap, long *) = ret;
			else if (flags & SHORTINT)
				*va_arg(ap, short *) = ret;
			else
				*va_arg(ap, int *) = ret;
			continue;	
		case 'O':
			flags |= LONGINT;
		case 'o':
			_uquad = UARG();
			base = OCT;
			goto nosign;
		case 'p':
			_uquad = (u_long)va_arg(ap, void *);
			base = HEX;
			xdigs = xdigits_lower_803dbd68;
			flags |= HEXPREFIX;
			ch = 'x';
			goto nosign;
		case 's':
			if ((cp = va_arg(ap, char *)) == NULL)
				cp = null_text_803dbd7c;
			if (prec >= 0) {
				char *p = memchr(cp, 0, prec);
				if (p != NULL) {
					size = p - cp;
					if (size > prec)
						size = prec;
				} else
					size = prec;
			} else
				size = strlen(cp);
			sign = '\0';
			break;
		case 'U':
			flags |= LONGINT;
		case 'u':
			_uquad = UARG();
			base = DEC;
			goto nosign;
		case 'X':
			xdigs = xdigits_upper_803dbd84;
			goto hex;
		case 'x':
			xdigs = xdigits_lower_803dbd68;
hex:			_uquad = UARG();
			base = HEX;
			if (flags & ALT && _uquad != 0)
				flags |= HEXPREFIX;
nosign:			sign = '\0';
number:			if ((dprec = prec) >= 0)
				flags &= ~ZEROPAD;
			cp = buf + BUF;
			if (_uquad != 0 || prec != 0) {
				switch (base) {
				case OCT:
					do {
						*--cp = to_char(_uquad & 7);
						_uquad >>= 3;
					} while (_uquad);
					if (flags & ALT && *cp != '0')
						*--cp = '0';
					break;
				case DEC:
					while (_uquad >= 10) {
						*--cp = to_char(_uquad % 10);
						_uquad /= 10;
					}
					*--cp = to_char(_uquad);
					break;
				case HEX:
					do {
						*--cp = xdigs[_uquad & 15];
						_uquad >>= 4;
					} while (_uquad);
					break;
				default:
					cp = bad_base_text_803dbd98;
					size = strlen(cp);
					goto skipsize;
				}
			}
			size = buf + BUF - cp;
		skipsize:
			break;
		default:	
			if (ch == '\0')
				goto done;
			cp = buf;
			*cp = ch;
			size = 1;
			sign = '\0';
			break;
		}
		realsz = dprec > size ? dprec : size;
		if (sign)
			realsz++;
		else if (flags & HEXPREFIX)
			realsz+= 2;
		if ((flags & (LADJUST|ZEROPAD)) == 0)
			PAD(width - realsz, blanks_803dbd48);
		if (sign) {
			PRINT(&sign, 1);
		} else if (flags & HEXPREFIX) {
			*(unsigned short *)ox = 0x3000 | (unsigned char)ch;
			PRINT(ox, 2);
		}
		if ((flags & (LADJUST|ZEROPAD)) == ZEROPAD)
			PAD(width - realsz, zeroes_803dbd58);
		PAD(dprec - size, zeroes_803dbd58);
		PRINT(cp, size);
		if (flags & LADJUST)
			PAD(width - realsz, blanks_803dbd48);
		ret += width > realsz ? width : realsz;
	}
done:
    if (!(fp->u.s._flags & 0x200))
        w3d_vfiprintf_console_write_802f1be0(fp->u.s._file, 0, 0, 1);
    return ret;
}
