#pragma interface
// The original copy installs table 0x80410500 at offset eight and copies
// the halfword at zero and word at four. The intervening bytes are ABI alignment.
struct Sol31cTransferRecord {
    unsigned short key;
    unsigned value;
    virtual void slot();
};
