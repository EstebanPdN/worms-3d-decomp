/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_ai_attack_plan_destroy_8000a20c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ai_origin_8041d3a0 = 0x8041d3a0;
w3d_ai_result_8041e850 = 0x8041e850;
w3d_auto_80015264 = 0x80015264;
w3d_f32_80369bd4 = 0x80369bd4;
w3d_f32_80369bd8 = 0x80369bd8;
w3d_fn_8001a7f8 = 0x8001a7f8;
w3d_fn_8001ae30 = 0x8001ae30;
w3d_fn_8001b0d4 = 0x8001b0d4;
w3d_move_queue_release = 0x800033d8;
w3d_path_cost_destroy = 0x80006388;
w3d_vtable_8040d7b8 = 0x8040d7b8;
SECTIONS {
  .text.w3d_ai_attack_plan_destroy_8000a20c 0x8000a20c : { *(.text.w3d_ai_attack_plan_destroy_8000a20c) }
  .text.w3d_ai_set_query_origin_8000a62c 0x8000a62c : { *(.text.w3d_ai_set_query_origin_8000a62c) }
  .text.w3d_ai_capture_query_8000a68c 0x8000a68c : { *(.text.w3d_ai_capture_query_8000a68c) }
  .text.w3d_ai_query_a_8000a758 0x8000a758 : { *(.text.w3d_ai_query_a_8000a758) }
  .text.w3d_ai_query_b_8000a7ac 0x8000a7ac : { *(.text.w3d_ai_query_b_8000a7ac) }
  .sdata 0x804aa570 (NOLOAD) : {
    . = 0x0; w3d_ai_cost_804aa570 = .;
    . = 0x71f8; w3d_ai_result_cost_804b1768 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
