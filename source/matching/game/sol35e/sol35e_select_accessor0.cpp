struct sol35e_Item;
extern "C" int sol35e_count_802bc71c(void *);
extern "C" int sol35e_index_802bd2bc(sol35e_Item *);
extern "C" void sol35e_choose_802bd318(sol35e_Item *,int);
struct sol35e_Iterator {
 sol35e_Item **p;
 sol35e_Iterator(sol35e_Item **x):p(x) {}
 sol35e_Item *operator*() const {return *p;}
 sol35e_Iterator &operator++() {++p;return *this;}
 sol35e_Iterator operator++(int) {sol35e_Iterator old=*this;++p;return old;}
 bool operator!=(sol35e_Iterator rhs) const {return p!=rhs.p;}
};
struct sol35e_Array {sol35e_Item **first,**last; sol35e_Item **begin() {return first;} sol35e_Item **end() {return last;} };
struct sol35e_Owner { char unknown00[56]; sol35e_Array items; char unknown40[8]; int selected;};
extern "C" void sol35e_select_802bc8b4(sol35e_Owner *owner,int selected) {if(sol35e_count_802bc71c(owner)<=selected)selected=-1; sol35e_Array *array=&owner->items;for(sol35e_Item **i=array->begin();i!=array->end();) {sol35e_Item *item=*i++;sol35e_choose_802bd318(item,sol35e_index_802bd2bc(item)==selected);}owner->selected=selected;}
