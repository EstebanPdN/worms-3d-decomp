typedef unsigned int cc32b_u32;
extern "C" {
void fn_8020c5c0(void *);
void fn_8020c5c4(void *);
void fn_80341588(void *);
void *fn_803426b8(void *);
unsigned short *fn_80341884(void *);
void *fn_8020bf2c(void *, const char *);
void *fn_8020bdf4(void *,const char *,cc32b_u32);
char *fn_802ef198(const char *,int);
extern const char *lbl_80403f54[];
extern char lbl_803d9448[];
}
inline void cc32b_copy_base_802cc0ac(void *self) { fn_8020c5c0(self); }
struct Cc32bLineString_802cc0ac {
 char *text; cc32b_u32 opaque;
 Cc32bLineString_802cc0ac();
 Cc32bLineString_802cc0ac(const Cc32bLineString_802cc0ac &other) {
  cc32b_copy_base_802cc0ac(this); text=other.text; ++*fn_80341884(this);
 }
 ~Cc32bLineString_802cc0ac() { fn_8020c5c4(this); fn_80341588(this); }
 Cc32bLineString_802cc0ac operator+(const char *suffix) const {
  Cc32bLineString_802cc0ac result(*this); fn_8020bf2c(&result,suffix); return result;
 }
};
extern "C" void w3d_cc32b_append_lines_802cc0ac(Cc32bLineString_802cc0ac *output,const char *text,int prefix) {
 fn_8020bf2c(output,lbl_80403f54[prefix]);
 if(text) {
  if(!fn_802ef198(text,10)) fn_8020bf2c(output,text);
  else {
   const char *begin=text;
   char *newline=fn_802ef198(begin,10);
   while(newline) {
    if(newline==begin) {
     fn_8020bf2c(output,lbl_803d9448); ++begin;
     newline=fn_802ef198(begin,10);
    } else if(newline[-1]==13) {
     newline=fn_802ef198(newline+1,10);
    } else {
     Cc32bLineString_802cc0ac segment;
     const char *old=begin; begin=newline+1;
     fn_8020bdf4(&segment,old,newline-old);
     fn_8020bf2c(output,(segment+lbl_803d9448).text);
     newline=fn_802ef198(begin,10);
    }
   }
   fn_8020bf2c(output,begin);
  }
  fn_8020bf2c(output,lbl_80403f54[9]);
 }
}
