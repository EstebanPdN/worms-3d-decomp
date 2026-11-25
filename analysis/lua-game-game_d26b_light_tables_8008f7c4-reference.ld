/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26b_light_tables_8008f7c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_sqrt_802e82c0 = 0x802e82c0;
w3d_table_80433760 = 0x80433760;
w3d_v_804336a0 = 0x804336a0;
w3d_v_804336ac = 0x804336ac;
w3d_v_804336b8 = 0x804336b8;
w3d_v_804336c4 = 0x804336c4;
w3d_v_804336d0 = 0x804336d0;
w3d_v_804336dc = 0x804336dc;
w3d_v_804336e8 = 0x804336e8;
w3d_v_804336f4 = 0x804336f4;
SECTIONS {
  .text.w3d_d26b_light_tables_8008f7c4 0x8008f7c4 : { *(.text.w3d_d26b_light_tables_8008f7c4) }
  .rodata 0x8037e7b8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
