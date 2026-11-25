// String data at +100 has a two-byte length in its header at data-4.
struct Cx7bSelection { char unknown00[96]; short selection; short unknown62; char *text; int unknown68; int ready; };
extern "C" void fn_802c7a98(Cx7bSelection *,int,int);
extern "C" void w3d_cx7b_selection_update_802c7894(Cx7bSelection *self,int selected,int refresh) {
 if(!selected) return;
 if(self->selection==selected && !refresh) return;
 self->selection=selected;
 if(refresh && *(unsigned short *)(self->text-4) && self->ready) fn_802c7a98(self,selected,refresh);
}
