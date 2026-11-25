/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27a_motion_step_trace_8001b964)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cx11a_linear_sample_800d76dc = 0x800d76dc;
w3d_cx14a_dispatch_normal_8001baf4 = 0x8001baf4;
w3d_goal_8041e85c = 0x8041e85c;
w3d_hit_8043ae20 = 0x8043ae20;
w3d_motion_8041e780 = 0x8041e780;
w3d_motion_at_height_80118a5c = 0x80118a5c;
w3d_step_8041e850 = 0x8041e850;
w3d_trace_800b0824 = 0x800b0824;
SECTIONS {
  .text.w3d_d27a_motion_step_trace_8001b964 0x8001b964 : { *(.text.w3d_d27a_motion_step_trace_8001b964) }
  .rodata 0x8036b068 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; w3d_hit_time_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
