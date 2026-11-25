/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24z_open_802e3324)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24z_close_802e4cec = 0x802e4cec;
d24z_create_802e4ce4 = 0x802e4ce4;
d24z_open_802e4cdc = 0x802e4cdc;
SECTIONS {
  .text.w3d_d24z_open_802e3324 0x802e3324 : { *(.text.w3d_d24z_open_802e3324) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
