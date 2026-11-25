/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35p_musyx_store_word_80333ccc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.sol35p_musyx_store_word_80333ccc 0x80333ccc : { *(.text.sol35p_musyx_store_word_80333ccc) }
  .text.sol35p_musyx_store_byte_803340ec 0x803340ec : { *(.text.sol35p_musyx_store_byte_803340ec) }
  .sdata 0x804b1744 (NOLOAD) : {
    . = 0x0; lbl_804b1744 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
