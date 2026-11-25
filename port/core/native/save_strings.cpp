// Bloque de cadenas del guardado: todas las cadenas del mapa, sin repetir, y una tabla con el desplazamiento de cada una por índice.
#include "native_game.h"

namespace {
struct StringNode {
    char pad[0x10];
    GameString text;     // +0x10
    w3d_u32 index;       // +0x14
};
struct StringMapHeader { char pad[8]; Ptr32<StringNode> leftmost; };
struct SaveWriter {
    char pad[0x6c];
    w3d_u32 pad2;
    Ptr32<StringMapHeader> map;   // +0x70
    w3d_u32 count;                // +0x74
};
struct ByteVector {
    Ptr32<char> begin, end, capacity;
    void append(const void *bytes, w3d_u32 length);
};
void ByteVector::append(const void *bytes, w3d_u32 length) {
    if (end.v + length > capacity.v) {
        const int capacity_bytes = (int)(capacity.v - begin.v);
        const int used = (int)(end.v - begin.v);
        const int grown = capacity_bytes + (int)((w3d_u32)capacity_bytes >> 1);
        const int needed = capacity_bytes + (int)length - (int)(capacity.v - end.v);
        const w3d_u32 bytes_wanted = (w3d_u32)(needed >= grown ? needed : grown);
        const w3d_u32 storage = A80212fd4(bytes_wanted);
        if (begin) {
            A802eee50(g2h(storage), begin.get(), bytes_wanted > (w3d_u32)used ? (w3d_u32)used : bytes_wanted);
            A802134fc(begin.get());
        }
        begin.v = storage;
        end.v = storage + used;
        capacity.v = storage + bytes_wanted;
    }
    A802eee50(end.get(), bytes, length);
    end.v += length;
}
struct ChunkHeader { w3d_u32 id, count, bytes; };
const w3d_u32 kStringsChunk = 0x53525453;  // Se guarda en el orden del anfitrión; los guardados de PPC no sirven aquí.
}
extern "C" {
w3d_u32 A80351ef8(void *node);
void A802047ac(void *writer, const void *bytes, w3d_u32 length);
void A802047e0(void *writer, const void *bytes, w3d_u32 length);

// 0x80205258
w3d_u32 A80205258(Ptr32<SaveWriter> self) {
    const w3d_u32 count = self->count;
    ByteVector text = {};
    const w3d_u32 offsets_bytes = count * 4;
    w3d_u32 *offsets = at<w3d_u32>(A80212fd4(offsets_bytes));
    void *const end_node = self->map.get();
    for (StringNode *node = self->map->leftmost; (void *)node != end_node; node = at<StringNode>(A80351ef8(node))) {
        offsets[node->index] = text.end.v - text.begin.v;
        text.append(node->text.text.get(), node->text.header()->length + 1u);
    }
    const ChunkHeader header = {kStringsChunk, count, text.end.v - text.begin.v};
    A802047ac(self.get(), &header, sizeof header);
    A802047e0(self.get(), offsets, offsets_bytes);
    A802047e0(self.get(), text.begin.get(), text.end.v - text.begin.v);
    if (offsets) A802134fc(offsets);
    if (text.begin) A802134fc(text.begin.get());
    return 0;
}
}
