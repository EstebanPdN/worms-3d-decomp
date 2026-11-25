#include "w3d_ptr.h"
#line 1 "g3c_allocate_zeroed_80213c30.cpp"
// Inferred allocator payload clearing. The allocator header gives the available word count.
extern "C" Ptr32<unsigned int> fn_80212fd4(unsigned int);
extern "C" Ptr32<void> g3c_allocate_zeroed_80213c30(unsigned int count,unsigned int size){
 Ptr32<unsigned int> result=fn_80212fd4(count*size);
 if(result){
  unsigned int words=((result[-1]&~3U)-4)>>2;
  if(words>9){
   Ptr32<unsigned int> p=result;unsigned int remainder=words;
   if(words<8)words=0;else{remainder=words&7;words=(words-1)>>3;}
   switch(remainder){
    case 0:for(;;){*p++=0;
    case 7:*p++=0;
    case 6:*p++=0;
    case 5:*p++=0;
    case 4:*p++=0;
    case 3:*p++=0;
    case 2:*p++=0;
    case 1:*p++=0;
    if((int)words<=0)break;--words;
    }
   }
  }else{
   result[0]=0;result[1]=0;result[2]=0;
   if(words>4){result[3]=0;result[4]=0;
    if(words>6){result[5]=0;result[6]=0;
     if(words>8){result[7]=0;result[8]=0;}
    }
   }
  }
 }
 return result;
}


