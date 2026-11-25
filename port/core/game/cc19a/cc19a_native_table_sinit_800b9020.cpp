#include "w3d_ptr.h"
#line 1 "cc19a_native_table_sinit_800b9020.cpp"
// PPC32 guarded file-static float table and derived storage slots; names inferred.
inline void *operator new(__SIZE_TYPE__,void *p){return p;}
struct Cc19aRow {float x,y,z;Cc19aRow(float a,float b,float c){x=a;y=b;z=c;}};
extern Cc19aRow table_8043b23c[];
extern const float value_80382524[];
extern const float value_80382528[];
extern Ptr32<unsigned char> pointer_804aacc8;
extern Ptr32<unsigned char> pointer_804ae48c;
extern Ptr32<unsigned char> pointer_804ae490;
extern Ptr32<unsigned char> pointer_804ae494;
extern Ptr32<unsigned char> pointer_804ae498;
extern Ptr32<unsigned char> pointer_804ae49c;
extern Ptr32<unsigned char> pointer_804ae4a0;
extern Ptr32<unsigned char> pointer_804ae4a4;
extern Ptr32<unsigned char> pointer_804ae4a8;
extern Ptr32<unsigned char> pointer_804ae4ac;
extern "C" void w3d_cc19a_native_table_sinit_800b9020(int initialize,int priority){
int countdown;
  if (priority != 0xffff) {
    return;
  }
  if (initialize == 0) {
    return;
  }
  pointer_804ae48c = pointer_804aacc8 + 0x4000;
  pointer_804ae494 = pointer_804aacc8 + 0x2e0;
  pointer_804ae498 = pointer_804aacc8 + 0x3070;
  pointer_804ae4a0 = pointer_804aacc8 + 0x3ff0;
  pointer_804ae4a4 = pointer_804aacc8 + 0x3fb0;
  pointer_804ae4a8 = pointer_804aacc8 + 0x3f30;
  pointer_804ae490 = pointer_804aacc8;
  pointer_804ae49c = pointer_804aacc8;
  pointer_804ae4ac = pointer_804aacc8;
  Ptr32<Cc19aRow> p=table_8043b23c;
  new (p) Cc19aRow(value_80382524[0],value_80382524[0],value_80382524[0]);
  

  
  new (++p) Cc19aRow(value_80382528[0],value_80382524[0],value_80382524[0]);
  
  
  new (++p) Cc19aRow(value_80382524[0],value_80382524[0],value_80382528[0]);
  
  
  new (++p) Cc19aRow(value_80382528[0],value_80382524[0],value_80382528[0]);

  
  
  new (++p) Cc19aRow(value_80382524[0],value_80382528[0],value_80382524[0]);

  
  
  new (++p) Cc19aRow(value_80382528[0],value_80382528[0],value_80382524[0]);

  
  
  new (++p) Cc19aRow(value_80382524[0],value_80382528[0],value_80382528[0]);






  
  
  new (++p) Cc19aRow(value_80382528[0],value_80382528[0],value_80382528[0]);
  
  
countdown=8;
  do {
    countdown = countdown + -1;
  } while (countdown != 0);
}


