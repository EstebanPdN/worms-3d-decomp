/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_find_entry_801d2098)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801d2400 = 0x801d2400;
fn_801d295c = 0x801d295c;
SECTIONS {
  .text.w3d_find_entry_801d2098 0x801d2098 : { *(.text.w3d_find_entry_801d2098) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
