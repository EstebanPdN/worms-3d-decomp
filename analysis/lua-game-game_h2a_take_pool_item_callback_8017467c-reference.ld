/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(h2a_take_pool_item_callback_8017467c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
add_80190438 = 0x80190438;
counts_804a89d8 = 0x804a89d8;
identity_8034bf4c = 0x8034bf4c;
SECTIONS {
  .text.h2a_take_pool_item_callback_8017467c 0x8017467c : { *(.text.h2a_take_pool_item_callback_8017467c) }
  .sdata 0x804ab588 (NOLOAD) : {
    . = 0x0; pool_804ab588 = .;
    . = 0x8; free_804ab590 = .;
    . = 0xc; count_804ab594 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
