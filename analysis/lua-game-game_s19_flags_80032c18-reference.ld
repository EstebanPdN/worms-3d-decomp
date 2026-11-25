/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_set_priority_flags_80032c18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80178df0 = 0x80178df0;
w3d_empty_80342a74 = 0x80342a74;
SECTIONS {
  .text.s19_set_priority_flags_80032c18 0x80032c18 : { *(.text.s19_set_priority_flags_80032c18) }
  .rodata 0x803732d0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
