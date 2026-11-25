/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29g_crate_properties_load_8004b448)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_800fc1f0 = 0x800fc1f0;
w3d_auto_800fc270 = 0x800fc270;
w3d_engine_get_context = 0x80165254;
SECTIONS {
  .text.w3d_d29g_crate_properties_load_8004b448 0x8004b448 : { *(.text.w3d_d29g_crate_properties_load_8004b448) }
  .rodata 0x80377118 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
