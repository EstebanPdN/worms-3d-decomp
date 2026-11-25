/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc25a_planner_trace_distance_8001b830)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc25a_hit_8043ae20 = 0x8043ae20;
cc25a_limit_8036b054 = 0x8036b054;
cc25a_position_8041e85c = 0x8041e85c;
cc25a_probe_8041e780 = 0x8041e780;
cc25a_trace_800b0824 = 0x800b0824;
SECTIONS {
  .text.cc25a_planner_trace_distance_8001b830 0x8001b830 : { *(.text.cc25a_planner_trace_distance_8001b830) }
  .rodata 0x8036b058 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; cc25a_hit_distance_804b1764 = .;
    . = 0x1c; cc25a_cached_distance_804b1780 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
