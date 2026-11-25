/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx7a_grid_probe_named_8001f1d8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
probe_8001f30c = 0x8001f30c;
tuning_8036b8ac = 0x8036b8ac;
update_8001f904 = 0x8001f904;
vector_80015588 = 0x80015588;
SECTIONS {
  .text.w3d_cx7a_grid_probe_named_8001f1d8 0x8001f1d8 : { *(.text.w3d_cx7a_grid_probe_named_8001f1d8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
