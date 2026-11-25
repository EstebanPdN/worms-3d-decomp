/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28k_fixed_allocate_80216c4c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80400768 = 0x80400768;
lbl_8040077c = 0x8040077c;
SECTIONS {
  .text.w3d_d28k_fixed_allocate_80216c4c 0x80216c4c : { *(.text.w3d_d28k_fixed_allocate_80216c4c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
