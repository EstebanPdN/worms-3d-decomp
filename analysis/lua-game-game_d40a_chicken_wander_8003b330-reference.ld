/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40a_chicken_wander_8003b330)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
compute_800bd920 = 0x800bd920;
cosf_802e86d4 = 0x802e86d4;
g_normal_8043ae38 = 0x8043ae38;
g_point_8043ae20 = 0x8043ae20;
random_801610a0 = 0x801610a0;
sinf_802e88ac = 0x802e88ac;
sqrt_802e82c0 = 0x802e82c0;
w3d_trace_800b0824 = 0x800b0824;
SECTIONS {
  .text.w3d_d40a_chicken_wander_8003b330 0x8003b330 : { *(.text.w3d_d40a_chicken_wander_8003b330) }
  .rodata 0x80374310 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; g_hit_804b1764 = .;
    . = 0x20; traceReady_804b1784 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
