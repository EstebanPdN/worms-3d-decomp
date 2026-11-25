/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f3a_hit_inner_8026f820)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80178df0 = 0x80178df0;
fn_802b22e4 = 0x802b22e4;
fn_802bc7c0 = 0x802bc7c0;
scale_803cbf24 = 0x803cbf24;
SECTIONS {
  .text.w3d_f3a_hit_inner_8026f820 0x8026f820 : { *(.text.w3d_f3a_hit_inner_8026f820) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
