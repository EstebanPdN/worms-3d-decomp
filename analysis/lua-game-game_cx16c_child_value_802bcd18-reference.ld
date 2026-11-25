/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16c_child_value_802bcd18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx16c_apply_802c0cb4 = 0x802c0cb4;
SECTIONS {
  .text.w3d_cx16c_child_value_802bcd18 0x802bcd18 : { *(.text.w3d_cx16c_child_value_802bcd18) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
