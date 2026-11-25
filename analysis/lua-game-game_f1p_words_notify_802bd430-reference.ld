/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_words_notify_802bd430)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802bd354 = 0x802bd354;
fn_802bf81c = 0x802bf81c;
SECTIONS {
  .text.w3d_words_notify_802bd430 0x802bd430 : { *(.text.w3d_words_notify_802bd430) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
