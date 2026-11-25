/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d20a_bomber_position_8002f098)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_float_property_800fc270 = 0x800fc270;
w3d_sqrt_802e82c0 = 0x802e82c0;
w3d_string_80372d2c = 0x80372d2c;
w3d_string_80372e34 = 0x80372e34;
w3d_string_80372e44 = 0x80372e44;
w3d_string_80372e4c = 0x80372e4c;
w3d_string_80372e64 = 0x80372e64;
w3d_string_80372e78 = 0x80372e78;
SECTIONS {
  .text.w3d_d20a_bomber_position_8002f098 0x8002f098 : { *(.text.w3d_d20a_bomber_position_8002f098) }
  .rodata 0x80372e88 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
