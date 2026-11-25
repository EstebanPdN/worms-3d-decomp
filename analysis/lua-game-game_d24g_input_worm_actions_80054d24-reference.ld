/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_input_worm_actions_80054d24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
action_name_803784bc = 0x803784bc;
action_name_803784d4 = 0x803784d4;
action_name_803784ec = 0x803784ec;
action_name_80378504 = 0x80378504;
action_name_8037851c = 0x8037851c;
action_name_80378530 = 0x80378530;
action_name_80378544 = 0x80378544;
action_name_8037855c = 0x8037855c;
action_name_80378574 = 0x80378574;
action_name_8037858c = 0x8037858c;
w3d_allocate_80212fd4 = 0x80212fd4;
w3d_copy_802eee50 = 0x802eee50;
w3d_name_8015f518 = 0x8015f518;
w3d_pool_allocate_802098d8 = 0x802098d8;
w3d_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_d24g_input_worm_actions_80054d24 0x80054d24 : { *(.text.w3d_d24g_input_worm_actions_80054d24) }
  .rodata 0x803785a4 : { *(.rodata) }
  .sdata 0x804ae280 (NOLOAD) : {
    . = 0x0; w3d_pool_804ae280 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
