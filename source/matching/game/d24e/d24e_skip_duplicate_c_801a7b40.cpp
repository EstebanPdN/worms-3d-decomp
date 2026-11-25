// Skips a queued command equal to the last one, flag-gated (Worms 3D GameCube PAL, 0x801a7b40).
//
// self is a secondary-base pointer (self - 4 is the owner, null stays null).
// back() copies the deque's finish iterator, steps it back across a 128-byte
// block if needed and reads the element. When the target's field at +32 is
// zero, bit 0 of the byte at +11 is set in both target and tail, both report
// the same key (virtual slot 5) and the tail's field at +32 is zero, returns 0
// without queueing; otherwise forwards to 0x801a7680.
struct d24e_Target {
    void **table;
    unsigned char unknown04[7];
    unsigned char flags;
    unsigned unknown0c[5];
    int field;
    int key() { return ((int (*)(d24e_Target *))table[5])(this); }
};
struct d24e_DequeIterator {
    d24e_Target **current, **first, **last, ***node;
    void setNode(d24e_Target ***n) { node = n; first = *n; last = first + 32; }
    d24e_DequeIterator &operator--() {
        if (current == first) { setNode(node - 1); current = last; }
        --current;
        return *this;
    }
    d24e_Target *operator*() const { return *current; }
};
struct d24e_DequeOwner {
    char prefix[64];
    d24e_DequeIterator finish;
    d24e_Target *back() { d24e_DequeIterator t = finish; --t; return *t; }
};
extern "C" int fn_801a7680(void *, d24e_Target *);

extern "C" int w3d_d24e_skip_duplicate_c_801a7b40(char *self, d24e_Target *target) {
    d24e_DequeOwner *owner = self ? (d24e_DequeOwner *)(self - 4) : 0;
    d24e_Target *tail = owner->back();
    if (target->field == 0 && (target->flags & 1) && (tail->flags & 1)) {
        int key = target->key();
        if (key == tail->key() && tail->field == 0) return 0;
    }
    return fn_801a7680(self, target);
}
