/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d11b_clear_panel_802c29d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d11b_clear_active_panel_802c4380 = 0x802c4380;
d11b_release_panel_resource_8015fd1c = 0x8015fd1c;
SECTIONS {
  .text.d11b_clear_panel_802c29d0 0x802c29d0 : { *(.text.d11b_clear_panel_802c29d0) }
  .sdata 0x804abb54 (NOLOAD) : {
    . = 0x0; d11b_active_panel_804abb54 = .;
    . = 0x8; d11b_panel_count_804abb5c = .;
    . = 0xc; d11b_resource_count_804abb60 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
