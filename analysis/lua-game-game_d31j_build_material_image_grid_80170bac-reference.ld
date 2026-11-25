/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31j_build_material_image_grid_80170bac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3StrPCc = 0x8020bb54;
fn_801720fc = 0x801720fc;
lbl_803a65d0 = 0x803a65d0;
lbl_80413db0 = 0x80413db0;
lbl_804143e0 = 0x804143e0;
lbl_80415b50 = 0x80415b50;
lbl_80415d60 = 0x80415d60;
w3d_auto_80171ab8 = 0x80171ab8;
w3d_auto_80171b1c = 0x80171b1c;
w3d_auto_80171b80 = 0x80171b80;
w3d_auto_801d0858 = 0x801d0858;
w3d_auto_801d086c = 0x801d086c;
w3d_auto_801d0898 = 0x801d0898;
w3d_auto_8020b648 = 0x8020b648;
w3d_k5b_array_ref_lock_801ef048 = 0x801ef048;
w3d_k5b_iface_array_field_append_801ef174 = 0x801ef174;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_s20_get_selected_material_80172088 = 0x80172088;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.d31j_build_material_image_grid_80170bac 0x80170bac : { *(.text.d31j_build_material_image_grid_80170bac) }
  .rodata 0x803a65e8 : { *(.rodata) }
  .sdata 0x804b012c (NOLOAD) : {
    . = 0x0; lbl_804b012c = .;
    . = 0x4; lbl_804b0130 = .;
    . = 0x10; lbl_804b013c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
