/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26l_static_tables_802cd308)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
a_80473724 = 0x80473724;
b_80473764 = 0x80473764;
c_804737a4 = 0x804737a4;
d_804738a4 = 0x804738a4;
e_804738e4 = 0x804738e4;
SECTIONS {
  .text.d26l_static_tables_802cd308 0x802cd308 : { *(.text.d26l_static_tables_802cd308) }
  .sdata 0x804b10b0 (NOLOAD) : {
    . = 0x0; count_804b10b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
