/* Observed signed count, four-byte string-pointer stride and strcmp followed
 * by an original reverse comparator. Search and key names are inferred. */
extern "C" int cx9c_strcmp_802ef234(const char *,const char *);
extern "C" int cx9c_name_greater_8010e698(const char *const *,const char *const *);
extern "C" const char **w3d_cx9c_binary_name_find_80347194(const char **base,int count,const char *const *key) {
 const char **first=base,**last=base+count;
 if(count)do {
  unsigned int length=last-first;const char **middle=first+(length>>1);
  if(middle-base>=count)return middle;
  if(cx9c_strcmp_802ef234(*middle,*key)<0)first=middle+1;
  else if(!cx9c_name_greater_8010e698(middle,key))return middle;
  else last=middle-1;
 }while(first<=last);
 return first;
}
