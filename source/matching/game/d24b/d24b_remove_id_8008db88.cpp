/* Remove a target id from the id list at +344 (0x8008db88): compares each entry with
 * the id of the message (0x801190d0), closes the gap with 0x802eee50 and shrinks the
 * list on the first match. Field and type names are inferred. */
extern "C" int w3d_get_801190d0(void *);
extern "C" void *w3d_copy_802eee50(...);
struct IdList {
    int *begin, *end, *capacity;
    int *End() const { return end; }
    void Erase(int *p) {
        int *next = p + 1;
        if (next != end) {
            int *last = end - 1;
            w3d_copy_802eee50(p, next, (char *)last - (char *)p);
        }
        end--;
    }
};
struct Owner { char unknown00[344]; IdList ids; };
extern "C" void w3d_d24b_remove_id_8008db88(Owner *self, void *message)
{
    for (int *p = self->ids.begin; p != self->ids.End(); p++) {
        if (*p == w3d_get_801190d0(message)) {
            self->ids.Erase(p);
            return;
        }
    }
}
