// Pool selectors are inferred; preserve the original signed selector domain and
// unsigned 16-bit capacity/used queries and modular result, including default zero.
extern "C" unsigned short cc40a_capacity_80170b10(),cc40a_used_80170b18();
extern "C" unsigned short cc40a_capacity_8017f524(),cc40a_used_8017f52c();
extern "C" unsigned short cc40a_capacity_80174520(),cc40a_used_80174528();
extern "C" unsigned short cc40a_capacity_8018774c(),cc40a_used_80187754();
extern "C" unsigned short cc40a_capacity_80183eb4(),cc40a_used_80183ebc();
extern "C" unsigned short cc40a_capacity_8018a7e4(),cc40a_used_8018a7ec();
extern "C" unsigned short cc40a_capacity_801829bc(),cc40a_used_801829c4();
extern "C" unsigned short cc40a_pool_available_8017e0c4(void*,int selector){
 switch(selector){
 case 0:return cc40a_capacity_80170b10()-cc40a_used_80170b18();
 case 1:return cc40a_capacity_8017f524()-cc40a_used_8017f52c();
 case 2:return cc40a_capacity_80174520()-cc40a_used_80174528();
 case 3:return cc40a_capacity_8018774c()-cc40a_used_80187754();
 case 4:return cc40a_capacity_80183eb4()-cc40a_used_80183ebc();
 case 5:return cc40a_capacity_8018a7e4()-cc40a_used_8018a7ec();
 case 6:return cc40a_capacity_801829bc()-cc40a_used_801829c4();
 default:return 0;
 }
}
