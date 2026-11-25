/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_ninja_rope_actions_80058f18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
action_name_8037894c = 0x8037894c;
action_name_80378964 = 0x80378964;
action_name_8037897c = 0x8037897c;
action_name_80378994 = 0x80378994;
action_name_803789ac = 0x803789ac;
action_name_803789c8 = 0x803789c8;
action_name_803789e4 = 0x803789e4;
action_name_80378a00 = 0x80378a00;
action_name_80378a1c = 0x80378a1c;
action_name_80378a34 = 0x80378a34;
action_name_80378a4c = 0x80378a4c;
action_name_80378a64 = 0x80378a64;
w3d_allocate_80212fd4 = 0x80212fd4;
w3d_copy_802eee50 = 0x802eee50;
w3d_name_8015f518 = 0x8015f518;
w3d_pool_allocate_802098d8 = 0x802098d8;
w3d_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_d24g_ninja_rope_actions_80058f18 0x80058f18 : { *(.text.w3d_d24g_ninja_rope_actions_80058f18) }
  .rodata 0x80378a80 : { *(.rodata) }
  .sdata 0x804ae280 (NOLOAD) : {
    . = 0x0; w3d_pool_804ae280 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
