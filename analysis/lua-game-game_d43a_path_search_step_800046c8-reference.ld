/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d43a_path_search_step_800046c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800047f0 = 0x800047f0;
FUN_80005e1c = 0x80005e1c;
d29s_push_tagged_800053e4 = 0x800053e4;
w3d_auto_80015264 = 0x80015264;
w3d_cx16a_rebuild_path_80005d4c = 0x80005d4c;
w3d_empty_8034144c = 0x8034144c;
w3d_path_search_pop = 0x8000577c;
w3d_path_table_clear_80005398 = 0x80005398;
SECTIONS {
  .text.w3d_d43a_path_search_step_800046c8 0x800046c8 : { *(.text.w3d_d43a_path_search_step_800046c8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
