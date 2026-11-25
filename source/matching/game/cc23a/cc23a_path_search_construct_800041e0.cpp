// Sparse native range constructors, observed table extents and path offsets.
inline void *operator new(unsigned int,void *p){return p;}
struct Cc23aTail800041e0{unsigned int unknown00;void *limit04;Cc23aTail800041e0(){}void clear(){limit04=0;}};
struct Cc23aRange800041e0{void *begin,*end;Cc23aTail800041e0 tail;Cc23aRange800041e0(){begin=0;end=0;tail.clear();}};
struct Cc23aTable800041e0{Cc23aRange800041e0 buckets[1024];int count;Cc23aTable800041e0(){count=0;}};
struct Cc23aPath800041e0{
 unsigned int unknown00;Cc23aTable800041e0 table04,table4008;
 void *owned800c,*owned8010;unsigned char unknown8014[16];Cc23aRange800041e0 pending8024;
 unsigned char unknown8034[24];Cc23aRange800041e0 range804c;unsigned char unknown805c[12];void *dispatch8068;
};
extern "C" {extern unsigned char lbl_8040cb10[];extern Cc23aPath800041e0 *lbl_804aa54c;void fn_80004394(Cc23aPath800041e0 *);}
extern "C" Cc23aPath800041e0 *cc23a_path_search_construct_800041e0(Cc23aPath800041e0 *self){
 // Extra original frame reservation is observed; source purpose unknown.
 volatile unsigned char original_frame_extent[32];
 self->dispatch8068=lbl_8040cb10;
 new (&self->table04) Cc23aTable800041e0;new (&self->table4008) Cc23aTable800041e0;
 new (&self->pending8024) Cc23aRange800041e0;new (&self->range804c) Cc23aRange800041e0;
 lbl_804aa54c=self;self->owned800c=0;self->owned8010=0;fn_80004394(self);return self;
}
