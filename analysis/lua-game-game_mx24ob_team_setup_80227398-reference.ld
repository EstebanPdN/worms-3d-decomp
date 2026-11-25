/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__10Mx24obTeamUs)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__12Mx24obString = 0x803426b8;
__12Mx24obTaggedUs = 0x801ea0ec;
__vt_10Mx24obTeam = 0x8041a168;
w3d_auto_80231fd0 = 0x80231fd0;
w3d_cc18b_array_write_80231f14 = 0x80231f14;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_service_key_80419ea8 = 0x80419ea8;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_format = 0x8020c510;
w3d_string_from_text = 0x8020bb54;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
w3d_text_worm_number_803b506c = 0x803b506c;
SECTIONS {
  .text.__10Mx24obTeamUs 0x80227398 : { *(.text.__10Mx24obTeamUs) }
  .rodata 0x803b8198 : { *(.rodata) }
  .sdata 0x804b05ac (NOLOAD) : {
    . = 0x0; w3d_default_store_804b05ac = .;
    . = 0x4; w3d_default_store_804b05b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
