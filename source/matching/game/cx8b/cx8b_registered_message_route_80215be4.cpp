
extern "C" int count_804b06c4;
extern "C" int ids_804640c0[];
extern "C" void fn_8021573c(void *,void *,int,void *,void *,int);
extern "C" void w3d_cx8b_registered_message_route_80215be4(void *self,int id,void *first,void *second,void *third) {
 if(count_804b06c4>=0) {
  int *it=ids_804640c0+count_804b06c4;
  do { int value=*it--; if(value==id) {fn_8021573c(self,(void *)id,(int)third,first,second,4);return;} }while((int)it>=(int)ids_804640c0);
 }
}


