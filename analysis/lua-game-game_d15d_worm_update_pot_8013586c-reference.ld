/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d15d_worm_update_pot_8013586c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__8D15dVec3 = 0x80343740;
s8_index_query_800fc6dc = 0x800fc6dc;
w3d_auto_80178c48 = 0x80178c48;
w3d_auto_80178d1c = 0x80178d1c;
w3d_empty_803426b4 = 0x803426b4;
w3d_engine_get_context = 0x80165254;
w3d_fn_80140b24 = 0x80140b24;
w3d_s20_lookup_handle_object_80164fc8 = 0x80164fc8;
w3d_set_80140d78 = 0x80140d78;
w3d_worm_pot_apply_pair = 0x80140f70;
w3d_worm_pot_set_second_text = 0x80140d80;
SECTIONS {
  .text.d15d_worm_update_pot_8013586c 0x8013586c : { *(.text.d15d_worm_update_pot_8013586c) }
  .sdata 0x804abab4 (NOLOAD) : {
    . = 0x0; w3d_flag_804abab4 = .;
    . = 0x5cd4; w3d_settings_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
