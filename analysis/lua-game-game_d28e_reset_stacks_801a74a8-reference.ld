/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28e_reset_stacks_801a74a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8035366c = 0x8035366c;
w3d_auto_80353880 = 0x80353880;
SECTIONS {
  .text.w3d_d28e_reset_stacks_801a74a8 0x801a74a8 : { *(.text.w3d_d28e_reset_stacks_801a74a8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
