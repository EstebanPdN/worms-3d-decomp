# Reference C++: table insertion and secondary-base thunks

These units target PAL `GWMP8P` revision 0 and the existing SN ProDG 3.7
reference route. Function meanings and type names are inferred. Admission and
coverage come from the central audited ledger, not this document.

`cc17p_hash_insert_8035c75c.cpp` describes observed 32-bit layouts: a key with
words read at offsets 0 and 8, an eight-byte payload, a twelve-byte chain node,
and bucket-vector endpoints at table offsets 4 and 8. The count is at offset
24. The implementation expands the table, hashes the sum of the two key
words modulo the bucket count, allocates with the original fallback, copies
the payload, prepends its node, increments the count, and returns the payload
address. The original epilogue leaves that address in r3. Modeling the return
as `void` changed register allocation and failed byte comparison.

The bucket-vector extent, successful allocation/fallback, key lifetime, and
caller ownership remain obligations of their separate implementations. This
unit introduces no substitute implementations for them. Native pointer widths
must not be substituted into this reference layout.

`cc17p_secondary_adjustors_80344d84.cpp` and its private headers emit eight
compiler-generated virtual thunks at `0x80344d84..0x80344dc4`. Each subtracts
28 from its incoming object pointer and tail-jumps to the witnessed target.
The synthetic C++ class declarations reproduce that ABI operation; they do
not establish the game's original class names, complete hierarchy, or vtable
data ownership. The manifest records the required `-fvtable-thunks` option.
Two Ghidra function records also included a disjoint instruction at the branch
target. Only each complete eight-byte thunk is claimed by these proofs.

Build and prove the units with:

```sh
python3 tools/build_game_unit.py cc17p_hash_insert_8035c75c
python3 tools/build_game_unit.py cc17p_secondary_adjustors_80344d84
```

The parent admits eligible results through `tools/admit_game_units.py`, after
preserving the prior evidence and excluding overlaps. Separate drafts and
failed experiments remain under `build/cc17-parent/`; they add no coverage.

For a native port, retain the key arithmetic, mutation order, allocation failure
contract and returned payload identity while expressing ownership through the
target's platform boundary. Use measurements before changing allocation or
table growth. A reference byte match does not establish a portable allocator,
whole-game behavior, an ARM build, or physical 3DS acceptance.
