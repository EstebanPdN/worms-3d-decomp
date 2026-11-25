/* Newlib 1.10 multibyte decoder algorithm, adapted to observed PPC32
 * reentrancy locale +52 and external original JIS tables/string literals.
 * The table names and reentrancy semantics are inferred from vendor source.
 */
typedef unsigned int Cx9cWide;
struct Cx9cReent {unsigned char opaque[52];const char *_current_locale;};
extern "C" unsigned int cx9c_strlen_802ef9c0(const char *);
extern "C" int cx9c_strcmp_802ef234(const char *,const char *);
extern "C" const char cx9c_sjis_name_803db610[],cx9c_euc_name_803db618[],cx9c_jis_name_803db620[];
#define ESC_CHAR 0x1b
#define _issjis1(c) (((c)>=0x81&&(c)<=0x9f)||((c)>=0xe0&&(c)<=0xef))
#define _issjis2(c) (((c)>=0x40&&(c)<=0x7e)||((c)>=0x80&&(c)<=0xfc))
#define _iseucjp(c) ((c)>=0xa1&&(c)<=0xfe)
#define _isjis(c) ((c)>=0x21&&(c)<=0x7e)
typedef enum { ESCAPE, DOLLAR, BRACKET, AT, B, J, 
               NUL, JIS_CHAR, OTHER, JIS_C_NUM } JIS_CHAR_TYPE;
typedef enum { ASCII, A_ESC, A_ESC_DL, JIS, JIS_1, JIS_2, J_ESC, J_ESC_BR,
               J2_ESC, J2_ESC_BR, DONE, INV, JIS_S_NUM } JIS_STATE; 
typedef enum { COPY_A, COPY_J, COPY_J2, MAKE_A, MAKE_J, NOOP, EMPTY, ERROR } JIS_ACTION;


extern "C" JIS_STATE cx9c_jis_states_80404784[JIS_S_NUM][JIS_C_NUM];
extern "C" JIS_ACTION cx9c_jis_actions_80404934[JIS_S_NUM][JIS_C_NUM];
extern "C" int w3d_cx9c_multibyte_decode_802edb28(Cx9cReent *r,Cx9cWide *pwc,const char *s,unsigned int n,int *state)
{
  Cx9cWide dummy;
  unsigned char *t = (unsigned char *)s;

  if (pwc == 0)
    pwc = &dummy;

  if (s != 0 && n == 0)
    return -1;


  if (r->_current_locale == 0 ||
      (cx9c_strlen_802ef9c0 (r->_current_locale) <= 1))
    { /* fall-through */ }
  else if (!cx9c_strcmp_802ef234 (r->_current_locale, cx9c_sjis_name_803db610))
    {
      int char1 = *t;
      if (s == 0)
        return 0;  /* not state-dependent */
      if (_issjis1 (char1))
        {
          int char2 = t[1];
          if (n <= 1)
            return -1;
          if (_issjis2 (char2))
            {
              *pwc = (((Cx9cWide)*t) << 8) + (Cx9cWide)(*(t+1));
              return 2;
            }
          else  
            return -1;
        }
    }
  else if (!cx9c_strcmp_802ef234 (r->_current_locale, cx9c_euc_name_803db618))
    {
      int char1 = *t;
      if (s == 0)
        return 0;  /* not state-dependent */
      if (_iseucjp (char1))
        {
          int char2 = t[1];     
          if (n <= 1)
            return -1;
          if (_iseucjp (char2))
            {
              *pwc = (((Cx9cWide)*t) << 8) + (Cx9cWide)(*(t+1));
              return 2;
            }
          else
            return -1;
        }
    }
  else if (!cx9c_strcmp_802ef234 (r->_current_locale, cx9c_jis_name_803db620))
    {
      JIS_STATE curr_state;
      unsigned int action;
      JIS_CHAR_TYPE ch;
      unsigned char *ptr;
      int i, curr_ch;
 
      if (s == 0)
        {
          *state = 0;
          return 1;  /* state-dependent */
        }

      curr_state = (*state == 0 ? ASCII : JIS);
      ptr = t;

      for (i = 0; i < n; ++i)
        {
          curr_ch = t[i];
          switch (curr_ch)
            {
	    case ESC_CHAR:
              ch = ESCAPE;
              break;
	    case '$':
              ch = DOLLAR;
              break;
            case '@':
              ch = AT;
              break;
            case '(':
	      ch = BRACKET;
              break;
            case 'B':
              ch = B;
              break;
            case 'J':
              ch = J;
              break;
            case '\0':
              ch = NUL;
              break;
            default:
              if (_isjis (curr_ch))
                ch = JIS_CHAR;
              else
                ch = OTHER;
	    }

          action = cx9c_jis_actions_80404934[curr_state][ch];
          curr_state = cx9c_jis_states_80404784[curr_state][ch];
        
          switch (action)
            {
            case NOOP:
              break;
            case EMPTY:
              *state = 0;
              *pwc = (Cx9cWide)0;
              return i;
            case COPY_A:
	      *state = 0;
              *pwc = (Cx9cWide)*ptr;
              return (i + 1);
            case COPY_J:
              *state = 0;
              *pwc = (((Cx9cWide)*ptr) << 8) + (Cx9cWide)(*(ptr+1));
              return (i + 1);
            case COPY_J2:
              *state = 1;
              *pwc = (((Cx9cWide)*ptr) << 8) + (Cx9cWide)(*(ptr+1));
              return (ptr - t) + 2;
            case MAKE_A:
            case MAKE_J:
              ptr = (unsigned char *)(t + i + 1);
              break;
            case ERROR:
            default:
              return -1;
            }

        }

      return -1;  /* n < bytes needed */
    }
               

  /* otherwise this must be the "C" locale or unknown locale */
  if (s == 0)
    return 0;  /* not state-dependent */

  *pwc = (Cx9cWide)*t;
  
  if (*t == '\0')
    return 0;

  return 1;
}

