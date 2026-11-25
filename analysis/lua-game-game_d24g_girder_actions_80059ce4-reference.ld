/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_girder_actions_80059ce4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
action_name_8037835c = 0x8037835c;
action_name_803785a8 = 0x803785a8;
action_name_803785c4 = 0x803785c4;
action_name_803785e0 = 0x803785e0;
action_name_803785fc = 0x803785fc;
action_name_80378618 = 0x80378618;
action_name_80378634 = 0x80378634;
action_name_80378650 = 0x80378650;
action_name_80378668 = 0x80378668;
action_name_80378868 = 0x80378868;
action_name_80378a84 = 0x80378a84;
action_name_80378a94 = 0x80378a94;
action_name_80378aa4 = 0x80378aa4;
action_name_80378ac0 = 0x80378ac0;
action_name_80378adc = 0x80378adc;
action_name_80378af4 = 0x80378af4;
action_name_80378b0c = 0x80378b0c;
action_name_80378b24 = 0x80378b24;
action_name_80378b3c = 0x80378b3c;
action_name_80378b5c = 0x80378b5c;
action_name_80378b7c = 0x80378b7c;
action_name_80378b9c = 0x80378b9c;
action_name_80378bbc = 0x80378bbc;
action_name_80378bd8 = 0x80378bd8;
action_name_80378bf4 = 0x80378bf4;
action_name_80378c10 = 0x80378c10;
action_name_80378c30 = 0x80378c30;
action_name_80378c4c = 0x80378c4c;
action_name_80378c6c = 0x80378c6c;
action_name_80378c8c = 0x80378c8c;
action_name_80378cac = 0x80378cac;
action_name_80378cc8 = 0x80378cc8;
action_name_80378ce4 = 0x80378ce4;
action_name_80378d00 = 0x80378d00;
w3d_allocate_80212fd4 = 0x80212fd4;
w3d_copy_802eee50 = 0x802eee50;
w3d_name_8015f518 = 0x8015f518;
w3d_pool_allocate_802098d8 = 0x802098d8;
w3d_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_d24g_girder_actions_80059ce4 0x80059ce4 : { *(.text.w3d_d24g_girder_actions_80059ce4) }
  .rodata 0x80378d1c : { *(.rodata) }
  .sdata 0x804ae280 (NOLOAD) : {
    . = 0x0; w3d_pool_804ae280 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
