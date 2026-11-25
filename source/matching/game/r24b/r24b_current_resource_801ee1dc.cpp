// desc: Read the current resource word from the external small-data global; resource semantics inferred.
// Observed: 0x801ee1dc loads one 32-bit word from 0x804b05b0.
// The global owner and the resource value's lifetime remain unresolved.
extern "C" unsigned r24b_current_resource_804b05b0;

extern "C" unsigned w3d_r24b_current_resource_801ee1dc()
{
    return r24b_current_resource_804b05b0;
}
