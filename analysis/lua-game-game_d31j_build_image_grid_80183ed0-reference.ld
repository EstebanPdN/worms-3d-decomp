/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31j_build_image_grid_80183ed0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3StrPCc = 0x8020bb54;
lbl_803a79c0 = 0x803a79c0;
lbl_80413db0 = 0x80413db0;
lbl_804143e0 = 0x804143e0;
lbl_804144f8 = 0x804144f8;
lbl_80414518 = 0x80414518;
lbl_80414600 = 0x80414600;
lbl_80415b50 = 0x80415b50;
lbl_80415d60 = 0x80415d60;
w3d_auto_801d0858 = 0x801d0858;
w3d_auto_801d086c = 0x801d086c;
w3d_auto_801d0898 = 0x801d0898;
w3d_auto_8020b648 = 0x8020b648;
w3d_cx13b_sphere_bounds_801f5724 = 0x801f5724;
w3d_k5b_array_ref_lock_801ef048 = 0x801ef048;
w3d_k5b_iface_array_field_append_801ef174 = 0x801ef174;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.d31j_build_image_grid_80183ed0 0x80183ed0 : { *(.text.d31j_build_image_grid_80183ed0) }
  .rodata 0x803a79d8 : { *(.rodata) }
  .sdata 0x804b01dc (NOLOAD) : {
    . = 0x0; lbl_804b01dc = .;
    . = 0x4; lbl_804b01e0 = .;
    . = 0x10; lbl_804b01ec = .;
    . = 0x1c; lbl_804b01f8 = .;
    . = 0x20; lbl_804b01fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
