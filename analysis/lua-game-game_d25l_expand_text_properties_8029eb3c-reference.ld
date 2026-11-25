/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25l_expand_text_properties_8029eb3c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80179170 = 0x80179170;
w3d_empty_80343744 = 0x80343744;
w3d_lookup_800fc1b0 = 0x800fc1b0;
SECTIONS {
  .text.d25l_expand_text_properties_8029eb3c 0x8029eb3c : { *(.text.d25l_expand_text_properties_8029eb3c) }
  .sdata 0x804b0e6c (NOLOAD) : {
    . = 0x0; lbl_804b0e6c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
