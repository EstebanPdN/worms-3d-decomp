/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k7b_placement_reset_801a4278)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801a3eb0 = 0x801a3eb0;
w3d_auto_801f6448 = 0x801f6448;
SECTIONS {
  .text.w3d_k7b_placement_reset_801a4278 0x801a4278 : { *(.text.w3d_k7b_placement_reset_801a4278) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
