/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_set_s8_from_float_801ed690)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_set_s8_from_float_801ed690 0x801ed690 : { *(.text.w3d_set_s8_from_float_801ed690) }
  .text.w3d_set_u16_from_float_801ed6f4 0x801ed6f4 : { *(.text.w3d_set_u16_from_float_801ed6f4) }
  .text.w3d_set_s16_from_float_801ed758 0x801ed758 : { *(.text.w3d_set_s16_from_float_801ed758) }
  .text.w3d_floats_to_u8_8020e6c0 0x8020e6c0 : { *(.text.w3d_floats_to_u8_8020e6c0) }
  .text.w3d_u8_to_floats_8020e700 0x8020e700 : { *(.text.w3d_u8_to_floats_8020e700) }
  .text.w3d_floats_to_u16_8020e740 0x8020e740 : { *(.text.w3d_floats_to_u16_8020e740) }
  .text.w3d_u16_to_floats_8020e780 0x8020e780 : { *(.text.w3d_u16_to_floats_8020e780) }
  .text.w3d_floats_to_s8_8020e88c 0x8020e88c : { *(.text.w3d_floats_to_s8_8020e88c) }
  .text.w3d_s8_to_floats_8020e8cc 0x8020e8cc : { *(.text.w3d_s8_to_floats_8020e8cc) }
  .text.w3d_floats_to_s16_8020e90c 0x8020e90c : { *(.text.w3d_floats_to_s16_8020e90c) }
  .text.w3d_s16_to_floats_8020e94c 0x8020e94c : { *(.text.w3d_s16_to_floats_8020e94c) }
  .text.w3d_get_field_as_u8_802bfc48 0x802bfc48 : { *(.text.w3d_get_field_as_u8_802bfc48) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
