/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27e_apply_attributes_801a2bf4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_d27e_apply_attributes_801a2bf4 0x801a2bf4 : { *(.text.w3d_d27e_apply_attributes_801a2bf4) }
  .sdata 0x804b18d8 (NOLOAD) : {
    . = 0x0; count_804b18d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
