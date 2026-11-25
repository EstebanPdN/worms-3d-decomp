/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__assert)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
abort = 0x802ed798;
fiprintf = 0x802f3434;
SECTIONS {
  .text.__assert 0x802ed7b0 : { *(.text.__assert) }
  .rodata 0x803db5e4 : { *(.rodata) }
  .sdata 0x804ac570 (NOLOAD) : {
    . = 0x0; _impure_ptr = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
