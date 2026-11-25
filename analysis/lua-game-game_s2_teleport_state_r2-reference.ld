/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_target_id_message_801190b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_base_destroy = 0x80161050;
w3d_auto_80178c48 = 0x80178c48;
w3d_cached_message_id = 0x8015f5a0;
w3d_f32_8039ab10 = 0x8039ab10;
w3d_fn_80035714 = 0x80035714;
w3d_fn_800fc43c = 0x800fc43c;
w3d_fn_800fc6dc = 0x800fc6dc;
w3d_fn_801613f0 = 0x801613f0;
w3d_fn_80162024 = 0x80162024;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_obj_8040db38 = 0x8040db38;
w3d_obj_80410950 = 0x80410950;
w3d_str_8039aadc = 0x8039aadc;
w3d_str_8039aaf8 = 0x8039aaf8;
w3d_str_8039ab00 = 0x8039ab00;
w3d_teleport_fire_80119794 = 0x80119794;
SECTIONS {
  .text.w3d_target_id_message_801190b4 0x801190b4 : { *(.text.w3d_target_id_message_801190b4) }
  .text.w3d_teleport_destroy_801193bc 0x801193bc : { *(.text.w3d_teleport_destroy_801193bc) }
  .text.w3d_teleport_setup_80119590 0x80119590 : { *(.text.w3d_teleport_setup_80119590) }
  .text.w3d_teleport_shutdown_801196d8 0x801196d8 : { *(.text.w3d_teleport_shutdown_801196d8) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; w3d_obj_804aa8c8 = .;
    . = 0x4a54; w3d_obj_804af31c = .;
    . = 0x4a5c; w3d_obj_804af324 = .;
    . = 0x4a64; w3d_obj_804af32c = .;
    . = 0x4ab4; w3d_obj_804af37c = .;
    . = 0x4abc; w3d_obj_804af384 = .;
    . = 0x4acc; w3d_obj_804af394 = .;
    . = 0x4ad4; w3d_obj_804af39c = .;
    . = 0x6e8c; w3d_obj_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
