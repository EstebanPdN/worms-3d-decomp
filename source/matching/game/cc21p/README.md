# Observed 64-bit helper at 0x8035b260

This reference unit uses the existing SN ProDG route and preserves the original
PPC32 two-register value handling. Keeping the whole 64-bit input alive across
the call, then explicitly narrowing each word, reproduces the original saved
register pair. Earlier split-scalar drafts did not match. That distinction was
identified while recovering the three stream wrappers recorded in cc19b.json.

The direct call at 0x8035b284 targets this same entry in the original DOL.
REA/Ghidra independently returned the same complete 116 bytes. Higher-level
intent, reachability and possible runtime modification remain unknown. The
source preserves this address-bound dependency; it does not silently substitute
a conventional finite 64-bit byte-swap routine.

The manifest identifies only this function. No referenced global data is claimed
as owned. The proof and parent admission use the unchanged project gates:

```sh
python3 tools/build_game_unit.py cc21p_recursive_words_8035b260
```

The original-byte witness is retained in
analysis/worker-reports/cc18-parent-recursive-words-evidence.json. Full unit
byte equality is separate from a complete game link, native portability and
physical-console behavior. Platform-specific replacements require their own
behavioral evidence and stay outside this immutable reference source.
