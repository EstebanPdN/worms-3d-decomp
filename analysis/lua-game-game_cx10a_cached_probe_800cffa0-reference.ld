/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx10a_cached_probe_800cffa0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
origin_8043fddc = 0x8043fddc;
probe_800b0824 = 0x800b0824;
scale_8038813c = 0x8038813c;
zero_80388138 = 0x80388138;
SECTIONS {
  .text.w3d_cx10a_cached_probe_800cffa0 0x800cffa0 : { *(.text.w3d_cx10a_cached_probe_800cffa0) }
  .sdata 0x804ae868 (NOLOAD) : {
    . = 0x0; initialized_804ae868 = .;
    . = 0x2efc; result_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
