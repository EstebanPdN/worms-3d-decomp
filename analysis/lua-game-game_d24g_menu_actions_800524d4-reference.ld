/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_menu_actions_800524d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
action_name_8037835c = 0x8037835c;
action_name_80378368 = 0x80378368;
action_name_8037837c = 0x8037837c;
action_name_8037838c = 0x8037838c;
action_name_8037839c = 0x8037839c;
action_name_803783b0 = 0x803783b0;
action_name_803783c0 = 0x803783c0;
action_name_803783d0 = 0x803783d0;
action_name_803783e8 = 0x803783e8;
action_name_80378404 = 0x80378404;
action_name_8037841c = 0x8037841c;
action_name_80378434 = 0x80378434;
action_name_80378448 = 0x80378448;
action_name_80378464 = 0x80378464;
action_name_80378470 = 0x80378470;
action_name_80378484 = 0x80378484;
action_name_803784a0 = 0x803784a0;
w3d_allocate_80212fd4 = 0x80212fd4;
w3d_copy_802eee50 = 0x802eee50;
w3d_name_8015f518 = 0x8015f518;
w3d_pool_allocate_802098d8 = 0x802098d8;
w3d_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_d24g_menu_actions_800524d4 0x800524d4 : { *(.text.w3d_d24g_menu_actions_800524d4) }
  .rodata 0x803784b8 : { *(.rodata) }
  .sdata 0x804ae280 (NOLOAD) : {
    . = 0x0; w3d_pool_804ae280 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
