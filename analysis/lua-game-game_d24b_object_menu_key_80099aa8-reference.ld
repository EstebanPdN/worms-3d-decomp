/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_object_menu_key_80099aa8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_page_setup_80098fc8 = 0x80098fc8;
w3d_rebuild_800994b4 = 0x800994b4;
w3d_refresh_800990a4 = 0x800990a4;
w3d_show_detail_80099dc0 = 0x80099dc0;
w3d_show_help_80099a20 = 0x80099a20;
w3d_show_options_80099998 = 0x80099998;
w3d_strchr_802ef198 = 0x802ef198;
SECTIONS {
  .text.w3d_d24b_object_menu_key_80099aa8 0x80099aa8 : { *(.text.w3d_d24b_object_menu_key_80099aa8) }
  .sdata 0x804aabc8 (NOLOAD) : {
    . = 0x0; w3d_keys_804aabc8 = .;
    . = 0x4; w3d_keys_804aabcc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
