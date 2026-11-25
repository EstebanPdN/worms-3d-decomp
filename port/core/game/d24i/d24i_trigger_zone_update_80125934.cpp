#include "w3d_ptr.h"
#line 1 "d24i_trigger_zone_update_80125934.cpp"
// d24i: 0x80125934 (364 bytes). Trigger zone update. Starts the object iterator
// at +100 (0x80126334) and walks it (0x801264fc) until the 0xffff terminator or
// until one of the flags +76, +80, +88 is set. For the current object (id at
// 0x804aa95e, resolved by 0x8003f240) whose team (+24) is not the zone's team
// (+20), its type (+20) selects: 1 worm entered (0x80125aa0), 136 with count +64
// at most 3 (0x80125c80), 8 with count +68 at most 3 (0x80125d0c), 512 with +84
// set (0x80125d98). Then finishes the walk (0x80126524) and collects (0x80125b44)
// when +88 is set.
struct d24i_Object {
    unsigned char unknown00[20];
    int type;                            // +20
    int team;                            // +24
};
struct d24i_Iterator { unsigned char opaque; };
struct d24i_Zone {
    unsigned char unknown00[20];
    int team;                            // +20
    unsigned char unknown18[40];
    int count_a;                         // +64
    int count_b;                         // +68
    unsigned char unknown48[4];
    int done_a;                          // +76
    int done_b;                          // +80
    int enabled;                         // +84
    int done_c;                          // +88
    unsigned char unknown5c[8];
    d24i_Iterator iterator;              // +100
};
extern "C" void d24i_iterator_start_80126334(Ptr32<d24i_Iterator>);
extern "C" int d24i_iterator_next_801264fc(Ptr32<d24i_Iterator>);
extern "C" void d24i_iterator_finish_80126524(Ptr32<d24i_Iterator>);
extern "C" Ptr32<d24i_Object> d24i_object_8003f240(unsigned short);
extern "C" void d24i_on_entered_80125aa0(Ptr32<d24i_Zone>, int);
extern "C" void d24i_check_a_80125c80(Ptr32<d24i_Zone>);
extern "C" void d24i_check_b_80125d0c(Ptr32<d24i_Zone>);
extern "C" void d24i_trigger_80125d98(Ptr32<d24i_Zone>);
extern "C" void d24i_collect_80125b44(Ptr32<d24i_Zone>);
extern unsigned short d24i_current_804aa95e;

extern "C" void d24i_trigger_zone_update_80125934(Ptr32<d24i_Zone> self) {
    int team = self->team;
    d24i_iterator_start_80126334(&self->iterator);
    int id = d24i_iterator_next_801264fc(&self->iterator);
    while (!self->done_a && !self->done_b && !self->done_c && id != 0xffff) {
        if (d24i_object_8003f240(d24i_current_804aa95e)->team != team) {
            int type = d24i_object_8003f240(d24i_current_804aa95e)->type;
            if (type == 1)
                d24i_on_entered_80125aa0(self, d24i_object_8003f240(d24i_current_804aa95e)->team);
            else if (self->count_a <= 3 && type == 136)
                d24i_check_a_80125c80(self);
            else if (self->count_b <= 3 && type == 8)
                d24i_check_b_80125d0c(self);
            else if (self->enabled && type == 512)
                d24i_trigger_80125d98(self);
        }
        id = d24i_iterator_next_801264fc(&self->iterator);
    }
    d24i_iterator_finish_80126524(&self->iterator);
    if (self->done_c)
        d24i_collect_80125b44(self);
}


