/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_global_light_destroy_800c000c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_global_light_detach_800c04a4 = 0x800c04a4;
w3d_global_light_refresh_800c06a0 = 0x800c06a0;
w3d_light_attach_80182410 = 0x80182410;
w3d_light_entries_8043c384 = 0x8043c384;
w3d_logic_base_destroy_801628ec = 0x801628ec;
w3d_logic_base_handle_8016293c = 0x8016293c;
w3d_str_80382f60 = 0x80382f60;
w3d_str_80382f74 = 0x80382f74;
w3d_vtable_8040f8a8 = 0x8040f8a8;
SECTIONS {
  .text.w3d_global_light_destroy_800c000c 0x800c000c : { *(.text.w3d_global_light_destroy_800c000c) }
  .text.w3d_global_light_handle_800c0090 0x800c0090 : { *(.text.w3d_global_light_handle_800c0090) }
  .text.w3d_global_light_attach_800c0440 0x800c0440 : { *(.text.w3d_global_light_attach_800c0440) }
  .text.w3d_light_set_position_800c125c 0x800c125c : { *(.text.w3d_light_set_position_800c125c) }
  .text.w3d_light_set_attachment_800c1294 0x800c1294 : { *(.text.w3d_light_set_attachment_800c1294) }
  .text.w3d_light_set_scale_800c1348 0x800c1348 : { *(.text.w3d_light_set_scale_800c1348) }
  .sdata 0x804aada8 (NOLOAD) : {
    . = 0x0; w3d_global_light_804aada8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
