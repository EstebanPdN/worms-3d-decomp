#include "w3d_ptr.h"
#line 1 "s1_commentary.cpp"
/* Display text events and their observed string lifetimes. */
extern "C" {
struct W3dS1Text { Ptr32<char> text; };
struct W3dS1TextHeader { unsigned short references; };
struct W3dS1TextVector { Ptr32<W3dS1Text> begin; Ptr32<W3dS1Text> end; };
struct W3dS1TextDisplay { unsigned char unknown[0x48]; W3dS1TextVector strings; };
struct W3dS1TextActor { unsigned char unknown[0x8c]; Ptr32<const char> name; };
void w3d_string_base_init(Ptr32<W3dS1Text>);
void w3d_string_base_finish(Ptr32<W3dS1Text>);
void w3d_string_release(Ptr32<W3dS1Text>);
Ptr32<W3dS1TextHeader> w3d_string_header(Ptr32<W3dS1Text>);
Ptr32<void> w3d_string_default(Ptr32<W3dS1Text>);
Ptr32<void> w3d_string_from_text(Ptr32<W3dS1Text>,Ptr32<const char>);
void w3d_string_format(Ptr32<W3dS1Text>,Ptr32<const char>,...);
void w3d_fn_80043134(Ptr32<void>,Ptr32<W3dS1Text>,unsigned int);
void w3d_fn_800438d4(Ptr32<void>,unsigned int);
Ptr32<void> w3d_fn_800fc2b0(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<const char>>);
Ptr32<W3dS1TextActor> w3d_fn_800fc6dc(int);
unsigned int w3d_auto_8015ff5c(Ptr32<void>);
extern const char w3d_str_80374f78[],w3d_str_803763c0[];
static inline void copy_text(Ptr32<W3dS1Text> dest,Ptr32<const W3dS1Text> src)
{
    w3d_string_base_init(dest);dest->text=src->text;++w3d_string_header(dest)->references;
}
static inline void finish_text(Ptr32<W3dS1Text> text) { w3d_string_base_finish(text);w3d_string_release(text); }
static inline void clear_texts(Ptr32<W3dS1TextVector> v)
{
    Ptr32<W3dS1Text> first=v->begin; Ptr32<W3dS1Text> last=v->end; Ptr32<W3dS1Text> p=first;
    for(;p!=last;++p) finish_text(p);
    v->end=first;
}
Ptr32<char> w3d_find_802efd14(Ptr32<const char>,Ptr32<const char>);
extern const char w3d_str_80374f74[];
struct W3dS1PaddedText { W3dS1Text value; unsigned int unused; };
struct W3dS1Team { unsigned char unknown[0x1c]; W3dS1Text name; };
Ptr32<W3dS1Team> w3d_fn_800fc7f8(int);
unsigned int w3d_auto_80178c48(Ptr32<void>);
Ptr32<void> w3d_empty_803426b4(unsigned int);
unsigned int w3d_get_800a830c(Ptr32<void>);
struct W3dS1Actor { unsigned char unknown[0x8c]; W3dS1Text name; unsigned char unknown90[0xd5-0x90]; unsigned char team; unsigned char unknownd6[6]; int sick; };
void w3d_auto_80046228(Ptr32<void>,unsigned char);
Ptr32<void> w3d_string_release_header(Ptr32<void>);
static inline void assign_text(Ptr32<W3dS1Text> dest,Ptr32<const W3dS1Text> source)
{
    Ptr32<unsigned short> incoming=(Ptr32<unsigned short>)(source->text-6);
    ++*incoming;
    Ptr32<char> old=dest->text;
    Ptr32<unsigned short> header=(Ptr32<unsigned short>)(old-6);
    if (--*header==0) w3d_string_release_header(header);
    dest->text=source->text;
}
extern const char w3d_str_80374e48[];
extern const char w3d_str_80374e5c[];
extern const char w3d_str_80374e70[];
extern const char w3d_str_80374e84[];
extern const char w3d_str_80374e98[];
void w3d_fn_80044244(Ptr32<unsigned int> self,Ptr32<void> message)
{
    struct { W3dS1PaddedText name,formatted,argument; Ptr32<const char> key0; Ptr32<const char> format; Ptr32<const char> keys[4]; } local;
    if (!self[0xfc/4]) return;
    Ptr32<W3dS1Team> team=w3d_fn_800fc7f8((int)w3d::H(message));
    copy_text(&local.name.value,&team->name);
    switch(w3d_auto_8015ff5c(self)%5) {
    case 0: local.key0=w3d_str_80374e48;w3d_fn_800fc2b0(&local.key0,&local.format);break;
    case 1: local.keys[0]=w3d_str_80374e5c;w3d_fn_800fc2b0(&local.keys[0],&local.format);break;
    case 2: local.keys[1]=w3d_str_80374e70;w3d_fn_800fc2b0(&local.keys[1],&local.format);break;
    case 3: local.keys[2]=w3d_str_80374e84;w3d_fn_800fc2b0(&local.keys[2],&local.format);break;
    case 4: local.keys[3]=w3d_str_80374e98;w3d_fn_800fc2b0(&local.keys[3],&local.format);break;
    }
    w3d_string_default(&local.formatted.value);
    w3d_string_format(&local.formatted.value,local.format,w3d::VA(local.name.value.text));
    copy_text(&local.argument.value,&local.formatted.value);
    w3d_fn_80043134(self,&local.argument.value,0);
    finish_text(&local.formatted.value);
    finish_text(&local.name.value);
}
extern const char w3d_str_80374eac[];
extern const char w3d_str_80374ebc[];
extern const char w3d_str_80374ecc[];
extern const char w3d_str_80374edc[];
extern const char w3d_str_80374eec[];
extern const char w3d_str_80374efc[];
extern const char w3d_str_80374f0c[];
extern const char w3d_str_80374f1c[];
#if 0 /* 0x80044410: constructor argument setup differs in two instruction positions. */
void w3d_fn_80044410(unsigned int *self)
{
    struct { W3dS1PaddedText formatted,argument; const char *key0,*format; const char *keys[9]; } local;
    if (!self[0xfc/4]) return;
    switch(w3d_auto_8015ff5c(self)%10) {
    case 0: local.key0=w3d_str_80374eac;w3d_fn_800fc2b0(&local.key0,&local.format);break;
    case 1: local.keys[0]=w3d_str_80374ebc;w3d_fn_800fc2b0(&local.keys[0],&local.format);break;
    case 2: local.keys[1]=w3d_str_80374ebc;w3d_fn_800fc2b0(&local.keys[1],&local.format);break;
    case 3: local.keys[2]=w3d_str_80374ecc;w3d_fn_800fc2b0(&local.keys[2],&local.format);break;
    case 4: local.keys[3]=w3d_str_80374edc;w3d_fn_800fc2b0(&local.keys[3],&local.format);break;
    case 5: local.keys[4]=w3d_str_80374edc;w3d_fn_800fc2b0(&local.keys[4],&local.format);break;
    case 6: local.keys[5]=w3d_str_80374eec;w3d_fn_800fc2b0(&local.keys[5],&local.format);break;
    case 7: local.keys[6]=w3d_str_80374efc;w3d_fn_800fc2b0(&local.keys[6],&local.format);break;
    case 8: local.keys[7]=w3d_str_80374f0c;w3d_fn_800fc2b0(&local.keys[7],&local.format);break;
    case 9: local.keys[8]=w3d_str_80374f1c;w3d_fn_800fc2b0(&local.keys[8],&local.format);break;
    }
    w3d_string_from_text(&local.formatted.value,local.format);
    copy_text(&local.argument.value,&local.formatted.value);
    w3d_fn_80043134(self,&local.argument.value,0);
    finish_text(&local.formatted.value);
}
#endif
extern const char w3d_str_80374f8c[];
extern const char w3d_str_80374fa0[];
extern const char w3d_str_80374fb4[];
extern const char w3d_str_80374fc8[];
void w3d_fn_80044a80(Ptr32<unsigned int> self)
{
    struct { W3dS1PaddedText formatted,argument; Ptr32<const char> key0; Ptr32<const char> format; Ptr32<const char> keys[3]; } local;
    if (!self[0xfc/4]) return;
    switch(w3d_auto_8015ff5c(self)%4) {
    case 0: local.key0=w3d_str_80374f8c;w3d_fn_800fc2b0(&local.key0,&local.format);break;
    case 1: local.keys[0]=w3d_str_80374fa0;w3d_fn_800fc2b0(&local.keys[0],&local.format);break;
    case 2: local.keys[1]=w3d_str_80374fb4;w3d_fn_800fc2b0(&local.keys[1],&local.format);break;
    default: local.keys[2]=w3d_str_80374fc8;w3d_fn_800fc2b0(&local.keys[2],&local.format);break;
    }
    unsigned int index=w3d_auto_80178c48(w3d_empty_803426b4(self[0x80/4]));
    Ptr32<W3dS1TextActor> actor=w3d_fn_800fc6dc((int)w3d::H(((Ptr32<void>)w3d::G(index))));
    w3d_string_default(&local.formatted.value);
    w3d_string_format(&local.formatted.value,local.format,w3d::VA(actor->name));
    copy_text(&local.argument.value,&local.formatted.value);
    w3d_fn_80043134(self,&local.argument.value,0);
    finish_text(&local.formatted.value);
}
extern const char w3d_str_80374fdc[];
extern const char w3d_str_80374fec[];
extern const char w3d_str_80374ffc[];
extern const char w3d_str_8037500c[];
extern const char w3d_str_8037501c[];
extern const char w3d_str_8037502c[];
extern const char w3d_str_8037503c[];
extern const char w3d_str_8037504c[];
extern const char w3d_str_8037505c[];
extern const char w3d_str_8037506c[];
extern const char w3d_str_80375080[];
extern const char w3d_str_80375094[];
extern const char w3d_str_803750a8[];
extern const char w3d_str_803750bc[];
extern const char w3d_str_803750d0[];
extern const char w3d_str_803750e4[];
extern const char w3d_str_803750f8[];
extern const char w3d_str_8037510c[];
extern const char w3d_str_80375120[];
void w3d_fn_80044bc0(Ptr32<unsigned int> self)
{
    struct { W3dS1PaddedText argument; Ptr32<const char> key0; Ptr32<const char> format; Ptr32<const char> keys[18]; } local;
    if (!self[0xfc/4]) return;
    switch(w3d_auto_8015ff5c(self)%19) {
    case 0: local.key0=w3d_str_80374fdc;w3d_fn_800fc2b0(&local.key0,&local.format);break;
    case 1: local.keys[0]=w3d_str_80374fec;w3d_fn_800fc2b0(&local.keys[0],&local.format);break;
    case 2: local.keys[1]=w3d_str_80374ffc;w3d_fn_800fc2b0(&local.keys[1],&local.format);break;
    case 3: local.keys[2]=w3d_str_8037500c;w3d_fn_800fc2b0(&local.keys[2],&local.format);break;
    case 4: local.keys[3]=w3d_str_8037501c;w3d_fn_800fc2b0(&local.keys[3],&local.format);break;
    case 5: local.keys[4]=w3d_str_8037502c;w3d_fn_800fc2b0(&local.keys[4],&local.format);break;
    case 6: local.keys[5]=w3d_str_8037503c;w3d_fn_800fc2b0(&local.keys[5],&local.format);break;
    case 7: local.keys[6]=w3d_str_8037504c;w3d_fn_800fc2b0(&local.keys[6],&local.format);break;
    case 8: local.keys[7]=w3d_str_8037505c;w3d_fn_800fc2b0(&local.keys[7],&local.format);break;
    case 9: local.keys[8]=w3d_str_8037506c;w3d_fn_800fc2b0(&local.keys[8],&local.format);break;
    case 10: local.keys[9]=w3d_str_80375080;w3d_fn_800fc2b0(&local.keys[9],&local.format);break;
    case 11: local.keys[10]=w3d_str_80375094;w3d_fn_800fc2b0(&local.keys[10],&local.format);break;
    case 12: local.keys[11]=w3d_str_803750a8;w3d_fn_800fc2b0(&local.keys[11],&local.format);break;
    case 13: local.keys[12]=w3d_str_803750bc;w3d_fn_800fc2b0(&local.keys[12],&local.format);break;
    case 14: local.keys[13]=w3d_str_803750d0;w3d_fn_800fc2b0(&local.keys[13],&local.format);break;
    case 15: local.keys[14]=w3d_str_803750e4;w3d_fn_800fc2b0(&local.keys[14],&local.format);break;
    case 16: local.keys[15]=w3d_str_803750f8;w3d_fn_800fc2b0(&local.keys[15],&local.format);break;
    case 17: local.keys[16]=w3d_str_8037510c;w3d_fn_800fc2b0(&local.keys[16],&local.format);break;
    default: local.keys[17]=w3d_str_80375120;w3d_fn_800fc2b0(&local.keys[17],&local.format);break;
    }
    w3d_string_from_text(&local.argument.value,local.format);
    w3d_fn_80043134(self,&local.argument.value,0);
}
extern const char w3d_str_803752b0[];
extern const char w3d_str_803752c4[];
extern const char w3d_str_803752d8[];
extern const char w3d_str_803752ec[];
extern const char w3d_str_80375300[];
extern const char w3d_str_80375314[];
extern const char w3d_str_80375328[];
extern const char w3d_str_8037533c[];
extern const char w3d_str_80375350[];
extern const char w3d_str_80375364[];
extern const char w3d_str_8037537c[];
extern const char w3d_str_80375394[];
extern const char w3d_str_803753ac[];
extern const char w3d_str_803753c4[];
extern const char w3d_str_803753dc[];
extern const char w3d_str_803753f4[];
extern const char w3d_str_8037540c[];
void w3d_fn_8004527c(Ptr32<unsigned int> self)
{
    struct { W3dS1PaddedText formatted,argument; Ptr32<const char> key0; Ptr32<const char> format; Ptr32<const char> keys[16]; } local;
    if (!self[0xfc/4]) return;
    switch(w3d_auto_8015ff5c(self)%17) {
    case 0: local.key0=w3d_str_803752b0;w3d_fn_800fc2b0(&local.key0,&local.format);break;
    case 1: local.keys[0]=w3d_str_803752c4;w3d_fn_800fc2b0(&local.keys[0],&local.format);break;
    case 2: local.keys[1]=w3d_str_803752d8;w3d_fn_800fc2b0(&local.keys[1],&local.format);break;
    case 3: local.keys[2]=w3d_str_803752ec;w3d_fn_800fc2b0(&local.keys[2],&local.format);break;
    case 4: local.keys[3]=w3d_str_80375300;w3d_fn_800fc2b0(&local.keys[3],&local.format);break;
    case 5: local.keys[4]=w3d_str_80375314;w3d_fn_800fc2b0(&local.keys[4],&local.format);break;
    case 6: local.keys[5]=w3d_str_80375328;w3d_fn_800fc2b0(&local.keys[5],&local.format);break;
    case 7: local.keys[6]=w3d_str_8037533c;w3d_fn_800fc2b0(&local.keys[6],&local.format);break;
    case 8: local.keys[7]=w3d_str_80375350;w3d_fn_800fc2b0(&local.keys[7],&local.format);break;
    case 9: local.keys[8]=w3d_str_80375364;w3d_fn_800fc2b0(&local.keys[8],&local.format);break;
    case 10: local.keys[9]=w3d_str_8037537c;w3d_fn_800fc2b0(&local.keys[9],&local.format);break;
    case 11: local.keys[10]=w3d_str_80375394;w3d_fn_800fc2b0(&local.keys[10],&local.format);break;
    case 12: local.keys[11]=w3d_str_803753ac;w3d_fn_800fc2b0(&local.keys[11],&local.format);break;
    case 13: local.keys[12]=w3d_str_803753c4;w3d_fn_800fc2b0(&local.keys[12],&local.format);break;
    case 14: local.keys[13]=w3d_str_803753dc;w3d_fn_800fc2b0(&local.keys[13],&local.format);break;
    case 15: local.keys[14]=w3d_str_803753f4;w3d_fn_800fc2b0(&local.keys[14],&local.format);break;
    default: local.keys[15]=w3d_str_8037540c;w3d_fn_800fc2b0(&local.keys[15],&local.format);break;
    }
    unsigned int index=w3d_auto_80178c48(w3d_empty_803426b4(self[0x80/4]));
    if(index>=16) return;
    Ptr32<W3dS1TextActor> actor=w3d_fn_800fc6dc((int)w3d::H(((Ptr32<void>)w3d::G(index))));
    w3d_string_default(&local.formatted.value);
    w3d_string_format(&local.formatted.value,local.format,w3d::VA(actor->name));
    copy_text(&local.argument.value,&local.formatted.value);
    w3d_fn_80043134(self,&local.argument.value,0);
    finish_text(&local.formatted.value);
}
extern const char w3d_str_803757a8[];
extern const char w3d_str_803757c0[];
extern const char w3d_str_803757d8[];
extern const char w3d_str_803757f0[];
extern const char w3d_str_80375808[];
extern const char w3d_str_80375820[];
extern const char w3d_str_80375838[];
extern const char w3d_str_80375850[];
extern const char w3d_str_80375868[];
extern const char w3d_str_80375880[];
extern const char w3d_str_80375898[];
void w3d_fn_80045cb4(Ptr32<unsigned int> self,Ptr32<void> message)
{
    struct { W3dS1PaddedText name,formatted,argument; Ptr32<const char> key0; Ptr32<const char> format; Ptr32<const char> keys[10]; } local;
    ++self[0x100/4];
    if (!self[0xfc/4]) return;
    w3d_string_default(&local.name.value);
    unsigned int index=w3d_get_800a830c(message);
    Ptr32<W3dS1Actor> actor=(Ptr32<W3dS1Actor>)w3d_fn_800fc6dc((int)w3d::H(((Ptr32<void>)w3d::G(index))));
    assign_text(&local.name.value,&actor->name);
    int choice=w3d_auto_8015ff5c(self)%11;
    switch(choice) {
    case 0: local.key0=w3d_str_803757a8;w3d_fn_800fc2b0(&local.key0,&local.format);break;
    case 1: local.keys[0]=w3d_str_803757c0;w3d_fn_800fc2b0(&local.keys[0],&local.format);break;
    case 2: local.keys[1]=w3d_str_803757d8;w3d_fn_800fc2b0(&local.keys[1],&local.format);break;
    case 3: local.keys[2]=w3d_str_803757f0;w3d_fn_800fc2b0(&local.keys[2],&local.format);break;
    case 4: local.keys[3]=w3d_str_80375808;w3d_fn_800fc2b0(&local.keys[3],&local.format);break;
    case 5: local.keys[4]=w3d_str_80375820;w3d_fn_800fc2b0(&local.keys[4],&local.format);break;
    case 6: local.keys[5]=w3d_str_80375838;w3d_fn_800fc2b0(&local.keys[5],&local.format);break;
    case 7: local.keys[6]=w3d_str_80375850;w3d_fn_800fc2b0(&local.keys[6],&local.format);break;
    case 8: local.keys[7]=w3d_str_80375868;w3d_fn_800fc2b0(&local.keys[7],&local.format);break;
    case 9: local.keys[8]=w3d_str_80375880;w3d_fn_800fc2b0(&local.keys[8],&local.format);break;
    case 10: local.keys[9]=w3d_str_80375898;w3d_fn_800fc2b0(&local.keys[9],&local.format);break;
    }
    w3d_string_default(&local.formatted.value);
    w3d_string_format(&local.formatted.value,local.format,w3d::VA(local.name.value.text));
    copy_text(&local.argument.value,&local.formatted.value);
    w3d_fn_80043134(self,&local.argument.value,0);
    index=w3d_get_800a830c(message);
    actor=(Ptr32<W3dS1Actor>)w3d_fn_800fc6dc((int)w3d::H(((Ptr32<void>)w3d::G(index))));
    w3d_auto_80046228(self,actor->team);
    finish_text(&local.formatted.value);
    finish_text(&local.name.value);
}
extern const char w3d_str_803758b0[];
extern const char w3d_str_803758c4[];
extern const char w3d_str_803758d8[];
extern const char w3d_str_803758ec[];
extern const char w3d_str_80375900[];
extern const char w3d_str_80375914[];
extern const char w3d_str_80375928[];
extern const char w3d_str_8037593c[];
extern const char w3d_str_80375950[];
extern const char w3d_str_80375964[];
void w3d_fn_80045fa4(Ptr32<unsigned int> self,Ptr32<void> message)
{
    struct { W3dS1PaddedText name,formatted,argument; Ptr32<const char> key0; Ptr32<const char> format; Ptr32<const char> keys[9]; } local;
    if (!self[0xfc/4]) return;
    switch(w3d_auto_8015ff5c(self)%10) {
    case 0: local.key0=w3d_str_803758b0;w3d_fn_800fc2b0(&local.key0,&local.format);break;
    case 1: local.keys[0]=w3d_str_803758c4;w3d_fn_800fc2b0(&local.keys[0],&local.format);break;
    case 2: local.keys[1]=w3d_str_803758d8;w3d_fn_800fc2b0(&local.keys[1],&local.format);break;
    case 3: local.keys[2]=w3d_str_803758ec;w3d_fn_800fc2b0(&local.keys[2],&local.format);break;
    case 4: local.keys[3]=w3d_str_80375900;w3d_fn_800fc2b0(&local.keys[3],&local.format);break;
    case 5: local.keys[4]=w3d_str_80375914;w3d_fn_800fc2b0(&local.keys[4],&local.format);break;
    case 6: local.keys[5]=w3d_str_80375928;w3d_fn_800fc2b0(&local.keys[5],&local.format);break;
    case 7: local.keys[6]=w3d_str_8037593c;w3d_fn_800fc2b0(&local.keys[6],&local.format);break;
    case 8: local.keys[7]=w3d_str_80375950;w3d_fn_800fc2b0(&local.keys[7],&local.format);break;
    case 9: local.keys[8]=w3d_str_80375964;w3d_fn_800fc2b0(&local.keys[8],&local.format);break;
    }
    Ptr32<W3dS1Team> team=w3d_fn_800fc7f8((int)w3d::H(message));
    copy_text(&local.name.value,&team->name);
    w3d_string_default(&local.formatted.value);
    w3d_string_format(&local.formatted.value,local.format,w3d::VA(local.name.value.text));
    copy_text(&local.argument.value,&local.formatted.value);
    w3d_fn_80043134(self,&local.argument.value,0);
    finish_text(&local.formatted.value);
    finish_text(&local.name.value);
}
extern const char w3d_str_80375a08[];
extern const char w3d_str_80375a1c[];
extern const char w3d_str_80375a30[];
extern const char w3d_str_80375a44[];
extern const char w3d_str_80375a58[];
extern const char w3d_str_80375a6c[];
extern const char w3d_str_80375a80[];
extern const char w3d_str_80375a94[];
extern const char w3d_str_80375aa8[];
extern const char w3d_str_80375abc[];
extern const char w3d_str_80375ad0[];
extern const char w3d_str_80375ae4[];
extern const char w3d_str_80375af8[];
extern const char w3d_str_80375b0c[];
extern const char w3d_str_80375b20[];
extern const char w3d_str_80375b34[];
extern const char w3d_str_80375b48[];
void w3d_fn_80046408(Ptr32<unsigned int> self,Ptr32<void> message)
{
    struct { W3dS1PaddedText formatted,argument; Ptr32<const char> key0; Ptr32<const char> format; Ptr32<const char> keys[16]; } local;
    if (!self[0xfc/4]) return;
    unsigned int index=w3d_get_800a830c(message);
    if (index>=16) return;
    Ptr32<W3dS1Actor> actor=(Ptr32<W3dS1Actor>)w3d_fn_800fc6dc((int)w3d::H(((Ptr32<void>)w3d::G(index))));
    if (!actor->sick) return;
    switch(w3d_auto_8015ff5c(self)%17) {
    case 0: local.key0=w3d_str_80375a08;w3d_fn_800fc2b0(&local.key0,&local.format);break;
    case 1: local.keys[0]=w3d_str_80375a1c;w3d_fn_800fc2b0(&local.keys[0],&local.format);break;
    case 2: local.keys[1]=w3d_str_80375a30;w3d_fn_800fc2b0(&local.keys[1],&local.format);break;
    case 3: local.keys[2]=w3d_str_80375a44;w3d_fn_800fc2b0(&local.keys[2],&local.format);break;
    case 4: local.keys[3]=w3d_str_80375a58;w3d_fn_800fc2b0(&local.keys[3],&local.format);break;
    case 5: local.keys[4]=w3d_str_80375a6c;w3d_fn_800fc2b0(&local.keys[4],&local.format);break;
    case 6: local.keys[5]=w3d_str_80375a80;w3d_fn_800fc2b0(&local.keys[5],&local.format);break;
    case 7: local.keys[6]=w3d_str_80375a94;w3d_fn_800fc2b0(&local.keys[6],&local.format);break;
    case 8: local.keys[7]=w3d_str_80375aa8;w3d_fn_800fc2b0(&local.keys[7],&local.format);break;
    case 9: local.keys[8]=w3d_str_80375abc;w3d_fn_800fc2b0(&local.keys[8],&local.format);break;
    case 10: local.keys[9]=w3d_str_80375ad0;w3d_fn_800fc2b0(&local.keys[9],&local.format);break;
    case 11: local.keys[10]=w3d_str_80375ae4;w3d_fn_800fc2b0(&local.keys[10],&local.format);break;
    case 12: local.keys[11]=w3d_str_80375af8;w3d_fn_800fc2b0(&local.keys[11],&local.format);break;
    case 13: local.keys[12]=w3d_str_80375b0c;w3d_fn_800fc2b0(&local.keys[12],&local.format);break;
    case 14: local.keys[13]=w3d_str_80375b20;w3d_fn_800fc2b0(&local.keys[13],&local.format);break;
    case 15: local.keys[14]=w3d_str_80375b34;w3d_fn_800fc2b0(&local.keys[14],&local.format);break;
    case 16: local.keys[15]=w3d_str_80375b48;w3d_fn_800fc2b0(&local.keys[15],&local.format);break;
    }
    w3d_string_default(&local.formatted.value);
    w3d_string_format(&local.formatted.value,local.format,w3d::VA(actor->name.text));
    copy_text(&local.argument.value,&local.formatted.value);
    w3d_fn_80043134(self,&local.argument.value,0);
    finish_text(&local.formatted.value);
}
extern const char w3d_str_803762cc[];
extern const char w3d_str_803762e0[];
extern const char w3d_str_803762f4[];
extern const char w3d_str_80376308[];
extern const char w3d_str_8037631c[];
extern const char w3d_str_80376330[];
void w3d_fn_80047b6c(Ptr32<unsigned int> self)
{
    struct { W3dS1PaddedText formatted,argument; Ptr32<const char> key0; Ptr32<const char> format; Ptr32<const char> keys[5]; } local;
    local.format=0;
    switch(w3d_auto_8015ff5c(self)%6) {
    case 0: local.key0=w3d_str_803762cc;w3d_fn_800fc2b0(&local.key0,&local.format);break;
    case 1: local.keys[0]=w3d_str_803762e0;w3d_fn_800fc2b0(&local.keys[0],&local.format);break;
    case 2: local.keys[1]=w3d_str_803762f4;w3d_fn_800fc2b0(&local.keys[1],&local.format);break;
    case 3: local.keys[2]=w3d_str_80376308;w3d_fn_800fc2b0(&local.keys[2],&local.format);break;
    case 4: local.keys[3]=w3d_str_8037631c;w3d_fn_800fc2b0(&local.keys[3],&local.format);break;
    default: local.keys[4]=w3d_str_80376330;w3d_fn_800fc2b0(&local.keys[4],&local.format);break;
    }
    if (w3d_find_802efd14(local.format,w3d_str_80374f74)) {
    unsigned int index=w3d_auto_80178c48(w3d_empty_803426b4(self[0x80/4]));
    if(index>=16) return;
    Ptr32<W3dS1TextActor> actor=w3d_fn_800fc6dc((int)w3d::H(((Ptr32<void>)w3d::G(index))));
    w3d_string_default(&local.formatted.value);
    w3d_string_format(&local.formatted.value,local.format,w3d::VA(actor->name));
    copy_text(&local.argument.value,&local.formatted.value);
    w3d_fn_80043134(self,&local.argument.value,0);
    finish_text(&local.formatted.value);
    } else {
        w3d_string_from_text(&local.formatted.value,local.format);
        w3d_fn_80043134(self,&local.formatted.value,0);
    }
}
}


