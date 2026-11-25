/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27d_worm_probe_ground_normal_80152a80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
compute_800bd920 = 0x800bd920;
construct_801f7538 = 0x801f7538;
sqrt_802e82c0 = 0x802e82c0;
test_800b0824 = 0x800b0824;
traceNormal_8043ae38 = 0x8043ae38;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d27d_worm_probe_ground_normal_80152a80 0x80152a80 : { *(.text.d27d_worm_probe_ground_normal_80152a80) }
  .rodata 0x803a1b30 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; traceFrac_804b1764 = .;
    . = 0x20; traceReady_804b1784 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
