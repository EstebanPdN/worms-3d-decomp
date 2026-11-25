"""Check the PAL disc identity and every recorded instruction range."""
import argparse
from collections import Counter
from hashlib import sha256
import json
from pathlib import Path
import struct

root = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("dol", type=Path, help="sys/main.dol from your extracted disc")
args = parser.parse_args()
ledger = json.loads((root / "analysis/recovery-ledger.json").read_text())
dol = args.dol.read_bytes()
if sha256(dol).hexdigest() != ledger["original_sha256"]:
    raise SystemExit("Expected the PAL GWMP8P revision 0 DOL.")
sections = list(zip(*(struct.unpack_from(">7I", dol, offset) for offset in (0, 0x48, 0x90))))
total = sum(size for _, _, size in sections)
counts = Counter()
sizes = Counter()
end = 0
for fn in sorted(ledger["functions"], key=lambda row: int(row["address"], 16)):
    start = int(fn["address"], 16)
    size = fn["bytes"]
    if not (fn.get("exact_match") or fn.get("exact_linked_match")) or start < end or size <= 0:
        raise SystemExit(f"Unverified or overlapping range at {start:#x}")
    end = start + size
    for offset, base, length in sections:
        if base <= start and end <= base + length:
            pos = offset + start - base
            break
    else:
        raise SystemExit(f"Range outside text at {start:#x}")
    if sha256(dol[pos:pos + size]).hexdigest() != fn["body_sha256"]:
        raise SystemExit(f"Instruction hash mismatch at {start:#x}")
    group = "/".join(fn["source"].split("/")[:2])
    counts[group] += 1
    sizes[group] += size
for group in sorted(counts):
    print(f"{group:25} {counts[group]:6,} functions  {sizes[group]:10,} bytes")
print(f"{sum(counts.values()):,} functions, {sum(sizes.values()):,}/{total:,} bytes ({100 * sum(sizes.values()) / total:.8f}%)")
if sum(sizes.values()) != ledger["verified_native_instruction_bytes_total"] or sum(counts.values()) != ledger["verified_source_function_count"]:
    raise SystemExit("Ledger totals differ from the verified ranges.")
