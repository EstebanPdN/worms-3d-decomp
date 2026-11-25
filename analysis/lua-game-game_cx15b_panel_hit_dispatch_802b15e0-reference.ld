/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx15b_panel_hit_dispatch_802b15e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_cx15b_panel_hit_dispatch_802b15e0 0x802b15e0 : { *(.text.w3d_cx15b_panel_hit_dispatch_802b15e0) }
  .sdata 0x804abb4c (NOLOAD) : {
    . = 0x0; mode_804abb4c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
