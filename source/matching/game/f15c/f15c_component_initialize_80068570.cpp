// External placement-constructed396-byte receiver prefix. No allocation occurs here.
// Original factory8006849c allocates400 bytes; four tail bytes are unmodeled.
// Constructor8015fef0 returns its receiver and calls8015fa40, which writes at0,4,8,12,16,20.
// String default constructor803426b8 writes only its four-byte text field.
// Member grouping records observed address lifetimes, not original class identity.
extern "C" void *base_8015fef0(void*);
extern void *vtable_8040ef28[];extern int selected_804aaa9c;
struct F15cCtorString {F15cCtorString();const char *text;};
struct F15cCtorHeld{void *p;F15cCtorHeld():p(0){}};
struct F15cCtorGroup{char unknown0[40];F15cCtorString first[10];char unknown80[80];F15cCtorString second[10];char unknown200[40];};
struct F15cCtorHeader{
 void **vtable;char unknown4[24];void *p28,*p32;char unknown36[60];void *p96,*p100,*handle,*p108;char unknown112[8];
 F15cCtorHeader(){base_8015fef0(this);vtable=vtable_8040ef28;p28=0;p32=0;p96=0;p100=0;p108=0;}
};
struct F15cCtorPrefix:F15cCtorHeader{
 F15cCtorGroup group;char unknown360[4];F15cCtorString name364,name368;F15cCtorHeld p372,p376,p380,p384,p388,p392;
 F15cCtorPrefix(){selected_804aaa9c=1;handle=0;}
};
inline void *operator new(unsigned int,void*place){return place;}
extern "C" F15cCtorPrefix *f15c_component_initialize_80068570(F15cCtorPrefix *self){return new(self) F15cCtorPrefix;}
