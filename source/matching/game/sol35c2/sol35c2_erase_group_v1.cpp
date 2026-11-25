// Four observed pointer-range records, each with begin/end/capacity.
extern "C" void *memcpy(void *, const void *, unsigned int);
struct Range { unsigned int *begin, *end, *capacity; };
struct Owner { char unknown0[100]; Range groups[4]; char unknown148[236]; unsigned int active; };
extern "C" void sol35c2_erase_group_801565e4(Owner *self, unsigned int value) {
 if(self->active) {
  Range *group = self->groups;
  unsigned int index = 0;
  do {
   unsigned int *item = group->begin;
   if(item != group->end) {
    do {
     if(*item == value) {
      if(item + 1 != group->end) memcpy(item, item + 1, (char *)(group->end - 1) - (char *)item);
      --group->end;
      return;
     }
     ++item;
    } while(item != group->end);
   }
   ++index; ++group;
  } while(index < 4);
 }
}
