/* Local data-console rendering, resource ownership, and key dispatch. */
extern "C" {
struct W3dS1ConsoleText { char *text; };
struct W3dS1ConsoleLocalText { W3dS1ConsoleText value;unsigned int gap; };
struct W3dS1ConsoleRef;
struct W3dS1ConsoleVtable { void (*unused[4])();void (*release)(W3dS1ConsoleRef *); };
struct W3dS1ConsoleRef { W3dS1ConsoleVtable *vtable; };
struct W3dS1ConsoleVector { unsigned int count,capacity;W3dS1ConsoleRef **data; };
extern unsigned char w3d_vtable_8040eae0[];
extern unsigned int *w3d_console_804aaa04;
extern const char w3d_options_803f3ff4[],w3d_str_80377f70[],w3d_str_80377f98[],w3d_str_80377fdc[],w3d_str_80377fe0[],w3d_str_80377fe8[],w3d_str_80378020[],w3d_str_80378064[],w3d_str_803780b4[],w3d_str_803780d4[],w3d_str_803780f4[];
extern const char *w3d_help_803f3f7c[],*w3d_border_803f3fc4[],*w3d_banks_803fcc90[];
extern const char *w3d_keys_804aa9fc;
void w3d_ctor_801628b0(void *);
void w3d_service_destroy_801628ec(void *,int);
void w3d_fn_802109dc(W3dS1ConsoleVector *);
void w3d_fn_80210abc(W3dS1ConsoleVector *,int);
void w3d_task_deferred_clear(W3dS1ConsoleVector *);
void w3d_fn_80210b90(W3dS1ConsoleVector *,unsigned int);
void w3d_string_default(W3dS1ConsoleText *);
void w3d_string_base_finish(W3dS1ConsoleText *);
void w3d_string_release(W3dS1ConsoleText *);
void w3d_string_format(W3dS1ConsoleText *,const char *,...);
void w3d_fn_802cc0ac(W3dS1ConsoleText *,const char *,int);
void w3d_fn_802cbf2c(W3dS1ConsoleText *,const char *,int);
void w3d_fn_802cbdf8(unsigned int,const char *,int);
void w3d_fn_802cd14c(unsigned int);
void w3d_fn_802cd07c(unsigned int);
void w3d_fn_802cd26c(W3dS1ConsoleText *,int,int);
void w3d_fn_802cd220(W3dS1ConsoleText *);
void w3d_fn_802cd128(W3dS1ConsoleText *);
void w3d_fn_802cc4f0(unsigned int);
int w3d_fn_802ccb40(unsigned int);
void w3d_fn_802cd2e0(unsigned int,int);
int w3d_fn_802cbacc(unsigned int);
int w3d_fn_802cba50(unsigned int);
unsigned int w3d_fn_802cbc68(unsigned int);
unsigned int w3d_fn_802cbb5c(unsigned int);
void w3d_empty_80050978(unsigned int *,unsigned int);
int w3d_auto_8016293c(unsigned int *,unsigned short *);
unsigned int w3d_fn_800fc668(void);
int w3d_fn_800fc69c(unsigned int *,W3dS1ConsoleRef **);
void w3d_fn_800fd4c8(unsigned char,unsigned int);
void w3d_fn_8020bbec(W3dS1ConsoleText *,char *,unsigned int,unsigned int);
void w3d_fn_8020c2e8(W3dS1ConsoleText *);
char *strchr(const char *,int);
char *strcpy(char *,const char *);
int strcmp(const char *,const char *);
void w3d_qsort_802ede44(void *,unsigned int,unsigned int,int (*)(const void *,const void *));
void w3d_fn_8004fd6c(unsigned int *);
void w3d_fn_8004fda4(unsigned int *);
void w3d_fn_8004fe48(unsigned int *);
void w3d_fn_8004ff24(unsigned int *);
void w3d_fn_80050534(unsigned int *);
void w3d_fn_80050620(unsigned int *);
void w3d_fn_800506a8(unsigned int *);
void w3d_fn_80050730(unsigned int *);
void w3d_fn_800507b8(unsigned int *,int);
void w3d_fn_8005097c(unsigned int *);
void w3d_fn_80050aa0(unsigned int *);
void w3d_fn_80050c20(unsigned int *);
void w3d_fn_80051234(unsigned int *,int);
static inline void console_finish(W3dS1ConsoleText *text) { w3d_string_base_finish(text);w3d_string_release(text); }
static inline void console_release(W3dS1ConsoleRef *ref) { if(ref)ref->vtable->release(ref); }
static inline void console_clear(W3dS1ConsoleVector *v) {
    W3dS1ConsoleRef **p=v->data;
    while(p!=v->data+v->count) {console_release(*p);*p=0;++p;}
}
#if 0 /* Remaining local-address CSE, argument scheduling, or register allocation differences. */
unsigned int *w3d_fn_8004f9f4(unsigned int *self)
{
    W3dS1ConsoleLocalText local;
    w3d_ctor_801628b0(self);self[0]=(unsigned int)w3d_vtable_8040eae0;
    w3d_fn_802109dc((W3dS1ConsoleVector *)(self+11));
    w3d_console_804aaa04=self;self[9]=0;self[14]=2;self[8]=0;
    w3d_string_default(&local.value);
    { extern const char w3d_str_80377ec0[]; w3d_fn_802cc0ac(&local.value,w3d_str_80377ec0,9); }
    { extern const char w3d_str_80377ecc[]; w3d_fn_802cc0ac(&local.value,w3d_str_80377ecc,7); }
    { extern const char w3d_str_80377ed0[]; w3d_fn_802cc0ac(&local.value,w3d_str_80377ed0,9); }
    { extern const char w3d_str_80377edc[]; w3d_fn_802cc0ac(&local.value,w3d_str_80377edc,7); }
    { extern const char w3d_str_80377ee0[]; w3d_fn_802cc0ac(&local.value,w3d_str_80377ee0,9); }
    { extern const char w3d_str_80377ef0[]; w3d_fn_802cc0ac(&local.value,w3d_str_80377ef0,7); }
    { extern const char w3d_str_80377ef4[]; w3d_fn_802cc0ac(&local.value,w3d_str_80377ef4,9); }
    { extern const char w3d_str_80377f00[]; w3d_fn_802cc0ac(&local.value,w3d_str_80377f00,7); }
    { extern const char w3d_str_80377f04[]; w3d_fn_802cc0ac(&local.value,w3d_str_80377f04,9); }
    { extern const char w3d_str_80377f0c[]; w3d_fn_802cc0ac(&local.value,w3d_str_80377f0c,7); }
    { extern const char w3d_str_80377f10[]; w3d_fn_802cc0ac(&local.value,w3d_str_80377f10,9); }
    { extern const char w3d_str_80377f1c[]; w3d_fn_802cc0ac(&local.value,w3d_str_80377f1c,7); }
    { extern const char w3d_str_80377f20[]; w3d_fn_802cc0ac(&local.value,w3d_str_80377f20,9); }
    { extern const char w3d_str_80377f28[]; w3d_fn_802cc0ac(&local.value,w3d_str_80377f28,7); }
    { extern const char w3d_str_80377f2c[]; w3d_fn_802cc0ac(&local.value,w3d_str_80377f2c,9); }
    strcpy((char *)w3d_options_803f3ff4,local.value.text);console_finish(&local.value);return self;
}
#endif
#if 0 /* Remaining local-address CSE, argument scheduling, or register allocation differences. */
void w3d_fn_8004fba8(unsigned int *self,int flags)
{
    self[0]=(unsigned int)w3d_vtable_8040eae0;
    console_clear((W3dS1ConsoleVector *)(self+11));
    w3d_console_804aaa04=0;w3d_fn_80210abc((W3dS1ConsoleVector *)(self+11),2);w3d_service_destroy_801628ec(self,flags);
}
#endif
int w3d_fn_8004fc60(unsigned int *self,unsigned short *message)
{
    if(*message==64) {
        if(w3d_auto_8016293c(self,message)>=0) {w3d_fn_8004fd6c(self);return 0;}return 0x80004005;
    }
    return w3d_auto_8016293c(self,message);
}
int w3d_fn_8004fcc4(unsigned int *self)
{
    if(w3d_fn_802ccb40(self[7])) {w3d_fn_802cd2e0(self[7],0);w3d_fn_8004fda4(self);}
    if(!self[8]) {if(w3d_fn_802cbacc(self[7]))w3d_fn_800507b8(self,(unsigned char)w3d_fn_802cbc68(self[7]));}
    else if(w3d_fn_802cba50(self[7]))w3d_empty_80050978(self,w3d_fn_802cbb5c(self[7]));
    return 100;
}
#if 0 /* Remaining local-address CSE, argument scheduling, or register allocation differences. */
void w3d_fn_8004fda4(unsigned int *self)
{
    W3dS1ConsoleLocalText local;
    w3d_fn_802cd14c(self[7]);w3d_fn_802cd07c(self[7]);w3d_string_default(&local.value);
    const char **p=w3d_help_803f3f7c;
    while(*p) {w3d_fn_802cbf2c(&local.value,*p,7);++p;}
    w3d_fn_802cbdf8(self[7],local.value.text,9);self[8]=0;self[9]=0;console_finish(&local.value);
}
#endif
#if 0 /* Remaining local-address CSE, argument scheduling, or register allocation differences. */
void w3d_fn_8004fe48(unsigned int *self)
{
    W3dS1ConsoleLocalText local;
    w3d_fn_802cd14c(self[7]);w3d_fn_802cd07c(self[7]);w3d_string_default(&local.value);
    w3d_fn_802cbf2c(&local.value,w3d_border_803f3fc4[0],2);w3d_fn_802cbf2c(&local.value,w3d_border_803f3fc4[1],2);
    for(unsigned int i=0;i<20;++i)w3d_fn_802cbf2c(&local.value,w3d_border_803f3fc4[2],2);
    w3d_fn_802cbdf8(self[7],local.value.text,9);w3d_fn_80050534(self);
    self[9]=1;self[8]=0;self[10]=0;w3d_fn_8004ff24(self);w3d_fn_80050620(self);console_finish(&local.value);
}
#endif
int w3d_fn_800504d0(const void *left,const void *right)
{
    W3dS1ConsoleRef *a=*(W3dS1ConsoleRef **)left;
    const char *first=((const char *(*)(W3dS1ConsoleRef *))(*(void ***)a)[8])(a);
    W3dS1ConsoleRef *b=*(W3dS1ConsoleRef **)right;
    const char *second=((const char *(*)(W3dS1ConsoleRef *))(*(void ***)b)[8])(b);
    return strcmp(first,second);
}
#if 0 /* Remaining local-address CSE, argument scheduling, or register allocation differences. */
void w3d_fn_80050534(unsigned int *self)
{
    struct { unsigned int iterator;int gap; } local;
    console_clear((W3dS1ConsoleVector *)(self+11));
    W3dS1ConsoleVector *list=(W3dS1ConsoleVector *)(self+11);
    w3d_task_deferred_clear(list);w3d_fn_80210b90(list,w3d_fn_800fc668());local.iterator=0;
    int index=-1;
    do {++index;}while(w3d_fn_800fc69c(&local.iterator,list->data+index));
    w3d_qsort_802ede44(list->data,list->count,4,w3d_fn_800504d0);
}
#endif
#if 0 /* Remaining local-address CSE, argument scheduling, or register allocation differences. */
void w3d_fn_80050620(unsigned int *self)
{
    W3dS1ConsoleLocalText local;w3d_string_default(&local.value);
    w3d_fn_802cd26c(&local.value,0,24);w3d_fn_802cc0ac(&local.value,w3d_options_803f3ff4,9);w3d_fn_802cd26c(&local.value,0,24);
    w3d_fn_802cbdf8(self[7],local.value.text,9);console_finish(&local.value);
}
#endif
#if 0 /* Remaining local-address CSE, argument scheduling, or register allocation differences. */
void w3d_fn_800506a8(unsigned int *self)
{
    W3dS1ConsoleLocalText local;w3d_string_default(&local.value);w3d_fn_802cd220(&local.value);w3d_fn_802cd128(&local.value);
    w3d_fn_802cbf2c(&local.value,w3d_str_80377f70,9);w3d_fn_802cbdf8(self[7],local.value.text,9);self[8]=0;self[9]=2;console_finish(&local.value);
}
#endif
#if 0 /* Remaining local-address CSE, argument scheduling, or register allocation differences. */
void w3d_fn_80050730(unsigned int *self)
{
    W3dS1ConsoleLocalText local;w3d_string_default(&local.value);w3d_fn_802cd220(&local.value);w3d_fn_802cd128(&local.value);
    w3d_fn_802cbf2c(&local.value,w3d_str_80377f70,9);w3d_fn_802cbdf8(self[7],local.value.text,9);self[8]=0;self[9]=3;console_finish(&local.value);
}
#endif
#if 0 /* Remaining local-address CSE, argument scheduling, or register allocation differences. */
void w3d_fn_800507b8(unsigned int *self,int key)
{
    switch((int)self[9]) {
    case 1:
        switch(key) {
        case 'N':case 'n': {unsigned int page=self[10]+1;if(page*20<self[11]) {self[10]=page;w3d_fn_8004ff24(self);}break;}
        case 'P':case 'p':if(self[10]) {--self[10];w3d_fn_8004ff24(self);}break;
        case '?':case '/':w3d_fn_800506a8(self);return;
        case 'F':case 'f':w3d_fn_80050730(self);return;
        case 'R':case 'r':w3d_fn_80050534(self);w3d_fn_8004ff24(self);break;
        case 'S':case 's':w3d_fn_8005097c(self);return;
        case 'L':case 'l':w3d_fn_80050aa0(self);return;
        }
        w3d_fn_80050620(self);break;
    case 0:case 2:case 3:w3d_fn_8004fe48(self);break;
    case 5:w3d_fn_80050c20(self);break;
    case 4:w3d_fn_80051234(self,key);break;
    }
}
#endif
#if 0 /* Remaining local-address CSE, argument scheduling, or register allocation differences. */
void w3d_fn_8005097c(unsigned int *self)
{
    W3dS1ConsoleLocalText text,row;
    w3d_string_default(&text.value);w3d_fn_802cd220(&text.value);w3d_fn_802cd128(&text.value);
    w3d_fn_802cbf2c(&text.value,w3d_str_80377f98,7);w3d_fn_802cbf2c(&text.value,w3d_str_80377fdc,9);
    const char **bank=w3d_banks_803fcc90;
    for(unsigned int i=0;i<14;++i,++bank) {
        w3d_string_default(&row.value);w3d_string_format(&row.value,w3d_str_80377fe0,(int)(signed char)w3d_keys_804aa9fc[i],*bank);
        w3d_fn_802cbf2c(&text.value,row.value.text,9);console_finish(&row.value);
    }
    w3d_fn_802cd26c(&text.value,0,24);w3d_fn_802cc0ac(&text.value,w3d_str_80377fe8,7);
    w3d_fn_802cbdf8(self[7],text.value.text,9);self[9]=5;console_finish(&text.value);
}
#endif
#if 0 /* Remaining local-address CSE, argument scheduling, or register allocation differences. */
void w3d_fn_80050aa0(unsigned int *self)
{
    W3dS1ConsoleLocalText text,row;
    w3d_string_default(&text.value);w3d_fn_802cd220(&text.value);w3d_fn_802cd128(&text.value);
    w3d_fn_802cbf2c(&text.value,w3d_str_80378020,1);w3d_fn_802cbf2c(&text.value,w3d_str_80377fdc,9);
    const char **bank=w3d_banks_803fcc90;
    for(unsigned int i=0;i<14;++i,++bank) {
        w3d_string_default(&row.value);w3d_string_format(&row.value,w3d_str_80377fe0,(int)(signed char)w3d_keys_804aa9fc[i],*bank);
        w3d_fn_802cbf2c(&text.value,row.value.text,9);console_finish(&row.value);
    }
    w3d_fn_802cd26c(&text.value,0,23);w3d_fn_802cbf2c(&text.value,w3d_str_80378064,1);
    switch((int)self[14]) {
    case 1:w3d_fn_802cc0ac(&text.value,w3d_str_803780b4,9);break;
    case 2:w3d_fn_802cc0ac(&text.value,w3d_str_803780d4,9);break;
    default:w3d_fn_802cc0ac(&text.value,w3d_str_803780f4,9);self[14]=2;break;
    }
    w3d_fn_802cbdf8(self[7],text.value.text,9);self[9]=4;console_finish(&text.value);
}
#endif
#if 0 /* Remaining local-address CSE, argument scheduling, or register allocation differences. */
void w3d_fn_80051234(unsigned int *self,int key)
{
    struct { char input;char gap[7];W3dS1ConsoleLocalText text; } local;
    local.input=key;
    switch(key) {
    case 32:for(unsigned int i=0;i<14;++i)w3d_fn_800fd4c8((unsigned char)i,self[14]);
    case 27:w3d_fn_8004fe48(self);break;
    case 10:self[14]=self[14]==2?1:2;w3d_fn_80050aa0(self);break;
    default:
        w3d_fn_8020bbec(&local.text.value,&local.input,0,1);w3d_fn_8020c2e8(&local.text.value);
        char *found=strchr(w3d_keys_804aa9fc,(signed char)local.text.value.text[0]);
        if(!found) {console_finish(&local.text.value);return;}
        unsigned int index=found-w3d_keys_804aa9fc;
        if(index<14) {w3d_fn_800fd4c8((unsigned char)index,self[14]);w3d_fn_8004fe48(self);}
        console_finish(&local.text.value);
    }
}
#endif
}
