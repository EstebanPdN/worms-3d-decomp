/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_hit_strip_forward_802b8260)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80178df0 = 0x80178df0;
fn_802b22e4 = 0x802b22e4;
fn_802bc7c0 = 0x802bc7c0;
gain_803d80a8 = 0x803d80a8;
gain_803d80ac = 0x803d80ac;
shift_803d80a4 = 0x803d80a4;
SECTIONS {
  .text.w3d_hit_strip_forward_802b8260 0x802b8260 : { *(.text.w3d_hit_strip_forward_802b8260) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
