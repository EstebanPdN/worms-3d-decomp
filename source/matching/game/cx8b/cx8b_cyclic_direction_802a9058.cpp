
struct Cx8bCyclicPositions { char unknown00[1316]; unsigned int first[3],second[3]; };
extern "C" int w3d_cx8b_cyclic_direction_802a9058(Cx8bCyclicPositions *self,int index,unsigned int period) {
 unsigned int first=self->first[index],second=self->second[index];
 if(first<second) {
  if(second-first < (period-second)+first) return 1;
  return 2;
 }
 if(first-second < (period-first)+second) return 2;
 return 1;
}



