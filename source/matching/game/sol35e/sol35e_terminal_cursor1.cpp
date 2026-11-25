// Terminal editing/filtering inferred from control bytes. Preserve the
// original behavior for unrecognized 0xff sequences: the cursor does not advance.
extern int sol35e_filter_enabled_804abce4;
extern "C" char *sol35e_strchr_802ef198(const char *,int);
extern "C" unsigned sol35e_strlen_802ef9c0(const char *);
extern "C" void *sol35e_memmove_802eeef4(void *,const void *,unsigned);
extern "C" void sol35e_filter_terminal_802cc3d0(char *text) {
 if(sol35e_filter_enabled_804abce4) {
  char *cursor=text;
  while((cursor=sol35e_strchr_802ef198(cursor,8))!=0) {
   if(cursor==text) {unsigned length=sol35e_strlen_802ef9c0(text);sol35e_memmove_802eeef4(text,text+1,length);}
   else {char *destination=cursor-1;char *old=cursor++;unsigned length=sol35e_strlen_802ef9c0(old);sol35e_memmove_802eeef4(destination,cursor,length);}
   cursor=text;
  }
  cursor=sol35e_strchr_802ef198(text,255);
  while(cursor) {
   switch((unsigned char)cursor[1]) {
   case 251: case 252: case 253: case 254:
    sol35e_memmove_802eeef4(cursor,cursor+3,sol35e_strlen_802ef9c0(cursor+2));
    cursor=sol35e_strchr_802ef198(text,255);
    break;
   case 250: {
    char *end=sol35e_strchr_802ef198(cursor,240);
    char *next=end+1;
    sol35e_memmove_802eeef4(cursor,next,sol35e_strlen_802ef9c0(end));
    cursor=sol35e_strchr_802ef198(next,255);
    break;
   }
   }
  }
 }
}
