/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_trigger_graphic_setup_80124c5c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_cached_message_id = 0x8015f5a0;
w3d_component_position_801256ec = 0x801256ec;
w3d_component_radius_801256e4 = 0x801256e4;
w3d_fn_800fc3b0 = 0x800fc3b0;
w3d_fn_801613f0 = 0x801613f0;
w3d_fn_80164fc8 = 0x80164fc8;
w3d_fn_80200a70 = 0x80200a70;
w3d_handle_set_name = 0x8015adf4;
w3d_light_set_attachment_800c1294 = 0x800c1294;
w3d_message_post_current = 0x8016239c;
w3d_obj_8040cac0 = 0x8040cac0;
w3d_obj_8040db38 = 0x8040db38;
w3d_obj_8044fae4 = 0x8044fae4;
w3d_registry_8044fae8 = 0x8044fae8;
w3d_str_8039b900 = 0x8039b900;
w3d_str_8039b944 = 0x8039b944;
w3d_str_8039baac = 0x8039baac;
w3d_str_8039bb9c = 0x8039bb9c;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_from_text = 0x8020bb54;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_trigger_graphic_setup_80124c5c 0x80124c5c : { *(.text.w3d_trigger_graphic_setup_80124c5c) }
  .text.w3d_trigger_collect_80125b44 0x80125b44 : { *(.text.w3d_trigger_collect_80125b44) }
  .text.w3d_handle_registry_init_8012609c 0x8012609c : { *(.text.w3d_handle_registry_init_8012609c) }
  .text.w3d_light_member_attach_80126610 0x80126610 : { *(.text.w3d_light_member_attach_80126610) }
  .sdata 0x804af56c (NOLOAD) : {
    . = 0x0; w3d_obj_804af56c = .;
    . = 0x8; w3d_obj_804af574 = .;
    . = 0x10; w3d_obj_804af57c = .;
    . = 0x18; w3d_obj_804af584 = .;
    . = 0x21e8; w3d_obj_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
