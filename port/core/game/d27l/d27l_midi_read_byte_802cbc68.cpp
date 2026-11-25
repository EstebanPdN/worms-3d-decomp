#include "w3d_ptr.h"
#line 1 "d27l_midi_read_byte_802cbc68.cpp"
// GWMP8P rev0 0x802cbc68. MIDI-style input read for port index (0..15):
// services the port, reads the two buffer spans through the port's table and
// looks at the status byte: 251..254 drop three bytes and recurse, 250 drops
// through the 0xF0 terminator across the spans and recurses, any other byte
// is consumed and returned sign-extended. The byte meanings come from the
// constants only; port methods are named by role. Tables at 0x80473724 and
// 0x804738a4 are indexed views.
struct Port;
struct PortVt {
    char u0[32];
    Ptr32<int (Ptr32<Port>, Ptr32<Ptr32<unsigned char>>, Ptr32<unsigned int>, Ptr32<Ptr32<unsigned char>>, Ptr32<unsigned int>)> read;
    Ptr32<int (Ptr32<Port>, unsigned int, int)> advance;
    char u40[8];
    Ptr32<int (Ptr32<Port>)> ready;
};
struct Port { Ptr32<PortVt> vt; };
extern int active_804abce4;
extern int connected_80473724[];
extern Ptr32<Port> ports_804738a4[];
extern "C" void fn_802cb314(unsigned);
extern "C" void fn_802ccbfc(unsigned);
extern "C" Ptr32<void> memchr(Ptr32<const void>, int, unsigned);
inline Ptr32<Port> port(unsigned i) { return *(Ptr32<Ptr32<Port>>)((i << 2) + (Ptr32<char>)ports_804738a4); }
inline int connected(unsigned i) { return *(Ptr32<int>)((i << 2) + (Ptr32<char>)connected_80473724); }
extern "C" int d27l_midi_read_byte_802cbc68(unsigned index) {
    if (!active_804abce4 || index > 15) return 0; {
        fn_802cb314(index);
        fn_802ccbfc(index);
        if (connected(index) && port(index)->vt->ready(port(index))) {
            Ptr32<unsigned char> first; Ptr32<unsigned char> second;
            unsigned firstSize, secondSize;
            port(index)->vt->read(port(index), &first, &firstSize, &second, &secondSize);
            if (!firstSize)
                return 0;
            switch (*first) {
            case 251:
            case 252:
            case 253:
            case 254:
                port(index)->vt->advance(port(index), 3, 0);
                { int next = d27l_midi_read_byte_802cbc68(index); return next; }
            case 250: {
                int skip = 0;
                Ptr32<unsigned char> end = (Ptr32<unsigned char>)memchr(first, 240, firstSize);
                Ptr32<unsigned char> start = first;
                if (!end) {
                    skip = firstSize;
                    end = (Ptr32<unsigned char>)memchr(second, 240, secondSize);
                    start = second;
                    if (!end)
                        return 0;
                }
                int n = end - start;
                int s = skip + 1;
                port(index)->vt->advance(port(index), s + n, 0);
                { int next = d27l_midi_read_byte_802cbc68(index); return next; }
            }
            default:
                port(index)->vt->advance(port(index), 1, 0);
                return (signed char)*first;
            }
        }
    }
    return 0;
}


