struct s8_TestObject { char pad0[44]; int value; };
extern "C" int s8_field_test_800cfc80(const s8_TestObject *p) { int result=0; if(p->value) result=1; return result; }
