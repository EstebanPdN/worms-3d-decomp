#if 0 /* Unmatched r30/r31 allocation. */
/* Crate component message dispatch. */
extern "C" {
struct W3dS1CrateMessage { unsigned short id; };
struct W3dS1CrateCachedId { unsigned short id,padding; const char *name; };
struct W3dS1CrateContext { unsigned char unknown[0x34]; unsigned int elapsed; };
extern W3dS1CrateCachedId w3d_id_804ad2e8,w3d_id_804ad310,w3d_id_804ad2f0,w3d_id_804ad318;
int w3d_auto_8015fb34(void *,W3dS1CrateMessage *);
int w3d_fn_8015f65c(unsigned short,W3dS1CrateCachedId *);
W3dS1CrateContext *w3d_engine_get_context(void);
void w3d_fn_80048a90(void *);
void w3d_fn_80048ec4(void *);
void w3d_fn_80048f1c(void *);
void w3d_auto_80048fac(void *);
void w3d_fn_80048840(void *,unsigned int);
int w3d_fn_80048734(void *self,W3dS1CrateMessage *message)
{
    switch(message->id) {
    case 0x40:
        if(w3d_auto_8015fb34(self,message)>=0) {
            w3d_fn_80048a90(self);
            return 0;
        }
        return (int)0x80004005;
    case 0x42: w3d_fn_80048ec4(self); break;
    default:
    if(w3d_fn_8015f65c(message->id,&w3d_id_804ad2e8) || w3d_fn_8015f65c(message->id,&w3d_id_804ad310)) w3d_fn_80048f1c(self);
    else if(w3d_fn_8015f65c(message->id,&w3d_id_804ad2f0)) w3d_auto_80048fac(self);
    else if(w3d_fn_8015f65c(message->id,&w3d_id_804ad318))w3d_fn_80048840(self,w3d_engine_get_context()->elapsed);
    }
    return w3d_auto_8015fb34(self,message);
}
}

#endif
