// Original controller indicator selection and UTF8 output. Workspaces cover
// observed16-byte text storage and trailing8 bytes; original declaration unknown.
struct cc29a_Controller_80024990 {unsigned char unknown[44];void*text;};
extern "C" {void*cc29a_text_80343580(void*);int cc29a_encode_8018b2b0(unsigned short,void*,char*);int cc29a_set_8018c5b0(void*,const char*);}
extern "C" void cc29a_controller_indicator_80024990(cc29a_Controller_80024990*self,unsigned action,int flag){
 int mode=0;
 switch(action){case 3:case 25:case 31:case 32:case 47:mode=1;break;
 case 14:case 16:mode=1;if(!flag)break;
 case 0:case 1:case 2:case 5:case 6:case 8:case 9:case 15:case 20:case 21:case 30:case 34:case 35:case 36:mode=2;break;}
 void*text=cc29a_text_80343580(self->text);char buffer[16];unsigned scratch[2];
 switch(mode){case 0:buffer[0]=0;break;case 1:cc29a_encode_8018b2b0(187,scratch,buffer);break;case 2:cc29a_encode_8018b2b0(186,scratch,buffer);break;}
 cc29a_set_8018c5b0(text,buffer);
}
