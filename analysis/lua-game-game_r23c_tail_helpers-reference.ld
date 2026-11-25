/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(r23c_set_high_flag_80348e1c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.r23c_set_high_flag_80348e1c 0x80348e1c : { *(.text.r23c_set_high_flag_80348e1c) }
  .text.r23c_max_byte_80352828 0x80352828 : { *(.text.r23c_max_byte_80352828) }
  .text.r23c_rgb_to_opaque_803563b8 0x803563b8 : { *(.text.r23c_rgb_to_opaque_803563b8) }
  .text.r23c_expand_1555_8035642c 0x8035642c : { *(.text.r23c_expand_1555_8035642c) }
  .text.r23c_history_append_80358144 0x80358144 : { *(.text.r23c_history_append_80358144) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
