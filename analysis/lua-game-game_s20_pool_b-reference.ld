/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_acquire_two_entries_80171ee0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ef048 = 0x801ef048;
fn_8034435c = 0x8034435c;
SECTIONS {
  .text.w3d_s20_acquire_two_entries_80171ee0 0x80171ee0 : { *(.text.w3d_s20_acquire_two_entries_80171ee0) }
  .text.w3d_s20_acquire_sized_8018d5b8 0x8018d5b8 : { *(.text.w3d_s20_acquire_sized_8018d5b8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
