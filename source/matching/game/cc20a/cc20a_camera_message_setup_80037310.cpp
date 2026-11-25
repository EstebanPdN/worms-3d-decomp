// Camera task field and message-name records are observed; the rest of the object is opaque.
struct Cc20aCamera {char reserved[208];unsigned int task;};
struct Cc20aName {unsigned int words[2];};
struct Cc20aMessage;
extern "C" void *lbl_804b1754;
extern "C" Cc20aName lbl_804ad038,lbl_804ad030;
extern "C" int fn_800fc230(const char**,unsigned int*);
extern "C" int fn_800fc2b0(const char**,void**);
extern "C" void fn_800d31d8(Cc20aCamera*,void*);
extern "C" Cc20aMessage *fn_801613f0(void*,int);
extern "C" int fn_8015f5a0(Cc20aName*,int);
extern "C" Cc20aMessage *fn_8010a8e0(Cc20aMessage*,unsigned short,const char*);
extern "C" int fn_8016239c(void *);
extern "C" void fn_800d308c(Cc20aCamera*,void*);
extern "C" const char lbl_80373da4[];
extern "C" const char lbl_80373dbc[];
extern "C" const char lbl_80373dc8[];
extern "C" const char lbl_80373dd0[];
extern "C" const char lbl_80373ddc[];
extern "C" const char lbl_80373de8[];
extern "C" const char lbl_80373e00[];
extern "C" const char lbl_80373e10[];
extern "C" const char lbl_80373e1c[];
extern "C" void w3d_cc20a_camera_message_setup_80037310(Cc20aCamera*self,void*state){
 const char *key1=lbl_80373da4;unsigned int task;
 fn_800fc230(&key1,&task);self->task=task;
 const char *key2=lbl_80373dbc;void*data;
 fn_800fc2b0(&key2,&data);fn_800d31d8(self,data);
Cc20aMessage *message0=fn_801613f0(lbl_804b1754,12);fn_8016239c((void *)fn_8010a8e0(message0,fn_8015f5a0(&lbl_804ad038,1),lbl_80373dc8));
Cc20aMessage *message1=fn_801613f0(lbl_804b1754,12);fn_8016239c((void *)fn_8010a8e0(message1,fn_8015f5a0(&lbl_804ad038,1),lbl_80373dd0));
Cc20aMessage *message2=fn_801613f0(lbl_804b1754,12);fn_8016239c((void *)fn_8010a8e0(message2,fn_8015f5a0(&lbl_804ad030,1),lbl_80373ddc));
Cc20aMessage *message3=fn_801613f0(lbl_804b1754,12);fn_8016239c((void *)fn_8010a8e0(message3,fn_8015f5a0(&lbl_804ad030,1),lbl_80373de8));
Cc20aMessage *message4=fn_801613f0(lbl_804b1754,12);fn_8016239c((void *)fn_8010a8e0(message4,fn_8015f5a0(&lbl_804ad030,1),lbl_80373e00));
Cc20aMessage *message5=fn_801613f0(lbl_804b1754,12);fn_8016239c((void *)fn_8010a8e0(message5,fn_8015f5a0(&lbl_804ad030,1),lbl_80373e10));
Cc20aMessage *message6=fn_801613f0(lbl_804b1754,12);fn_8016239c((void *)fn_8010a8e0(message6,fn_8015f5a0(&lbl_804ad030,1),lbl_80373e1c));
fn_800d308c(self,state);}