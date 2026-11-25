/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g7b_copy_stereo_802e1d7c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802e220c = 0x802e220c;
fn_802eefe0 = 0x802eefe0;
volume_804040ec = 0x804040ec;
SECTIONS {
  .text.g7b_copy_stereo_802e1d7c 0x802e1d7c : { *(.text.g7b_copy_stereo_802e1d7c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
