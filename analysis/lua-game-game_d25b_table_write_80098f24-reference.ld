/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25b_table_write_80098f24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
w3d_append_802cbf2c = 0x802cbf2c;
w3d_repeat_request_802cd220 = 0x802cd220;
w3d_sink_write_802cbdf8 = 0x802cbdf8;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_op_802cd128 = 0x802cd128;
w3d_string_release_80341588 = 0x80341588;
w3d_table_803f4b50 = 0x803f4b50;
SECTIONS {
  .text.w3d_d25b_table_write_80098f24 0x80098f24 : { *(.text.w3d_d25b_table_write_80098f24) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
