// Four observed pointer-range records, each with begin/end/capacity.
extern "C" void *memcpy(void *, const void *, unsigned int);
inline unsigned int distance(const void *first,const void *last) { return (const char *)last - (const char *)first; }
struct Iterator {
 void **pointer;
 Iterator(void **p) : pointer(p) {}
 void *operator*() const { return *pointer; }
 Iterator &operator++() { ++pointer; return *this; }
 bool operator!=(const Iterator &other) const { return pointer != other.pointer; }
};
struct Range { void **first, **last, **capacity;
 Iterator begin() { return Iterator(first); } Iterator end() { return Iterator(last); }
 void erase(Iterator where) { void **p=where.pointer; if(p+1!=last) memcpy(p,p+1,distance(p,last-1)); --last; }
};
struct Owner { char unknown0[100]; Range groups[4]; char unknown148[236]; unsigned int active; };
extern "C" void sol35c2_erase_group_801565e4(Owner *self, void *value) {
 if(self->active) {
  Range *group = self->groups;
  unsigned int index = 0;
  do {
   Iterator item = group->begin();
   if(item != group->end()) {
    do {
     if(*item == value) {
      group->erase(item);
      return;
     }
     ++item;
    } while(item != group->end());
   }
   ++index; ++group;
  } while(index < 4);
 }
}
