/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(_open_r)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_open = 0x802e3324;
SECTIONS {
  .text._open_r 0x802f3328 : { *(.text._open_r) }
  .sdata 0x804b1910 (NOLOAD) : {
    . = 0x0; errno = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
