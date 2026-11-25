/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28a_plan_settle_trace_80017684)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
g_hit_8043ae20 = 0x8043ae20;
s19_probe_8001744c = 0x8001744c;
w3d_ai_push_plan_a = 0x8000753c;
w3d_trace_800b0824 = 0x800b0824;
SECTIONS {
  .text.w3d_d28a_plan_settle_trace_80017684 0x80017684 : { *(.text.w3d_d28a_plan_settle_trace_80017684) }
  .rodata 0x8036a768 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; g_hit_time_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
