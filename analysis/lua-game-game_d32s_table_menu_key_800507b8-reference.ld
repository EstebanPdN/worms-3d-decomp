/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(key__13D32sTableMenui)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
bank__13D32sTableMenu = 0x80051234;
load__13D32sTableMenu = 0x80050aa0;
other__13D32sTableMenu = 0x80050c20;
refill__13D32sTableMenu = 0x80050534;
refresh__13D32sTableMenu = 0x8004ff24;
save__13D32sTableMenu = 0x8005097c;
setup__13D32sTableMenu = 0x8004fe48;
show_file__13D32sTableMenu = 0x80050730;
show_help__13D32sTableMenu = 0x800506a8;
show_line__13D32sTableMenu = 0x80050620;
SECTIONS {
  .text.key__13D32sTableMenui 0x800507b8 : { *(.text.key__13D32sTableMenui) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
