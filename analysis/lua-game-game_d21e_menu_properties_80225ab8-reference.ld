/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d21e_register_menu_properties_80225ab8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d20e_empty_804b06a0 = 0x804b06a0;
d20e_release_header_8020bb2c = 0x8020bb2c;
d20e_string_finish_8020c5c4 = 0x8020c5c4;
d20e_string_header_80341884 = 0x80341884;
d20e_string_init_8020c5c0 = 0x8020c5c0;
d20e_string_release_80341588 = 0x80341588;
desc_803b7d40 = 0x803b7d40;
desc_803b7d78 = 0x803b7d78;
desc_803b7db0 = 0x803b7db0;
desc_803b7de0 = 0x803b7de0;
desc_803b7e14 = 0x803b7e14;
desc_803b7e4c = 0x803b7e4c;
fn_801e8d9c = 0x801e8d9c;
fn_801eb674 = 0x801eb674;
fn_801ed24c = 0x801ed24c;
fn_801eff8c = 0x801eff8c;
lbl_803b7e74 = 0x803b7e74;
lbl_804007cc = 0x804007cc;
lbl_8045e004 = 0x8045e004;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_d21e_register_menu_properties_80225ab8 0x80225ab8 : { *(.text.w3d_d21e_register_menu_properties_80225ab8) }
  .bss 0x80464a2c : { *(.bss) }
  .sbss 0x804b07d4 : { *(.sbss) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
