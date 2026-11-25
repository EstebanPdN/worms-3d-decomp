/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_list_name_greater_8010e698)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strcmp = 0x802ef234;
w3d_auto_8016293c = 0x8016293c;
w3d_ctor_801628b0 = 0x801628b0;
w3d_empty_8010f7cc = 0x8010f7cc;
w3d_fn_8015f65c = 0x8015f65c;
w3d_get_8010a8fc = 0x8010a8fc;
w3d_list_fill_8010f7d0 = 0x8010f7d0;
w3d_list_fill_8010fd08 = 0x8010fd08;
w3d_list_fill_801100ac = 0x801100ac;
w3d_list_fill_80110450 = 0x80110450;
w3d_list_fill_80110c9c = 0x80110c9c;
w3d_list_fill_80111820 = 0x80111820;
w3d_list_fill_80112514 = 0x80112514;
w3d_list_fill_80112cb0 = 0x80112cb0;
w3d_list_fill_8011307c = 0x8011307c;
w3d_list_fill_8011385c = 0x8011385c;
w3d_list_fill_80113c18 = 0x80113c18;
w3d_list_fill_80113f24 = 0x80113f24;
w3d_list_fill_80114594 = 0x80114594;
w3d_list_fill_80114a2c = 0x80114a2c;
w3d_list_fill_80115088 = 0x80115088;
w3d_list_fill_8011577c = 0x8011577c;
w3d_list_fill_80115cd0 = 0x80115cd0;
w3d_list_fill_8011626c = 0x8011626c;
w3d_list_fill_801167d4 = 0x801167d4;
w3d_list_fill_8011711c = 0x8011711c;
w3d_list_fill_801175c8 = 0x801175c8;
w3d_list_initialize_8010ee14 = 0x8010ee14;
w3d_obj_804108a8 = 0x804108a8;
w3d_service_destroy_801628ec = 0x801628ec;
w3d_str_8039a110 = 0x8039a110;
w3d_str_8039a118 = 0x8039a118;
w3d_str_8039a124 = 0x8039a124;
w3d_str_8039a138 = 0x8039a138;
w3d_str_8039a14c = 0x8039a14c;
w3d_str_8039a160 = 0x8039a160;
w3d_str_8039a168 = 0x8039a168;
w3d_str_8039a178 = 0x8039a178;
w3d_str_8039a188 = 0x8039a188;
w3d_str_8039a190 = 0x8039a190;
w3d_str_8039a1a4 = 0x8039a1a4;
w3d_str_8039a1b4 = 0x8039a1b4;
w3d_str_8039a1c4 = 0x8039a1c4;
w3d_str_8039a1d4 = 0x8039a1d4;
w3d_str_8039a1e0 = 0x8039a1e0;
w3d_str_8039a1ec = 0x8039a1ec;
w3d_str_8039a1f8 = 0x8039a1f8;
w3d_str_8039a208 = 0x8039a208;
w3d_str_8039a214 = 0x8039a214;
w3d_str_8039a21c = 0x8039a21c;
w3d_str_8039a22c = 0x8039a22c;
w3d_str_8039a238 = 0x8039a238;
w3d_str_8039a244 = 0x8039a244;
SECTIONS {
  .text.w3d_list_name_greater_8010e698 0x8010e698 : { *(.text.w3d_list_name_greater_8010e698) }
  .text.w3d_list_service_construct_8010e6d0 0x8010e6d0 : { *(.text.w3d_list_service_construct_8010e6d0) }
  .text.w3d_list_service_destroy_8010e75c 0x8010e75c : { *(.text.w3d_list_service_destroy_8010e75c) }
  .text.w3d_list_service_dispatch_8010e9b4 0x8010e9b4 : { *(.text.w3d_list_service_dispatch_8010e9b4) }
  .sdata 0x804af308 (NOLOAD) : {
    . = 0x0; w3d_obj_804af308 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
