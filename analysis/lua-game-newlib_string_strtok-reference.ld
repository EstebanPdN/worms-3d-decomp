/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(strtok)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strtok_r = 0x802efda4;
SECTIONS {
  .text.strtok 0x802efd7c : { *(.text.strtok) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; _impure_ptr = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
