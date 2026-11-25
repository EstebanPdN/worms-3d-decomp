/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(set__9D32sFaderif)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_M_fill_insert__Q24_STLt6vector2Z12D32sFadeWordZt15ModuleAllocator1Z12D32sFadeWordP12D32sFadeWordUiRC12D32sFadeWord = 0x8034f1a0;
lbl_804a91d8 = 0x804a91d8;
lbl_804a91e8 = 0x804a91e8;
SECTIONS {
  .text.set__9D32sFaderif 0x80195cd4 : { *(.text.set__9D32sFaderif) }
  .rodata 0x803a8488 : { *(.rodata) }
  .sdata 0x804b18bc (NOLOAD) : {
    . = 0x0; lbl_804b18bc = .;
    . = 0x4; lbl_804b18c0 = .;
    . = 0x8; lbl_804b18c4 = .;
    . = 0xc; lbl_804b18c8 = .;
    . = 0x10; lbl_804b18cc = .;
    . = 0x14; lbl_804b18d0 = .;
    . = 0x18; lbl_804b18d4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
