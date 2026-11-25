/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_refresh_colours_802a6ce8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80173df0 = 0x80173df0;
fn_802a7998 = 0x802a7998;
fn_8034357c = 0x8034357c;
SECTIONS {
  .text.w3d_refresh_colours_802a6ce8 0x802a6ce8 : { *(.text.w3d_refresh_colours_802a6ce8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
