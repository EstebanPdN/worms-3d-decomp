/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40f_cursor_init_80285168)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__10D25fStringPCc = 0x8020bb54;
cc43b_clamp_position_802852c4 = 0x802852c4;
d24d_acquire_message_80162024 = 0x80162024;
lbl_803cf368 = 0x803cf368;
lbl_803cf374 = 0x803cf374;
w3d_auto_800fc270 = 0x800fc270;
w3d_cached_message_id = 0x8015f5a0;
w3d_handle_set_name_8015adf4 = 0x8015adf4;
w3d_sqrt_802e82c0 = 0x802e82c0;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_d40f_cursor_init_80285168 0x80285168 : { *(.text.w3d_d40f_cursor_init_80285168) }
  .rodata 0x803cf384 : { *(.rodata) }
  .sdata 0x804aac54 (NOLOAD) : {
    . = 0x0; w3d_globals_804aac54 = .;
    . = 0x5f38; w3d_name_804b0b8c = .;
    . = 0x5f40; w3d_name_804b0b94 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
