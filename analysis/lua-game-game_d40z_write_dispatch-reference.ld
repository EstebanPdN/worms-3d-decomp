/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d40z_write_802e3244)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_802e31ec = 0x802e31ec;
w3d_d40z_host_write_802e4cfc = 0x802e4cfc;
SECTIONS {
  .text.w3d_d40z_write_802e3244 0x802e3244 : { *(.text.w3d_d40z_write_802e3244) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
