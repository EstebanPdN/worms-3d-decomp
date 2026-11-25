// Complete20B channel view, witnessed width/height/data/pitch/stride accesses in801d6ca8.
struct ChannelView {int width,height;unsigned char*data;int pitch,stride;};
extern "C" void fn_801d7750(ChannelView*,const ChannelView*,unsigned);
extern "C" void g2b_resize_rgba_801b02c8(unsigned char*src,int srcPitch,int srcWidth,int srcHeight,unsigned char*dst,int dstPitch,int dstWidth,int dstHeight){
 if(srcHeight==dstHeight*2 && srcWidth==dstWidth*2){
  if(dstHeight){do{
   unsigned char*end=src+srcWidth*4;--dstHeight;
   if(src!=end){unsigned char*other=src+srcPitch;do{
    dst[0]=(src[0]+src[4]+other[0]+other[4])>>2;
    dst[1]=(src[1]+src[5]+other[1]+other[5])>>2;
    dst[2]=(src[2]+src[6]+other[2]+other[6])>>2;
    dst[3]=(src[3]+src[7]+other[3]+other[7])>>2;
    src+=8;other+=8;dst+=4;
   }while(src!=end);}
   src+=srcWidth*4;dst+=dstWidth*4-dstPitch;
  }while(dstHeight);}
 }else{
  ChannelView in,out;
  in.width=srcWidth;in.height=srcHeight;in.pitch=srcPitch;in.stride=4;
  out.width=dstWidth;out.height=dstHeight;out.pitch=dstPitch;out.stride=4;
  for(unsigned channel=0;channel<4;++channel){in.data=src+channel;out.data=dst+channel;fn_801d7750(&out,&in,4);}
 }
}
