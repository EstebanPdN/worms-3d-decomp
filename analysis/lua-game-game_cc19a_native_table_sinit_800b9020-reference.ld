/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc19a_native_table_sinit_800b9020)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
table_8043b23c = 0x8043b23c;
value_80382524 = 0x80382524;
value_80382528 = 0x80382528;
SECTIONS {
  .text.w3d_cc19a_native_table_sinit_800b9020 0x800b9020 : { *(.text.w3d_cc19a_native_table_sinit_800b9020) }
  .sdata 0x804aacc8 (NOLOAD) : {
    . = 0x0; pointer_804aacc8 = .;
    . = 0x37c4; pointer_804ae48c = .;
    . = 0x37c8; pointer_804ae490 = .;
    . = 0x37cc; pointer_804ae494 = .;
    . = 0x37d0; pointer_804ae498 = .;
    . = 0x37d4; pointer_804ae49c = .;
    . = 0x37d8; pointer_804ae4a0 = .;
    . = 0x37dc; pointer_804ae4a4 = .;
    . = 0x37e0; pointer_804ae4a8 = .;
    . = 0x37e4; pointer_804ae4ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
