/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx14a_probe_normal_800eae00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
bias_8045e788 = 0x8045e788;
normal_8043ae38 = 0x8043ae38;
one_8038b400 = 0x8038b400;
point_8043ae20 = 0x8043ae20;
select_800bd920 = 0x800bd920;
sqrt_802e82c0 = 0x802e82c0;
trace_800b0824 = 0x800b0824;
SECTIONS {
  .text.w3d_cx14a_probe_normal_800eae00 0x800eae00 : { *(.text.w3d_cx14a_probe_normal_800eae00) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; distance_804b1764 = .;
    . = 0x20; mode_804b1784 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
