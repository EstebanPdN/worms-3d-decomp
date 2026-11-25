/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b_pool_init_800c1580)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.sol35b_pool_init_800c1580 0x800c1580 : { *(.text.sol35b_pool_init_800c1580) }
  .sdata 0x804aadb4 (NOLOAD) : {
    . = 0x0; sol35b_pool_804aadb4 = .;
    . = 0x3888; sol35b_section_804ae63c = .;
    . = 0x388c; sol35b_section_804ae640 = .;
    . = 0x3890; sol35b_section_804ae644 = .;
    . = 0x3894; sol35b_section_804ae648 = .;
    . = 0x3898; sol35b_section_804ae64c = .;
    . = 0x389c; sol35b_section_804ae650 = .;
    . = 0x38a0; sol35b_section_804ae654 = .;
    . = 0x38a4; sol35b_section_804ae658 = .;
    . = 0x38a8; sol35b_section_804ae65c = .;
    . = 0x38ac; sol35b_section_804ae660 = .;
    . = 0x38b0; sol35b_section_804ae664 = .;
    . = 0x38b4; sol35b_section_804ae668 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
