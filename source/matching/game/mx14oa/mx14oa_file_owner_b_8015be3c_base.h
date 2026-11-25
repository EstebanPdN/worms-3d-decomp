// Abstract service interface whose six slots are all pure in the original
// table at 0x804111a0 (two header words, then six 4-byte entries bound to the
// pure-virtual trap 0x802f4440). `#pragma interface` keeps this table out of
// the unit: the original copy remains an external object, ownership pending.
// Slot meanings are unknown; names are structural.
#pragma interface
struct Mx14oaServiceB {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
};
