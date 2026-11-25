/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_widget_ctor_80270df0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8041be80 = 0x8041be80;
w3d_construct_802109dc = 0x802109dc;
w3d_ctor_801628b0 = 0x801628b0;
SECTIONS {
  .text.w3d_k6b_widget_ctor_80270df0 0x80270df0 : { *(.text.w3d_k6b_widget_ctor_80270df0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
