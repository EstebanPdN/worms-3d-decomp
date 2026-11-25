/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_message_float_init)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_empty_message_vtable = 0x8040db38;
SECTIONS {
  .text.w3d_message_float_init 0x80069a0c : { *(.text.w3d_message_float_init) }
  .text.w3d_message_int_init 0x800a82f0 : { *(.text.w3d_message_int_init) }
  .text.w3d_message_string_init 0x8010a8e0 : { *(.text.w3d_message_string_init) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
