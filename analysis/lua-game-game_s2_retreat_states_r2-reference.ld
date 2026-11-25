/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_retreat_construct_8010dadc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_800fcea0 = 0x800fcea0;
w3d_auto_80178c48 = 0x80178c48;
w3d_cached_message_id = 0x8015f5a0;
w3d_empty_803426b4 = 0x803426b4;
w3d_engine_get_context = 0x80165254;
w3d_f32_80399ff0 = 0x80399ff0;
w3d_fn_80022e20 = 0x80022e20;
w3d_fn_8002a914 = 0x8002a914;
w3d_fn_8002a978 = 0x8002a978;
w3d_fn_8002addc = 0x8002addc;
w3d_fn_8002ae70 = 0x8002ae70;
w3d_fn_8002af78 = 0x8002af78;
w3d_fn_800fc3b0 = 0x800fc3b0;
w3d_fn_800fc710 = 0x800fc710;
w3d_fn_801613f0 = 0x801613f0;
w3d_fn_80178474 = 0x80178474;
w3d_message_post_current = 0x8016239c;
w3d_obj_8040db38 = 0x8040db38;
w3d_obj_804107f8 = 0x804107f8;
w3d_obj_80410850 = 0x80410850;
w3d_scene_timer_is_one_8006e71c = 0x8006e71c;
w3d_str_80399ff4 = 0x80399ff4;
w3d_str_8039a000 = 0x8039a000;
w3d_str_8039a014 = 0x8039a014;
w3d_type_80361860 = 0x80361860;
w3d_type_803618f0 = 0x803618f0;
SECTIONS {
  .text.w3d_retreat_construct_8010dadc 0x8010dadc : { *(.text.w3d_retreat_construct_8010dadc) }
  .text.w3d_retreat_destroy_8010db24 0x8010db24 : { *(.text.w3d_retreat_destroy_8010db24) }
  .text.w3d_retreat_tick_8010dc0c 0x8010dc0c : { *(.text.w3d_retreat_tick_8010dc0c) }
  .text.w3d_retreat_launch_8010dd44 0x8010dd44 : { *(.text.w3d_retreat_launch_8010dd44) }
  .text.w3d_surrender_construct_8010df80 0x8010df80 : { *(.text.w3d_surrender_construct_8010df80) }
  .text.w3d_surrender_destroy_8010dfc8 0x8010dfc8 : { *(.text.w3d_surrender_destroy_8010dfc8) }
  .text.w3d_surrender_tick_8010e0b0 0x8010e0b0 : { *(.text.w3d_surrender_tick_8010e0b0) }
  .text.w3d_surrender_reset_8010e22c 0x8010e22c : { *(.text.w3d_surrender_reset_8010e22c) }
  .text.w3d_surrender_launch_8010e298 0x8010e298 : { *(.text.w3d_surrender_launch_8010e298) }
  .rodata 0x80399fe8 : { *(.rodata) }
  .sdata 0x804af2b8 (NOLOAD) : {
    . = 0x0; w3d_obj_804af2b8 = .;
    . = 0x4; w3d_obj_804af2bc = .;
    . = 0x8; w3d_obj_804af2c0 = .;
    . = 0x10; w3d_obj_804af2c8 = .;
    . = 0x18; w3d_obj_804af2d0 = .;
    . = 0x20; w3d_obj_804af2d8 = .;
    . = 0x28; w3d_obj_804af2e0 = .;
    . = 0x30; w3d_obj_804af2e8 = .;
    . = 0x38; w3d_obj_804af2f0 = .;
    . = 0x40; w3d_obj_804af2f8 = .;
    . = 0x48; w3d_obj_804af300 = .;
    . = 0x249c; w3d_obj_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
