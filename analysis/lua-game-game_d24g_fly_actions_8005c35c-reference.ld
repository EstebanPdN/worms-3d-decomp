/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_fly_actions_8005c35c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
action_name_80378d20 = 0x80378d20;
action_name_80378d38 = 0x80378d38;
action_name_80378d50 = 0x80378d50;
action_name_80378d68 = 0x80378d68;
action_name_80378d80 = 0x80378d80;
action_name_80378d98 = 0x80378d98;
action_name_80378db0 = 0x80378db0;
action_name_80378dc8 = 0x80378dc8;
action_name_80378de0 = 0x80378de0;
action_name_80378df8 = 0x80378df8;
action_name_80378e10 = 0x80378e10;
action_name_80378e28 = 0x80378e28;
w3d_allocate_80212fd4 = 0x80212fd4;
w3d_copy_802eee50 = 0x802eee50;
w3d_name_8015f518 = 0x8015f518;
w3d_pool_allocate_802098d8 = 0x802098d8;
w3d_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_d24g_fly_actions_8005c35c 0x8005c35c : { *(.text.w3d_d24g_fly_actions_8005c35c) }
  .rodata 0x80378e40 : { *(.rodata) }
  .sdata 0x804ae280 (NOLOAD) : {
    . = 0x0; w3d_pool_804ae280 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
