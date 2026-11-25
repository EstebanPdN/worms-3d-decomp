// Keep the original SD/card state machine and actions; replace only its 4:3 view.
// Offsets are verified against card_build_text_boxes, card_message and card_screen_update.
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "card_ui.h"
#define fn_8018d35c A8018d35c
#define fn_8018d434 A8018d434
#define fn_801fe3b0 A801fe3b0
#define fn_80288c7c A80288c7c
#define fn_80289914 A80289914
#define fn_80289df8 A80289df8
#define fn_80289eec A80289eec
#define fn_802aba0c A802aba0c
#define fn_802aba68 A802aba68
#define fn_802b30c0 A802b30c0
#define fn_802e88ac A802e88ac
#define fn_80344278 A80344278
#define lbl_803cf924 A803cf924
#define lbl_804abb5c A804abb5c
#define lbl_804abbe0 A804abbe0
#define d35f_card_screen_update_80288564 OriginalCardTick
#include "../game/d35f/d35f_card_screen_update_80288564.cpp"
#undef d35f_card_screen_update_80288564
static_assert(offsetof(Screen,tips)==968 && offsetof(Screen,panel)==992 && offsetof(Screen,flags)==1016,"Card layout");
extern "C" int w3d_fe_native_layout(void);
extern "C" int w3d_fe_popup_depth(void);
namespace {
W3dCardUi current;
int pending=-1;
char pending_title[96];
struct Item { Ptr32<const char> key; int action; };
struct Record { int unused; Ptr32<const char> title; unsigned count; int unused12; Item items[5]; };
void hide(Ptr32<void> node) {
    if(!node) return;
    auto table=*(Ptr32<Ptr32<void>> *)node.get();
    ((Ptr32<void(Ptr32<void>,int)>)table[22])(node,0);
}
}
extern "C" int A80288564(Ptr32<Screen> self,unsigned time) {
    if(!w3d_fe_native_layout()) return OriginalCardTick(self,time);
    auto record=(Record *)self->tips.get();
    if(pending>=0) {
        if(record && record->title && !strcmp(record->title.get(),pending_title) && self->state==1 && pending<(int)record->count) {
            self->page=pending; self->flags|=0x80000000;
        }
        pending=-1;
    }
    int result=OriginalCardTick(self,time);
    record=(Record *)self->tips.get();
    memset(&current,0,sizeof current);
    if(record && (self->flags&0x08000000)) {
        current.active=1; current.ready=self->state==1;
        current.selected=self->page; current.count=record->count<=5?record->count:0;
        current.operation=self->active;
        snprintf(current.title,sizeof current.title,"%s",record->title?record->title.get():"");
        for(int i=0;i<current.count;++i) snprintf(current.options[i],sizeof current.options[i],"%s",record->items[i].key?record->items[i].key.get():"");
        for(unsigned i=0;i<self->partCount && i<8;++i) hide(self->parts[i]);
        for(unsigned i=0;i<self->extraCount && i<5;++i) hide(self->extra[i]);
        hide(self->last);
        hide(*(Ptr32<void> *)((char *)self.get()+988)); // border scene, not the view object
    }
    return result;
}
extern "C" int w3d_card_ui_read(W3dCardUi *out) {
    if(!current.active || w3d_fe_popup_depth()<=0) return 0;
    if(out) *out=current;
    return 1;
}
extern "C" void w3d_card_ui_choose(int i) {
    if(!current.active || !current.ready || i<0 || i>=current.count) return;
    pending=i; snprintf(pending_title,sizeof pending_title,"%s",current.title);
}
