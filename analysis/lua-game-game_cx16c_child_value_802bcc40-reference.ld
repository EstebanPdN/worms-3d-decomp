/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16c_child_value_802bcc40)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx16c_apply_802bfba4 = 0x802bfba4;
SECTIONS {
  .text.w3d_cx16c_child_value_802bcc40 0x802bcc40 : { *(.text.w3d_cx16c_child_value_802bcc40) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
