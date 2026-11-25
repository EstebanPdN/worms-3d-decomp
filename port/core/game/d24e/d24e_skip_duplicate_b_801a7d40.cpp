#include "w3d_ptr.h"
#line 1 "d24e_skip_duplicate_b_801a7d40.cpp"
// Skips a queued command equal to the last one (Worms 3D GameCube PAL, 0x801a7d40).
//
// Duplicate check keyed on the field at +44.
// self is a secondary-base pointer (self - 4 is the owner, null stays null).
// The owner holds a deque of command pointers with 128-byte blocks: back()
// copies the finish iterator, steps it back across a block if needed and
// reads the element. When the target's field at +44 is zero and the target
// and the tail report the same key (virtual slot 5) with the tail's field also
// zero, returns 0 without queueing; otherwise forwards to 0x801a7680.
struct d24e_Target {
    Ptr32<Ptr32<void>> table;
    unsigned unknown04[10];
    int flag;
    int key() { return ((Ptr32<int (Ptr32<d24e_Target>)>)table[5])(this); }
};
struct d24e_DequeIterator {
    Ptr32<Ptr32<d24e_Target>> current; Ptr32<Ptr32<d24e_Target>> first; Ptr32<Ptr32<d24e_Target>> last; Ptr32<Ptr32<Ptr32<d24e_Target>>> node;
    void setNode(Ptr32<Ptr32<Ptr32<d24e_Target>>> n) { node = n; first = *n; last = first + 32; }
    d24e_DequeIterator &operator--() {
        if (current == first) { setNode(node - 1); current = last; }
        --current;
        return *this;
    }
    Ptr32<d24e_Target> operator*() const { return *current; }
};
struct d24e_DequeOwner {
    char prefix[64];
    d24e_DequeIterator finish;
    Ptr32<d24e_Target> back() { d24e_DequeIterator t = finish; --t; return *t; }
};
extern "C" int fn_801a7680(Ptr32<void>, Ptr32<d24e_Target>);

extern "C" int w3d_d24e_skip_duplicate_b_801a7d40(Ptr32<char> self, Ptr32<d24e_Target> target) {
    Ptr32<d24e_DequeOwner> owner = self ? w3d::R((Ptr32<d24e_DequeOwner>)(self - 4)) : 0;
    if (target->flag == 0) {
        Ptr32<d24e_Target> tail = owner->back();
        int key = target->key();
        if (key == tail->key() && tail->flag == 0) return 0;
    }
    return fn_801a7680(self, target);
}


