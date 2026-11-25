/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12b_focus_dispatch_802c3ff0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
set_a_802c7bec = 0x802c7bec;
set_b_802c688c = 0x802c688c;
SECTIONS {
  .text.w3d_cx12b_focus_dispatch_802c3ff0 0x802c3ff0 : { *(.text.w3d_cx12b_focus_dispatch_802c3ff0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
