/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25e_release_lists_801b4140)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80210afc = 0x80210afc;
SECTIONS {
  .text.w3d_d25e_release_lists_801b4140 0x801b4140 : { *(.text.w3d_d25e_release_lists_801b4140) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
