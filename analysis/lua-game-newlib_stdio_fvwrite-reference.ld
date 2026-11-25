/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__sfvwrite)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__swsetup = 0x802ed6b0;
fflush = 0x802eb084;
memchr = 0x802eed00;
memmove = 0x802eeef4;
SECTIONS {
  .text.__sfvwrite 0x802ebae8 : { *(.text.__sfvwrite) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
