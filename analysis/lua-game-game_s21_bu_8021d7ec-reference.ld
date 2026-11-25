/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_crc_update_8021d7ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_804a98f8 = 0x804a98f8;
SECTIONS {
  .text.w3d_s21_crc_update_8021d7ec 0x8021d7ec : { *(.text.w3d_s21_crc_update_8021d7ec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
