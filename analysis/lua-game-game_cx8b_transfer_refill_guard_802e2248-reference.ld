/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx8b_transfer_refill_guard_802e2248)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802e128c = 0x802e128c;
fn_802fdb6c = 0x802fdb6c;
fn_802fdb94 = 0x802fdb94;
SECTIONS {
  .text.w3d_cx8b_transfer_refill_guard_802e2248 0x802e2248 : { *(.text.w3d_cx8b_transfer_refill_guard_802e2248) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
