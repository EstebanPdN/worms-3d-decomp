/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_tick_timers_80029780)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.s19_tick_timers_80029780 0x80029780 : { *(.text.s19_tick_timers_80029780) }
  .sdata 0x804aa858 (NOLOAD) : {
    . = 0x0; lbl_804aa858 = .;
    . = 0x4; lbl_804aa85c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
