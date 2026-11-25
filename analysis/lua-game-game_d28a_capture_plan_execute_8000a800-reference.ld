/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28a_capture_plan_execute_8000a800)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_8001b510 = 0x8001b510;
g_prev_8041d394 = 0x8041d394;
g_step_8041e850 = 0x8041e850;
w3d_ai_capture_query_8000a68c = 0x8000a68c;
w3d_center_8041d3a0 = 0x8041d3a0;
SECTIONS {
  .text.w3d_d28a_capture_plan_execute_8000a800 0x8000a800 : { *(.text.w3d_d28a_capture_plan_execute_8000a800) }
  .rodata 0x80369bdc : { *(.rodata) }
  .sdata 0x804aa570 (NOLOAD) : {
    . = 0x0; g_time_804aa570 = .;
    . = 0x1e0; w3d_bodies_804aa750 = .;
    . = 0x22dc; g_guard_804ac84c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
