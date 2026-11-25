/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_spectate_cam_actions_8005e4a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
action_name_80378edc = 0x80378edc;
action_name_80378ef0 = 0x80378ef0;
action_name_80378f10 = 0x80378f10;
action_name_80378f30 = 0x80378f30;
action_name_80378f50 = 0x80378f50;
action_name_80378f70 = 0x80378f70;
action_name_80378f90 = 0x80378f90;
action_name_80378fb0 = 0x80378fb0;
action_name_80378fcc = 0x80378fcc;
action_name_80378fec = 0x80378fec;
action_name_80379008 = 0x80379008;
action_name_80379024 = 0x80379024;
action_name_8037903c = 0x8037903c;
action_name_80379058 = 0x80379058;
action_name_80379070 = 0x80379070;
action_name_8037908c = 0x8037908c;
action_name_803790a8 = 0x803790a8;
action_name_803790c4 = 0x803790c4;
action_name_803790e4 = 0x803790e4;
action_name_80379104 = 0x80379104;
w3d_allocate_80212fd4 = 0x80212fd4;
w3d_copy_802eee50 = 0x802eee50;
w3d_name_8015f518 = 0x8015f518;
w3d_pool_allocate_802098d8 = 0x802098d8;
w3d_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_d24g_spectate_cam_actions_8005e4a4 0x8005e4a4 : { *(.text.w3d_d24g_spectate_cam_actions_8005e4a4) }
  .rodata 0x8037911c : { *(.rodata) }
  .sdata 0x804ae280 (NOLOAD) : {
    . = 0x0; w3d_pool_804ae280 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
