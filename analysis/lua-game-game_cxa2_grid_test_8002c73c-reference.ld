/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cxa2_grid_test_8002c73c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
masks_80372724 = 0x80372724;
SECTIONS {
  .text.cxa2_grid_test_8002c73c 0x8002c73c : { *(.text.cxa2_grid_test_8002c73c) }
  .sdata 0x804accc0 (NOLOAD) : {
    . = 0x0; x_804accc0 = .;
    . = 0x4; z_804accc4 = .;
    . = 0x8; bit_804accc8 = .;
    . = 0xc; word_804acccc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
