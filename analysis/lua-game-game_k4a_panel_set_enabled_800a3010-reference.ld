/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_panel_set_enabled_800a3010)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80178d1c = 0x80178d1c;
SECTIONS {
  .text.k4a_panel_set_enabled_800a3010 0x800a3010 : { *(.text.k4a_panel_set_enabled_800a3010) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
