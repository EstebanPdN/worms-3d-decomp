/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d17a_water_level_probe_8004d23c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d17a_read_float_setting_800fc270 = 0x800fc270;
d17a_trace_800b0824 = 0x800b0824;
d17a_trace_hit_8043ae20 = 0x8043ae20;
d17a_water_level_key_80376eb0 = 0x80376eb0;
SECTIONS {
  .text.w3d_d17a_water_level_probe_8004d23c 0x8004d23c : { *(.text.w3d_d17a_water_level_probe_8004d23c) }
  .rodata 0x80377478 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; d17a_trace_distance_804b1764 = .;
    . = 0x7c; d17a_world_804b17e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
