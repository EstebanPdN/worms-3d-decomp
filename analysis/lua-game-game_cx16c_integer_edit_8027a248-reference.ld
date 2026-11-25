/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16c_integer_edit_8027a248)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx16c_lookup_801e9db8 = 0x801e9db8;
cx16c_notify_8027a98c = 0x8027a98c;
cx16c_parse_802ed89c = 0x802ed89c;
cx16c_refresh_8027ae00 = 0x8027ae00;
SECTIONS {
  .text.w3d_cx16c_integer_edit_8027a248 0x8027a248 : { *(.text.w3d_cx16c_integer_edit_8027a248) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
