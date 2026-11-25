
// Original routine accepts unsigned code units and has a four-byte fallback output.
extern "C" unsigned char buffer_804b0234[4];
extern "C" unsigned char*w3d_cx13b_utf8_encode_16_8018b2b0(unsigned int value,unsigned int*length,unsigned char*out){unsigned int local;if(!out)out=buffer_804b0234;if(!length)length=&local;if(value<=127){*length=1;out[0]=value;out[1]=0;}else if(value<=2047){*length=2;out[0]=(value>>6)|192;out[1]=(value&63)|128;out[2]=0;}else{*length=3;out[0]=(value>>12)|224;out[1]=((value>>6)&63)|128;out[2]=(value&63)|128;out[3]=0;}return out;}

