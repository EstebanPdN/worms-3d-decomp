#include "w3d_ptr.h"
#line 1 "s4_card_text.cpp"
extern "C" {
struct S4CardText { unsigned char pad[972]; Ptr32<const char> mode; Ptr32<const char> slot; Ptr32<const char> blocks; };
int w3d_text_format_80343b0c(Ptr32<char>,Ptr32<const char>,...);
Ptr32<char> strcpy(Ptr32<char>,Ptr32<const char>);
unsigned int strlen(Ptr32<const char>);
Ptr32<char> strstr(Ptr32<const char>,Ptr32<const char>);
Ptr32<void> memcpy(Ptr32<void>,Ptr32<const void>,unsigned int,...);
void w3d_s4_card_replace_marker(Ptr32<void>,Ptr32<char>,Ptr32<const char>,Ptr32<const char>,Ptr32<const char>);
extern const char w3d_str_803cfacc[],w3d_str_803cfae0[],w3d_str_803cfaf0[];
void w3d_s4_card_format_text(Ptr32<S4CardText> self,Ptr32<char> output,Ptr32<const char> format)
{
    char storage[128]; register Ptr32<char> text=storage; text[0]=0;
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
void w3d_s4_card_replace_marker(Ptr32<void>,Ptr32<char> output,Ptr32<const char> input,Ptr32<const char> marker,Ptr32<const char> replacement)
{
    int length=strlen(input);
    Ptr32<char> match=strstr(input,marker);
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


