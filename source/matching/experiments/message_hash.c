typedef unsigned int W3dWord;
extern "C" {
extern W3dWord w3d_message_name_capacity;
W3dWord w3d_message_hash_slot(const char *name)
{
    W3dWord high;
    W3dWord hash = 0;
    while (*name) {
        int character = *name++;
        hash <<= 4;
        hash += character;
        high = hash & 0xf0000000u;
        if (high) {
            hash ^= high >> 24;
            hash ^= high;
        }
    }
    return hash % w3d_message_name_capacity;
}

}
