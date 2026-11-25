extern "C" {
struct S4CardText { unsigned char pad[972]; const char *mode,*slot,*blocks; };
int w3d_text_format_80343b0c(char *,const char *,...);
char *strcpy(char *,const char *);
unsigned int strlen(const char *);
char *strstr(const char *,const char *);
void *memcpy(void *,const void *,unsigned int,...);
void w3d_s4_card_replace_marker(void *,char *,const char *,const char *,const char *);
extern const char w3d_str_803cfacc[],w3d_str_803cfae0[],w3d_str_803cfaf0[];
void w3d_s4_card_format_text(S4CardText *self,char *output,const char *format)
{
    char storage[128]; register char *text=storage; text[0]=0;
    w3d_text_format_80343b0c(text,format);
    if(self->mode) {
        w3d_s4_card_replace_marker(self,output,text,w3d_str_803cfacc,self->mode);
        w3d_text_format_80343b0c(text,output);
    }
    if(self->slot) {
        w3d_s4_card_replace_marker(self,output,text,w3d_str_803cfae0,self->slot);
        w3d_text_format_80343b0c(text,output);
    }
    if(self->blocks) {
        w3d_s4_card_replace_marker(self,output,text,w3d_str_803cfaf0,self->blocks);
        w3d_text_format_80343b0c(text,output);
    }
    strcpy(output,text);
}
// Deferred: branch layout differs after three attempts.
#if 0
bool w3d_s4_card_split_line(void *,char *output,signed char *text)
{
    bool found=false;
    while(*text) {
        if(*text=='\n') {found=true;break;}
        ++text;
    }
    if(found) goto split;
    return 0;
split:
    *text=0;
    strcpy(output,(char *)text+1);
    return 1;
}
#endif
void w3d_s4_card_replace_marker(void *,char *output,const char *input,const char *marker,const char *replacement)
{
    int length=strlen(input);
    char *match=strstr(input,marker);
    int inputOffset=match-input;
    if(match) {
        memcpy(output,input,inputOffset);
        int outputOffset=inputOffset;
        inputOffset=outputOffset+strlen(marker);
        memcpy(output+outputOffset,replacement,strlen(replacement));
        outputOffset+=strlen(replacement);
        if(length!=inputOffset) {
            int remaining=length-inputOffset;
            memcpy(output+outputOffset,input+inputOffset,remaining);
            outputOffset+=remaining;
        }
        output[outputOffset]=0;
    } else strcpy(output,input);
}
}
