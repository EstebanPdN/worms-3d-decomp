struct R27cItem;
struct R27cArray { R27cItem **begin; R27cItem **end; };
struct R27cOwner { char pad[56]; R27cArray array; char pad2[8]; int selected; };
extern "C" int r27c_count_802bc71c(R27cOwner *);
extern "C" int r27c_item_index_802bd2bc(R27cItem *);
extern "C" void r27c_item_select_802bd318(R27cItem *, bool);
extern "C" void r27c_select_802bc8b4(R27cOwner *owner,int selected) {
 if (r27c_count_802bc71c(owner) <= selected) selected=-1;
 R27cArray *array=&owner->array;
 R27cItem **p=array->begin;
 if (p!=array->end) do {
  R27cItem *item=*p++;
  r27c_item_select_802bd318(item,r27c_item_index_802bd2bc(item)==selected);
 } while(p!=array->end);
 owner->selected=selected;
}
