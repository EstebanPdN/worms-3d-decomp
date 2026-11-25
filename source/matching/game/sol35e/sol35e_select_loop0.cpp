struct sol35e_R27cItem;
struct sol35e_R27cArray { sol35e_R27cItem **begin; sol35e_R27cItem **end; };
struct sol35e_R27cOwner { char pad[56]; sol35e_R27cArray array; char pad2[8]; int selected; };
extern "C" int sol35e_r27c_count_802bc71c(sol35e_R27cOwner *);
extern "C" int sol35e_r27c_item_index_802bd2bc(sol35e_R27cItem *);
extern "C" void sol35e_r27c_item_select_802bd318(sol35e_R27cItem *, bool);
extern "C" void sol35e_r27c_select_802bc8b4(sol35e_R27cOwner *owner,int selected) { if (sol35e_r27c_count_802bc71c(owner)<=selected) selected=-1; sol35e_R27cArray *array=&owner->array; sol35e_R27cItem **p=owner->array.begin; if (p != owner->array.end) do { sol35e_R27cItem *item=*p++; sol35e_r27c_item_select_802bd318(item,sol35e_r27c_item_index_802bd2bc(item)==selected); } while(p!=array->end); owner->selected=selected; }
