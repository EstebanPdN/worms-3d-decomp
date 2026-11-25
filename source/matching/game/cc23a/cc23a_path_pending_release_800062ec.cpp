// Pending allocation range at observed path-search offset.
struct Cc23aPending800062ec {void **begin,**end;bool empty(){return begin==end;}void *pop(){void **next=end-1;void *p=*next;end=next;return p;}};
struct Cc23aPath800062ec {unsigned char unknown00[0x8024];Cc23aPending800062ec pending;};
extern "C" {void fn_8034144c();void fn_80015264(void *);}
extern "C" void cc23a_path_pending_release_800062ec(Cc23aPath800062ec *self){
 while(!self->pending.empty()) {void *p=self->pending.pop();if(p){fn_8034144c();fn_80015264(p);}}
}
