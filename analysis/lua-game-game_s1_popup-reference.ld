/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8004862c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_base_destroy_8015ff2c = 0x8015ff2c;
w3d_buffer_storage_available = 0x801981f8;
w3d_empty_80343584 = 0x80343584;
w3d_f32_80376748 = 0x80376748;
w3d_f32_8037674c = 0x8037674c;
w3d_fn_80048fcc = 0x80048fcc;
w3d_fn_800fc1f0 = 0x800fc1f0;
w3d_fn_800fc6dc = 0x800fc6dc;
w3d_fn_800fc7f8 = 0x800fc7f8;
w3d_fn_80164fc8 = 0x80164fc8;
w3d_fn_80181640 = 0x80181640;
w3d_handle_member_destroy_801265a4 = 0x801265a4;
w3d_mesh_instance_check_control = 0x8018179c;
w3d_registry_instance_80343810 = 0x80343810;
w3d_str_803766d4 = 0x803766d4;
w3d_str_80376740 = 0x80376740;
w3d_str_80376750 = 0x80376750;
w3d_vtable_8040e978 = 0x8040e978;
SECTIONS {
  .text.w3d_fn_8004862c 0x8004862c : { *(.text.w3d_fn_8004862c) }
  .text.w3d_fn_80048ec4 0x80048ec4 : { *(.text.w3d_fn_80048ec4) }
  .text.w3d_fn_80048f1c 0x80048f1c : { *(.text.w3d_fn_80048f1c) }
  .text.w3d_fn_80049108 0x80049108 : { *(.text.w3d_fn_80049108) }
  .text.w3d_fn_80049180 0x80049180 : { *(.text.w3d_fn_80049180) }
  .rodata 0x80376758 : { *(.rodata) }
  .sdata 0x804aa994 (NOLOAD) : {
    . = 0x0; w3d_clip_804aa994 = .;
    . = 0x4; w3d_clip_804aa998 = .;
    . = 0x8; w3d_clip_804aa99c = .;
    . = 0xc; w3d_clip_804aa9a0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
