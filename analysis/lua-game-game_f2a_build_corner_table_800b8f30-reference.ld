/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f2a_build_corner_table_800b8f30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800b3e20 = 0x800b3e20;
fn_801ef048 = 0x801ef048;
lbl_8040e078 = 0x8040e078;
SECTIONS {
  .text.w3d_f2a_build_corner_table_800b8f30 0x800b8f30 : { *(.text.w3d_f2a_build_corner_table_800b8f30) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
