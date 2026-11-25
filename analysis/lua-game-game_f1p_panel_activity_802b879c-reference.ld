/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_panel_activity_802b879c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802b85f4 = 0x802b85f4;
fn_802b8754 = 0x802b8754;
fn_802bc71c = 0x802bc71c;
gain_803d80c8 = 0x803d80c8;
minimum_803d80cc = 0x803d80cc;
SECTIONS {
  .text.w3d_panel_activity_802b879c 0x802b879c : { *(.text.w3d_panel_activity_802b879c) }
  .rodata 0x803d80d0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
