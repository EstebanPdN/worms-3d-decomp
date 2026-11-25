#include "w3d_ptr.h"
#line 1 "s1_session_maintenance.cpp"
/* Session resource maintenance, progress callbacks, and deadline refresh. */
extern "C" {
struct W3dS1MaintenanceContext {char unknown[52];unsigned int tick;};
extern Ptr32<unsigned int> w3d_session_804aaabc;
extern const char w3d_str_8037c3c8[];
int w3d_fn_800fd4c8(unsigned char,int);
void w3d_fn_800e64e8(void);
int w3d_fn_800fd504(Ptr32<const char>,int,int);
int w3d_handles_match_8006e10c(Ptr32<void>);
int w3d_fn_8006ae58(Ptr32<void>);
Ptr32<W3dS1MaintenanceContext> w3d_engine_get_context(void);
unsigned int w3d_auto_80178d1c(Ptr32<void>);
void w3d_fn_8006e004(Ptr32<void> unused,Ptr32<void (int, int)> progress)
{
    unsigned char index=0;
    do {
        switch(index) {
        case 1:case 2:case 6:case 9:case 11:case 12:break;
        default:
            if(progress)progress(0,1);
            if(w3d_fn_800fd4c8(index,2)<0)w3d_fn_800fd4c8(index,1);
        }
        ++index;
    }while(index<=13);
    if(progress)progress(0,1);
    w3d_fn_800e64e8();w3d_fn_800fd504(w3d_str_8037c3c8,5,1);
    if(progress)progress(0,1);
}
#if 0 /* Excluded: return-value and branch layout differ after three attempts. */
int w3d_fn_8006ee18(void)
{
    int result;
    unsigned int *self=w3d_session_804aaabc;
    if(self[60]&0x04000000U)result=0;
    else if(w3d_handles_match_8006e10c(self))result=0;
    else {
        self=w3d_session_804aaabc;
        if(self[60]&0x01000000U) {
            if(w3d_fn_8006ae58(self))result=1;else result=0;
        } else result=0;
    }
    return result;
}
#endif
void w3d_fn_8006eebc(Ptr32<unsigned int> self)
{
    switch(self[52]) {
    case 5:{unsigned int now=w3d_engine_get_context()->tick;self[58]=now+w3d_auto_80178d1c((Ptr32<void>)w3d::G(self[62]));break;}
    case 6:{unsigned int now=w3d_engine_get_context()->tick;self[58]=now+w3d_auto_80178d1c((Ptr32<void>)w3d::G(self[63]));break;}
    }
}
}


