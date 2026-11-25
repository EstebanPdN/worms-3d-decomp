/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k5a_orbit_camera_select_80035a30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80035714 = 0x80035714;
FUN_801613f0 = 0x801613f0;
s8_index_query_800fc6dc = 0x800fc6dc;
s8_property_write_800fc43c = 0x800fc43c;
strcmp = 0x802ef234;
w3d_auto_800fc1f0 = 0x800fc1f0;
w3d_cached_message_id = 0x8015f5a0;
w3d_f32_803733f4 = 0x803733f4;
w3d_message_int_init = 0x800a82f0;
w3d_message_post_current = 0x8016239c;
w3d_string_8037327c = 0x8037327c;
w3d_string_80373348 = 0x80373348;
w3d_string_803733d8 = 0x803733d8;
SECTIONS {
  .text.k5a_orbit_camera_select_80035a30 0x80035a30 : { *(.text.k5a_orbit_camera_select_80035a30) }
  .sdata 0x804acffc (NOLOAD) : {
    . = 0x0; w3d_message_804acffc = .;
    . = 0x4758; w3d_message_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
