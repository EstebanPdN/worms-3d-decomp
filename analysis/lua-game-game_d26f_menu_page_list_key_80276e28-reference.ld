/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26f_menu_page_list_key_80276e28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__17D26fText_803426b8 = 0x803426b8;
__17D26fText_803426b8PCc = 0x8020bb54;
d24d_rename_item_801790bc = 0x801790bc;
d25c_resource_load_800fd504 = 0x800fd504;
fn_80271420 = 0x80271420;
fn_80271518 = 0x80271518;
fn_80271c94 = 0x80271c94;
fn_80276d14 = 0x80276d14;
lbl_803ce3e0 = 0x803ce3e0;
lbl_803ce3f0 = 0x803ce3f0;
lbl_803ce3f8 = 0x803ce3f8;
lbl_803ce400 = 0x803ce400;
lbl_803ce408 = 0x803ce408;
lbl_803ce410 = 0x803ce410;
lbl_803fccf4 = 0x803fccf4;
lbl_80419e28 = 0x80419e28;
strchr = 0x802ef198;
strcmp = 0x802ef234;
w3d_auto_8027a98c = 0x8027a98c;
w3d_auto_8027a9e4 = 0x8027a9e4;
w3d_empty_80343744 = 0x80343744;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_s20_forward_indexed_800fd4c8 = 0x800fd4c8;
w3d_s20_service_call3_800fd440 = 0x800fd440;
w3d_s20_service_call4_800fc160 = 0x800fc160;
w3d_string_append = 0x8020bf2c;
w3d_string_assign = 0x8020bd38;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_format = 0x8020c510;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.d26f_menu_page_list_key_80276e28 0x80276e28 : { *(.text.d26f_menu_page_list_key_80276e28) }
  .sdata 0x804abb9c (NOLOAD) : {
    . = 0x0; lbl_804abb9c = .;
    . = 0x4; lbl_804abba0 = .;
    . = 0x5bec; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
