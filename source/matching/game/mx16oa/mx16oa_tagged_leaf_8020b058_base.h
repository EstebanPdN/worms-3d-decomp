// Abstract root of the tagged-object family. Its table at 0x804181c0 is
// all-pure in the original, so `#pragma interface` keeps it out of the unit:
// the original copy stays an external object (ownership pending). The slot
// count of that table is not recovered; one structural slot is declared.
#pragma interface
struct Mx16oaTaggedRoot {
    virtual void slot0() = 0;
};
